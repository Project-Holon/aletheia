/*
 * function: func_021D84D4
 * address: 0x021D84D4
 * packet: pkt_ov121_021D84D4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wave D9r lane P7): real extent is 0x744 bytes (1860); the 2004-byte
 *   listing extent includes the filed follower func_021D8C1C. Compiled size now equals
 *   the original (1860 bytes); 1055 concrete bytes still differ, almost all from two
 *   small layout residues that shift every later branch target by 2 bytes.
 *   Fixed this wave (from the older draft in docs/notes/pkt_ov121_021D84D4.c.txt):
 *   frame 0x64 -> 0x68 and push {r3-r7} (clamp local zero, arc spilled to its slot,
 *   zero set after the 0202D8D0 statement so the scheduler hoists it next to the call);
 *   D(8) tested as if(D(8)!=0) first (gives the beq over a lone b stub);
 *   the desc[90] > 2 arm written A-first (if(v<=2) set(v); else {v=f(); set(v);}) gives
 *   the bhi over b with the tail cross-jumped; the H(30)==0 failure block written inline
 *   with the failed label inside it; ability default is mon=0; goto image (original
 *   skips the free); move[i] read as a raw u16 at base+i*2 gives add sp/adds #2/ldrh [r0,r1].
 *   Remaining residue: (1) the default arm and the H(74)==0 arm are single b stubs into
 *   the H(30) failure block in the original (b 3F2 and b 3EC); here the copies are not
 *   cross-jumped (default keeps movs r6 + b, H(74) is a plain beq); (2) 02017588's
 *   arguments load id before level in the original (ldr r2,[sp,#0x1c] then r1); (3) the
 *   0186C8 call argument order: original stores [sp,#4] before the zero high word
 *   [sp,#0x34] and loads r2 after the lsls; (4) str r7,[sp] (day) comes after the r2/r3
 *   setup before 0202F2AC in the original.
 *   Tried (about 18 compiles): u64 id local (worse, 1165), separate move array (worse),
 *   separate base local for 020185F0 (no change), pragma scheduling off (no change),
 *   H74 arm written out (merges only blx..b, +8 bytes), value arm B-first (no b stub).
 *   Idioms checked: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy
 *   (default/H74 stubs still not merged), a-shared-exit-block-is-written-out-in-each-arm
 *   (gave the D8 and value stubs), two-arms-write-the-tail-out-and-the-third-branches-back-into-one
 *   (H74 copy not merged), a-call-before-a-goto-into-the-shared-tail-is-cross-jumped-to-its-bl (no).
 *   Callee prototypes: 020185F0 returns its argument in r0 (stub bx lr), as in the older draft.
 *   Pragma check (per brief): opt_lifetimes off 994 B differ (1864 size), opt_propagation off 1719,
 *   opt_common_subs off 1422, opt_dead_assignments off 1055, peephole off 1055, scheduling off no change.
 *   None closes it, so none is filed. Total compiles this lane: 24.
 * note 2026-10-05 (wave D9r lane P7b): 1055 -> 32 concrete bytes differ (size 1864 = the
 *   real extent; the final literal 0x2CA at +0x744 is shared with the original). Fix: the H(74)==0
 *   arm is a written-out copy of the failure block, `if(H(74)==0){func_020307B0(allocated);mon=0;
 *   goto image;}`, not `goto failed` (the copy is cross-jumped into the b stub, the ability
 *   default arm then also becomes the b stub, as in the original; matched twin
 *   ov010_func_02157E9C does the same for its nick and OT-name arms). Also id is now a u64 local
 *   with a separate u32 otId (`id = otId;` before 020173F0), day is u8, as in that twin.
 *   Residue (all instruction-order, no register or slot difference): (1) 020173F0 loads r1 (level)
 *   before r2 (id); (2) 0186C8 arms: ldrb r2,[desc+0x1c] and the str [sp,4]/[sp,0x34] order;
 *   (3) str r7,[sp] (day) before the r2/r3 setup of 0202F2AC instead of last.
 *   Tried this lane (about 17 compiles, plus a static inline wrapper for 0202F2AC (identical)): `default: goto nomon;` with a label inside the
 *   H(30) block (mwcc hangs, killed), function-level labels (default becomes bls table; b, worse),
 *   020173F0 prototype with u16 level (adds lsls/lsrs, worse), u16 level local (slot order
 *   changes, worse), static inline wrapper for 020173F0 (identical output), passing otId
 *   instead of id (identical), 020186C8 third parameter u8 (identical), u8 day (identical),
 *   pragma scheduling off and peephole off (identical). Non-const desc fixes the ldrb placement
 *   in the 0186C8 arms but hoists str [sp,4] above the species load and moves the H(26) load in
 *   02017588 (36 bytes, not kept). Idioms checked: a-conditional-branch-onto-an-unconditional-b-
 *   is-a-cross-jumped-tail-copy (the written-out copy form closes the stubs), a-goto-join-loses-
 *   the-registers-that-repeating-the-tail-in-each-arm-keeps (goto failed loses the stub),
 *   an-inline-wrappers-arguments-are-evaluated-last-to-first (no change),
 *   an-inline-call-argument-is-scheduled-per-site-a-local-is-not (no change),
 *   a-jump-table-bounds-check-turns-into-bls-and-b-when-the-default-is-out-of-range (explains
 *   the default b stub being local).
 * note 2026-10-05 (wave D9r lane P7c): 32 -> 14 concrete bytes differ (size 1864). Fixes from
 *   the matched twins (ov010 02157E9C, ov121 021DD24C): (a) gender is u8, ability and selector
 *   u32 (twin locals; cleared the whole 0186C8 arm residue, 14 B); (b) 020173F0 is called as
 *   in 021DD24C with an explicit zero high word and a u16 level: proto (u16,u16,u32,u32,u32),
 *   call f(species,level,otId,0,tag), with `id=otId;` just before it (the u64 copy is only for
 *   02017588), and level and tag are u16 locals (this gave the original r2-before-r1 loads and
 *   the slot order; a u32 level or the 4-arg u64 form load r1 first).
 *   Remaining residue (one hunk, 2 instructions): `str r7,[sp]` (day) before the call to
 *   0202F2AC sits right after the bl of 020185F0 here; the original (and the twin) emit it
 *   last, after `adds r1,r6,#0`. Tried this lane (about 20 compiles, all no change unless
 *   noted): place as ternary, place inline in the call, u16 place, int w = D(172) date word,
 *   u32 day, day declared first, 0202F2AC proto with u8 day (same), proto u16,u16,u8,u8 (worse),
 *   day inline as (u8)D(172) (worse, 47), place before the date block (worse), day after place
 *   (worse), pragma scheduling off and peephole off (no change).
 *   Idioms checked: a-spilled-constant-high-word-is-a-u32-copied-into-a-u64-before-the-call
 *   (already applied: closed the id copy, and its twin gave the explicit-0 call form).
 * note 2026-10-05 (wave D9r lane P7d): CLOSED, EXACT* (c99 and c). 14 -> 0 B. The date
 *   year local is u32 (`u32 year;` with `year=(u16)((int)D(172)>>16)`), not u16: a spilled
 *   narrow local keeps its reload below the outgoing stack-argument store, a spilled u32
 *   local has its reload hoisted above it, so `str r7,[sp]` (day) now comes last, after
 *   `adds r1,r6,#0`, as in the original (docs/idioms/a-reload-kept-below-outgoing-stack-
 *   stores-is-a-narrow-local.md read the other way round). Compiles this lane: 3.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02049F34 0x02049F34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_020056EC 0x020056EC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008530 0x02008530 thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_SetupPartyParamEx 0x02017588 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_SetDefaultMoves 0x02017FA8 thumb
 *   POKE_TOOL_AddMove 0x0201808C thumb
 *   POKE_TOOL_PushMove 0x020180F4 thumb
 *   func_02018A00 0x02018A00 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020185F0 0x020185F0 thumb
 *   func_0202F2AC 0x0202F2AC thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   func_021D94C4 0x021D94C4 thumb ov121
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02020E60 0x02020E60 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_02082A48 0x02082A48 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_021DF4F2 0x021DF4F2 data a2
 *   d_021DF4FC 0x021DF4FC data a4
 *   GAME_VERSION_Code 0x0209DF08 data
 *   GAME_LANGUAGE_Code 0x0209DF0C data
 *   gSpeciesNameBank 0x020A7370 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct {s16 x,y,z;u8 a,b;} Point;
typedef struct {u8 iv[6];u16 move[4];Point point;void *resdesc;} Work;
extern void MI_CpuFill8(void *,int,int);
extern void *func_02049F34(u32,u32,u32,u32);
extern void func_02082D44(const void *,void *,int);
extern u32 func_020307B0(void *p);
struct Actor;
struct MsgBank;
struct Obj;
struct Sub0200852CObj;
struct U16Vec;
extern void *func_021D6C58(u8 *p, int i);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern u32 func_020056EC(u32);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void *POKE_TOOL_Create(u16,u16,u32,u32,u32);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);
struct Mon;
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 POKE_TOOL_SetDefaultMoves(void *);
extern u32 POKE_TOOL_AddMove(void *,u32);
extern void POKE_TOOL_PushMove(void *p, int move);
extern void func_02018A00(void *,u32,u32);
extern u16 STRBUF_GetEosChar(void);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_020185F0(void *);
extern void func_0202F2AC(void *,u32,u32,u32,u32);
extern void POKE_TOOL_RecalcParam(void *);
extern u32 func_02017E1C(void *,u32,u32);
extern int POKEGRA_OpenHandle(int);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int POKEGRA_RegisterPalettePP(int,void *,int,int,u16,u16);
extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);
extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);
extern unsigned func_021D94C4(int,int);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02020E60(u32 item, u32 which);
typedef signed int     s32;
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern void func_02082A48(u32,void *,u32);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern const u16 d_021DF4F2[];
extern const u32 d_021DF4FC[];
extern const u8 GAME_VERSION_Code,GAME_LANGUAGE_Code;
extern void *gSpeciesNameBank;
#define PALETTE ((void *)0x050003C0)
#define D(k) (*(u32 *)(desc+(k)))
#define H(k) (*(u16 *)(desc+(k)))
#define O(k) (*(u32 *)(out+(k)))
#define OH(k) (*(u16 *)(out+(k)))
void func_021D84D4(u8 *out,void *owner,const u8 *desc,void *save,void *list,void *a5,void *a6,u16 heap)
{
    u32 palette;
    void *buf,*mon,*allocated,*str;
    u8 *base;
    int i;
    u32 selector;
    Work work;
    u32 arc;
    u32 month;
    u32 year;
    u32 ability;
    u8 gender;
    int clamp;
    u64 random;
    u32 species,otId;
    u16 level,tag;
    u64 id;
    u32 packed,j,place,value;
    u8 day;
    MI_CpuFill8(out,0,300);
    O(40)=(u32)a6;O(36)=(u32)a5;OH(0)=heap;O(276)=(u32)desc;OH(296)=0;OH(298)=0;
    if(desc[714]) palette=3;
    else palette=d_021DF4F2[desc[179]];
    buf=func_02049F34(34,2,(u32)&work.resdesc,heap);
    base=*(u8 **)((u8 *)work.resdesc+12);
    func_02082D44(base,out+146,32);
    func_02082D44(base+palette*32,out+114,32);
    func_020307B0(buf);
    for(i=0;i<32;i++) CLACT_SetActorPaletteOffset(func_021D6C58(list,i+1),(u8)palette,0);
    switch(desc[179]) {
    case 1:
        mon=0;
        tag=(u16)((heap&0x7FFF)|0x8000);
        level=desc[91];otId=D(0);species=H(26);gender=desc[53];ability=desc[54];
        work.iv[0]=desc[67];work.iv[1]=desc[68];work.iv[2]=desc[69];
        work.iv[3]=desc[71];work.iv[4]=desc[72];work.iv[5]=desc[70];
        work.move[0]=H(18);work.move[1]=H(20);work.move[2]=H(22);work.move[3]=H(24);
        if(desc[179]!=1 || species>649 || species==0 || level>100 || H(16)>626) goto image;
        if(level==0) level=(u16)(func_020056EC(100)+1);
        if(D(0)==0) otId=func_02008530((const struct Sub0200852CObj *)func_02012944(save));
        if(gender==255) gender=2;
        for(i=0;i<6;i++) if(work.iv[i]==255) work.iv[i]=func_020056EC(32);
        id=otId;
        allocated=POKE_TOOL_Create(species,level,otId,0,tag);
        packed=(work.iv[0]&31)|((u32)work.iv[1]<<27>>22)|((u32)work.iv[2]<<27>>17)|
               ((u32)work.iv[3]<<27>>12)|((u32)work.iv[4]<<27>>7)|((u32)work.iv[5]<<27>>2);
        if(ability==4) ability=(u8)func_020056EC(3);
        switch(ability) {
        case 0:selector=0;break;
        case 1:selector=1;break;
        case 2:selector=0;break;
        case 3:selector=2;break;
        default:mon=0;goto image;
        }
        if(D(8)!=0) random=D(8);
        else {
            if(desc[55]==0) random=POKE_TOOL_CreatePersonalRnd(otId,(u16)species,desc[28],gender,selector,0);
            else if(desc[55]==1) random=POKE_TOOL_CreatePersonalRnd(otId,(u16)species,desc[28],gender,selector,2);
            else if(desc[55]==2) random=POKE_TOOL_CreatePersonalRnd(otId,(u16)species,desc[28],gender,selector,1);
        }
        POKE_TOOL_SetupPartyParamEx(allocated,H(26),level,id,packed,random);
        POKE_TOOL_SetPartyValue(allocated,6,H(16));POKE_TOOL_SetDefaultMoves(allocated);
        for(i=0;i<4;i++) {
            value=*(u16 *)((u8 *)&work.move[0]+i*2);
            if(value!=0 && value<560 && POKE_TOOL_AddMove(allocated,value)==65535) POKE_TOOL_PushMove(allocated,value);
        }
        if(D(8)==0 && ability==2) func_02018A00(allocated,species,desc[28]);
        POKE_TOOL_SetPartyValue(allocated,111,desc[28]);
        if(H(14)!=0 && H(14)<=25) POKE_TOOL_SetPartyValue(allocated,152,H(14));
        else POKE_TOOL_SetPartyValue(allocated,152,4);
        if(desc[60]!=0) POKE_TOOL_SetPartyValue(allocated,153,desc[60]);
        POKE_TOOL_SetPartyValue(allocated,19,desc[61]);POKE_TOOL_SetPartyValue(allocated,20,desc[62]);
        POKE_TOOL_SetPartyValue(allocated,21,desc[63]);POKE_TOOL_SetPartyValue(allocated,22,desc[64]);
        POKE_TOOL_SetPartyValue(allocated,23,desc[65]);POKE_TOOL_SetPartyValue(allocated,24,desc[65]);
        for(j=0;j<15;j++) if(H(12)&(1<<j)) POKE_TOOL_SetPartyValue(allocated,d_021DF4FC[j],1);
        if(D(4)==0) POKE_TOOL_SetPartyValue(allocated,119,GAME_VERSION_Code);
        else POKE_TOOL_SetPartyValue(allocated,119,D(4));
        if(desc[29]==0) POKE_TOOL_SetPartyValue(allocated,12,GAME_LANGUAGE_Code);
        else POKE_TOOL_SetPartyValue(allocated,12,desc[29]);
        if(H(30)==0) {
        failed: func_020307B0(allocated);
        nomon: mon=0;goto image;
        }
        if(H(30)!=STRBUF_GetEosChar()) POKE_TOOL_SetPartyValue(allocated,116,(u32)(desc+30));
        value=desc[52];
        if(value==255) value=(u8)func_020056EC(25);
        POKE_TOOL_SetPartyValue(allocated,112,value);
        POKE_TOOL_SetPartyValue(allocated,149,H(56));POKE_TOOL_SetPartyValue(allocated,150,H(58));
        if(H(74)==0) {func_020307B0(allocated);mon=0;goto image;}
        if(H(74)==STRBUF_GetEosChar()) POKE_TOOL_SetPartyValue(allocated,142,(u32)func_020084F4(func_02012944(save)));
        else POKE_TOOL_SetPartyValue(allocated,142,(u32)(desc+74));
        value=desc[90];
        if(value<=2) POKE_TOOL_SetPartyValue(allocated,154,value);
        else {value=func_02008550((const struct Sub0200852CObj *)func_02012944(save));POKE_TOOL_SetPartyValue(allocated,154,value);}
        if(desc[92]) {
            POKE_TOOL_SetPartyValue(allocated,76,1);
            str=func_02045EC0(gSpeciesNameBank,650);
            POKE_TOOL_SetPartyValue(allocated,115,(u32)str);
            STRBUF_Delete(str);POKE_TOOL_SetPartyValue(allocated,9,10);
        }
        year=(u16)((int)D(172)>>16);month=(u8)((int)D(172)>>8);day=(u8)D(172);
        if(desc[92]) place=H(56);else place=H(58);
        func_0202F2AC(func_020185F0(allocated),place,year-2000,month,day);
        POKE_TOOL_RecalcParam(allocated);
        if(func_02017E1C(allocated,3,0)!=0) {func_020307B0(allocated);mon=0;}
        else mon=allocated;
        goto image;
    image:
        arc=POKEGRA_OpenHandle(heap);
        O(12)=POKEGRA_RegisterPalettePP((int)arc,POKE_TOOL_GetBoxParam(mon),0,0,448,heap);
        clamp=0;
        O(20)=POKEGRA_RegisterCellAnimPP((u32)POKE_TOOL_GetBoxParam(mon),0,2,0,heap);
        O(16)=POKEGRA_RegisterCgrPP((int)arc,POKE_TOOL_GetBoxParam(mon),0,0,heap);
        OH(296)=func_021D94C4((int)POKE_TOOL_GetBoxParam(mon),heap)-48;
        if(*(s16 *)(out+296)>48) clamp=48;
        else if(*(s16 *)(out+296)>=0) clamp=*(s16 *)(out+296);
        OH(296)=clamp;
        ARC_TOOL_DeleteHandle((void *)arc);func_020307B0(mon);
        break;
    case 2:
        arc=(u32)func_020490F4(25,heap);
        O(12)=CLACT_RegisterPalette((void *)arc,func_02020E60((u16)D(0),2),0,448,heap);
        O(20)=CLACT_RegisterCellAnim((void *)arc,1,0,heap);
        O(16)=CLACT_RegisterCharacter((void *)arc,func_02020E60((u16)D(0),1),0,0,heap);
        ARC_TOOL_DeleteHandle((void *)arc);OH(298)=4;OH(296)=8;
        break;
    case 3:
        arc=(u32)func_020490F4(34,heap);
        O(12)=CLACT_RegisterPalette((void *)arc,3,0,448,heap);
        O(20)=CLACT_RegisterCellAnim((void *)arc,33,36,heap);
        O(16)=CLACT_RegisterCharacter((void *)arc,12,0,0,heap);
        ARC_TOOL_DeleteHandle((void *)arc);OH(296)=8;
        break;
    }
    if(desc[714]) {
        func_02082D44(PALETTE,out+242,32);
        func_02082A48(32767,PALETTE,32);
        func_02082D44(PALETTE,out+210,32);
    }
    MI_CpuFill8(&work.point,0,8);
    work.point.x=*(s16 *)(out+298)+128;work.point.y=-96;work.point.b=2;
    O(4)=(u32)CLACT_CreateActor((void *)((u32)owner),O(16),O(12),O(20),&work.point,0,heap);
    CLACT_SetActorDrawEnable((void *)O(4),0);
    if(desc[714]) CLACT_SetActorObjMode((void *)O(4),1);
}
