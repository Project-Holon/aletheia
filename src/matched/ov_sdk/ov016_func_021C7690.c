/*
 * function: isOver
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
 *   MI_CpuCopy8  0x02082D44  arm
 *   atoi  0x020964E0  arm
 *   gMemSsea     0x021DE5E4  data
 */

typedef struct MemSsea {
    unsigned char pad0[8];
    unsigned char text[4][3];
    unsigned char pos;
} MemSsea;

extern void MI_CpuCopy8();
typedef unsigned int   u32;
extern int atoi(u32 a0);
extern MemSsea *gMemSsea;

int isOver(int val)
{
    unsigned char *c;
    unsigned char buf[4];
    int v;
    int i;

    c = gMemSsea->text[gMemSsea->pos];
    if (*c != 0 && *c != ' ')
        return 1;
    MI_CpuCopy8(c, buf, 3);
    buf[3] = 0;
    for (i = 0; i < 3; i++) {
        if (buf[i] != 0)
            break;
        buf[i] = ' ';
    }
    v = atoi((u32)buf);
    return v >= val;
}
