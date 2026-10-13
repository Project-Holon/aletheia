/*
 * function: FLDEFF_IWAKUDAKI_LoadResources
 * address:  0x021ADCF0
 * packet:   pkt_ov021_021ADCF0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   G3D_SYSTEM_CreateResourceArcHandle  0x02046E24  arm
 *   G3D_SYSTEM_AllocVramTexture  0x02047180  arm
 *   func_020056A0  0x020056A0  thumb
 *   FLDEFF_IWAKUDAKI_UploadTexturesTask  0x021ADD64  thumb  ov021
 *   sIwakudakiAnimeFiles     0x021DE0FC  data  a4
 */

extern int sIwakudakiAnimeFiles[];

typedef unsigned char  u8;
extern unsigned int FIELD_EFFECT_GetArcHandle(u8 *p);
extern void *G3D_SYSTEM_CreateResourceArcHandle(unsigned int a0, unsigned int a1);
extern int G3D_SYSTEM_AllocVramTexture(unsigned int *p);
extern int func_020056A0(void *fn, void *arg, int z);
typedef unsigned int   u32;
struct Q;
extern void FLDEFF_IWAKUDAKI_UploadTexturesTask(u32 a, struct Q *q);

void FLDEFF_IWAKUDAKI_LoadResources(int *p)
{
    int r7 = FIELD_EFFECT_GetArcHandle((u8 *)p[0]);
    int i;

    G3D_SYSTEM_AllocVramTexture((unsigned int *)(p[1] = (int)G3D_SYSTEM_CreateResourceArcHandle(r7, 0x4d)));
    p[6] = func_020056A0((void *)FLDEFF_IWAKUDAKI_UploadTexturesTask, p, 0);
    for (i = 0; i < 4; i++)
        p[2 + i] = (int)G3D_SYSTEM_CreateResourceArcHandle(r7, sIwakudakiAnimeFiles[i]);
}
