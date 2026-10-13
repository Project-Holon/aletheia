/*
 * function: CLACT_UpdateObjMapping
 * address:  0x0204DC70
 * packet:   pkt_0204DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;
typedef volatile u32 vu32;

struct TargetStruct {
    char pad[8];
    u32 dispcnt;
};

void CLACT_UpdateObjMapping(struct TargetStruct *obj, int which)
{
    u32 val = (which == 1) ? (*(vu32 *)0x04000000 & 0x00300010) : (*(vu32 *)0x04001000 & 0x00300010);
    if (obj->dispcnt != val) {
        obj->dispcnt = val;
    }
}
