/*
 * function: FLDMMDL_G3DOBJ_DeleteResTable
 * address:  0x0219D4EC
 * packet:   pkt_ov021_0219D4EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj06002.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; } E4;
extern void FIELD_G3DOBJ_DeleteResource(u8 *p, int i);
extern u32 func_020307B0(void *p);

void FLDMMDL_G3DOBJ_DeleteResTable(u8 *s)
{
    int i = 0;
    E4 *e = *(E4 * *)&((struct Obj06002 *)s)->fC;
    if (i < ((struct Obj06002 *)s)->f8) {
        for (; i < ((struct Obj06002 *)s)->f8; i++, e++) {
            if (e->b != 0xFFFF) {
                FIELD_G3DOBJ_DeleteResource((u8 *)(((struct Obj06002 *)s)->f4), e->a);
            }
        }
    }
    func_020307B0(((struct Obj06002 *)s)->fC);
}
