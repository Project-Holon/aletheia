/*
 * function: func_021F6BA4
 * address:  0x021F6BA4
 * packet:   pkt_021F6BA4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
 * symbols:
 *   func_021F6B34  0x021F6B34  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern int func_021F6B34(int v);
extern u32 func_0201AA18(void *party);

int func_021F6BA4(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0 && (int)func_0201AA18(party) < 2) {
        return 0;
    }
    return 1;
}
