/*
 * function: FLDEFF_BUBBLE_Update
 * address:  0x021D0750
 * packet:   pkt_ov021_021D0750
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * G3D_SYSTEM_GetObjectAnimeFrameMax (arm9 ARM leaf) is filed as src/matched/arm9/G3D_SYSTEM_GetObjectAnimeFrameMax.c
 * to give the witness.  EXACT*: the listing extent includes 2 pad bytes.
 *
 * symbols:
 *   FLDEFF_BUBBLE_FindFreeBubble  0x021D07FC  thumb  ov021
 *   FLDEFF_BUBBLE_SpawnBubble  0x021D0824  thumb  ov021
 *   FLDEFF_BUBBLE_UpdateBubble  0x021D08BC  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   G3D_SYSTEM_GetObjectAnimeFrameMax  0x02047888  arm
 */

typedef unsigned char u8;
typedef signed char s8;

typedef struct S {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S;

struct Row;
extern struct Row *FLDEFF_BUBBLE_FindFreeBubble(struct S *s);
extern void FLDEFF_BUBBLE_SpawnBubble(int *p, int a);
extern void FLDEFF_BUBBLE_UpdateBubble(struct Row *r, int v);
extern int FLDMMDL_CheckPossibleAcmd(int p);
extern int G3D_SYSTEM_GetObjectAnimeFrameMax(int *a, int idx, int *out);

void FLDEFF_BUBBLE_Update(int unused, S *s)
{
    int v;
    int i;
    void *r;

    s->fA++;
    if (s->fA >= 0x78) {
        r = FLDEFF_BUBBLE_FindFreeBubble(s);
        if (r) {
            FLDEFF_BUBBLE_SpawnBubble(r, s->f4);
        }
        s->fA = 0;
    }
    if (s->f8 != FLDMMDL_CheckPossibleAcmd(s->f4)) {
        s->f9++;
        if (s->f9 >= 5) {
            r = FLDEFF_BUBBLE_FindFreeBubble(s);
            if (r) {
                FLDEFF_BUBBLE_SpawnBubble(r, s->f4);
            }
            s->f9 = 0;
        }
        s->f8 = FLDMMDL_CheckPossibleAcmd(s->f4);
    }
    G3D_SYSTEM_GetObjectAnimeFrameMax((int *)s->f0[7], 0, &v);
    for (i = 0; i < 6; i++) {
        FLDEFF_BUBBLE_UpdateBubble((struct Row *)s->rows[i], v);
    }
}
