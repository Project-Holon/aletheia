/*
 * function: DENDOU_VIEW_StartButtonAnim
 * address: 0x021DD500
 * packet: pkt_ov171_021DD500
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: larger followers 0x021DD51C and 0x021DD558 have separate files.
 * symbols:
 *   DENDOU_VIEW_SetActorAnim 0x021DE080 thumb ov171
 */
#include "../include/Obj00347.h"
typedef unsigned char  u8;
extern void DENDOU_VIEW_SetActorAnim(u8 *p, int i, int value);
int DENDOU_VIEW_StartButtonAnim(char *p, int i, int n, int v)
{
    DENDOU_VIEW_SetActorAnim((u8 *)p, i, n);
    ((struct Obj00347 *)p)->fC64 = i;
    ((struct Obj00347 *)p)->fC68 = v;
    return 3;
}
