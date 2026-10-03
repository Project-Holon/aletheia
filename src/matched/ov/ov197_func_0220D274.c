/*
 * function: func_0220D274
 * address: 0x0220D274
 * packet: pkt_ov197_0220D274
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0220D848 0x0220D848 thumb ov197
 */
struct PrintSys;
extern unsigned func_0201C6B4(const struct PrintSys *);
extern void func_0220D848(char *,int);
int func_0220D274(char *p){if(func_0201C6B4(*(struct PrintSys **)(p+24))==1){func_0220D848(p,*(unsigned char *)(p+0x532));return *(unsigned char *)(p+0x531);}return 10;}
