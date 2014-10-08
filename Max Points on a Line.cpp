/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 
bool typeisless(const Point &data1,const Point &data2){
    return data1.x < data2.x;
}
 
class Solution {
public:

    int maxPoints(vector<Point> &points) {
        if(points.size()==0) return 0;

        int last_x = (points.begin()->x) - 1;
        int maxnum = INT_MIN,curnum = 0;
        std::sort(points.begin(),points.end(),typeisless);
        for(vector<Point>::iterator iter = points.begin();
            iter != points.end();++iter){
            if(iter->x == last_x){
                ++curnum;
            }else{
                last_x = iter->x;
                curnum = 1;
            }

            maxnum = maxnum<curnum?curnum:maxnum;
        }

        unordered_map<double,int> count_map;
        count_map.insert(pair<double,int>(0.0,0));

        for(vector<Point>::iterator iter1 = points.begin();
            iter1 != points.end();++iter1){
            count_map.clear();
            int samepointnum = 0;

            for(vector<Point>::iterator iter2 = iter1 + 1;
                iter2 != points.end();++iter2){

                if(iter2->x == iter1->x && iter2->y == iter1->y){
                   ++samepointnum;continue;
                }else if(iter2->x == iter1->x)
                    continue;
                else{
                    double dslope = (static_cast<double>(iter2->y - iter1->y))/
                                    (static_cast<double>(iter2->x - iter1->x));
                    if(count_map.find(dslope) != count_map.end()) ++count_map[dslope];
                    else{
                        count_map[dslope] = 1;
                        ++count_map[dslope];
                    }
                }
            }

            for(unordered_map<double,int>::iterator iter=count_map.begin();
                iter!=count_map.end();++iter){
                if(iter->second + samepointnum > maxnum){
                    maxnum = iter->second + samepointnum;
                }
            }
        }
        
        return maxnum;
    }
};