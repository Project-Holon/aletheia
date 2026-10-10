/*
 * function: func_0205109C
 * address: 0x0205109C
 * packet: pkt_arm9_0205109C
 * region: arm9
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/arm9/particle_p06.c and filed here.
 *
 * symbols:
 *   g_02146A88 0x02146A88 data
 */

typedef unsigned int   u32;
typedef unsigned char  u8;

typedef struct {
    u8 pad_00[0x10];
    u8 *cur;
} Arena_02050F1C;

void *func_0205109C(u32 size);
extern u32 *g_02146A88;

void *func_0205109C(u32 size)
{
    Arena_02050F1C *a = (Arena_02050F1C *)g_02146A88[8];
    u32 q = (u32)a->cur + size;
    u32 r = (u32)a->cur;
    if (q & 3) {
        q += 4 - (q & 3);
    }
    a->cur = (u8 *)q;
    return (void *)r;
}
