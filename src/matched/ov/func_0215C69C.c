/*
 * function: func_0215C69C
 * address:  0x0215C69C
 * packet:   pkt_0215C69C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB8  0x02158FB8  thumb  ov010
 *   func_020120F0  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02158FBC  0x02158FBC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0215A5DC();
extern int func_0215A5F4();
extern int func_02158FB8(int a0);
extern int func_020120F0();
extern void func_020307B0(int a0);
extern int func_02158FBC();

int func_0215C69C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t4 = a1 + 0;
a0 = t4 + 0;
    a0 = func_0215A5DC(a0);
loc_0215C6A6:
t6 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A5F4(a0);
loc_0215C6AE:
t4 = a0 + 0;
    a0 = func_02158FB8(a0);
loc_0215C6B4:
t5 = a0 + 0;
a0 = t6 + 0;
    a0 = func_020120F0(a0);
loc_0215C6BC:
    if (a0 == 0) goto loc_0215C6C4;
loc_0215C6C0:
a0 = 0;
    return a0;
loc_0215C6C4:
a1 = *(int *)((char *)t5 + 8);
    if (a1 == 0) goto loc_0215C6D0;
loc_0215C6CA:
a0 = t5 + 0;
    a0 = ((int (*)())a1)(a0);
loc_0215C6CE:
    goto loc_0215C6E4;
loc_0215C6D0:
a0 = *(int *)((char *)t5);
    if (a0 == 0) goto loc_0215C6DA;
loc_0215C6D6:
    func_020307B0(a0);
loc_0215C6DA:
a0 = *(int *)((char *)t5 + 4);
    if (a0 == 0) goto loc_0215C6E4;
loc_0215C6E0:
    func_020307B0(a0);
loc_0215C6E4:
a0 = t4 + 0;
    a0 = func_02158FBC(a0);
loc_0215C6EA:
a0 = 1;
    return a0;}
