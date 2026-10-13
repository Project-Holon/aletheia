/*
 * function: func_022023D0
 * address: 0x022023D0
 * packet: pkt_ov094_022023D0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02205F64 0x02205F64 thumb ov094
 *   func_02205E30 0x02205E30 thumb ov094
 *   func_02205F40 0x02205F40 thumb ov094
 *   func_02205AB8 0x02205AB8 thumb ov094
 *   func_02205D34 0x02205D34 thumb ov094
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   INFOWIN_Exit 0x02024DCC thumb
 *   func_022025B4 0x022025B4 thumb ov094
 *   func_02030EAC 0x02030EAC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj01049.h"
typedef unsigned int u32;
extern void func_02205F64(char *);
extern void func_02205E30(char *);
extern void func_02205F40(char *);
extern void func_02205AB8(char *);
extern void func_02205D34(char *);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_DeleteUnit(int);
struct Descriptor;
struct Node;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern int INFOWIN_Exit(void);
extern void func_022025B4(void);
extern void func_02030EAC(struct Node *n);
extern void ARC_TOOL_DeleteHandle(u32);
#define DROP_ID(k, f) if (*(int *)(p + (k)) != -1) { f(*(int *)(p + (k))); *(int *)(p + (k)) = -1; }
#define DROP_ZERO_ID(k, f) if (*(int *)(p + (k)) != 0) { f(*(int *)(p + (k))); *(int *)(p + (k)) = 0; }
#define DROP_PTR(k, f) if (*(void **)(p + (k)) != 0) { f(*(void **)(p + (k))); *(void **)(p + (k)) = 0; }
void func_022023D0(char *p)
{
    int i;
    func_02205F64(p);
    func_02205E30(p);
    func_02205F40(p);
    func_02205AB8(p);
    func_02205D34(p);
    DROP_ID(0x104, CLACT_ReleaseCharacter);
    DROP_ID(0x108, CLACT_ReleasePalette);
    DROP_ID(0x10c, CLACT_ReleaseCellAnim);
    DROP_ID(0x110, CLACT_ReleaseCharacter);
    DROP_ID(0x114, CLACT_ReleaseCellAnim);
    for (i = 0; i < 4; i++) {
        if (*(int *)(p + i * 4 + 0x1e0) != -1) {
            CLACT_ReleaseCharacter(*(int *)(p + i * 4 + 0x1e0));
            *(int *)(p + i * 4 + 0x1e0) = -1;
        }
    }
    DROP_ID(0x1f4, CLACT_ReleaseCellAnim);
    DROP_ID(0x1f0, CLACT_ReleasePalette);
    DROP_ZERO_ID(0x1f8, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x118, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x17c, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x1c4, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x20c, CLACT_DeleteUnit);
    DROP_ZERO_ID(0x218, CLACT_DeleteUnit);
    DROP_PTR(0x228, BMP_WIN_Delete);
    DROP_PTR(0x230, BMP_WIN_Delete);
    INFOWIN_Exit();
    func_022025B4();
    DROP_PTR(0x238, func_02030EAC);
    DROP_ZERO_ID(0x48, ARC_TOOL_DeleteHandle);
    ((struct Obj01049 *)p)->f58 = 0;
}
