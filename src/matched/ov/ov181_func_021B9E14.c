/*
 * function: STAFF_ROLL_Init3d
 * address: 0x021B9E14
 * packet: pkt_ov181_021B9E14
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: data relocation at +0xf4 names ARM9 020A1EB8, the +0x80
 *   interior of known d_020A1E38. Both direct and base-plus-offset declarations
 *   compile concrete-identically but no outside witness resolves that pool word.
 * volatile: 021B9EC4 reads and 021B9ECC writes 0x04000060 DISP3DCNT.
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_GetObjectAnimeCount 0x0204779C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_LIGHT_CreateSlots 0x02048BC4 arm
 *   G3D_LIGHT_ApplySlots 0x02048C58 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   BG_SYS_EnableBg0WithPriority 0x0204044C arm
 *   STAFF_ROLL_InitLights 0x021B9F9C thumb ov181
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G2x_SetBlendBrightness_ 0x0207D658 arm
 *   d_021BAB50 0x021BAB50 data a4
 *   d_021BAB38 0x021BAB38 data a4
 *   d_021BAC68 0x021BAC68 data a4
 *   d_021BACE4 0x021BACE4 data a4
 *   d_021BACF0 0x021BACF0 data a4
 *   d_020A1E38 0x020A1E38 data a2
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef struct { u32 x,y,z; } Vec3;
struct Util; struct Setup; struct LightSet; struct LightSlot; struct Light; struct G3dSys;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct Util *G3D_UTIL_Create(u16,u16,u16);
extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);
extern u32 func_02048A18(u8 *,int);
extern int G3D_SYSTEM_GetObjectAnimeCount(int *);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern struct LightSlot *G3D_LIGHT_CreateSlots(const struct LightSet *,u32);
extern void G3D_LIGHT_ApplySlots(struct LightSlot *);
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec3 *,Vec3 *,Vec3 *,u16);
extern void G3D_CAMERA_Reset(struct Light *);
extern void BG_SYS_EnableBg0WithPriority(u32);
extern void STAFF_ROLL_InitLights(u8 *p);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void G2x_SetBlendBrightness_(u32,int,int);
extern const struct Setup d_021BAB50;
extern const struct LightSet d_021BAB38;
extern const Vec3 d_021BAC68;
extern Vec3 d_021BACE4,d_021BACF0;
extern const u8 d_020A1E38[];
static inline void AntiAlias(int enable) {
    u32 tmp=*(volatile u16 *)0x04000060 & ~0x3000;
    if(enable) tmp|=0x10;
    else tmp&=~0x10;
    *(volatile u16 *)0x04000060=(u16)tmp;
}
void STAFF_ROLL_Init3d(char *p) {
    Vec3 v;
    u32 i;
    G3D_SYSTEM_Init(0,2,0,2,4096,142,0);
    *(struct Util **)(p+8)=G3D_UTIL_Create(3,1,142);
    *(u16 *)(p+0x18)=G3D_UTIL_AddUnit(*(struct Util **)(p+8),&d_021BAB50);
    *(u32 *)(p+0x20)=func_02048A18(*(u8 **)(p+8),*(u16 *)(p+0x18));
    *(u32 *)(p+0x24)=G3D_SYSTEM_GetObjectAnimeCount(*(int **)(p+0x20));
    for(i=0;i<*(u32 *)(p+0x24);i++) G3D_SYSTEM_EnableObjectAnime(*(struct G3dSys **)(p+0x20),(u16)i);
    *(struct LightSlot **)(p+0x10)=G3D_LIGHT_CreateSlots(&d_021BAB38,142);
    G3D_LIGHT_ApplySlots(*(struct LightSlot **)(p+0x10));
    v=d_021BAC68;
    *(u32 **)(p+0xc)=G3D_CAMERA_Create(0,*(s16 *)(d_020A1E38+0x8c),*(s16 *)(d_020A1E38+0x8e),0x1555,
        0,4096,0x400000,0,&d_021BACE4,&v,&d_021BACF0,142);
    G3D_CAMERA_Reset(*(struct Light **)(p+0xc));
    AntiAlias(1);
    BG_SYS_EnableBg0WithPriority(2);
    STAFF_ROLL_InitLights((u8 *)(p+0x28));
    BG_SYS_SetMainPlaneVisible(1,0);
    G2x_SetBlendBrightness_(0x04000050,1,-16);
}
