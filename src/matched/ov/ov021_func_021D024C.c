/*
 * function: func_021D024C
 * address:  0x021D024C
 * packet:   pkt_ov021_021D024C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Highlights button sel of four and records it.
 *
 * symbols:
 *   func_021AC1E0  0x021AC1E0  thumb
 *   func_02047804  0x02047804  arm
 *   func_020477A4  0x020477A4  arm
 *   func_020477D4  0x020477D4  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021AC1E0(u32 a);
extern void func_02047804(u32 h, u16 i);
extern void func_020477A4(u32 h, u16 i);
extern void func_020477D4(u32 h, u16 i);

void func_021D024C(void *obj, int sel)
{
    int i;
    u8 *q;

    if (obj == 0)
        return;
    q = (u8 *)func_021AC1E0((u32)obj);
    for (i = 0; i < 4; i++) {
        func_02047804(*(u32 *)(q + 0xc), i);
        if (i == sel)
            func_020477A4(*(u32 *)(q + 0xc), i);
        else
            func_020477D4(*(u32 *)(q + 0xc), i);
    }
    q[2] = sel;
    q[3] = 0;
}
