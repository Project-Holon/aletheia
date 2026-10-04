/*
 * function: func_0219800C
 * address:  0x0219800C
 * packet:   pkt_ov021_0219800C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6D4  0x0216D6D4  thumb  ov010
 *   func_02163FC0  0x02163FC0  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern void *func_0216D6D4(void *p);
extern void func_02163FC0(u8 *, u16, u32);
extern int func_02164010(int a);
extern void func_0216D568(void *p, u32 v);
extern void func_02163F10(u8 *);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *);

u32 func_0219800C(u8 *p)
{
    u8 *h;

    h = func_0216D6D4(p);
    func_02163FC0(p, *(u32 *)(h + 4), *(u32 *)(h + 8));
    func_02164010((int)p);
    *(s16 *)(h + 2) = *(s16 *)(h + 2) - 1;
    if (*(s16 *)(h + 2) > 0) {
        return 0;
    }
    func_0216D568(p, 0x440);
    func_02163F10(p);
    func_0216D674(p, 0);
    func_0216D7CC(p);
    return 0;
}
