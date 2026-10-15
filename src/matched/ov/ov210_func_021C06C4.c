/*
 * function: ZKNSEARCH_RESULT_SetRow4
 * address:  0x021C06C4
 * packet:   pkt_ov210_021C06C4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKNSEARCH_MAIN_TransferRowChars 0x021BECAC thumb ov210
 *   ZKNSEARCH_MAIN_PlaceColumnActor3 0x021BFA14 thumb ov210
 *   ZKNSEARCH_MAIN_PlacePageActor 0x021BFB8C thumb ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25636.h"

typedef unsigned char u8;

extern void ZKNSEARCH_MAIN_TransferRowChars(int p, unsigned *b);
extern void ZKNSEARCH_MAIN_PlaceColumnActor3(char *p, int y, int flag);
extern void ZKNSEARCH_MAIN_PlacePageActor(char *ctx, unsigned long slot, int y, int flag);

void ZKNSEARCH_RESULT_SetRow4(int p, unsigned a, unsigned *b, int c, int d)
{
    ZKNSEARCH_MAIN_TransferRowChars(p, b);
    if ((*(u8 **)(*(int * *)&((struct Obj25636 *)p)->f0 + 2))[6] == a)
        ZKNSEARCH_MAIN_PlaceColumnActor3((char *)p, c, d);
    ZKNSEARCH_MAIN_PlacePageActor((char *)p, (unsigned short)a, c, d);
}
