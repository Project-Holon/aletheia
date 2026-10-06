/*
 * function: func_021DDCEC
 * address: 0x021DDCEC
 * packet: pkt_ov137_021DDCEC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original r0 holds p at the call to func_021DD924; retain that
 * explicit input despite the pending empty callee's no-argument declaration.
 * symbols:
 *   func_021DD924 0x021DD924 thumb ov137
 *   func_021DD93C 0x021DD93C thumb ov137
 *   func_021DE4B4 0x021DE4B4 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DD924(char *p);
extern void func_021DD93C(char *,int);
extern void func_021DE4B4(char *,int,int);
int func_021DDCEC(char *p,int state) {func_021DE4B4(p,5,0);func_021DD93C(p,10);func_021DD924(p);return state;}
