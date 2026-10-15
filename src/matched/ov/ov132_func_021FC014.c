/*
 * function: func_021FC014
 * address: 0x021FC014
 * packet: pkt_ov132_021FC014
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   STA_ACTING_GetAnimSlot 0x021F9DC4 thumb ov132
 *   func_021F9F74 0x021F9F74 thumb ov132
 */
#include "../include/Obj05403.h"
#include "../include/Obj23258.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *STA_ACTING_GetAnimSlot(void *, u8);
extern void func_021F9F74(void *, u16, void *);
int func_021FC014(int unused, char *p)
{
    char *obj;
    int a, b, c, d, e;
    void *target;
    struct { int x, y, z; } vec;
    obj = *(char * *)&((struct Obj05403 *)p)->f0;
    a = VM_GetU32(((struct Obj05403 *)p)->f4);
    b = VM_GetU32(((struct Obj05403 *)p)->f4);
    c = VM_GetU32(((struct Obj05403 *)p)->f4);
    d = VM_GetU32(((struct Obj05403 *)p)->f4);
    e = VM_GetU32(((struct Obj05403 *)p)->f4);
    target = STA_ACTING_GetAnimSlot(((struct Obj23258 *)obj)->f34, (u8)a);
    vec.x = c / 16;
    vec.y = (0xC0000 - d) / 16;
    vec.z = e;
    func_021F9F74(target, (u16)b, &vec);
    return 0;
}
