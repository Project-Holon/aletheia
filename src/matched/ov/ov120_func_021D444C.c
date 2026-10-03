/*
 * function: func_021D444C
 * address: 0x021D444C
 * packet: pkt_ov120_021D444C
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02028218 0x02028218 thumb
 *   func_021D43BC 0x021D43BC thumb ov120
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_02028218(struct Obj *,u32);
extern int func_021D43BC(int,char *);
int func_021D444C(int n,char *p) { int result; if(*(struct Obj **)(p+0x34)) func_02028218(*(struct Obj **)(p+0x34),0); result=func_021D43BC(n,p); if(result) *(int *)(p+0x160)=result; return 1; }
