/*
 * function: GIMMICK53_RestartAnime
 * address: 0x021F3A5C
 * packet: pkt_ov053_021F3A5C
 * region: ov053
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SOUND_OBJ_SetAnimeFrame 0x021C4E08 thumb ov021
 */

extern int SOUND_OBJ_SetAnimeFrame(void *, int);
int GIMMICK53_RestartAnime(char *p, int i) { return SOUND_OBJ_SetAnimeFrame(*(void **)(p+8+4*i),0); }
