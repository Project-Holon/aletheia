/*
 * function: func_021A511C
 * address:  0x021A511C
 * packet:   pkt_ov021_021A511C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0216D5F8(void *p);
int func_02197E7C(int k, int a);
void func_0216D410(int b, int v);
void func_021A3964(u8 *p, u32 v);

void func_020061E4(u32 a);

void func_021A511C(u32 *p, int b, u8 *c)
{
    func_0216D410(b, func_02197E7C(*(u16 *)(c + 8), 0x38));
    p[0] = 1;
    func_021A3964((u8 *)p[3], 1);
    func_020061E4(0x55E);
}
