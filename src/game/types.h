#ifndef GAME_TYPES_H
#define GAME_TYPES_H

/*
 * Base types of the NitroSDK / TwlSDK (include/nitro/types.h): fixed-width
 * integers, volatile forms, fixed-point scalars, float and BOOL.  Every source
 * file takes these from here; no file defines its own.
 *
 * u32 and s32 are `unsigned int` and `signed int` here.  The compiler treats
 * `long` and `int` as different types, and a few functions only compile to the
 * original code when u32 or s32 is spelled `long` (the SDK spelling).  A source
 * file that needs it defines GAME_TYPES_U32_LONG and/or GAME_TYPES_S32_LONG
 * before its first include (`grep -rl GAME_TYPES_ src/game` lists them).
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
#ifdef GAME_TYPES_U32_LONG
typedef unsigned long      u32;
#else
typedef unsigned int       u32;
#endif
typedef unsigned long long u64;

/* C library size type: unsigned long in the SDK C library (libc string.h, MSL); the host takes its own. */
#ifdef __MWERKS__
typedef unsigned long      size_t;
#else
#define __need_size_t
#define __need_ptrdiff_t
#include <stddef.h>
#endif

typedef signed char        s8;
typedef signed short       s16;
#ifdef GAME_TYPES_S32_LONG
typedef signed long        s32;
#else
typedef signed int         s32;
#endif
typedef signed long long   s64;

typedef volatile u8        vu8;
typedef volatile u16       vu16;
typedef volatile u32       vu32;
typedef volatile u64       vu64;

typedef volatile s8        vs8;
typedef volatile s16       vs16;
typedef volatile s32       vs32;
typedef volatile s64       vs64;

typedef s16                fx16;
typedef s32                fx32;
typedef s64                fx64;

typedef float              f32;
typedef volatile f32       vf32;

typedef int                BOOL;

/*
 * uptr and sptr are the integers that hold an address.  On the DS they are
 * u32 and s32 (the same bytes as before).  A 64-bit host needs the full
 * pointer width, so a cast from a pointer to an integer, or a field that keeps
 * a pointer in an integer, uses these and not u32 or s32.
 */
#ifdef __MWERKS__
typedef u32                uptr;
typedef s32                sptr;
#else
typedef __UINTPTR_TYPE__   uptr;
typedef __INTPTR_TYPE__    sptr;
#endif

/*
 * Offset of a member, as a constant expression.  The DS compiler has no
 * stddef.h and no __builtin_offsetof, but accepts the null-pointer form.
 * Both forms give the same value on the same layout.
 */
#ifdef __MWERKS__
#define BW_OFFSETOF(type, member) ((uptr)&((type *)0)->member)
#else
#define BW_OFFSETOF(type, member) ((uptr)__builtin_offsetof(type, member))
#endif

#endif
