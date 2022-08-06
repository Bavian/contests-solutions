import kotlin.math.min

fun main() {

    for (i in 1..readLine()!!.toInt()) {
        readLine()!!

        var count0 = 0
        var count1 = 0
        var count2 = 0

        readLine()!!.split(" ").forEach{
            when(it.toInt() % 3) {
                0 -> count0++
                1 -> count1++
                2 -> count2++
            }
        }

        println(count0 + (count1 + count2 + min(count1, count2)) / 3)
    }

}