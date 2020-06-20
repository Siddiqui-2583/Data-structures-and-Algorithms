// C++ program for activity selection problem
#include <bits/stdc++.h>
using namespace std;

class  Activity
{
    public:
        int start, finish;

};
//ascending sort according to finishing time
bool activityCompare(Activity s1, Activity s2)
{
    return (s1.finish < s2.finish);
}

void printMaxActivities(vector<Activity>vec, int n)
{
    // Sort jobs according to finish time
    sort(vec.begin(), vec.end(), activityCompare);

    cout << "Maximum possible results are:  \n";

    vector<pair<int,int> >selected_reuslt;
    // The first activity always gets selected
    int i = 0;
    selected_reuslt.push_back(make_pair(vec[i].start,vec[i].finish));

    //traversing after the 1st index
    for (int j = 1; j < n; j++)
    {
      if (vec[j].start >= vec[i].finish)
      {
          selected_reuslt.push_back(make_pair(vec[j].start,vec[j].finish));
          i = j;
      }
    }
    for(auto x:selected_reuslt)
    {
        cout<<"("<<x.first<<","<<x.second<<")"<<endl;
    }
}
int main()
{
     freopen("input.txt","r",stdin);
    vector<Activity>vec;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int start,finish;

        cin>>start>>finish;
        Activity act;
        act.start=start;
        act.finish=finish;
        vec.push_back(act);

    }


    printMaxActivities(vec, n);
    return 0;
}
