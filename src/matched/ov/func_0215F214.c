/*
 * function: func_0215F214
 * address:  0x0215F214
 * packet:   pkt_0215F214
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 20 compiled 18
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0202EB44  0x0202EB44  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *func_02159AE8(void *a0, void *a1);
extern int func_0202EB44();

int func_0215F214(int a0, int a1)
{    unsigned short *v0;

    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215F21A:
    a0 = func_0202EB44();
loc_0215F220:
*(u16 *)((char *)v0) = a0;
a0 = 0;
    return a0;}
