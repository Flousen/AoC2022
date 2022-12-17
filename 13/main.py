import sys


def compare(l,r):
  if type(l) != type(r):
    print("types are not equal")
  if isinstance(l, int) and  isinstance(r, int):
    if l>r:
      #print('false', l, r)
      return False
    elif l<r:
      #print('true', l, r)
      return True
    elif l==r:
      return None
  else:
    for c, v in enumerate(l):
      if len(r)-1 < c:
        #print('short')
        return False
      elif (isinstance(v, list) and isinstance(r[c], list)) or (isinstance(v, int) and isinstance(r[c], int) ):
        res = compare(v,r[c]);
        if res is not None:
          return res
      elif isinstance(v, int) and isinstance(r[c], list):
        res = compare([v],r[c])
        if res is not None:
          return res
      elif isinstance(v, list) and isinstance(r[c], int):
        res = compare(v,[r[c]])
        if res is not None:
          return res
    return True
      
      


count=0
sol=0
while True:
  count = count + 1
  left = sys.stdin.readline()
  right = sys.stdin.readline()
  line3 = sys.stdin.readline()
  if not left: break  # EOF
  
  l = eval(left)
  r = eval(right)
  #print(count,' ',l,'#',r)
 
  
  res=compare(l,r)
  if (res is None) or res:
    #if (res is None): print('final')
    sol += count


  

print ("count ",sol)