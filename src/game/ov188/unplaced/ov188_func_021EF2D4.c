/*
 * function: func_021EF2D4
 * address: 0x021EF2D4
 * packet: pkt_ov188_021EF2D4
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u8-based bitfields retain the shift pairs; const source permits reused byte loads.
 * lever: the high-field stores are spelled +33 then +127 for the observed scheduling.
 * symbols:
 */
#include "../../../matched/include/Obj02907.h"
#include "../../../matched/include/Obj10804.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[4]; } Block16;
typedef struct { u32 w[6]; } Block24;
typedef struct { unsigned char low:5, high:3; } Bits50;
typedef struct { unsigned char low:4, mid:3, high:1; } Bits51;
int func_021EF2D4(u8 *a, const u8 *b)
{
    *(Block16 *)(a+8) = *(Block16 *)(b+24);
    *(Block24 *)(a+156) = *(Block24 *)b;
    ((struct Obj02907 *)a)->f18 = ((struct Obj10804 *)b)->f2C;
    ((struct Obj02907 *)a)->f1A = ((struct Obj10804 *)b)->f2E;
    ((struct Obj02907 *)a)->f0 = ((const Bits50 *)(b+50))->low;
    ((struct Obj02907 *)a)->f4 = ((const Bits51 *)(b+51))->low;
    a[34] = ((const Bits51 *)(b+51))->mid;
    ((struct Obj02907 *)a)->f86 = ((struct Obj10804 *)b)->f30;
    a[33] = ((const Bits50 *)(b+50))->high;
    a[127] = ((const Bits51 *)(b+51))->high;
    return 1;
}
