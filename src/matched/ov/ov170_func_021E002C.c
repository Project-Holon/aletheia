/*
 * function: func_021E002C
 * address: 0x021E002C
 * packet: pkt_ov170_021E002C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DE5F8 0x021DE5F8 thumb ov170
 *   func_021DD930 0x021DD930 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u16 id,slot,src,used;int vx,vy;short dx,dy,x,y;} Entry;
extern void func_021DE5F8(u8 *,unsigned);
extern int func_021DD930(u8 *);
extern void func_021DE66C(char *,Entry *);
int func_021E002C(u8 *p){char *s;s=*(char **)(p+0x2c)+0x58;switch(*(u16 *)(s+12)){case 0:func_021DE5F8(p,p[0x16]);(*(u16 *)(s+12))++;case 1:if(func_021DD930(p)==0){func_021DE66C((char *)p,*(Entry **)(s+8));*(u16 *)(s+12)=0;return 0;}break;}return 1;}
