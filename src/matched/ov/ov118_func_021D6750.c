/*
 * function: func_021D6750
 * address:  0x021D6750
 * packet:   pkt_ov118_021D6750
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E3BB0  0x021E3BB0  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D6544  0x021D6544  thumb  ov118
 *   func_021D67D4  0x021D67D4  thumb  ov118
 *   func_021D67F8  0x021D67F8  thumb  ov118
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_021E3BB0(void *p);
extern void func_021E3230(void *p);
extern int func_021D8A24(void *p);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *h, u32 a, u32 b);
extern void func_021D8E84(void *p, int next);
extern void func_021D6544(u8 *p, u8 *outSame, u8 *outFlag, u32 key, int enemy);
extern void func_021D67D4(u8 *p);
extern void func_021D67F8(u8 *p);

void func_021D6750(u8 *p)
{
    func_021E3BB0(p);
    if (*(u32 *)(p + 0x854) == 1) {
        func_021D6544(p, p + 0x11ED, p + 0x11EF, *(u32 *)(p + 0x834), 1);
        func_021D6544(p, p + 0x11EE, p + 0x11F0, *(u32 *)(p + 0x830), 0);
        func_021E3230(p);
        if (func_021D8A24(p) != 0) {
            func_02039C68((struct Link *)func_020399A8(), 0x11, 8);
            func_021D8E84(p, (int)func_021D67D4);
        } else {
            func_021D8E84(p, (int)func_021D67F8);
        }
    }
}
