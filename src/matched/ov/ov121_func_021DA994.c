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
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021DAA28 0x021DAA28 thumb ov121
 */
#include "../include/Obj03787.h"
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct MsgBank;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021DAA28(char *,int,int *);
extern void func_0201C724(void *,int,s16,s16,void *,int,u16);
void func_021DA994(char *p,int a,int b,int c)
{
    int xy[2];
    func_02043B5C((struct CharBuf *)(((struct Obj03787 *)p)->f0),(u8)(((struct Obj03787 *)p)->f4&31));
    func_02045CAC((struct MsgBank *)a,b,((struct Obj03787 *)p)->f18);
    func_021DAA28(p,c,xy);
    func_0201C724(((struct Obj03787 *)p)->f20,((struct Obj03787 *)p)->f0,(s16)xy[0],(s16)xy[1],((struct Obj03787 *)p)->f18,c,((struct Obj03787 *)p)->f4);
    ((struct Obj03787 *)p)->f8=1;
}
