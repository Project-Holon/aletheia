/*
 * function: MONOLITH_TOOL_InitInfoScreen
 * address:  0x021BA1FC
 * packet:   pkt_ov071_021BA1FC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   MONOLITH_TOOL_SetupInfoBgs  0x021BA3B4  thumb  ov071
 *   MONOLITH_TOOL_LoadInfoPalette  0x021BA420  thumb  ov071
 *   MONOLITH_TOOL_CreateInfoWindows  0x021BA44C  thumb  ov071
 *   MONOLITH_TOOL_DrawInfoHeader  0x021BA4EC  thumb  ov071
 *   MONOLITH_TOOL_DrawActiveEntry  0x021BA528  thumb  ov071
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 */
#include "../include/Obj06191.h"
#include "../include/Obj07706.h"
#include "../include/Obj20760.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef enum { B_FALSE, B_TRUE } Bool;

struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void MONOLITH_TOOL_SetupInfoBgs(void);
extern void MONOLITH_TOOL_LoadInfoPalette(char *p);
extern void MONOLITH_TOOL_CreateInfoWindows(void *a, void *b);
extern void MONOLITH_TOOL_DrawInfoHeader(char *p, char *q);
extern void MONOLITH_TOOL_DrawActiveEntry(u32 **a, u8 *b, u8 *c);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct PrintSys;
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);

int MONOLITH_TOOL_InitInfoScreen(struct Obj0203159C *a, int *b, u8 *o, u8 *c)
{
    u8 *m;
    int busy;
    int i;
    u32 t;
    u8 *e;
    Bool f;

    switch (*b) {
    case 0:
        m = PROCSYS_AllocProcWork(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        ((struct Obj20760 *)m)->f24 = 0x30;
        MONOLITH_TOOL_SetupInfoBgs();
        MONOLITH_TOOL_LoadInfoPalette(((struct Obj07706 *)o)->f4);
        MONOLITH_TOOL_CreateInfoWindows(((struct Obj07706 *)o)->f4, m);
        MONOLITH_TOOL_DrawInfoHeader(((struct Obj07706 *)o)->f4, (char *)m);
        MONOLITH_TOOL_DrawActiveEntry((u32 **)o, ((struct Obj07706 *)o)->f4, m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            t = (*(u32 **)(o + 4))[2];
            e = c + i * 8;
            if (e[0x10] != 0) {
                if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj06191 *)e)->fC))) == 0) {
                    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj06191 *)e)->fC);
                    e[0x10] = 0;
                }
            }
            f = e[0x10] == 0 ? B_TRUE : B_FALSE;
            if (f == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
