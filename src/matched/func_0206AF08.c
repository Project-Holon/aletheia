/*
 * function: func_0206AF08
 * address:  0x0206AF08
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node0206AF08;

typedef void (*Cb0206AF08)(u32 a0, struct Node0206AF08 *n, u32 v);

struct Node0206AF08 {
    u32 pad00[3];
    Cb0206AF08 cb;
    struct Node0206AF08 *next;
    u32 pad14;
    u8  pad18;
    u8  count;
    u16 v[1];
};

int func_0206AF08(u32 a0, struct Node0206AF08 *n, u32 idx)
{
    int r = 0;

    while (n != 0) {
        if (idx < n->count) {
            u16 v = n->v[idx];

            if ((v & 0x300) == 0x100) {
                Cb0206AF08 cb = n->cb;

                if (cb != 0) {
                    cb(a0, n, v & 0xff);
                    r = 1;
                }
            }
        }
        n = n->next;
    }
    return r;
}
