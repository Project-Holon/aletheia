/*
 * function: func_020160D4
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
 * copy, and finally either a task registration (func_0201691C as the
 * callback, through the owner-aware path or the plain one) or, if the
 * caller has already set the "skip" bit at +0x140, an immediate teardown
 * of everything just allocated.  Either way the done bit 0x10000000 is
 * latched into the same word at +0x140.
 *
 * The three heap ids are recomputed rather than cached: each is a fresh
 * `ldr`+lsls/lsrs of the int field at +0x14c, so the field is an `int`
 * truncated at the call, not a u16 member (see func_02016984 in this
 * same file).  The two __LINE__ pool words 0x761 and 0x769 are the
 * consecutive-line idiom: 0x76e is derived from 0x769 with `adds #5`.
 *
 * symbols:
 *   data_020A72CC  0x020A72CC  data
 *   func_0201691C  0x0201691C  thumb
 *   func_02016C38  0x02016C38  thumb
 *   func_02021F64  0x02021F64  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082A60  0x02082A60  arm
 *
 * Closed in the second pass (2026-09-22) from the 12-byte prologue-spill
 * near miss in docs/notes/func_020160D4.c.txt.  The lever is the THIRD
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
 * func_020169E8 hands to func_02021F64 as `(u16)` is 16-bit AT THE
 * PARAMETER here, not only at the call.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_020160D4.c \
 *       --func func_020160D4 --addr 0x020160D4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern char data_020A72CC[];

struct Obj_0201691C;
extern void func_0201691C(void *a0, struct Obj_0201691C *a1);
extern int func_02016C38(int a0);
extern void  func_02021F64(int a, int b, u16 c, int d, u16 e);
extern int   func_020056A0(int fn, int arg, int n);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern int   func_02030DA8(int owner, int fn, int arg, int n);
extern void func_020307B0(void *p);
extern void  func_02082A60(int a, int b, int c);

void func_020160D4(char *a0, char *a1, u16 a2, int a3)
{
    char *o;

    o = (char *)func_02030734(
            (u16)(((u16)*(int *)(a1 + 0x14c) & 0x7fff) | 0x8000),
            0x2c, 1, (const char *)data_020A72CC, 0x761);

    *(char **)(o + 0x20) = a0;
    *(int *)(o + 0x28) = (*(int *)(a0 + 8) != 0);
    *(char **)(o + 0x24) = a1;
    *(char **)(o + 0xc) = a1 + 0xc0;
    *(int *)(o + 0x1c) = *(int *)(a0 + 0x34) + (*(int *)(a1 + 0x148) << 5);

    *(char **)(o + 4) = (char *)func_02030734(
            (u16)(((u16)*(int *)(a1 + 0x14c) & 0x7fff) | 0x8000),
            0x10, 0, (const char *)data_020A72CC, 0x769);

    **(int **)(o + 4) = *(int *)(a1 + 0xc0);
    *(int *)(*(char **)(o + 4) + 4) = 0;
    *(int *)(*(char **)(o + 4) + 8) = *(int *)(a1 + 0xdc);
    *(int *)(*(char **)(o + 4) + 0xc) = (int)func_02030734(
            (u16)(((u16)*(int *)(a1 + 0x14c) & 0x7fff) | 0x8000),
            *(int *)(a1 + 0xdc), 0, (const char *)data_020A72CC, 0x76e);

    func_02021F64(*(int *)(a1 + 0xd4),
                  *(int *)(*(char **)(o + 4) + 0xc),
                  (u16)(*(int *)(a1 + 0xdc) / 2),
                  a2, (u16)a3);
    func_02082A60(*(int *)(*(char **)(o + 4) + 0xc),
                  *(int *)(a1 + 0xd8), *(int *)(a1 + 0xdc));

    if (*(int *)(a1 + 8) != 0) {
        func_02016C38(*(int *)(a1 + 8));
        *(int *)(a1 + 8) = 0;
    }

    if (((u32)(*(u32 *)(a1 + 0x140) << 0x13) >> 0x1f) == 0) {
        if (*(int *)(a0 + 8) != 0) {
            *(int *)(a1 + 8) = func_02030DA8(*(int *)(a0 + 8),
                                             (int)func_0201691C, (int)o, 0);
        } else {
            *(int *)(a1 + 8) = func_020056A0((int)func_0201691C, (int)o, 0);
        }
    } else {
        func_020307B0((void *)(*(int *)(*(char **)(o + 4) + 0xc)));
        func_020307B0((void *)(*(int *)(o + 4)));
        func_020307B0((void *)((int)o));
    }

    *(int *)(a1 + 0x140) |= 0x10000000;
}
