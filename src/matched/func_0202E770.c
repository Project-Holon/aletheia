/*
 * function: func_0202E770
 * address:  0x0202E770
 * packet:   pkt_0202E560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0202E79C  0x0202E79C  thumb
 *   g_020A77EC     0x020A77EC  data
 */
typedef unsigned int u32;

extern void *func_02030734(void *heap, u32 size, u32 flags, const void *file, u32 line);
extern void  func_0202E79C(void *p);
extern const char g_020A77EC[];

void *func_0202E770(void *heap)
{
    void *p = func_02030734(heap, 0x4c, 1, g_020A77EC, 0x2c);

    func_0202E79C(p);
    return p;
}
