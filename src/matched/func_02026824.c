/*
 * function: func_02026824
 * address:  0x02026824
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   data_0209FC20  0x0209FC20  data
 *
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

struct Obj;

extern const u32 data_0209FC20[];

void func_02026824(struct Obj *o)
{
    u16 n = *(u16 *)((u8 *)o + 0x30);

    if (n == 1) {
        return;
    }
    *(s16 *)((u8 *)o + 0x5c) += 1;
    if ((u32)*(s16 *)((u8 *)o + 0x5c) > (data_0209FC20[n] >> 8)) {
        *(u16 *)((u8 *)o + 0x5c) = 0;
        *(u16 *)((u8 *)o + 0x30) = 1;
    }
}
