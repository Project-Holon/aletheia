/*
 * function: func_021638AC
 * address:  0x021638AC
 * packet:   pkt_021638AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 28 compiled 26
 *
 * symbols:
 *   func_021AB3EC  0x021AB3EC  thumb
 *   func_021C8F7C  0x021C8F7C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB3EC();
extern int func_021C8F7C();

int func_021638AC(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(u16 *)((char *)t4 + 0xa);
    a0 = func_021AB3EC(a0);
loc_021638B8:
    if (a0 != 1) goto loc_021638C4;
loc_021638BC:
a1 = *(int *)((char *)t4 + 0x14);
a0 = t5 + 0;
    a0 = func_021C8F7C(a0, a1);
loc_021638C4:
    return a0;}
