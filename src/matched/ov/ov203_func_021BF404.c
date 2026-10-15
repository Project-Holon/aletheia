/*
 * function: func_021BF404
 * address: 0x021BF404
 * packet: pkt_ov203_021BF404
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 */
#include "../include/Obj14596.h"
typedef struct { char *ctx;int pad4[2];int c;int a;int b;void *text;void *window;int pad20[2]; } Work;
typedef unsigned char  u8;
struct CharBuf;
extern void MI_CpuFill8(void *,int,int);
extern void func_02049B40(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *BMP_MENUWORK_LoadFrameGfx(void *,unsigned,unsigned,unsigned);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
void func_021BF404(char *p,Work *out,int a,int b,int c,unsigned char d,unsigned char e,unsigned char f,unsigned char g)
{
    MI_CpuFill8(out,0,0x28);
    out->a=a;out->c=c;out->ctx=p;out->b=b;
    out->text=BMP_MENUWORK_LoadFrameGfx((void *)1,0,1,((struct Obj14596 *)p)->f2);
    func_02049B40(23,5,0,32,32,((struct Obj14596 *)p)->f2);
    out->window=(void *)BMP_WIN_Create(1,d,e,f,g,1,0);
    BMP_Clear(BMP_WIN_GetBmp(out->window),15);
}
