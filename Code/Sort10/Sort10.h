#include<vector>
using namespace std;

class Sort10{
public:
    //1，插入——插入排序
    static void InsertSort(vector<int>& arr){
        for(int i=1;i<arr.size();i++){
            for(int j = i;j>=0;j--){
                if(arr[j - 1] <= arr[j]){
                    break;
                }else{
                    swap(arr[j],arr[j-1]);
                }
            }
        }
    }
    //2. 插入——折半插入
    static void BinaryInsertSort(vector<int>& arr){
        for(int i=1;i<arr.size();i++){
            //先找到插入的位置
            int left = 0;
            int right = i - 1;
            int mid = 0;
            while(left <= right){
                mid = (left + right) / 2;
                if(arr[mid] < arr[i]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }
            //此时right必定《=arr[i]
            int t= arr[i];
            for(int j = i-1;j>right;j--){
                arr[j+1] = arr[j];
            }
            arr[right+1] = t;
        }
    }
    //3. 插入——希尔排序
    static void ShellSort(vector<int>& arr){
        for(int step = arr.size() / 2;step>0;step /= 2){
            for(int i=step;i<arr.size();i++){
                for(int j = i;j>=0;j-= step){
                    if(arr[j - step] <= arr[j]){
                        break;
                    }else{
                        swap(arr[j],arr[j-step]);
                    }
                }
            }
        }
    }
    //4.交换——冒泡排序
    static void BubbleSort(vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            bool isSorted = true;
            for(int j = 0;j<arr.size() - i - 1;j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j],arr[j+1]);
                    isSorted = false;
                }
            }
            if(isSorted){
                break;
            }
        }
    }
    //5.交换——快速排序
    static void QuickSort(vector<int>& arr,int left,int right){
        
    }
private:
    static void swap(int &x,int &y){
        x = x + y;
        y = x - y;
        x = x - y;
    }
};