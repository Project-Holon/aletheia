/*
 * function: func_021B7BC0
 * address: 0x021B7BC0
 * packet: pkt_ov105_021B7BC0
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes after the return, before 021B7C04.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
struct Bank;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,int);
void func_021B7BC0(void **p) {
 int i;
 for(i=0;i<38;i++) if(p[i+4]) func_0204B3B4(p[i+4]);
 func_0204ADA4(p[1]); func_0204A8D4(p[2]); func_0204AFD8(p[3]);
 func_0204B1CC(p[0]); func_0204A5AC(); func_02082BCC(p,0,0xa8);
}
