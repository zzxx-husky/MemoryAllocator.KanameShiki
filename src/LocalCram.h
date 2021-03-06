#pragma once



namespace KanameShiki {



uint64_t NumLocalCram() noexcept;



class alignas(csCacheLine) LocalCram final : public Base, private NonCopyable<LocalCram> {
	public:
		~LocalCram() noexcept;
		
		LocalCram(LocalCntx* pOwner, uint16_t b);
		
		std::size_t Size(Parcel* pParcel) const noexcept;
		void Free(Parcel* pParcel) noexcept;
		void* Alloc(std::size_t s) noexcept;
		
		uint16_t Clearance() noexcept;
		void Delete() noexcept;
		
		void* operator new(std::size_t sThis, uint16_t b, const std::nothrow_t&) noexcept;
		
		void operator delete(void* p, uint16_t b, const std::nothrow_t&) noexcept	{ assert(false); }
		void operator delete(void* p) noexcept										{ assert(false); }
	
	private:
		uint16_t DecCache(uint16_t nCache) noexcept;
	
	
	private:
		std::thread::id mId;
		LocalCntx* mpOwner;
		uint16_t mb;
		uint16_t mRealm;
		
		std::size_t mvParcel;
		std::size_t meParcel;
		
		std::array<Cache<cnCramParcel>, cnFrac+1> maCache;
		
		alignas(csCacheLine) std::atomic_bool mbCache;
		alignas(csCacheLine) std::atomic_uint16_t mnCache;
};



}
