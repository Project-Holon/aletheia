/*
 * function: BTLV_STAGE_Create
 * address: 0x021F6560
 * packet: pkt_ov094_021F6560
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: the id scan reuses `i` (not a fresh `j`) so its spilled web takes the
 * lowest stack slot; k = 0 sits after the allocation loop, whose 0/1 clear
 * arguments then reuse the k and i slots.
 * symbols:
 *   sub_02030734 0x02030734 arm
 *   ARC_TOOL_LoadMember 0x02048F60 arm
 *   G3D_SYSTEM_CreateResourceArc 0x02046DB8 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   func_0207ADC4 0x0207ADC4 arm
 *   G3D_SYSTEM_GetResourceFile 0x02046F48 arm
 *   NNS_G3dGetTex 0x0206E964 arm
 *   func_0207DCF8 0x0207DCF8 arm
 *   sub_020307B0 0x020307B0 arm
 *   gBtlvStageFileName 0x0220AC40 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int kind, a, b, c; } Ent;
typedef struct {
    int f0;
    int ids[4][4];
} Rec;
typedef struct {
    int f0, f4, f8;
    int sx, sy, sz;
    int matrix[9];
} Xf;
typedef struct {
    void *f0;
    int n;
    Ent *arr[2];
    void **f10;
    void **f14[2];
    void *h1c[2];
    void *h24[2];
    Xf xf[2];
    void **fa4;
    void **fa8;
    u8 fac, fad;
    u8 padae[10];
    u16 heap;
    u16 padba;
} Obj;
extern const char gBtlvStageFileName[];
extern void *sub_02030734(u32, u32, int, const char *, u16);
extern void *ARC_TOOL_LoadMember(u32, u32, u32);
extern void *G3D_SYSTEM_CreateResourceArc(u32, u32);
extern int G3D_SYSTEM_TransVramTexture(int *);
extern void *G3D_SYSTEM_CreateRender(void *, u32, void *);
struct G3dOwner;
struct G3dRec;
struct Tagged;
extern struct G3dRec *G3D_SYSTEM_CreateAnime(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
struct G3dSys;
extern void *G3D_SYSTEM_CreateObject(u32 a0, u32 *a1, int a2);
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
extern void func_0207ADC4(int *);
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void func_0207DCF8(void *);
extern u32 sub_020307B0(void *p);

Obj *BTLV_STAGE_Create(int mode, int group, int variant, u16 heap)
{
    Obj *o;
    Rec *table;
    int i, k, m;
    int bytes;
    o = sub_02030734(heap, 0xbc, 1, gBtlvStageFileName, 0x63);
    table = ARC_TOOL_LoadMember(0x98, 2, (u16)((heap & 0x7fff) | 0x8000));
    o->heap = heap;
    if (mode == 3)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, 0x56);
    else if (table[group].ids[0][variant] != -1)
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[0][variant]);
    else
        o->f0 = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[0][0]);
    G3D_SYSTEM_TransVramTexture(o->f0);
    o->n = 0;
    for (i = 1; i < 4; i++)
        if (table[group].ids[i][variant] != -1) o->n++;
    o->h1c[0] = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    o->h1c[1] = G3D_SYSTEM_CreateRender(o->f0, 0, o->f0);
    if (mode == 3) {
        o->n = 1;
        o->f10 = sub_02030734(o->heap, 4, 0, gBtlvStageFileName, 0x93);
        *o->f10 = G3D_SYSTEM_CreateResourceArc(11, 0x57);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, 4, 0, gBtlvStageFileName, 0x98);
            o->arr[i] = sub_02030734(o->heap, 0x10, 1, gBtlvStageFileName, 0x99);
            *o->f14[i] = G3D_SYSTEM_CreateAnime(o->h1c[i], *o->f10, 0);
            o->arr[i]->kind = 1;
            o->h24[i] = G3D_SYSTEM_CreateObject((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            G3D_SYSTEM_EnableObjectAnime(o->h24[i], (u16)0);
        }
    } else if (o->n != 0) {
        o->f10 = sub_02030734(o->heap, o->n * 4, 0, gBtlvStageFileName, 0xa7);
        for (i = 0; i < 2; i++) {
            o->f14[i] = sub_02030734(o->heap, o->n * 4, 0, gBtlvStageFileName, 0xab);
            o->arr[i] = sub_02030734(o->heap, o->n * 16, 1, gBtlvStageFileName, 0xac);
        }
        k = 0;
        for (i = 1; i < 4; i++) {
            if (table[group].ids[i][variant] != -1) {
                o->f10[k] = G3D_SYSTEM_CreateResourceArc(11, table[group].ids[i][variant]);
                for (m = 0; m < 2; m++) {
                    o->f14[m][k] = G3D_SYSTEM_CreateAnime(o->h1c[m], o->f10[k], 0);
                    o->arr[m][k].kind = 0;
                }
                k++;
            }
        }
        for (i = 0; i < 2; i++) {
            o->h24[i] = G3D_SYSTEM_CreateObject((u32)o->h1c[i], (u32 *)o->f14[i], (u16)o->n);
            for (m = 0; m < o->n; m++) G3D_SYSTEM_EnableObjectAnime(o->h24[i], (u16)m);
        }
    } else {
        o->h24[0] = G3D_SYSTEM_CreateObject((u32)o->h1c[0], 0, (u16)0);
        o->h24[1] = G3D_SYSTEM_CreateObject((u32)o->h1c[1], 0, (u16)0);
    }
    bytes = *(u16 *)(NNS_G3dGetTex(G3D_SYSTEM_GetResourceFile(o->f0)) + 0x30) * 8;
    o->fa4 = sub_02030734(o->heap, 4, 0, gBtlvStageFileName, 0xd6);
    o->fa8 = sub_02030734(o->heap, 4, 0, gBtlvStageFileName, 0xd7);
    *o->fa4 = o->f0;
    *o->fa8 = sub_02030734(o->heap, bytes, 0, gBtlvStageFileName, 0xda);
    o->fac = 0;
    o->fad = 1;
    o->xf[0].f0 = 0;
    o->xf[0].f4 = 0;
    o->xf[0].f8 = 0x572f;
    o->xf[0].sx = 0x1000;
    o->xf[0].sy = 0x1000;
    o->xf[0].sz = 0x1000;
    func_0207ADC4(o->xf[0].matrix);
    o->xf[1].f0 = 0;
    o->xf[1].f4 = 0;
    o->xf[1].f8 = -0xcb7d;
    o->xf[1].sx = 0x1000;
    o->xf[1].sy = 0x1000;
    o->xf[1].sz = 0x1000;
    func_0207ADC4(o->xf[1].matrix);
    if (mode == 3) {
        o->xf[0].f8 = 0xa000;
        o->xf[1].f8 = -0xf000;
    }
    func_0207DCF8(&table[group]);
    sub_020307B0(table);
    return o;
}
