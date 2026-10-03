/*
 * function: func_021FB738
 * address: 0x021FB738
 * packet: pkt_ov132_021FB738
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding follow the 58-byte body.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F95CC 0x021F95CC thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern int func_021FB1F4(char *,int);
extern void func_021F95CC(char *,unsigned char,int);
int func_021FB738(int unused,char *p) { char *obj; int mask; unsigned char i; obj=*(char **)p; mask=func_021FB1F4(p,func_0201134C(*(struct Cursor **)(p+4))); for(i=0;i<4;i++)if((1<<i)&mask)func_021F95CC(*(char **)(obj+0x34),i,1); return 0; }
