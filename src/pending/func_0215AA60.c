/*
 * function: func_0215AA60
 * address:  0x0215AA60
 * packet:   pkt_0215AA60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  listing 48 compiled 46
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020083E4  0x020083E4  thumb
 *   func_020083EC  0x020083EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02012EBC();
extern int func_0200873C();
extern int func_020083E4();
extern int func_020083EC();

int func_0215AA60(int a0, int a1)
{
    int t4;

a0 = a1 + 0;
    a0 = func_0215A5E4(a0);
loc_0215AA68:
    a0 = func_02012EBC();
loc_0215AA6C:
    a0 = func_0200873C();
loc_0215AA70:
t4 = a0 + 0;
    a0 = func_020083E4();
loc_0215AA76:
a1 = a0 + 0;
    if (a1 != 0) goto loc_0215AA7E;
loc_0215AA7A:
a1 = 1;
    goto loc_0215AA84;
loc_0215AA7E:
    if (a1 != 1) goto loc_0215AA84;
loc_0215AA82:
a1 = 0;
loc_0215AA84:
a0 = t4 + 0;
    a0 = func_020083EC(a0, a1);
loc_0215AA8A:
a0 = 0;
    return a0;}
