/*
 * function: func_021C7690
 * address:  0x021C7690
 * packet:   pkt_ov016_021C7690
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      isOver (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   func_020964E0  0x020964E0  arm
 *   g_021DE5E4     0x021DE5E4  data
 */

typedef struct MemSsea {
    unsigned char pad0[8];
    unsigned char text[4][3];
    unsigned char pos;
} MemSsea;

extern void func_02082D44();
extern int func_020964E0();
extern MemSsea *g_021DE5E4;

int func_021C7690(int val)
{
    unsigned char *c;
    unsigned char buf[4];
    int v;
    int i;

    c = g_021DE5E4->text[g_021DE5E4->pos];
    if (*c != 0 && *c != ' ')
        return 1;
    func_02082D44(c, buf, 3);
    buf[3] = 0;
    for (i = 0; i < 3; i++) {
        if (buf[i] != 0)
            break;
        buf[i] = ' ';
    }
    v = func_020964E0(buf);
    return v >= val;
}
