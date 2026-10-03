/*
 * function: func_021C5620
 * address:  0x021C5620
 * packet:   pkt_ov093_021C5620
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D6314  0x021D6314  thumb  ov093
 *   func_021D61F0  0x021D61F0  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021C5698  0x021C5698  thumb  ov093
 *   func_021D6238  0x021D6238  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 func_021D5440(u8 *p);
struct Slot { u32 kind : 3; u32 rest : 29; };
extern struct Slot func_021D6314(u8 *p, int i);
extern void func_021D61F0(u8 *p);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern int func_021C5698(void *p, int v);
extern void func_021D6238(u8 *p, int k);
void func_021C5620(u8 *p, u8 *a, int k, struct Slot *out)
{
    u8 n;
    if (k != 0) {
        n = func_021D5440(a);
        if (out != 0) *out = func_021D6314(a, k);
        if (k < 6) {
            func_021D61F0(a);
            func_021CD4B0(*(void **)(p + 0xc), 0x10, n);
            if (func_021C5698(p + 0x1AB8, n) != 6) {
                func_021CD4B0(*(void **)(p + 0xc), 0x35, n, 0);
            }
        } else {
            func_021D6238(a, k);
            func_021CD4B0(*(void **)(p + 0xc), 0x11, n, (u16)k);
        }
    }
}
