/*
 * function: STA_ACTING_UpdateText
 * address: 0x021F9374
 * packet: pkt_ov132_021F9374
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj02849.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Descriptor;
struct PrintSys;
struct Rec3;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void STA_ACTING_UpdateText(u8 *p)
{
    TCBL_Main(((struct Obj02849 *)p)->fCC);
    if (((struct Obj02849 *)p)->fD8 && PRINTSYS_PrintStreamGetState(((struct Obj02849 *)p)->fD8) == 2) {
        PRINTSYS_PrintStreamDelete(((struct Obj02849 *)p)->fD8);
        ((struct Obj02849 *)p)->fD8 = 0;
    }
    if (((struct Obj02849 *)p)->fE4 == 1) {
        PRINTSYS_QUE_Main(((struct Obj02849 *)p)->fE8);
        if (PRINTSYS_QUE_IsFinished(((struct Obj02849 *)p)->fE8) == 1) {
            BMP_WIN_TransferChars(((struct Obj02849 *)p)->fD0);
            ((struct Obj02849 *)p)->fE4 = 0;
        }
    }
}
