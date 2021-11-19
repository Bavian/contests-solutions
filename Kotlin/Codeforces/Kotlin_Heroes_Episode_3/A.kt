import kotlin.math.abs
 
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        if (n < 1000) {
            println(n)
        } else {
            val roundedToThousands = round(n, 1000)
            if (roundedToThousands < 1000) {
                println(roundedToThousands.toString() + "K")
            } else {
                println(round(n, 1000000).toString() + "M")
            }
        }
    }
}
 
fun round(n: Int, d: Int): Int {
    val left = n / d
    val right = left + 1
    return if (abs(left * d - n) < abs(right * d - n)) left else right
}

