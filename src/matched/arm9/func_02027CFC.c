/*
 * function: func_02027CFC
 * address:  0x02027CFC
 * packet:   pkt_02027CFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355C4 0x020355C4  arm
 *   func_02027B30 0x02027B30  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int  func_020355C4(void *p);
extern void func_02027B30(u32 item, u32 sub, int self);

void func_02027CFC(u8 *p, int sel)
{
    int i;

    *p = sel;
    if (func_020355C4(p) != 0) {
        return;
    }
    i = 0;
    while (i < *(u8 *)(p + 0x24)) {
        if (i == sel) {
            func_02027B30((*(u32 **)(p + 0x18))[i], *(u32 *)(p + 0x34), 1);
        } else {
            func_02027B30((*(u32 **)(p + 0x18))[i], *(u32 *)(p + 0x34), 0);
        }
        i++;
    }
}
