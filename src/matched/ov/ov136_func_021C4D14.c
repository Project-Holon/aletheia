/*
 * function: func_021C4D14
 * address:  0x021C4D14
 * packet:   pkt_ov136_021C4D14
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4D14 0x021C4D14 thumb
 *   func_021C4DA8 0x021C4DA8 thumb
 *   func_021C5470 0x021C5470 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_021C52F8 0x021C52F8 thumb
 *   func_021C5114 0x021C5114 thumb
 *   func_021C4EC4 0x021C4EC4 thumb
 */
typedef unsigned char u8;
extern void func_021C4DA8(void *p);
extern void func_021C5470(void *p);
extern void func_02045C04(void *p);
extern void func_02045808(void *p);
extern void func_02027FD8(void *p);
extern void func_021C52F8(void *p);
extern void func_021C5114(void *p);
extern void func_021C4EC4(void *p);
int func_021C4D14(u8 *p)
{
    func_021C4DA8(p);
    func_021C5470(p);
    if (p + 0x28) func_02045C04(*(void **)(p + 0x20));
    func_02045808(*(void **)(p + 0x34));
    func_02027FD8(*(void **)(p + 0x108));
    func_021C52F8(p);
    func_021C5114(p);
    func_021C4EC4(p);
    return 1;
}
