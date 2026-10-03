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

extern void *func_02030734(u32 heap, u32 size, int flags, const char *file, unsigned short line);
typedef unsigned char  u8;
extern void func_0202E79C(u8 *p);
extern const char g_020A77EC[];

void *func_0202E770(void *heap)
{
    void *p = func_02030734((u32)heap, 0x4c, 1, g_020A77EC, 0x2c);

    func_0202E79C(p);
    return p;
}
