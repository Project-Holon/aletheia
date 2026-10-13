/*
 * function: GIMMICK54_RestartAnime
 * address:  0x021F393C
 * packet:   pkt_021F393C
 * region:   ov054
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call wrapper: SOUND_OBJ_SetAnimeFrame(*(void **)(a + 4*b + 8), 0).  The pool
 * word names the thumb function at 0x021C4E08; that address is labelled in
 * both ov021 and ov093, so the symbols line carries the ov093 hint to
 * disambiguate.  Resolved as label (3 outside branches).
 *
 * symbols:
 *   SOUND_OBJ_SetAnimeFrame  0x021C4E08  thumb  ov093
 */

/* Sound object and gimmick work of unit_021F36C0.c; only the fields used here. */
struct SoundObj;

typedef struct Gimmick54Work {
    unsigned short heapId;
    unsigned short reserved02;
    void *iss3ds;
    struct SoundObj *soundObj[2];
} Gimmick54Work;

extern void SOUND_OBJ_SetAnimeFrame(struct SoundObj *obj, int frame);

/* Restarts the animation of one sound object at its first frame. */
void GIMMICK54_RestartAnime(Gimmick54Work *work, int index)
{
    SOUND_OBJ_SetAnimeFrame(work->soundObj[index], 0);
}
