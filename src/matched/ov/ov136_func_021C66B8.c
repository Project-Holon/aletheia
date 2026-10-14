/*
 * function: MB_SEQ_SetActorVisible
 * address:  0x021C66B8
 * packet:   pkt_ov136_021C66B8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable        0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void MB_SEQ_SetActorVisible(u8 *p, int i, u32 v)
{
    CLACT_SetActorDrawEnable(*(void **)(p + i * 4 + 0x1F0), v);
}
