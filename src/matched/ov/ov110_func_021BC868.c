/*
 * function: func_021BC868
 * address: 0x021BC868
 * packet: pkt_ov110_021BC868
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 *   func_021BC8C0 0x021BC8C0 thumb ov110
 *   _s32_div_f 0x0209C0A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_021BC8C0(void *, u8 *);
extern int _s32_div_f(int, int);
void func_021BC868(u8 *p, int a, int b, int start, int end, int frames)
{
    *(int *)(p + 0) = a;
    *(int *)(p + 4) = b;
    *(int *)(p + 20) = frames;
    *(int *)(p + 8) = start;
    *(int *)(p + 16) = _s32_div_f(end - start, frames);
    *(int *)(p + 12) = end;
    *(int *)(p + 24) = 0;
    *(void **)(p + 28) = func_021B9BA4(func_021BC8C0, p, 0);
}
