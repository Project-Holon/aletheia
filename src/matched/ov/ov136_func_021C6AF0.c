/*
 * function: func_021C6AF0
 * address: 0x021C6AF0
 * packet: pkt_ov136_021C6AF0
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
u32 func_021C6AF0(u8 *p)
{
    if (func_0201CE30(*(void **)(*(u8 **)(p + 8) + 0x1c8)) == 2) {
        if ((*(u8 **)(p + 8))[0x1dd] == 0) {
            func_0201CE48(*(void **)(*(u8 **)(p + 8) + 0x1c8));
            return *(u32 *)(p + 0x28);
        }
        if (func_02035C60() == 1 || (func_020362DC() & 3) != 0) {
            func_0201CE48(*(void **)(*(u8 **)(p + 8) + 0x1c8));
            func_020061E4(1352);
            return *(u32 *)(p + 0x28);
        }
    }
    return 3;
}
