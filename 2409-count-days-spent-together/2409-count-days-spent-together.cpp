class Solution {
    private:
    int findDays(string day,vector<int>& cumMonthDay){
        // stoi is string to integer function
        int month=stoi(day.substr(0,2));
        int days=stoi(day.substr(3,day.size()));
        return cumMonthDay[month-1]+days;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Optimal Solution
        // https://www.youtube.com/watch?v=RK9v3tuy8X4
        // code
        vector<int> monthdays={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> cumMonthDay(13,0);
        // 1 ind of cumMonthDay =january
        // 2 ind of cumMonthDay =february
        cumMonthDay[1]=31;
        for(int i=2;i<=12;i++){
            cumMonthDay[i]=cumMonthDay[i-1]+monthdays[i-1];
        }

        int arriveAliceDays=findDays(arriveAlice,cumMonthDay);
        int leaveAliceDays=findDays(leaveAlice,cumMonthDay);
        int arriveBobDays=findDays(arriveBob,cumMonthDay);
        int leaveBobDays=findDays(leaveBob,cumMonthDay);

        int result=min(leaveAliceDays,leaveBobDays)-max(arriveAliceDays,arriveBobDays)+1;
        return result<0?0:result;
    }
};