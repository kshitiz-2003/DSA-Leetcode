class Solution {
public:
    string reverseWords(string s) {
        //Optimal approach
        string result="";
        int i=s.size()-1;
        while(i>=0){
            //removing spaces
            while(i>=0 && s[i]==' '){
                i--;
            }

            //if the string is ended then break out
            if(i<0) break;

            //recording end of the word
            int end=i;

            //noting the word and finding its starting point
            while(i>=0 && s[i]!=' '){
                i--;
            }

            string word=s.substr(i+1,end-i);//s.substring(starting index,length of string)
            
            //ading space to result if we are not at starting point
            if(!result.empty()){
                result +=" ";
            }
            result += word;
        }
        return result;
    }
};