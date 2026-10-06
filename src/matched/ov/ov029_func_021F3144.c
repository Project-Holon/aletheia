/*
 * function: func_021F3144
 * address:  0x021F3144
 * packet:   pkt_ov029_021F3144
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_021F2CF4  0x021F2CF4  thumb
 *   func_021F2D10  0x021F2D10  thumb
 *   func_021F2CD8  0x021F2CD8  thumb
 *   func_021F2D30  0x021F2D30  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0203CD98(void);
extern void func_021F2CF4(u8 *);
extern void func_021F2D10(u8 *);
extern void func_021F2CD8(char *p);
extern void func_021F2D30(u8 *);

void func_021F3144(u8 *p, int v)
{
    if (func_0203CD98() == 0 && p[0x45A] != 0)
        func_021F2CF4(p);
    else
        func_021F2D10(p);
    if (p[0x454] != v) {
        if (v == 0)
            func_021F2CD8((char *)p);
        else
            func_021F2D30(p);
        p[0x454] = v;
    }
}
