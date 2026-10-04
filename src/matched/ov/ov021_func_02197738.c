/*
 * function: func_02197738
 * address:  0x02197738
 * packet:   pkt_ov021_02197738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012DD0  0x02012DD0  thumb
 *   func_02196228  0x02196228  thumb  ov021
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02196034  0x02196034  thumb  ov021
 *   func_02196A60  0x02196A60  thumb  ov021
 *   func_02196804  0x02196804  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_02012DD0(u8 *p);
extern void func_02196228(u8 *p, int flag);
struct Descriptor;
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020456F8(struct Descriptor *d);
extern void func_02041B6C(u32);
extern void func_02196034(u8 *, void (*)(), u32);
extern void func_02196A60(u8 *p);
extern void func_02196804(u8 *p);

void func_02197738(u8 *a)
{
    if (func_02012DD0(*(u8 **)(a + 0x30)) == 2) {
        func_02196228(a, 0);
        func_0201F7A8((void *)(*(u32 *)(a + 0x2b0)), 2);
        func_020456F8((struct Descriptor *)(*(u32 *)(a + 0x2b0)));
        func_02041B6C(5);
        if (*(u32 *)(a + 8) == 1) {
            func_02196034(a, func_02196A60, 0x776);
        } else {
            func_02196034(a, func_02196804, 0x779);
        }
        *(u32 *)(a + 0x2f8) = 1;
    }
}
