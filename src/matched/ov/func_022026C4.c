/*
 * function: WORLDTRADE_ADAPTER_StrObjThunk
 * address:  0x022026C4
 * packet:   pkt_022026C4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Tail call: the third argument goes first, the dereferenced pointer second, the u16 last.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);

int WORLDTRADE_ADAPTER_StrObjThunk(u32 *p, u32 b, u32 a, u32 c)
{
    return func_0201D304((struct StrObj *)a, *p, (u16)c);
}
