/*
 * function: SCRIPT_WORK_Create
 * address:  0x02158E7C
 * packet:   pkt_ov010_02158E7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   SCRIPT_SYS_IsChildScript  0x02158DB0  thumb  ov010
 *   func_0201EC74  0x0201EC74  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   SCRCMD_WORK_CreateCommon  0x0215A514  thumb  ov010
 *   SCRIPT_WORK_InitFieldParam  0x02158E54  thumb  ov010
 *   SCRIPT_WORK_ClearCheckFlags  0x02159130  thumb  ov010
 *   sScriptWorkFileName     0x0217289C  data  ov010  a1
 */
#include "../include/Obj00105.h"

typedef unsigned short u16;

struct O {
    int f0; u16 f4; int f8; u16 fc; int f10, f14, f18[3];
    int f24;
    int f20, f28, f2c, f30, f34;
};

typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int SCRIPT_SYS_IsChildScript(int);
struct WordSet;
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *SCRCMD_WORK_CreateCommon(int a, int heap);
extern int SCRIPT_WORK_InitFieldParam(int a0, int a1);
extern void SCRIPT_WORK_ClearCheckFlags(void);
extern char sScriptWorkFileName[];

int *SCRIPT_WORK_Create(u16 a, int b, int c, int d, int e, int f)
{
    int *p = func_02030734(a, 0x14C, 1, sScriptWorkFileName, 0xAF);
    p[0] = 0x3643F;
    *(u16 *)(p + 3) = a;
    p[4] = b;
    p[5] = c;
    ((struct Obj00105 *)p)->f4 = d;
    p[2] = 0;
    p[8] = e;
    p[10] = f;
    p[9] = SCRIPT_SYS_IsChildScript(f);
    if (p[9] == 0) {
        p[11] = (int)func_0201EC74(0x1C, 0x40, a);
        p[12] = (int)STRBUF_Create(0x500, a);
        p[13] = (int)STRBUF_Create(0x500, a);
    } else {
        p[11] = 0;
        p[12] = 0;
        p[13] = 0;
    }
    p[0x52] = (int)SCRCMD_WORK_CreateCommon((int)p, a);
    SCRIPT_WORK_InitFieldParam((int)(p + 6), b);
    if (p[9] == 0)
        SCRIPT_WORK_ClearCheckFlags();
    return p;
}
