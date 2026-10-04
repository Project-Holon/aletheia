/*
 * function: func_0218958C
 * address:  0x0218958C
 * packet:   pkt_ov021_0218958C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02188C68  0x02188C68  thumb  ov021
 *   func_021A0358  0x021A0358  thumb  ov021
 *   func_02013EEC  0x02013EEC  thumb
 *   func_02013F2C  0x02013F2C  thumb
 *   func_021A0338  0x021A0338  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 func_02188C68(u8 *p);
void func_021A0358(int a);
int func_02013EEC(unsigned short id);
int func_02013F2C(unsigned short id);
void func_021A0338(u8 *p, u32 id, u32 c, u8 d);

void func_0218958C(unsigned char *p, int id)
{
    int a;
    func_021A0358(func_02188C68(p));
    a = func_02013EEC(id);
    func_021A0338((u8 *)(*(int *)(p + 0x1C)), a, func_02013F2C(id), 1);
}
