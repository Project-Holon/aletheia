/*
 * function: func_02191978
 * address:  0x02191978
 * packet:   pkt_ov021_02191978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: original stores 0, reloads the slot, stores 0 again, then calls func_0219194C with the reloaded value, recomputing the slot address each time; the literal C below folds the reload away (34 vs 52 bytes).
 *
 * symbols:
 *   func_0219194C  0x0219194C  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern void func_0219194C(u32 a);

void func_02191978(u8 *p)
{
    int i;
    u32 t;

    for (i = 0; i < 8; i++) {
        if (((u32 *)(p + 0xA0))[i] != 0) {
            ((u32 *)(p + 0xA0))[i] = 0;
            t = ((u32 *)(p + 0xA0))[i];
            ((u32 *)(p + 0xA0))[i] = 0;
            func_0219194C(t);
        }
    }
}
