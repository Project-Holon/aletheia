/*
 * function: func_021B9280
 * address:  0x021B9280
 * packet:   pkt_ov070_021B9280
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note 2026-10-05 (wave D9r lane71): EXACT. The last 2 bytes (+0x15A movs vs copy of r4) closed with
 *   the real return type of func_02049990: void (u32 in the draft kept one more value in the IR between
 *   the 02008550 join and the 0x58 close). The contested data hints d_021BBBE0 and d_021BBAB0 resolve as
 *   "data a4" (no overlay token). Earlier wave notes (D3 to D9r) are in git history.
 * symbols:
 *   func_021B8F98  0x021B8F98  thumb  ov070
 *   func_021B9178  0x021B9178  thumb  ov070
 *   func_021B91FC  0x021B91FC  thumb  ov070
 *   func_021BA6F4  0x021BA6F4  thumb  ov070
 *   func_021BB5A4  0x021BB5A4  thumb  ov070
 *   d_021BBBE0  0x021BBBE0  data a4
 *   d_021BBA8C  0x021BBA8C  data  ov070
 *   d_021BBAB0  0x021BBAB0  data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct { u16 x, y, z; u8 a, b; } Rect;
typedef struct { u32 w[4]; } Tbl16;
extern u8 d_021BBBE0[];
extern u8 d_021BBA8C[];
extern const Tbl16 d_021BBAB0;
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct Obj;
struct Sub0200852CObj;
extern void func_020433E0(const struct DispVram *c);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_021B8F98(void);
extern void func_0201DD68(void);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u32 func_021B9178(char *p, int bg);
extern void func_021B91FC(u8 *, void *);
extern void func_02049238(void *);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_020409B4(u32 index);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_021BA6F4(char *p);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern u32 func_02027610(u32 a);
extern u32 func_020275F8(u32 a);
extern u8 func_02027604(u8 i);
extern u8 func_020275EC(int i);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_021BB5A4(char *p);

static inline void LoadIcons(u8 *p)
{
    void *a;
    u32 m;
    u32 i;

    a = func_020490F4(func_020275E4(), *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x5E0) = func_0204AC18(a, func_020275E8(), 1, 0x80, 0, 3, *(u16 *)(p + 0x544));
    m = func_020275FC(2);
    *(u32 *)(p + 0x5E4) = func_0204AF28(a, m, func_02027600(2), *(u16 *)(p + 0x544));
    for (i = 0; i < 3; i++)
        *(u32 *)(p + i * 4 + 0x5E8) = func_0204A6C8(a, func_02027610((u8)i), 0, 1, *(u16 *)(p + 0x544));
    for (i = 0; i < 17; i++)
        *(u32 *)(p + i * 4 + 0x59C) = func_0204A6C8(a, func_020275F8((u8)i), 0, 1, *(u16 *)(p + 0x544));
    func_02049238(a);
}

void func_021B9280(u8 *p)
{
    Tbl16 t;
    Rect r2;
    Rect r1;
    Rect r0;
    void *h;
    u32 v;
    u32 i;

    *(volatile u16 *)0x04000050 = 0;
    func_0203F8F4(*(u16 *)(p + 0x544));
    func_02045088(*(u16 *)(p + 0x544));
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021BBBE0);
    func_0204A48C((const struct Cfg *)d_021BBA8C, (u32)d_021BBBE0, *(u16 *)(p + 0x544));
    t = d_021BBAB0;
    func_0203FC28((struct DispConfig *)(&t));
    func_02043534(0);
    func_020435F4(0);
    func_021B8F98();
    func_0201DD68();
    *(u32 *)(p + 0x838) = (u32)func_0201F5DC((void *)3, 13, 0, *(u16 *)(p + 0x544));
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    func_02049B68(h, 8, 4, 0, 0, *(u16 *)(p + 0x544));
    if (func_02008550((const struct Sub0200852CObj *)(*(u32 *)(p + 8))) == 0)
        func_02049BDC(h, 8, 4, 0x20, 0, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 6, 4, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x7FC) = v;
    func_02049990(h, 7, 4, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    func_021B9178((char *)p, (int)h);
    v = func_02049740(h, 0x11, 5, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x800) = v;
    func_02049990(h, 0x17, 5, 0, (u16)v, 0, 0, *(u16 *)(p + 0x544));
    func_021B91FC(p, h);
    *(u32 *)(p + 0x808) = func_02049740(h, 0x21, 3, 0, 0, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x22, 0, 0x60, 0x20, *(u16 *)(p + 0x544));
    func_02049238(h);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x69C) = (u32)func_0204B100(0x34, 0, *(u16 *)(p + 0x544));
    func_02043598(0x10, 1);
    func_020434DC(0x10, 1);
    h = func_020490F4(0x53, *(u16 *)(p + 0x544));
    func_02049B68(h, 0x1B, 0, 0x100, 0x20, *(u16 *)(p + 0x544));
    v = func_02049740(h, 0x1C, 1, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x804) = v;
    func_02049990(h, 0x1D, 1, 0, (u16)v + 0x8000, 0, 0, *(u16 *)(p + 0x544));
    func_020409B4(1);
    *(u32 *)(p + 0x55C) = func_0204AC18(h, 0x13, 0, 0x140, 0, 3, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x564) = func_0204A6C8(h, 0x14, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x570) = func_0204AF28(h, 0x17, 0x1A, *(u16 *)(p + 0x544));
    func_02049238(h);
    func_021BA6F4((char *)p);
    LoadIcons(p);
    r2.x = 0x50;
    r2.y = 0xB8;
    r2.a = 1;
    r2.b = 1;
    r2.z = 0;
    for (i = 0; i < 3; i++) {
        *(u32 *)(p + i * 4 + 0x6C0) = (u32)func_0204B294((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + i * 4 + 0x5E8), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r2, 1, *(u16 *)(p + 0x544));
        func_0204B6F4((struct Obj *)(*(u32 *)(p + i * 4 + 0x6C0)), func_02027604((u8)i), 1);
        func_0204B3DC((struct Obj *)(*(u32 *)(p + i * 4 + 0x6C0)), 0);
    }
    r1.x = 0x52;
    r1.y = 0xA5;
    r1.a = 1;
    r1.b = 1;
    r1.z = 0;
    for (i = 0; i < 17; i++) {
        *(u32 *)(p + i * 4 + 0x6CC) = (u32)func_0204B294((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + i * 4 + 0x59C), *(u32 *)(p + 0x5E0), *(u32 *)(p + 0x5E4), &r1, 1, *(u16 *)(p + 0x544));
        func_0204B6F4((struct Obj *)(*(u32 *)(p + i * 4 + 0x6CC)), func_020275EC((u8)i), 1);
        func_0204B3DC((struct Obj *)(*(u32 *)(p + i * 4 + 0x6CC)), 0);
    }
    h = func_020490F4(0x58, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x580) = func_0204AC18(h, 0x27, 0, 0x80, 0, 2, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x584) = func_0204A6C8(h, 0x26, 0, 0, *(u16 *)(p + 0x544));
    *(u32 *)(p + 0x58C) = func_0204AF28(h, 0x25, 0x24, *(u16 *)(p + 0x544));
    func_02049238(h);
    r0.a = 10;
    r0.b = 1;
    r0.x = 0x92;
    r0.y = 0xB0;
    r0.z = 0;
    *(u32 *)(p + 0x72C) = (u32)func_0204B294((void *)(*(u32 *)(p + 0x69C)), *(u32 *)(p + 0x584), *(u32 *)(p + 0x580), *(u32 *)(p + 0x58C), &r0, 0, *(u16 *)(p + 0x544));
    func_0204B92C((struct Obj *)(*(u32 *)(p + 0x72C)), 1);
    func_0204B3DC((struct Obj *)(*(u32 *)(p + 0x72C)), 1);
    func_021BB5A4((char *)p);
}
