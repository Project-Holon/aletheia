/*
 * function: func_021BAB0C
 * address: 0x021BAB0C
 * packet: pkt_ov214_021BAB0C
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201BC3C 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int f0;u32 f4;int f8,fC,f10,f14,f18;u8 b1c,b1d,b1e;} In;
extern int func_0201BC3C(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern void UI_SCENE_LoadActorGfx(void*,In*,int,u16);
extern int UI_SCENE_CreateActor(void*,int,u16,u16,u8,u16);
extern void CLACT_SetActorBgPriority(int,u32);
struct Node;
struct Obj;
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
struct Obj;
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
int func_021BAB0C(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m)
{
    In in;
    int actor;
    in.f0=c;
    in.f4=1;
    in.f8=7;
    in.fC=func_0201BC3C();
    in.f10=POKE_TOOL_CalcGraphicIndex(e,f,g,h);
    in.f14=func_0201BC40();
    in.f18=func_0201BCB4();
    in.b1c=d;
    in.b1d=0;
    in.b1e=3;
    UI_SCENE_LoadActorGfx(x,&in,a,b);
    actor=UI_SCENE_CreateActor(x,a,i,j,k,b);
    CLACT_SetActorBgPriority(actor,l);
    CLACT_SetActorDrawPriority((struct Node *)actor,m);
    CLACT_SetActorAutoAnim((struct Obj *)actor,1);
    CLACT_SetActorPaletteOffset((struct Obj *)actor,POKE_TOOL_CalcIconPalette(e,f,g,h),0);
    return actor;
}
