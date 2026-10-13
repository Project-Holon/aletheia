/*
 * function: VS_MULTI_LIST_UpdatePrintQueue
 * address:  0x021F6B38
 * packet:   pkt_ov097_021F6B38
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj07928.h"
#include "../include/Obj10194.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *);

void VS_MULTI_LIST_UpdatePrintQueue(char *p)
{
    unsigned i;
    char *e;
    int q;

    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj10194 *)p)->f1C));
    for (i = 0; i < 6; i++) {
        q = ((struct Obj10194 *)p)->f1C;
        e = p + i * 8;
        if (((struct Obj07928 *)e)->f24 != 0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj07928 *)e)->f20))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)((struct Obj07928 *)e)->f20);
                ((struct Obj07928 *)e)->f24 = 0;
            }
        }
    }
}
