/*
 * function: func_02204EB0
 * address:  0x02204EB0
 * packet:   pkt_02204EB0
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 */
#include "../include/Obj14523.h"
#include "../include/Obj24946.h"

extern int GFL_USE_PopBgm(void);
typedef unsigned int   u32;
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern void GFL_USE_FadeInBgmFull(u32 a);

void func_02204EB0(char *a, char *b)
{
    if (((struct Obj24946 *)b)->f30 == 0 && ((struct Obj14523 *)a)->fC != 0) {
        GFL_USE_PopBgm();
        GFL_USE_SetBgmPlayerParam(0);
        GFL_USE_FadeInBgmFull(0x3c);
    }
}
