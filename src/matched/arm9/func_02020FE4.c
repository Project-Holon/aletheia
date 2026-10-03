/*
 * unit:     no
 * address:  0x02020FE4
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02020FE4
 *
 * symbols:
 *   func_02020F34  0x02020F34  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * One-shot wrapper over the record getter of src/matched/unit_02021014.c:
 * build a temporary record for the id (with bit 15 forced on and the rest of
 * the id masked to fifteen bits), read one property out of it, free it, and
 * answer the property.
 *
 * 0x8000 costs no second pool word: the compiler keeps 0x7FFF in r3 for the
 * mask and derives the set bit from it with `adds r2, r3, #1`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02020FE4.c \
 *       --func func_02020FE4 --addr 0x02020FE4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_02020F34(void *a, u32 b, u32 id);
struct Rec;
extern u32 func_02021014(struct Rec *p, u32 sel);
extern void  func_020307B0(void *p);

u32 func_02020FE4(void *a, u32 sel, u32 id)
{
    void *rec;
    u32   v;

    rec = func_02020F34(a, 0, (u16)((id & 0x7FFF) | 0x8000));
    v = func_02021014(rec, sel);
    func_020307B0(rec);
    return v;
}
