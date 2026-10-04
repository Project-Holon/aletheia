/*
 * function: func_0215B6C0
 * address:  0x0215B6C0
 * packet:   pkt_0215B6C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

int func_0215B6C0(int a0, int a1, int a2)
{
    unsigned char fr[4];
    int t5;
    int t6;
    u16 *q;
t6 = a0 + 0;
t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215B6CC:
a0 = t6 + 0;
a1 = t5 + 0;
    a0 = (int)func_02159B10((void *)a0, (void *)a1);
loc_0215B6D6:
a1 = a0 + 0;
t6 = 0;
a0 = t5 + 0;
a2 = (int)(fr + 0);
*q = t6;
    a0 = func_0215B4AC((void *)a0, a1, (void **)a2);
loc_0215B6E4:
    if (a0 != 1) goto loc_0215B6FE;
loc_0215B6E8:
    a0 = *(int *)(fr + 0);
a1 = 0x4c;
a2 = t6 + 0;
    a0 = func_02017E1C((void *)a0, a1, a2);
loc_0215B6F2:
    if (a0 != 0) goto loc_0215B6FA;
loc_0215B6F6:
*q = t6;
    goto loc_0215B6FE;
loc_0215B6FA:
a0 = 1;
*q = a0;
loc_0215B6FE:
a0 = 0;
    return a0;
}
