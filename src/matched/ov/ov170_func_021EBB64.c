/*
 * function: BOX2_SEQ_PrintWordsetBB64
 * address: 0x021EBB64
 * packet: pkt_ov170_021EBB64
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_Callback_EF40 0x0201EF40 thumb
 *   FILE_UTIL_Check136C 0x0202136C thumb
 *   BOX2_SEQ_PrintMessageMsg 0x021EBA84 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23990.h"
#include "../include/Obj23991.h"
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_Callback_EF40(struct WordSet *p, u32 i, u32 v);
extern unsigned FILE_UTIL_Check136C(unsigned short);
extern void BOX2_SEQ_PrintMessageMsg(unsigned char *, int, int);
void BOX2_SEQ_PrintWordsetBB64(unsigned char *p, unsigned v, int i)
{
    if (v == 0) {
        WORDSET_Callback_EF40(((struct Obj23990 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, 0x70);
        BOX2_SEQ_PrintMessageMsg(p, 0x2c, i);
    } else if (FILE_UTIL_Check136C(v) == 1) {
        BOX2_SEQ_PrintMessageMsg(p, 0x30, i);
    } else {
        WORDSET_Callback_EF40(((struct Obj23991 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f84, 0, v);
        BOX2_SEQ_PrintMessageMsg(p, 15, i);
    }
}
