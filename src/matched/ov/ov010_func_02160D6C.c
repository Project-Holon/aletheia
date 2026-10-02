/*
 * function: func_02160D6C
 * address:  0x02160D6C
 * packet:   pkt_ov010_02160D6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_02172978     0x02172978  data  a1
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012134  0x02012134  thumb
 *   func_02029DBC  0x02029DBC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct T { u32 a; u32 b; u32 c; u16 h; } T;

extern T *func_02030734();
extern u8 d_02172978[];
extern void func_02082BCC();
extern int func_020120F4();
extern int func_0200CA1C();
extern int func_02012944();
extern int func_02012A30();
extern int func_02012134();
extern void func_02029DBC();

T *func_02160D6C(int *a0, int a1)
{
    T *p;
    int s;

    p = func_02030734(4, 0x10, 0, d_02172978, 0x49b);
    func_02082BCC(p, 0, 0x10);
    s = func_020120F4(*(int *)a0[6]);
    p->a = s;
    p->b = func_0200CA1C(s);
    p->c = func_02012944(p->a);
    s = func_02012A30(p->a);
    func_02029DBC(s, func_02012134(*(int *)a0[6]));
    if (a1 != -1) {
        p->h = a1;
    } else {
        p->h = 0;
    }
    return p;
}
