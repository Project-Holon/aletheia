/*
 * function: func_021B5B0C
 * address:  0x021B5B0C
 * packet:   pkt_ov021_021B5B0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   g_021EE724     0x021EE724  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Ramp;

extern u16 g_021EE724;
extern void func_020307B0(void *);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_021B5B0C(int a0, Ramp *p)
{
    p->f8++;
    g_021EE724 = (p->f4 * p->f8) / p->fc;
    g_021EE724 = g_021EE724 + (u16)p->f0;
    if (p->f8 >= p->fc) {
        func_020307B0(p);
        func_02030EAC((struct Node *)a0);
    }
}
