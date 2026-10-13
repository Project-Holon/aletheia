/*
 * function: FIELD_CAMERA_IsMoving
 * address:  0x0218FE50
 * packet:   pkt_ov021_0218FE50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj19576.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    u32 saved;
    u8 body[0x94];
    u32 active;
    u32 unk9c;
} Sub;

int FIELD_CAMERA_IsMoving(u8 *a)
{
    Sub *s = (Sub *)(a + 0xf0);
    if (((struct Obj19576 *)a)->f1AC != 0 && s->unk9c != 0)
        return 1;
    return 0;
}
