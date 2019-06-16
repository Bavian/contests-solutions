fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map{it.toInt()}

    val cnt = IntArray(7){0}
    cnt[0] = 1000000

    for (number in a) {

        val index = when(number) {
            4 -> 1
            8 -> 2
            15 -> 3
            16 -> 4
            23 -> 5
            42 -> 6
            else -> 0
        }

        cnt[index] += if (cnt[index - 1] != cnt[index]) 1 else 0
    }

    println(n - cnt[6] * 6)
}