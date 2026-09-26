/*
 * function: func_02201D30
 * address:  0x02201D30
 * packet:   pkt_02201D30
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): state 0x25, the
 * +0x38/0x2b four-call group, the +0x38 archive with a plain redraw for the
 * 3+11 pair, the 0/1/13 and 2 redraw groups; 4..10 and 14 are table holes.
 * Concrete bytes reproduced; parked because 0x021C866C / 0x021C86A8 carry
 * no func_ label in any overlay listing (see pkt_ov135_residue.c.txt).
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT*.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);

int func_02201D30(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        *(u32 *)(p + 0xf8c) = 0;
        switch (n + 15) {
        case 15:
            *(u32 *)(p + 0x28) = 0x25;
            break;
        case 12:
            *(u32 *)(p + 0x38) = n;
            *(u32 *)(p + 0x28) = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 3:
        case 11:
            *(u32 *)(p + 0x38) = n;
        case 0:
        case 1:
        case 13:
            func_021F513C(p);
            break;
        case 2:
            func_021F513C(p);
            break;
        }
    } else {
        if (++*(u32 *)(p + 0xf8c) == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}
