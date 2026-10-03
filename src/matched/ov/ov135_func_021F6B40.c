/*
 * function: func_021F6B40
 * address:  0x021F6B40
 * packet:   pkt_021F6B40
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
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
extern int func_0201AA18(void *party);
struct Sub020079BCEntry;
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_020185F4(void *a);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);

void *func_021F6B40(void *party, void *save, int box, int slot)
{
    if (func_021F6B34(box) != 0) {
        if (slot > func_0201AA18(party) - 1) {
            return 0;
        }
        return func_020185F4(func_0201AB28(party, slot));
    }
    return func_02007A18(save, box, slot);
}
