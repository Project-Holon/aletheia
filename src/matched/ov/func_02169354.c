/*
 * function: func_02169354
 * address:  0x02169354
 * packet:   pkt_02169354
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216968C  0x0216968C  thumb  ov010
 *   func_02169710  0x02169710  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216968C();
extern int func_02169710();

int func_02169354(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t6 = a1 + 0;
t4 = 0;
    a0 = func_0216968C();
loc_02169360:
    if (a0 != 1) goto loc_02169378;
loc_02169364:
a0 = t5 + 0;
a0 = a0 + 0x98;
a0 = *(int *)((char *)a0);
    if (a0 == 0) goto loc_02169376;
loc_0216936E:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02169710(a0, a1);
loc_02169376:
t4 = 1;
loc_02169378:
a0 = t4 + 0;
    return a0;}
