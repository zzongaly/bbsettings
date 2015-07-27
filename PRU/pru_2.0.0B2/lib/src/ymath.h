/* ymath.h internal header */
#ifndef _YMATH
#define _YMATH
#include <yvals.h>
#include <float.h>
_C_STD_BEGIN
_C_LIB_DECL

		/* MACROS FOR _FPP_TYPE */
#define _FPP_NONE	0	/* software emulation of FPP */
#define _FPP_X86	1	/* Intel Pentium */
#define _FPP_SPARC	2	/* Sun SPARC */
#define _FPP_MIPS	3	/* SGI MIPS */
#define _FPP_S390	4	/* IBM S/390 */
#define _FPP_PPC	5	/* Motorola PowerPC */
#define _FPP_HPPA	6	/* Hewlett-Packard PA-RISC */
#define _FPP_ALPHA	7	/* Compaq Alpha */
#define _FPP_ARM	8	/* ARM ARM */
#define _FPP_M68K	9	/* Motorola 68xxx */
#define _FPP_SH4	10	/* Hitachi SH4 */
#define _FPP_IA64	11	/* Intel IA64 */
#define _FPP_WCE	12	/* EDG Windows CE */

		/* MACROS FOR _Dtest RETURN (0 => ZERO) */
#define _DENORM		(-2)	/* C9X only */
#define _FINITE		(-1)
#define _INFCODE	1
#define _NANCODE	2

		/* MACROS FOR _Feraise ARGUMENT */

 #if _FPP_TYPE == _FPP_X86
  #define _FE_DIVBYZERO	0x04
  #define _FE_INEXACT	0x20
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x10

 #elif _FPP_TYPE == _FPP_SPARC
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_MIPS
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_S390
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #elif _FPP_TYPE == _FPP_PPC
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_HPPA
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #elif _FPP_TYPE == _FPP_ALPHA
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x10
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x08

 #elif _FPP_TYPE == _FPP_ARM
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x10
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x08

 #elif _FPP_TYPE == _FPP_M68K
  #define _FE_DIVBYZERO	0x02
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x04

 #elif _FPP_TYPE == _FPP_SH4
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

 #elif _FPP_TYPE == _FPP_IA64
  #define _FE_DIVBYZERO	0x04
  #define _FE_INEXACT	0x20
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x10

 #elif _FPP_TYPE == _FPP_WCE
  #define _FE_DIVBYZERO	0x08
  #define _FE_INEXACT	0x01
  #define _FE_INVALID	0x10
  #define _FE_OVERFLOW	0x04
  #define _FE_UNDERFLOW	0x02

#else /* _FPP_TYPE == _FPP_NONE or unknown */
  #undef _FPP_TYPE
  #define _FPP_TYPE	_FPP_NONE

  #define _FE_DIVBYZERO	0x04	/* dummy same as Pentium */
  #define _FE_INEXACT	0x20
  #define _FE_INVALID	0x01
  #define _FE_OVERFLOW	0x08
  #define _FE_UNDERFLOW	0x10
 #endif /* _FPP_TYPE */

		/* TYPE DEFINITIONS */
typedef union
	{	/* pun float types as integer array */
	unsigned short _Word[8];
	float _Float;
	double _Double;
	long double _Long_double;
	} _Dconst;

		/* ERROR REPORTING */
void _Feraise(int);

		/* double DECLARATIONS */
double _Cosh(double, double);
short _Exp(double *, double, short);
double _Log(double, int);
double _Sin(double, unsigned int);
double _Sinh(double, double);
extern /* const */ _DATA_ACCESS _Dconst _Denorm, _Hugeval, _Inf,
	_Nan, _Snan;

		/* float DECLARATIONS */
float _FCosh(float, float);
short _FExp(float *, float, short);
float _FLog(float, int);
float _FSin(float, unsigned int);
float _FSinh(float, float);
extern /* const */ _DATA_ACCESS _Dconst _FDenorm, _FInf, _FNan, _FSnan;

		/* long double DECLARATIONS */
long double _LCosh(long double, long double);
short _LExp(long double *, long double, short);
long double _LLog(long double, int);
long double _LSin(long double, unsigned int);
long double _LSinh(long double, long double);
extern /* const */ _DATA_ACCESS _Dconst _LDenorm, _LInf, _LNan, _LSnan;



/* _ILONG == 0 means 16-bit int so use long instead */
#if _ILONG == 1
 typedef unsigned int   _TI_uint32_t;
#else
 typedef unsigned long  _TI_uint32_t;
#endif 

/* Assume all TI targets that have a 64-bit double have a 64-bit long long */
typedef unsigned long long _TI_uint64_t;

#define _TI_TARGET_USES_BITS_INTRINSICS \
    (defined(__MSP430__) || defined(__ARP32__) || \
     defined(__TMS320C2000__) || defined(__PRU__))

/*---------------------------------------------------------------------------*/
/*                  FLOATING POINT INTRINSICS - FLOAT DEFINES                */
/*---------------------------------------------------------------------------*/
#define _TI_FBIAS_FLOAT _FBIAS
#define _TI_FBITS_FLOAT FLT_MANT_DIG
#define _TI_FMAXEXP_FLOAT FLT_MAX_EXP
#define _TI_BIT_MASK_FLOAT(n) (((_TI_uint32_t)(1) << (n)) - 1)
#define _TI_EXP_BITS_MASK_FLOAT ((_TI_FMAXEXP_FLOAT << 1) - 1)
#define _TI_SGN_TEST_MASK_FLOAT ((_TI_uint32_t)(1) << (32-1))
#define _TI_EXP_TEST_MASK_FLOAT 0x7f80

#if _TI_TARGET_USES_BITS_INTRINSICS
 #define _TI_FTOU_FLOAT __f32_bits_as_u32
 #define _TI_UTOF_FLOAT __u32_bits_as_f32
#else
 #define _TI_FTOU_FLOAT _ftoi
 #define _TI_UTOF_FLOAT _itof
#endif 

#define _TI_SIGN_BIT_ZERO_FLOAT(f) \
    ((_TI_FTOU_FLOAT(f) & _TI_SGN_TEST_MASK_FLOAT) == 0)

#define _TI_BIASED_EXP_FLOAT(f) \
   (((unsigned int)(_TI_FTOU_FLOAT(f) >> 23)) & _TI_EXP_BITS_MASK_FLOAT)

#define _TI_BIASED_EXP_IS_MAX_FLOAT(f) \
   ((((unsigned int)(_TI_FTOU_FLOAT(f) >> 16)) & \
     _TI_EXP_TEST_MASK_FLOAT) == _TI_EXP_TEST_MASK_FLOAT)

#define _TI_FRAC_PART_FLOAT(f) \
   (_TI_FTOU_FLOAT(f) & _TI_BIT_MASK_FLOAT(_TI_FBITS_FLOAT-1))

#define _TI_FRAC_PART_IS_ZERO_FLOAT(f) (_TI_FRAC_PART_FLOAT(f) == 0)

#define _TI_DISCARD_N_FRAC_BITS_FLOAT(v,n) \
    _TI_UTOF_FLOAT(_TI_FTOU_FLOAT(v) & ~_TI_BIT_MASK_FLOAT(n))

#define _TI_DISCARD_EXP_AND_FRAC_PARTS_FLOAT(v) \
    _TI_UTOF_FLOAT(_TI_FTOU_FLOAT(v) & _TI_SGN_TEST_MASK_FLOAT)

#define _TI_UNBIASED_EXP_FLOAT(f) \
   (_TI_BIASED_EXP_FLOAT(f) - (_TI_FBIAS_FLOAT+1))

#define _TI_BIASED_EXP_PART_IS_ZERO_FLOAT(f) (_TI_BIASED_EXP_FLOAT(f) == 0)

#define _TI_EXP_AND_FRAC_PART_IS_ZERO_FLOAT(f) \
    ((_TI_FTOU_FLOAT(f) & ~_TI_SGN_TEST_MASK_FLOAT)==0)

#define _TI_HAS_BF_SQRT_FLOAT \
    (defined(__TMS470__) && defined(__TI_VFP_SUPPORT__))

#define _TI_TYPED_SQRT_FLOAT(n) __sqrtf(n)

/*---------------------------------------------------------------------------*/
/*                 FLOATING POINT INTRINSICS - DOUBLE DEFINES                */
/*---------------------------------------------------------------------------*/
#if defined(_32_BIT_DOUBLE)
#define _TI_FBIAS_DOUBLE _TI_FBIAS_FLOAT
#define _TI_EXP_TEST_MASK_DOUBLE _TI_EXP_TEST_MASK_FLOAT
#else
#define _TI_FBIAS_DOUBLE _DBIAS
#define _TI_EXP_TEST_MASK_DOUBLE 0x7ff0
#endif
#define _TI_FBITS_DOUBLE DBL_MANT_DIG
#define _TI_FMAXEXP_DOUBLE DBL_MAX_EXP
#define _TI_EXP_BITS_MASK_DOUBLE ((_TI_FMAXEXP_DOUBLE << 1) - 1)

/*---------------------------------------------------------------------------*/
/* This code requires the target to support type-punning intrinsics.  These  */
/* intrinsics treat the bits of a floating-point value as if it were an      */
/* integer, to allow fast access to the sign, exponent, and fractional bits. */
/* We need to know whether the target has an intrinsic that can represent    */
/* the entire floating-point type with one integral type.                    */
/*---------------------------------------------------------------------------*/

#if DBL_MANT_DIG == 24 /* DBL_MANT_DIG == 24 implies _32_BIT_DOUBLE */
 #define _TI_DOUBLE_SIZE 32
#else
 #define _TI_DOUBLE_SIZE 64
#endif

#if _TI_DOUBLE_SIZE == 32
 #define _TI_BIT_MASK_DOUBLE      _TI_BIT_MASK_FLOAT
 #define _TI_SGN_TEST_MASK_DOUBLE _TI_SGN_TEST_MASK_FLOAT   
 #define _TI_FTOU_DOUBLE          _TI_FTOU_FLOAT
 #define _TI_UTOF_DOUBLE          _TI_UTOF_FLOAT
#elif !_TI_TARGET_USES_BITS_INTRINSICS
 #define _TI_BIT_MASK_DOUBLE(n) (((_TI_uint32_t)(1) << (n)) - 1)
 #define _TI_SGN_TEST_MASK_DOUBLE \
     ((_TI_uint32_t)(1) << (31))
/* Do not define _TI_FTOU_DOUBLE or _TI_UTOF_DOUBLE since the target
   does not support them.                                                    */
#else
 #define _TI_BIT_MASK_DOUBLE(n) (((_TI_uint64_t)(1) << (n)) - 1)
 #define _TI_SGN_TEST_MASK_DOUBLE \
     ((_TI_uint64_t)(1) << (63))

 #define _TI_FTOU_DOUBLE __f64_bits_as_u64
 #define _TI_UTOF_DOUBLE __u64_bits_as_f64
#endif

#if _TI_TARGET_USES_BITS_INTRINSICS

 #define _TI_SIGN_BIT_ZERO_DOUBLE(f) \
    ((_TI_FTOU_DOUBLE(f) & _TI_SGN_TEST_MASK_DOUBLE) == 0)

 #define _TI_BIASED_EXP_DOUBLE(f) \
    ((_TI_FTOU_DOUBLE(f) >> (_TI_FBITS_DOUBLE-1)) & _TI_EXP_BITS_MASK_DOUBLE)

 #define _TI_BIASED_EXP_IS_MAX_DOUBLE(f) \
    ((((unsigned int)(_TI_FTOU_DOUBLE(f) >> 48)) &  \
      _TI_EXP_TEST_MASK_DOUBLE) == _TI_EXP_TEST_MASK_DOUBLE)

 #define _TI_FRAC_PART_DOUBLE(f) \
    (_TI_FTOU_DOUBLE(f) & _TI_BIT_MASK_DOUBLE(_TI_FBITS_DOUBLE-1))

 #define _TI_FRAC_PART_IS_ZERO_DOUBLE(f) (_TI_FRAC_PART_DOUBLE(f) == 0)

 #define _TI_DISCARD_N_FRAC_BITS_DOUBLE(v,n) \
    _TI_UTOF_DOUBLE(_TI_FTOU_DOUBLE(v) & ~_TI_BIT_MASK_DOUBLE(n))

 #define _TI_DISCARD_EXP_AND_FRAC_PARTS_DOUBLE(v) \
    _TI_UTOF_DOUBLE(_TI_FTOU_DOUBLE(v) & _TI_SGN_TEST_MASK_DOUBLE)

 #define _TI_UNBIASED_EXP_DOUBLE(f) \
    (_TI_BIASED_EXP_DOUBLE(f) - (_TI_FBIAS_DOUBLE+1))

 #define _TI_BIASED_EXP_PART_IS_ZERO_DOUBLE(f) \
    (_TI_BIASED_EXP_DOUBLE(f) == 0)

 #define _TI_EXP_AND_FRAC_PART_IS_ZERO_DOUBLE(f) \
    ((_TI_FTOU_DOUBLE(f) & ~_TI_SGN_TEST_MASK_DOUBLE)==0)

#else /* !_TI_TARGET_USES_BITS_INTRINSICS */

 #define _TI_SIGN_BIT_ZERO_DOUBLE(f) \
    ((_hi(f) & _TI_SGN_TEST_MASK_DOUBLE) == 0)

 #define _TI_FRAC_PART_HI_DOUBLE(f) \
    (_hi(f) & _TI_BIT_MASK_DOUBLE(_TI_FBITS_DOUBLE-1-32))

 #define _TI_FRAC_PART_LO_DOUBLE(f) (_lo(f))

 #define _TI_BIASED_EXP_DOUBLE(f) \
    ((_hi(f) >> (_TI_FBITS_DOUBLE-1-32)) & _TI_EXP_BITS_MASK_DOUBLE)

 #define _TI_BIASED_EXP_IS_MAX_DOUBLE(f) \
    (((_hi(f) >> 16) & _TI_EXP_TEST_MASK_DOUBLE) == _TI_EXP_TEST_MASK_DOUBLE)

 #define _TI_FRAC_PART_IS_ZERO_DOUBLE(f) \
    ((_TI_FRAC_PART_HI_DOUBLE(f) & \
    _TI_BIT_MASK_DOUBLE(_TI_FBITS_DOUBLE-1-32)) == 0 && \
    _TI_FRAC_PART_LO_DOUBLE(f) == 0)

 #define _TI_DISCARD_N_FRAC_BITS_DOUBLE(v,n) \
    (n >= 32 ? (_itod(_hi(v) & ~_TI_BIT_MASK_DOUBLE(n-32), 0)): \
    (_itod(_hi(v), _lo(v) & ~_TI_BIT_MASK_DOUBLE(n))))

 #define _TI_DISCARD_EXP_AND_FRAC_PARTS_DOUBLE(v) \
    _itod(_hi(v) & _TI_SGN_TEST_MASK_DOUBLE, 0)

 #define _TI_UNBIASED_EXP_DOUBLE(f) \
    (_TI_BIASED_EXP_DOUBLE(f) - (_TI_FBIAS_DOUBLE+1))

 #define _TI_BIASED_EXP_PART_IS_ZERO_DOUBLE(f) \
    (_TI_BIASED_EXP_DOUBLE(f) == 0)

 #define _TI_EXP_AND_FRAC_PART_IS_ZERO_DOUBLE(f) \
    (((_hi(f) & ~_TI_SGN_TEST_MASK_DOUBLE)==0)&&(_lo(f)==0))

#endif /* _TI_TARGET_USES_BITS_INTRINSICS */

#define _TI_HAS_BF_SQRT_DOUBLE (!defined(_32_BIT_DOUBLE) && \
                               defined(__TMS470__) && \
                               defined(__TI_VFP_SUPPORT__) && \
                              !defined(__TI_FPv4SPD16_SUPPORT__))

#define _TI_TYPED_SQRT_DOUBLE(n)  __sqrt(n)

/*---------------------------------------------------------------------------*/
/*             FLOATING POINT INTRINSICS - LONG DOUBLE DEFINES               */
/*---------------------------------------------------------------------------*/
#if defined(_32_BIT_LDOUBLE)
#define _TI_FBIAS_LONG _TI_FBIAS_FLOAT
#define _TI_EXP_TEST_MASK_LONG _TI_EXP_TEST_MASK_FLOAT
#elif _DLONG == 0
#define _TI_FBIAS_LONG _DBIAS
#define _TI_EXP_TEST_MASK_LONG 0x7ff0
#else
#error "80-bit and 128-bit long double not supported"
#endif
#define _TI_FBITS_LONG LDBL_MANT_DIG
#define _TI_FMAXEXP_LONG LDBL_MAX_EXP
#define _TI_EXP_BITS_MASK_LONG ((_TI_FMAXEXP_LONG << 1) - 1)

/*---------------------------------------------------------------------------*/
/* This code requires the target to support type-punning intrinsics.  These  */
/* intrinsics treat the bits of a floating-point value as if it were an      */
/* integer, to allow fast access to the sign, exponent, and fractional bits. */
/* We need to know whether the target has an intrinsic that can represent    */
/* the entire floating-point type with one integral type.                    */
/*---------------------------------------------------------------------------*/

#if LDBL_MANT_DIG == 24 /* LDBL_MANT_DIG == 24 implies _32_BIT_DOUBLE */
 #define _TI_LONG_DOUBLE_SIZE 32
#else
 #define _TI_LONG_DOUBLE_SIZE 64
#endif

#if _TI_LONG_DOUBLE_SIZE == _TI_DOUBLE_SIZE
 #define _TI_BIT_MASK_LONG      _TI_BIT_MASK_DOUBLE
 #define _TI_SGN_TEST_MASK_LONG _TI_SGN_TEST_MASK_DOUBLE
 #define _TI_FTOU_LONG          _TI_FTOU_DOUBLE
 #define _TI_UTOF_LONG          _TI_UTOF_DOUBLE
#elif _TI_TARGET_USES_BITS_INTRINSICS
 #if _TI_LONG_DOUBLE_SIZE != 64
   #error LONG DOUBLE REQUIRED TO BE 64 BITS
 #endif
 #define _TI_BIT_MASK_LONG(n) (((_TI_uint64_t)(1) << (n)) - 1)
 #define _TI_SGN_TEST_MASK_LONG ((_TI_uint64_t)(1) << (63))
 #define _TI_FTOU_LONG __f64_bits_as_u64
 #define _TI_UTOF_LONG __u64_bits_as_f64
#else
 #error _TI_LONG_DOUBLE_SIZE != _TI_DOUBLE_SIZE REQUIRES _TI_TARGET_USES_BITS_INTRINSICS
#endif

#if _TI_TARGET_USES_BITS_INTRINSICS

 #define _TI_SIGN_BIT_ZERO_LONG(f) \
    ((_TI_FTOU_LONG(f) & _TI_SGN_TEST_MASK_LONG) == 0)

 #define _TI_BIASED_EXP_LONG(f) \
    ((_TI_FTOU_LONG(f) >> (_TI_FBITS_LONG-1)) & _TI_EXP_BITS_MASK_LONG)

 #define _TI_BIASED_EXP_IS_MAX_LONG(f) \
    ((((unsigned int)(_TI_FTOU_LONG(f) >> 48)) &  \
      _TI_EXP_TEST_MASK_LONG) == _TI_EXP_TEST_MASK_LONG)

 #define _TI_FRAC_PART_LONG(f) \
    (_TI_FTOU_LONG(f) & _TI_BIT_MASK_LONG(_TI_FBITS_LONG-1))

 #define _TI_FRAC_PART_IS_ZERO_LONG(f) (_TI_FRAC_PART_LONG(f) == 0)

 #define _TI_DISCARD_N_FRAC_BITS_LONG(v,n) \
    _TI_UTOF_LONG(_TI_FTOU_LONG(v) & ~_TI_BIT_MASK_LONG(n))

 #define _TI_DISCARD_EXP_AND_FRAC_PARTS_LONG(v) \
    _TI_UTOF_LONG(_TI_FTOU_LONG(v) & _TI_SGN_TEST_MASK_LONG)

 #define _TI_UNBIASED_EXP_LONG(f) \
    (_TI_BIASED_EXP_LONG(f) - (_TI_FBIAS_LONG+1))

 #define _TI_BIASED_EXP_PART_IS_ZERO_LONG(f) (_TI_BIASED_EXP_LONG(f) == 0)

 #define _TI_EXP_AND_FRAC_PART_IS_ZERO_LONG(f) \
    ((_TI_FTOU_LONG(f) & ~_TI_SGN_TEST_MASK_LONG)==0)

#else

 #define _TI_SIGN_BIT_ZERO_LONG(f) ((_hi(f) & _TI_SGN_TEST_MASK_LONG) == 0)

 #define _TI_FRAC_PART_HI_LONG(f) \
    (_hi(f) & _TI_BIT_MASK_LONG(_TI_FBITS_LONG-1-32))

 #define _TI_FRAC_PART_LO_LONG(f) (_lo(f))

 #define _TI_BIASED_EXP_LONG(f) \
    ((_hi(f) >> (_TI_FBITS_LONG-1-32)) & _TI_EXP_BITS_MASK_LONG)

 #define _TI_BIASED_EXP_IS_MAX_LONG(f) \
    (((_hi(f) >> 16) & _TI_EXP_TEST_MASK_LONG) == _TI_EXP_TEST_MASK_LONG)

 #define _TI_FRAC_PART_IS_ZERO_LONG(f) \
    ((_TI_FRAC_PART_HI_LONG(f) & \
    _TI_BIT_MASK_LONG(_TI_FBITS_LONG-1-32))== 0 && \
    _TI_FRAC_PART_LO_LONG(f) == 0)

 #define _TI_DISCARD_N_FRAC_BITS_LONG(v,n) \
     (n >= 32 ? (_itod(_hi(v) & ~_TI_BIT_MASK_LONG(n-32), 0)) : \
     (_itod(_hi(v), _lo(v) & ~_TI_BIT_MASK_LONG(n))))

 #define _TI_DISCARD_EXP_AND_FRAC_PARTS_LONG(v) \
    _itod(_hi(v) & _TI_SGN_TEST_MASK_LONG, 0)

 #define _TI_UNBIASED_EXP_LONG(f) \
    (_TI_BIASED_EXP_LONG(f) - (_TI_FBIAS_LONG+1))

 #define _TI_BIASED_EXP_PART_IS_ZERO_LONG(f) (_TI_BIASED_EXP_LONG(f) == 0)

 #define _TI_EXP_AND_FRAC_PART_IS_ZERO_LONG(f) \
    (((_hi(f) & ~_TI_SGN_TEST_MASK_LONG)==0)&&(_lo(f)==0))

#endif /* _TI_TARGET_USES_BITS_INTRINSICS */

#define _TI_HAS_BF_SQRT_LONG ( defined(__TMS470__) && \
                             defined(__TI_VFP_SUPPORT__) && \
                             !defined(__TI_FPv4SPD16_SUPPORT__))

#define _TI_TYPED_SQRT_LONG(n)  __sqrt(n)


/*---------------------------------------------------------------------------*/
/* SINGLE PRECISION (FLOAT) FUNCTION                                         */
/* Exponent is checked using a right-shift by 16 to avoid assembly overhead  */
/* within MSP430 and ARM calculations. Specifically within the MSP430, a     */
/* shift by 16 results in the lower 16 bits to be ignored and no shift is    */
/* actually executed in the assembly code.                                   */
/*---------------------------------------------------------------------------*/
#define _FDtest __FDtest
__inline int __FDtest(float *fd)
{ 
  if (_TI_BIASED_EXP_IS_MAX_FLOAT(*fd))
  {
    if(_TI_FRAC_PART_IS_ZERO_FLOAT(*fd))
      return _INFCODE;

    else
      return _NANCODE;
  }
  /* Zero check: ignores sign bit and checks the lower 31-bits for zero */
  else if(_TI_EXP_AND_FRAC_PART_IS_ZERO_FLOAT(*fd))
    return 0;

  else
    return _FINITE;
}

/*---------------------------------------------------------------------------*/
/* DOUBLE PRECISION (DOUBLE) FUNCTION                                        */
/* If the target has instrinsic which can handle the entire float with one   */
/* integral type (64-bit), then do operation. Else, operate as 32-bit float  */
/* or split into two 32-bit parts                                            */
/*                                                                           */
/* The 64-bit exponent is checked using a right-shift by 48 to avoid         */
/* assembly overhead within MSP430. Specifically, a shift by 48 results      */
/* in the lower 48 bits to be ignored and no shift is actually executed      */
/* in the assembly code.                                                     */
/*---------------------------------------------------------------------------*/
#if !defined(_32_BIT_DOUBLE) && !defined(OPT_COFF) 
  #define _Dtest __Dtest
  __inline int __Dtest(double *d)
  { 
     if (_TI_BIASED_EXP_IS_MAX_DOUBLE(*d))
     {
        if(_TI_FRAC_PART_IS_ZERO_DOUBLE(*d))
          return _INFCODE;

        else
          return _NANCODE;
      }
      /* Zero check: ignores sign bit and checks the lower 63-bits for zero */
      else if(_TI_EXP_AND_FRAC_PART_IS_ZERO_DOUBLE(*d))
        return 0;

      else
        return _FINITE;
  }
#else  /*Operate as 32-bit Double */
  #define _Dtest(x) _FDtest(((float *)(x)))
#endif /* !defined(_32_BIT_DOUBLE) && !defined(OPT_COFF) */

/*---------------------------------------------------------------------------*/
/* QUADRUPLE PRECISION(LONG DOUBLE) FUNCTION                                 */
/* If the target doesn't support quadruple precision,                        */
/* operate as double precision (64-bit)                                      */
/*---------------------------------------------------------------------------*/
#if _TI_LONG_DOUBLE_SIZE == _TI_DOUBLE_SIZE
  #define _LDtest(x) _Dtest(((double *)(x)))

/*---------------------------------------------------------------------------*/
/* If the target has instrinsic which can handle the entire float with one   */
/* integral type (128-bit) or by splitting it into two,then do operation     */
/*---------------------------------------------------------------------------*/
#else
  #define _LDtest __LDtest
  __inline int __LDtest(long double *ld)
  {
     if (_TI_BIASED_EXP_IS_MAX_LONG(*ld))
     {
        if(_TI_FRAC_PART_IS_ZERO_LONG(*ld))
          return _INFCODE;
      
        else
          return _NANCODE;
     }
     /* Zero check: ignores sign bit and checks the lower 127-bits for zero */
     else if(_TI_EXP_AND_FRAC_PART_IS_ZERO_LONG(*ld))
        return 0;
     
     else
        return _FINITE;
  }
#endif /* _DLONG */

_END_C_LIB_DECL
_C_STD_END
#endif /* _YMATH */

/*
 * Copyright (c) 1992-2004 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V4.02:1476 */
