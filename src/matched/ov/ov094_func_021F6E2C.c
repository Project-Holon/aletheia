/*
 * function: func_021F6E2C
 * address:  0x021F6E2C
 * packet:   pkt_ov094_021F6E2C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed as the blocker of ov094 func_021F839C (lane S22).
 *
 * symbols:
 */
typedef unsigned int u32;
typedef struct { char pad[0x68]; u32 f : 1; u32 rest : 31; } Obj;

void func_021F6E2C(Obj *o, u32 v)
{
    o->f = v;
}
