/*
 * function: func_021C0384
 * address: 0x021C0384
 * packet: pkt_ov210_021C0384
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_02049238 0x02049238 arm
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_02045EC0 0x02045EC0 arm
 *   func_021BCEF4 0x021BCEF4 thumb ov210
 *   d_021C0C48 0x021C0C48 data a4
 */
#include "../include/Obj04624.h"
typedef unsigned short u16;
typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;
extern const Template d_021C0C48;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_021B7754(void *, unsigned);
extern void func_021B7A10(void *, void *, unsigned, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_02049238(void *);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 func_021BCEF4(int a0, int a1);
void func_021C0384(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0C48;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((struct Obj04624 *)ctx)->f1E0 = func_021B7754(&config, 123);
    ((struct Obj04624 *)ctx)->f2AC = config.count;
    func_021B7A10(((struct Obj04624 *)ctx)->f1E0, archive, 97, 0, 0);
    func_021B7A4C(((struct Obj04624 *)ctx)->f1E0, archive, 73, 2, 3);
    func_02049238(archive);
    for (i = 0; i <= 16; i++) { func_021B79E4(((struct Obj04624 *)ctx)->f1E0, 0, i); ((void **)(ctx + 0x1e4))[i] = func_02045EC0(((struct Obj04624 *)ctx)->f1D0, func_021BCEF4((int)ctx, i)); }
}
