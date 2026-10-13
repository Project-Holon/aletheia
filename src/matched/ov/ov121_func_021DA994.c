/*
 * function: func_021DA994
 * address: 0x021DA994
 * packet: pkt_ov121_021DA994
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021DAA28 0x021DAA28 thumb ov121
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 */
#include "../include/Obj03787.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct MsgBank;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021DAA28(char *,int,int *);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021DA994(char *p,int a,int b,int c)
{
    int xy[2];
    BMP_Clear((struct CharBuf *)(((struct Obj03787 *)p)->f0),(u8)(((struct Obj03787 *)p)->f4&31));
    MSGDATA_ReadString((struct MsgBank *)a,b,((struct Obj03787 *)p)->f18);
    func_021DAA28(p,c,xy);
    PRINTSYS_PrintQueColor(((struct Obj03787 *)p)->f20,((struct Obj03787 *)p)->f0,(s16)xy[0],(s16)xy[1],(u32)(((struct Obj03787 *)p)->f18),c,((struct Obj03787 *)p)->f4);
    ((struct Obj03787 *)p)->f8=1;
}
