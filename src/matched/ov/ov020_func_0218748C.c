/*
 * function: FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice
 * address:  0x0218748C
 * packet:   pkt_ov020_0218748C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   d_02187E04     0x02187E04  data  ov020  a2
 */
#include "../include/Obj00128.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
struct Ent;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern struct Ent *FIELD_MSGBG_AddTalkWin(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern u16 d_02187E04[];

void FIELD_WFBC_DATA_LOCAL_StartTalkMessageWithChoice(char *p, int a1, int *out, int a3, u16 a4)
{
    int i;

    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00128 *)p)->f18),
                  (u16)(a1 + (d_02187E04[(*(u16 **)(p + 0x48))[1]] + ((struct Obj00128 *)p)->f4C * 8)),
                  (void *)(((struct Obj00128 *)p)->f24));
    WORDSET_CopyTaggedText((struct WordSet *)(((struct Obj00128 *)p)->f1C), (void *)(((struct Obj00128 *)p)->f20), (void *)(((struct Obj00128 *)p)->f24));
    i = 0;
    *(int *)&((struct Obj00128 *)p)->f10 = (int)FIELD_MSGBG_AddTalkWin((u8 *)(((struct Obj00128 *)p)->fC), 2, (u32)(p + 0x34), ((struct Obj00128 *)p)->f20, i, i);
    *out = 0x10;
    ((struct Obj00128 *)p)->f4E = a3;
    ((struct Obj00128 *)p)->f50 = a4;
    ((struct Obj00128 *)p)->f52 = 0;
    ((struct Obj00128 *)p)->f54 = 1;
    ((struct Obj00128 *)p)->f55 = 1;
}
