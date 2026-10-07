/*
 * file:     unit_02173CB0_p02.c
 * unit:     yes
 * function: func_02173E6C, func_02173EB8
 * address:  0x02173E6C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02026478 0x02026478 thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02175954 0x02175954 thumb ov011
 */
#include "../../matched/include/Obj12417.h"

struct Entry;
struct SaveBlock;
struct Rec44;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct Rec {
    u32 lo : 15;
    u32 a : 7;
    u32 b : 10;
    u8 pad04[0x28];
    u8 f2c;
    u8 pad2d[7];
} Rec;

int func_021736D8(void);
u32 func_0203D1C0(u32 index);
struct Entry *func_020399A8(void);
u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_02026478(void *obj);
void *func_020127A4(struct SaveBlock *a);
unsigned short func_02012AC8(const struct Rec44 *a);
int func_02175954(void *unused, u8 *o, Rec *src);
int func_02173E6C(int a, int b, int c);
void func_02173EB8(int a, int b, void *c, u8 *d);


int func_02173E6C(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    if (func_0203D1C0(c & 0xFF) == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), (unsigned char)c, 0x211, 0x38, b, 0, 0, 0);
}


void func_02173EB8(int a, int b, void *c, u8 *d)
{
    func_02012AC8(func_020127A4((struct SaveBlock *)func_02026478(((struct Obj12417 *)d)->f4)));
    if (func_02175954(d, d + 0x1ac, c) == 1) d[0x90d] = 1;
}
