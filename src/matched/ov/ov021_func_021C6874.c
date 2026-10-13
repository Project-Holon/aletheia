/*
 * function: FIELD_G3DOBJ_LoadResource
 * address:  0x021C6874
 * packet:   pkt_ov021_021C6874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   G3D_SYSTEM_CreateResourceArcHandle   0x02046E24  arm
 *   G3D_SYSTEM_CheckResourceType   0x02046F50  arm
 *   G3D_SYSTEM_GetResourceFile   0x02046F48  arm
 *   NNS_G3dGetTex   0x0206E964  arm
 *   PALANM_ConvertGrayTable   0x02022040  thumb
 *   FIELD_G3DOBJ_TransferResourceTexture   0x021C6854  thumb  ov021
 *   MIi_CpuClear32  0x02082A7C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8[8];
    u8 f28;
    u8 f29;
} S;

typedef struct {
    u32 f0;
    u32 f4;
    u32 f8;
    u16 fC;
    u16 fE;
    u16 f10[8];
    u8 f20;
} D;

typedef struct {
    u8 pad0[0x30];
    u16 f30;
    u8 pad32[6];
    u32 f38;
} Pal;

struct Tagged;
extern void *G3D_SYSTEM_CreateResourceArcHandle(u32 a0, u32 a1);
extern u32 G3D_SYSTEM_CheckResourceType(struct Tagged *p, u32 sel);
extern void *G3D_SYSTEM_GetResourceFile(struct Tagged *p);
extern unsigned char *NNS_G3dGetTex(unsigned char *p);
extern void PALANM_ConvertGrayTable(u16 *pal, int n, const u8 *table);
extern void FIELD_G3DOBJ_TransferResourceTexture(S *s);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);

void FIELD_G3DOBJ_LoadResource(S *s, int unused, D *d, int mode, int flag)
{
    u32 h;
    Pal *p;
    int i;

    if (d->f0 != 0)
        s->f0 = (u32)G3D_SYSTEM_CreateResourceArcHandle(d->f0, d->fC);
    if (d->f4 != 0)
        s->f4 = (u32)G3D_SYSTEM_CreateResourceArcHandle(d->f4, d->fE);
    if (flag != 0) {
        h = 0;
        if (s->f0 != 0)
            h = s->f0;
        if (s->f4 != 0)
            h = s->f4;
        if (G3D_SYSTEM_CheckResourceType((struct Tagged *)h, 2)) {
            p = (Pal *)NNS_G3dGetTex((unsigned char *)((u32)G3D_SYSTEM_GetResourceFile((struct Tagged *)h)));
            PALANM_ConvertGrayTable((u16 *)((u8 *)p + p->f38), (u32)(p->f30 << 3) / sizeof(u16), (const u8 *)flag);
        }
    }
    if (s->f0 != 0 || s->f4 != 0) {
        if (mode == 1)
            FIELD_G3DOBJ_TransferResourceTexture(s);
        else
            s->f29 = 2;
    }
    if (d->f20 != 0) {
        s->f28 = d->f20;
        MIi_CpuClear32(0, s->f8, sizeof(s->f8));
        for (i = 0; i < s->f28; i++)
            s->f8[i] = (u32)G3D_SYSTEM_CreateResourceArcHandle(d->f8, d->f10[i]);
    }
}
