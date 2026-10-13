/*
 * function: IRC_RANKING_ProcMain
 * address: 0x021B7848
 * packet: pkt_ov106_021B7848
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RANKING_SeqRun 0x021B78B8 thumb ov106
 *   IRC_RANKING_Draw 0x021B80A0 thumb ov106
 *   IRC_RANKING_LabelUpdate 0x021B93E4 thumb ov106
 *   IRC_RANKING_SeqIsDone 0x021B78CC thumb ov106
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 */
#include "../include/Obj22255.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void IRC_RANKING_SeqRun(u8 *);
extern void IRC_RANKING_Draw(u8 *);
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern int IRC_RANKING_LabelUpdate(u8 *p);
extern u32 IRC_RANKING_SeqIsDone(u8 *);
int IRC_RANKING_ProcMain(int a, int b, int c, u8 *p)
{
    int i;
    IRC_RANKING_SeqRun(p + 0x28);
    IRC_RANKING_Draw(p);
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj22255 *)p)->f61C));
    for (i = 0; i < 4; i++) IRC_RANKING_LabelUpdate((u8 *)(*(u32 *)(p + 0x62C + i * 4)));
    if (IRC_RANKING_SeqIsDone(p + 0x28)) return 1;
    return 0;
}
