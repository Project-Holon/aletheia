/*
 * function: func_021C4998
 * address:  0x021C4998
 * packet:   pkt_ov136_021C4998
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4998 0x021C4998 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct TaskMenu;
struct U16Vec;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_02045808(struct U16Vec *vec);
int func_021C4998(u8 *p)
{
    int r = -1;
    if (func_020279E8(*(void **)(p + 0x10C))) {
        r = func_02027A04(*(void **)(p + 0x10C));
        func_02027858(*(void **)(p + 0x10C));
        func_02045808(*(void **)(p + 0x110));
        func_02045808(*(void **)(p + 0x11C));
    }
    return r;
}
