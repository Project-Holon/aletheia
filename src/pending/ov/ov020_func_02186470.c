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
 * note: 2026-10-05 (wD7 lane14): still DIFF 13 bytes. Tried: char *items = base + 8 form as in the matched sibling 021862A8 (21 B, full a0/id + items/off swap), the loop body as a static inline Step(base, e, u16 id) (13, same), static inline GetId returning u32 (same) or u16 (88), u16 callee return with u16 id (79), Item *e = base->items + i and an explicit off local (15). Callee arities rechecked (02186BA8, 02186B2C, 02161ECC, 02161E78, 02161E60, 02013DE0): no hidden arguments. Residue unchanged: a0 r5 / id r4 (image a0 r4 / id r5).
 *
 * note: 2026-10-05 (wD6 lane13): DIFF 13 bytes (was 15). The first call is nested: id = func_02012AC8(func_020127A4(a0)) (020127A4 returns a0 + 0x114, 02012AC8 reads a u16 through it). The item array is a struct field (Box: 8-byte header, Item items[10] of 0x18 bytes, q at 0xF8 = 8 + 10*0x18); this gives the base/[sp,#4] double store and items/off in r4/r5 as in the image. Residue: a0 r5 / id r4 (image a0 r4 / id r5), because the hoisted (u16)id is placed before the items load. Tried: u32 callee + explicit (u16) cast (86 B), a key local before the loop (86-90 B), an Item *e local (15 B), continue form, void * a0: no change.
 *
 * note: 2026-10-05 (wD5 lane17): still DIFF 15 bytes. New test: u32 a0 parameter and u32 callee prototype for func_020127C4 (no change). Colour classes {a0,items} and {id,off} still swapped.
 * 2026-10-05 (wD4 lane19): still DIFF 15 bytes. Tried signed id, an explicit int h = (u16)id local before the loop, a copy of a0: no change. Colour classes match ({a0,items} and {id,off}); only their register labels are swapped (orig a0/items r4, id/off r5).
 *
 * 2026-10-04 (wD2 lane 02): same residue, 15 bytes (pure r4/r5 colour swap of a0 and id, plus the 02013DE0 leaf
 * has no witness). Also tried: u16 id (86 bytes worse), id & 0xFFFF, a u32 id16 local, no q local, e outside the
 * loop, func_020127A4(a0) as a one-argument call. a0 should get the lower colour; the draft gives id the lower one.
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

typedef struct Item { char d[0x18]; } Item;
typedef struct Box { u32 h[2]; Item items[10]; char q[4]; } Box;

extern void *func_020127A4(int a);
extern u32 func_02012AC8(void *p);
extern Box *func_020127C4(int a);
extern int func_02161ECC(Item *p);
extern int func_02186BA8(Item *p);
extern int func_02013DE0(u16 id);
extern char *func_02186B2C(char *p, Item *src);
extern void func_02161E78(Item *p);
extern void func_02161E60(Box *p, int a);

void func_02186470(int a0)
{
    u32 id;
    Box *base;
    int i;

    id = func_02012AC8(func_020127A4(a0));
    base = func_020127C4(a0);
    for (i = 0; i < 10; i++) {
        if (func_02161ECC(&base->items[i]) != 0 && func_02186BA8(&base->items[i]) != 0 && func_02013DE0(id) == 0) {
            func_02186B2C(base->q, &base->items[i]);
            func_02161E78(&base->items[i]);
        }
    }
    func_02161E60(base, 0);
}
