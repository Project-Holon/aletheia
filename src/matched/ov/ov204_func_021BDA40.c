/*
 * function: func_021BDA40
 * address: 0x021BDA40
 * packet: pkt_ov204_021BDA40
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BDC18 0x021BDC18 thumb ov204
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_021BF594 0x021BF594 thumb ov204
 *   func_021BF8DC 0x021BF8DC thumb ov204
 *   func_021BFC24 0x021BFC24 thumb ov204
 *   func_021BEF20 0x021BEF20 thumb ov204
 *   ov067_id 0x00000043 data
 */
#include "../include/Obj00689.h"
#include "../include/Obj25331.h"
#include "../include/Obj25332.h"
#include "../include/Obj25333.h"
struct Obj0203159C; struct GfFont; struct MsgBank;
extern int func_02034AC4(int);
extern void func_0203064C(unsigned int, unsigned, unsigned);
extern char *func_0203159C(struct Obj0203159C *, unsigned, unsigned);
extern void func_02082BCC(void *, unsigned, unsigned);
extern unsigned char *func_021BDC18(int, int, unsigned short);
extern struct GfFont *func_0201D7EC(int, int, int, int, unsigned);
extern struct MsgBank *func_02045B38(unsigned, unsigned, unsigned, unsigned);
extern char *func_021BF594(unsigned short, int);
typedef unsigned int   u32;
extern char *func_021BF8DC(void *owner, int kind, u32 heap);
extern char *func_021BFC24(void *owner, unsigned heap);
extern char *func_021BEF20(void *, unsigned, unsigned, char *, unsigned, unsigned short);
extern const char ov067_id[];
int func_021BDA40(struct Obj0203159C *owner, int unused, char *args)
{
    char *p;
    func_02034AC4((int)ov067_id);
    func_0203064C(1, 111, 0x100000);
    p = func_0203159C(owner, 0x24, 111);
    func_02082BCC(p, 0, 0x24);
    ((struct Obj00689 *)p)->f0 = 111;
    *(char * *)&((struct Obj00689 *)p)->f4 = args;
    *(unsigned char * *)&((struct Obj00689 *)p)->f8 = func_021BDC18(1, ((struct Obj25331 *)args)->f8, ((struct Obj00689 *)p)->f0);
    *(struct GfFont * *)&((struct Obj00689 *)p)->fC = func_0201D7EC(23, 0, 0, 0, ((struct Obj00689 *)p)->f0);
    *(struct MsgBank * *)&((struct Obj00689 *)p)->f10 = func_02045B38(0, 2, 65, ((struct Obj00689 *)p)->f0);
    *(char * *)&((struct Obj00689 *)p)->f18 = func_021BF594(((struct Obj00689 *)p)->f0, ((struct Obj25332 *)(*(char * *)&((struct Obj00689 *)p)->f4))->f8);
    ((struct Obj00689 *)p)->f1C = func_021BF8DC(*(unsigned char * *)&((struct Obj00689 *)p)->f8, ((struct Obj25333 *)(*(char * *)&((struct Obj00689 *)p)->f4))->f8, ((struct Obj00689 *)p)->f0);
    ((struct Obj00689 *)p)->f20 = func_021BFC24(*(unsigned char * *)&((struct Obj00689 *)p)->f8, ((struct Obj00689 *)p)->f0);
    *(char * *)&((struct Obj00689 *)p)->f14 = func_021BEF20(((struct Obj00689 *)p)->f1C, *(unsigned *)&((struct Obj00689 *)p)->f20, *(unsigned *)&((struct Obj00689 *)p)->f18, *(char * *)&((struct Obj00689 *)p)->f4, *(unsigned *)&((struct Obj00689 *)p)->f8, ((struct Obj00689 *)p)->f0);
    return 1;
}
