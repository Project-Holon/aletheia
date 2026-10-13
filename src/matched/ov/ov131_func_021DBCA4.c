/*
 * function: P_STA_OAM_SetBitmapActorsEnabled
 * address: 0x021DBCA4
 * packet: pkt_ov131_021DBCA4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void P_STA_OAM_SetBitmapActorsEnabled(u8 *p, int v)
{
    u8 i, j;
    for (i = 0; i < p[0x23]; i++) {
        for (j = 0; j < p[0x22]; j++) {
            CLACT_SetActorDrawEnable(*(void **)(p + 4 + (j + i * p[0x22]) * 4), v);
        }
    }
}
