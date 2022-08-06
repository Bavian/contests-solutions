import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.max

fun main() {

    val input = BufferedReader(InputStreamReader(System.`in`))
    val output = BufferedWriter(OutputStreamWriter(System.out))

    val t = input.readLine()!!.toInt()

    for (i in 1..t) {

        val (n, m) = input.readLine()!!.split(" ").map{it.toInt()}
        val dsu = DSU(n)
        val colors = Coloring(n, 2)

        for (j in 1..m) {

            val (u, v) = input.readLine()!!.split(" ").map{it.toInt()}
            if (!dsu.isUnited(u, v)) {

                if (!colors.isDefined(u) and !colors.isDefined(v)) {
                    colors.paint(u, 0)
                    colors.paint(v, 1)
                } else if (!colors.isDefined(u)) {
                    colors.paint(u, ( colors.getColor(v) + 1 ) % 2)
                } else if (!colors.isDefined(v)) {
                    colors.paint(v, ( colors.getColor(u) + 1 ) % 2)
                }

                dsu.merge(u, v)
            }
        }

        val answer = colors.getSmallestColoring()
        output.write("${answer.size}\n${answer.joinToString(" ")}\n")

    }

    input.close()
    output.close()

}

class DSU(size: Int) {

    private val p = IntArray(size + 1){it}
    private val depth = IntArray(size + 1){0}

    private fun getParent(element: Int): Int {
        p[element] = if (p[element] == element) element else getParent(p[element])
        return p[element]
    }

    fun merge(a: Int, b: Int) {
        val pa = getParent(a)
        val pb = getParent(b)

        if (pa != pb) {
            val (x, y) = if (depth[pa] > depth[pb]) Pair(pa, pb) else Pair(pb, pa)

            p[y] = x
            depth[x] = max(depth[x], depth[y] + 1)
        }
    }

    fun isUnited(a: Int, b: Int): Boolean {
        return getParent(a) == getParent(b)
    }

}

class Coloring(size: Int, colorsCount: Int) {

    private val colors = IntArray(size + 1){-1}
    private val colorsVertices = Array(colorsCount) {ArrayList<Int>(size / colorsCount)}

    fun paint(v: Int, color: Int) {
        colors[v] = color
        colorsVertices[color].add(v)
    }

    fun getSmallestColoring(): ArrayList<Int> {

        var result = colorsVertices[0]
        for (array in colorsVertices) {
            result = if (array.size < result.size) array else result
        }

        return result
    }

    fun getColor(v: Int): Int {
        return colors[v]
    }

    fun isDefined(v: Int): Boolean {
        return colors[v] != -1
    }

}