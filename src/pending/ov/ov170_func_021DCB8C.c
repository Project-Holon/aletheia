/*
 * function: func_021DCB8C
 * address:  0x021DCB8C
 * packet:   pkt_ov170_021DCB8C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note: DIFF vs 2026-10-04: 15 bytes differ, all in register-argument zeros. Original uses movs rN,#0 for a zero register argument at 7 places (2049B68 call with 0x3F r2, both 02040E78 r0, the four r3 zeros in the 2049658/20498F4/2049B68 calls after the palette block), ours emits adds rN,r5,#0 there. Loop counter must be u32 (blo). Tried: variable z vs literal 0 for stack zeros (no change).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02049F34  0x02049F34  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02027628  0x02027628  thumb
 *   func_02027624  0x02027624  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 */

/*
 * 2026-10-05 (wave D4 lane07): DIFF, unchanged 15 bytes. Finding: the zero in r5 is the compiler's own CSE of the constant 0 (all-literal source without z gives the same code), and the original r5 is later the loop counter i. From the 0x3F call onward this build substitutes r5 for every literal register zero; the original does that only from the arc2 block on (arc2 args, 020413B0 r0/r1, 02041B6C, 0204162C). Tried: no z (all literal 0), i = 0 at the top and used as the loop start, z only in the arc2-block positions, the first part (up to func_02049238(arc)) as a static inline helper: all identical or worse.
 */
/*
 * 2026-10-05 (wave D5 lane15): DIFF, 14 bytes with all-literal zeros (z removed), same 7
 *   places. Experiments on the mechanism: with the 0x3E call deleted the first copy moves
 *   one use later (0x3F r2 becomes movs, the 02040E78 r0 copies), so the movs-vs-copy choice
 *   depends on code before the use, not on the use count or the previous r5 use. Tried: the
 *   arc2 block through the loop as a static inline helper (literal zeros inside): r4/r5 swap,
 *   same copies. Idea left: the r5 zero is a coalesced temp; find a source shape that gives
 *   the palette-region literals their own value (not the 0 CSE temp).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 f0; u32 f4; u32 f8; u8 *fC; } PlttData;
struct Ov170Ctx { char pad[0x2c]; char *f2c; };

extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_020275E4(void);
extern void *func_02049F34(u32, u32, PlttData **, u32);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern void func_020307B0(void *);
extern void func_02049238(void *);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u32, u8, u8, u8, u8, u8);
extern void func_02041B6C(u32);
extern u16 *func_0204162C(u8);
extern int func_0201F5DC(int, int, int, int);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);

void func_021DCB8C(struct Ov170Ctx *ctx)
{
    void *arc;
    void *arc2;
    void *pal;
    PlttData *pd;
    u8 *src;
    u32 ofs;
    u32 r6;
    u16 *a;
    u16 *b;
    u32 i;
    u32 z = 0;

    arc = func_020490F4(0x74, 0x4c);
    func_02049658(arc, 0xc, 1, 0, z, 1, 0x4c);
    func_02049740(arc, 3, 2, 0, 1, 0x4c);
    func_020498F4(arc, 2, 2, 0, z, 1, 0x4c);
    func_02049658(arc, 1, 3, 0, z, 1, 0x4c);
    func_020498F4(arc, 0, 3, 0, z, 1, 0x4c);
    func_02049B68(arc, 4, 0, 0, 0x80, 0x4c);
    func_02049658(arc, 0x3e, 1, 1000, 0x300, 1, 0x4c);
    func_02049B68(arc, 0x3f, 0, 0x180, 0x40, 0x4c);
    pal = func_02049F34(func_020275E4(), 0x1f, &pd, 0x804c);
    src = pd->fC;
    ofs = 0x194;
    func_02040E78(0, src + 0x34, 4, ofs);
    src += 0x14;
    ofs += 0x20;
    func_02040E78(0, src, 4, ofs);
    func_020307B0(pal);
    func_02049658(arc, 6, 5, 0, z, 1, 0x4c);
    func_020498F4(arc, 5, 5, 0, z, 1, 0x4c);
    func_02049658(arc, 6, 6, 0, z, 1, 0x4c);
    func_02049B68(arc, 7, 4, 0, z, 0x4c);
    func_02049238(arc);
    arc2 = func_020490F4(func_020275E4(), 0x4c);
    func_02049740(arc2, func_02027628(), 0, 0, z, 0x4c);
    func_02049B68(arc2, func_02027624(), 0, 0xe0, 0x20, 0x4c);
    func_020498F4(arc2, func_0202762C(), 0, 0, z, z, 0x4c);
    func_020413B0(0, 0, 0x15, 0x20, 3, 7);
    func_02041B6C(0);
    r6 = func_02049740(arc2, func_02027628(), 2, 0, z, 0x4c);
    func_02049238(arc2);
    a = func_0204162C(0);
    b = func_0204162C(2);
    for (i = 0; i < 0x60u; i++) {
        *(u16 *)((char *)b + 0x540 + i * 2) = r6 + *(u16 *)((char *)a + 0x540 + i * 2);
    }
    func_02041B6C(2);
    *(int *)(ctx->f2c + 0x178) = func_0201F5DC(0, 10, 0, 0x4c);
    func_02049B40(0x17, 5, 0, 0x160, 0x20, 0x4c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4c);
}
