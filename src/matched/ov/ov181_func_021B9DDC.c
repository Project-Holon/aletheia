/*
 * function: STAFF_ROLL_FlushWindows
 * address: 0x021B9DDC
 * packet: pkt_ov181_021B9DDC
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 0x021B9E12.
 * symbols:
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj06587.h"
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
void STAFF_ROLL_FlushWindows(char *p){if(((struct Obj06587 *)p)->f2CC&1)BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06587 *)p)->f2BC);if(((struct Obj06587 *)p)->f2CC&2)BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06587 *)p)->f2C4);((struct Obj06587 *)p)->f2CC=0;}
