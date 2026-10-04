/*
 * function: func_021C39CC
 * address: 0x021C39CC
 * packet: pkt_ov093_021C39CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86B8 0x021B86B8 thumb ov093
 */
#include "../include/Obj13329.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
extern u32 func_021B8588(void **p);
extern void *func_021B86B8(void ***);
BOOL func_021C39CC(u8 *p)
{
    u32 a;
    void *b;
    a = func_021B8588(((struct Obj13329 *)p)->f4);
    b = func_021B86B8(*(void *** *)&((struct Obj13329 *)p)->f4);
    if (a == 0) {
        if (b == 0) {
            return FALSE;
        } else {
            return TRUE;
        }
    }
    return TRUE;
}
