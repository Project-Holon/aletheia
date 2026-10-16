/*
 * function: ZUKAN_INFO_SetActors
 * address:  0x021BB13C
 * packet:   pkt_021BB13C
 * region:   ov206
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_INFO_RegisterGfx 0x021BB184 thumb
 *   ZUKAN_INFO_CreateActor 0x021BB23C thumb
 *   ZUKAN_INFO_DisableActors 0x021BB2D4 thumb
 */

extern void ZUKAN_INFO_RegisterGfx(char *p, int index);
extern void ZUKAN_INFO_CreateActor(char *p, int x, int y, int index);
extern void ZUKAN_INFO_DisableActors(char *p);

void ZUKAN_INFO_SetActors(void *a0, void *a1, void *a2, void *a3)
{
    ZUKAN_INFO_RegisterGfx(a0, (int)a3);
    ZUKAN_INFO_CreateActor(a0, (int)a1, (int)a2, (int)a3);
    ZUKAN_INFO_DisableActors(a0);
}
