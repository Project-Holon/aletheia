/*
 * function: MONOLITH_TOOL_SLOT_SELECT_Init
 * address:  0x021B730C
 * packet:   pkt_ov071_021B730C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds  0x021B7880  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_LoadGraphics  0x021B78F4  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow  0x021B7924  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons  0x021B7A68  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_CreateButtons  0x021B7B10  thumb  ov071
 *   MONOLITH_TOOL_SLOT_SELECT_CreateCursor  0x021B7BD8  thumb  ov071
 *   MONOLITH_TOOL_CreateCursor  0x021B7014  thumb  ov071
 *   func_02040588  0x02040588  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   d_021BA8A0     0x021BA8A0  data  a4
 */
#include "../include/Obj13174.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, int v, int n);
extern void MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds(void);
extern void MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(void *p, void **q);
extern void MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow(void **p, void **q);
extern void MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(void *a, void *b);
extern void MONOLITH_TOOL_SLOT_SELECT_CreateButtons(int *a, char *b);
extern void MONOLITH_TOOL_SLOT_SELECT_CreateCursor(void *p, int a);
extern int MONOLITH_TOOL_CreateCursor(int *, const int *, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern const char d_021BA8A0[];

int MONOLITH_TOOL_SLOT_SELECT_Init(void *ctx, int *st, int *w)
{
    u8 *m;

    switch (st[0]) {
    case 0:
        m = PROCSYS_AllocProcWork(ctx, 0x84, 0x61);
        MI_CpuFill8(m, 0, 0x84);
        m[0x82] = 0;
        MONOLITH_TOOL_SLOT_SELECT_InitBackgrounds();
        MONOLITH_TOOL_SLOT_SELECT_LoadGraphics(w, (void *)w[1]);
        MONOLITH_TOOL_SLOT_SELECT_InitMsgWindow((void **)m, (void *)w[1]);
        MONOLITH_TOOL_SLOT_SELECT_CreateSlotIcons(m, w);
        MONOLITH_TOOL_SLOT_SELECT_CreateButtons(w, (char *)m);
        MONOLITH_TOOL_SLOT_SELECT_CreateCursor(w, (int)m);
        ((struct Obj13174 *)m)->f7C = MONOLITH_TOOL_CreateCursor((int *)w[1], (const int *)(d_021BA8A0 + *(u8 *)w[2] * 8), 1);
        st[0]++;
        break;
    case 1:
        func_02040588(6, 1);
        BG_SYS_SetSubPlaneVisible(0x10, 1);
        return 1;
    }
    return 0;
}
