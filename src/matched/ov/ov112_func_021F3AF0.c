/*
 * function: func_021F3AF0
 * address:  0x021F3AF0
 * packet:   pkt_ov112_021F3AF0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021F67E0  0x021F67E0  thumb  ov112
 *   func_021F3CA4  0x021F3CA4  thumb  ov112
 *   func_021F3F00  0x021F3F00  thumb  ov112
 *   func_021F40F4  0x021F40F4  thumb  ov112
 *   func_021F6F24  0x021F6F24  thumb  ov112
 *   func_021F6FB0  0x021F6FB0  thumb  ov112
 *   func_021F75DC  0x021F75DC  thumb  ov112
 *   func_021F7098  0x021F7098  thumb  ov112
 *   d_021F8380     0x021F8380  data  ov112  a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct F5 { u32 v : 5; };
struct BF { u16 a : 2; u16 c : 1; u16 b : 5; };
extern char d_021F8380[];
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u32 tag);
extern void *func_021F67E0(u16 a, u8 b, u8 c, u8 d, u32 e, u16 heap);
extern void func_021F3CA4(void *o);
extern void func_021F3F00(void *o);
extern void func_021F40F4(void *o);
extern void *func_021F6F24(u32 heap, u32 v);
extern void func_021F6FB0(void *a, u8 b);
extern void func_021F75DC(void *a, u16 v);
extern void func_021F7098(void *a, u16 v);
u8 *func_021F3AF0(u8 *src, u16 heap)
{
    u8 i;
    u8 *o;
    u8 j;
    o = func_02030734(heap, 100, 1, d_021F8380, 0x85);
    *(u16 *)o = heap;
    *(u8 **)(o + 4) = src;
    for (i = 0; i < 4; i++) {
        u32 off = i * 0x58;
        u8 *row;
        *(u32 *)(o + i * 4 + 8) = (u32)func_021F67E0(*(u16 *)(src + off + 4), (u8)((struct BF *)(src + 6 + off))->a, (u8)((struct BF *)(src + 6 + off))->b, (u8)((struct BF *)(src + 6 + off))->c, *(u32 *)(src + off + 8), heap);
        row = (u8 *)((u32)src + off);
        for (j = 0; j < 8; j++) {
            u8 k = row[j * 8 + 0x20];
            if (k != 10) {
                *(u16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x14) = *(u16 *)(row + j * 8 + 0x1c);
                *(s16 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x16) = *(s16 *)(row + j * 8 + 0x1e);
                *(u8 *)(*(u8 **)(o + i * 4 + 8) + k * 6 + 0x18) = j;
            }
        }
    }
    func_021F3CA4(o);
    func_021F3F00(o);
    func_021F40F4(o);
    *(void **)(o + 0x28) = func_021F6F24(*(u16 *)o, 0);
    func_021F6FB0(*(void **)(o + 0x28), (u8)((struct F5 *)*(u8 **)(o + 4))->v);
    func_021F75DC(*(void **)(o + 0x2c), 0x80);
    func_021F7098(*(void **)(o + 0x28), 0x80);
    return o;
}
