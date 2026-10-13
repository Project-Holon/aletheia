/*
 * function: func_021D8FA4
 * address:  0x021D8FA4
 * packet:   pkt_021D8FA4
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm  arm9
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern int func_021D8A24(void *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);

void *func_021D8FA4(void *p, int idx)
{
    u32 v = func_021D8A24(p);
    if (v == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    if (GFL_NET_GetHandleNetID((struct Link *)((u32)GFL_NET_HANDLE_GetCurrentHandle())) == 0)
        return *(void **)((char *)p + idx * 4 + 0x5DC);
    return *(void **)((char *)p + (1 - idx) * 4 + 0x5DC);
}
