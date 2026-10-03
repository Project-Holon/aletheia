/*
 * function: func_021BDDF4
 * address: 0x021BDDF4
 * packet: pkt_ov099_021BDDF4
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 */
extern int func_021BCB70(int,int,int *);
extern int func_021BCBBC(int,int,int *);
int func_021BDDF4(char *p) {
 int out;
 if (func_021BCB70(*(int *)(p+0x1348),*(int *)(p+0xc4),&out) && func_021BCBBC(*(int *)(p+0x1348),*(int *)(p+0xcc),&out)) return 0;
 return 1;
}
