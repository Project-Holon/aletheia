/*
 * function: func_021B9818
 * address:  0x021B9818
 * packet:   pkt_ov071_021B9818
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   d_021BABFC     0x021BABFC  data  a4
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern char d_021BABFC[];
struct Cfg;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_0201DD78(u32 a, u32 b, u32 c);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u16 a10);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);

void func_021B9818(char *a, char *b, u32 c)
{
    void *r6;

    if (*(void **)(a + 0x294) != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    r6 = func_02045EC0(*(void **)(b + 0x28), c);
    *(void **)(a + 0x290) = func_020457B0(0x100, 0x61);
    func_0201F250(*(void **)(b + 0x10), *(void **)(a + 0x290), r6);
    func_02045808(r6);
    *(void **)(a + 0x294) = func_0201CCE4(*(void **)(a + 0x280), 0, 0, *(void **)(a + 0x290), *(u32 *)(b + 0xc), func_02012FFC(), *(u32 *)(b + 0x18), 0xa, 0x61, 0xf);
    func_02045374(*(void **)(a + 0x280));
    func_0201F73C(*(void **)(a + 0x280), 1, 1, 0xb);
}
