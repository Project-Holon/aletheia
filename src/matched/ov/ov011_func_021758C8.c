/*
 * function: func_021758C8
 * address:  0x021758C8
 * packet:   pkt_ov011_021758C8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175894  0x02175894  thumb  ov011
 *   func_021758B4  0x021758B4  thumb  ov011
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Flags {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags;

extern int func_02175B14(u8 *p);
extern int func_02175894(u8 *p);
extern int func_021758B4(u8 *p);

int func_021758C8(u8 *o)
{
    int h;
    int v;

    if (func_02175B14(o) == 1 && o[0xd8] == 4) {
        h = *(u16 *)(o + 0xa8);
        if (h != 0 || ((Flags *)(o + 0x1a5))->f == 0) {
            v = h - func_02175894(o);
        } else {
            v = func_021758B4(o);
        }
        if (v < 0) {
            return 0;
        }
        return v;
    }
    return 0;
}
