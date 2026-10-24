#include <vector>
#include <iterator>
#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <algorithm>
#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
void printVector(std::vector<int> vec, char *lable)
{
    std::cout << lable << ": ";
    auto it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << ",";
        it++;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> myvector{1, 4, 3, 6, 7, 51, 54, 63, 123, 51};
    std::vector<int> myvector2{3, -1, -2};
    // auto it=myvector.begin();
    std::vector<int>::iterator it = myvector.begin();
    while (it != myvector.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    std::cout << myvector.data() << std::endl;  // pointer to first elment in array
    std::cout << *myvector.data() << std::endl; // pointer to first elment in array
    printVector(myvector, "myvector");
    printVector(myvector2, "myvector2");
    swap(myvector2, myvector);
    printVector(myvector, "AfterSwap myvector");
    printVector(myvector2, "AfterSwap myvector2");
    std::sort(myvector2.begin(), myvector2.end());
    printVector(myvector2, "AfterSort myvector2");
    std::reverse(myvector2.begin(), myvector2.end());
    printVector(myvector2, "AfterReverse myvector2");
    auto s_it = std::find(myvector2.begin(), myvector2.end(), 51);
    if (s_it == myvector2.end())
        std::cout << "not found" << std::endl;
    else
        std::cout << *s_it << std::endl;
    auto c = std::count(myvector2.begin(), myvector2.end(), 51);
    std::cout << "found 51:" << c << " times." << std::endl;
    auto mi = std::min_element(myvector2.begin(), myvector2.end());
    std::cout << "found min:" << *mi << std::endl;
    auto ma = std::max_element(myvector2.begin(), myvector2.end());
    std::cout << "found max:" << *ma << std::endl;
    auto sum = std::accumulate(myvector2.begin(), myvector2.end(), 0);
    std::cout << "found sum:" << sum << std::endl;
    myvector2.push_back(2);
    myvector2.push_back(32);
    myvector2.push_back(89);
    myvector2.push_back(0);
    // ranges
    std::ranges::sort(myvector2);
    printVector(myvector2, "AfterSortRange myvector2");
    // printVector(myvector2,"AfterReverse myvector2");
    std::ranges::reverse(myvector2);
    printVector(myvector2, "AfterReverseRange myvector2");
    s_it=std::ranges::find(myvector2,51);
      if (s_it == myvector2.end())
        std::cout << "not found" << std::endl;
    else
        std::cout <<"found with ranges" <<*s_it << std::endl;
     c = std::ranges::count(myvector2, 51);
    std::cout << "found with ranges 51:" << c << " times." << std::endl;
    myvector2.push_back(123);
    myvector2.push_back(4);
    myvector2.push_back(2);
    std::sort(myvector2.begin(),myvector2.end());
    printVector(myvector2,"vector before remove duplicates :");
    myvector2.erase(std::unique(myvector2.begin(),myvector2.end()),myvector2.end());
    printVector(myvector2,"vector after remove duplicates  :");
    
    return 0;
}
