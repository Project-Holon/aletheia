/*
 * function: func_021FFA40
 * address: 0x021FFA40
 * packet: pkt_ov186_021FFA40
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D69B4 0x021D69B4 thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 */
extern int func_021D69B4(char *);extern void func_02034714(const char *,unsigned,const char *);extern void func_021FFB68(char *,int);extern void func_021FF8E4(void *,int,int);extern const char d_02200D98[];
void func_021FFA40(char *p,int unused,char *q) {if(!func_021D69B4(q))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}
