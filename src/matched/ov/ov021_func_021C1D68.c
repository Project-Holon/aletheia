/*
 * function: func_021C1D68
 * address:  0x021C1D68
 * packet:   pkt_ov021_021C1D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017EAC  0x02017EAC  thumb
 *   func_021C1D18  0x021C1D18  thumb  ov021
 */

typedef unsigned int u32;

struct Ctx;
void *func_020120F4(const struct Ctx *p);
struct BigObj;
void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
u32 func_02017E1C(void *p, u32 id, u32 v);
u32 func_02017EAC(void *p);
int func_021C1D18(int a, char *b, int c, int d, int e, int f, int g);

int func_021C1D68(int a, int b, int c)
{
    int p;
    int x5;
    int x6f;
    int x6e;
    int xe;
    int x4c;

    p = (int)func_0201AB28(func_02012934(func_020120F4((const struct Ctx *)a)), c);
    x5 = func_02017E1C((void *)p, 5, 0);
    x6f = func_02017E1C((void *)p, 0x6f, 0);
    x6e = func_02017E1C((void *)p, 0x6e, 0);
    xe = func_02017EAC((void *)p);
    x4c = func_02017E1C((void *)p, 0x4c, 0);
    return func_021C1D18(a, (char *)b, x5, x6f, x6e, xe, x4c);
}
