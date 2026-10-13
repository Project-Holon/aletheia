/*
 * function: FIELD_CAMERA_PushStateConstrained
 * address:  0x0218F848
 * packet:   pkt_ov021_0218F848
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb
 *   FIELD_CAMERA_TakeViewConstrained  0x0218F7D0  thumb
 */
#include "../include/Obj02371.h"

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
} Sub;

extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FIELD_CAMERA_TakeViewConstrained(u8 *s, u8 *d);

void FIELD_CAMERA_PushStateConstrained(u8 *a)
{
    if (a != 0) {
        Sub *s = (Sub *)(a + 0xf0);
        if (s->active == 0) {
            s->saved = ((struct Obj02371 *)a)->f14;
            FIELD_CAMERA_SetMode(a, 0);
            FIELD_CAMERA_TakeViewConstrained(a, s->body);
            s->active = 1;
        }
    }
}
