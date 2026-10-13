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
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E0128 0x021E0128 thumb
 *   func_021E00C4 0x021E00C4 thumb
 */
#include "../include/Obj00000.h"

extern int func_021DD210(unsigned char *p, unsigned a, unsigned b);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E0128(char *p);
extern int func_021E00C4(char *p);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021EA798(unsigned char *p, int sel)
{
    int (*cb)(unsigned char *);
    int r = func_021DD210(p, p[0x14], *(unsigned char *)(WORK(p) + 0xA17F));
    p[0x14] = *(unsigned char *)(WORK(p) + 0xA17F);
    func_021EC35C((char **)p, p[0x14]);
    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), r);
    if (r == 1)
        cb = (int (*)(unsigned char *))func_021E0128;
    else
        cb = (int (*)(unsigned char *))func_021E00C4;
    switch (sel) {
    case 0:
        ((struct Obj00000 *)p)->f28 = 0x15;
        break;
    case 1:
        ((struct Obj00000 *)p)->f28 = 0x63;
        break;
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
    return func_021E8FC0((char *)p, (int)cb, ((struct Obj00000 *)p)->f28);
}
