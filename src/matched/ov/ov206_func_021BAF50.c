/*
 * function: ZUKAN_INFO_ClearSlotWindows
 * address: 0x021BAF50
 * packet: pkt_ov206_021BAF50
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 */
#include "../include/Obj14637.h"
#include "../include/Obj25402.h"
typedef unsigned char  u8;
struct CharBuf;
struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
void ZUKAN_INFO_ClearSlotWindows(char *p)
{
    int i;
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj25402 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        ((struct Obj14637 *)slot)->f7C = 1;
        BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj14637 *)slot)->f6C)), 0);
    }
}
