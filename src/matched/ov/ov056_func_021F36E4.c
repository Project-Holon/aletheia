/*
 * function: FIELD_FK_DEMO_UploadModelTask
 * address:  0x021F36E4
 * packet:   pkt_ov056_021F36E4
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf: forwards the second argument plus 0x3c.
 *
 * symbols:
 *   FIELD_FK_DEMO_UploadModelOnce  0x021F3D2C  thumb  ov056
 */

typedef unsigned char u8;

extern void FIELD_FK_DEMO_UploadModelOnce(u8 *p);

void FIELD_FK_DEMO_UploadModelTask(u8 *a, u8 *b)
{
    FIELD_FK_DEMO_UploadModelOnce(b + 0x3c);
}
