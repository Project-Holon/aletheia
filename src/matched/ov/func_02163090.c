/*
 * function: func_02163090
 * address:  0x02163090
 * packet:   pkt_02163090
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_0216D5A0  0x0216D5A0  thumb  ov010
 *   func_0216D564  0x0216D564  thumb  ov010
 *   func_0216DB68  0x0216DB68  thumb  ov010
 *   func_0216DCB4  0x0216DCB4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216DA5C(void *a0);
extern u32 func_0216D57C(void *p, u32 v);
extern u16 func_0216D5A0(void *p);
extern u32 func_0216D564(void *p);
extern int func_0216DB68(void *a0);
extern int func_0216DCB4(void *a0);

int func_02163090(int a0, int a1)
{
    int t4;
    int t5;

t5 = a0 + 0;
    a0 = func_0216DA5C((void *)a0);
loc_02163098:
    if (a0 != 0) goto loc_021630F0;
loc_0216309C:
a1 = 6;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = func_0216D57C((void *)a0, a1);
loc_021630A6:
    if (a0 != 0) goto loc_021630AE;
loc_021630AA:
a0 = 1;
    return a0;
loc_021630AE:
a0 = t5 + 0;
    a0 = func_0216D5A0((void *)a0);
loc_021630B4:
    if (a0 != 0x32) goto loc_021630BC;
loc_021630B8:
a0 = 1;
    return a0;
loc_021630BC:
a0 = t5 + 0;
    a0 = func_0216D564((void *)a0);
loc_021630C2:
t4 = a0 + 0;
a0 = 1;
a0 = a0 << 0xc;
    if ((a0 & t4) == 0) goto loc_021630DA;
loc_021630CC:
a0 = t5 + 0;
    a0 = func_0216DB68((void *)a0);
loc_021630D2:
    if (a0 != 0) goto loc_021630DA;
loc_021630D6:
a0 = 0;
    return a0;
loc_021630DA:
a0 = 2;
a0 = a0 << 0xa;
    if ((a0 & t4) == 0) goto loc_021630F0;
loc_021630E2:
a0 = t5 + 0;
    a0 = func_0216DCB4((void *)a0);
loc_021630E8:
    if (a0 != 0) goto loc_021630F0;
loc_021630EC:
a0 = 0;
    return a0;
loc_021630F0:
a0 = 1;
    return a0;}
