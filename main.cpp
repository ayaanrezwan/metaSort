#include <iostream>
#include <vector>
#include <algorithm>

bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++)
        if (arr[i] < arr[i-1]) return false;
    return true;
}

bool isPermutation(const std::vector<int>& candidate, const std::vector<int>& original) {
    std::vector<int> a = candidate, b = original;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}

void metaSort(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> indices(n, 0);

    while (true) {
        std::vector<int> candidate(n);
        for (int i = 0; i < n; i++)
            candidate[i] = arr[indices[i]];

        if (isSorted(candidate) && isPermutation(candidate, arr)) {
            arr = candidate;
            return;
        }

        int pos = n - 1;
        while (pos >= 0 && ++indices[pos] == n) {
            indices[pos] = 0;
            pos--;
        }
        if (pos < 0) break;
    }
}

int main() {
    std::vector<int> arr = {9, 234, 5};
    metaSort(arr);
    for (int x : arr) std::cout << x << " ";
    std::cin.get();
    return 0;
}