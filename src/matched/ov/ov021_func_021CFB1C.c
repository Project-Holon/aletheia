/*
 * unit:     yes
 * function: func_021CFB1C
 * function: func_021CFB68
 * address:  0x021CFB1C
 * packet:   pkt_ov021_021CFB1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021CFB1C removes slot i (copies it out, shifts the later ones down).
 * func_021CFB68 (unlabelled, 0x021CFB68) walks to the next used slot.
 *
 * symbols:
 *   d_021DB834  0x021DB834  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    s16 a0;
    s16 a2;
    s16 a4;
    u16 a6;
} Row;

extern const Row d_021DB834[];

typedef struct {
    u16 v[10];
} Slot;

typedef struct {
    u8   pad[0x10];
    Slot slot[20];
} Slots;

void func_021CFB1C(Slots *base, int i, Slot *dst)
{
    *dst = base->slot[i];
    for (i++; i < 20; i++) {
        base->slot[i - 1] = base->slot[i];
    }
    *(u16 *)((u8 *)base + 0x19c) = 0;
}

const Row *func_021CFB68(u8 *base, int *idx)
{
    int i = *idx;

    if (i < 20) {
        do {
            u8 *p = base + i * 0x14;
            if (*(u16 *)(p + 0x20) != 0) {
                const Row *r = &d_021DB834[p[0x22]];
                (*idx)++;
                return r;
            }
            i = ++*idx;
        } while (i < 20);
    }
    return 0;
}
