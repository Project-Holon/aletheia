/*
 * function: func_021B9750
 * address:  0x021B9750
 * packet:   pkt_ov071_021B9750
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C6FC(void *a, void *b, u32 c, u32 d, void *e, void *f);
extern void func_02045808(struct U16Vec *vec);

void func_021B9750(char *a, char *b)
{
    void *r6;
    char *r4;
    void *r7;

    r6 = func_02045EC0(*(void **)(*(char **)(a + 4) + 0x28), 0x22);
    r4 = *(char **)(a + 4);
    r7 = *(void **)(r4 + 8);
    func_0201C6FC(r7, func_02045770(*(void **)(b + 0x288)), 0x18, 4, r6, *(void **)(r4 + 0xc));
    *(u8 *)(b + 0x28c) = 1;
    func_02045808(r6);
}
