/*
 * function: func_02009F1C
 * address:  0x02009F1C
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern u32 func_0200A400(struct Obj *obj);
extern void *func_0200A43C(struct Obj *obj, u32 index);
extern u32 func_02009F0C(u32 a);

int func_02009F1C(void *a0)
{
    u32 i;
    u32 n = func_0200A400(a0);

    for (i = 0; i < n; i++) {
        if (func_02009F0C(((u8 *)func_0200A43C(a0, i))[0xb3]) == 0)
            return 1;
    }
    return 0;
}
