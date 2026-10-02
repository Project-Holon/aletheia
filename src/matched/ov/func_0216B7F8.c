/*
 * function: func_0216B7F8
 * address:  0x0216B7F8
 * packet:   pkt_0216B7F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 36 compiled 34
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021670F8  0x021670F8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_021670F8(void *p);
extern int func_0215897C();

int func_0216B7F8(int a0, int a1)
{    int t5;
    void *p;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216B802:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216B80A:
    p = func_021670F8(v1);
loc_0216B80E:
    a0 = func_0215897C(v0, p);
loc_0216B816:
a0 = 1;
    return a0;}
