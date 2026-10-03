/*
 * function: func_0201104C
 * address:  0x0201104C
 * packet:   pkt_0201104C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208     0x02146208  data
 *   g_02146228     0x02146228  data
 *   func_0201BA34  0x0201BA34  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_02010F50  0x02010F50  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201104C.c  *       --func func_0201104C --addr 0x0201104C --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x19 (slot 5): unless the +0xc factor
 * is 999, pick the record func_0201AB08(box) names inside the box
 * (func_0201AB28: box + 8 + idx * 0xdc), and add the +0xc factor to its
 * field 0xa0 clamped to field 0xa1, inside the func_02017D30 /
 * func_02017D70 access bracket; then clear slot 5.  Returns the index, or
 * 0xff when the mode byte is '0'.
 *
 * Wave 14 closed the entry residue shared with func_020110CC and
 * func_020111BC (pool word loaded into r1 before the parameter copy):
 * it was ARITY, not order.  func_0201BA34, func_0201AB08 (a tail-call
 * forwarder that passes r0 through) and func_02017D30 all take the box
 * or record pointer, so r0 stays live across the guards.  The record is
 * a separate local from the box parameter (reassigning the parameter
 * swaps r4/r5).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 g_02146208[];
extern u8 g_02146228[];
extern void func_0201BA34(void *p);
extern u32 func_0201AB08(void *p);
extern void *func_0201AB28(void *p, u32 idx);
struct Sav;
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern void func_02010F50(int idx);

u32 func_0201104C(void *box)
{
    void *p;
    u32 idx;
    u32 h;
    int max;
    int n;

    if (g_02146208[0x19] != 0x30) {
        if (*(u16 *)(g_02146228 + 0xc) == 999) {
            func_0201BA34(box);
            idx = 0;
        } else {
            idx = func_0201AB08(box);
            p = func_0201AB28(box, idx);
            h = func_02017D30(p);
            max = func_02017E1C(p, 0xa1, 0);
            n = func_02017E1C(p, 0xa0, 0);
            n = n + *(u16 *)(g_02146228 + 0xc);
            if (n > max) {
                n = max;
            }
            func_02017E40(p, 0xa0, n);
            func_02017D70(p, h);
        }
        func_02010F50(5);
        return idx;
    }
    return 0xff;
}
