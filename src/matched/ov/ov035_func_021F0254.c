/*
 * function: func_021F0254
 * address:  0x021F0254
 * packet:   pkt_ov035_021F0254
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0254 0x021F0254 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 */

typedef signed short   s16;
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal);
extern void func_02045334(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);

void func_021F0254(char *p, int a1, int a2)
{
    int r6 = (int)func_02045EC0((struct MsgBank *)(*(int *)(p + 0x38)), a2);
    func_0201C7A4((void *)((int)func_02045770((struct Descriptor *)a1)), 0, 0, (void *)r6, (void *)(*(int *)(p + 0x34)));
    func_0201F79C((void *)a1, 0, *(int *)(p + 0x14), 2);
    func_02045334((struct Descriptor *)a1);
    func_02045808((struct U16Vec *)r6);
}
