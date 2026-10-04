/*
 * function: func_021B370C
 * address:  0x021B370C
 * packet:   pkt_ov013_021B370C
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02004EB0  0x02004EB0  arm
 *   d_02005108     0x02005108  data
 *   func_02082BCC  0x02082BCC  arm
 *   d_021B60CC     0x021B60CC  data  ov013
 *   d_021B60D8     0x021B60D8  data  ov013
 *   func_021B0508  0x021B0508  arm  ov013
 *   func_021B22B4  0x021B22B4  arm  ov013
 *   func_021B23C8  0x021B23C8  arm  ov013
 *   func_021B2ED8  0x021B2ED8  arm  ov013
 *   func_021B2F98  0x021B2F98  arm  ov013
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    int f8;
    u8  fc;
    u8  fd, fe, ff;
    int f10;
    int f14;
    int f18;
    int f1c;
} Param;

extern char d_02005108[];
extern int  d_021B60CC[];
extern u8   d_021B60D8[];
extern void func_02004EB0(const void *symbol);
extern void func_02082BCC(void *dst, int c, int n);
extern int  func_021B0508(void);
extern int  func_021B22B4(Param *p);
extern void func_021B23C8(void);
typedef unsigned int   u32;
struct E;
extern int func_021B2ED8(struct E *a, u32 b);
extern void func_021B2F98(void);

int func_021B370C(Param *p)
{
    func_02004EB0(d_02005108);
    if (p == 0)
        return 0;
    if (d_021B60CC[2] != 0)
        return 1;
    if (p->f8 != 1 && p->f8 != 2 && p->f8 != 3)
        return 0;
    if (p->f18 == 0)
        return 0;
    if (p->f10 == 0 || p->f14 == 0)
        return 0;
    if (p->f10 % 32 != 0)
        return 0;
    func_02082BCC(d_021B60D8, 0, 0x18);
    d_021B60CC[4] = p->f18;
    d_021B60CC[5] = p->f1c;
    d_021B60CC[7] = p->f8;
    d_021B60CC[6] = 0;
    if (p->fc >= 0x20)
        return 0;
    ((u8 *)d_021B60CC)[0xc] = p->fc;
    if (func_021B2ED8((struct E *)p->f10, p->f14) == 0) {
        func_021B2F98();
        return 0;
    }
    if (func_021B22B4(p) == 0) {
        func_021B2F98();
        return 0;
    }
    if (func_021B0508() != 0) {
        d_021B60CC[2] = 1;
        return 1;
    }
    func_021B23C8();
    func_021B2F98();
    return 0;
}
