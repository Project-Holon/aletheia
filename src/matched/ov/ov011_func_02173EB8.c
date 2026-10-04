/*
 * function: func_02173EB8
 * address: 0x02173EB8
 * packet: pkt_ov011_02173EB8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02175954 0x02175954 thumb ov011
 */
#include "../include/Obj12417.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct SaveBlock;
struct Rec44;
u32 func_02026478(void *obj);
void *func_020127A4(struct SaveBlock *a);
unsigned short func_02012AC8(const struct Rec44 *a);
typedef struct Rec {
    u32 lo : 15;
    u32 a : 7;
    u32 b : 10;
    u8 pad04[0x28];
    u8 f2c;
    u8 pad2d[7];
} Rec;
int func_02175954(void *unused, u8 *o, Rec *src);

void func_02173EB8(int a, int b, void *c, u8 *d)
{
    func_02012AC8(func_020127A4((struct SaveBlock *)func_02026478(((struct Obj12417 *)d)->f4)));
    if (func_02175954(d, d + 0x1ac, c) == 1) d[0x90d] = 1;
}
