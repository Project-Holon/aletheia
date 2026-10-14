/*
 * function: DENDOU_VIEW_FlushWindows
 * address: 0x021DD8DC
 * packet: pkt_ov171_021DD8DC
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: offset locals carry both their initial and replacement constants.
 * note 2026-10-05 (wave D9r lane 131): removed the 4 dead first assignments
 * (`a = 0xb6c;` before `a = 0xb48;`; `b = 0xb6c;` before `b = 0xb4c;` and 2
 * more). Game code has no line table, so these were stand-ins. The plain
 * single assignment gives EXACT in --lang c99 and --lang c: the output bytes
 * do not change. Older text in this header that asks for the double
 * assignment is superseded.
 *
 * symbols:
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj14290.h"
typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void DENDOU_VIEW_FlushWindows(char *p)
{
    int a, b, c, d;
    unsigned i;
    int obj;
    char *q;
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj14290 *)p)->fB6C));
    a = 0xb48;
    b = 0xb4c;
    c = 0xb48;
    d = 0xb4c;
    for (i = 0; i < 2; ++i) {
        obj = ((struct Obj14290 *)p)->fB6C;
        q = p + i * 8;
        if (*(unsigned char *)(q + d)) {
            if (!PRINTSYS_QUE_IsExistTarget((struct PrintSys *)obj, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)(q + c))))) {
                BMP_WIN_TransferChars((struct Descriptor *)*(int *)(q + a));
                *(unsigned char *)(q + b) = 0;
            }
        }
    }
}
