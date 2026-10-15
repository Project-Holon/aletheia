/*
 * function: BOX2_SEQ_PrintTextWin
 * address: 0x021EABD0
 * packet: pkt_ov170_021EABD0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj23962.h"
#define WORK(p) (*(char **)((p)+0x2C))
typedef unsigned int   u32;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
typedef unsigned short u16;
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
void BOX2_SEQ_PrintTextWin(unsigned char *w,int i,void *bank,unsigned idx,int x,int y,unsigned font,unsigned short color) {
 void *s; unsigned print;
 s=func_02045EC0(bank,idx);
 print=((struct Obj23962 *)w)->f8C;
 PRINTSYS_PrintQueColor((void *)print,(u32)BMP_WIN_GetBmp(*(void **)(w+0x94+i*8)),(short)x,(short)y,(u32)s,font,color);
 *(w+i*8+0x98)=1;
 STRBUF_Delete(s);
}
