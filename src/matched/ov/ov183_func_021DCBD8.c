/*
 * function: BR_CODEIN_RecordSetupActors
 * address: 0x021DCBD8
 * packet: pkt_ov183_021DCBD8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05: re-run, bytes identical to the original; the only unresolved relocation is the BL to arm9 0x0200B98C (Thumb, 64 bytes, no code-start label, no asm/arm9 witness). Integrator: seed a label at 0x0200B98C; no source change needed.
 * blocker: 0x0200B98C arm9 thumb, no witness outside caller; prior verified Thumb EXACT copied from BR_CODEIN_SearchBuildHeader.c; not recompiled (integrator-owned ARM9).
 * blocker-symbols: BattleRecModeTable 0x0209DDCC data a4
 *   typedef unsigned char u8;
 *   typedef unsigned short u16;
 *   typedef unsigned long long u64;
 *   extern const u16 BattleRecModeTable[];
 *   u64 BATTLE_REC_GetHeaderParam(char *p, int selector, int index)
 *   {
 *       int i;
 *       u16 v;
 *       switch (selector) {
 *       case 0:
 *           v = ((u16 *)p)[index];
 *           if (v > 0x289) return 0;
 *           return v;
 *       case 1:
 *           return *(u8 *)(p + index + 0x18) & 0x7F;
 *       case 2:
 *           v = *(u16 *)(p + 0x24);
 *           if (v > 0x270F) return 0x270F;
 *           return v;
 *       case 3:
 *           for (i = 0; i < 0x29; i++) {
 *               if (*(u16 *)(p + 0x26) == BattleRecModeTable[i]) return i;
 *           }
 *           return 0;
 *       case 4:
 *           return *(u64 *)(p + 0x38);
 *       case 5:
 *           return *(u8 *)(p + 0x2A);
 *       case 6:
 *           return (*(u8 *)(p + index + 0x18) & 0x80) >> 7;
 *       case 7:
 *           return *(u8 *)(p + 0x2B);
 *       default:
 *           return 0;
 *       }
 *   }
 * lever: swapped start/end declaration homes, then zeroed phase-two j before coords assignment; DIFF16 to4 to MATCH.
 * checks: 1 own ARM9 and matched caller arities re-derived; B98C original shown, 3 args/u64, DD228 shown 1 arg; 2 F838 and F620/DE084 twins reread; 3 codegen became MATCH in3 runs, further type probes unnecessary; 4 counter-before-base/declared-struct idioms read; 5 fresh directory/neighbors reread before handoff; prior permuter300 not repeated.
 * TU: cbd8-tu.log terminal exit0, MATCH, three B98C wildcards at +009A/+00A6/+00B2, no viable split.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   BR_CODEIN_RecordIsType1 0x021DD228 thumb ov183
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   d_021E32F0 0x021E32F0 data a2
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;
typedef struct {s16 x,y,z;u8 a,b;} Position;
typedef struct {s16 x,y;} Pair;
typedef signed int     s32;
struct Actor;
struct Obj;
extern void *func_020490F4(u32 id, u32 heap);
extern int POKE_TOOL_GetIconPaletteArcId(void),POKE_TOOL_GetIconCellArcId(void),POKE_TOOL_GetIconCellEntryId(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int BR_CODEIN_RecordIsType1(void *);
extern unsigned long long BATTLE_REC_GetHeaderParam(u8 *p, int selector, int index);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32),POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void MI_CpuFill8(void *,int,unsigned);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void ARC_TOOL_DeleteHandle(void *);
extern const Pair d_021E32F0[];
void BR_CODEIN_RecordSetupActors(char *p,void *manager,void *party,u16 heap)
{
    u32 species[12],forms[12],half[12];
    Position pos;
    u32 v,f,h;
    int count=0;
    int mode;
    void *archive;
    int step;
    int i;
    int start;
    int n;
    int end;
    const Pair *coords;
    char *slot;
    int mapping;
    archive=func_020490F4(7,(u16)((heap&0x7fff)|0x8000));
    *(void **)(p+0x48)=(void *)CLACT_RegisterPaletteCompressed(archive,POKE_TOOL_GetIconPaletteArcId(),0,128,heap);
    mapping=POKE_TOOL_GetIconCellArcId();
    *(void **)(p+0x4c)=(void *)CLACT_RegisterCellAnim(archive,mapping,POKE_TOOL_GetIconCellEntryId(),heap);
    n=0;
    step=6;start=0;end=6;mode=0;
    if(BR_CODEIN_RecordIsType1(party)==1) {step=3;end=3;mode=1;}
    do {
        for(i=start;i<end;i++) {
            species[n]=255;
            v=BATTLE_REC_GetHeaderParam(party,0,i);
            f=BATTLE_REC_GetHeaderParam(party,1,i);
            h=BATTLE_REC_GetHeaderParam(party,6,i);
            if(v) {species[n]=v;forms[n]=f;half[n]=h;n++;}
        }
        for(i=n;i<end;i++) {species[n]=0;forms[n]=0;half[n]=0;n++;}
        start+=step;end+=step;
    } while(end<=12);
    {
    int j;
    u32 h2,f2,v2;
    j=0;
    coords=(const Pair *)((u32)d_021E32F0+(int)mode*48);
    for(;j<12;j++) {
        slot=p+j*4;
        *(void **)(slot+0x80)=0;
        *(u32 *)(slot+0x50)=-1;
        v2=species[j];
        if(v2) {
            h2=half[j];f2=forms[j];
            *(u32 *)(slot+0x50)=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(v2,f2,h2,0),0,0,heap);
            MI_CpuFill8(&pos,0,8);
            pos.x=coords[j].x+8;pos.y=coords[j].y-12;pos.z=1;pos.a=12-count;
            *(void **)(p+count*4+0x80)=CLACT_CreateActor(manager,(u32)(*(void **)(slot+0x50)),(u32)(*(void **)(p+0x48)),(u32)(*(void **)(p+0x4c)),&pos,0,heap);
            CLACT_SetActorObjMode(*(void **)(count*4+p+0x80),1);
            CLACT_SetActorPaletteOffset(*(void **)(p+count*4+0x80),POKE_TOOL_CalcIconPalette(v2,f2,h2,0),0);
            count++;
        }
    }
    }
    ARC_TOOL_DeleteHandle(archive);
}
