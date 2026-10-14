/*
 * function: ZUKAN_DETAIL_VOICE_Exit
 * address:  0x021C2644
 * packet:   pkt_ov208_021C2644
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PM_VOICE_IsAnyActive  0x02006650  thumb
 *   PM_VOICE_StopAll  0x020065D8  thumb
 *   ZUKAN_DETAIL_VOICE_DeleteWaveformWindow  0x021C3638  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_FreeBgPalette  0x021BC97C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_SetBgScrollPacked  0x021BCA54  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics  0x021C2FEC  thumb
 *   ZUKAN_DETAIL_VOICE_ClearTimerWindow  0x021C32FC  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_DeleteTimerWindow  0x021C3268  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_NoOpC  0x021C337C  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_NoOpA  0x021C3374  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_DeleteNumberActors  0x021C2D88  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_DeletePaletteAnim  0x021BC61C  thumb  ov208
 *   ZUKAN_DETAIL_COMMON_FreeBlendWork  0x021BC464  thumb  ov208
 *   ZUKAN_DETAIL_VOICE_RestoreBgm  0x021C2BF4  thumb
 *   func_02030EAC  0x02030EAC  arm
 *   ZUKAN_DETAIL_PROCSYS_FreeBuffer  0x021BC34C  thumb  ov208
 */
#include "../include/Obj03934.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern int PM_VOICE_IsAnyActive(void);
extern void PM_VOICE_StopAll(void);
extern void ZUKAN_DETAIL_VOICE_DeleteWaveformWindow(void *unused, char *p, void *a2);
extern void ZUKAN_DETAIL_COMMON_FreeBgPalette(char *p);
extern void ZUKAN_DETAIL_COMMON_SetBgScrollPacked(u32 a, u32 packed);
struct S;
extern void ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(void *unused, struct S *p, u32 unused2, u32 i);
extern void ZUKAN_DETAIL_VOICE_ClearTimerWindow(u16 *heap, u8 *p, int key);
extern void ZUKAN_DETAIL_VOICE_DeleteTimerWindow(void *unused, char *p, void *a2);
extern void ZUKAN_DETAIL_VOICE_NoOpC(void *a0, void *st, void *a2);
extern void ZUKAN_DETAIL_VOICE_NoOpA(void *a0, void *st, void *a2);
extern void ZUKAN_DETAIL_VOICE_DeleteNumberActors(void *a0, u8 *st, void *a2);
extern void ZUKAN_DETAIL_COMMON_DeletePaletteAnim(char *p);
extern void ZUKAN_DETAIL_COMMON_FreeBlendWork(void *a0);
extern void ZUKAN_DETAIL_VOICE_RestoreBgm(void *unused, char *p, void *a2);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void ZUKAN_DETAIL_PROCSYS_FreeBuffer(char *p);

u32 ZUKAN_DETAIL_VOICE_Exit(void *a0, u32 a1, void *a2, u8 *st, void *a4)
{
    u8 i;

    if (PM_VOICE_IsAnyActive() != 0) {
        PM_VOICE_StopAll();
    }
    ZUKAN_DETAIL_VOICE_DeleteWaveformWindow(a2, (char *)st, a4);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(*(char * *)&((struct Obj03934 *)st)->f80);
    ZUKAN_DETAIL_COMMON_FreeBgPalette(*(char * *)&((struct Obj03934 *)st)->f7C);
    ZUKAN_DETAIL_COMMON_SetBgScrollPacked(2, ((struct Obj03934 *)st)->f78);
    for (i = 0; i < 2; i++) {
        ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(a2, (struct S *)st, (u32)a4, i);
    }
    ZUKAN_DETAIL_VOICE_ClearTimerWindow(a2, st, (int)a4);
    ZUKAN_DETAIL_VOICE_DeleteTimerWindow(a2, (char *)st, a4);
    ZUKAN_DETAIL_VOICE_NoOpC(a2, st, a4);
    ZUKAN_DETAIL_VOICE_NoOpA(a2, st, a4);
    ZUKAN_DETAIL_VOICE_DeleteNumberActors(a2, st, a4);
    ZUKAN_DETAIL_COMMON_DeletePaletteAnim(*(char * *)&((struct Obj03934 *)st)->fC8);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(*(char * *)&((struct Obj03934 *)st)->fC4);
    ZUKAN_DETAIL_COMMON_FreeBlendWork(*(char * *)&((struct Obj03934 *)st)->fC0);
    if (((struct Obj03934 *)st)->fB8 != 3) {
        ZUKAN_DETAIL_VOICE_RestoreBgm(a2, (char *)st, a4);
    }
    func_02030EAC(((struct Obj03934 *)st)->fBC);
    ZUKAN_DETAIL_PROCSYS_FreeBuffer((char *)a0);
    return 1;
}
