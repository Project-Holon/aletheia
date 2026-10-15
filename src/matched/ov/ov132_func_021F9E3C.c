/*
 * function: STA_ACTING_SetField10
 * address: 0x021F9E3C
 * packet: pkt_ov132_021F9E20
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: leaf called from script_command.c (ov132).
 */
void STA_ACTING_SetField10(char *p, unsigned int v) { *(unsigned int *)(p + 0x10) = v; }
