/*
 * function: func_021DF428
 * address: 0x021DF428
 * packet: pkt_ov183_021DF428
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave P6 lane U1b): EXACT. Types from matched ov183 021DF1DC (Menu: base
 * at +0xD0) and 021DF620 (State layout). Two fixes closed the earlier 24 B residue:
 * heap is a u16 parameter (it is only masked and passed to u16-style callees; the
 * narrow type moves its home store before mgr's), and the clamp is a ternary
 * `n = (n >= 5) ? 5 : n;` which gives n the lowest spill slot, under the loop temps.
 * Final call is an if/else with a call in each arm.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021DF838 0x021DF838 thumb ov183
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct State { u8 pad[0x14]; u16 shared0,shared1; u16 indices[5][6]; int cursor; void *sprites[5][6]; char *source; };
struct Pos { u16 x; short y; u16 z; u8 a,b; };
struct Entries { u32 species[6],form[6],gender[6]; };
extern void *func_020490F4(u32 id, u32 heap);
typedef signed int     s32;
struct Actor;
struct Obj;
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void MI_CpuFill8(void *,u32,u32);
extern void func_021DF838(int p, char *out);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32),POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021DF428(struct State *p,u32 mgr,u16 heap)
{
    int i,j;
    void *archive;
    u32 mode,species;
    int n;
    struct Entries e;
    struct Pos pos;
    n=*(int *)(p->source+0x1718);
    n=(n>=5)?5:n;
    mode=(heap&0x7fff)|0x8000;
    archive=func_020490F4(7,(u16)mode);
    i=0;
    p->shared0=CLACT_RegisterPaletteCompressed(archive,func_0201BC3C(),0,0x80,heap);
    p->shared1=CLACT_RegisterCellAnim(archive,func_0201BC40(),func_0201BCB4(),heap);
    MI_CpuFill8(&pos,0,8);
    pos.z=1;
    pos.a=i;
    pos.b=i;
    for(i=0;i<n;i++) {
        func_021DF838((int)(p->source+i*0xc4),(char *)(&e));
        for(j=0;j<6;j++) {
            species=e.species[j];
            if(species==0) species=1;
            p->indices[i][j]=CLACT_RegisterCharacter(archive,POKE_TOOL_CalcGraphicIndex(species,e.form[j],e.gender[j],0),0,0,heap);
            pos.x=j*0x18+0x6e;
            pos.y=i*0x18+0x48;
            pos.a=6-j;
            p->sprites[i][j]=CLACT_CreateActor((void *)mgr,p->indices[i][j],p->shared0,p->shared1,&pos,0,heap);
            CLACT_SetActorPaletteOffset(p->sprites[i][j],POKE_TOOL_CalcIconPalette(species,e.form[j],e.gender[j],0),0);
            CLACT_SetActorObjMode(p->sprites[i][j],1);
            if(e.species[j]==0) CLACT_SetActorDrawEnable(p->sprites[i][j],0);
            else CLACT_SetActorDrawEnable(p->sprites[i][j],1);
        }
    }
    ARC_TOOL_DeleteHandle(archive);
}
