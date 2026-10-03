/*
 * function: func_021BCF38
 * address: 0x021BCF38
 * packet: pkt_ov110_021BCF38
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends in two-byte alignment padding at 0x021BCF6E.
 * symbols:
 *   func_021BCDFC 0x021BCDFC thumb ov110
 *   func_021BCE30 0x021BCE30 thumb ov110
 *   func_021BCE70 0x021BCE70 thumb ov110
 *   func_021BCEBC 0x021BCEBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BCDFC(char *);
extern int func_021BCE30(char *);
extern int func_021BCE70(char *);
extern int func_021BCEBC(char *);
int func_021BCF38(char *p,u32 mode) { switch(mode) { case 0: return func_021BCDFC(p); case 1: return func_021BCE30(p); case 2: return func_021BCE70(p); case 3: return func_021BCEBC(p); } return 1; }
