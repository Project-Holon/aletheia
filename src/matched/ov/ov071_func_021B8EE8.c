/*
 * function: MONOLITH_TOOL_LIST_Init
 * address:  0x021B8EE8
 * packet:   pkt_ov071_021B8EE8
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_02045B38  0x02045B38  arm
 *   MONOLITH_TOOL_LIST_InitBackgrounds  0x021B9560  thumb  ov071
 *   MONOLITH_TOOL_LIST_LoadGraphics  0x021B95FC  thumb  ov071
 *   MONOLITH_TOOL_LIST_InitWindows  0x021B96A4  thumb  ov071
 *   MONOLITH_TOOL_UpdateBgScroll  0x021BA11C  thumb  ov071
 *   MONOLITH_TOOL_CreateMarker  0x021B9BB8  thumb  ov071
 *   MONOLITH_TOOL_CreateRowGrids  0x021B9AE4  thumb  ov071
 *   MONOLITH_TOOL_CreateBackButton  0x021B9B64  thumb  ov071
 *   MONOLITH_TOOL_CreateScrollArrows  0x021B9BE8  thumb  ov071
 *   MONOLITH_TOOL_LIST_DrawTitle  0x021B9750  thumb  ov071
 *   func_021B7174  0x021B7174  thumb  ov071
 *   func_020056A0  0x020056A0  thumb
 *   MONOLITH_TOOL_TaskUploadRows  0x021BA1B0  thumb  ov071
 *   MONOLITH_TOOL_LIST_BuildEntryList  0x021B9970  thumb  ov071
 *   MONOLITH_TOOL_LIST_FitBackground  0x021B992C  thumb  ov071
 *   MONOLITH_TOOL_LIST_DrawEntryNames  0x021B9A40  thumb  ov071
 *   MONOLITH_TOOL_UpdateRows  0x021BA140  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   MONOLITH_TOOL_SetCursor  0x021B9F2C  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 */
#include "../include/Obj01884.h"
#include "../include/Obj02123.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;

struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void func_021B6C54(char *p);
struct MsgBank;
struct PrintSys;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void MONOLITH_TOOL_LIST_InitBackgrounds(void);
extern void MONOLITH_TOOL_LIST_LoadGraphics(void *a, void *b);
extern void MONOLITH_TOOL_LIST_InitWindows(char *a, void **b);
extern void MONOLITH_TOOL_UpdateBgScroll(char *p);
extern void MONOLITH_TOOL_CreateMarker(char *p, char *q);
extern void MONOLITH_TOOL_CreateRowGrids(void *a, void *b);
extern void MONOLITH_TOOL_CreateBackButton(char *p, char *q);
extern void MONOLITH_TOOL_CreateScrollArrows(char *p, char *q);
extern void MONOLITH_TOOL_LIST_DrawTitle(char *a, char *b);
typedef unsigned short u16;
struct R;
extern struct R *func_021B7174(u32 *p, int a, u16 heap);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void MONOLITH_TOOL_TaskUploadRows(void *unused, char *p);
extern void MONOLITH_TOOL_LIST_BuildEntryList(void *a, void *b, void *c);
extern void MONOLITH_TOOL_LIST_FitBackground(char *a);
extern int MONOLITH_TOOL_LIST_DrawEntryNames(char *a, char *b);
extern void MONOLITH_TOOL_UpdateRows(u8 *p);
extern u8 func_020355C4(void);
extern int MONOLITH_TOOL_SetCursor(u8 *p, int i, int v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

int MONOLITH_TOOL_LIST_Init(struct Obj0203159C *a, int *b, u8 *c, u8 *o)
{
    int busy;
    u32 t;
    Bool f;

    switch (*b) {
    case 0:
        o = PROCSYS_AllocProcWork(a, 0x314, 0x61);
        func_02082BCC(o, 0, 0x314);
        ((struct Obj01884 *)o)->f2D8 = 0x800;
        ((struct Obj01884 *)o)->f300 = 0xffff;
        ((struct Obj01884 *)o)->f2F8 = 0xffff;
        ((struct Obj01884 *)o)->f2FC = 0xffff;
        func_021B6C54((char *)c);
        ((struct Obj01884 *)o)->f20 = (int)func_02045B38(0, 2, 0xa0, 0x61);
        MONOLITH_TOOL_LIST_InitBackgrounds();
        MONOLITH_TOOL_LIST_LoadGraphics(o, ((struct Obj02123 *)c)->f4);
        MONOLITH_TOOL_LIST_InitWindows((char *)o, ((struct Obj02123 *)c)->f4);
        MONOLITH_TOOL_UpdateBgScroll((char *)o);
        MONOLITH_TOOL_CreateMarker((char *)c, (char *)o);
        MONOLITH_TOOL_CreateRowGrids(o, ((struct Obj02123 *)c)->f4);
        MONOLITH_TOOL_CreateBackButton((char *)c, (char *)o);
        MONOLITH_TOOL_CreateScrollArrows((char *)c, (char *)o);
        MONOLITH_TOOL_LIST_DrawTitle((char *)c, (char *)o);
        ((struct Obj01884 *)o)->f30C = (int)func_021B7174(((struct Obj02123 *)c)->f4, 4, 0x61);
        (*(u8 **)(c + 8))[1] = 0x30;
        ((struct Obj01884 *)o)->f0 = func_020056A0((void (*)(void))MONOLITH_TOOL_TaskUploadRows, o, 3);
        MONOLITH_TOOL_LIST_BuildEntryList(c, o, ((struct Obj02123 *)c)->f4);
        MONOLITH_TOOL_LIST_FitBackground((char *)o);
        *b = *b + 1;
        break;
    case 1:
        if (MONOLITH_TOOL_LIST_DrawEntryNames((char *)o, ((struct Obj02123 *)c)->f4) == 1) {
            MONOLITH_TOOL_UpdateRows(o);
            ((struct Obj01884 *)o)->f2F0 = 1;
            if (func_020355C4() == 0) {
                MONOLITH_TOOL_SetCursor(o, 1, 0);
            } else {
                MONOLITH_TOOL_SetCursor(o, 0xffff, 0);
            }
            *b = *b + 1;
        }
        break;
    case 2:
        busy = 0;
        t = (*(u32 **)(c + 4))[2];
        if (o[0x28c] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj01884 *)o)->f288))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01884 *)o)->f288);
                o[0x28c] = 0;
            }
        }
        f = o[0x28c] == 0 ? B_TRUE : B_FALSE;
        if (f == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(6, 1);
            BG_SYS_SetSubPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
