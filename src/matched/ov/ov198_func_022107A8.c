/*
 * function: func_022107A8
 * address: 0x022107A8
 * packet: pkt_ov198_022107A8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: write upper experience to the same field in both if/else arms;
 *   one common store or a switch removes the original two-byte branch.
 * 2026-10-04: filed src/matched/arm9/POKE_TOOL_GetLevelMinExp.c (EXACT, 8 bytes); needs the label registered by the integrator, then this resolves.
 * blocker: +0146 THM_CALL POKE_TOOL_GetLevelMinExp has no witness outside
 *   022107A8..0221099C. integrator-owned ARM9 Thumb tail stub, verified EXACT
 *   (8 bytes, 1/1 relocation resolved) in B9/blocker18544.log:
 *   typedef unsigned int u32;
 *   extern u32 POKE_TOOL_GetBoxLevelMinExp(void *);
 *   u32 POKE_TOOL_GetLevelMinExp(void *p) {return POKE_TOOL_GetBoxLevelMinExp(p);}
 *   symbols: POKE_TOOL_GetBoxLevelMinExp 0x0201854C thumb
 * symbols:
 *   func_02017E1C 0x02017E1C thumb
 *   POKE_TOOL_GetGender 0x02017F00 thumb
 *   func_020276C4 0x020276C4 thumb
 *   POKE_TOOL_GetLevelMinExp 0x02018544 thumb
 *   func_02018584 0x02018584 thumb
 *   WAZA_TOOL_GetMaxPP 0x0201C158 thumb
 *   sub_0201BD28 0x0201BD28 thumb
 *   WAZA_TOOL_IsAlwaysHit 0x0201C1F4 thumb
 * 020276C4's matched legacy C has unused a1/a2/a3 parameters; this caller
 * and the callee body use only a0, so its declaration here has one argument.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Move {u16 id;u8 pp,up,kind,power,type,accuracy;};
struct Summary {
    void *mon;
    u16 species,hp,attack,defense,speed,stat6,spatk,spdef;
    u8 ability,form;
    u8 level:7,egg:1;
    u8 gender:3,nature:4,flag:1;
    u16 item,unknown;
    u32 exp,lower,upper,personality;
    struct Move moves[4];
};
extern u32 func_02017E1C(void *,u32,u32);
extern u8 POKE_TOOL_GetGender(void *);
extern int func_020276C4(int a0);
extern u32 POKE_TOOL_GetLevelMinExp(void *);
extern u32 func_02018584(u16,u16,u16);
extern u8 WAZA_TOOL_GetMaxPP(u16,u32);
extern u32 sub_0201BD28(u16,u32);
extern u32 WAZA_TOOL_IsAlwaysHit(u16);
void func_022107A8(void *unused,void *mon,struct Summary *p)
{
    u32 exp;
    unsigned i;
    struct Move *move;
    struct Move *moves;
    p->mon=mon;
    if(mon==0) {
        p->species=0;
        return;
    }
    p->species=func_02017E1C(mon,5,0);
    if(p->species==0) return;
    p->hp=func_02017E1C(p->mon,0xa2,0);
    p->attack=func_02017E1C(p->mon,0xa3,0);
    p->defense=func_02017E1C(p->mon,0xa4,0);
    p->speed=func_02017E1C(p->mon,0xa5,0);
    p->stat6=func_02017E1C(p->mon,0xa6,0);
    p->spatk=func_02017E1C(p->mon,0xa0,0);
    p->spdef=func_02017E1C(p->mon,0xa1,0);
    p->ability=func_02017E1C(p->mon,0xae,0);
    p->form=func_02017E1C(p->mon,0xaf,0);
    p->level=(u8)func_02017E1C(p->mon,0x9e,0);
    if(func_02017E1C(p->mon,0xad,0)==1) p->egg=0;
    else p->egg=1;
    p->gender=POKE_TOOL_GetGender(p->mon);
    p->nature=(u8)func_020276C4((int)p->mon);
    p->flag=(u8)func_02017E1C(p->mon,0x4c,0);
    p->item=func_02017E1C(p->mon,10,0);
    p->unknown=func_02017E1C(p->mon,6,0);
    p->personality=func_02017E1C(p->mon,0x6f,0);
    p->exp=func_02017E1C(p->mon,8,0);
    exp=POKE_TOOL_GetLevelMinExp(p->mon);
    p->lower=exp;
    if(p->level==100) p->upper=p->lower;
    else p->upper=func_02018584(p->species,(u16)p->personality,(u16)(p->level+1));
    i=0;
    moves=p->moves;
    for(;i<4;i++) {
        move=&moves[i];
        moves[i].id=func_02017E1C(p->mon,i+0x36,0);
        if(moves[i].id==0) continue;
        move->pp=func_02017E1C(p->mon,i+0x3a,0);
        move->up=func_02017E1C(p->mon,i+0x3e,0);
        move->up=WAZA_TOOL_GetMaxPP(move->id,move->up);
        move->kind=sub_0201BD28(move->id,0);
        move->power=sub_0201BD28(move->id,2);
        if(WAZA_TOOL_IsAlwaysHit(move->id)==1) move->type=0;
        else move->type=sub_0201BD28(move->id,4);
        move->accuracy=sub_0201BD28(move->id,3);
    }
}
