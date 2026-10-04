/*
 * function: func_02165940
 * address:  0x02165940
 * packet:   pkt_02165940
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sweep the 0x5c-strided record array and hand the first occupied slot to
 * the arm9 helper; the sweep stops at the first empty one.
 *
 * symbols:
 *   func_02026D04   0x02026D04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec;
extern int func_02026D04(const struct Rec *r);

void func_02165940(unsigned char *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        if (p[i * 0x5C] == 0)
            break;
        func_02026D04((const struct Rec *)(p + i * 0x5C));
    }
}

