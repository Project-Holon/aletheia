/*
 * function: BTLV_MCSS_StartAlphaTween
 * address: 0x021FF924
 * packet: pkt_ov094_021FF924
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * 2026-10-01: the arm9 witness leaves named below are now filed in
 * src/matched/arm9, which closes the former MATCH.
 * blocker: ARM9 0x02015FAC has no outside witness at all three call sites.
 * Verified scratch C, EXACT (blocker_02015FAC_r1.log):
 * typedef unsigned char u8;
 * typedef struct { char pad[0x140]; unsigned int value : 8; } Data;
 * u8 MCSS_GetAlpha(Data *p) { return p->value; }
 * symbols:
 *   BTLV_MCSS_FindSpriteIndex 0x022019F4 thumb ov094
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   BTLV_MCSS_CreateTweenTask 0x0220074C thumb ov094
 *   BTLV_EFFECT_GetBitMask 0x021F935C thumb ov094
 *   BTLV_MCSS_AlphaTweenTaskMain 0x02200D68 thumb ov094
 *   BTLV_MCSS_AlphaTweenTaskEnd 0x02200DE4 thumb ov094
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 */
#include "../include/Obj06309.h"
typedef unsigned char u8;
typedef struct { int x, y, z; } Vec;
extern int BTLV_MCSS_FindSpriteIndex(char *p, int key);
extern u8 MCSS_GetAlpha(void *p);
extern void BTLV_MCSS_CreateTweenTask(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern int BTLV_EFFECT_GetBitMask(int x);
extern void BTLV_MCSS_AlphaTweenTaskMain(void *o, char *q);
extern void BTLV_MCSS_AlphaTweenTaskEnd(void *p);
#define FX(x) ((int)(((x) > 0) ? ((float)((x) << 12) + .5f) : ((float)((x) << 12) - .5f)))
void BTLV_MCSS_StartAlphaTween(char *w, int key, int kind, int value, int a, int b, int c)
{
    int idx = BTLV_MCSS_FindSpriteIndex(w, key);
    char *e;
    int off;
    Vec start, end;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    start.x = FX(MCSS_GetAlpha(*(void **)(e + off)));
    start.y = 0;
    start.z = 0;
    end.x = FX(value);
    end.y = 0;
    end.z = 0;
    (*(u8 *)(w + 0x596 + key))++;
    BTLV_MCSS_CreateTweenTask(w, key, kind, &start, &end, a, b, c, (void *)BTLV_MCSS_AlphaTweenTaskMain, BTLV_MCSS_AlphaTweenTaskEnd, 0, *(u8 *)(w + 0x596 + key));
    ((struct Obj06309 *)w)->f52C |= BTLV_EFFECT_GetBitMask(key);
}
