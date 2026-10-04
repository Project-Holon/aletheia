/*
 * function: func_02177E20
 * address:  0x02177E20
 * packet:   pkt_ov014_02177E20
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   func_0203D798  0x0203D798  arm
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021788FC  0x021788FC  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_02177DB0  0x02177DB0  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A4;
void *func_0203D798(void);
int func_02178E4C(void);
int func_021788FC(void);
void func_0217727C(u32 *p, u32 v);
void func_02177DB0(void);
void func_02082D44(void *d, void *s, u32 n);

int func_02177E20(u32 a, u8 *b, u32 c, u32 d)
{
    func_0203D798();
    if (*(u32 *)g_021797A4 != 0)
        return 0;
    if (func_02178E4C() == 2) {
        g_021797A4[0xCE9] = 0;
        func_021788FC();
    }
    func_0217727C((u32 *)g_021797A4, (u32)func_02177DB0);
    if (b != 0)
        func_02082D44(b, g_021797A4 + 0xCDE, 6);
    else
        func_02082D44(g_021797A4 + 0xC + c * 0xC0, g_021797A4 + 0xCDE, 6);
    *(u32 *)(g_021797A4 + 0xC60) = d;
    return 1;
}
