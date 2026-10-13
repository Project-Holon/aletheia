/*
 * function: FIELDMAP_CTRL_GRID_Create
 * address:  0x021A2D88
 * packet:   pkt_ov021_021A2D88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_PLAYER_CreateGrid  0x021A35E0  thumb  ov021
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   FIELDMAP_SetTargetPos  0x02188D40  thumb  ov021
 *   FIELDMAP_SetCtrlWork  0x02188CAC  thumb  ov021
 *   gFieldMapCtrlGridFileName     0x021DDE90  data  a4
 */
#include "../include/Obj12722.h"

typedef unsigned short u16;

extern int gFieldMapCtrlGridFileName;

void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, u16 e);
typedef unsigned char  u8;
u16 FIELDMAP_GetHeapId(u8 *p);
struct Obj00020;
void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
void *FIELD_PLAYER_GetMmdl(unsigned char *p);
void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
typedef unsigned int   u32;
void FIELD_PLAYER_CreateGrid(u32 *p, u32 heap);
void *FLDMMDL_GetPosPtr(void *a);
void FIELDMAP_SetTargetPos(u8 *p, u32 v);
void FIELDMAP_SetCtrlWork(u8 *p, u32 v);

void FIELDMAP_CTRL_GRID_Create(int obj, int unused, int y)
{
    int h;
    void *a;
    void *b;
    char *p;

    h = FIELDMAP_GetHeapId((u8 *)obj);
    p = (char *)func_02030734(h, 0x10, 1, (const char *)&gFieldMapCtrlGridFileName, 0x68);
    ((struct Obj12722 *)p)->f0 = h;
    ((struct Obj12722 *)p)->f4 = obj;
    a = FIELDMAP_GetFieldPlayer((void *)obj);
    b = FIELD_PLAYER_GetMmdl((void *)a);
    FLDMMDL_SetDirDispCheckPause((int)b, y);
    FIELD_PLAYER_CreateGrid(a, h);
    FIELDMAP_SetTargetPos((u8 *)obj, (u32)FLDMMDL_GetPosPtr(b));
    FIELDMAP_SetCtrlWork((u8 *)obj, (u32)p);
}
