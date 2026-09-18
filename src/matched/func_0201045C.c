/*
 * function: func_0201045C
 * address:  0x0201045C
 * packet:   pkt_0201045C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021461E0        0x021461E0  data
 *   func_02082D44     0x02082D44  arm
 *
 * wih_dwc.c: pick one of four 0xC0-byte records out of the object hanging off
 * 0x021461E0 and hand it to 0x02082D44, then bump the record count field.
 *
 * The three guards are one predicate: the count at +0x310, then the index at
 * +0x316 against the count and against 4.  The pointer is loaded once (the
 * code loads [r5] a single time) but re-loaded after the call, because the
 * callee may write the global it hangs off.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201045C.c \
 *       --func func_0201045C --addr 0x0201045C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub0201045CObj {
    u8  pad0[0x310];
    u16 count;      /* +0x310 */
    u16 pad312;
    u16 pad314;
    u16 index;      /* +0x316 */
};

extern struct Sub0201045CObj *g_021461E0;
extern void func_02082D44(u8 *p, u8 *rec);

void func_0201045C(u8 *p)
{
    struct Sub0201045CObj *o = g_021461E0;
    u16 n = o->count;
    u16 i;

    if (n == 0)
        return;
    i = o->index;
    if (i >= n)
        return;
    if (i >= 4)
        return;

    func_02082D44(p, (u8 *)o + i * 0xC0);

    g_021461E0->index = g_021461E0->index + 1;
}
