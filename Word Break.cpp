class Solution {
public:

bool ** pmatrix = NULL;

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

bool FindWord(int length){

    int i=0,j=0;
    for(j=i;j<length;++j){
        if(pmatrix[i][j]){
            if(j==length-1) return true;
            else i = j+1;
        }
    }

    return false;
}

bool wordBreak(string strtomatch, unordered_set<string> &myset) {
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

    bool ret = FindWord(strlength);

    ReleaseMatrix(&pmatrix,strtomatch.length());
    
    return ret;
}

};