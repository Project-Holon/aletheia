/*
 * function: func_0220D848
 * address: 0x0220D848
 * packet: pkt_ov197_0220D848
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220D7F0 0x0220D7F0 thumb ov197
 *   func_02041570 0x02041570 arm
 *   func_0220B990 0x0220B990 thumb ov197
 *   func_0220BD24 0x0220BD24 thumb ov197
 *   func_0220D924 0x0220D924 thumb ov197
 *   func_0220C4EC 0x0220C4EC thumb ov197
 */
typedef unsigned short u16;
extern void func_0220D7F0(void *,int);
extern void func_02041570(int channel, u16 val);
extern void func_0220BD24(char *,int);
extern void func_0220D924(unsigned char *,int,int);
extern void func_0220C4EC(char *,int);
extern unsigned func_0220B990(unsigned char *);
void func_0220D848(char *p,int mode){func_0220D7F0(p,mode);func_02041570(4,0);func_02041570(5,0);func_0220B990((unsigned char *)p);func_0220BD24(p,mode);func_0220D924((unsigned char *)p,mode,0);func_0220C4EC(p,mode);}
