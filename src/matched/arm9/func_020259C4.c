/*
 * function: BMP_OAM_SetDrawPriority
 * address:  0x020259C4
 * packet:   pkt_0202590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 */
#include "../include/Obj08788.h"

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Node;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);

void BMP_OAM_SetDrawPriority(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08788 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08788 *)g)->fCA; j++) {
            CLACT_SetActorDrawPriority(*(void **)(g + 4 + (i * ((struct Obj08788 *)g)->fCA + j) * 4), a);
        }
    }
}
