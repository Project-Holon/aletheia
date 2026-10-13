/*
 * function: PARTICLE_CreateSystem
 * address:  0x02050C30
 * packet:   pkt_02050C30
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_pParticleMan     0x02146A88  data
 *   sParticleFile     0x020A7FC0  data
 *   sDefaultCameraPos     0x020A1590  data
 *   sDefaultCameraTarget     0x020A1584  data
 *   sDefaultCameraUp     0x020A1578  data
 *   sSystemEngineIds     0x020A15A8  data
 *   func_02030734  0x02030734  arm
 *   PARTICLE_InitCamera  0x02051648  arm
 *   func_02052DC8  0x02052DC8  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *
 * particle.c, the emitter constructor (wave 13): find a free slot among the
 * sixteen in the 0x02146A88 table, allocate a 0x260-byte emitter (particle.c
 * line 285), clear it, copy the three default vectors in as struct
 * assignments, clear flag bit 0, wire the span fields from (a0, a1), publish
 * the emitter in its slot, optionally build the 3D block (a2 == 1), and store
 * func_02052DC8's handle at +0.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02050C30.c.txt: size-exact at 392 with 37
 * bytes out inside the final argument setup, permuter exhausted): the
 * per-slot table 0x020A15A8 is CONST, `extern const u32 sSystemEngineIds[];`.
 * Without const the element load may not move above the two argument stores
 * to the outgoing area (they could alias it), so the compiler schedules the
 * truncations and stores first; const lets it issue the table base load
 * first and the element load in the middle, as the image does.  The same
 * mechanism as docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md,
 * applied to a global array.  The note's argument order (a3, a4, a5 each
 * truncated with a (u16) cast at the use) and its three other decisions all
 * stand.
 */

#include "../include/G_02146A88.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u32 x, y, z; } Vec3;

extern struct G_02146A88 *g_pParticleMan;
extern const char sParticleFile[];
extern Vec3 sDefaultCameraPos;
extern Vec3 sDefaultCameraTarget;
extern Vec3 sDefaultCameraUp;
extern const u32 sSystemEngineIds[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct Dst648;
struct Src648;
extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern u32   func_02052DC8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  MI_CpuFill8(void *dst, u32 v, u32 n);

struct Emit {
    u32  f00;
    u8   pad04[0x08];
    u32  f0c;
    u32  f10;
    u32  f14;
    u8   pad18[0x1a];
    u16  f32;
    Vec3 f34;
    Vec3 f40;
    Vec3 f4c;
    u8   pad58[0x202];
    u8   f25a;
};

void *PARTICLE_CreateSystem(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 heap)
{
    struct Emit *e;
    u32 *tab;
    int i = 0;

    tab = ((u32 *)g_pParticleMan);
    do {
        if (tab[i] == 0)
            break;
        i++;
    } while (i < 16);
    if (i >= 16)
        return 0;

    e = (struct Emit *)func_02030734((u16)heap, 0x260, 0, sParticleFile, 285);
    MI_CpuFill8(e, 0, 0x260);
    e->f34 = sDefaultCameraPos;
    e->f40 = sDefaultCameraTarget;
    e->f4c = sDefaultCameraUp;
    e->f32 = e->f32 & ~1u;
    MI_CpuFill8((void *)a0, 0, a1);
    e->f0c = a0;
    e->f10 = a0;
    e->f14 = a0 + a1;
    e->f25a = (u8)i;
    ((u32 *)g_pParticleMan)[i] = (u32)e;

    if (a2 == 1)
        PARTICLE_InitCamera((struct Dst648 *)e, 0, 0x2000, 0, 0, 0, heap);

    e->f00 = func_02052DC8(sSystemEngineIds[i], 0x18, 0xc8, (u16)a3, (u16)a4, (u16)a5);
    return e;
}
