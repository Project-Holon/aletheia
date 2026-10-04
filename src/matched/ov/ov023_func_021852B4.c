/*
 * function: func_021852B4
 * address:  0x021852B4
 * packet:   pkt_ov023_021852B4
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02186BEC  0x02186BEC  data  a2
 *   func_0204B878  0x0204B878  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Ent {
    u16 a;
    u16 b;
    u16 c;
};

extern struct Ent d_02186BEC[];
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);

void func_021852B4(u32 *p, int n)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (i == n)
            func_0204B878((struct Obj *)p[i], (u16)(d_02186BEC[i].c + 1));
        else
            func_0204B878((struct Obj *)p[i], d_02186BEC[i].c);
    }
}
