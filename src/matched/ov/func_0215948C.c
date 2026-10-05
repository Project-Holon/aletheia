/*
 * function: func_0215948C
 * address:  0x0215948C
 * packet:   pkt_0215948C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011398  0x02011398  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_0201137C  0x0201137C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ring;
extern u32 func_02011398(struct Ring *r);
extern int func_0209C2B0();
extern int func_0201137C();

int func_0215948C(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_02159494:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02011398((struct Ring *)a0);
loc_0215949C:
a1 = t4 + 0;
    a0 = func_0209C2B0(a0, a1);
loc_021594A2:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0201137C(a0, a1);
loc_021594AA:
a0 = 0;
    return a0;}
