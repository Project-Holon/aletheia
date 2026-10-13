/*
 * function: FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime
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

extern int SOUND_OBJ_SetAnimeFrame(void *, int);

int FIELD_GIMMICK_SOUND_OBJS_B_RestartAnime(char *a, int b)
{
    return SOUND_OBJ_SetAnimeFrame(*(void **)(a + 4 * b + 8), 0);
}
