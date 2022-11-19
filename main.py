

if __name__ == "__main__":
    Lownumber = [ 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 100 , 1000 , 10000 , 100000000 ]
    Upnumber = [ '零' , '壹' , '贰' , '叁' , '肆' , '伍' , '陆' , '柒' , '捌' , '玖' , '拾' , '佰' , '仟' , '万' ,
                 '亿' ]
    number= '壹仟零贰拾捌万元整'
    # 输出结果
    sum = 0
    # 中间数记录
    temp = 0
    # 权值位判断
    tempmax = -1
    # print(i)
    # 循环判断
    i = 0
    lenth = len(number)-2
    digittemp = 0
    while (i < lenth) :
        if (Upnumber.index(number [ i ]) < 10) :
            digittemp = Lownumber [ Upnumber.index(number [ i ]) ]
            flag = 1
            if(i == lenth-1):
                temp += digittemp
        else:
            if(tempmax != -1):
                if(tempmax < Upnumber.index(number [ i ])):
                    if(flag == 1):
                        temp += digittemp
                    temp = temp * Lownumber[Upnumber.index(number [ i ])]
                    sum += temp
                    temp = 0
                    tempmax = -1
                    flag = 0
                else:
                    temp = temp + digittemp * Lownumber[Upnumber.index(number [ i ])]
                    flag = 0
            else:
                tempmax = Upnumber.index(number [ i ])
                temp = temp + digittemp * Lownumber[Upnumber.index(number [ i ])]
                flag = 0
        i += 1
    print(sum+temp)
