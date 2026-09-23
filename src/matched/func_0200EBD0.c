/*
 * function: func_0200EBD0
 * address:  0x0200EBD0
 * packet:   pkt_0200EA3C
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200EA3C  0x0200EA3C  thumb
 *
 * Ring-buffer record dispatcher: while the saturating counter at +0x1558 is
 * below 9999, hand the 0x16c-byte record at slot +0x1554 to func_0200EA3C,
 * then advance the slot (wrapping at 15) and the counter.
 *
 * The residue that stood for four passes (r6 vs r1, push one register
 * narrower) was the parameter list: func_0200EA3C takes FOUR arguments
 * (its prologue homes r0..r3), and this function forwards its own r1..r3 to
 * it untouched.  With a1..a3 live in r1..r3 across the prologue the index
 * temporary cannot take r1 and lands in r6.  The only caller
 * (ov205 0x021B9B62) passes (obj, func_02012934 result, &stack date record
 * from func_02088864, 4).  The slot index is read inline in the call's
 * argument, not through a named local.
 *
 * EXACT* only because the listing extent runs over the unlabelled follower
 * func_0200EC14 (its own matched entry); compiled bytes match exactly.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8  pad[0x1554];
    u32 unk1554;
    u32 unk1558;
};

extern void func_0200EA3C(u8 *rec, void *a1, void *date, u32 heap);

void func_0200EBD0(struct Obj *obj, void *a1, void *date, u32 heap)
{
    if (obj->unk1558 < 9999) {
        u32 idx;
        func_0200EA3C((u8 *)obj + obj->unk1554 * 0x16c, a1, date, heap);
        idx = obj->unk1554 + 1;
        obj->unk1554 = idx;
        if (idx >= 15) {
            obj->unk1554 = 0;
        }
        obj->unk1558 += 1;
    }
}
