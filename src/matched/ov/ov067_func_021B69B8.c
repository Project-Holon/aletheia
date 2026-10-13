/*
 * unit:     yes
 * function: TOUCHBAR_GetButtonId, func_021B69BC, TOUCHBAR_CallSetEnabled, TOUCHBAR_SetButtonSoundId, TOUCHBAR_SetButtonKeys
 * address:  0x021B69B8
 * packet:   pkt_ov067_021B69B8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter, ARM9 tail call, indirect call, and two setters.  0x021B69BC is also
 * resident in ov172, so the packet id is region-qualified.
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj20610.h"
#include "../include/Obj20611.h"
#include "../include/Obj20612.h"
#include "../include/Obj20613.h"

int TOUCHBAR_GetButtonId(void *p)
{
    return ((struct Obj20610 *)p)->f18;
}

typedef unsigned int   u32;
struct Obj;
void func_021B69BC(void *p, unsigned int v)
{
    void func_0204B3DC(struct Obj *p, u32 v);
    func_0204B3DC(((struct Obj20611 *)p)->f0, v);
}

int TOUCHBAR_CallSetEnabled(void *p, int a)
{
    return (*(int (**)(void *, int))((char *)p + 0x10))(p, a);
}

void TOUCHBAR_SetButtonSoundId(void *p, int v)
{
    ((struct Obj20612 *)p)->f34 = v;
}

void TOUCHBAR_SetButtonKeys(void *p, int v)
{
    ((struct Obj20613 *)p)->f30 = v;
}
