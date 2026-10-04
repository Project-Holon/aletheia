/*
 * function: func_021A4140
 * address:  0x021A4140
 * packet:   pkt_ov021_021A4140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDECC     0x021DDECC  data  ov021  a4
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A5354  0x021A5354  thumb  ov021
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 d_021DDECC[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021A395C(u8 *p);
extern void func_021A5354(u32 a);
extern int func_021A3974(u32);
extern int func_021A3CB0(u32, u32);
extern void func_021A3CE8(u32);

u32 *func_021A4140(u32 a, u32 b)
{
    u32 *o;
    int k;

    o = func_02030734(b, 0x20, 1, (const char *)d_021DDECC, 0x17D);
    o[3] = a;
    o[4] = func_021A395C((u8 *)a);
    *(u16 *)(o + 6) = 0x546;
    func_021A5354((u32)o);
    k = func_021A3974(o[3]);
    switch (k) {
    case 2:
        func_021A3CB0(o[3], 4);
        func_021A3CE8(o[3]);
        break;
    case 3:
        func_021A3CB0(o[3], 0x100);
        func_021A3CE8(o[3]);
        break;
    }
    return o;
}
