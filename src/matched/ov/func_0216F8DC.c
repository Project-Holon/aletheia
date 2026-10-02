/*
 * function: func_0216F8DC
 * address:  0x0216F8DC
 * packet:   pkt_0216F8DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021F38BC  0x021F38BC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_021F38BC();
extern int func_0215897C();

int func_0216F8DC(int a0, int a1)
{    int t5;
    void *task;
    void *v0;
    void *v1;

t5 = a1 + 0;
a0 = t5 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216F8E6:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216F8EE:
    task = func_021F38BC(v1);
loc_0216F8F2:
    a0 = func_0215897C(v0, task);
loc_0216F8FA:
a0 = 1;
    return a0;}
