/*
 * function: func_021FB800
 * address:  0x021FB800
 * packet:   pkt_021FB800
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
  *
 * symbols:
 *   tbl_02203324  0x02203324  data  a4
 *   tbl_022033F8  0x022033F8  data
 *   tbl_02203440  0x02203440  data  a4
 *   tbl_022032C6  0x022032C6  data
 *   func_021F9260  0x021F9260  thumb
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FC008  0x021FC008  thumb
 *   func_021FBEB8  0x021FBEB8  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    int first;
    int count;
} Span;

typedef struct {
    void **strs;
    u8 pad4[8 - 4];
    u32 cursor;
    u8 padC[0x14 - 0xC];
    u32 cursor2;
    void *mgr;
    u8 pad1C[0x20 - 0x1C];
    void *bank;
    u8 pad24[0x38 - 0x24];
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x60 - 0x4C];
    u8 flags[0x7C - 0x60];
    u8 g[4];
} Obj;

struct WinMgr;
extern const int tbl_02203324[];
extern const Span tbl_022033F8[];
extern const u32 tbl_02203440[];
extern const Cell tbl_022032C6[];

extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(Obj *p, u32 mode);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FC008(void *p, u32 a);
extern void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern u8 func_020355C4(void);
struct Obj;
extern void func_0204B3DC(struct Obj *obj, unsigned int on);

int func_021FB800(Obj *p)
{
    int i;
    u16 color;

    func_0202CAE4(p->mgr, 0, 0x60, 0x1A, 1);
    func_0202CF84(p->mgr, 0);
    func_021F9260(p, 5);
    func_02082BCC(p->flags, 1, 0x1A);
    func_021FBE84(p->mgr, p->bank, p->strs[0], p->layout + 0x74, 2, 0x3DC2, p->g);
    for (i = 1; i < 4; i++) {
        if (func_021FC008(p, tbl_02203324[p->layout] + i - 1) > 0) {
            color = 0x3DC2;
            p->flags[tbl_02203324[p->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            p->flags[tbl_02203324[p->layout] + i - 1] = 0;
        }
        func_021FBE84(p->mgr, p->bank, p->strs[i], tbl_02203440[tbl_022033F8[p->layout].first + i - 1], 5, color, p->g);
    }
    func_021FBEB8(p->mgr, p->bank, p->strs[14], 0x4A, p->g);
    func_0202CB4C(p->mgr, 0, 0x10, 0);
    func_0204B878((struct Obj *)p->cursor, 4);
    if (p->start < 0) {
        p->pos = 0;
    } else {
        p->pos = p->start;
    }
    func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
    if (func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 0);
    } else {
        func_0204B3DC((struct Obj *)p->cursor, 1);
    }
    if (p->cursor2 != 0) {
        func_0204B3DC((struct Obj *)p->cursor2, 1);
    }
    p->state = 0x17;
    return -1;
}
