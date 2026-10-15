/*
 * function: BOX2_SEQ_StateClosePmVoice
 * address: 0x021E8508
 * packet: pkt_ov170_021E8508
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_PollRepeatInput 0x02025DE8 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_SEQ_ReturnAfterClear 0x021E8F50 thumb ov170
 *   BOX2_SEQ_GotoBox2Main 0x021E949C thumb ov170
 *   BOX2_SEQ_SetState 0x021E8FE0 thumb ov170
 *   BOX2_SEQ_SetSeqSecond 0x021E8FD0 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23929.h"
#include "../include/Obj23930.h"
typedef unsigned char u8;
struct Sound;
extern int CURSOR_MOVE_PollRepeatInput(struct Sound *obj);
extern void GFL_USE_PlaySeDefaultVolume(unsigned);
extern int BOX2_SEQ_ReturnAfterClear(char *p, int v);
extern int BOX2_SEQ_GotoBox2Main(char *p, int a, int b);
extern int BOX2_SEQ_SetState(char *p, int v);
extern int BOX2_SEQ_SetSeqSecond(char *p, int a);
int BOX2_SEQ_StateClosePmVoice(u8 *p)
{
    unsigned v = CURSOR_MOVE_PollRepeatInput(((struct Obj23929 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
    switch (v) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GotoBox2Main((char *)p, 2, BOX2_SEQ_ReturnAfterClear((char *)p, 0x60));
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        ((struct Obj23930 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA17C = 0;
        return BOX2_SEQ_GotoBox2Main((char *)p, 3, BOX2_SEQ_ReturnAfterClear((char *)p, 0x64));
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return BOX2_SEQ_GotoBox2Main((char *)p, 4, 0x67);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, BOX2_SEQ_ReturnAfterClear((char *)p, 0x5f));
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return BOX2_SEQ_GotoBox2Main((char *)p, 5, BOX2_SEQ_ReturnAfterClear((char *)p, 0x5f));
    case -3:
        GFL_USE_PlaySeDefaultVolume(0x548);
        return BOX2_SEQ_SetSeqSecond((char *)p, BOX2_SEQ_SetState((char *)p, 0x5e));
    }
    return 0x5e;
}
