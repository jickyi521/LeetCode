#字符串相加
# 1、将两个字符串补齐到同样的长度  2、对位上的字符串进行比较相加，看当前是否有进位要加，是否要进位

def addBinary(a,b):
    diff = abs(len(a)-len(b))
    if len(a) > len(b):
        b = "0"*diff + b
    else:
        a = "0"*diff + a
    ret=""
    carry = 0
    ai,bi=len(a)-1, len(b)-1
    while ai>=0 and bi>=0:
      ac, bc=a[ai], b[bi]
      if ac =="1" and bc == "1":
        if carry ==1:
            ret += "1"
        else:
            ret += "0"
        carry=1
      elif ac =="0" and bc == "0":
           if carry ==1:
                ret += "1"
           else:
                ret += "0"
           carry=0
      else:
          if carry ==1:
                ret += "0"
          else:
                ret += "1"
      ai -= 1
      bi -= 1
    
    if carry ==1:
        ret += "1"
    
    return ret[::-1] #ret[::-1] 代表从最后一个到第一个元素复制一遍新数组，即 reversed(ret)

print(addBinary("1010", "1010"))