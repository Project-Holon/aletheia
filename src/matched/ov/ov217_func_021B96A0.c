/*
 * function: func_021B96A0
 * address:  0x021B96A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201058C  0x0201058C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_0201283C  0x0201283C  thumb
 *
 * Flushes the +4 handle through three sub-calls, then raises event 1 with
 * the record's leading halfword when the fourth sub-call reports busy.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10953.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0201058C(void *key);
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct IcaAnime;
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_0201283C(const struct BigObj *p);
extern void func_0203D34C(u32 a, u32 b);
void func_021B96A0(u32 a0)
{
    func_0201058C((void *)func_0201283C(func_020120F4(((struct Obj10953 *)(((u8*)a0)))->f4)));
    if (func_020121CC((struct IcaAnime *)(*(u32 *)&((struct Obj10953 *)(((u8*)a0)))->f4)) != 0) {
    func_0203D34C(1, ((struct Obj10953 *)((u8*)a0))->f0);
    }
}
