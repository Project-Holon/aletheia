/*
 * function: ov208_func_021C0740
 * address:  0x021C0740
 * packet:   pkt_ov208_021C0740
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *win);
extern int  func_0201C6C4(u32 a, u32 b);
extern void func_02045334(struct Descriptor *v);
extern void func_02045374(u32 v);
extern u8   func_02045730(u32 v);
extern void func_02041B6C(u32 bit);

void ov208_func_021C0740(u16 *heap, u8 *p, int key, u8 i)
{
    u32 w;

    if (((u32 *)(p + 0x24))[i] != 0) {
        if (func_0201C6C4(((u32 *)(p + 0x34))[i], (u32)func_02045770((struct Descriptor *)((u32 *)(p + 0x14))[i])) == 0) {
            w = ((u32 *)(p + 0x14))[i];
            func_02045334((struct Descriptor *)w);
            func_02045374(w);
            func_02041B6C(func_02045730(w));
            ((u32 *)(p + 0x24))[i] = 0;
        }
    }
}
