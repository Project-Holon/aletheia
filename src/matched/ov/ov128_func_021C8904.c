/*
 * function: func_021C8904
 * address: 0x021C8904
 * packet: pkt_ov128_021C8904
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   func_021C8A80 0x021C8A80 thumb ov128
 *   func_021C8B90 0x021C8B90 thumb ov128
 *   GAME_DATA_GetWifiList  0x0201283C  thumb  arm9
 */
#include "../include/Obj05381.h"
#include "../include/Obj23090.h"
#include "../include/Obj23091.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BigObj;
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_021C8A50(char *p, int unused);
extern void func_021C8A80(u8 *p, void *a, u8 *b, int unused, int i, void *base, int idx, u16 heap);
extern void func_021C8B90(char *p, char *q, int unused, int i, u16 h);
void func_021C8904(char *p,char *q,void *r,void *s,int t,char *table,int page,u16 heap) {
 int i;int offset;void *base;int found;char *row;void *v;
 base=(void *)GAME_DATA_GetWifiList(((struct Obj23090 *)q)->f4);
 v=func_02045770(**(void ** *)&((struct Obj05381 *)p)->f8);
 found=0;
 BMP_Clear(v,0);
 func_021C8A50(p,(int)r);
 offset=page*8;i=0;row=table+offset;
 for(;i<8;i++) {
  if(((struct Obj23091 *)table)->f0 > offset+i) {
   func_021C8A80((u8 *)p,s,r,t,i,base,(u8)row[i+8],heap);found=1;
  } else func_021C8B90(p,r,t,i,heap);
 }
 if(!found)BMP_WIN_TransferChars(**(void ** *)&((struct Obj05381 *)p)->f8);
}
