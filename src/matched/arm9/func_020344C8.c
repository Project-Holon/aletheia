/*
 * function: func_020344C8
 * address:  0x020344C8
 * packet:   pkt_020344C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020344C4  0x020344C4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020344C4(u8);

struct Struct_020344C8 {
    u8 pad[2];
    u16 count;
    u32 unk_4;
    void *ptr;
    u8 data[];
};

void func_020344C8(struct Struct_020344C8 *param)
{
    if (param->ptr != 0) {
        int i;
        for (i = 0; i < param->count; i++) {
            func_020344C4(param->data[i]);
        }
    }
}
