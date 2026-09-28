/*
 * function: func_021FB3D8
 * address:  0x021FB3D8
 * packet:   pkt_021FB3D8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   tbl_02203324  0x02203324  data  a4
 *   tbl_02203220  0x02203220  data
 *   func_021F9260  0x021F9260  thumb
 *   func_021FB26C  0x021FB26C  thumb
 *   func_021FB2F0  0x021FB2F0  thumb
 *   func_021F9EEC  0x021F9EEC  thumb
 *   func_021FBF04  0x021FBF04  thumb
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
    void **strs;
    u8 pad4[8 - 4];
    u32 cursor;
    u32 left;
    u32 right;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    void *bag;
    void *bank;
    void *msg;
    u8 pad28[0x2C - 0x28];
    u32 x2c;
    void *menu;
    void *list;
    s16 layout;
    s16 start;
    u8 pad3C[0x44 - 0x3C];
    int pos;
    int state;
    u8 pad4C[0x56 - 0x4C];
    s16 page;
    int count;
    u8 pad5C[0x7C - 0x5C];
    u8 g[4];
} Obj;

extern const int tbl_02203324[];
extern const Cell tbl_02203220[];

extern void func_0202CAE4(void *mgr, int a, int b, int c, int d);
extern u32 func_0202CF84(void *mgr, u32 idx);
extern void func_021F9260(Obj *p, u32 mode);
extern int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);
extern void func_021FB2F0(Obj *p, int page, int total);
extern u32 func_021F9EEC(int n, u32 per);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern void func_021FBEB8(void *mgr, void *bank, void *win, u32 index, void *g);
extern void func_0202CB4C(void *mgr, int a, int b, int c);
extern void func_0204B878(u32 v, int k);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern int func_020355C4(void);
extern void func_0204B3DC(u32 obj, int on);
extern void func_0204B92C(u32 obj, int v);

int func_021FB3D8(Obj *p)
{
    u8 pages;

    func_0202CAE4(p->mgr, 0, 0x60, 0x1D, 1);
    func_0202CF84(p->mgr, 0);
    func_021F9260(p, 0);
    p->count = func_021FB26C(&p->menu, p->msg, p->bank, p->x2c, tbl_02203324[p->layout] + p->start, p->bag);
    p->page = 0;
    func_021FB2F0(p, 0, p->count);
    pages = func_021F9EEC(p->count, 4);
    func_021FBF04(p->mgr, p->list, p->strs[4], p->page, pages);
    func_021FBEB8(p->mgr, p->bank, p->strs[14], 0x4A, p->g);
    func_0202CB4C(p->mgr, 0, 0x10, 0);
    func_0204B878(p->cursor, 6);
    p->pos = 0;
    func_021F4FF4(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    func_021F4FF4(p->left, 0xE4, 0x78);
    func_021F4FF4(p->right, 0x9A, 0x78);
    if (func_020355C4() == 1) {
        func_0204B3DC(p->cursor, 0);
    } else {
        func_0204B3DC(p->cursor, 1);
    }
    if (pages == 1) {
        func_0204B878(p->left, 0x3D);
        func_0204B878(p->right, 0x3E);
    } else {
        func_0204B878(p->left, 0x26);
        func_0204B878(p->right, 0x27);
    }
    func_0204B92C(p->left, 0);
    func_0204B92C(p->right, 0);
    func_0204B3DC(p->left, 1);
    func_0204B3DC(p->right, 1);
    p->state = 0xF;
    return -1;
}
