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
 * 2026-10-05 (wD9r lane96): still DIFF 13 bytes. Twin search by callees: only 021862A8 (02013DE0, 02186B2C,
 *   02161E78) and the leaf loops 0218609C/021860B8 (p + 8 and p + 0xF8, 10 records of 0x18: q is a second
 *   Item[10] history list, 02186B2C shifts it). Tried, all with a real compile: Box with Item hist[10] and
 *   B2C(base->hist) or &hist[0] (13); Item list[2][10] with list[0][i] and list[1] (13); u8 items[10][0x18]
 *   rows with u8 * prototypes, with and without (u8 *) on the rows (13 each); a different item address form
 *   only in the ECC/BA8 calls (char * + 8 + i*0x18: 54, base->items + i: 13, + (i*0x18 + 8): 90); the twin
 *   char * shape with items = base + 8 after i = 0 (18: classes right, {a0,items} {id,off}, but labels r5/r4
 *   and items is a copy of r0, not the [sp] reload); items and q assigned inside the loop body (18, 30, 31);
 *   goto loop (13); for (;;) with break (81); extra unused parameters (13); u32/int k = id copy at the loop top
 *   (13); id & 0xFFFF with u16/int/u32 parameter (86-90); ok = ECC && BA8 local (91), nested continue (13),
 *   ternary (102); static inline CanAdd(e, id) condition (105). Probes: the image needs items defined while
 *   id is live (items an IV temp reloaded from [sp], before the shift). Explicit casts hoist first, implicit
 *   argument conversion in a conditional block hoists before items, only a header-block conversion (DE0 first,
 *   wrong logic) hoists after items. No real source form found that puts it there.
 * 2026-10-05 (wD9r lane76): still DIFF 13 bytes. Tried real callee return types (02161E78/02161E60 int,
 *   02186B2C void, 020127A4 u32 with 02012AC8(u32)): 13, same. Nested ifs instead of the && chain (13);
 *   char *q = base->q as a block local in the if (13); u32 i (14); explicit (u16)id at the call (13).
 *   Probe (wrong logic): with no items use in the ECC/BA8 calls the preheader is still q, shift, items, so
 *   the order is not the block order of the first items use; only the DE0-first probe flips it.
 * 2026-10-05 (wD9r lane63): still DIFF 13 bytes. Probe (wrong logic, not kept): with the 02013DE0(id)
 *   test written FIRST in the && chain, the whole preheader matches the image (q, items, shift and
 *   a0 r4 / id r5). So the image's LICM finds the (u16)id conversion before the items base. Tried for a
 *   real form: static inline Step(u16 id, Box *base, Item *e) with id as the first parameter (13, the
 *   parameter temp is propagated); a different address shape only in the 02186B2C/02161E78 calls
 *   (base->items + i: 13; raw char * + 8 + i * 0x18: 54; Item *e local in the if: 15); q as
 *   (char *)base + 0xF8 or (char *)&base->items[10] (13); !02013DE0(id) (13). Open lead: a source form
 *   where the id conversion is seen before the first items use in the loop.
 * 2026-10-05 (wD9r lane49): still DIFF 13 bytes. Tried: the item address as (char *)base + 8 + i * 0x18,
 *   base + i * 0x18 + 8, base->items + i, &((Item *)((char *)base + 8))[i] (all 13; 0x18 + 8 order 92);
 *   off = i * 0x18 at the loop top with (char *)base->items + off at each use (13); explicit q = base->q
 *   and items = base->items locals before the loop (31); register on id or on a0 (13). Probes: with
 *   base->q removed the preheader is shift then items, so the items temp is always placed after the
 *   hoisted (u16)id shift, whatever the address form.
 * 2026-10-05 (wD9r lane32): still DIFF 13 bytes. Tried: a reused pointer local (base = 020127A4(a0);
 *   id = 02012AC8(base); base = 020127C4(a0)) and a reused id local for the 020127A4 pointer (13, same);
 *   (base->items + i) at each use, while loop (13); static inline GetQ(base) for base->q and GetItem(base, i)
 *   (13); static inline u16 GetId(a0) (88); base declared before id, i first (13). Residue unchanged:
 *   a0 r5 / id r4 (image a0 r4 / id r5), shift scheduled before the items reload.
 * 2026-10-05 (wD9r lane19): still DIFF 13 bytes. Tried: the matched sibling 021862A8 shape exactly (char * base,
 *   i = 0; items = base + 8; for (; i < 10; ...) with base + 0xF8 inline: 18 B, items stays in a register and
 *   is no longer reloaded from [sp]); int 02013DE0 parameter with an explicit (u16)id at the call (86, the
 *   cast is placed before the loop); K&R 02013DE0 (79); Item *items = base->items as the first statement of
 *   the loop body (18); continue-chain body, do-while loop, continue plus final if (all 13, same). The
 *   implicit parameter conversion is the only form that is hoisted; its preheader slot stays before items.
 * 2026-10-05 (wD9r lane01): still DIFF 13 bytes. Reading: the colours look ordered so that items (a LICM temp)
 *   is coloured first; it takes r4 only when it is defined before the id shift (then id interferes with it and
 *   a0 gets r4). So the residue is the preheader order q, shift, items (image q, items, shift). Tried: u16
 *   return for 02012AC8 with u32 or int id (13, same); u16 k = id at the loop-body top (86, shift moves first);
 *   static inline Setup(a0, &id) returning base, Body(id, base) and Body(base, id) inlines (13, same). Callees
 *   020127A4, 020127C4 (tail to 020127D0, r0/r1 only), 02013DE0 rechecked: no hidden arguments.
 * 2026-10-05 (wD9 lane17): still DIFF 13 bytes. New reading: the swap comes from the pre-allocation order of the hoisted items def and the (u16)id shift (image: items defined while id is live, so items shares a0's class). Tried: an explicit Item *items = base->items before the loop, at the top or right after the base call, with u32 id (21 B: classes now {a0,items} {id,off} as in the image but r4/r5 labels still swapped and items no longer reloaded from [sp]); a void *pp local for the 020127A4 result (13, same); a hoisted char *q = base->q local (20).
 * 2026-10-05 (wD8 lane04): still DIFF 13 bytes. Re-read: the classes are {a0, items} r4 and {id, off} r5 in the image, but {id, items} r4 and {a0, off} r5 here: the image defines items (ldr r4,[sp]) while id is still live, ours converts id first. Tried an explicit Item *items = base->items before a u16 key = id copy (88 B, worse). Callee heads rechecked: 02012AC8 is a bare ldrh (returns u16), 020127C4 is a tail jump with r1 = 1, no hidden arguments.
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
