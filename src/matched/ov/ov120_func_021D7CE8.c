/*
 * function: GTSNEGO_MSG_RedrawRow
 * address: 0x021D7CE8
 * packet: pkt_ov120_021D7CE8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D7D2E.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 */
#include "../include/Obj08081.h"
typedef unsigned short u16;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
typedef signed short   s16;
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void GTSNEGO_MSG_RedrawRow(char *p,u16 n,int i)
{
    void *q=*(void **)(p+0x38+4*i);
    if(q) {
        BMP_Clear(BMP_WIN_GetBmp(q),0);
        MSGDATA_ReadString(((struct Obj08081 *)p)->fC,n,(void *)(((struct Obj08081 *)p)->f18));
        PRINTSYS_Print(BMP_WIN_GetBmp(q),2,2,(void *)(((struct Obj08081 *)p)->f18),(void *)(((struct Obj08081 *)p)->f14));
        BMP_WIN_TransferChars(q);
    }
}
