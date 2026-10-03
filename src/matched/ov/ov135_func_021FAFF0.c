/*
 * function: func_021FAFF0
 * address:  0x021FAFF0
 * packet:   pkt_021FAFF0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CAE4  0x0202CAE4  thumb
 *   func_0202CF84  0x0202CF84  thumb
 *   ov135_func_021F9260  0x021F9260  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FBF6C  0x021FBF6C  thumb
 *   func_021FBEB8  0x021FBEB8  thumb
 *   func_0202CB4C  0x0202CB4C  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   tbl_022032C6   0x022032C6  data  a1
 *   tbl_02203324   0x02203324  data
 *   tbl_022033F8   0x022033F8  data
 *   tbl_02203440   0x02203440  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

typedef struct {
    int first;
    int count;
} Range;

typedef struct {
    void **wins;
    u8 pad4[8 - 4];
    u32 cursor;
    u8 padC[0x18 - 0xC];
    void *mgr;
    u8 pad1C[0x20 - 0x1C];
    void *bank;
    u8 pad24[0x38 - 0x24];
    s16 page;
    s16 sel;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x60 - 0x4C];
    u8 flags[0x1C];
    u8 g[4];
} Menu;

struct WinMgr;
extern const CurPos tbl_022032C6[];
extern const int tbl_02203324[];
extern const Range tbl_022033F8[];
extern const u32 tbl_02203440[];

extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void ov135_func_021F9260(Menu *m, u32 mode);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FBF6C(Menu *m, u32 idx);
extern void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0204B878(u32 v, int k);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern int func_020355C4(void);
extern void func_0204B3DC(u32 v, int k);

int func_021FAFF0(Menu *m)
{
    int i;
    u16 color;

    i = 1;
    func_0202CAE4(m->mgr, 0, 0x60, 0x1A, 1);
    func_0202CF84(m->mgr, 0);
    ov135_func_021F9260(m, 5);
    func_02082BCC(m->flags, 1, 0x1A);
    func_021FBE84(m->mgr, m->bank, m->wins[0], m->page + 0x74, 2, 0x3DC2, m->g);
    for (i = 1; i < tbl_022033F8[m->page].count + 1; i++) {
        if (func_021FBF6C(m, tbl_02203324[m->page] + i - 1) > 0) {
            color = 0x3DC2;
            m->flags[tbl_02203324[m->page] + i - 1] = 1;
        } else {
            color = 0x2122;
            m->flags[tbl_02203324[m->page] + i - 1] = 0;
        }
        func_021FBE84(m->mgr, m->bank, m->wins[i], tbl_02203440[i + tbl_022033F8[m->page].first - 1], 5, color, m->g);
    }
    func_021FBEB8(m->mgr, m->bank, m->wins[14], 0x4A, m->g);
    func_0202CB4C(m->mgr, 0, 0x10, 0);
    func_0204B878(m->cursor, 4);
    if (m->sel < 0) {
        m->pos = 0;
    } else {
        m->pos = m->sel;
    }
    func_021F4FF4(m->cursor, (tbl_022032C6[m->pos].x + 0x10) * 8, tbl_022032C6[m->pos].y * 8);
    if (func_020355C4() == 1) {
        func_0204B3DC(m->cursor, 0);
    } else {
        func_0204B3DC(m->cursor, 1);
    }
    m->state = 0xB;
    return -1;
}
