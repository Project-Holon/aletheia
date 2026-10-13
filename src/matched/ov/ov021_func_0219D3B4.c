/*
 * function: FLDMMDL_BLACT_IsCodeChangePending
 * address:  0x0219D3B4
 * packet:   pkt_ov021_0219D3B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj00429.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u32 p; u16 id; u16 pad; u32 x; } Slot;

int FLDMMDL_BLACT_IsCodeChangePending(u8 *s, u32 p, u16 id)
{
    Slot *e = *(Slot * *)&((struct Obj00429 *)s)->f20;
    int i;
    if (e != 0) {
        for (i = 0; i < 4; i++, e++) {
            if (e->p != 0 && e->p == p && e->id == id) {
                return 1;
            }
        }
    }
    return 0;
}
