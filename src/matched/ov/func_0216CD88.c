/*
 * function: func_0216CD88
 * address:  0x0216CD88
 * packet:   pkt_0216CD88
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 48 compiled 46
 *
 * symbols:
 *   func_0219C630  0x0219C630  thumb
 *   func_0216CD64  0x0216CD64  thumb  ov010
 *   func_02087A3C  0x02087A3C  arm
 *   func_0216CD78  0x0216CD78  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0219C630();
extern int func_0216CD64(int a0);
extern int func_02087A3C();
extern int func_0216CD78();

int func_0216CD88(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_0219C630(a0);
loc_0216CD90:
    if (a0 != 1) goto loc_0216CDB4;
loc_0216CD94:
t4 = 1;
loc_0216CD96:
a0 = t5 + 0;
    a0 = func_0216CD64(a0);
loc_0216CD9C:
a0 = t4 + 0;
a1 = t4 + 0;
    a0 = func_02087A3C(a0, a1);
loc_0216CDA4:
a0 = t5 + 0;
    a0 = func_0216CD78(a0);
loc_0216CDAA:
a0 = t5 + 0;
    a0 = func_0219C630(a0);
loc_0216CDB0:
    if (a0 == 1) goto loc_0216CD96;
loc_0216CDB4:
    return a0;}
