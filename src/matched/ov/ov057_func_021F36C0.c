/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov057_021F36C0
 * region:   ov057
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resource setup; ov057_func_021F37BC is its teardown over the same arrays.
 * The second loop is an if/else with the call written in each arm (the
 * shared p->res[t] load is hoisted above the beq and the calls cross-jump);
 * a ternary third argument reloads in each arm. The four index tables
 * resolve as sole-ref only with the ov057 token dropped.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_CheckResourceType  0x02046F50  arm
 *   G3D_SYSTEM_TransVramTexture  0x02046FF8  arm
 *   G3D_SYSTEM_CreateRender  0x02047400  arm
 *   G3D_SYSTEM_CreateAnime  0x02047564  arm
 *   G3D_SYSTEM_CreateObject  0x0204767C  arm
 *   G3D_SYSTEM_EnableObjectAnime  0x020477A4  arm
 *   G3D_SYSTEM_SetSwapBuffersMode  0x02046BE0  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   d_021F38A8     0x021F38A8  data  a4
 *   d_021F387C     0x021F387C  data  a4
 *   d_021F3888     0x021F3888  data  a4
 *   d_021F3898     0x021F3898  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Res {
    u32 res[7];
    u32 tex[3];
    u32 anm[4];
    u32 obj[3];
} Res;

typedef unsigned char  u8;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Tagged;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern u32 G3D_SYSTEM_CheckResourceType(struct Tagged *p, u32 sel);
extern int G3D_SYSTEM_TransVramTexture(int *self);
extern void *G3D_SYSTEM_CreateRender(void *a0, u32 n, void *a2);
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void ARC_TOOL_DeleteHandle(void *);

extern const u32 d_021F38A8[];
extern const u32 d_021F387C[];
extern const u32 d_021F3888[];
extern const u32 d_021F3898[];

void func_021F36C0(int a, int b, Res *p)
{
    void *h;
    int i;
    u32 t;

    h = func_020490F4(0xbe, (u16)((FIELDMAP_GetHeapId((u8 *)b) & 0x7fff) | 0x8000));
    for (i = 0; i < 7; i++) {
        if (G3D_SYSTEM_CheckResourceType((struct Tagged *)(p->res[i] = (u32)G3D_SYSTEM_CreateResourceArcHandle((u32)h, d_021F38A8[i])), 2)) {
            G3D_SYSTEM_TransVramTexture((int *)p->res[i]);
        }
    }
    for (i = 0; i < 3; i++) {
        t = d_021F387C[i];
        if (G3D_SYSTEM_CheckResourceType((struct Tagged *)p->res[t], 2)) {
            p->tex[i] = (u32)G3D_SYSTEM_CreateRender((void *)p->res[t], 0, (void *)p->res[t]);
        } else {
            p->tex[i] = (u32)G3D_SYSTEM_CreateRender((void *)p->res[t], 0, 0);
        }
    }
    for (i = 0; i < 4; i++) {
        p->anm[i] = (u32)G3D_SYSTEM_CreateAnime((struct G3dOwner *)p->tex[d_021F3888[i]], (const struct G3dOwner *)p->res[d_021F3898[i]], 0);
    }
    for (i = 0; i < 3; i++) {
        p->obj[i] = (u32)G3D_SYSTEM_CreateObject(p->tex[i], p->anm, 4);
    }
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->obj[0], 0);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->obj[0], 3);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->obj[1], 1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)p->obj[2], 2);
    G3D_SYSTEM_SetSwapBuffersMode(1, 1);
    ARC_TOOL_DeleteHandle(h);
}
