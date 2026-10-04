/*
 * function: func_021B6308
 * address: 0x021B6308
 * packet: pkt_ov098_021B6308
 * region: ov098
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020310C4 0x020310C4 arm
 *   func_021F78E4 0x021F78E4 thumb ov094
 *   func_02202228 0x02202228 thumb ov094
 */
#include "../include/Obj10196.h"
struct Tcbl;
extern void func_020310C4(struct Tcbl *p);
extern void func_021F78E4(void);
extern void func_02202228(void **);
int func_021B6308(unsigned p)
{
    int (*cb)(unsigned);
    func_020310C4(((struct Obj10196 *)p)->f18);
    func_021F78E4();
    func_02202228(*(void ** *)&((struct Obj10196 *)p)->f10);
    cb = *(int (**)(unsigned))(p + 0x68);
    if (cb != 0) return cb(p);
    return 0;
}
