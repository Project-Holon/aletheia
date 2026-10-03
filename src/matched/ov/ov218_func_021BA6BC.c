/*
 * function: func_021BA6BC
 * address: 0x021BA6BC
 * packet: pkt_ov218_021BA6BC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;typedef unsigned int u32;
struct Actor;struct Obj;typedef struct PtS{s16 x,y;} PtS;extern void func_0204B454(struct Actor *,PtS *,u32);extern void func_0204B404(struct Obj *,const PtS *,u32);
void func_021BA6BC(char *p,int y){PtS pos;void *o=*(void **)(p+0x240);func_0204B454(o,&pos,65535);pos.y=y;func_0204B404(o,&pos,65535);}
