/*
 * function: func_021BD844
 * address: 0x021BD844
 * packet: pkt_ov172_021BD844
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: closed. The draft read pal->raw through one extra load (the out
 *   parameter of func_02049F78 is a palette-data pointer; raw is at +0xc), and the
 *   last call is written per arm (literal 7/6 in each arm); a shared ternary or
 *   sel variable lets the compiler CSE the constant 7 into a stack temp.
 * symbols:
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0204AC18 0x0204AC18 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02049238 0x02049238 arm
 *   func_021BE024 0x021BE024 thumb ov172
 *   func_021BE018 0x021BE018 thumb ov172
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082A90 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Sub0200852CObj;
struct PltData { u32 fmt; u32 ext; u32 size; u8 *raw; };
struct CellCfg { u16 a; u16 b; u16 c; u8 d; u8 e; };
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020490F4(u32 id, u32 heap);
struct Obj;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 index);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u32 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void func_02049238(void *arc);
extern u32 func_021BE024(void *p);
extern u32 func_021BE018(void *p, int i);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *e, unsigned short f, unsigned short g);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082A90(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);

#define W(o) (*(u32 *)(p + (o)))
#define BG (*(void **)(p + 0x17c))
#define HEAP (*(u16 *)p)
void func_021BD844(u8 *p)
{
    struct Sub0200852CObj *t;
    void *dev;
    u32 o;
    u32 i0;
    u32 i1;
    u32 i2;
    int z;
    struct CellCfg cfg;
    struct PltData *pal;
    t = (struct Sub0200852CObj *)func_02012944(*(void **)W(0x1f8));
    BG = func_020490F4(0xac, HEAP);
    if (func_02008550(t) == 0) {
        func_02049B68(BG, 7, 4, 0, 0xc0, HEAP);
    } else {
        func_02049B68(BG, 6, 4, 0, 0xc0, HEAP);
    }
    z = 0;
    func_02049658(BG, 0xb, 7, 0, z, z, HEAP);
    func_020498F4(BG, 0xe, 7, 0, z, z, HEAP);
    func_020409B4(7);
    func_02049B68(BG, 0, 0, 0x20, 0x20, HEAP);
    func_02049658(BG, 8, 1, 0, z, z, HEAP);
    func_020498F4(BG, 0xd, 1, 0, z, z, HEAP);
    func_020409B4(1);
    W(0x180) = func_0204ACEC(BG, 3, 0, 0, HEAP);
    W(0x190) = func_0204A6C8(BG, 0x18, 0, 0, HEAP);
    W(0x1a0) = func_0204AF28(BG, 0x14, 0x16, HEAP);
    W(0x184) = func_0204ACEC(BG, 3, 1, 0, HEAP);
    W(0x194) = func_0204A6C8(BG, 0x17, 0, 1, HEAP);
    W(0x1a4) = func_0204AF28(BG, 0x13, 0x15, HEAP);
    dev = func_020490F4(func_020275E4(), HEAP);
    func_02049B68(dev, func_02027624(), 0, 0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 0, 0, z, z, HEAP);
    func_02049B68(dev, func_02027624(), 4, 0xc0, 0x20, HEAP);
    func_02049658(dev, func_02027628(), 5, z, z, z, HEAP);
    func_020498F4(dev, func_0202762C(), 5, z, z, z, HEAP);
    func_020413B0(5, z, 0x15, 0x20, 3, 6);
    func_020409B4(5);
    W(0x18c) = func_0204AC18(dev, func_02027614(), z, 0xe0, z, 3, HEAP);
    W(0x19c) = func_0204A6C8(dev, func_02027618(), z, z, HEAP);
    W(0x188) = func_0204AC18(dev, func_02027614(), 1, 0xe0, z, 3, HEAP);
    W(0x198) = func_0204A6C8(dev, func_02027618(), z, 1, HEAP);
    W(0x1a8) = func_0204AF28(dev, func_0202761C(2), func_02027620(2), HEAP);
    func_02049238(dev);
    cfg.a = z;
    cfg.b = z;
    cfg.c = z;
    cfg.d = z;
    cfg.e = z;
    o = func_021BE024(p);
    i0 = func_021BE018(p, 4);
    i1 = func_021BE018(p, z);
    i2 = func_021BE018(p, 8);
    W(0x1b0) = (u32)func_0204B294((void *)o, i0, i1, i2, &cfg, z, HEAP);
    func_0204B3DC((void *)W(0x1b0), z);
    func_0204B92C((void *)W(0x1b0), 1);
    if (func_02008550(t) == 0) {
        dev = func_02049F78(BG, 7, (u32)(&pal), HEAP);
    } else {
        dev = func_02049F78(BG, 6, (u32)(&pal), HEAP);
    }
    func_02082A90(pal->raw + 0xc0, p + 0x3c, 0x140);
    func_020307B0(dev);
}
