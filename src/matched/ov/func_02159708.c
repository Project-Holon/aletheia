/*
 * function: func_02159708
 * address:  0x02159708
 * packet:   pkt_02159708
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   func_02014460  0x02014460  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012B38(const struct BigObj *p);
extern int func_02014460();

int func_02159708(int a0, int a1)
{
    int t5;
    void *p;
    u16 *q;
    void *v0;

t5 = a1 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_02159710:
a0 = t5 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159718:
    p = func_02012B38((const struct BigObj *)v0);
loc_0215971C:
    a0 = func_02014460(p);
loc_02159720:
*q = a0;
a0 = 0;
    return a0;}
