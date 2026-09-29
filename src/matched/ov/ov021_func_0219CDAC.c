/*
 * function: func_0219CDAC
 * address:  0x0219CDAC
 * packet:   pkt_ov021_0219CDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Commits pending 0xC-byte entries through func_0219CE60, then compacts the
 * table so the free (0xFFFF) entries sit at the end.
 *
 * symbols:
 *   func_0219CE60  0x0219CE60  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 a, b, c; } E12;

extern int func_0219CE60(u8 *, u32, u32, u32, u16, u32);

void func_0219CDAC(u8 *o)
{
    u8 *ctx = *(u8 **)(o + 0x1c);
    u32 j = 0;
    u32 k = 0;
    u8 *e = *(u8 **)(ctx + 0xc);
    u8 *base;
    for (; j < *(u16 *)(ctx + 4); j++, e += 0xc) {
        if (*(u16 *)e != 0xFFFF) {
            if (func_0219CE60(o, *(u16 *)e, e[4], e[5], *(u16 *)(e + 2), *(u32 *)(e + 8)) == 0)
                break;
            *(u16 *)e = 0xFFFF;
            k++;
            if (k >= *(u16 *)(ctx + 6))
                break;
        }
    }
    if (k != 0) {
        j = 0;
        base = *(u8 **)(ctx + 0xc);
        for (; j < (u32)*(u16 *)(ctx + 4) - 1; j++) {
            E12 *ent = (E12 *)(base + 12 * j);
            if (*(u16 *)ent == 0xFFFF) {
                for (k = j + 1; k < *(u16 *)(ctx + 4); k++) {
                    if (*(u16 *)(base + 12 * k) != 0xFFFF) {
                        *ent = *(E12 *)(base + 12 * k);
                        *(u16 *)(base + 12 * k) = 0xFFFF;
                        break;
                    }
                }
            }
        }
    }
}
