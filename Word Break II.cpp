class Solution {
public:

    set<string> myset;
    vector<string> vstring;
    bool ** pmatrix = NULL;
    string strtomatch;

    template<typename T>
    void BuildMatrix(T *** pmaze,unsigned row_num,unsigned column_num)
    {
        *pmaze = new T*[row_num];
        for(unsigned i=0;i<row_num;++i){
            (*pmaze)[i] = new T[column_num];
        }
    }

    template<typename T>
    void ReleaseMatrix(T ***pmaze,unsigned row_num)
    {
        if(!pmaze) return;

        for(unsigned i=0;i<row_num;++i){
            delete [](*pmaze)[i];
        }

        delete [](*pmaze);
    }

    void ListSentences(int i,int j,int length,string &strdata){
        if(i>=length) return;
        unsigned originallength = 0;
        for(i=++j;j<length;++j){
            if(pmatrix[i][j]){
                originallength = strdata.length();
                strdata.append(strtomatch,i,j-i+1);

                if(j==length-1){
                    vstring.push_back(strdata);
                }else{
                    strdata.append(" ");
                    ListSentences(i,j,length,strdata);
                    strdata.resize(originallength);
                }
            }
        }
    }

    vector<string> wordBreak(string &str, std::unordered_set<string> &myset) {
            strtomatch.assign(str);
            unsigned strlength = strtomatch.length();

            BuildMatrix(&pmatrix,strlength,strlength);

            for(int i=0;i<strlength;++i){
                for(int j=i;j<strlength;++j){
                    pmatrix[i][j] = false;
                }
            }

            for(unsigned i=0;i<strlength;++i){
                for(unsigned j=i;j<strlength;++j){
                    string strdata;
                    strdata.assign(strtomatch,i,j-i+1);
                    if(myset.find(strdata)!=myset.end()){
                        pmatrix[i][j] = true;
                    }
                }
            }

            for(int i=strlength-1;i>=0;--i){
                bool isallfalse = true;
                for(int j = i;j<strlength;++j){
                    if(pmatrix[i][j]){
                        isallfalse = false;
                        break;
                    }
                }

                if(isallfalse&&(i-1>=0)){
                    for(int j = 0;j<strlength;++j){
                        pmatrix[j][i-1] = false;
                    }
                }
            }

        string strintov;
        vstring.clear();
        ListSentences(0,-1,strlength,strintov);

        ReleaseMatrix(&pmatrix,strtomatch.length());
        return vstring;
        }
};