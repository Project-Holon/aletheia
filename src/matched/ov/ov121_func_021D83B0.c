/*
 * function: func_021D83B0
 * address: 0x021D83B0
 * packet: pkt_ov121_021D83B0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DA6D0 0x021DA6D0 thumb ov121
 *   func_021D6C84 0x021D6C84 thumb ov121
 */
extern int func_021DA6D0(unsigned char *);
extern void func_021D6C84(void *);
int func_021D83B0(char *p) {
 int n=func_021DA6D0(*(unsigned char **)(p+0x270));
 func_021D6C84(p+0x294);
 return n;
}
