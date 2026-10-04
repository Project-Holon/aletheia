/*
 * function: func_0215BCA0
 * address:  0x0215BCA0
 * packet:   pkt_0215BCA0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215B4AC  0x0215B4AC  thumb  ov010
 *   func_02017E1C  0x02017E1C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern unsigned int func_02159B10(void *a0, void *a1);
extern int func_0215B4AC(void *a0, u32 a1, void **a2);
extern u32 func_02017E1C(void *p, u32 id, u32 v);

int func_0215BCA0(int a0, int a1, int a2)
{
    int v0;
    int t4;
    int t5;
    int t6;
    u16 *q;
t5 = a0 + 0;
t4 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215BCAA:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215BCB4:
a1 = a0 + 0;
a0 = t4 + 0;
a2 = (int)&v0;
t5 = 0;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215BCC0:
    if (a0 != 1) goto loc_0215BCE0;
loc_0215BCC4:
t4 = t5 + 0;
t6 = t5 + 0;
loc_0215BCC8:
a1 = t4 + 0;
    a0 = v0;
a1 = a1 + 0x36;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215BCD4:
    if (a0 == 0) goto loc_0215BCDA;
loc_0215BCD8:
t5 = t5 + 1;
loc_0215BCDA:
t4 = t4 + 1;
    if (t4 < 4) goto loc_0215BCC8;
loc_0215BCE0:
*q = t5;
a0 = 0;
    return a0;
}
