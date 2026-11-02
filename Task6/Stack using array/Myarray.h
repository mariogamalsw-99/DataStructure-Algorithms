#ifndef MY_ARRAY_H
#define MY_ARRAY_H
template <typename T>
class MYArray
{
private:
    T *ptr;
    int mysize;
    int cap;
    void doubleSize()
    {
        // alocate new space
        T *newptr = new T[cap * 2];
        // copy to new space
        for (int i = 0; i < mysize; i++)
        {
            newptr[i] = ptr[i];
        }
        // clear old space
        delete ptr;
        ptr = newptr;
        // douple the cap
        cap *= 2;
    }
    void checkLimit()
    {
        if (mysize == cap)
        {
            doubleSize();
        }
    }
    void shiftsubright(int offset, int start, int end)
    {
        if (end + offset >= cap)
        {
            throw std::invalid_argument("Wrog shift out of scope");
        }

        for (int i = end; i >= start; i--)
        {
            ptr[i + offset] = ptr[i];
        }
    }
    void shiftsubleft(int offset, int start, int end)
    {
        if (start - offset < 0)
        {
            throw std::invalid_argument("Wrog shift out of scope");
        }

        for (int i = start; i <= end; i++)
        {
            ptr[i - offset] = ptr[i];
        }
    }
    void swap(int i, int j)
    {
        int temp = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = temp;
    }

public:
    MYArray(int s, int cap1) : mysize(s), cap(cap1)
    {
        ptr = new T[cap1];
    }
    ~MYArray()
    {
        delete[] ptr;
    }
    int getSize()
    {
        return mysize;
    }
    void display()
    {
        for (int i = 0; i < mysize; i++)
        {
            std::cout << ptr[i] << ",";
        }
        std::cout << std::endl;
    }
    void add(T x)
    {
        checkLimit();
        // add the new elment
        ptr[mysize++] = x;
    }
    void insert(int id, T x)
    {
        checkLimit();
        shiftsubright(1, id, mysize - 1);
        ptr[id] = x;
        mysize++;
    }
    void remove(int id)
    {
        shiftsubleft(1, id + 1, mysize - 1);
        mysize--;
    }
    // return index of first ocurance if not found return -1
    int search(T srch)
    {
        int res = -1;
        for (int i = 0; i < mysize; i++)
        {
            if (ptr[i] == srch)
            {
                res = i;
                break;
            }
        }
        return res;
    }
    T get(int id)
    {
        if (id < 0 || id >= mysize)
        {
            throw std::invalid_argument("Get out of scope");
        }
        else
            return ptr[id];
    }
    void set(int id, T x)
    {
        if (id < 0 || id >= mysize)
        {
            throw std::invalid_argument("Get out of scope");
        }
        else
            ptr[id] = x;
    }
    T min()
    {
        if (mysize == 0)
        {
            throw std::invalid_argument("arrray is empty");
        }
        int min = ptr[0];
        for (int i = 1; i < mysize; i++)
        {
            if (min > ptr[i])
            {
                min = ptr[i];
            }
        }
        return min;
    }
    T max()
    {
        if (mysize == 0)
        {
            throw std::invalid_argument("arrray is empty");
        }
        int max = ptr[0];
        for (int i = 1; i < mysize; i++)
        {
            if (max < ptr[i])
            {
                max = ptr[i];
            }
        }
        return max;
    }
    void reverse()
    {
        int left = 0, right = mysize - 1;
        while (left < right)
        {
            // swap
            swap(left, right);
            left++;
            right--;
        }
    }
    void shiftRight(int x)
    {
        mysize -= x;
    }
    void shiftLeft(int x)
    {
        shiftsubleft(x, x, mysize - 1);
        mysize -= x;
    }
    void rotateRight(int x)
    {
        // save right x elments
        int *newptr = new int[x];
        for (int i = 0; i < x; i++)
        {
            newptr[i] = ptr[mysize + (-x + i)];
        }
        shiftsubright(x, 0, mysize - x - 1);
        // add saved x elment
        for (int i = 0; i < x; i++)
        {
            ptr[i] = newptr[i];
        }
        delete newptr;
    }
    void rotateLeft(int x)
    {
        // save left x elments
        int *newptr = new int[x];
        for (int i = 0; i < x; i++)
        {
            newptr[i] = ptr[i];
        }
        shiftsubleft(x, x, mysize - 1);
        // add saved x elment
        for (int i = 0; i < x; i++)
        {
            ptr[(mysize - x) + i] = newptr[i];
        }
        delete newptr;
    }
    void merge(MYArray b)
    {
        while ((mysize + b.getSize()) > cap)
        {
            doubleSize();
        }
        for (int i = 0; i < b.getSize(); i++)
        {
            add(b.get(i));
        }
    }
    T sum()
    {
        int sum = 0;
        for (int i = 0; i < mysize; i++)
        {
            sum += ptr[i];
        }
        return sum;
    }
    double avg()
    {
        return double(sum()) / mysize;
    }
    void replace(int x, int y)
    {
        swap(x, y);
    }
};


#endif