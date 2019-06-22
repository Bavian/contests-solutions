import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

const val B_MIN = 2
const val B_MAX = 2750131

val primeNumbers = getPrimes()

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))

    val n = br.readLine()!!.toInt()
    val b = br.readLine()!!.split(" ").map{ it.toInt() }.sortedWith(Comparator{x, y -> y - x})
    br.close()

    val map = HashMap<Int, Int>()
    b.forEach { map.increment(it) }

    val a = ArrayList<Int>(n)
    for (element in b) {
        if (map.containsKey(element)) {

            map.decrement(element)
            map.decrement(primeNumbers[element])

            a.add(if (element % primeNumbers[element] == 0) element else primeNumbers[element])
        }
    }

    val bw = BufferedWriter(OutputStreamWriter(System.out))
    bw.write( a.joinToString(" ") )
    bw.close()
}

fun getPrimes(): Array<Int> {

    val result = Array(B_MAX + 1) {0}
    var count = 0

    for (number in 2..B_MAX) {

        if (result[number] == 0) {
            result[number] = ++count

            for (m in (number*2)..B_MAX step number) {

                if (result[m] == 0) {
                    result[m] = m / number
                }

            }
        }

    }

    return result
}

fun HashMap<Int, Int>.increment(key: Int) {
    this.compute(key) { _, v -> if (v != null) v + 1 else 1 }
}

fun HashMap<Int, Int>.decrement(key: Int) {
    this.computeIfPresent(key) { _, v -> if (v > 1) v - 1 else null }
}
