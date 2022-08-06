fun main() {

    val q = readLine()!!.toInt()

    for (i in 1..q) {
        var n = readLine()!!.toLong()
        var count = 0

        counting@ while (n != 1L) {

            when {

                n % 2 == 0L -> {
                    n /= 2
                    count++
                }

                n % 3 == 0L -> {
                    n /= 3
                    count += 2
                }

                n % 5 == 0L -> {
                    n /= 5
                    count += 3
                }

                else -> break@counting
            }

        }

        println(if (n == 1L) count else -1)
    }

}
