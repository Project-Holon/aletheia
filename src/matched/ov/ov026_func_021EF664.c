/*
 * function: func_021EF664
 * address:  0x021EF664
 * packet:   pkt_ov026_021EF664
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 12-byte-stride tables index as a struct array: `muls` by the
 * 0xC already live as the p[6] load offset. An int[i * 3] subscript
 * costs a shift/add pair and four bytes.
 *
 * symbols:
 *   func_021EF664  0x021EF664  thumb  ov026
 *   func_021EF920  0x021EF920  thumb  ov026
 *   func_021EF950  0x021EF950  thumb  ov026
 *   func_021EF614  0x021EF614  thumb  ov026
 *   func_020056EC  0x020056EC  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A2170  0x021A2170  thumb  ov021
 *   func_021A2180  0x021A2180  thumb  ov021
 *   d_021EFD74     0x021EFD74  data  ov026  a4
 *   d_021EFD78     0x021EFD78  data  ov026  a4
 *   d_021EFD3C     0x021EFD3C  data  ov026  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
typedef unsigned char  u8;
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern void func_021A2170(unsigned char *o, unsigned int v, int i);
extern void func_021A2180(unsigned char *o, unsigned int v, int i);
extern void func_021EF920(u8 *a, s16 *p, int b, int c);
extern void func_021EF950(int, s16 *, int);
extern void func_021EF614(int, u16 *, int, int);
typedef struct {
    int a;
    int b;
    int c;
} T3;

extern T3 d_021EFD74[];
extern T3 d_021EFD78[];
extern int d_021EFD3C[];

void func_021EF664(int a, s16 *p, int b, int d)
{
    u32 r;
    int i;

    switch (p[8]) {
    case 0:
        break;
    case 1:
        p[6] = p[6] + 1;
        func_021EF920((u8 *)a, p, b, 0x71F);
        if (p[6] >= p[7]) {
            p[8] = 3;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                func_021A232C((u8 *)a, 9, 0x7F70, 10, b);
                func_021A25BC((unsigned char *)a, 0x720);
            }
        }
        break;
    case 2:
        p[6] = p[6] + 1;
        func_021EF920((u8 *)a, p, b, 0x71F);
        func_021EF950(a, p, b);
        if (p[6] >= p[7]) {
            p[8] = 4;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                func_021A2160((unsigned char *)a, 0, 1);
                func_021A2170((unsigned char *)a, 0x1000, 0);
                func_021A2180((unsigned char *)a, 0x1000, 0);
            }
        }
        break;
    case 3:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            r = func_020056EC(0);
            p[8] = 2;
            p[7] = r % 400 + 0x3C;
            p[6] = 0;
            if (d == 0) {
                func_021A2160((unsigned char *)a, 1, 1);
                func_021A2170((unsigned char *)a, 0x800, 0);
                func_021A2180((unsigned char *)a, 0x1800, 0);
            }
        }
        break;
    case 4:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            func_021EF614(a, (u16 *)p, b, d);
        }
        break;
    }
    switch (p[8]) {
    case 0:
        break;
    case 1:
        if (p[7] - p[6] >= 9) {
            p[11] = 0;
            p[12] = 0;
        } else {
            p[11] = 0xA0;
            p[12] = 0x10;
        }
        break;
    case 2:
        i = p[6] % 0x48 * 6 / 0x48;
        p[11] = d_021EFD74[i].a;
        p[12] = d_021EFD78[i].a;
        *(int *)(p + 14) = d_021EFD3C[(p[6] % 0xE0u) * 14 / 0xE0u];
        break;
    case 3:
    case 4:
        p[11] = 0xA0;
        p[12] = 0x10;
        *(int *)(p + 14) = 0x800;
        break;
    }
}
