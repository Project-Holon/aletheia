/*
 * function: func_021B6208
 * address:  0x021B6208
 * packet:   pkt_ov067_021B6208
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fC;
} Out;

typedef struct {
    int f0;
    u32 f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
} In;

extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *h, u32 a1, u32 a2, u32 a3, u16 a4);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);

void func_021B6208(Out *out, In *in, int unused, u16 d)
{
    int flag;
    void *h;

    flag = in->f4 & 2;
    h = func_020490F4(in->f8, d);
    if (in->f4 & 1)
        out->f4 = func_0204ACEC(h, in->fC, in->f0, (u16)(in->b1c << 5), d);
    else
        out->f4 = func_0204AC18(h, in->fC, in->f0, (u16)(in->b1c << 5), in->b1d, in->b1e, d);
    out->f0 = func_0204A6C8(h, in->f10, flag, in->f0, d);
    out->f8 = func_0204AF28(h, in->f14, in->f18, d);
    out->fC = in->f0;
    func_02049238(h);
}
