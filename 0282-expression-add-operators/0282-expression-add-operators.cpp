class Solution {
    private:
    void Solve(string num,int target,vector<string>& ans,int i,const string& path,long eval,long residual){
        if(i==num.size()){
            if(eval==target){
                ans.push_back(path);
            }
            return;
        }
        string currStr;
        long numb=0;
        //Recusion
        for(int j=i;j<num.size();j++){
            // handle 0
            if(j>i && num[i]=='0') return;//checking for 08 if our number is not 0 but 08 like 1208 if i starts from 2 and j=3
            currStr+=num[j];
            numb=numb*10+num[j]-'0';
            if(i==0){
                Solve(num,target,ans,j+1,path+currStr,numb,numb);
            }
            else{
                Solve(num,target,ans,j+1,path+'+'+currStr,eval+numb,numb);
                Solve(num,target,ans,j+1,path+'-'+currStr,eval-numb,-numb);
                Solve(num,target,ans,j+1,path+'*'+currStr,(eval-residual)+(residual*numb),residual*numb);

            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        // optimal Approach backtracking
        //https://www.youtube.com/watch?v=GfxBod3HN9Y
        // code
        vector<string> ans;
        Solve(num,target,ans,0,"",0,0);
        return ans;
    }
};