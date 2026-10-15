/*
 * function: BOX2_SEQ_SetSlotActorMode
 * address:  0x021ECB60
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SetActorObjMode  0x021EC060  thumb  ov170
 *
 * Forward the byte at the pooled table offset.  The callee takes three
 * arguments, so the forwarded byte is argument 1 and the passing flag
 * stays in r2 untouched; that is what forces the sum into r3.
 */

extern void BOX2_SEQ_SetActorObjMode(char *p, unsigned i, int b);

void BOX2_SEQ_SetSlotActorMode(char *p, int i, int f)
{
    BOX2_SEQ_SetActorObjMode(p, *(unsigned char *)(p + i + 0x3DD2), f);
}
