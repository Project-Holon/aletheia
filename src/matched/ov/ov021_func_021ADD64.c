/*
 * function: FLDEFF_IWAKUDAKI_UploadTexturesTask
 * address:  0x021ADD64
 * packet:   pkt_ov021_021ADD64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_TransAllocatedTexture  0x02047204  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Q { u32 f0; u32 f4; u32 arr[4]; u32 f18; u32 f1c; } Q;

struct Tagged;
extern u32 G3D_SYSTEM_TransAllocatedTexture(struct Tagged *p);

void FLDEFF_IWAKUDAKI_UploadTexturesTask(u32 a, Q *q)
{
    if (q->f1c == 0) {
        G3D_SYSTEM_TransAllocatedTexture((struct Tagged *)q->f4);
        q->f1c = 1;
    }
}
