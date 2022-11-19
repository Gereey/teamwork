map<char,string> mp1{{'0',"零"},{'1',"壹"},{'2',"贰"},{'3',"叁"},{'4',"肆"},{'5',"伍"},{'6',"陆"},{'7',"柒"},{'8',"捌"},{'9',"玖"},{'a',"拾"},{'b',"佰"},{'c',"仟"},{'d',"万"},{'e',"亿"}};
map<int,string> mp{{0,"0"},{1,"1"},{2,"2"},{3,"3"},{4,"4"},{5,"5"},{6,"6"},{7,"7"},{8,"8"},{9,"9"}};
vector<int> s;
int count(long long num)
{
    string temp = to_string(num);
    return temp.size();
}
string func0(int num,int length)
{
    long long tempnum = num;
    string res;
    for(int i = 0;i < length;i ++)
    {
        int temp = tempnum % 10;
        int tt = tempnum / 10;
        int ttt = tt % 10;
        res = mp[temp] + res;
        if(i == 0 && i < 3 && ttt) res = "a" + res;
        if(i == 1 && i < 3 && ttt) res = "b" + res;
        if(i == 2 && i < 3 && ttt) res = "c" + res;
        tempnum /= 10;
    }
    return res;
}
string func1(long long num)
{
    int n = count(num);
    string res;
    int k = 0;
    if(n <= 4) k = n;
    if(n > 4 && n <= 8) k = n - 4;
    if(n > 8 && n <= 12) k = n - 8;
    int t = 0;
    int ff = 0;
    if(n > 4 && n <= 8) ff = 4;
    if(n > 8 && n <= 12) ff = 8;
    for(int i = n - 1;i >= ff;i --)
    {
        t = t * 10 + s[i]; 
    }
    int t1 = 0,t2 = 0;
    if(n > 4 && n <= 8) t1 = s[0] + s[1] * 10 + s[2] * 100 + s[3] * 1000;
    if(n > 8 && n <= 12)
    {
        t1 = s[0] + s[1] * 10 + s[2] * 100 + s[3] * 1000;
        t2 = s[4] + s[5] * 10 + s[6] * 100 + s[7] * 1000;
    }      
    if(n <= 4) return func0((int)num,n);
    if(n > 4 && n <= 8)
    {
        res =  func0(t,k) + "d" + func0(t1,4)  + res;
    }
    if(n > 8 && n <= 12) 
    {
        res = func0(t,k) + "e" +  func0(t2,4) + "d" + func0(t1,4) + res;
    }
    return res;
}
void solve(string str)
{
    long long num = 0;
    for(int i = 0;i < str.size();i ++)
    {
        num = num * 10 + str[i] - '0';
    }

    if(num == 0)
    {
        cout << "零" ;
        return;
    }
    auto tt = num;
    while(tt > 0)
    {
        s.push_back(tt % 10);
        tt /= 10;
    }
    string res = func1(num);
    //cout << res;
    string ans;
    for(int i = 0;i < res.size();i ++)
    {
        while(i < res.size() && res[i] == res[i - 1]) i ++;
        ans += res[i];
    }
    if(num==10||num==100||num==1000||num==10000||num==100000||num==1000000||num==10000000)
    {
        for(int i = 0;i < ans.size() - 2;i ++) 
        {
            cout << mp1[ans[i]];
        }
    }
    else
    {
        for(int i = 0;i < ans.size();i ++) 
        {
            cout << mp1[ans[i]];
        }
    }

}
