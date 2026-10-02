/*
 * function: func_021ABD50
 * address:  0x021ABD50
 * packet:   pkt_ov021_021ABD50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013B38  0x02013B38  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   func_021ABEAC  0x021ABEAC  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204EDBC  0x0204EDBC  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_0204EDB0  0x0204EDB0  arm
 *   d_021DE018     0x021DE018  data  a1
 *   d_021D8F04     0x021D8F04  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int x; int y; int z; } V;

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern void *func_020490F4(unsigned int id, u16 heap);
extern int func_02188C9C(int a);
extern int func_02013B38(int a);
extern int func_02188C80(int a);
extern int func_0202E83C(int a);
extern int func_02188D58(int a);
extern int func_020140D8(int a);
extern void func_021ABEAC(char *p);
extern int func_02188C88(int a);
extern int func_02050080(int a);
extern void func_0204EDBC(int a, int b);
extern void func_0204ED70(int a, V *v);
extern void func_0204EDB0(int a, u8 *b);
extern char d_021DE018[];
extern V d_021D8F04;

char *func_021ABD50(int a, int b, u16 c)
{
    char *p;
    int h;
    V v;
    u8 z;

    p = (char *)func_02030734(c, 0x28, 1, d_021DE018, 0x7e);
    *(int *)p = b;
    *(u16 *)(p + 4) = c;
    *(int *)(p + 8) = a;
    *(int *)(p + 0xc) = (int)func_020490F4(0x4b, c);
    func_02013B38(func_02188C9C(a));
    *(u8 *)(p + 0x16) = func_0202E83C(func_02188C80(a));
    *(u8 *)(p + 0x17) = func_020140D8(func_02188D58(a));
    func_021ABEAC(p);
    h = func_02050080(func_02188C88(*(int *)(p + 8)));
    func_0204EDBC(h, 0);
    v = d_021D8F04;
    func_0204ED70(h, &v);
    z = 0;
    func_0204EDB0(h, &z);
    return p;
}
