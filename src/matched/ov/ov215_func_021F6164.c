/*
 * function: func_021F6164
 * address: 0x021F6164
 * packet: pkt_ov215_021F6164
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj10939.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Cfg;
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
typedef unsigned int   u32;
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
void func_021F6164(void *unused, char *p)
{
    void *obj;
    func_0201F73C(((struct Obj10939 *)p)->f58, 0, (u16)(((struct Obj10939 *)p)->f60), 2);
    obj = ((struct Obj10939 *)p)->f58;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_020409B4(BMP_WIN_GetBgLayer(obj));
}
