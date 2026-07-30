class Solution {
public:
    bool isValid(string s) {
      int prev = -1;

        while (prev != s.length()) {
            prev = s.length();

            size_t pos;

            while ((pos = s.find("()")) != string::npos)
                s.erase(pos, 2);

            while ((pos = s.find("{}")) != string::npos)
                s.erase(pos, 2);

            while ((pos = s.find("[]")) != string::npos)
                s.erase(pos, 2);
        }

        return s.empty();
    }   
    
};