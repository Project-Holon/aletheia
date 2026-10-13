/*
 * function: FIELD_FK_DEMO_DrawModel
 * address: 0x021F3D44
 * packet: pkt_ov056_021F3D44
 * region: ov056
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov056/unit_021F36C0.c and filed here.
 *
 * symbols:
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 */

extern void G3D_SYSTEM_DrawObject(void *, void *);
void FIELD_FK_DEMO_DrawModel(char *a);

/*
 * note:     heap is u16: the original passes r2 straight to the stack slot
 *           of FIELD_FK_SOUND_ANIME_Create's u16 parameter (an int heap adds lsls/lsrs).
 */
void FIELD_FK_DEMO_DrawModel(char *a)
{
    G3D_SYSTEM_DrawObject(*(void **)(a + 0x1c), a + 0x20);
}
