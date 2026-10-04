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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_020120F4(u8 *p);
extern u8  *func_020122C0(u8 *p, u32 a, u32 cb, u32 c);
extern u8  *func_020124E8(u8 *p);
struct BigObj;
extern unsigned int func_02012A30(const struct BigObj *p);
extern int func_02029488(u32 unused, u32 *state, u8 *cfg);

u8 *func_020294C0(u8 *p, u32 a)
{
    u32 r7 = func_020120F4(p);
    u8 *r6 = func_020122C0(p, 0, (u32)func_02029488, 0x10);
    u8 *r4 = func_020124E8(r6);

    *(u32 *)(r4 + 4) = func_02012A30((const struct BigObj *)r7);
    *(u16 *)(r4 + 0xc) = (u16)a;
    return r6;
}
