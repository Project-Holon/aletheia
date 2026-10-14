/*
 * function: MB_SEQ_Update
 * address:  0x021C68A0
 * packet:   pkt_ov136_021C68A0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main            0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget            0x0201C6C4  thumb
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   TCBL_Main            0x020310C4  arm
 *   BMP_WIN_TransferChars            0x02045334  arm
 *   BMP_WIN_GetBmp            0x02045770  arm
 *   MB_SEQ_DrawActors 0x021C6594 thumb
 *   d_021C7DA8 0x021C7DA8 data a4
 */
#include "../include/Obj01752.h"
#include "../include/Obj08204.h"
#include "../include/Obj08205.h"
#include "../include/Obj23598.h"
#include "../include/Obj23599.h"
#include "../include/Obj23600.h"
#include "../include/Obj23601.h"
#include "../include/Obj23602.h"
#include "../include/Obj23603.h"
#include "../include/Obj23604.h"
#include "../include/Obj23605.h"
#include "../include/Obj23606.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct WinMgr;
extern int (*const d_021C7DA8[])(u8 *);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void MB_SEQ_DrawActors(u8 *);
struct Descriptor;
struct PrintSys;
struct Tcbl;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void TCBL_Main(struct Tcbl *p);
extern void PMS_DRAW_Main(u8 *p);
int MB_SEQ_Update(u8 *p, int *st)
{
    int i;
    int j;
    *st = d_021C7DA8[*st](p);
    if (*st == 0x1B) {
        return 0;
    }
    if (*(u8 * *)&((struct Obj01752 *)p)->f8 != 0) {
        BGWINFRM_UpdateMoves(**(struct WinMgr ** *)&((struct Obj01752 *)p)->f8);
        MB_SEQ_DrawActors(*(u8 * *)&((struct Obj01752 *)p)->f8);
        if (((struct Obj23598 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4 != 0) {
            PRINTSYS_QUE_Main(((struct Obj23599 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4);
            for (i = 0; i < 0x1B; i++) {
                void *h = ((struct Obj23600 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4;
                u8 *e = *(u8 * *)&((struct Obj01752 *)p)->f8 + 0xC4 + i * 8;
                if (e[4] != 0) {
                    if (PRINTSYS_QUE_IsExistTarget(h, BMP_WIN_GetBmp(((struct Obj08204 *)e)->f0)) == 0) {
                        BMP_WIN_TransferChars(((struct Obj08204 *)e)->f0);
                        e[4] = 0;
                    }
                }
            }
        }
        if (((struct Obj23601 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1CC != 0) {
            TCBL_Main(((struct Obj23602 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1CC);
        }
        if (((struct Obj23603 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f36C != 0) {
            PMS_DRAW_Main(((struct Obj23604 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f35C);
            PRINTSYS_QUE_Main(((struct Obj23605 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f36C);
            for (j = 0x1B; j < 0x20; j++) {
                void *g = ((struct Obj23606 *)(*(u8 * *)&((struct Obj01752 *)p)->f8))->f1C4;
                u8 *f = *(u8 * *)&((struct Obj01752 *)p)->f8 + 0xC4 + j * 8;
                if (f[4] != 0) {
                    if (PRINTSYS_QUE_IsExistTarget(g, BMP_WIN_GetBmp(((struct Obj08205 *)f)->f0)) == 0) {
                        BMP_WIN_TransferChars(((struct Obj08205 *)f)->f0);
                        f[4] = 0;
                    }
                }
            }
        }
    }
    return 1;
}
