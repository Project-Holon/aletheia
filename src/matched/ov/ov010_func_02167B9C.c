/*
 * function: func_02167B9C
 * address:  0x02167B9C
 * packet:   pkt_ov010_02167B9C
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
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef struct Obj {
    u8 pad00[0x32];
    u8 b32[0x668 - 0x32];
    u8 b668[0x1C];
} Obj;

extern void func_02082D44(void *dst, void *src, int n);

void func_02167B9C(Obj *o)
{
    func_02082D44(o->b32, o->b668, 0x1C);
}
