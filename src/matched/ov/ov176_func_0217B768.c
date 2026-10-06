/*
 * function: func_0217B768
 * address: 0x0217B768
 * packet: pkt_ov176_0217B768
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0217B93C 0x0217B93C thumb ov176
 *   func_0217B964 0x0217B964 thumb ov176
 *   func_0217B6AC 0x0217B6AC thumb ov176
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0217B93C(int *,int);
extern int func_0217B964(int *p);
extern void func_0217B6AC(int p, unsigned *state, int *q);
extern void func_021E8AA0(int *,int);
void func_0217B768(int *p,int *state,u8 *q) {switch(*state) {case 0:func_0217B93C((int *)q,15);*state=1;break;case 1:if(func_0217B964((int *)q)==1) func_021E8AA0(p,(int)func_0217B6AC);break;}}
