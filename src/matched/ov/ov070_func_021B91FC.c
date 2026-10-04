/*
 * function: func_021B91FC
 * address:  0x021B91FC
 * packet:   pkt_ov070_021B91FC
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008550  0x02008550  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 */

typedef signed int     s32;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);

void func_021B91FC(char *p, int bg)
{
    int a, b, c, d;
    int r = func_02008550((const struct Sub0200852CObj *)(*(int *)(p + 8)));
    if (r == 0) {
        a = 0x10;
        b = 0xf;
        c = 0xe;
        d = 0xd;
    } else if (r == 1) {
        a = 0xc;
        b = 0xb;
        c = 0xa;
        d = 9;
    }
    *(int *)(p + 0x590) = func_0204AC18((void *)bg, a, 0, 0xc0, 0, 4, *(unsigned short *)(p + 0x544));
    *(int *)(p + 0x594) = func_0204A6C8((void *)bg, b, 0, 0, *(unsigned short *)(p + 0x544));
    *(int *)(p + 0x598) = func_0204AF28((void *)bg, c, d, *(unsigned short *)(p + 0x544));
}
