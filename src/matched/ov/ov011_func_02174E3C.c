/*
 * function: func_02174E3C
 * address:  0x02174E3C
 * packet:   pkt_ov011_02174E3C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008468  0x02008468  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020127B8  0x020127B8  thumb
 *   func_021752DC  0x021752DC  thumb ov011
 *   func_02039338  0x02039338  arm
 *   func_02175710  0x02175710  thumb ov011
 */
#include "../include/Obj09349.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Ent {
    int w[7];
} Ent;

typedef struct F86 {
    u16 x : 3;
    u16 rest : 13;
} F86;

unsigned int func_02026478(void *obj);
u8 *func_02012944(void *p);
int func_02008468(void);
void func_02082D44(int a, u8 *b, int c);
int func_020127B8(int a);
typedef unsigned int   u32;
int func_021752DC(u8 *p);
u16 func_02039338(void);
void func_02175710(u8 *o, u32 v);

void func_02174E3C(u8 *p)
{
    int v;

    v = func_02026478((void *)(((struct Obj09349 *)p)->f4));
    func_02082D44((int)func_02012944((void *)v), p + 0x160, func_02008468());
    func_02082D44(func_020127B8(v), p + 0x180, 0x10);
    func_021752DC(p);
    if (((F86 *)(p + 0x86))->x == 0x80) {
        func_02175710(p, func_02039338());
    }
    *(Ent *)(p + 0x190) = *(Ent *)(p + 0x70);
}
