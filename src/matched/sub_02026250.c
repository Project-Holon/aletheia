/*
 * function: func_02026250
 * address:  0x02026250
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02045808  0x02045808  arm
 *   sub_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void sub_02045808(void *vec);
extern void sub_020307B0(void *p);

struct Item {
    u32 unk0;
    void *vec1;
    void *vec2;
};

void func_02026250(void *obj)
{
    struct Item *items = (struct Item *)((u8 *)obj + 0x3c);
    int i;

    for (i = 0; i < 6; i++) {
        sub_02045808(items[i].vec1);
        sub_02045808(items[i].vec2);
    }
    sub_020307B0(obj);
}
