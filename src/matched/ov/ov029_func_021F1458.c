/*
 * function: func_021F1458
 * address:  0x021F1458
 * packet:   pkt_ov029_021F1458
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x230 table must be a struct member (u16 [3][5]); a raw cast keeps
 * p + 0x230 in ip and spills the source pointer instead. `n` is declared
 * before `r` so the counter lands at [sp,#0x20] and the handle at [sp,#0x1c].
 *
 * symbols:
 *   func_021F1458  0x021F1458  thumb  ov029
 *   func_02049F78  0x02049F78  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E468  0x0207E468  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021F09B4  0x021F09B4  thumb  ov029
 *   func_0203FA08  0x0203FA08  arm
 *   func_02049658  0x02049658  arm
 *   func_02049990  0x02049990  arm
 *   d_021F31E0     0x021F31E0  data  a4
 *   d_021F31A8     0x021F31A8  data  ov029  a1
 *   d_021F32E0     0x021F32E0  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct W {
    u8 pad0[0x230];
    u16 unk_230[3][5];
};

extern int func_02049F78(int, int, void *, int);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E468(void *a, u32 b, u32 c);
extern void func_020307B0(int);
extern void func_021F09B4(u8 *p, void *src, int k);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern void func_02049658(int h, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_02049990(int h, int a, int b, int c, u16 d, int e, int f, int g);
extern const int d_021F31E0[];
extern const u8 d_021F31A8[];
extern const int d_021F32E0[][3];

void func_021F1458(u8 *p, int a, int b, int c)
{
    int n;
    int r;
    char *loc;
    u8 *src;
    int m;
    int k;
    u32 size;
    u32 v;

    if (c) {
        r = func_02049F78(*(int *)(p + 0x24), d_021F31E0[a], &loc, 0x8070);
        func_020862F0(*(void **)(loc + 0xc), *(u32 *)(loc + 8));
        func_0207E468(*(void **)(loc + 0xc), 0, *(u32 *)(loc + 8));
        src = *(u8 **)(loc + 0xc);
        for (n = 0; n < 5; n++) {
            for (m = 0; m < 3; m++) {
                ((struct W *)p)->unk_230[m][n] = ((u16 *)(src + (n + 1) * 0x20))[d_021F31A8[m]];
            }
        }
        func_020307B0(r);
        r = func_02049F78(*(int *)(p + 0x24), 0x17, &loc, 0x8070);
        for (k = 0; k < 9; k++) {
            func_021F09B4(p, *(void **)(loc + 0xc), k);
        }
        func_020307B0(r);
    }
    size = 0x5000;
    v = func_0203FA08(6, size, 0);
    *(u32 *)(p + 0x14) = (u16)v | (size << 16);
    func_02049658(*(int *)(p + 0x24), d_021F32E0[b][a], 6, v, 0, 0, 0x70);
    func_02049990(*(int *)(p + 0x24), 2, 6, 0, (u16)*(u32 *)(p + 0x14), 0, 0, 0x70);
}
