/*
 * function: MONOLITH_TOOL_STATS_Create
 * address:  0x021B889C
 * packet:   pkt_ov071_021B889C
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Twin of MONOLITH_TOOL_SUMMARY_Create (six handle slots at +0x18 instead of two at +8).
 *
 * symbols:
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021B8A70  0x021B8A70  thumb  ov071
 *   func_021B8ADC  0x021B8ADC  thumb  ov071
 *   func_021B8B08  0x021B8B08  thumb  ov071
 *   func_021B8EC4  0x021B8EC4  thumb  ov071
 *   func_021B8C0C  0x021B8C0C  thumb  ov071
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   func_02040588  0x02040588  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 */
#include "../include/Obj06189.h"

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
struct Obj0203159C;
int MONOLITH_TOOL_STATS_Create(struct Obj0203159C *a, int *b, C *c, u8 *d)
{
    extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void MI_CpuFill8(void *, int, int);
    extern void func_021B8A70(void);
    extern void func_021B8ADC(char *p);
    extern void func_021B8B08(Q *, u8 *);
    extern void func_021B8EC4(void *p, int a);
    extern void func_021B8C0C(C *, Q *, u8 *);
    extern void *BMP_WIN_GetBmp(struct Descriptor *p);
    extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
    extern void BMP_WIN_TransferChars(struct Descriptor *d);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = PROCSYS_AllocProcWork(a, 0x50, 0x61);
        MI_CpuFill8(m, 0, 0x50);
        func_021B8A70();
        func_021B8ADC((char *)c->f4);
        func_021B8B08(c->f4, m);
        func_021B8EC4(c, (int)m);
        func_021B8C0C(c, c->f4, m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0x1c] != 0) {
                if (PRINTSYS_QUE_IsExistTarget(q, (void *)((unsigned)BMP_WIN_GetBmp(((struct Obj06189 *)s)->f18))) == 0) {
                    BMP_WIN_TransferChars(((struct Obj06189 *)s)->f18);
                    s[0x1c] = 0;
                }
            }
            if ((!s[0x1c]) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(6, 1);
            BG_SYS_SetSubPlaneVisible(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}
