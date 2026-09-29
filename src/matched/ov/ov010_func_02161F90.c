/*
 * function: func_02161F90
 * address:  0x02161F90
 * packet:   pkt_ov010_02161F90
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02161DC4  0x02161DC4  thumb
 *   func_021867C4  0x021867C4  thumb ov020
 *   func_0218682C  0x0218682C  thumb
 *   func_02186804  0x02186804  thumb
 *   func_02186520  0x02186520  thumb
 *   func_02161E78  0x02161E78  thumb
 *   func_02161E60  0x02161E60  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *func_02161DC4(char *, int, int);
extern int func_021867C4(int, int);
extern u16 *func_0218682C(void);
extern void func_02186804(int);
extern void func_02186520(u16 *, int, u8 *);
extern void func_02161E78(u8 *);
extern void func_02161E60(char *, int);

void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v)
{
    u8 *r4;
    int h;
    u16 *q;

    r4 = func_02161DC4(y, w, 1);
    h = func_021867C4(w, v);
    q = func_0218682C();
    if (x[1] == 0)
        r4[2] = q[3];
    else
        r4[2] = q[2];
    r4[3] = 7;
    func_02186804(h);
    func_02186520(x, z, r4);
    func_02161E78(r4);
    func_02161E60(y, 1);
}
