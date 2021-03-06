


using namespace KanameShiki;



void* operator new(std::size_t size)										{ Auto p = LocalCntxPtr()->Alloc(size); if (!p){ throw std::bad_alloc(); } return p; }
void* operator new[](std::size_t size)										{ Auto p = LocalCntxPtr()->Alloc(size); if (!p){ throw std::bad_alloc(); } return p; }
void operator delete(void* p) noexcept										{ Free(p); }
void operator delete[](void* p) noexcept									{ Free(p); }

void* operator new(std::size_t size, const std::nothrow_t& nt) noexcept		{ return LocalCntxPtr()->Alloc(size); }
void* operator new[](std::size_t size, const std::nothrow_t& nt) noexcept	{ return LocalCntxPtr()->Alloc(size); }
void operator delete(void* p, const std::nothrow_t& nt) noexcept			{ Free(p); }
void operator delete[](void* p, const std::nothrow_t& nt) noexcept			{ Free(p); }
