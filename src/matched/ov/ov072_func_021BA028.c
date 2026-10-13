/*
 * function: TOWNMAP_BackButtonGetPressed
 * address: 0x021BA028
 * packet: pkt_ov072_021BA028
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 */
#include "../include/Obj13193.h"
extern int TOUCHBAR_GetPressedButtonIdIfDone(unsigned char *);
int TOWNMAP_BackButtonGetPressed(char *p) {
    int n;
    n = TOUCHBAR_GetPressedButtonIdIfDone(*(unsigned char * *)&((struct Obj13193 *)p)->fC);
    if (n == -1) n = ((struct Obj13193 *)p)->f18;
    return n;
}
