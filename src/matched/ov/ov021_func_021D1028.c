/*
 * function: func_021D1028
 * address:  0x021D1028
 * packet:   pkt_ov021_021D1028
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
struct Big;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E8F8(void *sys);

int func_021D1028(const struct Ctx *a0)
{
    u8 *p = func_0200E8F8(func_02012EBC((struct Big *)func_020120F4(a0)));

    if (p[0] != 0) {
        if (p[0x14] != 0) {
            return 3;
        }
        return 1;
    }
    if (p[0x14] != 0) {
        return 2;
    }
    return 0;
}
