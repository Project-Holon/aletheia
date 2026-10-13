/*
 * function: IRC_RANKING_SeqFadeIn
 * address: 0x021B78E0
 * packet: pkt_ov106_021B78E0
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_RANKING_ListFindLatestScrollPos 0x021B84D0 thumb ov106
 *   IRC_RANKING_SeqSetFunc 0x021B78D0 thumb ov106
 *   IRC_RANKING_SeqScrollToLatest 0x021B7BC4 thumb ov106
 *   IRC_RANKING_SeqBrowse 0x021B7984 thumb ov106
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern int IRC_RANKING_ListFindLatestScrollPos(u8 *);
extern void IRC_RANKING_SeqSetFunc(u8 *,u32);
extern void IRC_RANKING_SeqScrollToLatest(u8 *a, u32 unused, u8 *p);
extern void IRC_RANKING_SeqBrowse(u8 *a, u32 unused, u8 *p);
void IRC_RANKING_SeqFadeIn(u8 *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: FADE_Start(3,16,0,0); *state = 1; break;
    case 1: if (!FADE_IsActive()) *state = 2; break;
    case 2:
        if (IRC_RANKING_ListFindLatestScrollPos(p+0x38) != 65535) IRC_RANKING_SeqSetFunc(p+0x28,(u32)IRC_RANKING_SeqScrollToLatest);
        else IRC_RANKING_SeqSetFunc(a,(u32)IRC_RANKING_SeqBrowse);
        break;
    }
}
