
# Question:
Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

For example, swapping at indices 0 and 2 in "abcd" results in "cbad".
 

- Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.
- Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.
Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.
 

Constraints:
1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters


# Approach
<img
  src="https://github.com/Glorycs29/Animated-Fluent-Emojis/blob/master/Emojis/Smilies/Alien%20Monster.png"
  alt="Alien Monster"
  width="25"
  height="25"
/>
## The approach of the code is as follows:

- First, the code checks if the lengths of the two input strings, s, and goal, are not equal or if the length of s is less than or equal to 1. If either of these conditions is true, the function returns false. This is because for the two strings to be buddy strings, they must have the same length and contain at least two differing characters.

- Next, the code checks if s and goal are identical. If they are, it means that all characters are the same. In this case, the code creates an set, distinctChars, to store the distinct characters from s. If the size of distinctChars is less than the length of s, it means there are duplicate characters, and we can swap two of them to make s and goal equal. The function returns true in this case.

- If the previous conditions are not met, it means that s and goal are different strings, and we need to check if they can be made equal by swapping exactly two characters.

- The code iterates through each character of s and goal simultaneously, comparing the characters at each index. Whenever a pair of characters at the same index is different, the index is added to the index vector.

- After iterating through both strings, the code checks if the size of the index is exactly 2. If it's not, it means there are either more or fewer than two differing characters, and the strings cannot be made equal by swapping two characters. In this case, the function returns false.

- If there are exactly two different characters, the code proceeds to swap these characters in s by using the indices stored in the index vector.

- Finally, the code checks if s is now equal to the goal after the swap. If they are equal, it means that s and goal can be made equal by swapping two characters, and the function returns true. Otherwise, it means the swap did not result in s becoming equal to the goal, and the function returns false.

## Complexity
- Time complexity: O(n)O(n)O(n)

- Space complexity: O(n)O(n)O(n)

1 <= s.length, goal.length <= 2 * 104
s and goal consist of lowercase letters.
