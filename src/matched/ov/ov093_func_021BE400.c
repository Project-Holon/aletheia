/*
 * function: func_021BE400
 * address: 0x021BE400
 * packet: pkt_ov093_021BE400
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021BEA60 0x021BEA60 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C64B4 0x021C64B4 thumb ov093
 *   func_021CA7F4 0x021CA7F4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D7394 0x021D7394 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021E02DC 0x021E02DC thumb ov093
 *   func_021BEC58 0x021BEC58 thumb ov093
 *   func_021E03D8 0x021E03D8 thumb ov093
 *   func_021D73D4 0x021D73D4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Out { u8 pad[16]; u32 flag : 1; u32 rest : 31; };
extern u8 *func_021B9934(char *, int);
extern int func_021D5B7C(void *);
extern u32 func_021CC8D8(void *, int);
extern void func_021BEA60(u8 *, u8 *, u8 *, u32);
extern void func_021CC95C(void *, u32, int);
extern void func_021C64B4(u8 *, u16, u8 *, struct Out *);
extern int func_021CA7F4(u8 *p, u8 *a, u16 b, const u8 *q, void *out);
extern u8 func_021D5440(u8 *p);
extern void func_021D7394(int kind);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E02DC(u8 *, u16, u32);
extern int func_021BEC58(u8 *p, u8 *a, u16 key, u8 *d);
extern void func_021E03D8(u8 *a, int b);
extern void func_021D73D4(int kind);
void func_021BE400(u8 *p, u16 key)
{
    u32 i;
    u8 *a;
    u8 *b;
    u32 lock;
    for (i = 0; i < (*(u8 **)(p + 0x4b0))[0]; i++) {
        a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 1]);
        b = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (*(u8 **)(p + 0x4b0))[i + 13]);
        if (func_021D5B7C(a) != 0) {
            lock = func_021CC8D8(p + 0x1d74, 3657);
            func_021BEA60(p, a, b, key);
            func_021CC95C(p + 0x1d74, lock, 3659);
            func_021C64B4(p, key, a, *(struct Out * *)&((struct Obj00003 *)p)->f1AB0);
            (*(struct Out **)(p + 0x1ab0))->flag = 1;
            func_021CA7F4(p, a, (*(u8 **)(p + 0x4b0))[i + 7], (const u8 *)(*(struct Out **)(p + 0x1ab0)), ((struct Obj00003 *)p)->f864);
            func_021D7394(func_021D5440(a));
            func_021E02DC(a, key, func_021D59B4(a, 12));
            func_021BEC58(p, a, key, ((struct Obj00003 *)p)->f864);
            func_021E03D8(a, key);
            func_021D73D4(func_021D5440(a));
        }
    }
}
