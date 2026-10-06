/*
 * function: func_021B7970
 * address:  0x021B7970
 * packet:   pkt_ov021_021B7970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B91A8  0x021B91A8  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 f2;
    u8 pad[0x78];
} Elem;

typedef struct {
    u8 pad[8];
    Elem *arr;
    int count;
} Ctx;

extern u16 func_021B91A8(u8 *p);

void func_021B7970(Ctx *c)
{
    Elem *found = 0;
    int i;

    for (i = 0; i < c->count; i++) {
        if (func_021B91A8((u8 *)(&c->arr[i])) == 0) {
            found = &c->arr[i];
            break;
        }
    }
    found->f2 = 1;
}
