/*
 * function: ZKNSEARCH_MAIN_UpdateBmpWindows
 * address: 0x021BE3D4
 * packet: pkt_ov210_021BE3D4
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: each int offset is assigned 0x1DC, then its final literal;
 *        spilled locals retain both stores without a reload.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`release = 0x1dc;` before `release = 0x14c;`; `clear = 0x1dc;` before
 * `clear = 0x150;` and 2 more). Game code has no line table, so these were
 * stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj08413.h"
typedef unsigned char u8;
struct PrintSys;
struct Descriptor;
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *, void *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void ZKNSEARCH_MAIN_UpdateBmpWindows(u8 *p)
{
    int release, clear, get, flag;
    unsigned i;
    PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC);
    release = 0x14c;
    clear = 0x150;
    get = 0x14c;
    flag = 0x150;
    for (i = 0; i < 16; i++) {
        struct PrintSys *ps = *(struct PrintSys * *)&((struct Obj08413 *)p)->f1DC;
        u8 *record = p + i * 8;
        if (record[flag] != 0 && PRINTSYS_QUE_IsExistTarget(ps, BMP_WIN_GetBmp(*(struct Descriptor **)(record + get))) == 0) {
            BMP_WIN_TransferChars(*(struct Descriptor **)(record + release));
            record[clear] = 0;
        }
    }
}
