/*
 * function: func_021DE2D4
 * address: 0x021DE2D4
 * packet: pkt_ov171_021DE2D4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: group the integer table offset before adding its symbol base.
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_021DE290 0x021DE290 thumb ov171
 *   func_021DE064 0x021DE064 thumb ov171
 *   d_021DEBA4 0x021DEBA4 data a4
 */
#include "../include/Obj01756.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *func_021DE290(char *p, const char *q);
extern void func_021DE064(int *, int, int);
extern const char d_021DEBA4[];
void func_021DE2D4(char *p)
{
    unsigned i;
    *(int *)&((struct Obj01756 *)p)->fB70 = (int)CLACT_CreateUnit(31, 0, 0x8c);
    for (i = 0; i < 16; ++i)
        *(int *)(p + 0xb74 + i * 4) = 0;
    for (i = 12; i <= 15; ++i)
        *(int *)(p + 0xb74 + i * 4) = (int)func_021DE290(p, d_021DEBA4 + (i * 24 - 0x120));
    if (((struct Obj01756 *)p)->fC5F == 1) {
        func_021DE064((int *)p, 12, 0);
        func_021DE064((int *)p, 13, 0);
    }
}
