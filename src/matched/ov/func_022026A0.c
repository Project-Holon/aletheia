/*
 * function: WORLDTRADE_ADAPTER_CopyBoxMon
 * address:  0x022026A0
 * packet:   pkt_022026A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_CopyMon  0x0220262C  thumb  ov135
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb  arm9

 * Create the 0x48 sub-object, register the handle and hand it to the callback.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Mon;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void WORLDTRADE_ADAPTER_CopyMon(u32 h, u32 k);
extern u32 func_020307B0(void *p);

void WORLDTRADE_ADAPTER_CopyBoxMon(u8 *p, u32 k)
{
    u32 h = (u32)POKE_TOOL_CreateFromBoxParam((struct Mon *)p, 0x48);

    WORLDTRADE_ADAPTER_CopyMon(h, k);
    func_020307B0((void *)h);
}
