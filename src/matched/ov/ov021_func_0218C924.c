/*
 * function: FIELD_BUILDMODEL_GetNodeModelKind
 * address:  0x0218C924
 * packet:   pkt_ov021_0218C924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj19541.h"

typedef struct { unsigned short a, b; } E;

unsigned short FIELD_BUILDMODEL_GetNodeModelKind(unsigned char *p)
{
    if (p == 0)
        return 0;
    return (**(E ** *)&((struct Obj19541 *)p)->f10)->b;
}
