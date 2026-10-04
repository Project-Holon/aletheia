/*
 * function: func_021B7C78
 * address: 0x021B7C78
 * packet: pkt_ov180_021B7C78
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned short u16;

extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
typedef unsigned int   u32;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void *func_0204ABF0(void *, unsigned, int, unsigned, unsigned);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
void func_021B7C78(char *p)
{
    void *h = func_020490F4(0xD8, 0x808D);
    *(void **)(p + 0x90D4) = (void *)func_0204A6C8(h, 0x18, 0, 0, 0x8D);
    *(void **)(p + 0x90EC) = func_0204ABF0(h, 3, 0, 0, 0x8D);
    *(void **)(p + 0x9108) = (void *)func_0204AF28(h, 0x1A, 0x20, 0x8D);
    func_02049238(h);
    h = func_020490F4(0x17, 0x808D);
    *(void **)(p + 0x90F0) = (void *)func_0204ACEC(h, 5, 0, 0xA0, 0x8D);
    func_02049238(h);
}
