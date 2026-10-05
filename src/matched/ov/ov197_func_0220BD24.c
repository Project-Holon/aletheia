/*
 * function: func_0220BD24
 * address: 0x0220BD24
 * packet: pkt_ov197_0220BD24
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (wave D4 lane 02): the two window calls 11/12 are written in each if/else
 *   arm with literal arguments. Tail merging sinks the common call parts into the join and keeps
 *   r4 = 0x533 live, so 0x520 comes out as 0x533 - 0x13.
 * symbols:
 *   func_0202CE50 0x0202CE50 thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0202CC70 0x0202CC70 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0220BB98 0x0220BB98 thumb
 *   d_0220DB44 0x0220DB44 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
struct Row { u8 a,b,c,d; };
extern const struct Row d_0220DB44[];
struct WinMgr;
extern void func_0202CE50(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s32 a, s32 b);
extern u32 func_0220BB98(char *p, u32 n);
struct S { char pad0[0x520]; struct WinMgr *mgr; char pad1[0x533-0x524]; u8 idx; char pad2[5]; u8 fl[1]; };
#define MGR(p) (*(struct WinMgr **)((p) + 0x520))
void func_0220BD24(char *p, u32 mode)
{
    u32 i;
    for (i = 0; i < 14; i++) func_0202CC70(MGR(p), i);
    switch (mode) {
    case 0:
        func_0202CB4C(MGR(p), 10, 27, 19);
        func_0202CB4C(MGR(p), 13, 1, 19);
        if (*(u16 *)(p + 0x540) == 0)
            func_0202CE50(MGR(p), 13, 0, 0, 25, 5, 3);
        else
            func_0202CE50(MGR(p), 13, 0, 0, 25, 5, 1);
        func_0202CC58(MGR(p), 0);
        func_0202CC58(MGR(p), 1);
        func_0202CC58(MGR(p), 2);
        func_0202CC58(MGR(p), 3);
        func_0202CC58(MGR(p), 10);
        func_0202CC58(MGR(p), 13);
        break;
    case 1: {
        struct WinMgr **pm;
        func_0202CB4C(MGR(p), 10, 59, 19);
        pm = (struct WinMgr **)(p + 0x520);
        for (i = 0; i < 6; i++) {
            if (func_0220BB98(p, i) == 0)
                func_0202CE50(MGR(p), i + 4, 0, 0, d_0220DB44[i + 4].c, d_0220DB44[i + 4].d, 6);
            else
                func_0202CE50(*pm, i + 4, 0, 0, d_0220DB44[i + 4].c, d_0220DB44[i + 4].d, 4);
        }
        {
            struct S *q = (struct S *)p;
            if (q->fl[q->idx] == 0) {
                func_0202CE50(q->mgr, 11, 0, 0, 5, 5, 3);
                func_0202CE50(q->mgr, 12, 0, 0, 5, 5, 3);
            } else {
                func_0202CE50(q->mgr, 11, 0, 0, 5, 5, 1);
                func_0202CE50(q->mgr, 12, 0, 0, 5, 5, 1);
            }
        }
        func_0202CC58(MGR(p), 4);
        func_0202CC58(MGR(p), 5);
        func_0202CC58(MGR(p), 6);
        func_0202CC58(MGR(p), 7);
        func_0202CC58(MGR(p), 8);
        func_0202CC58(MGR(p), 9);
        func_0202CC58(MGR(p), 11);
        func_0202CC58(MGR(p), 12);
        func_0202CC58(MGR(p), 10);
        break;
    }
    case 2:
        func_0202CE50(MGR(p), 13, 0, 0, 25, 5, 1);
        func_0202CB4C(MGR(p), 10, 27, 51);
        func_0202CB4C(MGR(p), 13, 1, 51);
        func_0202CC58(MGR(p), 10);
        func_0202CC58(MGR(p), 13);
        break;
    }
}
