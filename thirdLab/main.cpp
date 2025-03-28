int main() {
    CircularList<int> list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    
    auto it = list.getIterator();
    it.begin();
    while (it.hasNext()) {
        std::cout << it.currentValue() << " ";
        it.next();
    }
    return 0;
}