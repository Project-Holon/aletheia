/*
 * function: func_0202ABD0
 * address:  0x0202ABD0
 * packet:   pkt_0202AB7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0202AF28  0x0202AF28  thumb
 *   sub_020307B0   0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj {
    u8 pad[0x14];
    void **arr;
    u8 count;
};

extern void func_0202AF28(void *item);
extern u32 sub_020307B0(void *p);

void func_0202ABD0(struct Obj *obj)
{
    int i;
    int count = obj->count;

    for (i = 0; i < count; i++) {
        func_0202AF28(obj->arr[i]);
    }
    sub_020307B0(obj->arr);
    obj->arr = 0;
}
