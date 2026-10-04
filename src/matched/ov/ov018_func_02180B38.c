/*
 * function: func_02180B38
 * address:  0x02180B38
 * packet:   pkt_ov018_02180B38
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb ov010
 *   func_02012944  0x02012944  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F184  0x0201F184  thumb
 *   func_0217F3C4  0x0217F3C4  thumb ov018
 *   func_0217F40C  0x0217F40C  thumb ov018
 *   func_0217F420  0x0217F420  thumb ov018
 *   func_0217FE38  0x0217FE38  thumb ov018
 *   d_02183848     0x02183848  data ov018 a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u16 d_02183848[];

int func_020124E4(int x);
int func_020120F4(int x);
struct Ctx;
unsigned int func_02012138(const struct Ctx *x);
void *func_02158344(int x);
int func_02012944(int a);
void func_0201F02C(int a, int b, int c);
void func_0201F184(int a, int b, int c);
void func_0217F3C4(u8 *p, int a);
int func_0217F40C(u8 *p);
int func_0217F420(void);
void func_0217FE38(void *m, u8 *obj);

int func_02180B38(int x, int *st, u8 *obj)
{
    int v = func_020124E4(x);
    void *m;

    m = func_02158344(func_02012138((const struct Ctx *)v));
    switch (*st) {
    case 0:
        func_0201F02C(*(int *)(obj + 0x10), 0, (int)(obj + 0x78));
        func_0201F02C(*(int *)(obj + 0x10), 1, func_02012944(func_020120F4(v)));
        func_0201F184(*(int *)(obj + 0x10), 2, *(u16 *)(obj + 0x58));
        func_0217F3C4(obj + 0x10, d_02183848[obj[0x42]]);
        *st = *st + 1;
        break;
    case 1:
        if (func_0217F40C(obj + 0x10) == 1) {
            *st = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *st = 3;
        }
        break;
    case 3:
        func_0217FE38(m, obj);
        return 1;
    }
    return 0;
}
