/*
 * function: func_0215B660
 * address:  0x0215B660
 * packet:   pkt_0215B660
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02159AE8();
extern int func_02159B10();
extern int func_0215B4AC();
extern int func_02017E1C();

int func_0215B660(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t4;
    int t5;
    int t6;
t6 = a0 + 0;
t5 = a1 + 0;
    a0 = func_02159AE8(a0, a1);
loc_0215B66C:
t4 = a0 + 0;
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215B676:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*(u16 *)((char *)t4) = t6;
    a0 = func_0215B4AC(a0, a1, a2);
loc_0215B684:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B688:
    a0 = *(int *)(fr + 0);
a1 = 0xa0;
a2 = t6 + 0;
    a0 = func_02017E1C(a0, a1, a2);
loc_0215B692:
a0 = a0 << 0x10;
t5 = (unsigned)a0 >> 0x10;
    a0 = *(int *)(fr + 0);
a1 = 0xa1;
a2 = t6 + 0;
    a0 = func_02017E1C(a0, a1, a2);
loc_0215B6A0:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    if (t5 == a0) goto loc_0215B6B6;
loc_0215B6A8:
    a0 = *(int *)(fr + 0);
a1 = 0x4c;
a2 = t6 + 0;
    a0 = func_02017E1C(a0, a1, a2);
loc_0215B6B2:
    if (a0 != 1) goto loc_0215B6BA;
loc_0215B6B6:
a0 = 1;
*(u16 *)((char *)t4) = a0;
loc_0215B6BA:
a0 = 0;
    return a0;
}
