/*
 * function: FIELD_FK_DEMO_DrawProc
 * address: 0x021F3D54
 * packet: pkt_ov056_021F3D54
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
 *   FIELD_FK_DEMO_DrawModel 0x021F3D44 thumb
 */

void FIELD_FK_DEMO_DrawModel(char *a);
void FIELD_FK_DEMO_DrawProc(int a, int b, char **c);

/*
 * Addresses are Black-image addresses.
 */
void FIELD_FK_DEMO_DrawProc(int a, int b, char **c)
{
    FIELD_FK_DEMO_DrawModel(*c);
}
