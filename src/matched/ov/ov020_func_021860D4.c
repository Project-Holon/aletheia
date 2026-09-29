/*
 * function: func_021860D4
 * address:  0x021860D4
 * packet:   pkt_ov020_021860D4
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008530  0x02008530  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_0218682C  0x0218682C  thumb  ov020
 *   func_02186B60  0x02186B60  thumb  ov020
 *   func_021869E0  0x021869E0  thumb  ov020
 *   func_02186B84  0x02186B84  thumb  ov020
 *   func_02186804  0x02186804  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02008530(u32 a);
extern u32 func_020056EC(u32 n);
extern int func_021867C4(int, int);
extern char *func_0218682C(int);
extern void *func_02186B60(void *p);
extern char *func_021869E0(u16 *p, int r, int h, int *out);
extern void func_02186B84(void *slot, u8 a, int b, u16 c, int d);
extern void func_02186804(int);

void func_021860D4(u16 *p, int a1, int id)
{
    int i;
    int j;
    int r;
    char *e;
    int rem;
    int flag;
    int out;
    void *slot;
    int h;
    int v;

    p[0] = 1;
    i = 0;
    p[1] = 0;
    rem = 0x1CE;
    *(u32 *)(p + 2) = func_02008530(a1);
    h = func_021867C4(0, (u16)((id & 0x7FFF) | 0x8000));
    func_0218682C(h);
    for (i = 0; i < 10; i++) {
        r = func_020056EC(rem);
        slot = func_02186B60(p + 4);
        e = func_021869E0(p, r, h, &out);
        if (p[1] == 0) {
            v = *(u16 *)(e + 6);
            flag = 1;
        } else {
            v = *(u16 *)(e + 4);
            flag = 0;
        }
        func_02186B84(slot, (u8)out, a1, v, flag);
        rem -= *(u16 *)(e + 0x2c);
    }
    for (j = 0; j < 3; j++) {
        r = func_020056EC(rem);
        slot = func_02186B60((char *)p + 0xf8);
        e = func_021869E0(p, r, h, &out);
        func_02186B84(slot, (u8)out, a1, 0, flag);
        rem -= *(u16 *)(e + 0x2c);
    }
    func_02186804(h);
}
