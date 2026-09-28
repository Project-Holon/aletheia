/*
 * function: func_021EA798
 * address:  0x021EA798
 * packet:   pkt_ov170_021EA798
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DD210 0x021DD210 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021E00C4 0x021E00C4 thumb
 */

extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(unsigned char *p, int box);
extern int func_021DEDCC(unsigned char *p, int box);
extern void func_021DEC98(unsigned char *p, int a, int dir);
extern void func_020061E4(unsigned se);
extern void func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E0128(unsigned char *p);
extern int func_021E00C4(unsigned char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

void func_021EA798(unsigned char *p, int sel)
{
    int (*cb)(unsigned char *);
    int r = func_021DD210(p, p[0x14], *(unsigned char *)(WORK(p) + 0xA17F));
    p[0x14] = *(unsigned char *)(WORK(p) + 0xA17F);
    func_021EC35C(p, p[0x14]);
    func_021DEC98(p, func_021DEDCC(p, p[0x14]), r);
    if (r == 1)
        cb = func_021E0128;
    else
        cb = func_021E00C4;
    switch (sel) {
    case 0:
        *(int *)(p + 0x28) = 0x15;
        break;
    case 1:
        *(int *)(p + 0x28) = 0x63;
        break;
    }
    func_020061E4(0x548);
    func_021E8FC0(p, cb, *(int *)(p + 0x28));
}
