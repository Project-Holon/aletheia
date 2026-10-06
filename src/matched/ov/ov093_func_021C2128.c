/*
 * function: func_021C2128
 * address: 0x021C2128
 * packet: pkt_ov093_021C2128
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021C21F4 0x021C21F4 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C2204 0x021C2204 thumb ov093
 *   func_021CD4FC 0x021CD4FC thumb ov093
 *   func_021CC918 0x021CC918 thumb ov093
 *   func_021C6DD0 0x021C6DD0 thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021CD568 0x021CD568 thumb ov093
 *   func_021D805C 0x021D805C thumb ov093
 *   func_021C2250 0x021C2250 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a:10,b:9,c:9,d:1,e:1,f:1,g:1; } Lock;
struct QI;
extern u16 func_021D5B40(struct QI *p);
extern u8 func_021D5440(u8 *p);
extern int func_021C21F4(void *, u32);
extern u32 func_021CC8D8(void *, int);
extern int func_021C2204(u8 *, u8 *, u16);
extern u32 func_021CD4FC(void *, u32);
extern u32 func_021CC918(void *, u16, int);
extern void func_021C6DD0(u8 *, u8 *);
extern int func_021C88E4(u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021CD568(void *, u32, u32, ...);
extern u32 func_021D805C(void *p, u32 n);
extern void func_021C2250(u8 *p, u8 *a, u16 b, u32 c);
int func_021C2128(u8 *p, u8 *a)
{
    int t = func_021D5B40((struct QI *)a);
    int result = 0;
    u32 s;
    u32 v;
    u32 pos;
    if (func_021C21F4(p + 0x1ab8, func_021D5440(a))) {
        s = func_021CC8D8(p + 0x1d74, 0x1cea);
        if (func_021C2204(p, a, (u16)t) == 0) result = 1;
        if (result) {
            pos = func_021CD4FC(((struct Obj00003 *)p)->fC, 0x42);
            v = func_021CC918(p + 0x1d74, (u16)t, 0x1cf4);
            func_021C6DD0(p, a);
            if (func_021C88E4(p) != 2) result = 0;
            func_021CC95C((u32 *)(p + 0x1d74), v, 0x1cf9);
            if (result) {
                func_021CD568(((struct Obj00003 *)p)->fC, pos, 0x42, func_021D5440(a));
                if (func_021D805C((void *)((u16)t), 0x10)) func_021C2250(p, a, 0, 1);
            }
        }
        func_021CC95C((u32 *)(p + 0x1d74), s, 0x1d06);
    }
    return result;
}
