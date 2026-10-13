/*
 * function: func_0216EFF0
 * address: 0x0216EFF0
 * packet: pkt_ov010_0216EFF0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * func_0202C83C's body consumes only r0/r1, forwarding those to
 * func_0202C794; original supplies no new r2/r3. Legacy trailing
 * arguments are omitted. func_02012AC8 consumes the preceding result.
 * symbols:
 *   GAME_DATA_SetFieldMode 0x02012A4C thumb
 *   func_0215E5B0 0x0215E5B0 thumb ov010
 *   func_0216EE7C 0x0216EE7C thumb ov010
 *   func_0216EF84 0x0216EF84 thumb ov010
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_0202C83C 0x0202C83C thumb
 */
#include "../include/Obj00020.h"
#include "../include/Obj19144.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
struct Rec44;
struct SaveBlock;
extern void GAME_DATA_SetFieldMode(struct BigObj *p, u32 v);
struct BattleEndCtx;
struct Work;
extern void func_0215E5B0(void *a0, struct Work *w);
extern void func_0216EE7C(struct BattleEndCtx *c);
extern int func_0216EF84(int a0);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern int func_0202C83C(int,int);
void func_0216EFF0(int *p,void *a) {
    GAME_DATA_SetFieldMode(a,((struct Obj19144 *)(*(char * *)&((struct Obj00020 *)p)->f8))->f8C);
    func_0215E5B0(a,(void *)p[2]);
    func_0216EE7C((struct BattleEndCtx *)p);
    func_0216EF84((int)p);
    func_0202C83C(p[0],func_02012AC8(func_020127A4(a)));
}
