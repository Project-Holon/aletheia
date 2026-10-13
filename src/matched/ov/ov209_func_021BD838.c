/*
 * function: func_021BD838
 * address: 0x021BD838
 * packet: pkt_ov209_021BD838
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Actor;struct Obj;extern u32 CLACT_GetActorAutoAnim(struct Actor *);extern void CLACT_AddActorAnimFrame(struct Obj *,u32);extern void CLACT_DrawSystem(void);
void func_021BD838(char *p) {u32 i;for(i=0;i<60;i++) {if(*(void **)(p+i*4+0xa74)) {if(CLACT_GetActorAutoAnim(*(struct Actor **)(p+i*4+0xa74))!=1) CLACT_AddActorAnimFrame(*(struct Obj **)(p+i*4+0xa74),0x1000);}}CLACT_DrawSystem();}
