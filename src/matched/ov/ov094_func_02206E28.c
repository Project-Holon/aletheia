/*
 * function: func_02206E28
 * address:  0x02206E28
 * packet:   pkt_ov094_02206E28
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02207960  0x02207960  thumb  ov094
 *   func_0220778C  0x0220778C  thumb  ov094
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   func_02208D24  0x02208D24  thumb  ov094
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   func_020307B0  0x020307B0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   TCBL_IsDeletePending  0x02030EE8  arm
 *   func_02030EAC  0x02030EAC  arm
 */
#include "../include/Obj00380.h"
typedef unsigned int u32;

typedef enum { SLOT_0, SLOT_MAX = 8 } Slot;

typedef struct {
    unsigned int lo : 2;
    unsigned int b2 : 1;
} Bf;

extern void func_02207960(char *p, int i);
extern void func_0220778C(char *p, int i);
extern int GFL_USE_PopBgm(void);
extern void func_02208D24(int a);
struct Node;
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
struct Bank;
struct S02030EE8;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(u32 h);
extern u32 TCBL_IsDeletePending(struct S02030EE8 *p);
extern void func_02030EAC(struct Node *n);

void func_02206E28(char *p)
{
    Slot i;
    int j;

    for (i = SLOT_0; i < SLOT_MAX; i++) {
        func_02207960(p, i);
        func_0220778C(p, i);
    }
    if (((Bf *)(p + 0x440))->b2) {
        GFL_USE_PopBgm();
        func_02208D24(0);
    }
    for (j = 0; j < 6; j++)
        CLACT_ReleasePalette(*(int *)(p + j * 4 + 0x18));
    CLACT_ReleaseCharacter(((struct Obj00380 *)p)->f30);
    CLACT_ReleaseCellAnim(((struct Obj00380 *)p)->f34);
    CLACT_ReleasePalette(((struct Obj00380 *)p)->f38);
    CLACT_ReleasePalette(((struct Obj00380 *)p)->f3C);
    CLACT_DeleteUnit((struct Bank *)(((struct Obj00380 *)p)->f0));
    func_020307B0(((struct Obj00380 *)p)->f10);
    ARC_TOOL_DeleteHandle(((struct Obj00380 *)p)->f4);
    func_020307B0((void *)TCBL_IsDeletePending(((struct Obj00380 *)p)->fC));
    func_02030EAC(((struct Obj00380 *)p)->fC);
    func_020307B0(p);
}
