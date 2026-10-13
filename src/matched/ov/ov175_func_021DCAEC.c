/*
 * function: func_021DCAEC
 * address:  0x021DCAEC
 * packet:   pkt_021DCAEC
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_CheckProfanityProcess  0x0217BC90  arm  ov009
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020084E4  0x020084E4  thumb
 *   STRBUF_Delete  0x02045808  arm
 *
 * Polls the profanity check; once it has finished (state 2) reports whether the +0x1488 count is positive, and when it is, loads message 0x51 for the +0x124 id and hands it to the +0x1490 window.
 */
#include "../include/Obj10693.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern int DWC_CheckProfanityProcess(void);
struct MsgBank;
struct Rec;
struct U16Vec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
struct U16Vec;
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern void STRBUF_Delete(struct U16Vec *vec);

int func_021DCAEC(char *obj, int *out)
{
    int state = DWC_CheckProfanityProcess();
    int done = 1;

    if (state != 2)
        done = 0;
    if (done)
        *out = ((struct Obj10693 *)obj)->f1488 > 0 ? 1 : 0;
    if (done == 1 && *out == 1) {
        u32 msg = (u32)func_02045B38(0, 2, 0x51, ((struct Obj10693 *)obj)->f124);
        u32 str = (u32)func_02045EC0((struct MsgBank *)msg, 0xf);
        MSGDATA_Delete((struct Rec *)msg);
        func_020084E4((u16 *)((struct Obj10693 *)obj)->f1490, (struct U16Vec *)str);
        STRBUF_Delete((struct U16Vec *)str);
    }
    return done;
}
