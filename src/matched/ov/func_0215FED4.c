/*
 * function: SCRCMD_NETWORK_RecordLinkOnUpdate
 * address:  0x0215FED4
 * packet:   pkt_0215FED4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Conditional arm9 pair call on the record's second field; the first
 * call's result is the first operand either way.
 *
 * symbols:
 *   FIELDMAP_GetSubscreen   0x02188CCC  thumb
 *   FIELD_SUBSCREEN_SetMenuSelectedButton   0x021A12BC  thumb
 */
#include "../include/Obj12045.h"
#include "../include/Obj17708.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *FIELDMAP_GetSubscreen(int);
extern void FIELD_SUBSCREEN_SetMenuSelectedButton(void *, int);

int SCRCMD_NETWORK_RecordLinkOnUpdate(void *a0, void *a1)
{
    void *v = FIELDMAP_GetSubscreen(((struct Obj12045 *)a1)->fC);

    if (((struct Obj17708 *)a0)->f24 == 0)
        FIELD_SUBSCREEN_SetMenuSelectedButton(v, ((struct Obj12045 *)a1)->f10);

    return 1;
}

