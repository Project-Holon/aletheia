/*
 * function: func_021F0724
 * address:  0x021F0724
 * packet:   pkt_ov034_021F0724
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F0724 0x021F0724 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0A60    0x021F0A60 data a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    s16 x;
    s16 y;
    u16 c;
    u16 d;
} Rect;

extern void *func_020120F4(int);
typedef signed int     s32;
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern unsigned int func_0201AA18(void *);
extern int func_0204B100(int, int, unsigned);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_0201AB28(void *list, u32 i);
extern void *func_020185F4(void *a);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern int func_0204B294(int, int, int, int, Rect *, int, int);
extern void func_0204B3DC(int, int);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(u32 obj, u32 v, u32 flag);
extern void func_02043598(u32 mask, u32 enable);

extern const Rect d_021F0A60[2];

void func_021F0724(int *p)
{
    void *list;
    unsigned int n;
    unsigned int i;
    void *h;
    u32 t;
    void *e;
    Rect r;

    list = func_02012934(func_020120F4(p[0]));
    n = func_0201AA18(list);
    p[0x14] = func_0204B100(0x10, 0, *(u16 *)(p + 0x4B));
    h = func_020490F4(7, *(u16 *)(p + 0x4B));
    for (i = 0; i < n; i++)
        p[0x25 + i] = func_0204A6C8(h, func_0201BA68(func_020185F4(func_0201AB28(list, i))), 0, 1,
                                    *(u16 *)(p + 0x4B));
    p[0x34] = func_0204ACEC(h, func_0201BC3C(), 1, 0, *(u16 *)(p + 0x4B));
    t = func_0201BC40();
    p[0x41] = func_0204AF28(h, t, func_0201BCB4(), *(u16 *)(p + 0x4B));
    func_02049238(h);
    h = func_020490F4(0xC4, *(u16 *)(p + 0x4B));
    p[0x2B] = func_0204A6C8(h, 3, 1, 1, *(u16 *)(p + 0x4B));
    p[0x35] = func_0204AC18(h, 4, 1, 0x60, 0, 1, *(u16 *)(p + 0x4B));
    p[0x42] = func_0204AF28(h, 5, 6, *(u16 *)(p + 0x4B));
    func_02049238(h);
    r = d_021F0A60[0];
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        p[0x15 + i] = func_0204B294(p[0x14], p[0x25 + i], p[0x34], p[0x41], &r, 1,
                                    *(u16 *)(p + 0x4B));
        func_0204B3DC(p[0x15 + i], 0);
        r.x += 0x20;
        func_0204B6F4(p[0x15 + i], func_0201BBE8(func_020185F4(e)), 1);
    }
    r = d_021F0A60[1];
    for (i = 6; i <= 15; i++) {
        p[0x15 + i] = func_0204B294(p[0x14], p[0x2B], p[0x35], p[0x42], &r, 1,
                                    *(u16 *)(p + 0x4B));
        func_0204B3DC(p[0x15 + i], 0);
        r.x += 0xC;
    }
    func_02043598(0x10, 1);
}
