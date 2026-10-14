/*
 * function: ZUKAN_DETAIL_FORM_PlaceModelItem
 * address:  0x021C569C
 * packet:   pkt_ov208_021C569C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_DETAIL_COMMON_GetCurrentEntry  0x021BC3C0  thumb
 *   ZUKAN_DETAIL_COMMON_GetSource  0x021BC3A4  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_GetSpindaPersonality  0x0200D288  thumb
 *   ZUKAN_DETAIL_FORM_CreateModelItem  0x021C5128  thumb
 *   ZUKAN_DETAIL_FORM_SelectModelPosition  0x021C80AC  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

struct Ov208Mdl {
    u32 obj;
    u32 f4;
    u8  pos[0x3c];
};

extern u16  ZUKAN_DETAIL_COMMON_GetCurrentEntry(int key);
extern int ZUKAN_DETAIL_COMMON_GetSource(int *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
struct Blk37;
extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *p, u32 which);
extern void ZUKAN_DETAIL_FORM_CreateModelItem(struct Ov208Mdl *m, u32 heap, u32 sys, u32 species, u32 a4,
                                u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
extern void ZUKAN_DETAIL_FORM_SelectModelPosition(int a, int b, int c);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_SetVanishFlag(void *p);

#define W(o) (*(u32 *)(p + (o)))
#define MDL(i) ((struct Ov208Mdl *)(p + 0xc) + (i))

void ZUKAN_DETAIL_FORM_PlaceModelItem(u16 *heap, u8 *p, int key, int a, int b, int pose, u16 idx)
{
    Vec v;
    u16 species;
    u32 form;
    u32 f152;
    u32 f153;
    u32 extra;

    extra = 0;
    species = ZUKAN_DETAIL_COMMON_GetCurrentEntry(key);
    form = *(u16 *)(p + idx * 16 + 0x154);
    f152 = *(p + idx * 16 + 0x152);
    f153 = *(p + idx * 16 + 0x153);
    if (species == 0x147)
        extra = ZUKAN_SAVE_GetSpindaPersonality(ZUKAN_SAVE_GetFromGameData((void *)ZUKAN_DETAIL_COMMON_GetSource((int *)key)), extra);
    if (a != 4) {
        ZUKAN_DETAIL_FORM_CreateModelItem(MDL(a), *heap, W(8), species, form, f152, f153, 0, 0, extra);
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)MDL(a), pose, (int)(&v));
        MCSS_SetPosition((void *)MDL(a)->obj, (u32 *)(&v));
        if (W(0x124) == 0)
            MCSS_SetVanishFlag((void *)MDL(a)->obj);
    }
    if (b != 4) {
        ZUKAN_DETAIL_FORM_CreateModelItem(MDL(b), *heap, W(8), species, form, f152, f153, 0, 1, extra);
        ZUKAN_DETAIL_FORM_SelectModelPosition((int)MDL(b), pose, (int)(&v));
        MCSS_SetPosition((void *)MDL(b)->obj, (u32 *)(&v));
        if (W(0x124) != 0)
            MCSS_SetVanishFlag((void *)MDL(b)->obj);
    }
}
