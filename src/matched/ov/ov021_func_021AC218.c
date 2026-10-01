/*
 * function: func_021AC218
 * address:  0x021AC218
 * packet:   pkt_ov021_021AC218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C88  0x02188C88  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_021AC274  0x021AC274  thumb  ov021
 *   d_021DE028     0x021DE028  data  a1
 *   d_021D908C     0x021D908C  data  a4
 */

typedef struct { int x; int y; int z; } V;

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern int func_021ABE14(int a);
extern int func_02188C88(int a);
extern int func_02050080(int a);
extern void func_021AC274(char *p);
extern char d_021DE028[];
extern V d_021D908C;

char *func_021AC218(int a, int heap)
{
    char *p;

    p = (char *)func_02030734(heap, 0x1c, 1, d_021DE028, 0x5c);
    *(int *)p = a;
    *(V *)(p + 4) = d_021D908C;
    *(int *)(p + 0x10) = func_02188C88(func_021ABE14(a));
    *(int *)(p + 0x14) = func_02050080(*(int *)(p + 0x10));
    func_021AC274(p);
    return p;
}
