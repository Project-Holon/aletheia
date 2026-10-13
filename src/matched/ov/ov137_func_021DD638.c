/*
 * function: func_021DD638
 * address: 0x021DD638
 * packet: pkt_ov137_021DD638
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two-byte alignment padding at 0x021DD6FE.
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021DD700 0x021DD700 thumb ov137
 *   func_021DE248 0x021DE248 thumb ov137
 */
#include "../include/Obj00170.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BMP_WIN_Init(u16);
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021DD700(void *,void *,void *);
extern int func_021DE248(void *,int,u16,void *);
void func_021DD638(u8 *p) {
    BMP_WIN_Init(0x72);
    *(u32 *)&((struct Obj00170 *)p)->fD8=BMP_WIN_Create(5,26,20,6,2,13,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00170 *)p)->fD8),0);
    *(u32 *)&((struct Obj00170 *)p)->fD4=BMP_WIN_Create(0,2,19,27,4,13,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00170 *)p)->fD4),15);
    *(u32 *)&((struct Obj00170 *)p)->fDC=BMP_WIN_Create(0,3,1,26,2,15,1);
    func_021DD700(((struct Obj00170 *)p)->fDC,((struct Obj00170 *)p)->f60,((struct Obj00170 *)p)->f38);
    *(u32 *)&((struct Obj00170 *)p)->fD0=BMP_WIN_Create(0,2,6,16,11,15,1);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj00170 *)p)->fD0),0);
    func_021DE248(((struct Obj00170 *)p)->fD0,0,0x480,p);
    ((struct Obj00170 *)p)->fF8=((struct Obj00170 *)p)->fDC;
    ((struct Obj00170 *)p)->fFC=0;
}
