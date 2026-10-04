/*
 * function: func_021BD75C
 * address: 0x021BD75C
 * packet: pkt_ov209_021BD75C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_0200CA70 0x0200CA70 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 */
#include "../include/Obj02924.h"
#include "../include/Obj25567.h"
struct Blk37;
struct MsgBank;
struct WordSet;
struct U16Vec;
typedef unsigned short u16;
extern unsigned func_021B9394(char *);
extern unsigned func_0200CA70(struct Blk37 *);
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern void func_0201EFA4(struct WordSet *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern void func_0201F250(struct WordSet *, void *, void *);
extern void func_02045808(struct U16Vec *);
extern void func_021B6AE4(unsigned char *, unsigned, u16, u16, unsigned, unsigned, u16, unsigned);
void func_021BD75C(char *p, unsigned char *dest, unsigned text0, unsigned index)
{
    unsigned ps;
    void *text;
    ps = func_021B9394(*(char * *)&((struct Obj02924 *)p)->fC2C);
    if (func_0200CA70(*(struct Blk37 * *)&((struct Obj25567 *)(*(char * *)&((struct Obj02924 *)p)->f0))->f4) == 0)
        index = (*(u16 **)(p + 0xc38))[index];
    text = func_02045EC0(*(struct MsgBank * *)&((struct Obj02924 *)p)->f3C, 8);
    func_0201EFA4(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, 0, index, 3, 2, 1);
    func_0201F250(*(struct WordSet * *)&((struct Obj02924 *)p)->f40, ((struct Obj02924 *)p)->f44, text);
    func_02045808(text);
    func_021B6AE4(dest, ps, 0, 4, *(unsigned *)&((struct Obj02924 *)p)->f44, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
    func_021B6AE4(dest, ps, 28, 4, text0, ((struct Obj02924 *)p)->f38, 0x39e0, 0);
}
