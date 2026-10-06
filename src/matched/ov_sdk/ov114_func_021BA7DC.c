/*
 * function: func_021BA7DC
 * address:  0x021BA7DC
 * packet:   pkt_ov114_021BA7DC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_InitBgnEndInfo (libnhttp.TWL.HYB.a(nhttp_bgnend.o))
 *
 * symbols:
 *   func_021BA874 0x021BA874 arm ov114
 *   func_021BA87C 0x021BA87C arm ov114
 */

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
} BgnEnd;

typedef unsigned char  u8;
extern void func_021BA87C(u8 *p, int v);
extern void func_021BA874(u8 *p, int v);

void func_021BA7DC(BgnEnd *info_p)
{
    info_p->f0 = 0;
    info_p->f4 = 0;
    info_p->f8 = 0;
    info_p->fc = -1;
    func_021BA87C((u8 *)info_p, 0);
    func_021BA874((u8 *)info_p, 0);
    info_p->f18 = 0;
    info_p->f1c = 0;
    info_p->f20 = 0;
}
