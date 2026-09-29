/*
 * function: func_021F3950
 * address:  0x021F3950
 * packet:   pkt_ov060_021F3950
 * region:   ov060
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char u8;

extern void func_021BE4B4(void *p, int i, int j, int v);
extern void func_021BE700(void *p, int i, int j, u16 k, int flag);
extern u8 *func_021BE674(void *p, int i, int j, u16 k);
extern void func_021BE6B8(u8 *p, int v);
extern void func_021BE6B0(u8 *p, int v);

void func_021F3950(void *unused, void *p)
{
    int i;
    u8 *e;

    func_021BE4B4(p, 0, 0x14, 1);
    for (i = 0; i < 3; i++) {
        func_021BE700(p, 0, 0x14, (u16)i, 1);
        e = func_021BE674(p, 0, 0x14, (u16)i);
        func_021BE6B8(e, 0);
        func_021BE6B0(e, 0);
    }
}
