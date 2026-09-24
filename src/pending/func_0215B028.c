/*
 * function: func_0215B028
 * address:  0x0215B028
 * packet:   pkt_0215B028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:  
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02008428  0x02008428  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02012EBC();
extern int func_0200873C();
extern int func_02159AE8();
extern int func_02008428();

int func_0215B028(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_0215A5DC(a0);
loc_0215B034:
    a0 = func_020120F4();
loc_0215B038:
    a0 = func_02012EBC();
loc_0215B03C:
    a0 = func_0200873C();
loc_0215B040:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215B04A:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_02008428(a0);
loc_0215B052:
    if (a0 == 0) goto loc_0215B05C;
loc_0215B056:
    if (a0 == 1) goto loc_0215B060;
loc_0215B05A:
    goto loc_0215B064;
loc_0215B05C:
a0 = 0;
    goto loc_0215B062;
loc_0215B060:
a0 = 1;
loc_0215B062:
*(u16 *)((char *)t5) = a0;
loc_0215B064:
a0 = 0;
    return a0;}
