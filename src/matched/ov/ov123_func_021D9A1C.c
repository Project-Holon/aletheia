/*
 * function: PDWACC_DISP_Exit
 * address: 0x021D9A1C
 * packet: pkt_ov123_021D9A1C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PDWACC_DISP_DeleteActors 0x021D9FB0 thumb ov123
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 */
#include "../include/Obj03802.h"
typedef unsigned char u8;
typedef enum { C0=0 } Counter;
extern u8 ov_id[];
extern void PDWACC_DISP_DeleteActors(unsigned int p);
extern void CLACT_ReleasePalette(unsigned int i);
extern void CLACT_ReleaseCharacter(unsigned int i);
extern void CLACT_ReleaseCellAnim(unsigned int i);
typedef unsigned int   u32;
struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void BG_SYS_FreeLayerBuf(unsigned int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_Delete(void);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
void PDWACC_DISP_Exit(u8 *p)
{
    Counter i;
    PDWACC_DISP_DeleteActors((unsigned int)p);
    if (((struct Obj03802 *)p)->f8) {
        func_02030EAC(((struct Obj03802 *)p)->f8);
        ((struct Obj03802 *)p)->f8=0;
        ((struct Obj03802 *)p)->fC=0;
    }
    i=0;
    do { if (*(void **)(p+i*4+0x988)) CLACT_ReleasePalette((unsigned int)(*(void **)(p+i*4+0x988))); i++; } while(i<3);
    for(;i<6;i++) if (*(void **)(p+i*4+0x988)) CLACT_ReleaseCharacter((unsigned int)(*(void **)(p+i*4+0x988)));
    for(;i<9;i++) if (*(void **)(p+i*4+0x988)) CLACT_ReleaseCellAnim((unsigned int)(*(void **)(p+i*4+0x988)));
    if (((struct Obj03802 *)p)->f984) func_02030EAC(((struct Obj03802 *)p)->f984);
    func_02030EAC(((struct Obj03802 *)p)->f980);
    CLACT_DeleteUnit(((struct Obj03802 *)p)->f97C);
    CLACT_ExitSystem();
    BG_SYS_SetTileUnit(1,1,0);
    BG_SYS_SetTileUnit(6,1,0);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    func_02040588(5,0);
    BG_SYS_Delete();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}
