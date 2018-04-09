class MyHeap {
    int nums[10000];
    int cnt = 0;
    public:
    void insert(int x) {
        nums[++cnt] = x;
        int idx = cnt;
        while(idx != 1) {
            int par = idx / 2;
            if (x < nums[par]) {
                swap(nums[par], nums[idx]);
                idx = par;
            } else {
                break;
            }
        }
    }
    int top() {
        return nums[1];
    }
    void pop() {
        nums[1] = nums[cnt];
        cnt--;
        int cur = 1;
        while(cur < cnt) {
            int idx = cur;
            int ls = idx * 2;
            int rs = idx * 2 + 1;
            if (ls <= cnt && nums[ls] < nums[idx]) {
                idx = ls;
            }
            if (rs <= cnt && nums[rs] < nums[idx]) {
                idx = rs;
            }
            if (idx != cur) {
                swap(nums[idx], nums[cur]);
                cur = idx;
            } else {
                break;
            }
        }
    }
    int getSize() {
        return cnt;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        MyHeap myHeap;
        for (int i = 0; i < n; ++i) {
            if (myHeap.getSize() < k) {
                myHeap.insert(nums[i]);
            } else {
                int top = myHeap.top();
                if (nums[i] <= top) continue;
                myHeap.pop();
                myHeap.insert(nums[i]);
            }
        }
        return myHeap.top();
    }
};
