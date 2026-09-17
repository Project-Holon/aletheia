/*
 * function: func_020295A4
 * address:  0x020295A4
 * packet:   pkt_02029354
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020295A4.c \\
 *       --func func_020295A4 --addr 0x020295A4 --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_020120F4(u8 *p);
extern u8  *func_020122C0(u8 *p, u32 a, u32 cb, u32 c);
extern u8  *func_020124E8(void);
extern u32  func_02012A30(u32 v);
extern void func_02029560(void);

u8 *func_020295A4(u8 *p, u32 a)
{
    u32 r7 = func_020120F4(p);
    u8 *r6 = func_020122C0(p, 0, (u32)func_02029560, 0x10);
    u8 *r4 = func_020124E8();

    *(u32 *)(r4 + 4) = func_02012A30(r7);
    *(u16 *)(r4 + 0xe) = (u16)a;
    return r6;
}
