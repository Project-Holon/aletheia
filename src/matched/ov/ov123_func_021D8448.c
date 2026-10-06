/*
 * function: func_021D8448
 * address: 0x021D8448
 * packet: pkt_ov123_021D8448
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5AB0 0x021D5AB0 thumb ov123
 *   func_021D56FC 0x021D56FC thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D840C 0x021D840C thumb ov123
 */
#include "../include/Obj06467.h"
#include "../include/Obj22968.h"
typedef unsigned char u8;
extern u8 *func_02012944(void *p);
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern void func_021D5AB0(u8 *, int);
extern void func_021D56FC(char *, int);
extern int func_021D5950(u8 *p, int x);
extern void func_021D5960(char *, int, int);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D840C(char *p);
void func_021D8448(char *p)
{
    func_021D5AB0(*(u8 * *)&((struct Obj06467 *)p)->f18, func_0200853C((const struct Sub0200852CObj *)func_02012944(((struct Obj22968 *)(*(char * *)&((struct Obj06467 *)p)->f20))->f4)));
    func_021D56FC(*(char * *)&((struct Obj06467 *)p)->f18, 1);
    func_021D5950((u8 *)(*(char * *)&((struct Obj06467 *)p)->f18), 47);
    func_021D5960(*(char * *)&((struct Obj06467 *)p)->f18, 7, 14);
    func_021D6EE0((u8 *)p, (int)func_021D840C, 0x6b7);
}
