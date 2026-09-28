/*
 * function: func_02020A34
 * address:  0x02020A34
 * packet:   pkt_02020408
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Elem {
    u32 unk00;
    void *unk04;
};

struct Obj {
    struct Elem *arr;
    void (*callback)(struct Obj *, void *, void *);
    u8 pad[0x40 - 0x08];
    u16 f40;
    u16 f42;
};

void func_02020A34(struct Obj *obj, void *arg1)
{
    if (obj->callback != 0) {
        obj->callback(obj, obj->arr[obj->f40 + obj->f42].unk04, arg1);
    }
}
