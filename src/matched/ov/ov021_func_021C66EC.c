/*
 * function: func_021C66EC
 * address:  0x021C66EC
 * packet:   pkt_ov021_021C66EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047910  0x02047910  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 k : 2; } K;

extern int func_02047910(u32 h, u16 i, int v);

int func_021C66EC(u32 *a, int idx, int v)
{
    int r = 0;
    u8 *e = (u8 *)a[3] + idx * 0x68;
    int n, i;

    if (((K *)e)->k == 1) {
        n = *(u8 *)((u8 *)a[2] + *(u16 *)(e + 4) * 0x2c + 0x28);
        for (i = r; i < n; i++) {
            if (func_02047910(*(u32 *)(e + 0x44), i, v))
                r = 1;
        }
    } else if (((K *)e)->k == 2) {
        r = 1;
    }
    return r;
}
