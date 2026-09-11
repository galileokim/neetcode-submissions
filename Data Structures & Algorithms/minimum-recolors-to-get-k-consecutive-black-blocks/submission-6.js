class Solution {
    /**
     * @param {string} blocks
     * @param {number} k
     * @return {number}
     */
    minimumRecolors(blocks, k) {
        let whites = 0
        if (blocks.length < k) {
            for (let i = 0; i < blocks.length; i++) {
                if (blocks[i] == "W") {
                    whites++
            }
            return whites
        }
        }

        let l = 0
        let r = k - 1
        console.log(blocks.slice(l,k))
        
        let min = Infinity

        for (let i = 0; i < k; i++) {
            if (blocks[i] == "W") {
                whites++
            }
        }

        console.log(whites)
        min = Math.min(whites, min)
        console.log(min)

        while (r < blocks.length) {
            min = Math.min(whites, min)

            if (blocks[l] == "W") {
                whites--
            }

            l += 1

            r += 1

            if (blocks[r] == "W") {
                whites++
            }
        }

        return min
    }
}
