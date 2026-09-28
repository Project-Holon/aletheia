/*
 * function: func_021F6C48
 * address:  0x021F6C48
 * packet:   pkt_021F6C48
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
  *
 * symbols:
 *   func_021F6B40  0x021F6B40  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern void *func_021F6B40(void *party, void *save, int box, int slot);
extern u32 func_02017E88(void *p, u32 id, u32 v);

int func_021F6C48(void *party, void *save, int box, int slot)
{
    void *mon = func_021F6B40(party, save, box, slot);

    if (mon == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xA9, 0) == 0) {
        return 0;
    }
    if (func_02017E88(mon, 0xAA, 0) != 0) {
        return 2;
    }
    return 1;
}
