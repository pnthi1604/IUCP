#define in(...) { string _s = #__VA_ARGS__; replace(begin(_s), end(_s), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); out_error(_it, __VA_ARGS__);}
#define hi cout << "debug\n";
using namespace std;

void out_error(istream_iterator<string> it) { cerr << '\n'; }

template<typename T, typename ...Args>
void out_error(istream_iterator<string> it, T a, Args... args) {
    cerr << " [" << *it << " = " << a << "] ";
    out_error(++it, args...);
}

template<typename T, typename G> ostream& operator<<(ostream &os, const pair<T, G> &p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& os, const Con& container) {
    os << "{";
    for (auto it = container.begin(); it != container.end(); ++it)
        os << (it == container.begin() ? "" : ", ") << *it;
    return os << "}";
}

/*
ostream& operator<<(ostream &os, const chienBinh &cb) {
    os << "[can nang: " << cb.canNang << ", ";
    os << "chieu cao: " << cb.chieuCao << "]";
    return os;
}
*/
