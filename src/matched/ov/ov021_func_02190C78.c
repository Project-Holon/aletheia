/*
 * function: func_02190C78
 * address:  0x02190C78
 * packet:   pkt_ov021_02190C78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190860  0x02190860  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
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
extern int func_021909E4(Handle *h);

int func_02190C78(Handle *h)
{
    int v = func_021909E4(h);
    if (v == -1)
        return 2;
    if (v == -2)
        return 1;
    return v;
}
