/*
 * function: MCSS_CreatePaletteTransTask
 * address:  0x020160D4
 * packet:   pkt_020160D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * mcss.c: builds the per-scene fade/transition context.  Three debug
 * allocations out of the heap named by the u16 at +0x14c (masked to
 * 0x7fff and forced into the 0x8000 bank), then a palette blend and a
 * copy, and finally either a task registration (MCSS_TransPaletteTask as the
 * callback, through the owner-aware path or the plain one) or, if the
 * caller has already set the "skip" bit at +0x140, an immediate teardown
 * of everything just allocated.  Either way the done bit 0x10000000 is
 * latched into the same word at +0x140.
 *
 * The three heap ids are recomputed rather than cached: each is a fresh
 * `ldr`+lsls/lsrs of the int field at +0x14c, so the field is an `int`
 * truncated at the call, not a u16 member (see MCSS_InitAnimCtrl in this
 * same file).  The two __LINE__ pool words 0x761 and 0x769 are the
 * consecutive-line idiom: 0x76e is derived from 0x769 with `adds #5`.
 *
 * symbols:
 *   data_020A72CC  0x020A72CC  data
 *   MCSS_TransPaletteTask  0x0201691C  thumb
 *   MCSS_DeletePaletteTask  0x02016C38  thumb
 *   func_02021F64  0x02021F64  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082A60  0x02082A60  arm
 *
 * Closed in the second pass (2026-09-22) from the 12-byte prologue-spill
 * near miss in docs/notes/MCSS_CreatePaletteTransTask.c.txt.  The lever is the THIRD
 * PARAMETER'S TYPE: `u16 a2`, not `int a2`.
 *
 * That note's own list had tried `u16` on a3 (which made it worse, 168
 * bytes) and `u32` on a2, but never `u16` on a2.  tools/permuter.py
 * found it as `type:p(a2:int->u16)` on the 306th compile of a
 * `--mode hill --budget 800 --types` run, taking 12 concrete bytes to 0
 * in one mutation.  A 16-bit parameter arrives already narrowed, so the
 * front end spills it BEFORE it touches the literal pool -- which is
 * exactly the `str r2,[sp,#4]` / `ldr r0,[pc,#0x158]` / `str r3,[sp,#8]`
 * order the note recorded and could not reach.  The note's "untried
 * lever" guess (make a2 reach a call earlier) was not needed.
 *
 * This is also a data point for the family: the value at +0x13C that
 * MCSS_UpdatePaletteFade hands to func_02021F64 as `(u16)` is 16-bit AT THE
 * PARAMETER here, not only at the call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/MCSS_CreatePaletteTransTask.c \
 *       --func MCSS_CreatePaletteTransTask --addr 0x020160D4 --cc 1.1p1 --thumb
 */
#include "../include/Obj01093.h"
#include "../include/Obj01612.h"
#include "../include/Obj06864.h"
#include "../include/Obj15676.h"
#include "../include/Obj15677.h"
#include "../include/Obj15678.h"
#include "../include/Obj15679.h"
#include "../include/Obj15680.h"
#include "../include/Obj15681.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern char data_020A72CC[];

struct Obj_0201691C;
extern void MCSS_TransPaletteTask(void *a0, struct Obj_0201691C *a1);
extern int MCSS_DeletePaletteTask(int a0);
extern void  func_02021F64(int a, int b, u16 c, int d, u16 e);
extern int   func_020056A0(int fn, int arg, int n);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern int   func_02030DA8(int owner, int fn, int arg, int n);
extern u32 func_020307B0(void *p);
extern void  func_02082A60(int a, int b, int c);

void MCSS_CreatePaletteTransTask(char *a0, char *a1, u16 a2, int a3)
{
    char *o;

    o = (char *)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            0x2c, 1, (const char *)data_020A72CC, 0x761);

    *(char * *)&((struct Obj01612 *)o)->f20 = a0;
    ((struct Obj01612 *)o)->f28 = (((struct Obj06864 *)a0)->f8 != 0);
    *(char * *)&((struct Obj01612 *)o)->f24 = a1;
    *(char * *)&((struct Obj01612 *)o)->fC = a1 + 0xc0;
    ((struct Obj01612 *)o)->f1C = ((struct Obj06864 *)a0)->f34 + (((struct Obj01093 *)a1)->f148 << 5);

    *(char * *)&((struct Obj01612 *)o)->f4 = (char *)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            0x10, 0, (const char *)data_020A72CC, 0x769);

    **(int * *)&((struct Obj01612 *)o)->f4 = ((struct Obj01093 *)a1)->fC0;
    ((struct Obj15676 *)(*(char * *)&((struct Obj01612 *)o)->f4))->f4 = 0;
    ((struct Obj15677 *)(*(char * *)&((struct Obj01612 *)o)->f4))->f8 = ((struct Obj01093 *)a1)->fDC;
    ((struct Obj15678 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC = (int)func_02030734(
            (u16)(((u16)((struct Obj01093 *)a1)->f14C & 0x7fff) | 0x8000),
            ((struct Obj01093 *)a1)->fDC, 0, (const char *)data_020A72CC, 0x76e);

    func_02021F64(((struct Obj01093 *)a1)->fD4,
                  ((struct Obj15679 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC,
                  (u16)(((struct Obj01093 *)a1)->fDC / 2),
                  a2, (u16)a3);
    func_02082A60(((struct Obj15680 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC,
                  ((struct Obj01093 *)a1)->fD8, ((struct Obj01093 *)a1)->fDC);

    if (((struct Obj01093 *)a1)->f8 != 0) {
        MCSS_DeletePaletteTask(((struct Obj01093 *)a1)->f8);
        ((struct Obj01093 *)a1)->f8 = 0;
    }

    if (((u32)(((struct Obj01093 *)a1)->f140 << 0x13) >> 0x1f) == 0) {
        if (((struct Obj06864 *)a0)->f8 != 0) {
            ((struct Obj01093 *)a1)->f8 = func_02030DA8(((struct Obj06864 *)a0)->f8,
                                             (int)MCSS_TransPaletteTask, (int)o, 0);
        } else {
            ((struct Obj01093 *)a1)->f8 = func_020056A0((int)MCSS_TransPaletteTask, (int)o, 0);
        }
    } else {
        func_020307B0((void *)(((struct Obj15681 *)(*(char * *)&((struct Obj01612 *)o)->f4))->fC));
        func_020307B0((void *)(*(int *)&((struct Obj01612 *)o)->f4));
        func_020307B0((void *)((int)o));
    }

    *(int *)&((struct Obj01093 *)a1)->f140 |= 0x10000000;
}
