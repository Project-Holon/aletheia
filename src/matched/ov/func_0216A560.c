/*
 * function: func_0216A560
 * address:  0x0216A560
 * packet:   pkt_0216A560
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 52 compiled 50
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02168CF4  0x02168CF4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5F4();
extern int func_0215A5DC();
extern int func_020120F4();
extern int func_02012F50();
extern int func_02168CF4();
extern int func_0215897C();

int func_0216A560(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0216A56A:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0216A572:
t4 = a0 + 0;
    a0 = func_020120F4(a0);
loc_0216A578:
    a0 = func_02012F50(a0);
loc_0216A57C:
a1 = a0 + 0;
a1 = *(int *)((char *)a1);
a0 = t4 + 0;
    a0 = func_02168CF4(a0, a1);
loc_0216A586:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0215897C(a0, a1);
loc_0216A58E:
a0 = 1;
    return a0;}
