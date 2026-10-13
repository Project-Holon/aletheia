/*
 * function: func_021DB2D4
 * address:  0x021DB2D4
 * packet:   pkt_021DB2D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021E2EF8  0x021E2EF8  data
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm  arm9
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm  arm9
 *
 * Compare the caller's first word with the current 0x0203D1A4 handle of the 0x020399A8 block; a match releases the 0x021E2EF8 pair through 0x02034714, a mismatch yields the +0x218 sub-block.
 */

typedef unsigned long u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 g_021E2EF8[];
int func_021DB2D4(int a, char *b)
{
    if (GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle())) == a) {
        func_02034714((const char *)((int)g_021E2EF8), 0, (const char *)((int)g_021E2EF8));
        return 0;
    }
    return (int)(b + 0x218);
}

