/*
 * function: func_0215A514
 * address:  0x0215A514
 * packet:   pkt_ov010_0215A514
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   d_021728E0     0x021728E0  data  ov010  a4
 */

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_02158F54(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
extern int d_021728E0;

void *func_0215A514(int a, int heap)
{
    int *p = (int *)func_02030734(heap, 0x110, 1, (const char *)&d_021728E0, 0x78);

    p[0] = a;
    p[1] = (int)func_02158F54((void *)a);
    p[2] = (int)func_020120F4((const struct Ctx *)p[1]);
    p[3] = func_02012964((const struct BigObj *)p[2]);
    *((char *)p + 0x104) = 7;
    return p;
}
