/*
 * file:     palette_anime_p19.c
 * unit:     yes
 * function: func_021C2BF0, func_021C2C30, func_021C2C70
 * address:  0x021C2BF0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02021F64 0x02021F64 thumb
 *   func_021C2A28 0x021C2A28 thumb ov217
 *   func_021C2D88 0x021C2D88 thumb ov217
 */
#include "../../matched/include/Obj00115.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Rgb555_021C2BF0 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

struct Rgb555_021C2C30 { u16 r:5; u16 g:5; u16 b:5; u16 pad:1; };

struct Rgb555_021C2C70 {
    unsigned short r : 5;
    unsigned short g : 5;
    unsigned short b : 5;
    unsigned short pad : 1;
};

extern void func_02021F64(u16 *,u16 *,u32,int,u16);
extern void func_021C2A28(void *);
extern int func_021C2D88(char *);
void func_021C2BF0(u8 *p);
void func_021C2C30(u8 *p);
void func_021C2C70(char *p);

void func_021C2BF0(u8 *p)
{
    int weight;
    if ((((struct Obj00115 *)p)->f1C >> 2 & 1) == 0) weight=0;
    else weight=6;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],weight,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C += 1;
    if (((struct Obj00115 *)p)->f1C>20) {
        func_021C2A28(p);
        func_021C2D88((char *)p);
    }
}

/*
 * tail: two zero padding bytes at 0x021C2C6E, not a follower.
 * ABI: 02021F64 reads its fifth stack input as one RGB555 halfword;
 *      original caller stores the numeric u16 color as a full stack word.
 *      The legacy aggregate declaration inserts an extra strh setup.
 */
void func_021C2C30(u8 *p)
{
    int weight;
    if ((((struct Obj00115 *)p)->f1C >> 2 & 1) == 0) weight=0;
    else weight=6;
    func_02021F64(*(u16 * *)&((struct Obj00115 *)p)->fC,*(u16 * *)&((struct Obj00115 *)p)->f8,p[0x10],weight,((struct Obj00115 *)p)->f12);
    ((struct Obj00115 *)p)->f1C += 1;
    if (((struct Obj00115 *)p)->f1C>10) {
        func_021C2A28(p);
        func_021C2D88((char *)p);
    }
}

/*
 * Tail: 021C2CAE..021C2CB0 is two zero alignment bytes.
 * Callee 02021F64's legacy Rgb555 aggregate input reads only its low
 * stack halfword; scalar u16 preserves the original caller's str word.
 */
void func_021C2C70(char *p)
{
    int weight = ((((struct Obj00115 *)p)->f1C >> 2) & 1) == 0 ? 0 : 6;
    func_02021F64(*(unsigned short * *)&((struct Obj00115 *)p)->fC, *(unsigned short * *)&((struct Obj00115 *)p)->f8, ((struct Obj00115 *)p)->f10, weight, ((struct Obj00115 *)p)->f12);
    if (++((struct Obj00115 *)p)->f1C > 30) {
        func_021C2A28(p);
        func_021C2D88(p);
    }
}
