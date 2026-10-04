/*
 * function: func_021B3C78
 * address:  0x021B3C78
 * packet:   pkt_ov021_021B3C78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B3C78 0x021B3C78 thumb
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */

typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *);

void func_021B3C78(char *p)
{
    void *q = func_020490F4(54, *(u16 *)(p + 4));

    *(void **)(p + 468) = (void *)func_0204AC18(q, 10, 0, 0, 0, 1, *(u16 *)(p + 4));
    *(void **)(p + 472) = (void *)func_0204A6C8(q, 7, 0, 0, *(u16 *)(p + 4));
    *(void **)(p + 484) = (void *)func_0204A6C8(q, 4, 0, 0, *(u16 *)(p + 4));
    *(void **)(p + 476) = (void *)func_0204AF28(q, 8, 9, *(u16 *)(p + 4));
    *(void **)(p + 488) = (void *)func_0204AF28(q, 5, 6, *(u16 *)(p + 4));
    func_02049238(q);
}
