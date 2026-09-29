/*
 * function: func_0218A494
 * address:  0x0218A494
 * packet:   pkt_ov096_0218A494
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049250  0x02049250  arm
 *   D_0218A7C0     0x0218A7C0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 id[4];
    u8 ref[4];
    void *obj[4];
} Slot;

extern Slot *D_0218A7C0;
extern void *func_02049250(void *h, u32 id, u16 heap);

void *func_0218A494(u8 *a)
{
    int i;
    u32 x;

    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == a[0x45]) {
            D_0218A7C0->ref[i]++;
            return D_0218A7C0->obj[i];
        }
    }
    for (i = 0; i < 4; i++) {
        if (D_0218A7C0->id[i] == 0xff)
            break;
    }
    if (a[0x45] == 2)
        x = (u16)((*(u16 *)(a + 0xa0) & 0x7fff) | 0x8000);
    else
        x = *(u16 *)(a + 0xa0);
    D_0218A7C0->id[i] = a[0x45];
    D_0218A7C0->ref[i]++;
    D_0218A7C0->obj[i] = func_02049250(*(void **)(a + 0xa4), a[0x45], x);
    return D_0218A7C0->obj[i];
}
