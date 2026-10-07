/*
 * function: func_021EEE78
 * address:  0x021EEE78
 * packet:   pkt_021EEE78
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EEFA4  0x021EEFA4  thumb  ov188
 *   func_021EF014  0x021EF014  thumb  ov188
 *   func_021EF1AC  0x021EF1AC  thumb  ov188
 *   func_021EF1F4  0x021EF1F4  thumb  ov188
 *   g_0214616C     0x0214616C  data
 */

#include "../include/G_BattleRec.h"

typedef unsigned int u32;

extern void func_021EEFA4(int *a, char *p);
typedef unsigned char  u8;
extern void func_021EF014(u8 *a, u8 *b);
extern int func_021EF1AC(char *p, char *q);
extern int func_021EF1F4(const u8 *a, u8 *b);
extern struct BattleRec *g_0214616C;

void func_021EEE78(void *p)
{
    char *q = ((char *)g_0214616C) + 0xc4;

    func_021EEFA4(p, q);
    func_021EF014(p, (u8 *)q);
    func_021EF1AC(p, q);
    func_021EF1F4(p, (u8 *)q);
}
