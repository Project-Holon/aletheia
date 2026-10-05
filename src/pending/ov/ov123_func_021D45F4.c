/*
 * function: func_021D45F4
 * address:  0x021D45F4
 * packet:   pkt_ov123_021D45F4
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wave D3 lane 13): complete draft, same length (316 bytes), same
 *   calls and registers for owner (r5), i (r7), j (r4) and slot (r6); 197 bytes differ.
 *   Residue: (1) prologue spill order: original spills r0 (count) to [sp,#0xc] first,
 *   then the two stack args and r1, ours copies count to r1 and spills later;
 *   (2) the slot-clear loop stores r4 (`movs r7,#0; adds r4,r7,#0` before the loop) where
 *   ours stores a fresh `movs r0,#0`; (3) in the record loop the original keeps j*4 in
 *   r6 (computed early, reused for tbl/xs/ys) and slot=owner+j*4 in r7, ours swaps them.
 *   Tried: `i = 0; j = i;`, `j = i = 0;`, literal 0 store, `int i = 0; int j = 0;`, an
 *   explicit `off = j * 4` (this recolours owner to r4, worse).  Not tried: making the
 *   count a struct field or a different parameter order.
 *
 * note (2026-10-05, wave D4 lane 06): 197 -> 43 bytes differ.  The owner is now a struct
 *   (Own: heap +0xC, obj[4] +0x10, res +0x20, bank +0x24, font +0x30, str +0x38, n +0x25C), the slot-clear loop stores a
 *   literal 0 and j is set in the for-init: the slot-clear loop and the whole tail now match.
 *   Residue: (1) prologue: original spills count to [sp,#0xc] first and reloads it for the
 *   +0x25C store (count behaves as a memory-resident variable); ours copies r0 to r1.
 *   (2) record loop scheduling: original computes j*4 (r6) and slot r7 = owner + r6 early and
 *   issues the three stack-argument stores before the recs reload; ours loads recs.a/b/c first.
 *   Tried: void **slot local before the call, recs[j].x directly instead of a Rec pointer, u8
 *   record fields, raw ((u32 *)(owner + 0x10))[j] (worse, 229), func_0201DD68(owner->n).
 *
 * symbols:
 *   func_0201DD68  0x0201DD68  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    u32 a, b, c, d;
} Rec;

extern void func_0201DD68(int n);
extern void func_020456F8(void *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020452E8(void *d);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(void *p);
extern void func_02043B5C(void *buf, u8 value);
extern void func_02045CAC(void *bank, u32 index, void *dest);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern u32 func_0201D304(void *s, u32 a, u32 b);
extern u32 func_0201D42C(void *s, void *font);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(void *d);
extern void func_02045374(void *d);
extern void func_02051C6C(void *p);
extern void func_020409B4(u32 index);

typedef struct {
    u8 pad0[0xC];
    u16 heap;
    u8 pad1[2];
    void *obj[4];
    void *res;
    void *bank;
    u8 pad2[8];
    void *font;
    u8 pad3[4];
    void *str;
    u8 pad4[0x25C - 0x3C];
    int n;
} Own;

void func_021D45F4(int count, u32 *tbl, Own *owner, const Rec *recs, u32 *xs, u32 *ys)
{
    int i;
    int j;
    int a;
    int b;

    owner->n = count;
    func_0201DD68(count);
    for (i = 0; i < 4; i++) {
        if (owner->obj[i] != 0) {
            func_020456F8(owner->obj[i]);
            func_0201F7A8(owner->obj[i], 2);
            func_020452E8(owner->obj[i]);
        }
        owner->obj[i] = 0;
    }
    func_02049B40(0x17, 5, 4, 0x100, 0x20, owner->heap);
    for (j = 0; j < count; j++) {
        const Rec *r = &recs[j];
        owner->obj[j] = (void *)func_020450F0(7, (u8)r->a, (u8)r->b, (u8)r->c, (u8)r->d, 8, 0);
        func_02043B5C(func_02045770(owner->obj[j]), 0);
        func_02045CAC(owner->bank, tbl[j], owner->str);
        func_0201DD78(0xF, 2, 0);
        if (xs != 0)
            a = xs[j] - func_0201D304(owner->str, (u32)owner->font, 0) / 2;
        else
            a = 0;
        if (ys != 0)
            b = ys[j] - func_0201D42C(owner->str, owner->font) / 2;
        else
            b = 0;
        func_0201C7A4(func_02045770(owner->obj[j]), (s16)a, (s16)b, owner->str, owner->font);
        func_02045334(owner->obj[j]);
        func_02045374(owner->obj[j]);
    }
    if (owner->res != 0)
        func_02051C6C(owner->res);
    owner->res = 0;
    func_020409B4(7);
}
