class Solution {
    /**
     * @param {number[]} students
     * @param {number[]} sandwiches
     * @return {number}
     */
    countStudents(students, sandwiches) {
        
        while (this.studentHasPref(students, sandwiches)) {
            if (students[0] == sandwiches[0]) {
                students.shift()
                sandwiches.shift()
            } else {
                students.push(students.shift())
            }
            i += 1
            console.log(students, sandwiches)
        }

        return students.length
    }

    studentHasPref(students, sandwiches) {
        let std = new Set(students)

        if (sandwiches.length == 0) {
            return false
        }

        if (std.has(sandwiches[0])) {
            return true
        }
        return false

        // students = [0, 0] sandwiches = [1, 0, 0]
    }
}
