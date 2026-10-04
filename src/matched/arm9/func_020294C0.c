/*
 * function: func_020294C0
 * address:  0x020294C0
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_020294C0.c is now a manifest entry (matched class)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020294C0.c \\
 *       --func func_020294C0 --addr 0x020294C0 --thumb --cc 1.1p1
 */
#include "../include/Obj11298.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8  *func_020124E8(u8 *p);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern int func_02029488(u32 unused, u32 *state, u8 *cfg);

u8 *func_020294C0(u8 *p, u32 a)
{
    u32 r7 = (u32)func_020120F4((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)func_02029488), 0x10);
    u8 *r4 = func_020124E8(r6);

    ((struct Obj11298 *)r4)->f4 = func_02012A30((const struct BigObj *)r7);
    ((struct Obj11298 *)r4)->fC = (u16)a;
    return r6;
}
