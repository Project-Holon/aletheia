/*
 * function: func_021EC060
 * address: 0x021EC060
 * packet: pkt_ov170_021EC060
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B688 0x0204B688 arm
 */
typedef unsigned int   u32;
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);
void func_021EC060(char *p,unsigned i,int b){if(b==1)func_0204B688(*(void **)((unsigned)p+i*4+0x9e74),1);else func_0204B688(*(void **)((unsigned)p+i*4+0x9e74),0);}
