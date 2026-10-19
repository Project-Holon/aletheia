/*
 * file:     cdemo_wipe.c
 * unit:     yes
 * function: CDEMO_WIPE_StartFadeOut, CDEMO_WIPE_StartFadeIn, CDEMO_WIPE_StartFadeOutWhite, CDEMO_WIPE_StartFadeInWhite, CDEMO_WIPE_LoadPalette, CDEMO_WIPE_RunScript
 * address:  0x021B6290
 * region:   ov179
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle  0x02049F78  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   KEY_GetTrg 0x020362DC arm
 *   GFL_USE_IsBgmPlaying 0x02005F38 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   d_021B6A04 0x021B6A04 data a4
 */
#include "cdemo_types.h"

typedef unsigned int u32;

extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, u32 unpackedOut, u32 flags);
extern void MIi_CpuCopy32(int, int, int);
extern u32 GFL_HEAP_Free(void *p);
extern u32 KEY_GetTrg(void);
extern int GFL_USE_IsBgmPlaying(void);
extern void GFL_USE_FadeOutBgm(unsigned v);
void CDEMO_WIPE_StartFadeOut(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_StartFadeIn(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_StartFadeOutWhite(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_StartFadeInWhite(char *p, u32 a, u32 b, u32 c);
void CDEMO_WIPE_LoadPalette(void *obj, int a, int b);
int CDEMO_WIPE_RunScript(char *p);


void CDEMO_WIPE_StartFadeOut(char *p, u32 a, u32 b, u32 c)
{
    WIPE_SYS_Start(0, 1, 1, 0, a, b, 0x7f);
    ((struct CdemoState *)p)->fade = c;
}


void CDEMO_WIPE_StartFadeIn(char *p, u32 a, u32 b, u32 c)
{
    WIPE_SYS_Start(0, 0, 0, 0, a, b, 0x7f);
    ((struct CdemoState *)p)->fade = c;
}


void CDEMO_WIPE_StartFadeOutWhite(char *p, u32 a, u32 b, u32 c)
{
    WIPE_SYS_Start(0, 1, 1, 0x7fff, a, b, 0x7f);
    ((struct CdemoState *)p)->fade = c;
}


void CDEMO_WIPE_StartFadeInWhite(char *p, u32 a, u32 b, u32 c)
{
    WIPE_SYS_Start(0, 0, 0, 0x7fff, a, b, 0x7f);
    ((struct CdemoState *)p)->fade = c;
}


void CDEMO_WIPE_LoadPalette(void *obj, int a, int b)
{
    void *ptr;
    int t;
    char *p;

    t = (int)ARC_UTIL_LoadPaletteBlockFromHandle(((struct CdemoState *)obj)->arcHandle, b, (u32)(&ptr), 0x807f);
    p = (char *)obj + 8 + a * 0x2004;
    ((struct CdemoPaletteBlock *)p)->count = ((struct CdemoPaletteEntry *)ptr)->size;
    MIi_CpuCopy32(((struct CdemoPaletteEntry *)ptr)->data, (int)p, ((struct CdemoPaletteBlock *)p)->count);
    GFL_HEAP_Free((void *)t);
}

extern int (*const d_021B6A04[])(char *);

int CDEMO_WIPE_RunScript(char *p)
{
    if (((struct CdemoState *)p)->script->state != 0 && (KEY_GetTrg() & 0xB) != 0) {
        if (GFL_USE_IsBgmPlaying() == 1)
            GFL_USE_FadeOutBgm(8);
        ((struct CdemoState *)p)->result = 1;
        ((struct CdemoState *)p)->script->flag = 1;
    }
    ((struct CdemoState *)p)->result = d_021B6A04[((struct CdemoState *)p)->result](p);
    if (((struct CdemoState *)p)->result != 6)
        return 1;
    return 0;
}
