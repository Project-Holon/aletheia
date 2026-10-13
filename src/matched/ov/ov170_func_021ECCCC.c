/*
 * function: func_021ECCCC
 * address: 0x021ECCCC
 * packet: pkt_ov170_021ECCCC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 0202D7C8 reads and forwards only r0; legacy r1-r3 omitted.
 * prototype: 0202D8D0 stack mode is full-width in this caller, with no
 * truncation; its callee forwards the same low-halfword value.
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_DecodeBoxParam 0x02017DBC thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKE_TOOL_EncodeBoxParam 0x02017DE4 thumb
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_021EC000 0x021EC000 thumb ov170
 *   d_021EFD80 0x021EFD80 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern int POKEGRA_OpenHandle(int);
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);
extern int POKEGRA_RegisterPalettePP(int,void *,int,int,u32,u16);
extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern void ARC_TOOL_DeleteHandle(int);
extern void *func_021EBEE0(char *,const void *);
extern void func_021EC000(char *,int,int);
extern const char d_021EFD80[];
#define W(p) (*(char **)((p)+44))
void func_021ECCCC(char *p,void **mon,int index)
{
    int *bmp,*cell,*anim;
    int other;
    int mode;
    int archive,state;
    if (*(u16 *)(W(p)+0xA164)==0) {
        bmp=(int *)(W(p)+0xA088);cell=(int *)(W(p)+0xA10C);
        anim=(int *)(W(p)+0xA138);mode=96;other=index+1;
    } else {
        bmp=(int *)(W(p)+0xA08C);cell=(int *)(W(p)+0xA110);
        anim=(int *)(W(p)+0xA13C);mode=128;other=index;index++;
    }
    if (*(void **)((W(p)+index*4)+0x9E74)) {
        CLACT_DeleteActor(*(void **)((W(p)+index*4)+0x9E74));
        CLACT_ReleaseCharacter(*bmp);CLACT_ReleasePalette(*cell);CLACT_ReleaseCellAnim(*anim);
    }
    archive=POKEGRA_OpenHandle(76);
    state=POKE_TOOL_DecodeBoxParam(*mon);
    *bmp=POKEGRA_RegisterCgrPP(archive,*mon,0,1,76);
    *cell=POKEGRA_RegisterPalettePP(archive,*mon,0,1,mode,76);
    *anim=POKEGRA_RegisterCellAnimPP((u32)*mon,0,2,1,76);
    POKE_TOOL_EncodeBoxParam(*mon,state);ARC_TOOL_DeleteHandle(archive);
    *(void **)((W(p)+index*4)+0x9E74)=func_021EBEE0(W(p),d_021EFD80+24*(u32)index);
    func_021EC000(W(p),index,1);
    if (*(void **)((W(p)+other*4)+0x9E74)) func_021EC000(W(p),other,0);
    *(u16 *)(W(p)+0xA164)^=1;
}
