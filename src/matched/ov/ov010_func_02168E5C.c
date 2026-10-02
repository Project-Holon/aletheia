/*
 * function: func_02168E5C
 * address:  0x02168E5C
 * packet:   pkt_ov010_02168E5C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E8F8  0x0200E8F8  thumb
 *   func_02168EB0  0x02168EB0  thumb
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern int func_020120F4(int);
extern int func_020122C0(int, int, void *, int);
extern int *func_020124E8(int);
extern void *func_0201210C(void *p);
extern int func_02012944(int);
extern u8 func_02008550(int);
extern int func_02012EBC(int);
extern int func_0200E8F8(int);
extern void func_02168EB0(void);

int func_02168E5C(int a, int b, int c)
{
    int x = func_020120F4(a);
    int h = func_020122C0(a, 0, func_02168EB0, 0x18);
    int *p = func_020124E8(h);
    p[0] = a;
    p[1] = func_0201210C((void *)a);
    *(u8 *)(p + 2) = func_02008550(func_02012944(x));
    p[3] = func_0200E8F8(func_02012EBC(x));
    p[4] = b;
    p[5] = c;
    return h;
}
