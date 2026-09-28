/*
 * function: func_02157374
 * address:  0x02157374
 * packet:   pkt_ov010_02157374
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Slot {
    u8 pad00[0xE];
    u8 f0e;             /* 0x0E */
    u8 pad0f[0x2C - 0xF];
} Slot;

typedef struct Deal {
    u8 pad00[8];
    u8 map[4];          /* 0x08 */
    Slot *slots;        /* 0x0C */
} Deal;

u8 func_02157374(Deal *d, u8 i)
{
    return d->slots[d->map[i]].f0e;
}
