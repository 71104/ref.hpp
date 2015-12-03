#include <utility>

template<typename T>
struct ref {
private:
	T *m_p;
public:
	inline ref() : m_p(0) {}
	inline ref(T *&&a_rrp) : m_p(std::move(a_rrp)) {}
	inline ref(ref<T> const&) = delete;
	inline ref(ref<T> &&a_rrp) : m_p(std::move(a_rrp.m_p)) { a_rrp.m_p = 0; }
	inline ~ref() { delete m_p; }
	inline ref<T> &operator = (ref<T> const&) = delete;
	inline ref<T> &operator = (ref<T> &&a_rrp) { return delete m_p, m_p = std::move(a_rrp.m_p), a_rrp.m_p = 0, *this; };
	inline ref<T> &operator = (T *&&a_rrp) { return delete m_p, m_p = std::move(a_rrp), *this; };
	inline operator T* () { return m_p; }
	inline operator T const* () const { return m_p; }
	inline T &operator * () { return *m_p; }
	inline T const &operator * () const { return *m_p; }
	inline T *operator -> () { return m_p; }
	inline T const *operator -> () const { return m_p; }
};
