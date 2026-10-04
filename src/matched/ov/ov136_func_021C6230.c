/*
 * function: func_021C6230
 * address: 0x021C6230
 * packet: pkt_ov136_021C6230
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C6230 0x021C6230 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 */
#include "../include/Obj00127.h"
#include "../include/Obj23559.h"
#include "../include/Obj23560.h"
#include "../include/Obj23561.h"
#include "../include/Obj23562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
struct CharBuf;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);

void func_021C6230(u8 *p)
{
    u32 win = ((struct Obj23559 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->fA8;
    u32 w2;
    w2 = (u32)func_02045770((struct Descriptor *)win);
    func_02043B5C((struct CharBuf *)w2, 0xf);
    ((struct Obj23562 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1C8 = func_0201CCE4(win, 0, 0, ((struct Obj23560 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8, ((struct Obj00127 *)p)->f18, func_02012FFC(), ((struct Obj23561 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1CC, 0, 0x66, 0xf);
}
