/*
 * function: CDEMO_SCENE_CmdPlayFanfare
 * address:  0x021B6888
 * packet:   pkt_021B6888
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 12-byte leaf: forwards the second word of the record to GFL_USE_PlayFanfare and
 * returns 1.  The lane enumerator reports 664 bytes because this is the last
 * func_ label in ov179; the disassembly ends at the pop and the rest is data.
 *
 * symbols:
 *   GFL_USE_PlayFanfare  0x02005DAC  thumb  arm9
 */

extern void GFL_USE_PlayFanfare(void *arg);

int CDEMO_SCENE_CmdPlayFanfare(void *ctx, unsigned int *rec)
{
    GFL_USE_PlayFanfare((void *)rec[1]);
    return 1;
}
