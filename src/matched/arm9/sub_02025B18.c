/*
 * function: func_02025B18
 * address:  0x02025B18
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0204AFD8  0x0204AFD8  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Obj02025774 {
    u8  pad[0xc];
    s32 slots[3];
};

extern void sub_0204AFD8(u32 slot);

void func_02025B18(struct Obj02025774 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (p->slots[i] != -1) {
            sub_0204AFD8(p->slots[i]);
            p->slots[i] = -1;
        }
    }
}
