/*
 * function: func_021BDB20
 * address: 0x021BDB20
 * packet: pkt_ov203_021BDB20
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045C04 0x02045C04 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021BDD18 0x021BDD18 thumb ov203
 *   func_021BE4B4 0x021BE4B4 thumb ov203
 *   func_021BDE98 0x021BDE98 thumb ov203
 *   ov067_id 0x00000043 data a1
 */
#include "../include/Obj06664.h"
typedef unsigned int   u32;
struct PrintSys;
struct Rec;
struct S020315D4;
extern void func_02023F98(u32 mask);
extern void func_021BDD18(char *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021BE4B4(char *ctx);
extern void func_021BDE98(char *ctx);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_02034A5C(int);
extern const char ov067_id[];
int func_021BDB20(void *a, void *b, void *c, char *work)
{
    func_02023F98(3);
    func_021BDD18(*(char * *)&((struct Obj06664 *)work)->f1C);
    func_02045C04(((struct Obj06664 *)work)->f14);
    func_0201C4C0(((struct Obj06664 *)work)->f10);
    func_021BE4B4(((struct Obj06664 *)work)->f18);
    func_021BDE98(((struct Obj06664 *)work)->fC);
    func_020315D4(a);
    func_020306F0(0x6c);
    func_02034A5C((int)ov067_id);
    return 1;
}
