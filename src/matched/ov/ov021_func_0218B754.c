/*
 * function: func_0218B754
 * address:  0x0218B754
 * packet:   pkt_ov021_0218B754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocates and initialises a 0x13F8-byte object.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DD9CC     0x021DD9CC  data  ov021  a4
 *   func_0218BCE4  0x0218BCE4  thumb
 *   func_0218C490  0x0218C490  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02071.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern int d_021DD9CC;
extern void func_0218BCE4(char *p, u8 a);
extern void func_0218C490(char *p, char *q);

char *func_0218B754(int a, int b, u16 c)
{
    char *p;
    int i;
    unsigned j;
    int z = 0;

    p = (char *)func_02030734(a, 0x13F8, 0, (const char *)&d_021DD9CC, 0x193);
    ((struct Obj02071 *)p)->f0 = a;
    ((struct Obj02071 *)p)->f4 = b;
    func_0218BCE4(p + 8, c);
    for (i = 0; i < 7; i++)
        *(int *)(p + 0x1DC + i * 4) = z;
    for (j = 0; j < 0x120; j++)
        func_0218C490(p, p + 0x1F8 + j * 16);
    ((struct Obj02071 *)p)->f1B0 = 0;
    ((struct Obj02071 *)p)->f1B4 = 0;
    ((struct Obj02071 *)p)->f1B8 = 0;
    ((struct Obj02071 *)p)->f1BC = 0;
    ((struct Obj02071 *)p)->f1C0 = 0;
    ((struct Obj02071 *)p)->f1C4 = 0;
    ((struct Obj02071 *)p)->f1C8 = 0;
    ((struct Obj02071 *)p)->f1CC = 0;
    ((struct Obj02071 *)p)->f1D4 = 0;
    ((struct Obj02071 *)p)->f1D8 = 0;
    return p;
}
