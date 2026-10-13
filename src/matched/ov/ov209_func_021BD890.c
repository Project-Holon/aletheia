/*
 * function: func_021BD890
 * address: 0x021BD890
 * packet: pkt_ov209_021BD890
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD86C 0x021BD86C thumb ov209
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BD86C(char *,int,int);struct Actor; struct Obj; extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned int);
void func_021BD890(char *p,int idx,int value) {func_021BD86C(p,idx,value);CLACT_SetActorAutoAnim((struct Obj *)*(struct Actor **)(p+idx*4+0xa74),1);}
