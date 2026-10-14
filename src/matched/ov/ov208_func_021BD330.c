/*
 * function: ZKND_TBAR_SetButtonDrawEnable
 * address:  0x021BD330
 * packet:   pkt_ov208_021BD330
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZKND_TBAR_SetActorDrawEnable  0x021BD7FC  thumb
 */

typedef unsigned int u32;

struct Ov208Mgr {
    u32 f0;
    u32 count;
};

struct Obj;
extern void ZKND_TBAR_SetActorDrawEnable(struct Obj **p, unsigned int v);

void ZKND_TBAR_SetButtonDrawEnable(struct Ov208Mgr *p, int v)
{
    u32 i;

    for (i = 0; i < p->count; i++)
        ZKND_TBAR_SetActorDrawEnable((void *)((u32)p + 0x28 + i * 0x38), v);
}
