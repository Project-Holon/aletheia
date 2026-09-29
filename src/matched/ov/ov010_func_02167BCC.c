/*
 * function: func_02167BCC
 * address:  0x02167BCC
 * packet:   pkt_ov010_02167BCC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 func_02167BFC.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[9];
    u8 b09;
    u8 pad0a[0x668 - 0x0A];
    u32 w668;
} Obj;

void func_02167BCC(Obj *o)
{
    o->w668 = o->b09;
}
