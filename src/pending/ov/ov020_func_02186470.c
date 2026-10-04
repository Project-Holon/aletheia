/*
 * function: func_02186470
 * address:  0x02186470
 * packet:   pkt_ov020_02186470
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02161ECC  0x02161ECC  thumb
 *   func_02186BA8  0x02186BA8  thumb
 *   func_02013DE0  0x02013DE0  thumb
 *   func_02186B2C  0x02186B2C  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02161E60  0x02161E60  thumb
 *
 * 2026-10-04: DIFF, 14 diff lines, body shape and stack slots right. Residue: the original keeps a0 in r4 and
 * the func_02012AC8 result in r5 (shifted to u16 in r7 only just before the loop); this draft swaps r4/r5.
 * The original stores base to [sp] and [sp,#4], then base+0xF8 to [sp,#4] again (double store of q).
 * Tried: u16 id (shift moves right after the call), decl order permutations of q/base/items/i/id, items local.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020127A4(void);
extern u32 func_02012AC8(void);
extern char *func_020127C4(int a);
extern int func_02161ECC(char *p);
extern int func_02186BA8(u8 *p);
extern int func_02013DE0(u32 id);
extern char *func_02186B2C(char *p, char *src);
extern void func_02161E78(char *p);
extern void func_02161E60(char *p, int a);

void func_02186470(int a0)
{
    char *q;
    char *base;
    char *items;
    int i;
    u32 id;

    func_020127A4();
    id = func_02012AC8();
    base = func_020127C4(a0);
    q = base + 0xF8;
    items = base + 8;
    for (i = 0; i < 10; i++) {
        char *e = items + i * 0x18;
        if (func_02161ECC(e) != 0 && func_02186BA8((u8 *)e) != 0 && func_02013DE0((u16)id) == 0) {
            func_02186B2C(q, e);
            func_02161E78(e);
        }
    }
    func_02161E60(base, 0);
}
