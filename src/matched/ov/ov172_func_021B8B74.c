/*
 * function: CTVT_COMM_IsPostBusy
 * address: 0x021B8B74
 * packet: pkt_ov172_021B8B74
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Return the word at +0x194 of the record. Filed as the call witness for
 * ov172 CTVT_TALK_UpdateVoiceSend.
 */
typedef unsigned char u8;
typedef unsigned int u32;

int CTVT_COMM_IsPostBusy(void *ctx, u8 *rec)
{
    return *(u32 *)(rec + 0x194);
}
