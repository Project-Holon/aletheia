/*
 * function: func_021E8BF8
 * address:  0x021E8BF8
 * packet:   pkt_ov170_021E8BF8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02025DE8 0x02025DE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_02007A80 0x02007A80 thumb
 *   func_021E8F50 0x021E8F50 thumb
 *   func_021E949C 0x021E949C thumb
 *   func_021EA928 0x021EA928 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 */
#include "../include/Obj00000.h"

struct Sound;
extern int func_02025DE8(struct Sound *obj);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern int func_02007A80(void *save, unsigned bits);
extern int func_021E8F50(char *p, int v);
extern int func_021E949C(char *p, int a, int b);
extern int func_021EA928(unsigned char *p, int a);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);

#define WORK(p) (*(char **)((p) + 0x2C))
#define SEL(p) (*(unsigned char *)(WORK(p) + 0xA17C))

int func_021E8BF8(unsigned char *p)
{
    switch ((unsigned)func_02025DE8(*(void **)(WORK(p) + 0x70))) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 5;
            return func_021E949C((char *)p, 0, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 0);
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 1;
            return func_021E949C((char *)p, 1, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 1);
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 2;
            return func_021E949C((char *)p, 2, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 2);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 3;
            return func_021E949C((char *)p, 3, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 3);
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x54C);
        if (SEL(p) == 0) {
            SEL(p) = 4;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        if (SEL(p) == 5 && func_02007A80(((void **)((struct Obj00000 *)p)->f0)[1], 2) == 1) {
            SEL(p) = 6;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        if (SEL(p) == 6) {
            SEL(p) = 5;
            return func_021E949C((char *)p, 4, func_021E8F50((char *)p, 0x64));
        }
        return func_021EA928(p, 4);
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (SEL(p) == 0)
            return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5F));
        SEL(p) = 0;
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x64));
    case 0xFFFFFFFE:
        GFL_USE_PlaySeDefaultVolume(0x551);
        if (SEL(p) == 0)
            return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x5F));
        SEL(p) = 0;
        return func_021E949C((char *)p, 5, func_021E8F50((char *)p, 0x64));
    case 0xFFFFFFFD:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x65));
    }
    return 0x65;
}
