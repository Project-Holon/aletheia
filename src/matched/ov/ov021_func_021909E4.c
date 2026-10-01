/*
 * function: func_021909E4
 * address:  0x021909E4
 * packet:   pkt_ov021_021909E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020200CC  0x020200CC  thumb  arm9
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_02190860  0x02190860  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Handle {
    u16 *owner;
    u32 slot;
    u32 id;
    u32 c;
    u32 obj;
} Handle;

extern Handle *func_02190860(u16 *a, const u8 *b, u32 c, u16 d, u16 e, u16 f, u32 g, u32 h, u32 i);
extern int func_0219049C(u16 *p);
extern int func_020200CC(u32 obj);

int func_021909E4(Handle *h)
{
    int v;

    if (func_0219049C(h->owner) == 0)
        return -1;
    v = func_020200CC(h->obj);
    if (v == -1)
        return -1;
    if (v == -2)
        return -2;
    return v;
}
