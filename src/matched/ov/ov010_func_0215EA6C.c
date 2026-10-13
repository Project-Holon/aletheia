/*
 * function: MOVE_POKEMON_CreateCutEvent
 * address: 0x0215EA6C
 * packet: pkt_ov010_0215EA6C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   MOVE_POKEMON_InitSkillWork 0x0215F0E8 thumb ov010
 *   MOVE_POKEMON_CutEventMain 0x0215EA94 thumb ov010
 */
#include "../include/Obj02057.h"
typedef unsigned int   u32;
struct Desc;
struct Obj;
struct Pair;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MOVE_POKEMON_InitSkillWork(u32 *out, const struct Pair *in, u32 *ctx);
extern int MOVE_POKEMON_CutEventMain(void *,void *,void *);
void *MOVE_POKEMON_CreateCutEvent(void *a,void *b)
{
 void *t = func_020122C0(((struct Obj02057 *)b)->f8,0,MOVE_POKEMON_CutEventMain,20);
 MOVE_POKEMON_InitSkillWork(func_020124E8(t),a,b);
 return t;
}
