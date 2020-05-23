def big_endian(arr,start,end):
    root = start
    child = root*2+1 #左孩子
    while child<=end:
      if child+1<=end and arr[child]<arr[child+1]
          child += 1
      if arr[root]<arr[child]:
          arr[root],arr[child] = arr[child],arr[root]
          root = child
          child = root*2+1
      else:
          break
def heap_sort(arr):
    first=len(arr)//2 - 1
    for start in range(first,-1,-1):
        big_endian(arr,start,len(arr)-1)
    for end in range(len(arr)-1,0,-1):
        arr[0],arr[end] = arr[end],arr[0]
        big_endian(arr,0,end-1)
    return arr
def main():
    l=[1,3,4,5,6,7,8,9,10]
if __name__=="__main__":
    main()   
            
