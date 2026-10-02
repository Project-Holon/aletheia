/*
 * function: func_021BD1AC
 * address:  0x021BD1AC
 * packet:   pkt_ov172_021BD1AC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02: whole body matches except the 4-window loop tail: the original
 * copies i to r6 first and passes r6 to sub_02043B5C, then stores r6 (=3) twice;
 * every spelling tried (for/do-while, j=i before/after, u32 j, i=j+1 early) lets
 * the compiler forward r5 into the call or swaps r5/r6. func_021B80DC/80EC also
 * sit in the mislabelled ARM span 021B80CC..810C (layout gap, figure move).
 *
 * symbols:
 *   func_021BD5D8  0x021BD5D8  thumb  ov172
 *   func_021BD844  0x021BD844  thumb  ov172
 *   func_021B6EE0  0x021B6EE0  thumb  ov172
 *   func_021B7BA8  0x021B7BA8  thumb  ov172
 *   func_021B8C3C  0x021B8C3C  thumb  ov172
 *   func_021BA280  0x021BA280  thumb  ov172
 *   func_021BBA6C  0x021BBA6C  thumb  ov172
 *   func_021B6BE0  0x021B6BE0  thumb  ov172
 *   func_021B80DC  0x021B80DC  thumb
 *   func_021B80EC  0x021B80EC  thumb
 *   func_021BD5AC  0x021BD5AC  thumb  ov172
 *   func_021BDBC4  0x021BDBC4  thumb  ov172
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

extern void func_021BD5D8(char *ctx);
extern void func_021BD844(char *ctx);
extern void func_021BDBC4(u8 *p);
extern void *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_021B6EE0(char *ctx, u32 id);
extern void *func_021B7BA8(char *ctx, u32 id);
extern void *func_021B8C3C(char *ctx, u32 id);
extern void *func_021BA280(char *ctx, u32 id);
extern void *func_021BBA6C(char *ctx, u32 id);
extern void *func_021B6BE0(Params *p);
extern void func_021B80DC(char *ctx, u32 a, u32 b);
extern void func_021B80EC(char *ctx, u32 a, u32 b);
extern void func_021BD5AC(int unused, char *ctx);
extern void *func_020056A0(void (*cb)(int, char *), char *arg, u32 prio);
extern int  func_0202EB14(void);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02012A30(u32 a);
extern void func_02028A70(void);
extern u32  sub_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(u32 w);
extern void sub_02043B5C(void *buf, u8 value);
extern void func_02005D90(u32 a, u32 b);

#define F(o) (*(u32 *)(ctx + (o)))
#define H(o) (*(u16 *)(ctx + (o)))
#define B(o) (*(u8 *)(ctx + (o)))

void func_021BD1AC(char *ctx)
{
    Params prm;
    u8 i;
    u8 j;

    B(0x18) = 1;
    B(0x19) = 0;
    F(0x1c) = 0;
    func_021BD5D8(ctx);
    func_021BD844(ctx);
    func_021BDBC4((u8 *)ctx);
    F(0x1d4) = (u32)func_02027F60(4, 7, F(0x1c8), F(0x1d0), H(0));
    F(0x1e0) = (u32)func_021B6EE0(ctx, H(0));
    F(0x1e4) = (u32)func_021B7BA8(ctx, H(0));
    F(0x1e8) = (u32)func_021B8C3C(ctx, H(0));
    F(0x1ec) = (u32)func_021BA280(ctx, H(0));
    F(0x1f0) = (u32)func_021BBA6C(ctx, H(0));
    prm.heap = H(0);
    prm.kind = 2;
    prm.count = 0x64;
    prm.a = 0;
    prm.b = 0x100;
    prm.c = 0;
    prm.d = 0xc0;
    F(0x1f4) = (u32)func_021B6BE0(&prm);
    F(4) = (u32)func_020056A0(func_021BD5AC, ctx, 8);
    F(8) = 0;
    H(0x38) = 0;
    H(0x3a) = 0;
    F(0x10) = 1;
    F(0x20) = 0;
    F(0x24) = 0;
    F(0x28) = 0;
    F(0x2c) = 0;
    F(0x30) = 0;
    F(0x34) = 0;
    if (func_0202EB14() == 1) {
        F(0x30) = 1;
    }
    func_0203D34C(0, H(0));
    switch (*(u32 *)(F(0x1f8) + 4)) {
    case 0:
        func_021B80DC(ctx, F(0x1e4), 3);
        F(0xc) = 1;
        break;
    case 1:
        func_021B80DC(ctx, F(0x1e4), 2);
        F(0xc) = 2;
        break;
    case 2:
        func_021B80DC(ctx, F(0x1e4), 4);
        func_021B80EC(ctx, F(0x1e4), F(0x1f8) + 8);
        F(0xc) = 2;
        func_02012A30(*(u32 *)F(0x1f8));
        func_02028A70();
        break;
    case 3:
        func_021B80DC(ctx, F(0x1e4), 5);
        F(0xc) = 2;
        break;
    }
    F(0x1b8) = sub_020450F0(0, 2, 0xa, 0xc, 2, 0xa, 1);
    F(0x1bc) = sub_020450F0(0, 0x12, 0xa, 0xc, 2, 0xa, 1);
    F(0x1c0) = sub_020450F0(0, 2, 0x16, 0xc, 2, 0xa, 1);
    F(0x1c4) = sub_020450F0(0, 0x12, 0x16, 0xc, 2, 0xa, 1);
    i = 0;
    do {
        j = i;
        sub_02043B5C(func_02045770(*(u32 *)(ctx + i * 4 + 0x1b8)), j);
        i = i + 1;
    } while (i < 4);
    B(0x1b4) = j;
    B(0x1b5) = j;
    func_02005D90(0x3e9, 0xffff);
}
