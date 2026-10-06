/*
 * function: func_021BB184
 * address:  0x021BB184
 * packet:   pkt_ov088_021BB184
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads two resource archives (0x1f and 0x23) and builds the sprite
 * resources and actors from them.  Twin: ov088_func_021B9EC4.c.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_02008550  0x02008550  thumb
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02049238  0x02049238  arm
 *   d_021BD688     0x021BD688  data  a4
 *   d_021BD60C     0x021BD60C  data  a4
 *   d_021BD5DC     0x021BD5DC  data  a4
 *   d_021BD5E4     0x021BD5E4  data  a4
 *   d_021BD5D4     0x021BD5D4  data  a4
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct T28 {
    u32 w[7];
} T28;

extern T28 d_021BD688;
extern char d_021BD60C[];
extern char d_021BD5DC[];
extern char d_021BD5E4[];
extern char d_021BD5D4[];

extern void *func_020490F4(unsigned int id, u16 heap);
typedef unsigned char  u8;
struct Bank;
struct Cfg;
struct Sub0200852CObj;
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
typedef signed int     s32;
struct Obj;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 space, u16 heap);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *, u32);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02049238(void *);

void func_021BB184(int *p)
{
    T28 t;
    void *h;
    u32 i;

    t = d_021BD688;
    func_0204A48C((const struct Cfg *)(&t), (u32)d_021BD60C, 0xb);
    h = func_020490F4(0x1f, 0x800b);
    if (func_02008550((const struct Sub0200852CObj *)p[1]) == 0) {
        p[13] = func_0204A6C8(h, 5, 0, 0, 0xb);
        p[16] = func_0204ABF0(h, 4, 0, 0, 0xb);
        p[19] = func_0204AF28(h, 0, 1, 0xb);
    } else {
        p[13] = func_0204A6C8(h, 7, 0, 0, 0xb);
        p[16] = func_0204ABF0(h, 6, 0, 0, 0xb);
        p[19] = func_0204AF28(h, 2, 3, 0xb);
    }
    func_02049238(h);
    h = func_020490F4(0x23, 0x800b);
    p[14] = func_0204A6C8(h, 8, 1, 0, 0xb);
    p[17] = func_0204ABF0(h, 9, 0, 0x20, 0xb);
    p[20] = func_0204AF28(h, 0xa, 0xb, 0xb);
    p[15] = func_0204A6C8(h, 0xc, 1, 0, 0xb);
    p[18] = func_0204ABF0(h, 0xd, 0, 0x40, 0xb);
    p[21] = func_0204AF28(h, 0xe, 0xf, 0xb);
    func_02049238(h);
    p[6] = (int)func_0204B100(6, 0, 0xb);
    p[7] = (int)func_0204B294((void *)p[6], p[13], p[16], p[19], d_021BD5DC, 0, 0xb);
    func_0204B3DC((void *)p[7], 0);
    for (i = 1; i <= 4; i++) {
        p[7 + i] = (int)func_0204B294((void *)p[6], p[14], p[17], p[20], d_021BD5E4, 0, 0xb);
        func_0204B92C((struct Obj *)p[7 + i], 1);
        func_0204B3DC((void *)p[7 + i], 0);
    }
    p[12] = (int)func_0204B294((void *)p[6], p[15], p[18], p[21], d_021BD5D4, 0, 0xb);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}
