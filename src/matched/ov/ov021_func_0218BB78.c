/*
 * function: func_0218BB78
 * address:  0x0218BB78
 * packet:   pkt_ov021_0218BB78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0218B924  0x0218B924  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *p, int v, int n);
extern u16 *func_0218B924(void *s, int i);

void func_0218BB78(u8 *s, int k)
{
    u8 i;
    u8 v;
    int j;

    func_02082BCC(s + 0x1c, 0x80, 0x190);
    for (i = 0; i < *(u16 *)(s + 0x1ac); i++)
        s[*func_0218B924(s, i) + 0x1c] = i;
    v = (s + k)[0x1c];
    for (j = 0; j < 0x190; j++) {
        if (s[j + 0x1c] == 0x80)
            s[j + 0x1c] = v;
    }
}
