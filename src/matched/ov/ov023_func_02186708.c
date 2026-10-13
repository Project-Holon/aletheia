/*
 * function: OEKAKI_UpdatePrintJobs
 * address:  0x02186708
 * packet:   pkt_ov023_02186708
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj03626.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *a);

void OEKAKI_UpdatePrintJobs(char *p)
{
    int i;
    u32 h;

    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj03626 *)p)->f164));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj03626 *)p)->f168));
    for (i = 0; i < 5; i++) {
        h = ((struct Obj03626 *)p)->f164;
        if (*(u8 *)(p + i * 8 + 0x130) != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)h, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C)))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C));
                *(u8 *)(p + i * 8 + 0x130) = 0;
            }
        }
    }
    h = ((struct Obj03626 *)p)->f168;
    if (((struct Obj03626 *)p)->f160 != 0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)h, (void *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj03626 *)p)->f15C))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct Obj03626 *)p)->f15C);
            ((struct Obj03626 *)p)->f160 = 0;
        }
    }
}
