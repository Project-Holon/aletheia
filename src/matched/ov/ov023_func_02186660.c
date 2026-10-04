/*
 * function: func_02186660
 * address: 0x02186660
 * packet: pkt_ov023_02186660
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x02186692.
 * lever: naming the accessor result before clearing r preserves call/store scheduling.
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02186694 0x02186694 thumb ov023
 */
#include "../include/Obj03625.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Obj;
struct TaskMenu;
extern void func_02027974(struct Obj *);
extern u32 func_020279E8(struct TaskMenu *);
extern u8 func_02027A04(const u8 *);
extern void func_02186694(char *);
int func_02186660(char *p)
{
    int r = 2;
    func_02027974(*(struct Obj * *)&((struct Obj03625 *)p)->f178);
    if (func_020279E8(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178) != 0) {
        u8 v = func_02027A04(*(const u8 * *)&((struct Obj03625 *)p)->f178);
        r = 0;
        if (v != 0) r = 1;
        func_02186694(p);
    }
    return r;
}
