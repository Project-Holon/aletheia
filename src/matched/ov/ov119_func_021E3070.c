/*
 * function: POKETRADE_3D_InitTradeParticleSet
 * address:  0x021E3070
 * packet:   pkt_ov119_021E3070
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_InitManager  0x02050B80  arm
 *   func_02030734  0x02030734  arm
 *   PARTICLE_CreateSystemDefault  0x02050C04  arm
 *   PARTICLE_LoadArchiveMember  0x0205121C  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *   gParticleBufferAllocTag  0x021E81C0  data a1
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void PARTICLE_InitManager(u32 heap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void PARTICLE_SetupSystem(void *, void *, int, int);
extern const char gParticleBufferAllocTag[];

typedef struct {
    void *a[9];         /* 0x000 */
    void *b[6];         /* 0x024 */
    u16 pad3C[0x3F];    /* 0x03C */
    u16 heap;           /* 0x0BA */
} S;

void POKETRADE_3D_InitTradeParticleSet(S *p)
{
    int i;
    void *buf;
    void *h;
    void **q;

    PARTICLE_InitManager(p->heap);
    for (i = 0; i < 6; i++) {
        q = &p->a[i];
        buf = func_02030734(p->heap, 0x4800, 1, gParticleBufferAllocTag, 0x273);
        q[9] = buf;
        *q = (void *)PARTICLE_CreateSystemDefault((int)buf, 0x4800, 0, p->heap);
    }
    h = (void *)PARTICLE_LoadArchiveMember(0x68, 10, p->heap);
    for (i = 0; i < 6; i++)
        PARTICLE_SetupSystem(p->a[i], h, 1, 0);
}
