#include<bits/stdc++.h>
using namespace std;


class Item
{
    public:
        int value, weight;

};
// Comparison function to descending sort Item according to val/weight ratio

bool cmp(struct Item a, struct Item b)
{

    double r1 = (double)a.value / a.weight;

    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}
int total_capcity;
int number_of_items;
vector<Item>vec;

double fractionalKnapsack()
{

    sort(vec.begin(),vec.end(), cmp);

    int curWeight = 0;
    double finalvalue = 0; // Result (value in Knapsack)

    for (int i = 0; i < number_of_items; i++)
    {
        if (curWeight + vec[i].weight <= total_capcity)
        {
            curWeight += vec[i].weight;
            cout<<vec[i].weight<<"kg  taken"<<endl;
            finalvalue += vec[i].value;
        }
        else
        {
            int remain_value = total_capcity - curWeight;


            finalvalue += vec[i].value * ((double) remain_value / vec[i].weight);


            break;
        }
    }
    cout<<"Maximum value in knapsack: "<<finalvalue<<endl;



}
int main()
{
    freopen("input.txt","r",stdin);
    //cout<<"Enter the total capacity of the knapsack:  ";
    cin>>total_capcity;
   // cout<<"Enter the number of items:  ";
    cin>>number_of_items;
    for(int i=0;i<number_of_items;i++)
    {
        int value,weight;
        cin>>value>>weight;
        Item get;
        get.value=value;
        get.weight=weight;
        vec.push_back(get);
    }
    fractionalKnapsack();
}
