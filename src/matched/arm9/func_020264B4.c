/*
 * function: func_020264B4
 * address:  0x020264B4
 * packet:   pkt_020264B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020266C0 0x020266C0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_020266C0(u32 a, u32 b, u32 c);

void func_020264B4(void *p, int idx, u16 val0, u8 val3, u32 val4, int flag)
{
    u8 *base = (u8 *)p + 0x24;
    u8 *elem = base + idx * 8;
    u16 old0;
    u8 old5;

    elem[4] = val4;
    old0 = *(u16 *)(base + idx * 8);
    if (old0 == val0 && elem[5] == val3) {
        return;
    }
    if (old0 != val0) {
        *(u16 *)(elem + 2) = old0;
        *(u16 *)elem = val0;
    }
    old5 = elem[5];
    if (old5 == val3) {
        return;
    }
    elem[6] = old5;
    elem[5] = val3;
    if (!flag) {
        sub_020266C0((u32)p, idx, val3);
    }
}
