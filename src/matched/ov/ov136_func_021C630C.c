/*
 * function: func_021C630C
 * address: 0x021C630C
 * packet: pkt_ov136_021C630C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021C6230 0x021C6230 thumb ov136
 */
#include "../include/Obj00127.h"
#include "../include/Obj23569.h"
#include "../include/Obj23570.h"
#include "../include/Obj23571.h"
#include "../include/Obj23572.h"
#include "../include/Obj23573.h"
#include "../include/Obj23574.h"
#include "../include/Obj23575.h"
#include "../include/Obj23576.h"
#include "../include/Obj23577.h"
#include "../include/Obj23578.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021C6230(u8 *);
void func_021C630C(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: func_02045CAC(((struct Obj23569 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D0, 10, ((struct Obj23570 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8); break;
    case 1: func_02045CAC(((struct Obj23571 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D0, 11, ((struct Obj23572 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8); break;
    case 2: func_02045CAC(((struct Obj23573 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D0, 12, ((struct Obj23574 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8); break;
    case 3: func_02045CAC(((struct Obj23575 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D0, 13, ((struct Obj23576 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8); break;
    case 4: func_02045CAC(((struct Obj23577 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D0, 14, ((struct Obj23578 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->f1D8); break;
    }
    func_021C6230(p);
}
