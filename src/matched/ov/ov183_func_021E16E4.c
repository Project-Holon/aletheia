/*
 * function: func_021E16E4
 * address: 0x021E16E4
 * packet: pkt_ov183_021E16E4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E3858 0x021E3858 data a4
 *   func_021E0D90 0x021E0D90 thumb ov183
 */
extern int (*const d_021E3858[])(char *);
extern void func_021E0D90(char *);
int func_021E16E4(char *p){ int r=d_021E3858[*(int *)(p+0x22c)](p); func_021E0D90(p); return r; }
