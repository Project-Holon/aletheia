/*
 * function: func_0219630C
 * address:  0x0219630C
 * packet:   pkt_ov021_0219630C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020414EC  0x020414EC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020456F8  0x020456F8  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02051C6C  0x02051C6C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02040588  0x02040588  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 x0; u32 x4; u32 x8; u32 xc; } Desc;
typedef struct Obj {
    u8 pad0[0x10];
    u16 x10;
    u16 pad12;
    u32 w[4];
    u32 x24;
    u32 x28;
    u32 x2c;
    u8 pad30[8];
    u32 x38;
    u8 pad3c[0x2B8];
    int x2f4;
} Obj;
extern void func_020414EC(u32);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct StrObj;
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02051C6C(void *p);
extern void func_02041B6C(u32);
extern void func_02040588(u32, u32);

void func_0219630C(int n, u32 *msg, Obj *a, Desc *d, int *xs, int *ys)
{
    int i;
    int x;
    int y;

    func_020414EC(7);
    a->x2f4 = n;
    func_02049B40(0x17, 5, 4, 0x100, 0x20, a->x10);
    for (i = 0; i < 4; i++) {
        if (a->w[i] != 0) {
            func_020456F8((struct Descriptor *)a->w[i]);
            func_0201F7A8((void *)a->w[i], 2);
            func_020452E8((struct Descriptor *)a->w[i]);
        }
        a->w[i] = 0;
    }
    for (i = 0; i < n; i++) {
        func_0201DD78(15, 2, 0);
        a->w[i] = func_020450F0(7, (u8)d[i].x0, (u8)d[i].x4, (u8)d[i].x8, (u8)d[i].xc, 8, 0);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)a->w[i])), 0);
        func_02045CAC((struct MsgBank *)a->x28, msg[i], (void *)a->x38);
        if (xs != 0) {
            x = xs[i] - (func_0201D304((struct StrObj *)a->x38, a->x2c, 0) >> 1);
        } else {
            x = 0;
        }
        if (ys != 0) {
            y = ys[i] - (func_0201D42C((struct StrObj *)a->x38, (void *)a->x2c) >> 1);
        } else {
            y = 0;
        }
        func_0201C7A4((void *)((u32)func_02045770((struct Descriptor *)a->w[i])), x, y, (void *)a->x38, (void *)a->x2c);
        func_02045334((struct Descriptor *)a->w[i]);
        func_02045374((struct Cfg *)a->w[i]);
    }
    if (a->x24 != 0) {
        func_02051C6C((void *)a->x24);
    }
    a->x24 = 0;
    func_02041B6C(7);
    func_02040588(7, 1);
}
