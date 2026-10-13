/*
 * function: OEKAKI_UpdateMembers
 * address:  0x02186324
 * packet:   pkt_ov023_02186324
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   OEKAKI_GetMemberCount  0x02186164  thumb  ov023
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_CloseMenuIfOpen  0x02186480  thumb  ov023
 *   OEKAKI_NotifyHostSync  0x02186304  thumb  ov023
 *   OEKAKI_GetJoinedCount  0x0218654C  thumb  ov023
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
#include "../include/Obj00460.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int OEKAKI_GetMemberCount(char *p);
extern int OEKAKI_GetJoinedBits(char *p);
extern void OEKAKI_CloseMenuIfOpen(char *p);
extern void OEKAKI_NotifyHostSync(char *p, int a);
extern int OEKAKI_GetJoinedCount(char *p);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

int OEKAKI_UpdateMembers(u8 *p)
{
    int st;
    int r;

    st = OEKAKI_GetMemberCount((char *)p);
    switch (st) {
    case 0:
        break;
    case 1:
        if (((struct Obj00460 *)p)->f198 > 0x10) {
            break;
        }
        if (OEKAKI_GetJoinedBits((char *)p) != 1) {
            ((struct Obj00460 *)p)->f9E78 = 1;
        }
        ((struct Obj00460 *)p)->f19C = 0x16;
        if (((struct Obj00460 *)p)->f9E70 != 0) {
            OEKAKI_CloseMenuIfOpen((char *)p);
            CLACT_SetActorAnimSeq(((struct Obj00460 *)p)->fF0, 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (st < ((struct Obj00460 *)p)->f1A8) {
            if (((struct Obj00460 *)p)->f9E6C == 2) {
                OEKAKI_NotifyHostSync((char *)p, 0);
            } else if (((struct Obj00460 *)p)->f9E7C == 0) {
                OEKAKI_NotifyHostSync((char *)p, 1);
            } else {
                OEKAKI_NotifyHostSync((char *)p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (st < ((struct Obj00460 *)p)->f1A8) {
        ((struct Obj00460 *)p)->f1AC = OEKAKI_GetJoinedCount((char *)p);
        r = OEKAKI_GetJoinedBits((char *)p);
        ((struct Obj00460 *)p)->f1B0 = r;
        if (((struct Obj00460 *)p)->f9E7C != 0 && (r & ((struct Obj00460 *)p)->f9E80) == 0) {
            OEKAKI_NotifyHostSync((char *)p, 1);
            ((struct Obj00460 *)p)->f9E6C = 1;
            ((struct Obj00460 *)p)->f9E7C = 0;
            ((struct Obj00460 *)p)->f9E80 = 0;
        }
    }
    ((struct Obj00460 *)p)->f1A8 = OEKAKI_GetMemberCount((char *)p);
    if (((struct Obj00460 *)p)->f1AC < OEKAKI_GetJoinedCount((char *)p)) {
        ((struct Obj00460 *)p)->f9E6C = 2;
        ((struct Obj00460 *)p)->f9E7C = 1;
        ((struct Obj00460 *)p)->f9E80 = OEKAKI_GetJoinedBits((char *)p) ^ ((struct Obj00460 *)p)->f1B0;
    }
    return 1;
}
