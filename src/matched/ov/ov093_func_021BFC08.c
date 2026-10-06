/*
 * function: func_021BFC08
 * address: 0x021BFC08
 * packet: pkt_ov093_021BFC08
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Wide n/callee parameter avoids truncation; named one-word Word result supplies the frame word.
 * symbols:
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8D8C 0x021B8D8C thumb ov093
 *   func_021C66AC 0x021C66AC thumb ov093
 *   func_021C5718 0x021C5718 thumb ov093
 *   func_021C6720 0x021C6720 thumb ov093
 *   func_021BFD24 0x021BFD24 thumb ov093
 *   func_021E896C 0x021E896C thumb ov093
 *   func_021C5C1C 0x021C5C1C thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 *   func_021C6878 0x021C6878 thumb ov093
 *   func_021C68A8 0x021C68A8 thumb ov093
 *   func_021D5FC0 0x021D5FC0 thumb ov093
 *   func_021BFE60 0x021BFE60 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 raw; } Word;
struct Unk021D62A8;
struct UtilWork;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u8 func_021D5440(u8 *p);
extern int func_021B8D8C(void *, void *, u32);
extern int func_021C66AC(u8 *, u8 *, u32);
extern void func_021C5718(u8 *, u8 *, u32);
extern int func_021C6720(u8 *, u8 *, u32);
extern int func_021BFD24(u8 *, u8 *, int, u8 *, u16);
extern Word func_021E896C(int, int);
extern void func_021C5C1C(u8 *, u8 *, int, Word);
extern u32 func_021CC8D8(void *, int);
extern void func_021CC95C(u32 *p, u32 v, int line);
extern void func_021C6878(u8 *p, u8 *a, int a2);
extern int func_021C68A8(u8 *, u8 *, u8 *, u16);
extern void func_021D5FC0(struct UtilWork *p, u32 n);
extern void func_021BFE60(u8 *, u8 *);
int func_021BFC08(u8 *p, u8 *q, u8 *d, u16 c)
{
    int result;
    if (func_021D62C4((struct Unk021D62A8 *)q, 26) == 0) {
        int n = func_021B8D8C(((struct Obj00003 *)p)->f4, ((struct Obj00003 *)p)->f8, func_021D5440(q));
        if (func_021C66AC(p, q, (u32)d)) {
            func_021C5718(p, q, c);
            return 1;
        }
        if (func_021C6720(p, q, c) == 0) {
            if (func_021BFD24(p, q, n, d, c)) {
                Word s = func_021E896C(2, c);
                func_021C5C1C(p, q, 26, s);
            }
            return 2;
        }
        if (func_021BFD24(p, q, n, d, c) == 0) return 1;
        {
            u32 lock = func_021CC8D8(p + 0x1d74, 5124);
            func_021C6878(p, q, c);
            func_021CC95C((u32 *)(p + 0x1d74), lock, 5126);
        }
    }
    (*(u8 **)(p + 0x4a8))[4] = 1;
    {
        u32 lock = func_021CC8D8(p + 0x1d74, 5134);
        result = func_021C68A8(p, q, d, c);
        func_021CC95C((u32 *)(p + 0x1d74), lock, 5136);
    }
    func_021D5FC0((struct UtilWork *)q, 11);
    func_021BFE60(p, q);
    return result ? 4 : 3;
}
