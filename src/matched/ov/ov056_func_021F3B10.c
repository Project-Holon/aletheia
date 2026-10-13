/*
 * function: FIELD_FK_DEMO_InitModel
 * address:  0x021F3B10
 * packet:   pkt_ov056_021F3B10
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the image loads the stack parameter idx into r4 before the first
 *           call and keeps it there to the arms' idx * 6.  An unassigned stack
 *           parameter is re-read from its slot at each use (228 bytes); any
 *           assignment to it makes it a register variable loaded at entry.
 *           `idx = (u32)idx;` does that and emits no code (`idx = idx;`,
 *           `idx += 0;` and `idx = idx * 1;` fold away first; `idx *= 6` in the
 *           arms promotes it but multiplies in place, 220 bytes).
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_02008550  0x02008550  thumb
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_AllocVramTexture  0x02047180  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   gFkDemoEndTile     0x021F4308  data  a4
 *   gFkDemoEndDir     0x021F4264  data  a2
 *   gFkDemoOrigin     0x021F426C  data  ov056  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

typedef struct Mtx33 {
    int m[9];
} Mtx33;

typedef struct Obj {
    void *res0;
    void *res1;
    void *res2;
    int f0c;
    u8 pad10[0x10];
    Vec pos;
    Vec scale;
    Mtx33 rot;
    int f5c;
    int f60;
    void *f64;
    void *f68;
    Vec f6c;
    u16 f78;
    u16 pad7a;
    int f7c;
} Obj;

extern void *func_020490F4(u32 id, u32 heap);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void func_0207ADC4(Mtx33 *m);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern int G3D_SYSTEM_AllocVramTexture(u32 *p);
extern void ARC_TOOL_DeleteHandle(void *);

extern const Vec gFkDemoEndTile[];
extern const u16 gFkDemoEndDir[];
extern const Vec gFkDemoOrigin;

void FIELD_FK_DEMO_InitModel(Obj *o, void *a1, int a2, int a3, int idx)
{
    void *h;
    int k;

    idx = (u32)idx;
    h = func_020490F4(0x96, (u16)((a3 & 0x7fff) | 0x8000));
    o->f7c = 0;
    o->f5c = 0;
    o->f6c = gFkDemoEndTile[idx];
    o->f60 = a2;
    o->f78 = gFkDemoEndDir[idx];
    o->f64 = a1;
    o->f68 = FIELD_PLAYER_GetMmdl(a1);
    o->pos = gFkDemoOrigin;
    o->scale.x = 0x1000;
    o->scale.y = 0x1000;
    o->scale.z = 0x1000;
    func_0207ADC4(&o->rot);
    if (func_02008550((const struct Sub0200852CObj *)a2) == 0) {
        k = idx * 6;
        o->res0 = G3D_SYSTEM_CreateResourceArcHandle((u32)h, k + 3);
        o->res2 = G3D_SYSTEM_CreateResourceArcHandle((u32)h, k + 4);
    } else {
        k = idx * 6;
        o->res0 = G3D_SYSTEM_CreateResourceArcHandle((u32)h, k + 1);
        o->res2 = G3D_SYSTEM_CreateResourceArcHandle((u32)h, k + 2);
    }
    o->res1 = G3D_SYSTEM_CreateResourceArcHandle((u32)h, k + 5);
    G3D_SYSTEM_AllocVramTexture(o->res0);
    o->f0c = 1;
    ARC_TOOL_DeleteHandle(h);
}
