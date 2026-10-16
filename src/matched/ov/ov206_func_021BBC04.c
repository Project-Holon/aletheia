/*
 * function: ZUKAN_INFO_DisableUnselected
 * address: 0x021BBC04
 * packet: pkt_ov206_021BBC04
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 */
typedef unsigned char u8;
typedef struct S {
    char pad0[0x174];
    void *a[2];
    char padx[0xc];
    void *b[2];
    int sel;
} S;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
void ZUKAN_INFO_DisableUnselected(S *p)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (i != p->sel && p->b[i] != 0)
            CLACT_SetActorDrawEnable(p->b[i], 0);
    }
}
