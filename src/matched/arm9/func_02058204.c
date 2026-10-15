/*
 * function: SPL_EMITTER_UpdateNode
 * address:  0x02058204
 * packet:   pkt_02057830
 * region:   arm9
 * compiler: ../1.2/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   _s32_div_f     0x0209C0A4  arm
 *   g_02146A8C     0x02146A8C  data
 * note:     EXACT* because the follower at 0x020582C0 is an unlabelled leaf run
 *           (its own literal pool); every byte of the 188-byte function plus the
 *           pool at 0x020582C0 compares identical.
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

struct Obj {
    s16 v0;
    s16 v1;
    s16 v2;
    u16 f06;
};

struct Src {
    char _00[0x26];
    u16 f26;
};

u32 g_02146A8C;

void SPL_EMITTER_UpdateNode(struct Obj *o, struct Src *s, int *dst)
{
    int r;

    if (s->f26 % o->f06 != 0) {
        return;
    }

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[0] = dst[0] + ((o->v0 * r - (o->v0 << 8)) >> 8);

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[1] = dst[1] + ((o->v1 * r - (o->v1 << 8)) >> 8);

    g_02146A8C = g_02146A8C * 0x5EEDF715 + 0x1B0CB173;
    r = g_02146A8C >> 23;
    dst[2] = dst[2] + ((o->v2 * r - (o->v2 << 8)) >> 8);
}
