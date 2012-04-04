#include <stdint.h>

#if defined (__GLIBC__)
  #include <endian.h>
  #if (__BYTE_ORDER == __LITTLE_ENDIAN)
    #define BO_LITTLE_ENDIAN
  #elif (__BYTE_ORDER == __BIG_ENDIAN)
    #define BO_BIG_ENDIAN
  #else
    #error Unknown machine endianness detected.
  #endif
#elif defined(__BIG_ENDIAN)
  #define BO_BIG_ENDIAN
#elif defined(__LITTLE_ENDIAN)
  #define BO_LITTLE_ENDIAN
#elif defined(__sparc) || defined(__sparc__) \
   || defined(_POWER) || defined(__powerpc__) \
   || defined(__ppc__) || defined(__hpux) \
   || defined(_MIPSEB) || defined(_POWER) \
   || defined(__s390__)
  #define BO_BIG_ENDIAN
#elif defined(__i386__) || defined(__alpha__) \
   || defined(__ia64) || defined(__ia64__) \
   || defined(_M_IX86) || defined(_M_IA64) \
   || defined(_M_ALPHA) || defined(__amd64) \
   || defined(__amd64__) || defined(_M_AMD64) \
   || defined(__x86_64) || defined(__x86_64__) \
   || defined(_M_X64)
  #define BO_LITTLE_ENDIAN
#else
  #error Please file an issue on Github (alexchamberlain/byte-order) with CPU type.
#endif


inline uint32_t htobel(uint32_t v) {
  #ifdef BO_BIG_ENDIAN
    return v;
  #else
    uint32_t ret;
    uint8_t * data = (uint8_t*) &ret;

    data[0] = v/(2 << 23);
    v %= (2 << 24);
    data[1] = v/(2 << 15);
    v %= (2 << 16);
    data[2] = v/(2 <<  7);
    v %= (2 <<  8);
    data[3] = v;

    return ret;
  #endif
}

inline uint32_t betohl(uint32_t v) {
  #ifdef BO_BIG_ENDIAN
    return v;
  #else
    uint8_t * data = (uint8_t*) &v;
    return (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
  #endif
}

inline uint32_t htolel(uint32_t v) {
  #ifdef BO_LITTLE_ENDIAN
    return v;
  #else
    uint32_t ret;
    uint8_t * data = (uint8_t*) &ret;

    data[3] = v/(2 << 23);
    v %= (2 << 24);
    data[2] = v/(2 << 15);
    v %= (2 << 16);
    data[1] = v/(2 <<  7);
    v %= (2 <<  8);
    data[0] = v;

    return ret;
  #endif
}

inline uint32_t letohl(uint32_t v) {
  #ifdef BO_LITTLE_ENDIAN
    return v;
  #else
    uint8_t * data = (uint8_t*) &v;
    return (data[3]<<0) | (data[2]<<8) | (data[1]<<16) | (data[0]<<24);
  #endif
}

#ifdef __cplusplus
  /* C++ Overloads */
  inline uint32_t htobe(uint32_t v) {return htobel(v);}
  inline uint32_t betoh(uint32_t v) {return betohl(v);}
  inline uint32_t htole(uint32_t v) {return htolel(v);}
  inline uint32_t letoh(uint32_t v) {return letohl(v);}
#endif
