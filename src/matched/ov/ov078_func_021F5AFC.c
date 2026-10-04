/*
 * function: func_021F5AFC
 * address:  0x021F5AFC
 * packet:   pkt_ov078_021F5AFC
 * region:   ov078
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov078 func_021F5698 with different constants.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF52C  0x021CF52C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_021F5748  0x021F5748  thumb  ov078
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

struct Ctx;
struct Desc;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02189A08(unsigned char *p);
extern u32 func_021CF52C(u32 *p, int size, int heap);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int func_021F5748(void *task, int *st);

void *func_021F5AFC(void *a)
{
    u8 *w;
    void *h;
    int i;

    w = (u8 *)func_021CF52C((u32 *)func_02189A08((unsigned char *)((int)func_0201210C(a))), 0x19E0, 0x50);
    h = func_020122C0(a, 0, (void (*)(void))func_021F5748, 0);
    *(s16 *)(w + 0x19CA) = 7;
    *(s16 *)(w + 0x19C8) = 0;
    *(s16 *)(w + 0x19CC) = 2;
    *(int *)(w + 0x19D0) = 0x555;
    *(s16 *)(w + 0x19CE) = 0x2d;
    *(int *)(w + 0x19D8) = 0x37;
    *(int *)(w + 0x19DC) = 0;
    for (i = 0; i < 0x339; i++) {
        s16 *e = (s16 *)(w + i * 6);

        e[0] = ((i % 33) << 12) / 16;
        e[1] = ((i / 33) << 12) / 16;
        e[2] = 0;
    }
    *(int *)(w + 0x19D4) = 3;
    return h;
}
