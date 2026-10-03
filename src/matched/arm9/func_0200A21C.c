/*
 * function: func_0200A21C
 * address:  0x0200A21C
 * packet:   pkt_0200A21C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     closed 2026-09-21 by tools/permuter.py (hill, --types): declaration order i before n,
 *           and the counter n is unsigned (8 bytes)
 *
 * symbols:
 *   func_0203F1FC  0x0203F1FC  arm
 *
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_0203F1FC(const u8 *src, u32 len);

int func_0200A21C(u8 *obj)
{
    int i;
    u32 limit = 0x2d0;
    u32 n = 0;

    do {
        for (i = 0; i < 16; i++) {
            n++;
        }
    } while (n < (int)limit);
    return *(u16 *)(obj + 0x2ce) == func_0203F1FC(obj, 0x2ce);
}
