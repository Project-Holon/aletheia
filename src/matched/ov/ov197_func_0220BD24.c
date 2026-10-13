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
 *   BGWINFRM_ChangePalette 0x0202CE50 thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_HideFrame 0x0202CC70 thumb
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
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
extern void BGWINFRM_ChangePalette(struct WinMgr *mgr, u32 idx, s32 x, s32 y, u8 w, u8 h, u8 pal);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
typedef signed char    s8;
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern unsigned func_0220BB98(const char *p, unsigned n);
struct S { char pad0[0x520]; struct WinMgr *mgr; char pad1[0x533-0x524]; u8 idx; char pad2[5]; u8 fl[1]; };
#define MGR(p) (*(struct WinMgr **)((p) + 0x520))
void func_0220BD24(char *p, int mode)
{
    u32 i;
    for (i = 0; i < 14; i++) BGWINFRM_HideFrame(MGR(p), i);
    switch (mode) {
    case 0:
        BGWINFRM_PutFrame(MGR(p), 10, 27, 19);
        BGWINFRM_PutFrame(MGR(p), 13, 1, 19);
        if (*(u16 *)(p + 0x540) == 0)
            BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 3);
        else
            BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 1);
        BGWINFRM_ShowFrame(MGR(p), 0);
        BGWINFRM_ShowFrame(MGR(p), 1);
        BGWINFRM_ShowFrame(MGR(p), 2);
        BGWINFRM_ShowFrame(MGR(p), 3);
        BGWINFRM_ShowFrame(MGR(p), 10);
        BGWINFRM_ShowFrame(MGR(p), 13);
        break;
    case 1: {
        struct WinMgr **pm;
        BGWINFRM_PutFrame(MGR(p), 10, 59, 19);
        pm = (struct WinMgr **)(p + 0x520);
        for (i = 0; i < 6; i++) {
            if (func_0220BB98(p, i) == 0)
                BGWINFRM_ChangePalette(MGR(p), i + 4, 0, 0, d_0220DB44[i + 4].c, d_0220DB44[i + 4].d, 6);
            else
                BGWINFRM_ChangePalette(*pm, i + 4, 0, 0, d_0220DB44[i + 4].c, d_0220DB44[i + 4].d, 4);
        }
        {
            struct S *q = (struct S *)p;
            if (q->fl[q->idx] == 0) {
                BGWINFRM_ChangePalette(q->mgr, 11, 0, 0, 5, 5, 3);
                BGWINFRM_ChangePalette(q->mgr, 12, 0, 0, 5, 5, 3);
            } else {
                BGWINFRM_ChangePalette(q->mgr, 11, 0, 0, 5, 5, 1);
                BGWINFRM_ChangePalette(q->mgr, 12, 0, 0, 5, 5, 1);
            }
        }
        BGWINFRM_ShowFrame(MGR(p), 4);
        BGWINFRM_ShowFrame(MGR(p), 5);
        BGWINFRM_ShowFrame(MGR(p), 6);
        BGWINFRM_ShowFrame(MGR(p), 7);
        BGWINFRM_ShowFrame(MGR(p), 8);
        BGWINFRM_ShowFrame(MGR(p), 9);
        BGWINFRM_ShowFrame(MGR(p), 11);
        BGWINFRM_ShowFrame(MGR(p), 12);
        BGWINFRM_ShowFrame(MGR(p), 10);
        break;
    }
    case 2:
        BGWINFRM_ChangePalette(MGR(p), 13, 0, 0, 25, 5, 1);
        BGWINFRM_PutFrame(MGR(p), 10, 27, 51);
        BGWINFRM_PutFrame(MGR(p), 13, 1, 51);
        BGWINFRM_ShowFrame(MGR(p), 10);
        BGWINFRM_ShowFrame(MGR(p), 13);
        break;
    }
}
