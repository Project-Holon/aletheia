/*
 * function: func_021DCEC4
 * address:  0x021DCEC4
 * packet:   pkt_ov093_021DCEC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D58A8  0x021D58A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6F0C  0x021D6F0C  thumb  ov093
 *   d_021F1EA4     0x021F1EA4  data  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u32 func_021D58A8(void *p, int k);
extern u8 func_021D5440(void *p);
extern void *func_021D6F0C(int id, u32 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);

struct Ent { u32 key; u32 (*fn)(u32 *); };
extern struct Ent d_021F1EA4[0xac];

void *func_021DCEC4(void *a, u32 k)
{
    u32 i;
    u16 t;
    u8 sub;
    u32 f8;
    u32 loc;

    for (i = 0; i < 0xac; i++) {
        if (k == d_021F1EA4[i].key) {
            t = func_021D58A8(a, 0xc);
            sub = func_021D5440(a);
            f8 = d_021F1EA4[i].fn(&loc);
            return func_021D6F0C(5, k, 6, t, sub, f8, loc);
        }
    }
    return 0;
}
