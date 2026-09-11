class Solution {
    /**
     * @param {string} s
     * @param {string} t
     * @return {string}
     */
    minWindow(s, t) {
        let tDict = new Map()

        for (let c of t) {
            tDict.set(c, (tDict.get(c) || 0) + 1)
        }
        
        let l = 0
        let r = 0
        let sDict = new Map()
        let minString = ""
        let minLen = Infinity

        while (r < s.length) {
            
            if (tDict.has(s[r])) {
                sDict.set(s[r], (sDict.get(s[r]) || 0) + 1)
            }
                
            let contains_all = true
            for (let [key, val] of tDict) {
                if (!sDict.has(key) || sDict.get(key) < val) {
                    // we know we need to move the window to find the letters of t
                    contains_all = false
                    break
                }
            }

            while (contains_all) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1
                    minString = s.slice(l, r + 1)
                }

                if (tDict.has(s[l])) {
                    sDict.set(s[l], sDict.get(s[l]) - 1)
                }
                l += 1

                for (let [key, val] of tDict) {
                    if (!sDict.has(key) || sDict.get(key) < val) {
                        contains_all = false
                        break
                    }
                }
            }

            r += 1  
        }

        return minString
    }
}
