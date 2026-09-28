/*
 * function: func_021FE118
 * address:  0x021FE118
 * packet:   pkt_021FE118
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02030734  0x02030734  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021F84EC  0x021F84EC  thumb
 *   func_021F8990  0x021F8990  thumb
 *   g_02203E18     0x02203E18  data  ov135
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 g_02203E18[];

extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02045EC0(void *bank, u32 index);
extern void *func_02030734(u32 heap, u32 size, u32 clear, const char *file, u32 line);
extern void func_02082AC0(u32 value, void *dst, u32 size);
extern u8 *func_021F84EC(u32 id);
extern void func_021F8990(u8 *p);

void func_021FE118(u8 *p)
{
    *(void **)(p + 0xb88) = func_020457B0(0xb4, 0x48);
    *(void **)(p + 0xb8c) = func_02045EC0(*(void **)(p + 0xb6c), 0x30);
    *(void **)(p + 0xe00) = func_02030734(0x48, 0x30, 0, (const char *)g_02203E18, 0x351);
    func_02082AC0(0, *(void **)(p + 0xe00), 0x30);
    *(u8 **)(*(u8 **)(p + 0xe00) + 0x14) = func_021F84EC(0x48);
    func_021F8990(p + 0xeec);
}
