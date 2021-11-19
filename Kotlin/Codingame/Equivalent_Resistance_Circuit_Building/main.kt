import kotlin.math.roundToInt

// Constants

const val N_MIN = 0
const val N_MAX = 10
const val R_MIN = 0
const val R_MAX = 100
const val BRACE_SERIES_LEFT = '('
const val BRACE_SERIES_RIGHT = ')'
const val BRACE_PARALLEL_LEFT = '['
const val BRACE_PARALLEL_RIGHT = ']'

enum class Braces(val left: Char, val right: Char) {
    SERIES('(', ')'),
    PARALLEL('[', ']')
}

interface Connection {
    fun calculate(): Float
}

class SimpleConnection(private val r: Float) : Connection {
    override fun calculate() = r
}

abstract class HardConnection : Connection {
    protected val connections = ArrayList<Connection>() 
    
    fun appendConnection(connection: Connection) {
        connections.add(connection)
    }
}

class SeriesConnection : HardConnection() {
    override fun calculate(): Float {
        var sum = 0f
        for (connection in connections) {
            sum += connection.calculate()
        }
        //println("S $sum")
        return sum
    }
}

class ParallelConnection : HardConnection() {
    override fun calculate(): Float {
        var sum = 0f
        for (connection in connections) {
            //println("Connection: $sum")
            sum += 1 / connection.calculate()
        }
        //println("P $sum")
        return 1 / sum
    }
}

val values = HashMap<String, Float>()

fun main() {
    val sb = StringBuilder()

    val n = readLine()!!.toInt()
    repeat(n) {
        val (key, value) = readLine()!!.split(" ")
        values[key] = value.toInt().toFloat()
        sb.append("$key $value\n")
    }

    val chain = readLine()!!
    sb.append(chain)
    sb.append('\n')
    //println(sb.toString())
    println(parseChain(chain, 0 until chain.length).calculate().roundToAnswer())
    
}

fun parseChain(chain: String, range: IntRange): Connection {
    //println("parseChain: $range")
    return when (chain[range.start]) {
        Braces.SERIES.left -> {
            val seriesConnection = SeriesConnection()
            for (ran in splitChain(chain, range)) {
                seriesConnection.appendConnection(parseChain(chain, ran))
            }
            return seriesConnection
        }
        Braces.PARALLEL.left -> {
            val parallelConnection = ParallelConnection()
            for (ran in splitChain(chain, range)) {
                parallelConnection.appendConnection(parseChain(chain, ran))
            }
            return parallelConnection
        }
        ' ' -> {
            parseChain(chain, range.first + 1 .. range.last)            
        }
        else -> {
            SimpleConnection(values[chain.substring(range)]!!)
        }
    }
}

fun splitChain(chain: String, range: IntRange): List<IntRange> {
    val result = ArrayList<IntRange>()
    var braceLevel = 0
    var elementStart = 0
    for (i in range) {
        if (chain[i] in arrayOf('(', '[')) {
            braceLevel++
            if (braceLevel == 2) {
                elementStart = i    
            }
        } else if (chain[i] in arrayOf(')', ']')) {
            braceLevel--
            if (braceLevel == 1) {
                result.add(elementStart .. i)
            }
        }

        if (braceLevel > 1) {
            continue
        }

        if (chain[i].isLetter() && !chain[i - 1].isLetter()) {
            elementStart = i
        }

        if (chain[i] == ' ' && chain[i] in arrayOf('(', '[')) {
            continue
        }

        if (chain[i] == ' ' && chain[elementStart].isLetter()) {
            result.add(elementStart until i)
        }
    }
    return result
}

fun Float.roundToAnswer(): Float {
    return (this * 10).roundToInt() / 10f
}

