/*
 * function: func_021CF5AC
 * address:  0x021CF5AC
 * packet:   pkt_ov021_021CF5AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034A5C  0x02034A5C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res021CF {
    u8 pad0[0xc];
    u32 ids[3];
    int n;
} Res021CF;

typedef signed int     s32;
extern void func_02034A5C(s32 handle);

void func_021CF5AC(Res021CF *r)
{
    int i;

    if (r->n > 0) {
        while (r->n > 0) {
            i = r->n - 1;
            if (r->ids[i] != 0) {
                func_02034A5C(r->ids[i]);
            }
            r->n--;
        }
    }
}
