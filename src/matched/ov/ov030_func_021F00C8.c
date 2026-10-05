/*
 * function: func_021F00C8
 * address:  0x021F00C8
 * packet:   pkt_ov030_021F00C8
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F00C8  0x021F00C8  thumb
 *   func_02030734  0x02030734  arm
 *   func_021F0058  0x021F0058  thumb  ov030
 *   str_021F01C0   0x021F01C0  data   ov030  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char str_021F01C0[];
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021F0058(void *p);

char *func_021F00C8(u32 a, u32 b, u32 c)
{
    char *w;

    w = func_02030734(0x15, 0x20, 1, str_021F01C0, 0x17A);
    *(u16 *)(w + 8) = 0x15;
    *(u32 *)(w + 0x18) = c;
    func_021F0058(w);
    return w;
}
