/*
 * function: BMP_OAM_SetBgPriority
 * address:  0x02025A0C
 * packet:   pkt_0202590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 */
#include "../include/Obj08789.h"

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void CLACT_SetActorBgPriority(void *p, u32 a);

void BMP_OAM_SetBgPriority(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08789 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08789 *)g)->fCA; j++) {
            CLACT_SetActorBgPriority(*(void **)(g + 4 + (i * ((struct Obj08789 *)g)->fCA + j) * 4), a);
        }
    }
}
