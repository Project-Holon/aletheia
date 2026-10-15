/*
 * function: MYSTERY_CardMenuCallback
 * address: 0x021D83CC
 * packet: pkt_ov121_021D83CC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole callback blocker of 021D81B0; root claim granted.
 * symbols:
 *   MYSTERY_ResetActorAngle 0x021D6CEC thumb ov121
 */
typedef unsigned char  u8;
extern void MYSTERY_ResetActorAngle(u8 *p);
void MYSTERY_CardMenuCallback(char *p)
{
    MYSTERY_ResetActorAngle((u8 *)(p+660));
}
