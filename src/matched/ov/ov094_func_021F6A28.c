/*
 * function: func_021F6A28
 * address:  0x021F6A28
 * packet:   pkt_ov094_021F6A28
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
typedef struct { char pad[0xB4]; u32 f : 2; u32 rest : 30; } Obj;

void func_021F6A28(Obj *o, u32 mode, u32 on)
{
    if (mode == 2) {
        if (on)
            o->f = 3;
        else
            o->f = 0;
    } else {
        if (on)
            o->f = o->f | (1 << mode);
        else
            o->f = o->f & ((1 << mode) ^ 3);
    }
}
