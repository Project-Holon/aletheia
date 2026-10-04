/*
 * function: func_021D4F60
 * address:  0x021D4F60
 * packet:   pkt_021D4F60
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021D6D8C  0x021D6D8C  arm
 *   func_021D546C  0x021D546C  arm
 *   g_021DE670     0x021DE670  data
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_021D6D8C(void *p);
extern void func_021D546C(void *queue, void *data);
extern u8  *g_021DE670;

void func_021D4F60(u8 *p)
{
    u32 *q;
    int i;
    int sel = 0;
    u8 *base;

    q = *(u32 **)(p + 8);
    for (i = 0; i < p[0xc]; i++) {
        *q = (*q & 0xC1FFFCFF) | 0x200;
        q += 2;
    }
    func_021D6D8C(p);
    base = g_021DE670;
    if (p >= base + 0x228)
        sel = 1;
    func_021D546C((void *)(*(u32 *)(base + sel * 0x228 + 0x224)), p);
}
