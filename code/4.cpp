//better codes
class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m > n) return findMedianSortedArrays(B, n, A, m);
    int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1,num2;
    while (minidx <= maxidx)
    {
      i = (minidx + maxidx) >> 1;
      j = mid - i;
      if (i<m && j>0 && B[j-1] > A[i]) minidx = i + 1;
      else if (i>0 && j<n && B[j] < A[i-1]) maxidx = i - 1;
      else
      {
        if (i == 0) num1 = B[j-1];
        else if (j == 0) num1 = A[i - 1];
        else num1 = max(A[i-1],B[j-1]);
        break;
      }
    }
    if (((m + n) & 1)) return num1;
    if (i == m) num2 = B[j];
    else if (j == n) num2 = A[i];
    else num2 = min(A[i],B[j]);
    return (num1 + num2) / 2.;
  }
};
//my codes
class Solution {
public:
    double find_kth_num(vector<int>&nums1,int m,vector<int>&nums2,int n,int k)
    {
        if(m>n)
            return find_kth_num(nums2,n,nums1, m, k);
        if(m==0) 
            return nums2[k-1];
        if(k==1)
            return min(nums1[0],nums2[0]);
        int l1=min(m,k/2);
        int l2=k-l1;
        if(nums1[l1-1]==nums2[l2-1])
            return nums1[l1-1];
        else if(nums1[l1-1]<nums2[l2-1])
        {
           vector<int> a(nums1.begin()+l1,nums1.end()+1);
            return find_kth_num(a,m-l1,nums2,n,k-l1);
        }
            
        else if(nums1[l1-1]>nums2[l2-1])
        {
            vector<int> a(nums2.begin()+l2,nums2.end()+1);
            return find_kth_num(nums1,m,a,n-l2,k-l2);
        }
            
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0)
        {
            if(nums2.size()%2==0)
                return double((nums2[(nums2.size()-2)/2]+nums2[(nums2.size())/2]))/2;
            else
                return nums2[(nums2.size()-1)/2];
        }
        if(nums2.size()==0)
        {
            if(nums1.size()%2==0)
                return double((nums1[(nums1.size()-2)/2]+nums1[(nums1.size())/2]))/2;
            else
                return nums1[(nums1.size()-1)/2];
        }
        if((nums1.size()+nums2.size())%2==1)
            return find_kth_num(nums1,nums1.size(),nums2,nums2.size(),(nums1.size()+nums2.size()+1)/2);
        else
            return (find_kth_num(nums1,nums1.size(),nums2,nums2.size(),(nums1.size()+nums2.size())/2)
                +find_kth_num(nums1,nums1.size(),nums2,nums2.size(),(nums1.size()+nums2.size()+2)/2))/2;
    }
};
