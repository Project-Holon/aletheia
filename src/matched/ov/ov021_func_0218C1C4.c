/*
 * function: func_0218C1C4
 * address:  0x0218C1C4
 * packet:   pkt_ov021_0218C1C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-slot state machine step over four slots.
 *
 * symbols:
 *   func_020478B8  0x020478B8  arm
 *   func_0204784C  0x0204784C  arm
 *   func_02047910  0x02047910  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020478B8(u32 h, u16 i, int v);
extern void func_0204784C(u32 h, u16 i, int v);
extern void func_02047910(u32 h, u16 i, int v);

void func_0218C1C4(u32 unused, u32 *st)
{
    int i;

    for (i = 0; i < 4; i++) {
        switch (st[2 + i]) {
        case 0:
        case 2:
            break;
        case 3:
            if (func_020478B8(st[0], i, 0x1000) == 0)
                st[2 + i] = 2;
            break;
        case 4:
            if (func_020478B8(st[0], i, -0x1000) == 0) {
                func_0204784C(st[0], i, 0);
                st[2 + i] = 2;
            }
            break;
        case 1:
            func_02047910(st[0], i, 0x1000);
            break;
        }
    }
}
