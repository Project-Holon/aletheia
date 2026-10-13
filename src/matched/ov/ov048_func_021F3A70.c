/*
 * function: FIELD_GIMMICK_GATE_HasMessagesToShow
 * address:  0x021F3A70
 * packet:   pkt_021F3A70
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlNetSourceName  0x021F3A98  thumb
 *   FIELD_GIMMICK_GATE_IsExtraSaveListOn  0x021F3AB4  thumb
 */
#include "../include/Obj20530.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern int gBtlNetSourceName(void *p);
extern int FIELD_GIMMICK_GATE_IsExtraSaveListOn(void *p);

int FIELD_GIMMICK_GATE_HasMessagesToShow(u8 *p)
{
    if (gBtlNetSourceName(p) == 1 || FIELD_GIMMICK_GATE_IsExtraSaveListOn(p) == 1) {
        if (((struct Obj20530 *)p)->f64 != 0) {
            return 1;
        }
    }
    return 0;
}
