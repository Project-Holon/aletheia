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
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021DD700 0x021DD700 thumb ov137
 *   func_021DE248 0x021DE248 thumb ov137
 */
#include "../include/Obj00170.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045088(u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021DD700(void *,void *,void *);
extern int func_021DE248(void *,int,u16,void *);
void func_021DD638(u8 *p) {
    func_02045088(0x72);
    *(u32 *)&((struct Obj00170 *)p)->fD8=func_020450F0(5,26,20,6,2,13,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD8),0);
    *(u32 *)&((struct Obj00170 *)p)->fD4=func_020450F0(0,2,19,27,4,13,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD4),15);
    *(u32 *)&((struct Obj00170 *)p)->fDC=func_020450F0(0,3,1,26,2,15,1);
    func_021DD700(((struct Obj00170 *)p)->fDC,((struct Obj00170 *)p)->f60,((struct Obj00170 *)p)->f38);
    *(u32 *)&((struct Obj00170 *)p)->fD0=func_020450F0(0,2,6,16,11,15,1);
    func_02043B5C(func_02045770(((struct Obj00170 *)p)->fD0),0);
    func_021DE248(((struct Obj00170 *)p)->fD0,0,0x480,p);
    ((struct Obj00170 *)p)->fF8=((struct Obj00170 *)p)->fDC;
    ((struct Obj00170 *)p)->fFC=0;
}
