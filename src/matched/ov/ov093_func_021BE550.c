/*
 * function: func_021BE550
 * address: 0x021BE550
 * packet: pkt_ov093_021BE550
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BEA14 0x021BEA14 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_0201BEB8 0x0201BEB8 thumb
 *   func_021C0520 0x021C0520 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021BEC58 0x021BEC58 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *, int);
extern u32 func_021CC8D8(void *, int);
extern void func_021BEA14(u8 *, u8 *, u8 *, u32);
extern void func_021CC95C(void *, u32, int);
extern void func_021C64B4(u8 *, u16, u8 *, void *);
extern int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
extern int func_021D62C4(void *, int);
extern u32 func_0201BEB8(u16, u32);
extern void func_021C0520(u8 *, u8 *, u16, u32);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *, u16, u32);
extern int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d);
extern void func_021E03D8(u8 *a, int b);
void func_021BE550(u8 *p, u8 *b, u16 c)
{
    u8 *a;
    u32 lock;
    if ((*(u8 **)(p + 0x4ac))[0] != 0) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4ac))[1]);
        lock = func_021CC8D8(p + 0x1d74, 3720);
        func_021BEA14(p, a, b, c);
        func_021CC95C(p + 0x1d74, lock, 3722);
        func_021C64B4(p, c, a, ((struct Obj00003 *)p)->f1AB0);
        func_021CA7F4(p, a, (*(u8 **)(p + 0x4ac))[7], ((struct Obj00003 *)p)->f1AB0, ((struct Obj00003 *)p)->f864);
        if (func_021D62C4(a, 15) != 0 && func_0201BEB8(c, 12) != 0) {
            func_021C0520(p, a, c, 13);
            return;
        }
        func_021E02DC(a, c, func_021D59B4(a, 12));
        func_021BEC58(p, a, c, ((struct Obj00003 *)p)->f864);
        func_021E03D8(a, c);
    }
}
