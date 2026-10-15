/*
 * function: func_021F2908
 * address:  0x021F2908
 * packet:   pkt_ov032_021F2908
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2908  0x021F2908  thumb
 *   func_021F2664  0x021F2664  thumb  ov032
 *   TCBL_Create  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   PRINTSYS_QUE_SetForceQueue  0x0201C4C8  thumb
 *   PRINTSYS_QUE_SetLimitTick  0x0201C4DC  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   STRBUF_Create  0x020457B0  arm
 */
#include "../include/Obj00007.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct MsgBank;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern void func_021F2664(int a, char *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
struct PalAnmSlot;
struct PrintSys;
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern u32 PRINTSYS_QUE_Create(void *p);
extern void PRINTSYS_QUE_SetForceQueue(struct PrintSys *p, u32 v);
extern void PRINTSYS_QUE_SetLimitTick(struct PrintSys *p, u32 lo, u32 hi);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
extern void GF_FONT_SetDefaultTextColor(void);
extern struct WordSet *GF_FONT_Create_EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

void func_021F2908(char *p)
{
    ((struct Obj00007 *)p)->fA0 = TCBL_Create(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f98, 0x10, 0x80);
    ((struct Obj00007 *)p)->fA4 = func_020056A0((void *)func_021F2664, p, 0);
    ((struct Obj00007 *)p)->fAC = (u32)PALANM_Create(((struct Obj00007 *)p)->f98);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 1, 0x1c0, ((struct Obj00007 *)p)->f98);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 3, 0x200, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB4 = PRINTSYS_QUE_Create((void *)(((struct Obj00007 *)p)->f98));
    PRINTSYS_QUE_SetForceQueue((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 1);
    PRINTSYS_QUE_SetLimitTick((struct PrintSys *)(((struct Obj00007 *)p)->fB4), 0x1f4, 0);
    ((struct Obj00007 *)p)->fB0 = FIELD_MSGBG_GetFont((u8 *)FIELDMAP_GetMsgBg((u8 *)(*(u32 *)&((struct Obj00007 *)p)->f8)));
    GF_FONT_SetDefaultTextColor();
    ((struct Obj00007 *)p)->f110 = GF_FONT_Create_EC64(((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f114 = func_02045B38(1, 2, 8, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f118 = STRBUF_Create(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f11C = STRBUF_Create(0xd9, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->f120 = STRBUF_Create(0xd9, ((struct Obj00007 *)p)->f98);
}
