/*
 * function: FLDMMDL_G3DOBJ_DeleteResByCode
 * address:  0x0219D604
 * packet:   pkt_ov021_0219D604
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 */
#include "../include/Obj07479.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; } E4;
extern void FIELD_G3DOBJ_DeleteResource(u8 *p, int i);

void FLDMMDL_G3DOBJ_DeleteResByCode(u8 *s, u16 k)
{
    int i;
    int n = ((struct Obj07479 *)s)->f8;
    E4 *e = *(E4 * *)&((struct Obj07479 *)s)->fC;
    for (i = 0; i < n; i++, e++) {
        if (e->b == k) {
            FIELD_G3DOBJ_DeleteResource((u8 *)(((struct Obj07479 *)s)->f4), e->a);
            e->b = 0xFFFF;
            return;
        }
    }
}
