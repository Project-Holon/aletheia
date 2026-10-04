/*
 * function: func_021B9EA0
 * address:  0x021B9EA0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0204A8D4  0x0204A8D4  arm
 *   sub_0204ADA4  0x0204ADA4  arm
 *   sub_0204AFD8  0x0204AFD8  arm
 *
 * Releases three pointers at +8, +0xC and +0x10 through three arm9 helpers.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void sub_0204A8D4(u32 i);
extern void sub_0204ADA4(u32 i);
extern void sub_0204AFD8(u32 i);

typedef struct {
    char pad[8];
    void *f08;
    void *f0C;
    void *f10;
} S;

void func_021B9EA0(S *s)
{
    sub_0204A8D4((u32)s->f08);
    sub_0204ADA4((u32)s->f0C);
    sub_0204AFD8((u32)s->f10);
}
