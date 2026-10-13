/*
 * function: func_021DF864
 * address: 0x021DF864
 * packet: pkt_ov137_021DF864
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02048B6C has no witness; owner unit src/matched/arm9/unit_02048AD0.c
 * omits G3D_CAMERA_SetRoll from function: and its shard. tu --suggest-split leaves caller OUT.
 * blocker: 02048B6C verified EXACT with fixed flags in scratch/blocker48b6c.c:
 * typedef unsigned int u32;
 * void G3D_CAMERA_SetRoll(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 * symbols:
 *   G3D_CAMERA_SetRoll 0x02048B6C arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_CAMERA_Reset 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   NNS_G3dGlbLightVector 0x0206AA3C arm
 *   NNS_G3dGlbLightColor 0x0206AA78 arm
 *   NNS_G3dGlbMaterialColorDiffAmb 0x0206AA8C arm
 *   NNS_G3dGlbMaterialColorSpecEmi 0x0206AAB0 arm
 *   func_021E0698 0x021E0698 thumb ov137
 *   func_021E05D4 0x021E05D4 thumb ov137
 *   func_021E0848 0x021E0848 thumb ov137
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_02045770 0x02045770 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   TIME_ICON_Update 0x0202F0B0 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Descriptor;
struct Light;
extern void G3D_CAMERA_SetRoll(struct Light *l, const u32 *in);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_DrawStart(void),G3D_SYSTEM_ApplyLookAt(void),G3D_SYSTEM_DrawEnd(void),CLACT_DrawSystem(void);
extern void NNS_G3dGlbLightVector(int,int,int,int),NNS_G3dGlbLightColor(int,u32),NNS_G3dGlbMaterialColorDiffAmb(u32,u32,u32),NNS_G3dGlbMaterialColorSpecEmi(u32,u32,u32);
extern void func_021E0698(u8 *),func_021E05D4(u8 *),func_021E0848(u8 *);
struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void TIME_ICON_Update(u8 *p);
void func_021DF864(u8 *p)
{
    u32 flags=0x1000000;
    void *r;
    int i;
    G3D_CAMERA_SetRoll(*(void **)(p+0xd54),&flags);
    G3D_SYSTEM_DrawStart();
    G3D_CAMERA_Reset(*(void **)(p+0xd54));
    G3D_SYSTEM_ApplyLookAt();
    NNS_G3dGlbLightVector(0,0,-4096,0);
    NNS_G3dGlbLightColor(0,0x7fff);
    NNS_G3dGlbMaterialColorDiffAmb(0x7fff,0x7fff,0);
    NNS_G3dGlbMaterialColorSpecEmi(0x7fff,0x7fff,0);
    func_021E0698(p);func_021E05D4(p);func_021E0848(p);
    G3D_SYSTEM_DrawEnd();CLACT_DrawSystem();
    PRINTSYS_QUE_Main(*(void **)(p+0xd38));
    r=*(void **)(p+0xd38);
    if(*(u8 *)(p+0xd0c)) {
        if(!func_0201C6C4(r,func_02045770(*(void **)(p+0xd08)))) {
            BMP_WIN_TransferChars(*(void **)(p+0xd08));
            *(u8 *)(p+0xd0c)=0;
        }
    }
    for(i=0;i<5;i++) {
        r=*(void **)(p+0xd38);
        if(*(u8 *)(p+i*8+0xd14)) {
            if(!func_0201C6C4(r,func_02045770(*(void **)(p+i*8+0xd10)))) {
                BMP_WIN_TransferChars(*(void **)(p+i*8+0xd10));
                *(u8 *)(p+i*8+0xd14)=0;
            }
        }
    }
    if(*(void **)(p+0xda8)) TIME_ICON_Update(*(void **)(p+0xda8));
}
