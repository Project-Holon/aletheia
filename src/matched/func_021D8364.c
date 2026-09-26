/*
 * function: func_021D8364
 * address:  0x021D8364
 * packet:   pkt_021D8364
 * region:   ov116
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021D83F0  0x021D83F0  data
 *   func_020403F4  0x020403F4  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02082BCC  0x02082BCC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 g_021D83F0[];

void func_020403F4(int x);
void func_020450C8(void);
void func_0203F9B4(void);
void func_02082BCC(void *dst, int c, int n);

void func_021D8364(void *a0)
{
    unsigned int i;

    for (i = 0; i < 8; i++) {
        func_020403F4((u8)*(u32 *)(g_021D83F0 + i * 0x2c));
    }
    func_020450C8();
    func_0203F9B4();
    func_02082BCC(a0, 0, 4);
}
