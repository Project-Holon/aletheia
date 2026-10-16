/*
 * function: ZUKAN_INFO_FlushSlotWindows
 * address: 0x021BAF7C
 * packet: pkt_ov206_021BAF7C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08388.h"
#include "../include/Obj25403.h"
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct PrintSys;
extern unsigned int PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *);
typedef unsigned char  u8;
struct Cfg;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void ZUKAN_INFO_FlushSlotWindows(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj08388 *)slot)->f7C == 0 && PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((struct Obj25403 *)p)->f2C), (void *)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj08388 *)slot)->f6C)) == 0) {
            int window = ((struct Obj08388 *)slot)->f6C;
            BMP_WIN_TransferChars((struct Descriptor *)window);
            BMP_WIN_MakeScreen((struct Cfg *)window);
            func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)window));
            ((struct Obj08388 *)slot)->f7C = 1;
        }
    }
}
