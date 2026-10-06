/*
 * function: func_02189560
 * address:  0x02189560
 * packet:   pkt_ov021_02189560
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_0202C83C  0x0202C83C  thumb
 *   func_02012994  0x02012994  thumb
 *   func_021A1BDC  0x021A1BDC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
u32 func_02188C6C(u8 *p);
int func_0202C83C(int a0, int a1);
u8 func_02012994(const struct BigObj *p);
void func_021A1BDC(int x, int k);

void func_02189560(int *p, int b)
{
    int r = (int)func_02188C6C((u8 *)p);
    unsigned short k;
    func_0202C83C(p[1], b);
    k = (int)func_02012994((const struct BigObj *)p[2]);
    if (k != 0xF)
        func_021A1BDC(r, k);
}
