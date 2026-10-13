/*
 * function: func_021E0068
 * address: 0x021E0068
 * packet: pkt_ov170_021E0068
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the full party-count-plus-30 expression to an int local.
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   func_021DE158 0x021DE158 thumb ov170
 *   func_021ED6E4 0x021ED6E4 thumb ov170
 *   func_021DD930 0x021DD930 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj08233.h"
extern unsigned POKEPARTY_GetCount(void *p);
extern int func_021DE158(unsigned char *p, unsigned a, unsigned b);
extern void func_021ED6E4(char **p, int v);
extern int func_021DD930(unsigned char *p);
extern void func_021DE66C(char *p, void *a);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021E0068(char *p)
{
    char *s;
    int count;
    s = *(char * *)&((struct Obj00000 *)p)->f2C + 0x58;
    switch (((struct Obj08233 *)s)->fC) {
    case 0:
        count = POKEPARTY_GetCount((*(void *** )p)[2]) + 30;
        func_021DE158((unsigned char *)p, ((struct Obj00000 *)p)->f16, count);
        func_021ED6E4((char **)p, 0);
        (((struct Obj08233 *)s)->fC)++;
        break;
    case 1:
        if (func_021DD930((unsigned char *)p) == 0) {
            func_021DE66C(p, ((struct Obj08233 *)s)->f8);
            GFL_USE_PlaySeDefaultVolume(0x667);
            ((struct Obj08233 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
