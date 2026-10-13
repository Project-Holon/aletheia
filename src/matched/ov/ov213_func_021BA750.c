/*
 * function: func_021BA750
 * address: 0x021BA750
 * packet: pkt_ov213_021BA750
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BA71C 0x021BA71C thumb ov213
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 */
struct Obj;
extern void *func_021BA71C(char *p, int a, int b, unsigned short c);extern void func_0204B3DC(struct Obj *p, unsigned int v),CLACT_SetActorDrawPriority(void *,unsigned);
void *func_021BA750(void *p,int kind,unsigned a){int x,y;void *v;if(kind==0){x=206;y=152;}else{x=50;y=40;}v=func_021BA71C(p,x,y,a);func_0204B3DC(v,0);CLACT_SetActorDrawPriority(v,1);return v;}
