/*
 * function: func_021B9A40
 * address:  0x021B9A40
 * packet:   pkt_ov071_021B9A40
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045808  0x02045808  arm
 *   d_021BAAF8     0x021BAAF8  data  a2
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;

extern u16 d_021BAAF8[];
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045808(struct U16Vec *vec);

int func_021B9A40(char *a, char *b)
{
    int j;
    int i;
    char *r6;
    void *buf;

    j = 0;
    buf = func_020457B0(0x20, 0x61);
    i = *(u8 *)(a + 0x27d);
    if (i < *(u8 *)(a + 0x27c)) {
        do {
            if (i >= 1 && i < *(u8 *)(a + 0x27c) - 1) {
                r6 = a + i * 4;
                func_02045CAC((struct MsgBank *)(*(u32 *)(a + 0x20)), *(u32 *)(r6 + 0xec), buf);
                func_0201C7D0(*(void **)(r6 + 0x24), 0, 0, buf, *(void **)(b + 0xc),
                              d_021BAAF8[*(u32 *)(r6 + 0x1b4)]);
            }
            j++;
            if (j >= 3)
                break;
            i++;
        } while (i < *(u8 *)(a + 0x27c));
    }
    func_02045808(buf);
    *(u8 *)(a + 0x27d) = i;
    return *(u8 *)(a + 0x27d) >= *(u8 *)(a + 0x27c);
}
