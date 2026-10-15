/*
 * function: BOX2_SEQ_FillTextWinEntry
 * address: 0x021EADB4
 * packet: pkt_ov170_021EADB4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201EEA4 0x0201EEA4 thumb
 *   BOX2_SEQ_PrintTextWinEx 0x021EAC28 thumb ov170
 *   BOX2_SEQ_SetDirtyBit 0x021EAAE4 thumb ov170
 *   BOX2_SEQ_MakeScreen 0x021EABA0 thumb ov170
 */
#include "../include/Obj00414.h"
#define WORK(p) (*(char **)((p)+0x2C))
typedef struct { unsigned value; unsigned char pad[14]; unsigned char low:7; unsigned char flag:1; } Entry;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201EEA4(struct WordSet *p, u32 i, void *mon);
typedef unsigned short u16;
extern void BOX2_SEQ_PrintTextWinEx(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color);
extern void BOX2_SEQ_SetDirtyBit(unsigned char *,unsigned);
extern void BOX2_SEQ_MakeScreen(void **);
void BOX2_SEQ_FillTextWinEntry(unsigned char *w,Entry *e,unsigned i) {
 void **windows;
 windows=(void **)(w+0x94);
 BMP_Clear(BMP_WIN_GetBmp(windows[i*2]),0);
 if(!e->flag) {
  func_0201EEA4(((struct Obj00414 *)w)->f84,0,(void *)e->value);
  BOX2_SEQ_PrintTextWinEx((char *)w,i,((struct Obj00414 *)w)->f80,0,0,0,((struct Obj00414 *)w)->f78,0x440);
 } else { BOX2_SEQ_SetDirtyBit(w,i); return; }
 BOX2_SEQ_MakeScreen(windows+i*2);
}
