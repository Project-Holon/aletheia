/*
 * function: func_0215B3AC
 * address:  0x0215B3AC
 * packet:   pkt_0215B3AC
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
 *   func_0215F6E8  0x0215F6E8  thumb  ov010
 *   func_0215898C  0x0215898C  thumb  ov010
 *   func_02011290  0x02011290  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern void *func_0215F6E8(void *p);
extern int func_0215898C();
extern int func_02011290();

int func_0215B3AC(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215B3B8:
a0 = t6 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215B3C0:
    p = func_0215F6E8(v0);
loc_0215B3C8:
    a0 = func_0215898C(v1, p);
loc_0215B3D0:
a0 = t5 + 0;
    a0 = func_02011290(a0);
loc_0215B3D6:
a0 = 1;
    return a0;}
