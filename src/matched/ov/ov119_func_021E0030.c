/*
 * function: func_021E0030
 * address:  0x021E0030
 * packet:   pkt_ov119_021E0030
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021E0980  0x021E0980  thumb  ov119
 */

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern void func_021D8E84(void *, int);
extern void func_021E0980(char *p);

void func_021E0030(void *p)
{
    if (func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x17, 8)) {
        func_021D8E84(p, (int)func_021E0980);
    }
}
