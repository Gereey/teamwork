 bool JudgeErrorSToB(string a)
 {
     int length=a.length();
    //判断是否超出范围
    if(length>12)
    {
        return false;
    }
    else
    {
        //是否有前导0
        if(length>1)
        {
            if(a[0]=='0'){return false;}
            return true;
        }
         return true;
        
    }
    
 }