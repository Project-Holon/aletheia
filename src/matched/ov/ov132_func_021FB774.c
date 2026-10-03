/*
 * function: func_021FB774
 * address: 0x021FB774
 * packet: pkt_ov132_021FB774
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F95CC 0x021F95CC thumb ov132
 */
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
extern void func_021F95CC(char *,unsigned char,int);
int func_021FB774(int unused,char *p) { char *obj; obj=*(char **)p; func_021F95CC(*(char **)(obj+0x34),0,0);func_021F95CC(*(char **)(obj+0x34),1,0);func_021F95CC(*(char **)(obj+0x34),2,0);func_021F95CC(*(char **)(obj+0x34),3,0);return 0; }
