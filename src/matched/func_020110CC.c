/*
 * function: func_020110CC
 * address:  0x020110CC
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
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201C158  0x0201C158  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_02010F50  0x02010F50  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020110CC.c  *       --func func_020110CC --addr 0x020110CC --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x1a (slot 6): for each of the record's
 * four slots whose field 0x36+i is set, add the +0xe factor to field
 * 0x3a+i, clamped to func_0201C158(field 0x36+i, field 0x3e+i); inside the
 * func_02017D30 / func_02017D70 access bracket; then clear slot 6.  Same
 * declarations as func_0201104C.c (the callees take the box / record
 * pointer, the record is its own local), which is what closed the
 * entry-order residue of docs/notes/pkt_0201104C.sub_020110CC.c.txt.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_02146208[];
extern u8 g_02146228[];
extern u32   func_0201AB08(void *box);
extern void *func_0201AB28(void *box, u32 idx);
extern u32   func_02017D30(void *p);
extern u32   func_02017E1C(void *p, int field, int arg);
extern u32   func_0201C158(u16 move, u8 ppUps);
extern void  func_02017E40(void *p, int field, u32 v);
extern void  func_02017D70(void *p, u32 h);
extern void  func_02010F50(int idx);

u32 func_020110CC(void *box)
{
    void *p;
    u32 idx;
    u32 h;
    u32 i;
    u32 move;
    u32 max;
    u32 v;

    if (g_02146208[0x1a] != 0x30) {
        idx = func_0201AB08(box);
        p = func_0201AB28(box, idx);
        h = func_02017D30(p);
        for (i = 0; i < 4; i++) {
            move = func_02017E1C(p, 0x36 + i, 0);
            if (move != 0) {
                max = func_0201C158(move, func_02017E1C(p, 0x3e + i, 0));
                v = func_02017E1C(p, 0x3a + i, 0);
                v += *(u16 *)(g_02146228 + 0xe);
                if (v > max) {
                    v = max;
                }
                func_02017E40(p, 0x3a + i, v);
            }
        }
        func_02017D70(p, h);
        func_02010F50(6);
        return idx;
    }
    return 0xff;
}
