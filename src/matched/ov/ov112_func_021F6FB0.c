/*
 * function: func_021F6FB0
 * address: 0x021F6FB0
 * packet: pkt_ov112_021F6FB0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before 021F7048.
 * symbols:
 *   func_021F7048 0x021F7048 thumb ov112
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 */
typedef unsigned char u8;
typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;
extern void func_021F7048(Cleanup *);
typedef unsigned int   u32;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
extern void *G3D_SYSTEM_CreateResourceArc(u32 a0, u32 a1);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
void func_021F6FB0(Cleanup *p, char *q) {
    u8 i, j;
    if (p->single != 0) func_021F7048(p);
    p->single = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x1e));
    p->a[0] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x24));
    p->a[1] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x2e));
    p->a[2] = (int)G3D_SYSTEM_CreateResourceArc(0x2f, (u32)(q + 0x29));
    if (G3D_SYSTEM_TransVramTexture((int *)p->single) != 0) {
        p->b = (int)G3D_SYSTEM_CreateRender((void *)p->single, 0, (void *)p->single);
        for (i = 0; i < 3; i++) p->c[i] = (int)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p->b, (const struct G3dOwner *)p->a[i], 0);
        p->d = (int)G3D_SYSTEM_CreateObject(p->b, (u32 *)p->c, 3);
        for (j = 0; j < 3; j++) G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->d, j);
    }
}
