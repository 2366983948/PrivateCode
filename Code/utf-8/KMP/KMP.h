#include <vector>
#include <string>

/**
 * KMP算法类，用于字符串的模式匹配
 */
class KMP {
public:
    /**
     * 构造函数，初始化KMP算法需要的部分匹配表
     * @param pattern 模式字符串
     */
    KMP(const std::string& pattern) {
        buildPartialMatchTable(pattern);
    }

    /**
     * 在给定的文本中寻找与模式串匹配的位置
     * @param text 给定的文本字符串
     * @return 匹配位置的向量
     */
    std::vector<int> findMatches(const std::string& text) const {
        std::vector<int> matches; // 存储匹配位置
        int m = pattern_.size(); // 模式串长度
        int n = text.size(); // 文本串长度

        int i = 0; // 文本串指针
        int j = 0; // 模式串指针

        // 遍历文本串
        while (i < n) {
            if (text[i] == pattern_[j]) {
                ++i;
                ++j;
                // 当模式串匹配结束时，记录匹配位置，并进行回溯
                if (j == m) {
                    matches.push_back(i - m);
                    j = partialMatchTable_[j - 1];
                }
            } else if (j > 0) {
                // 如果当前字符不匹配，则利用部分匹配表进行回溯
                j = partialMatchTable_[j - 1];
            } else {
                // 如果模式串指针为0，直接移动文本串指针
                ++i;
            }
        }

        return matches;
    }

private:
    std::string pattern_; // 存储模式串
    std::vector<int> partialMatchTable_; // 存储部分匹配表

    /**
     * 构建模式串的部分匹配表
     * @param pattern 模式字符串
     */
    void buildPartialMatchTable(const std::string& pattern) {
        pattern_ = pattern;
        int m = pattern.size();
        partialMatchTable_.resize(m);

        // 初始化部分匹配表
        partialMatchTable_[0] = 0;
        for (int i = 1, j = 0; i < m; ++i) {
            // 根据已构建的部分匹配表和当前字符，更新部分匹配表
            while (j > 0 && pattern[i] != pattern[j]) {
                j = partialMatchTable_[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                ++j;
            }
            partialMatchTable_[i] = j;
        }
    }
};