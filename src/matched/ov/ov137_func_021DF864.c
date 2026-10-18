/*
 * function: GURU2_MAIN_Draw3D
 * address: 0x021DF864
 * packet: pkt_ov137_021DF864
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02048B6C has no witness; owner unit src/matched/arm9/unit_02048AD0.c
 * omits G3D_CAMERA_SetFar from function: and its shard. tu --suggest-split leaves caller OUT.
 * blocker: 02048B6C verified EXACT with fixed flags in scratch/blocker48b6c.c:
 * typedef unsigned int u32;
 * void G3D_CAMERA_SetFar(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 * symbols:
 *   G3D_CAMERA_SetFar 0x02048B6C arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   NNS_G3dGlbLightVector 0x0206AA3C arm
 *   NNS_G3dGlbLightColor 0x0206AA78 arm
 *   NNS_G3dGlbMaterialColorDiffAmb 0x0206AA8C arm
 *   NNS_G3dGlbMaterialColorSpecEmi 0x0206AAB0 arm
 *   GURU2_MAIN_DrawBackgroundUnit 0x021E0698 thumb ov137
 *   GURU2_MAIN_DrawCenterUnit 0x021E05D4 thumb ov137
 *   GURU2_MAIN_DrawPlayerRecords 0x021E0848 thumb ov137
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   TIME_ICON_Update 0x0202F0B0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Light;
extern void G3D_CAMERA_SetFar(struct Light *l, const u32 *in);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_DrawStart(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void),CLACT_DrawSystem(void);
extern void NNS_G3dGlbLightVector(int,int,int,int),NNS_G3dGlbLightColor(int,u32),NNS_G3dGlbMaterialColorDiffAmb(u32,u32,u32),NNS_G3dGlbMaterialColorSpecEmi(u32,u32,u32);
extern void GURU2_MAIN_DrawBackgroundUnit(u8 *),GURU2_MAIN_DrawCenterUnit(u8 *),GURU2_MAIN_DrawPlayerRecords(u8 *);
struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void TIME_ICON_Update(u8 *p);
void GURU2_MAIN_Draw3D(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    G3D_CAMERA_SetFar(*(void **)(p+0xd54),&flags);
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset(*(void **)(p+0xd54));
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGlbLightVector(0,0,-4096,0);
    NNS_G3dGlbLightColor(0,0x7fff);
    NNS_G3dGlbMaterialColorDiffAmb(0x7fff,0x7fff,0);
    NNS_G3dGlbMaterialColorSpecEmi(0x7fff,0x7fff,0);
    GURU2_MAIN_DrawBackgroundUnit(p);GURU2_MAIN_DrawCenterUnit(p);GURU2_MAIN_DrawPlayerRecords(p);
    G3D_SYSTEM_DrawEnd();CLACT_DrawSystem();
    PRINTSYS_QUE_Main(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!PRINTSYS_QUE_IsExistTarget(r,BMP_WIN_GetBmp(*(void **)(p+0xd08)))) {
            BMP_WIN_TransferChars(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!PRINTSYS_QUE_IsExistTarget(r,BMP_WIN_GetBmp(*(void **)(p+i*8+0xd10)))) {
                BMP_WIN_TransferChars(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) TIME_ICON_Update(*(void **)(p+0xda8));
}
