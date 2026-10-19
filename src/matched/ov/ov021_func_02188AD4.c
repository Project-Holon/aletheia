/*
 * function: FIELDMAP_SeqExitSystem
 * address:  0x02188AD4
 * packet:   pkt_ov021_02188AD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCB_Noop  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   func_02034A5C  0x02034A5C  arm
 *   FLD_VREQ_Delete  0x021D31A4  thumb
 *   FIELD_TASK_MANAGER_Delete  0x021C6D5C  thumb
 *   FIELD_G3D_MAPPER_Delete  0x0218CA4C  thumb
 *   FIELDMAP_DeleteG3dResources  0x021890C8  thumb
 *   FIELDMAP_ExitBgSystem  0x02188E38  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   abs_id_13  0x00000013  data
 *   abs_id_12  0x00000012  data
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u8 abs_id_13[];
extern u8 abs_id_12[];
extern void TCB_Noop(u32 a);
struct Node;
extern u32 func_020307B0(void *p);
extern void func_02030EAC(struct Node *n);
extern void CLACT_ExitSystem(void);
extern void BMP_WIN_Exit(void);
extern void func_02034A5C(s32 handle);
extern void FLD_VREQ_Delete(u32 a);
extern void FIELD_TASK_MANAGER_Delete(u32 a);
extern int FIELD_G3D_MAPPER_Delete(void *a);
extern void FIELDMAP_DeleteG3dResources(void *a);
extern void FIELDMAP_ExitBgSystem(void *a);
extern u32 ZONEDATA_IsUnionRoom(u32 a);
extern u32 ZONEDATA_IsZone96Pair(u32 a);

u32 FIELDMAP_SeqExitSystem(void *a, u8 *b)
{
    TCB_Noop(((struct Obj03103 *)b)->f110);
    func_020307B0((void *)(((struct Obj03103 *)b)->f114));
    FLD_VREQ_Delete(((struct Obj03103 *)b)->f14C);
    ((struct Obj03103 *)b)->f14C = 0;
    FIELD_TASK_MANAGER_Delete(((struct Obj03103 *)b)->f134);
    func_02030EAC((struct Node *)(((struct Obj03103 *)b)->fAC));
    FIELD_G3D_MAPPER_Delete((void *)(((struct Obj03103 *)b)->f48));
    FIELDMAP_DeleteG3dResources(b);
    CLACT_ExitSystem();
    BMP_WIN_Exit();
    FIELDMAP_ExitBgSystem(b);
    if (ZONEDATA_IsUnionRoom(((struct Obj03103 *)b)->fD0) == 1 || ZONEDATA_IsZone96Pair(((struct Obj03103 *)b)->fD0) == 1)
        func_02034A5C((s32)abs_id_13);
    else
        func_02034A5C((s32)abs_id_12);
    return 2;
}
