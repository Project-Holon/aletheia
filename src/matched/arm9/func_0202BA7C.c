/*
 * function: ISS_3DS_SYS_SetSourcePosImpl
 * address:  0x0202BA7C
 * packet:   pkt_0202BA7C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for arm9 func_0202B934 (ov021 func_021C4E34)
 * (wave A1, lane 13).
 */

typedef struct { int x, y, z; } V3;
typedef struct { int f0; V3 pos; int f10; int f14; int f18; } E;
typedef struct { char pad[0x24]; E e[1]; } M;

static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void ISS_3DS_SYS_SetSourcePosImpl(M *m, int i, const V3 *v)
{
    E *e = &m->e[i];

    if (e->f0 != 0)
        V3_Set(&e->pos, v->x, v->y, v->z);
}
