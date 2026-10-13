/*
 * function: func_02201DA0
 * address:  0x02201DA0
 * packet:   pkt_ov094_02201DA0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 CLACT_SetActorAnimSeq(void *obj, u16 v);

u32 func_02201DA0(char *p, int i, int v)
{
    return CLACT_SetActorAnimSeq(*(void **)(p + i * 16 + 8), (u16)v);
}
