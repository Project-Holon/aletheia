/*
 * function: BSUBWAY_RECORD_LIST_UpdateText
 * address:  0x021B9DFC
 * packet:   pkt_ov069_021B9DFC
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 */
#include "../include/Obj06172.h"

typedef unsigned int   u32;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_WIN_TransferChars(struct Descriptor *d);

void BSUBWAY_RECORD_LIST_UpdateText(unsigned char *p)
{
    int i;
    int h;

    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj06172 *)p)->fE8));
    for (i = 0; i < 18; i++) {
        h = ((struct Obj06172 *)p)->fE8;
        if (p[i * 8 + 0x5C] != 0) {
            if (func_0201C6C4((struct PrintSys *)h, (void *)((int)func_02045770((struct Descriptor *)*(int *)(p + i * 8 + 0x58)))) == 0) {
                BMP_WIN_TransferChars((struct Descriptor *)*(int *)(p + i * 8 + 0x58));
                p[i * 8 + 0x5C] = 0;
            }
        }
    }
}
