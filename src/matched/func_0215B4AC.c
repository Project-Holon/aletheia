/*
 * function: func_0215B4AC
 * address:  0x0215B4AC
 * packet:   pkt_0215B4AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5E4();
extern int func_02012934();
extern int func_0201AA18();
extern int func_0201AB28();

int func_0215B4AC(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;
    int t7;

t5 = a1 + 0;
t6 = a2 + 0;
    a0 = func_0215A5E4();
loc_0215B4B6:
    a0 = func_02012934();
loc_0215B4BA:
t7 = a0 + 0;
    a0 = func_0201AA18();
loc_0215B4C0:
    if ((unsigned)t5 >= (unsigned)a0) goto loc_0215B4C8;
loc_0215B4C4:
t4 = 1;
    goto loc_0215B4CC;
loc_0215B4C8:
t4 = 0;
t5 = 0;
loc_0215B4CC:
a0 = t7 + 0;
a1 = t5 + 0;
    a0 = func_0201AB28(a0, a1);
loc_0215B4D4:
*(int *)((char *)t6) = a0;
a0 = t4 + 0;
    return a0;}
