/*
 * function: func_02201A64
 * address:  0x02201A64
 * packet:   pkt_02201A64
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_0220252C  0x0220252C  thumb  ov135
 *   func_02201B18  0x02201B18  thumb  ov135
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *
 * Switch on the 0x021C86A8 index (case value = index + 15): the 0x1a guard
 * over func_0220252C with the +0x32 flag, index 12 with only the flag, the
 * +0x38/0x2b group returning 2, and the plain redraw returning 2.  The nine
 * hole indices 4..11 and 14 are LISTED as empty cases: without them the
 * compiler folds the case set into a compare chain instead of the listing's
 * 16-slot table, and the func_02201B18 call sits after the switch (every
 * break and every hole lands on it).
 * The shape is settled and every concrete byte is reproduced; the site is
 * parked because 0x021C866C / 0x021C86A8 carry no func_ label in any
 * overlay listing (see the wave-5 residue note for the one-line fix).
 
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
*/

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern u32 func_0220252C(u8 *p);
extern void func_02201B18(u8 *p);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);

int func_02201A64(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        *(u32 *)(p + 0xf8c) = 0;
        switch (n + 15) {
        case 15:
            if (func_0220252C(p) != 0) {
                *(u32 *)(p + 0x28) = 0x1a;
                *(u16 *)(p + 0x32) = 0;
                return 2;
            }
            *(u16 *)(p + 0x32) = 1;
            break;
        case 12:
            *(u16 *)(p + 0x32) = 0;
            break;
        case 0:
        case 1:
        case 3:
        case 13:
            *(u32 *)(p + 0x38) = n;
            *(u32 *)(p + 0x28) = 0x2b;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            return 2;
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 14:
            break;
        case 2:
            func_021F513C(p);
            return 2;
        }
        func_02201B18(p);
    } else {
        if (++*(u32 *)(p + 0xf8c) == 0xe10) {
            func_021F513C(p);
        }
    }
    return 2;
}
