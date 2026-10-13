/*
 * function: WIPE_SUB_BoxInit
 * address:  0x0202350C
 * packet:   pkt_0202350C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   WIPE_SUB_InitRectInterp  0x02022940  thumb
 *   WIPE_SUB_SetupWindow  0x02022E20  thumb
 *
 * wipe_sub.  Closed 2026-09-24 (wave 21, lane E2) from the DIFF 2 recorded
 * in docs/notes/WIPE_SUB_BoxInit.c.txt.  Two matching levers carry it:
 *   - the zero is an enum-typed local (docs/idioms/an-enum-typed-zero-keeps-
 *     its-own-web-where-a-u32-zero-is-folded.md), read in image order k8, z,
 *     kb;
 *   - a5 is read through a volatile access placed after the f40 store and
 *     before the f44 store.  That puts a5's load (r0, the call's first
 *     argument) inside kb's live range, so kb can no longer take r0 and the
 *     zero does, while the f48 store stays last.  A plain copy of a5 is
 *     propagated back to the f48 store and does nothing (12 out).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u32 f00;
    u8  pad04[0x0c];
    u32 f10;       /* 0x10 */
    u8  pad14[0x0c];
    u32 f20;       /* 0x20 */
    u8  pad24[0x0c];
    u32 f30;       /* 0x30 */
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
};

typedef signed int     s32;
struct Quad;
extern void WIPE_SUB_InitRectInterp(struct Quad *cur, struct Quad *end, struct Quad *step, const u8 *from, const u8 *to, s32 frames);
extern void WIPE_SUB_SetupWindow(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5,
                          u32 a6, u32 a7, u32 a8, u32 a9);

typedef enum { Z0 } E;
void WIPE_SUB_BoxInit(struct Obj *obj, const u8 *cfg, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u32 k8;
    u32 kb;
    E z;
    u32 v5;
    WIPE_SUB_InitRectInterp((struct Quad *)obj, (struct Quad *)(&obj->f20), (struct Quad *)(&obj->f10), cfg, cfg + 4, a2);
    k8 = cfg[8];
    z = Z0;
    kb = cfg[0x0b];
    obj->f30 = a4;
    obj->f40 = z;
    v5 = *(volatile u32 *)&a5;
    obj->f44 = kb;
    obj->f34 = k8;
    obj->f38 = a2;
    obj->f3c = a3;
    obj->f48 = v5;
    WIPE_SUB_SetupWindow(v5, cfg[9], cfg[0x0a], cfg[8], a4, cfg[0], cfg[1],
                  cfg[2], cfg[3], obj->f44);
}
