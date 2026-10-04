/*
 * function: func_021EAF7C
 * address:  0x021EAF7C
 * packet:   pkt_ov093_021EAF7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm    arm9
 *   d_021F3AD0     0x021F3AD0  data   a4
 *   func_020457B0  0x020457B0  arm    arm9
 *   func_0201C440  0x0201C440  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 d_021F3AD0[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_020457B0(int, int);
extern u32 func_0201C440(void *p);

u8 *func_021EAF7C(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap)
{
    u8 *p;
    p = func_02030734(heap, 0x180, 1, (const char *)d_021F3AD0, 0x151);
    *(u32 *)(p + 0x130) = a;
    *(u32 *)(p + 0x134) = b;
    *(u32 *)(p + 0x138) = c;
    *(u16 *)(p + 0x13c) = heap;
    p[0x140] = e2;
    *(u32 *)(p + 0x24) = e0;
    *(u32 *)(p + 0x28) = e1;
    p[0x150] = 0;
    *(u32 *)(p + 0x30) = 0;
    *(u32 *)(p + 0x2c) = d;
    *(int *)(p + 0x34) = func_020457B0(0x400, heap);
    *(int *)(p + 0x38) = func_020457B0(0x180, heap);
    *(int *)(p + 0x3c) = func_020457B0(0x180, heap);
    p[0x14e] = 0;
    *(u32 *)(p + 0xd8) = 0;
    *(u32 *)(p + 0x18) = func_0201C440((void *)(*(u16 *)(p + 0x13c)));
    *(u32 *)(p + 0x1c) = *(u32 *)p;
    p[0x20] = 0;
    return p;
}
