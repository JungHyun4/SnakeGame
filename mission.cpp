using namespace std;

class mission{
    public:
    int stage = 0;// 현재 stage 

    //단계별 미션 목록 idx 0 : score / 1: growth / 2:poison / 3:gate
    int m_list[3][4] = 
    {
        {10,5,2,1},
        {15,5,5,2},
        {20,8,5,3}
    };
};
