/*
 * function: IRC_RHYTHM_InitTextWindow
 * address: 0x021B7E58
 * packet: pkt_ov104_021B7E58
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: c and its callee parameter are u8; u32 hoists its spill reload.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
#include "../include/Obj03233.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
void IRC_RHYTHM_InitTextWindow(u8 *p,u32 a,u32 b,u8 c,u8 d,u8 e,u8 f,u16 color,u8 heap,u16 size) { void *q; MI_CpuFill8(p,0,0x14); ((struct Obj03233 *)p)->f10=color; ((struct Obj03233 *)p)->f0=(void *)BMP_WIN_Create(a,b,c,d,e,f,heap); ((struct Obj03233 *)p)->fC=STRBUF_Create(0xff,size); ((struct Obj03233 *)p)->f4=((struct Obj03233 *)p)->f0; p[8]=0; BMP_Clear(BMP_WIN_GetBmp(((struct Obj03233 *)p)->f0),((struct Obj03233 *)p)->f10); q=((struct Obj03233 *)p)->f0; BMP_WIN_TransferChars(q); BMP_WIN_MakeScreen(q); BG_SYS_PushTile(BMP_WIN_GetBgLayer(q)); }
