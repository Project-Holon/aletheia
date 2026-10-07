/*
 * file:     ctvt_comm_p10.c
 * unit:     yes
 * function: func_021B8B48, func_021B8B5C, func_021B8B68, func_021B8B74, func_021B8B7C, func_021B8B84, func_021B8B8C, func_021B8B94, func_021B8B9C, func_021B8BA4, func_021B8BAC
 * address:  0x021B8B48
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_020399A8  0x020399A8  arm
 *   sub_02039CB4  0x02039CB4  arm
 *   func_0203D1A4  0x0203D1A4  arm
 */
#include "../../matched/include/Obj24088.h"
#include "../../matched/include/Obj24089.h"

struct Entry;
struct Link;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern struct Entry *sub_020399A8(void);
extern u32 sub_02039CB4(struct Link *a, u32 b, u32 c);
extern u32 func_0203D1A4(struct Link *p);
int func_021B8B48(void *p, u32 a, u32 b);
void func_021B8B5C(void);
u8 func_021B8B68(int unused, char *p);
int func_021B8B74(void *ctx, u8 *rec);
u8 *func_021B8B7C(void *c, u8 *x);
u32 func_021B8B84(int unused, char *p);
u32 func_021B8B8C(int unused, char *base, int i);
char *func_021B8B94(int unused, char *base, int i);
char *func_021B8B9C(int unused, char *base);
u32 func_021B8BA4(int unused, char *base, int i);
u8 func_021B8BAC(void *unused, char *base, int i);


/*
 * arm9 call whose result is the first argument of the second call.
 *
 * Addresses are Black-image addresses.
 */
int func_021B8B48(void *p, u32 a, u32 b)
{
    return sub_02039CB4((struct Link *)sub_020399A8(), b, 0x20);
}


void func_021B8B5C(void)
{
    func_0203D1A4((struct Link *)((u32)sub_020399A8()));
}


/*
 * Field getter, u8 at +0x3ae of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u8 func_021B8B68(int unused, char *p)
{
    return ((struct Obj24088 *)p)->f3AE;
}


int func_021B8B74(void *ctx, u8 *rec)
{
    return *(u32 *)(rec + 0x194);
}


u8 *func_021B8B7C(void *c, u8 *x)
{
    return x + 0xc;
}


/*
 * Field getter, u32 at +0x1a4 of the second argument.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8B84(int unused, char *p)
{
    return ((struct Obj24089 *)p)->f1A4;
}


/*
 * Field getter, u32 at +0x68 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8B8C(int unused, char *base, int i)
{
    return *(u32 *)(base + (i << 6) + 0x68);
}


/*
 * Record address, +0x80, stride 0x40.
 *
 * Addresses are Black-image addresses.
 */
char *func_021B8B94(int unused, char *base, int i)
{
    return base + 0x80 + (i << 6);
}


char *func_021B8B9C(int unused, char *base)
{
    return base + 0x40;
}


/*
 * Field getter, u32 at +0x64 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021B8BA4(int unused, char *base, int i)
{
    return *(u32 *)(base + (i << 6) + 0x64);
}


/*
 * Field getter, u8 at +0xa0 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */
u8 func_021B8BAC(void *unused, char *base, int i)
{
    return *(u8 *)(base + (i << 6) + 0xa0);
}
