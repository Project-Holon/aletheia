/*
 * function: func_021D840C
 * address: 0x021D840C
 * packet: pkt_ov123_021D840C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D83C8 0x021D83C8 thumb ov123
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D5960 0x021D5960 thumb ov123
 */
#include "../include/Obj13994.h"
extern void func_021D6EE0(char *, int, int);
extern void func_021D83C8(char *);
extern unsigned int func_020362DC(void);
extern int func_02035C60(void);
extern void func_021D5950(char *, int);
extern void func_021D5960(char *, int, int);
void func_021D840C(char *p)
{
    if (func_020362DC() || func_02035C60()) {
        func_021D5950(*(char * *)&((struct Obj13994 *)p)->f18, 48);
        func_021D5960(*(char * *)&((struct Obj13994 *)p)->f18, 7, 14);
        func_021D6EE0(p, (int)func_021D83C8, 0x6ab);
    }
}
