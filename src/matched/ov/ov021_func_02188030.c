/*
 * function: func_02188030
 * address:  0x02188030
 * packet:   pkt_ov021_02188030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013B38  0x02013B38  thumb
 *   func_0202E83C  0x0202E83C  thumb
 *   func_0201407C  0x0201407C  thumb
 *   func_02189BA8  0x02189BA8  thumb  ov021
 *   d_021DD9C0     0x021DD9C0  data  a4
 */

typedef unsigned short u16;

extern int d_021DD9C0;

void *func_02030734(int a, int b, int c, void *d, int e);
int func_020120F4(int x);
struct Ctx;
unsigned char *func_020120F8(const struct Ctx *p);
struct Rec44;
unsigned short func_02012AC8(const struct Rec44 *p);
typedef unsigned int   u32;
u32 func_02013B38(u32 id);
int func_0202E83C(int x);
int func_0201407C(int a, int b, int c);
int func_02189BA8(int x);

void *func_02188030(int a, int b)
{
    char *p = (char *)func_02030734(b, 0x154, 1, &d_021DD9C0, 0x209);

    *(u16 *)p = b;
    *(int *)(p + 0xc0) = 0;
    *(int *)(p + 4) = a;
    *(int *)(p + 8) = func_020120F4(a);
    *(u16 *)(p + 0xd0) = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)a));
    {
        int r7 = func_02013B38(*(u16 *)(p + 0xd0));
        *(int *)(p + 0xc) = func_0201407C(b, r7, func_0202E83C(a));
    }
    *(int *)(p + 0x108) = func_02189BA8(*(u16 *)(p + 0xd0));
    return p;
}
