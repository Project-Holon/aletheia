/*
 * function: func_021FFEC8
 * address: 0x021FFEC8
 * packet: pkt_ov135_021FFEC8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02200290 0x02200290 thumb ov135
 *   func_02200434 0x02200434 thumb ov135
 *   func_022003BC 0x022003BC thumb ov135
 *   func_02200118 0x02200118 thumb ov135
 *   func_022000E4 0x022000E4 thumb ov135
 *   func_021F4EC8 0x021F4EC8 thumb ov135
 *   func_0204B3DC 0x0204B3DC arm
 */
#include "../include/Obj00287.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02200290(u8 *);
extern void func_02200434(u8 *);
extern void func_022003BC(u8 *);
extern void func_02200118(void);
extern void func_022000E4(char *p);
extern void func_021F4EC8(u8 *);
struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
int func_021FFEC8(u8 *p)
{
    func_02200290(p);
    func_02200434(p);
    func_022003BC(p);
    func_02200118();
    if (((struct Obj00287 *)p)->f14 == 4 || ((struct Obj00287 *)p)->f14 == 5) ((struct Obj00287 *)p)->f12E4 = 1;
    func_022000E4((char *)p);
    func_0204B3DC((struct Obj *)*(u32 *)&((struct Obj00287 *)p)->fD38, 0);
    func_021F4EC8(p);
    return 0;
}
