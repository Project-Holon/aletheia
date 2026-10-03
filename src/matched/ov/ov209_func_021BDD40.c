/*
 * function: func_021BDD40
 * address: 0x021BDD40
 * packet: pkt_ov209_021BDD40
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named byte offset assigned before the base keeps offset in r5 and base in r4.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;extern void func_0204B3B4(struct Obj *);
void func_021BDD40(char *p,u32 idx) {char *base;u32 offset;offset=idx*4;base=p+0xa74;if(*(struct Obj **)(base+offset)) {func_0204B3B4(*(struct Obj **)(base+offset));*(struct Obj **)(base+offset)=0;}}
