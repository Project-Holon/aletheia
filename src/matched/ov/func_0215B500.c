/*
 * function: func_0215B500
 * address:  0x0215B500
 * packet:   pkt_0215B500
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02017E1C(void *p, u32 id, u32 v);

int func_0215B500(int a0, int a1)
{
    int a2;
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a1 = 0x4c;
a2 = 0;
t5 = a0 + 0;
t6 = 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B510:
    if (a0 == 0) goto loc_0215B518;
loc_0215B514:
a0 = t6 + 0;
    return a0;
loc_0215B518:
a0 = t5 + 0;
a1 = 0x36;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B522:
    if (t4 == a0) goto loc_0215B550;
loc_0215B526:
a0 = t5 + 0;
a1 = 0x37;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B530:
    if (t4 == a0) goto loc_0215B550;
loc_0215B534:
a0 = t5 + 0;
a1 = 0x38;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B53E:
    if (t4 == a0) goto loc_0215B550;
loc_0215B542:
a0 = t5 + 0;
a1 = 0x39;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B54C:
    if (t4 != a0) goto loc_0215B554;
loc_0215B550:
a0 = 1;
    return a0;
loc_0215B554:
a0 = t6 + 0;
    return a0;}
