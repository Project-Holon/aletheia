/*
 * function: WIPE_SUB_SetupWindow
 * address:  0x02022E20
 * packet:   pkt_02022E20
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SUB_SetWindowInside  0x02023B74  thumb
 *   WIPE_SUB_SetWindowOutside  0x02023BFC  thumb
 *   WIPE_SUB_SetWindowRect  0x02023C3C  thumb
 *   WIPE_SUB_RequestWindowInside  0x02023D18  thumb
 *   WIPE_SUB_RequestWindowOutside  0x02023D40  thumb
 *   WIPE_SUB_RequestWindowRect  0x02023D60  thumb
 *
 * The family's ten-argument setup dispatcher, called from WIPE_SUB_BoxInit
 * with a wipe's configuration block already unpacked into registers and
 * stack.  The last argument selects the shape: zero takes the window
 * path (WIPE_SUB_SetWindowInside / WIPE_SUB_SetWindowOutside / WIPE_SUB_SetWindowRect) and anything else
 * takes the blend path (WIPE_SUB_RequestWindowInside / WIPE_SUB_RequestWindowOutside / WIPE_SUB_RequestWindowRect).
 *
 * The two arms are written out in full rather than factored, which is
 * what keeps them as two separate three-call sequences with their own
 * epilogues rather than one tail-merged tail
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/WIPE_SUB_SetupWindow.c \
 *       --func WIPE_SUB_SetupWindow --addr 0x02022E20 --cc 1.1p1 --thumb
 */

typedef unsigned int  u32;

extern void WIPE_SUB_SetWindowInside(u32 a0, u32 a1, u32 a2, u32 a3);
extern void WIPE_SUB_SetWindowOutside(u32 a0, u32 a1, u32 a2);
extern void WIPE_SUB_SetWindowRect(u32 x2, u32 y2, u32 x1, u32 y1, int win, int sub);
extern void WIPE_SUB_RequestWindowInside(void *obj, void *val, u32 f4, u32 f8, u32 fC);
extern void WIPE_SUB_RequestWindowOutside(void *obj, void *val, u32 f4, u32 f8);
typedef unsigned char  u8;
extern void WIPE_SUB_RequestWindowRect(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);

void WIPE_SUB_SetupWindow(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                   u32 a7, u32 a8, u32 a9)
{
    if (a9 == 0) {
        WIPE_SUB_SetWindowInside(a1, 0, a3, a4);
        WIPE_SUB_SetWindowOutside(a2, 0, a4);
        WIPE_SUB_SetWindowRect(a5, a6, a7, a8, a3, a4);
    } else {
        WIPE_SUB_RequestWindowInside((void *)a0, (void *)a1, 0, a3, a4);
        WIPE_SUB_RequestWindowOutside((void *)a0, (void *)a2, 0, a4);
        WIPE_SUB_RequestWindowRect((u8 *)a0, a5, a6, a7, a8, a3, a4);
    }
}
