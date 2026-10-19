/*
 * function: BOX2_SEQ_SetBox2MainE
 * address: 0x021E7BD0
 * packet: pkt_ov170_021E7BD0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_RefreshMonInfo 0x021DEF98 thumb ov170
 *   BOX2_MAIN_RefreshCurrentBoxMonInfo 0x021DEFEC thumb ov170
 *   BOX2_SEQ_SetCursorFrame 0x021ED544 thumb ov170
 *   BOX2_SEQ_SetWindow9 0x021ED508 thumb ov170
 *   BOX2_SEQ_StatePmVoiceOpenB 0x021E9968 thumb ov170
 *   BOX2_SEQ_StatePmVoiceOpen 0x021E9938 thumb ov170
 *   BOX2_SEQ_StatePmVoiceOpenC 0x021E99B0 thumb ov170
 *   BOX2_SEQ_StatePmVoiceOpenD 0x021E9B74 thumb ov170
 *   BOX2_SEQ_StateWaitPrint 0x021E22B8 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23912.h"
extern int BOX2_MAIN_RefreshMonInfo(char *p, int a, unsigned b);
extern void BOX2_MAIN_RefreshCurrentBoxMonInfo(char *p, int b);
extern void BOX2_SEQ_SetCursorFrame(char *p, int b);
extern void BOX2_SEQ_SetWindow9(unsigned char *p, int a, int b);
extern int BOX2_SEQ_StatePmVoiceOpenB(unsigned char *p);
extern int BOX2_SEQ_StatePmVoiceOpen(unsigned char *p);
extern int BOX2_SEQ_StatePmVoiceOpenC(unsigned char *p);
extern int BOX2_SEQ_StatePmVoiceOpenD(unsigned char *p);
extern int BOX2_SEQ_StateWaitPrint(int p);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags;
int BOX2_SEQ_SetBox2MainE(unsigned char *p)
{
    if (p[0x17] != 0xFF)
        BOX2_MAIN_RefreshMonInfo((char *)p, p[0x17], p[0x16]);
    else
        BOX2_MAIN_RefreshCurrentBoxMonInfo((char *)p, p[0x16]);
    BOX2_SEQ_SetCursorFrame((char *)p, 6);
    if (((Flags *)p)->lo == 0)
        BOX2_SEQ_SetWindow9(p, 0xE, 1);
    else
        BOX2_SEQ_SetWindow9(p, 0xD, 1);
    switch (((struct Obj23912 *)(*(char * *)&((struct Obj00000 *)p)->f0))->f24) {
    case 0:
        *(int *)(WORK(p) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenB(p);
        break;
    case 1:
        *(int *)(WORK(p) + 0xA198) = BOX2_SEQ_StatePmVoiceOpen(p);
        break;
    case 2:
        *(int *)(WORK(p) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenC(p);
        break;
    case 4:
        *(int *)(WORK(p) + 0xA198) = BOX2_SEQ_StatePmVoiceOpenD(p);
        break;
    case 3:
        break;
    }
    return BOX2_SEQ_StateWaitPrint((int)p);
}
