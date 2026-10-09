/*
 * function: func_021CC4AC
 * address:  0x021CC4AC
 * packet:   pkt_ov093_021CC4AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021CC4F8  0x021CC4F8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C84AC  0x021C84AC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct QI;
extern u16 func_021D5B40(struct QI *p);
extern int func_021CC4F8(u16 v);
extern u8 func_021D5440(u8 *p);
extern int func_021C84AC(u8 *p, u8 *a, u8 *out);

u8 func_021CC4AC(void *a, void *m)
{
    u8 buf;

    if (func_021CC4F8((u16)(u32)func_021D5B40(m)) == 0) {
        func_021D5440(m);
        if ((u8)func_021C84AC(a, m, &buf) == 0) {
            return buf != 0 ? 2 : 0;
        }
        return 1;
    }
    return 0;
}
