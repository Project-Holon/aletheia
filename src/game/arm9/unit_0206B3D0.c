/*
 * file:     unit_0206B3D0.c
 * function: func_0206B3D0
 * address:  0x0206B3D0
 * packet:   pkt_0206AFE4
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

typedef struct Node0206B3D0 {
    u8 pad00[0xc];
    void (*f0c)(u32 *out, struct Node0206B3D0 *self, u32 arg);
    struct Node0206B3D0 *f10;
    u8 pad14[5];
    u8 f19;
    u16 f1a[1];
} Node0206B3D0;

int func_0206B3D0(u32 *out, Node0206B3D0 *node, unsigned index)
{
    int result = 0;
    u32 v;

    *out = 0;
    do {
        if (index < node->f19) {
            u16 f = *(u16 *)((char *)node + 0x1a + index * 2);
            if ((f & 0x300) == 0x100) {
                if (node->f0c != 0) {
                    node->f0c(&v, node, f & 0xff);
                    *out |= v;
                    result = 1;
                }
            }
        }
        node = node->f10;
    } while (node != 0);
    return result;
}
