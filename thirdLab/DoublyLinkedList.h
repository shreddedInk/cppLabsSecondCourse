template <typename T>

class List {
    
public:
    virtual void insert(T value) = 0;
    virtual void insertAt(T value, class Iterator& it) = 0;
    virtual void removeAt(class Iterator& it) = 0;
    virtual class Iterator find(T value) = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
    virtual void clear() = 0;
    virtual class Iterator getIterator() = 0;
    virtual ~List() {}
};