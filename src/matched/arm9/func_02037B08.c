/*
 * function: GFL_NET_SYSTEM_FreeWork
 * address:  0x02037B08
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession   0x0203D788  arm
 *   GFL_NET_GetInitParam   0x0203D798  arm
 *   func_020307B0   0x020307B0  arm
 *   GFL_NET_QUEUE_Exit   0x02036B88  arm
 *   _pNetSys      0x021469D0  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SYSTEM_FreeWork.c \
 *       --func GFL_NET_SYSTEM_FreeWork --addr 0x02037B08 --cc 1.1p1 --arm
 */

#include "../include/G_LinkState.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *GFL_NET_GetSession(void);
extern void *GFL_NET_GetInitParam(void);
extern u32 func_020307B0(void *p);
extern void  GFL_NET_QUEUE_Exit(void *p);

extern struct LinkState *_pNetSys;

void GFL_NET_SYSTEM_FreeWork(void)
{
    GFL_NET_GetSession();
    GFL_NET_GetInitParam();

    if (_pNetSys == 0) {
        return;
    }

    func_020307B0(_pNetSys->f14);
    func_020307B0(_pNetSys->f18);
    func_020307B0(_pNetSys->f10);

    GFL_NET_QUEUE_Exit(&_pNetSys->obj_F4);
    GFL_NET_QUEUE_Exit(&_pNetSys->obj_CC);

    func_020307B0(_pNetSys->f0);
    func_020307B0(_pNetSys->f04);
    func_020307B0(_pNetSys->f08);
    func_020307B0(_pNetSys->f0C);

    func_020307B0(_pNetSys);

    _pNetSys = 0;
}
