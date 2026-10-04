/*
 * function: func_02027584
 * address:  0x02027584
 * packet:   pkt_020274B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Releases the +0xB08 handle, zeroes 0xB10 bytes and frees the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02027584.c \
 *       --func func_02027584 --addr 0x02027584 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct U16Vec;
extern void func_02045808(struct U16Vec *vec);
extern void func_02082BCC(void *p, u32 v, u32 size);
extern void func_020307B0(void *p);

void func_02027584(u8 *p)
{
    func_02045808((struct U16Vec *)(*(u32 *)(p + 0xb08)));
    func_02082BCC(p, 0, 0xb10);
    func_020307B0(p);
}
