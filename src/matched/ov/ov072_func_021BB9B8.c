/*
 * function: func_021BB9B8
 * address:  0x021BB9B8
 * packet:   pkt_ov072_021BB9B8
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BBC0C     0x021BBC0C  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Rect;

typedef struct { u32 w[7]; } Tbl;

typedef struct {
    u32 res;
    u32 obj[4];
    u32 f14;
    u32 chr;
    u32 cell;
    u32 pal;
} Gfx;

extern void func_02082BCC(void *p, int v, int n);
struct Cfg;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
struct Obj;
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
typedef signed int     s32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern u32 func_0204ABF0(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern u32 func_0204A6C8(void *arc, u32 id, u32 a, u32 b, u32 heap);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern u32 func_0204B294(u32, u32, u32, u32, Rect *, u32, u32);
extern void func_0204B878(struct Obj *p, u16 value);
struct Obj;
extern void func_0204B3DC(struct Obj *a, unsigned int v);
extern const Tbl d_021BBC0C;

void func_021BB9B8(Gfx *o, u32 mode, u32 heap)
{
    int i;
    void *h;
    Tbl t;
    Rect s;

    i = 0;
    func_02082BCC(o, 0, 0x24);
    t = d_021BBC0C;
    func_0204A48C((const struct Cfg *)(&t), mode, heap);
    o->res = (u32)func_0204B100(0x80, 0, heap);
    CLACT_SetUnitDefaultRenderer((struct Bank *)o->res);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    h = func_020490F4(0x55, heap);
    o->pal = func_0204ABF0(h, 2, 0, 0, heap);
    o->chr = func_0204A6C8(h, 8, 0, 0, heap);
    o->cell = func_0204AF28(h, 0xc, 0x13, heap);
    func_02049238(h);
    func_02082BCC(&s, 0, 8);
    for (; i < 4; i++) {
        o->obj[i] = func_0204B294(o->res, o->chr, o->pal, o->cell, &s, 1, heap);
    }
    func_0204B878((struct Obj *)o->obj[0], 0);
    func_0204B878((struct Obj *)o->obj[1], 4);
    func_0204B878((struct Obj *)o->obj[2], 5);
    func_0204B878((struct Obj *)o->obj[3], 6);
    for (i = 0; i < 4; i++) {
        func_0204B3DC((struct Obj *)o->obj[i], 0);
    }
}
