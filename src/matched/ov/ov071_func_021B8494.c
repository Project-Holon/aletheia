/*
 * function: MONOLITH_TOOL_SUMMARY_Create
 * address:  0x021B8494
 * packet:   pkt_ov071_021B8494
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   MONOLITH_TOOL_SUMMARY_InitBackgrounds  0x021B8650  thumb  ov071
 *   MONOLITH_TOOL_SUMMARY_LoadGraphics  0x021B86BC  thumb  ov071
 *   MONOLITH_TOOL_SUMMARY_CreateWindows  0x021B86E8  thumb  ov071
 *   MONOLITH_TOOL_SUMMARY_CreateLabel  0x021B8764  thumb  ov071
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 */
#include "../include/Obj06186.h"

typedef unsigned char u8;

typedef struct {
    char pad0[8];
    void *f8;
} Q;

typedef struct {
    void **f0;
    Q *f4;
} C;

typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
struct Proc;
int MONOLITH_TOOL_SUMMARY_Create(struct Proc *a, int *b, C *c, u8 *d)
{
    extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
    extern void MI_CpuFill8(void *, int, int);
    extern void MONOLITH_TOOL_SUMMARY_InitBackgrounds(void);
    extern void MONOLITH_TOOL_SUMMARY_LoadGraphics(char *p);
    extern void MONOLITH_TOOL_SUMMARY_CreateWindows(Q *, u8 *);
    extern void MONOLITH_TOOL_SUMMARY_CreateLabel(void *p, char *q);
    extern void *BMP_WIN_GetBmp(struct Descriptor *p);
    extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
    extern void BMP_WIN_TransferChars(struct Descriptor *d);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = PROCSYS_AllocProcWork(a, 0x28, 0x61);
        MI_CpuFill8(m, 0, 0x28);
        MONOLITH_TOOL_SUMMARY_InitBackgrounds();
        MONOLITH_TOOL_SUMMARY_LoadGraphics((char *)c->f4);
        MONOLITH_TOOL_SUMMARY_CreateWindows(c->f4, m);
        MONOLITH_TOOL_SUMMARY_CreateLabel(c->f4, (char *)m);
        m[0x24] = 0xff;
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0xc] != 0) {
                if (PRINTSYS_QUE_IsExistTarget(q, (void *)((unsigned)BMP_WIN_GetBmp(((struct Obj06186 *)s)->f8))) == 0) {
                    BMP_WIN_TransferChars(((struct Obj06186 *)s)->f8);
                    s[0xc] = 0;
                }
            }
            if ((!s[0xc]) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            BG_SYS_SetMainPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
