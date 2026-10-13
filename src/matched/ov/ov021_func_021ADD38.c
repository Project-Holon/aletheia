/*
 * function: FLDEFF_IWAKUDAKI_FreeResources
 * address:  0x021ADD38
 * packet:   pkt_ov021_021ADD38
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DeleteResource  0x02046EFC  arm  arm9
 *   G3D_SYSTEM_FreeVramTexture  0x020470D0  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Q { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q;

struct Node;
struct Tagged;
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void func_02030EAC(struct Node *n);

void FLDEFF_IWAKUDAKI_FreeResources(Q *q)
{
    int i;

    for (i = 0; i < 4; i++)
        G3D_SYSTEM_DeleteResource((struct Tagged *)q->arr[i]);
    G3D_SYSTEM_FreeVramTexture((u32 *)q->f4);
    G3D_SYSTEM_DeleteResource((struct Tagged *)q->f4);
    func_02030EAC((struct Node *)q->f18);
}
