/*
 * function: ZUKAN_DETAIL_FORM_DestroyModelItem
 * address:  0x021C51A0
 * packet:   pkt_021C51A0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_DeleteModel 0x021C5078  thumb  ov208

 * Releases the two handles held at +0 and +4.
 */
#include "../include/Obj04897.h"


extern void ZUKAN_DETAIL_FORM_DeleteModel(int, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void ZUKAN_DETAIL_FORM_DestroyModelItem(char *p, int a)
{
    if (((struct Obj04897 *)p)->f0 != 0)
        ZUKAN_DETAIL_FORM_DeleteModel(a, ((struct Obj04897 *)p)->f0);
    ((struct Obj04897 *)p)->f0 = 0;
    if (((struct Obj04897 *)p)->f4 != 0)
        func_020307B0((void *)(((struct Obj04897 *)p)->f4));
    ((struct Obj04897 *)p)->f4 = 0;
}

