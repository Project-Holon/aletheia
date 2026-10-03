/*
 * function: func_02192E0C
 * address:  0x02192E0C
 * packet:   pkt_ov021_02192E0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02192FA4  0x02192FA4  thumb  ov021
 *   func_02194670  0x02194670  thumb  ov021
 *   func_02040588  0x02040588  arm
 *   d_021D3EB8     0x021D3EB8  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int w[8]; } B32;
typedef struct { u16 a; int b; int c; u16 d; int e; u8 f; u8 g; } Req;

extern const B32 d_021D3EB8;
extern void func_0203FCA0(int, void *, int);
typedef unsigned int   u32;
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void func_02192FA4(int, int);
extern int func_02194670(void *);
extern void func_02040588(u32 which, u32 enable);

void func_02192E0C(char *p)
{
    B32 tmp;
    Req r;

    *(u16 *)(p + 2) = 1;
    tmp = d_021D3EB8;
    func_0203FCA0(*(u16 *)(p + 2) & 0xff, &tmp, 0);
    func_02040C14(*(u16 *)(p + 2), 0, 1, 0);
    func_02041300(*(u16 *)(p + 2) & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(*(u16 *)(p + 2) & 0xff);
    func_02192FA4(*(u16 *)(p + 2), *(u16 *)p);
    if (*(int *)(p + 0x168) != 0) {
        r.a = *(u16 *)p;
        r.b = *(int *)(p + 0x168);
        r.c = *(int *)(p + 8);
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        *(int *)(p + 0x15c) = func_02194670(&r);
    }
    func_02040588(*(u16 *)(p + 2) & 0xff, 1);
    *(u16 *)(p + 6) = 0xe;
}
