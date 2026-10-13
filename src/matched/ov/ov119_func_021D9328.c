/*
 * function: func_021D9328
 * address: 0x021D9328
 * packet: pkt_ov119_021D9328
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_021DD4F4 0x021DD4F4 thumb ov119
 *   func_021E62D4 0x021E62D4 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
struct S119DD4F4;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
extern void func_021E62D4(void *, int, int);
void func_021D9328(u32 a, u32 b, int *src, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) {
            func_021DD4F4(base, 1, *src);
            func_021E62D4(base, 1, *src);
        }
    }
}
