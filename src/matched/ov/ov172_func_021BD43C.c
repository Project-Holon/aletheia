/*
 * function: func_021BD43C
 * address:  0x021BD43C
 * packet:   pkt_ov172_021BD43C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-02: byte-correct. Blocker: func_021B80CC (a 64-byte thumb getter-style
 * function, show prints it as ARM) has no label/start in ov172's layout (only ov105
 * has the label), so its 2 bl sites stay unresolved. Layout gap = figure move,
 * not edited; referencing sites +0056 and +0078 here.
 *
 * symbols:
 *   func_021B7E34  0x021B7E34  thumb  ov172
 *   func_021B9044  0x021B9044  thumb  ov172
 *   func_021BBF2C  0x021BBF2C  thumb  ov172
 *   func_021BA9EC  0x021BA9EC  thumb  ov172
 *   func_021B80CC  0x021B80CC  thumb
 *   _fflt          0x0209BDBC  arm
 *   _fdiv          0x0209CE10  arm
 *   _ffixu         0x0209C4C8  arm
 *   func_021BDD6C  0x021BDD6C  thumb  ov172
 *   func_021B6C48  0x021B6C48  thumb  ov172
 *   func_021B712C  0x021B712C  thumb  ov172
 *   func_021B7590  0x021B7590  thumb  ov172
 *   func_021BDCB8  0x021BDCB8  thumb  ov172
 *   func_02061CA4  0x02061CA4  arm
 *   g_020A1B38     0x020A1B38  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct PrintSys;
struct Tcbl;
extern void func_021B7E34(void *p, char *q);
struct S;
extern u32 func_021B9044(void *p, struct S *s);
extern int func_021BBF2C(void *a0, char *p);
extern int func_021BA9EC(void *a0, char *p);
extern u32 func_021B80CC(int unused, char *p);
extern void func_021BDD6C(u8 *p);
extern void func_021B6C48(u32 a);
extern void func_021B712C(int unused, char *q);
extern int func_021B7590(int x, char *p);
extern void func_021BDCB8(u8 *p);
extern u32  func_020221A4(void);
extern void func_0204A600(void);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_020310C4(struct Tcbl *p);
extern u32  func_02005728(u32 v);
extern void sub_02040618(u32 layer, u32 a, u32 b);
extern s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size);
extern s16 g_020A1B38[];

#define F(o) (*(u32 *)(ctx + (o)))
#define H(o) (*(u16 *)(ctx + (o)))

int func_021BD43C(char *ctx)
{
    u32 idx;
    s32 v;
    u8 pal;

    func_021B7E34(ctx, (char *)F(0x1e4));
    switch (F(8)) {
    case 1:
        F(0xc) = func_021B9044(ctx, (struct S *)F(0x1e8));
        break;
    case 2:
        F(0xc) = func_021BBF2C(ctx, (char *)F(0x1f0));
        break;
    case 3:
        F(0xc) = func_021BA9EC(ctx, (char *)F(0x1ec));
        break;
    case 4:
        if (func_021B80CC((int)ctx, (char *)F(0x1e4)) == 1 && func_021B7590((int)ctx, (char *)F(0x1e0)) == 1) {
            return 1;
        }
        return 0;
    case 5:
        if (func_021B80CC((int)ctx, (char *)F(0x1e4)) == 1 && func_021B7590((int)ctx, (char *)F(0x1e0)) == 1
            && func_020221A4() == 1) {
            return 1;
        }
        break;
    }
    if (F(0x14) == 1 && func_020221A4() == 1) {
        F(0xc) = 5;
    }
    if (F(8) != F(0xc)) {
        func_021BDCB8((u8 *)ctx);
    }
    func_021B712C((int)ctx, (char *)F(0x1e0));
    func_021B6C48(F(0x1f4));
    func_0204A600();
    func_0201C4E4((struct PrintSys *)F(0x1d0));
    func_021BDD6C((u8 *)ctx);
    H(0x38) += 0x200;
    idx = H(0x38) >> 4;
    v = (g_020A1B38[idx * 2] + 0x1000) / 2 * 10;
    pal = (u8)(u32)((float)v / 4096.0f);
    if (pal >= 10) {
        pal = 9;
    }
    if (pal != H(0x3a)) {
        H(0x3a) = pal;
        sub_02061CA4((void *)0x1f, 0x40, (u32)(ctx + 0x3c + pal * 32), 0x20);
    }
    func_020310C4((struct Tcbl *)F(0x1d8));
    sub_02040618(1, 0, func_02005728(0x100));
    sub_02040618(1, 3, func_02005728(0x100));
    return 0;
}
