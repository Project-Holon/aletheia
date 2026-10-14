/*
 * function: WORLDTRADE_INPUT_PrintStringPlain
 * address:  0x021F90A0
 * packet:   pkt_021F90A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WORLDTRADE_INPUT_PrintBankString  0x021F90B8  thumb  ov135
 *

 *
 * Forward the u16 stack argument to WORLDTRADE_INPUT_PrintBankString with mode 0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void WORLDTRADE_INPUT_PrintBankString(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow);

void WORLDTRADE_INPUT_PrintStringPlain(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    WORLDTRADE_INPUT_PrintBankString((u8 *)a, (void *)b, c, d, e, 0);
}
