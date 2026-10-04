/*
 * function: func_020295A4
 * address:  0x020295A4
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
 *   python tools/match.py one --src src/matched/func_020295A4.c \\
 *       --func func_020295A4 --addr 0x020295A4 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
struct Desc;
extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern u8  *func_020124E8(u8 *p);
struct BigObj;
extern u32  func_02012A30(const struct BigObj *v);
extern int func_02029560(u32 unused, u32 *state, u8 *cfg);

u8 *func_020295A4(u8 *p, u32 a)
{
    u32 r7 = (u32)func_020120F4((const struct Ctx *)p);
    u8 *r6 = (u8 *)func_020122C0(p, 0, (void *)((u32)func_02029560), 0x10);
    u8 *r4 = func_020124E8(r6);

    *(u32 *)(r4 + 4) = func_02012A30((const struct BigObj *)r7);
    *(u16 *)(r4 + 0xe) = (u16)a;
    return r6;
}
