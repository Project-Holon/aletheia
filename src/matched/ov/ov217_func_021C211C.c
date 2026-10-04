/*
 * function: func_021C211C
 * address:  0x021C211C
 * packet:   pkt_ov217_021C211C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C21C4  0x021C21C4  thumb  ov217
 *   func_021C2250  0x021C2250  thumb  ov217
 *   func_021C2194  0x021C2194  thumb  ov217
 *   func_021C218C  0x021C218C  thumb  ov217
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern void func_021C21C4(u8 *p, int index);
extern void func_021C2250(u32 a0, u32 a1);
extern u32 func_021C2194(void *p);
extern void func_021C218C(void *p, u32 v);

void func_021C211C(void *p)
{
    s32 i;
    for (i = 0; i < *(u8 *)((char *)p + 0x298); i++) {
        char *e = (char *)p + i * 0x18;
        if (*(u32 *)(e + 0x28) == 0 && *(u16 *)(e + 0x2c) <= *(u32 *)((char *)p + 0x24))
            func_021C21C4(p, (u8)i);
        if (*(u32 *)(e + 0x28) == 1 && *(u32 *)(e + 0x30) == 1 && *(u16 *)(e + 0x34) <= *(u32 *)((char *)p + 0x24))
            func_021C2250((u32)p, (u8)i);
    }
    if (func_021C2194(p))
        func_021C218C(p, 2);
}
