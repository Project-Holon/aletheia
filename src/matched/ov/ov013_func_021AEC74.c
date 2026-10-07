/*
 * function: func_021AEC74
 * address: 0x021AEC74
 * packet: pkt_ov013_021AEC74
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 the call to func_021B20B0 is written in each arm of the
 *   null test (new allocation, existing node); the compiler cross-jumps the
 *   shared tail and the first arm uses the call result register directly.
 * symbols:
 *   d_021B3C80 0x021B3C80 data ov013 a4
 *   func_021B1F2C 0x021B1F2C arm ov013
 *   func_021B20B0 0x021B20B0 arm ov013
 *   func_021B1F54 0x021B1F54 arm ov013
 */

#include "../include/G_Work.h"

typedef unsigned char u8;
struct Node;

extern struct Work *d_021B3C80;

extern struct Node *func_021B1F2C(unsigned int i);
extern int func_021B20B0(int p, int x);
extern int func_021B1F54(struct Node *p);

int func_021AEC74(int i)
{
    struct Node *p = d_021B3C80->f1A1C;
    int r;

    if (p == 0) {
        p = func_021B1F2C(i);
        if (p == 0) {
            return 0;
        }
        r = func_021B20B0((int)p, 0);
    } else {
        r = func_021B20B0((int)p, 0);
    }
    if (r != 0) {
        func_021B1F54(p);
        d_021B3C80->f1A1C = 0;
        return 0;
    }
    d_021B3C80->f1A1C = p;
    return 1;
}
