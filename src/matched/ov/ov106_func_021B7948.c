/*
 * function: IRC_RANKING_SeqFadeOut
 * address: 0x021B7948
 * packet: pkt_ov106_021B7948
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte alignment padding, no follower.
 * symbols:
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   IRC_RANKING_SeqFinish 0x021B78D8 thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void IRC_RANKING_SeqFinish(u8 *);
void IRC_RANKING_SeqFadeOut(u8 *a,int *s) { switch (*s) { case 0: FADE_Start(3,0,16,0); *s=1; break; case 1: if (!FADE_IsActive()) *s=2; break; case 2: IRC_RANKING_SeqFinish(a); break; } }
