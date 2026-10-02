/*
 * function: func_0215E184
 * address:  0x0215E184
 * packet:   pkt_0215E184
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012F80  0x02012F80  thumb
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_021FD910  0x021FD910  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern int func_02012F80(void *a0);
extern int func_02156BAC();
extern int func_02156BCC();
extern int func_021FD910();

int func_0215E184(int a0, int a1)
{
    int t4;
    void *v0;
    void *v1;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0215E18E:
a0 = t4 + 0;
    v1 = func_0215A5E4((void *)a0);
loc_0215E194:
    a0 = func_02012F80(v1);
loc_0215E198:
t4 = a0 + 0;
a0 = *(int *)((char *)t4);
    a0 = func_02156BAC(a0);
loc_0215E1A0:
a0 = *(int *)((char *)t4);
    a0 = func_02156BCC(a0);
loc_0215E1A6:
    if (a0 != 1) goto loc_0215E1AE;
loc_0215E1AA:
a0 = 1;
    return a0;
loc_0215E1AE:
a0 = *(int *)((char *)t4 + 4);
    a0 = func_021FD910(a0);
loc_0215E1B4:
    if (a0 != 1) goto loc_0215E1BC;
loc_0215E1B8:
a0 = 1;
    return a0;
loc_0215E1BC:
a0 = 0;
    return a0;}
