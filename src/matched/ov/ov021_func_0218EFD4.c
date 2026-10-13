/*
 * function: FIELD_CAMERA_DeleteDelay
 * address:  0x0218EFD4
 * packet:   pkt_ov021_0218EFD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj04202.h"
#include "../include/Obj19566.h"
#include "../include/Obj19567.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020307B0(void *p);

void FIELD_CAMERA_DeleteDelay(u8 *a)
{
    if (*(u8 * *)&((struct Obj04202 *)a)->fEC != 0) {
        func_020307B0(((struct Obj19566 *)(*(u8 * *)&((struct Obj04202 *)a)->fEC))->f20);
        func_020307B0(((struct Obj19567 *)(*(u8 * *)&((struct Obj04202 *)a)->fEC))->f24);
        func_020307B0(((struct Obj04202 *)a)->fEC);
        ((struct Obj04202 *)a)->fEC = 0;
    }
}
