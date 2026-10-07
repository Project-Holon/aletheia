/*
 * function: func_021D770C
 * address: 0x021D770C
 * packet: pkt_ov125_021D770C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D9E40 0x021D9E40 data a4
 *   d_021DA040 0x021DA040 data a4
 *   func_021D7808 0x021D7808 arm ov125
 *   func_021D7CEC 0x021D7CEC arm ov125
 *   func_021D7D20 0x021D7D20 arm ov125
 */

#include "../include/G_Clear.h"

typedef struct { int words[78]; } Clear;
extern struct Clear d_021D9E40;
extern char d_021DA040[];
extern void func_021D7808(void);
extern int func_021D7CEC(void *);
extern void func_021D7D20(void);
void func_021D770C(void)
{
    func_021D7808();
    __builtin__clear(&d_021D9E40, sizeof(Clear));
    *(int *)((char *)&d_021D9E40 + 0x138) = 0;
    *((char *)&d_021D9E40 + 0x140) = 0;
    *(short *)(d_021DA040 + 0x40) = 0;
    func_021D7CEC(d_021DA040);
    func_021D7D20();
}
