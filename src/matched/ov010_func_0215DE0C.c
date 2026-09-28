/*
 * function: func_0215DE0C
 * address:  0x0215DE0C
 * packet:   pkt_ov010_0215DE0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unload overlays 112 and 132, free the link work and detach it.
 *
 * The call to arm9 0x02012F74 (the +0x6A8 setter beside func_02012F80)
 * resolves since seeds_2 labelled and matched it (src/matched/unit_02012F68.c).
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02012F74  0x02012F74  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   ov132_id       0x00000084  data
 *   ov112_id       0x00000070  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

extern u8 ov132_id[];
extern u8 ov112_id[];

extern void func_020307B0(void *p);
extern void func_02012F74(void *h, void *w);
extern void func_02034A5C(u32 id);

void func_0215DE0C(void *w, void *h)
{
    func_02034A5C((u32)ov112_id);
    func_02034A5C((u32)ov132_id);
    func_020307B0(w);
    func_02012F74(h, 0);
}
