
class Solution {
public:
    int convert(string date, vector<int>& days) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return days[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice,
     string leaveAlice,
     string arriveBob,
     string leaveBob) {
        vector<int> days = {
      0, 31, 59, 90, 120, 151,
     181, 212, 243, 273, 304, 334
};
        int a1 = convert(arriveAlice, days);
        int a2 = convert(leaveAlice, days);
        int b1 = convert(arriveBob, days);
        int b2 = convert(leaveBob, days);
        int start = max(a1, b1);
        int end = min(a2, b2);
        if (start > end)
            return 0;
        return end - start + 1;
    }
};
