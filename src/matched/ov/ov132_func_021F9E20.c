/*
 * function: func_021F9E20
 * address: 0x021F9E20
 * packet: pkt_ov132_021F9E20
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: leaf called from script_command.c (ov132).
 */
unsigned char func_021F9E20(char *p, unsigned int i) { return *(unsigned short *)(((char **)(*(char **)(p + 0x30) + i * 4))[1] + 0x4A); }
