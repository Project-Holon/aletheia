/*
 * function: ITEMMENU_FlushDirtyWindows
 * address:  0x021BB73C
 * packet:   pkt_ov070_021BB73C
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Eleven dirty-window cleanup blocks. Code/pool ends at 0x021BB95C;
 * remaining handed extent is tables/strings, not an unlabelled follower.
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj09884.h"
#include "../include/Obj20678.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

static inline void clean(u8 *p, int off)
{
    void *t = ((struct Obj09884 *)p)->f50C;
    if (p[off] != 0) {
        if (PRINTSYS_QUE_IsExistTarget(t, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + off - 4)))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)(p + off - 4));
            p[off] = 0;
        }
    }
}

void ITEMMENU_FlushDirtyWindows(u8 *p)
{
    PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj20678 *)p)->f50C);
    clean(p, 0x738);
    clean(p, 0x740);
    clean(p, 0x748);
    clean(p, 0x750);
    clean(p, 0x758);
    clean(p, 0x760);
    clean(p, 0x768);
    clean(p, 0x770);
    clean(p, 0x778);
    clean(p, 0x500);
    clean(p, 0x508);
}
