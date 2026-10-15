/*
 * unit:     yes
 * address:  0x020640DC
 * packet:   pkt_020640DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O1
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * function: NNS_G2dSetSRTTranslate, NNS_G2dSetSRTRotate, NNS_G2dSetSRTScale
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 state;
    u32 arg1;
    u32 arg2;
    u16 field0c;
    u16 field0e;
    u16 field10;
    u16 flags;
} Obj020640DC;

void NNS_G2dSetSRTTranslate(Obj020640DC *obj, u16 a, u16 b)
{
    if (obj->state != 1) return;
    obj->flags |= 8;
    obj->field0c = a;
    obj->field0e = b;
}

void NNS_G2dSetSRTRotate(Obj020640DC *obj, u16 val)
{
    if (obj->state != 1) return;
    obj->flags |= 4;
    obj->field10 = val;
}

void NNS_G2dSetSRTScale(Obj020640DC *obj, u32 a1, u32 a2)
{
    if (obj->state != 1) return;
    obj->flags |= 2;
    obj->arg1 = a1;
    obj->arg2 = a2;
}
