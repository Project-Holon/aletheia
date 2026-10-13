/*
 * function: BMP_OAM_SetEnabled
 * address:  0x02025774
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 */
#include "../include/Obj08786.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);

void BMP_OAM_SetEnabled(u8 *g, u32 a)
{
    u8 i;
    u8 j;

    for (i = 0; i < ((struct Obj08786 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08786 *)g)->fCA; j++) {
            CLACT_SetActorDrawEnable(*(void **)(g + 4 + (i * ((struct Obj08786 *)g)->fCA + j) * 4), a);
        }
    }
}
