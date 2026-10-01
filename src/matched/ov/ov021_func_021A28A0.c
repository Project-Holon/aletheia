/*
 * function: func_021A28A0
 * address:  0x021A28A0
 * packet:   pkt_ov021_021A28A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A2A68  0x021A2A68  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[4];
    u16 count;
} Info021A28A0;

typedef struct {
    u8 pad[0x18];
    u32 *items;
    u8 pad1C[4];
    Info021A28A0 *info;
    u8 pad24[4];
    u8 slots[1];
} Obj021A28A0;

void func_021A2A68(u8 *s, int i, u32 x);

void func_021A28A0(Obj021A28A0 *p)
{
    int i;

    for (i = 0; i < p->info->count; i++)
        func_021A2A68(p->slots, i, p->items[i]);
}
