/*
 * function: STA_ACTING_GetBonus
 * address: 0x021F9E34
 * packet: pkt_ov132_021F9E20
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: leaf called from script_command.c (ov132).
 */
unsigned char STA_ACTING_GetBonus(char *p, unsigned int i) { return *(unsigned char *)(p + i + 0xF7); }
