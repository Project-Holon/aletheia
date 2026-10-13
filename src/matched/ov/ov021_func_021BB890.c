/*
 * function: FIELD_SUBPROC_MGR_Create
 * address:  0x021BB890
 * packet:   pkt_ov021_021BB890
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   d_021DE2F8     0x021DE2F8  data  a4
 */

extern int d_021DE2F8;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
typedef unsigned int   u32;
u32 func_02030CB0(u32 idx);
struct Ctx;
struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);

int *FIELD_SUBPROC_MGR_Create(int a, int b, int n)
{
    int *p = func_02030734(b, 0x18, 1, (const char *)&d_021DE2F8, 0x46);
    int sz;

    p[0] = a;
    p[1] = b;
    p[2] = n;
    p[3] = (int)func_02030734(b, 0x18 * n, 1, (const char *)&d_021DE2F8, 0x4a);
    sz = func_02030CB0(n);
    p[5] = (int)func_02030734(b, sz, 1, (const char *)&d_021DE2F8, 0x56);
    p[5] = (int)func_02030CBC(n, (struct Ctx *)p[5]);
    p[4] = (int)func_02030734(b, sz, 1, (const char *)&d_021DE2F8, 0x59);
    p[4] = (int)func_02030CBC(n, (struct Ctx *)p[4]);
    return p;
}
