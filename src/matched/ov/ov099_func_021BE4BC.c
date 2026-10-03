/*
 * function: func_021BE4BC
 * address: 0x021BE4BC
 * packet: pkt_ov099_021BE4BC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BE4EA.
 * symbols:
 *   func_021BE448 0x021BE448 thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 */
extern int func_021BE448(unsigned int,int);
extern void func_021BE3CC(char *,int,int,int,int,int);
void func_021BE4BC(char *p,int a,int b,int c,int d,unsigned int e,int f) {
 int value;
 value=func_021BE448(e,d);
 func_021BE3CC(p,a,b,c,value+f,0);
}
