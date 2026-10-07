/*
 * file:     queue_p04.c
 * unit:     yes
 * function: func_021C0A5C, func_021C0AA4, func_021C0AD8
 * address:  0x021C0A5C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_021C0B0C 0x021C0B0C thumb ov217
 *   func_021C0B94 0x021C0B94 thumb ov217
 *   func_021C0BBC 0x021C0BBC thumb ov217
 *   func_021C0C40 0x021C0C40 thumb ov217
 *   func_021C0C5C 0x021C0C5C thumb ov217
 *   func_021C0D88 0x021C0D88 thumb ov217
 *   func_021C0CF8 0x021C0CF8 thumb ov217
 *   func_021C0D14 0x021C0D14 thumb ov217
 *   func_021C0AF0  0x021C0AF0  thumb  ov217
 *   func_021C0B74  0x021C0B74  thumb  ov217
 *   func_021C0BA8  0x021C0BA8  thumb  ov217
 *   func_021C0C2C  0x021C0C2C  thumb  ov217
 *   func_021C0C50  0x021C0C50  thumb  ov217
 *   func_021C0CC8  0x021C0CC8  thumb  ov217
 *   func_021C0D08  0x021C0D08  thumb  ov217
 *   func_021C0D2C  0x021C0D2C  thumb  ov217
 *   d_021C3F64  0x021C3F64  data
 *   d_021C3F9C  0x021C3F9C  data
 */
#include "../../matched/include/Obj00791.h"
#include "../../matched/include/Obj25984.h"

struct Ctx;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

extern void *func_020120F4(const struct Ctx *);
extern void func_021C0B0C(u8 *);
extern void func_021C0B94(u32);
extern void func_021C0BBC(u8 *);
extern void func_021C0C40(u32);
extern void func_021C0C5C(u8 *);
extern void func_021C0D88(u8 *);
extern void func_021C0CF8(u32);
extern u32 func_021C0D14(u8 *);
extern u32 func_021C0AF0();
extern u32 func_021C0B74(u32 a0);
extern void func_021C0BA8(u8 *a0);
extern void func_021C0C2C(u8 *a0);
extern void func_021C0C50(u8 *a0);
extern void func_021C0CC8(int *p);
extern void func_021C0D08(u8 *a0);
extern void func_021C0D2C(u8 *);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
void func_021C0A5C(u8 *p, const struct Ctx *ctx, u32 heap);
u32 func_021C0AA4(u32 a0);
void func_021C0AD8(u32 a0);
extern u8 d_021C3F64[];
extern u8 d_021C3F9C[];

void func_021C0A5C(u8 *p, const struct Ctx *ctx, u32 heap)
{
    ((struct Obj00791 *)p)->f0 = heap;
    *(const struct Ctx * *)&((struct Obj00791 *)p)->f4 = ctx;
    ((struct Obj00791 *)p)->f8 = func_020120F4(ctx);
    func_021C0AD8((u32)p);
    func_021C0B0C(p);
    func_021C0B94((u32)p);
    func_021C0BBC(p);
    func_021C0C40((u32)p);
    func_021C0C5C(p);
    func_021C0D88(p);
    func_021C0CF8((u32)p);
    func_021C0D14(p);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
u32 func_021C0AA4(u32 a0)
{
    func_021C0D2C((u8 *)a0);
    func_021C0D08((u8 *)a0);
    func_021C0CC8((int *)a0);
    func_021C0C50((u8 *)a0);
    func_021C0C2C((u8 *)a0);
    func_021C0BA8((u8 *)a0);
    func_021C0B74(a0);
    return func_021C0AF0(a0);
}

/*
 * Reconstructed from the listing.
 *
 * closed: both data sites carried the contested ov217 token; dropping it lets
 * the function's own region (ov217) pick the objects and 0x021C3F9C resolves
 * as sole-ref/data.  All three relocations resolve, 24 bytes EXACT.
 * See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0AD8(u32 a0)
{
    func_0204A48C((const struct Cfg *)d_021C3F64, (u32)d_021C3F9C, ((struct Obj25984 *)((u8*)a0))->f0);
}
