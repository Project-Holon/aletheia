/*
 * unit:     no
 * function: MYSTERY_DATA_IsMainSave
 * address:  0x0200A350
 * packet:   pkt_0200A170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_GetSaveType  0x0200A3FC  thumb
 */

typedef unsigned int   u32;
struct Obj;
extern u32 MYSTERY_DATA_GetSaveType(struct Obj *obj);
int MYSTERY_DATA_IsMainSave(struct Obj *a0)
{
    return MYSTERY_DATA_GetSaveType(a0);
}
