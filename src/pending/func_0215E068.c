/*
 * function: func_0215E068
 * address:  0x0215E068
 * packet:   pkt_0215E068
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 72 compiled 70
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_021FCE00  0x021FCE00  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5E4();
extern int func_02012F80();
extern int func_02156BAC();
extern int func_02156BCC();
extern int func_021FCE00();

int func_0215E068(int a0, int a1)
{
    int t4;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0215E072:
a0 = t4 + 0;
    a0 = func_0215A5E4(a0);
loc_0215E078:
    a0 = func_02012F80();
loc_0215E07C:
t4 = a0 + 0;
a0 = *(int *)((char *)t4);
    if (a0 == 0) goto loc_0215E096;
loc_0215E084:
    a0 = func_02156BAC();
loc_0215E088:
a0 = *(int *)((char *)t4);
    a0 = func_02156BCC(a0);
loc_0215E08E:
    if (a0 != 1) goto loc_0215E096;
loc_0215E092:
a0 = 1;
    return a0;
loc_0215E096:
a1 = *(u16 *)((char *)t4 + 0x34);
a0 = *(int *)((char *)t4 + 4);
a1 = a1 << 0x18;
a1 = (unsigned)a1 >> 0x18;
    a0 = func_021FCE00(a0, a1);
loc_0215E0A2:
    if (a0 != 1) goto loc_0215E0AA;
loc_0215E0A6:
a0 = 1;
    return a0;
loc_0215E0AA:
a0 = 0;
    return a0;}
