/*
 * function: func_021EACA8
 * address: 0x021EACA8
 * packet: pkt_ov170_021EACA8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021EAC98 0x021EAC98 thumb ov170
 *   func_021EABD0 0x021EABD0 thumb ov170
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_021EABA0 0x021EABA0 thumb ov170
 */
#include "../include/Obj14269.h"
#include "../include/Obj23963.h"
#include "../include/Obj23964.h"
#define WORK(p) (*(char **)((p)+0x2C))
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct Rec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_021EAC98(void);
extern void func_021EABD0(unsigned char *,int,void *,unsigned,int,int,unsigned,unsigned short);
typedef unsigned int   u32;
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void func_021EABA0(void **);
void func_021EACA8(unsigned char *p) {
 unsigned char *w; void *bank;
 w=(unsigned char *)WORK(p);
 BMP_Clear(BMP_WIN_GetBmp(((struct Obj14269 *)w)->f94),0);
 bank=func_021EAC98();
 func_021EABD0(w,0,bank,((struct Obj23964 *)(*(char * *)&((struct Obj23963 *)p)->f0))->f24+0x25,0,8,((struct Obj14269 *)w)->f78,0x440);
 MSGDATA_Delete(bank);
 func_021EABA0((void **)(WORK(p)+0x94));
}
