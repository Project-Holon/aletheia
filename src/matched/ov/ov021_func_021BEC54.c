/*
 * function: func_021BEC54
 * address:  0x021BEC54
 * packet:   pkt_ov021_021BEC54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BEA6C  0x021BEA6C  thumb  ov021
 *   func_021BF19C  0x021BF19C  thumb  ov021
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Ent;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
int func_021BF19C(u32 p0, int *st, u8 *q);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
Ent *func_020124E8(int h);
int func_021BEA6C(int x);

int func_021BEC54(int a, int b)
{
    int h = (int)func_020122C0((void *)a, 0, func_021BF19C, 0x2c);
    Ent *e = func_020124E8(h);
    e->f0 = a;
    e->f4 = b;
    e->f8 = 5;
    e->fC = func_021BEA6C(5);
    return h;
}
