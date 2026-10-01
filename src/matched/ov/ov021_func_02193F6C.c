/*
 * function: func_02193F6C
 * address:  0x02193F6C
 * packet:   pkt_ov021_02193F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x4E];
} E50;

extern void func_02082BCC(void *p, int v, int n);

void func_02193F6C(E50 *e)
{
    func_02082BCC(e, 0, 0x50);
    e->f00 = 0;
}
