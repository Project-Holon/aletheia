/*
 * function: SCRCMD_WORK_AddMenuItem
 * address:  0x0215A7F0
 * packet:   pkt_ov010_0215A7F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_CountItems  0x0201F91C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Clone  0x02045874  arm
 *   FIELD_MSGBG_AddMenuItemStr  0x02190A64  thumb  ov021
 */
#include "../include/Obj00005.h"

typedef struct {
    unsigned short a;
    unsigned short pad[5];
    int g;
    int h;
    int i;
    int j;
    int pad1c;
    int k[32];
} Q;

struct MsgBank;
struct Slot;
struct U16Vec;
extern unsigned int BMP_MENUWORK_CountItems(struct Slot *s);
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, unsigned int heapId);
typedef unsigned int   u32;
extern int FIELD_MSGBG_AddMenuItemStr(u32 a, u32 b, u32 c, u32 d);

void SCRCMD_WORK_AddMenuItem(unsigned short *p, int a, int b, int c, struct U16Vec *s0, void *s1)
{
    Q *q = (Q *)(*(char * *)&((struct Obj00005 *)p)->f20 + 0x34);

    if (b != 0xffff) {
        unsigned i = BMP_MENUWORK_CountItems((struct Slot *)q->j);
        if (i >= 0x20) {
            return;
        }
        MSGDATA_ReadString((struct MsgBank *)q->i, b, s1);
        func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
        q->k[i] = (int)STRBUF_Clone(s0, *p);
    }
    MSGDATA_ReadString((struct MsgBank *)q->i, a, s1);
    func_0201F250((struct WordSet *)q->g, (void *)s0, (void *)s1);
    FIELD_MSGBG_AddMenuItemStr(q->j, (u32)s0, c, *p);
}
