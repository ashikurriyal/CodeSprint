/* Problem: MinimumTimeDifference 
Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.
 

Example 1:

Input: timePoints = ["23:59","00:00"]
Output: 1
Example 2:

Input: timePoints = ["00:00","23:59","00:00"]
Output: 0
 

Constraints:

2 <= timePoints.length <= 2 * 104
timePoints[i] is in the format "HH:MM".

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits> // For INT_MAX

using namespace std;

class Solution
{
public:
    int timeConvertToMinutes(string time)
    {
        int hourToMinute = stoi(time.substr(0, 2)) * 60;
        int minute = stoi(time.substr(3, 2));
        return hourToMinute + minute;
    }

    int findMinDifference(vector<string> &timePoints)
    {
        sort(begin(timePoints), end(timePoints));
        timePoints.push_back(timePoints[0]);

        int ans = INT_MAX, n = timePoints.size(), time_one, time_two;

        for (int i = 0; i < n - 1; i++)
        {
            time_one = timeConvertToMinutes(timePoints[i]);
            time_two = timeConvertToMinutes(timePoints[i + 1]);

            ans = min(ans, abs(time_one - time_two));
            ans = min(ans, abs(time_one - (1440 + time_two)));
        }
        return ans;
    }
};

int main()
{
    Solution ob;
    vector<string> timePoints;
    timePoints.push_back("23:59");
    timePoints.push_back("00:00");
    timePoints.push_back("12:30");

    cout << ob.findMinDifference(timePoints) << endl;

    return 0;
}
