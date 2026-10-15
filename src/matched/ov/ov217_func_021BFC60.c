/*
 * function: RESEARCH_GRAPH_BuildGraphTable
 * address:  0x021BFC60
 * packet:   pkt_ov217_021BFC60
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetAppResource 0x021BF740 thumb ov217
 *   RESEARCH_GRAPH_GetFirstSaveGroup 0x021BF8B0 thumb ov217
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   MISC_SAVEDATA_GetStatusByte 0x0200E44C thumb
 *   MISC_SAVEDATA_GetHalfword 0x0200E458 thumb
 *   MISC_SAVEDATA_GetTallyWord 0x0200E47C thumb
 *   MISC_SAVEDATA_GetTallyValue 0x0200E4B0 thumb
 *   MISC_SAVEDATA_GetScoreValue 0x0200E4F8 thumb
 *   d_021C367C 0x021C367C data a1
 *   d_021C3D44 0x021C3D44 data a1
 *   d_021C386C 0x021C386C data a1
 *   d_021C3900 0x021C3900 data a1
 *   d_021C3994 0x021C3994 data a1
 *
 * blocker (2026-10-02, lane04 wC1): 203 bytes differ, relocations all resolve.
 * Locals now laid out like the original (sh, A, B, va, vb, buf declaration
 * order gives the right stack slots). Left: the original keeps the first
 * loop counter in memory (sp+0x20) and addresses buf+3 as reg+reg, has one
 * more spill word (frame sub sp 0x4c vs 0x48), first byte in sp+0x1c, and
 * spills grp[1] to sp+8. Opus lane to finish.
 *
 * Addresses are Black-image addresses.
 *
 * Note 2026-10-04 (wD2 lane04): n, i, first now sit in the original slots (declare `int n` before
 * `i`, then `first`; 195 bytes differ). Left: the u8 c1 spill (original sp+8, the last slot, below the four
 * loop pointer temps at 0x18..0xc; here 0x18), k lives in memory (sp+4), and buf+3 is formed as
 * `add r1,sp,#0x28; adds r1,#3` then reg+reg (here folded to [r0,#3]); a two-array struct
 * {u8 a[3]; u8 b[3]} did not change that.
 * Note 2026-10-05 (wD4 lane12): MATCH, all 480 bytes. Keys: buf is two
 * separate u8 arrays grp[3] (declared first, lands at sp+0x2B) and cnt[3]
 * (sp+0x28), which gives the `add sp,#0x28; adds #3` reg+reg form; no c0/c1/c2
 * locals (grp[x] re-read, the compiler CSE temp takes the sp+8 slot below the
 * loop temps); no `a` local for va[k]; `s = sh[k][j]` before `r = q + j*12`.
 * Only blocker: arm9 callee 0x0200E47C had no label. Filed it as
 * src/matched/arm9/MISC_SAVEDATA_GetTallyWord.c (EXACT, 10 bytes); this goes EXACT once
 * that file has a shard (integrator).
 * Note 2026-10-04 (wD1 lane06): Not retried (203 bytes, stack slot order only). No new finding.
 */

#include "../include/G_Bg.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u8 d_021C367C[];
extern u8 d_021C3D44[][17];
extern struct Bg d_021C386C;
extern u8 d_021C3900[];
extern u8 d_021C3994[];
struct Big;
extern u32 RESEARCH_GRAPH_GetAppResource(u8 *a0);
extern u8 RESEARCH_GRAPH_GetFirstSaveGroup(u8 *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern int MISC_SAVEDATA_GetStatusByte(int p0, int p1);
extern u16 MISC_SAVEDATA_GetHalfword(const u16 *p, int i);
extern u32 MISC_SAVEDATA_GetTallyWord(u8 *p, int i);
extern u32 MISC_SAVEDATA_GetTallyValue(u8 *a0, u32 a1, u32 a2);
extern int MISC_SAVEDATA_GetScoreValue(int a0, int a1, int a2);
void RESEARCH_GRAPH_BuildGraphTable(char *p)
{
    u16 sh[3][17];
    u32 A[3][17];
    u32 B[3][17];
    u32 va[3];
    u32 vb[3];
    u8 grp[3];
    u8 cnt[3];
    int n;
    int i, j, k;
    void *h;
    u8 first;
    h = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_GRAPH_GetAppResource((u8 *)p)));
    first = RESEARCH_GRAPH_GetFirstSaveGroup((u8 *)p);
    i = 0;
    grp[0] = MISC_SAVEDATA_GetStatusByte((int)h, 0);
    grp[1] = MISC_SAVEDATA_GetStatusByte((int)h, 1);
    grp[2] = MISC_SAVEDATA_GetStatusByte((int)h, 2);
    cnt[0] = d_021C367C[grp[0]];
    cnt[1] = d_021C367C[grp[1]];
    cnt[2] = d_021C367C[grp[2]];
    va[0] = MISC_SAVEDATA_GetHalfword(h, grp[0]);
    va[1] = MISC_SAVEDATA_GetHalfword(h, grp[1]);
    va[2] = MISC_SAVEDATA_GetHalfword(h, grp[2]);
    vb[0] = MISC_SAVEDATA_GetTallyWord(h, grp[0]);
    vb[1] = MISC_SAVEDATA_GetTallyWord(h, grp[1]);
    vb[2] = MISC_SAVEDATA_GetTallyWord(h, grp[2]);
    for (i = 0; i < 3; i++) {
        u8 g = grp[i];
        n = cnt[i];
        for (j = 0; j < n; j++) {
            sh[i][j] = d_021C3D44[g][j];
            A[i][j] = MISC_SAVEDATA_GetTallyValue(h, g, j + 1);
            B[i][j] = MISC_SAVEDATA_GetScoreValue((int)h, g, j + 1);
        }
    }
    *(u8 *)(p + 0x38) = first;
    for (k = 0; k < 3; k++) {
        char *q = p + k * 0xd4;
        *(u8 *)(q + 0x3c) = grp[k];
        *(u8 *)(q + 0x3d) = cnt[k];
        *(u16 *)(q + 0x3e) = va[k];
        *(u32 *)(q + 0x40) = va[k] + vb[k];
        if (*(u32 *)(q + 0x40) > 999999) {
            *(u32 *)(q + 0x40) = 999999;
        }
        for (j = 0; j < 17; j++) {
            u16 s = sh[k][j];
            char *r = q + j * 12;
            u32 x;
            *(u16 *)(r + 0x44) = s;
            *(u8 *)(r + 0x46) = ((u8 *)&d_021C386C)[s];
            *(u8 *)(r + 0x47) = d_021C3900[s];
            *(u8 *)(r + 0x48) = d_021C3994[s];
            x = A[k][j];
            *(u16 *)(r + 0x4a) = x;
            *(u32 *)(r + 0x4c) = x + B[k][j];
        }
    }
}
