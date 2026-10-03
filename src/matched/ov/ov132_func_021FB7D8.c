/*
 * function: func_021FB7D8
 * address: 0x021FB7D8
 * packet: pkt_ov132_021FB7D8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021FB1F4 0x021FB1F4 thumb ov132
 *   func_021F91A8 0x021F91A8 thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern int func_021FB1F4(char *,int);
extern void func_021F91A8(unsigned char *,unsigned char,unsigned char);
int func_021FB7D8(int unused,char *p) { char *obj; int mask; unsigned int n; obj=*(char **)p;mask=func_021FB1F4(p,func_0201134C(*(struct Cursor **)(p+4)));n=func_0201134C(*(struct Cursor **)(p+4));func_021F91A8(*(unsigned char **)(obj+0x34),n,mask);return 0; }
