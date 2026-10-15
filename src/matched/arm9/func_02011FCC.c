/*
 * function: GAMESYSTEM_Main
 * address:  0x02011FCC
 * packet:   pkt_02011FB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct, MATCH-capped: all 144 concrete bytes reproduce, the four
 * remaining wildcards are call sites whose targets live in OTHER PACKETS and
 * have no witness outside this range:
 *
 *   +0034  bl GAME_EVENT_Control   -> pkt_02012380
 *   +003A  bl GAME_COMM_Update   -> pkt_0202627C
 *   +0052  bl ISS_SYS_Update   -> pkt_0202B500
 *   +0058  bl PALANM_UpdateTimer   -> pkt_02021464
 *
 * Each reports `no witness outside 02011FCC..02012060`, i.e. the only branch
 * anywhere in the image reaching them is the call in this function, so the
 * `label` class cannot attest them and no cut frees them.  Blocking class:
 * label.  Nothing in this C changes when those packets are filed -- the file
 * graduates for free.
 *
 * Two spellings this function pinned down:
 *
 *  - The last guard is ONE conjunction, `a == 0 && b == 0 -> return 1`.  The
 *    equivalent disjunction (`a != 0 || b != 0 -> return 0`) makes mwcc pick
 *    the other arm as the fall-through and comes out four bytes of wrong
 *    layout: `bne #0x2012054` + `beq` + the two `movs r0` swapped, where the
 *    original branches BOTH tests to a shared out-of-line `movs r0,#0; pop`
 *    and falls through to `movs r0,#1`.
 *  - The state word at +0x0c is re-read from memory at each use rather than
 *    cached in a register, so it is spelled as the field every time.
 *
 * symbols:
 *   GAMESYSTEM_UpdateEventActiveFlag  0x020120A4  thumb
 *   GAME_DATA_IsWalkCountEnabled  0x02012A24  thumb
 *   func_02035614  0x02035614  arm
 *   GAME_DATA_IncWalkCount  0x020129FC  thumb
 *   GAME_EVENT_StartByCreator  0x020123D8  thumb
 *   GAMESYSTEM_UpdateAutoComm  0x0201205C  thumb
 *   GAME_EVENT_Control  0x02012380  thumb
 *   GAME_COMM_Update  0x0202627C  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_Update  0x02028A14  thumb
 *   ISS_SYS_Update  0x0202B500  thumb
 *   PALANM_UpdateTimer  0x02021464  thumb
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 */
#include "../include/Obj01458.h"

extern void GAMESYSTEM_UpdateEventActiveFlag(char *p);
struct BigObj;
extern unsigned char GAME_DATA_IsWalkCountEnabled(const struct BigObj *p);
extern void func_02035614(int v);
extern unsigned char GAME_DATA_IncWalkCount(struct BigObj *h);
typedef unsigned int   u32;
extern int GAME_EVENT_StartByCreator(void *o, u32 (*fn)(void *, void *), void *a2);
struct IcaAnime;
extern void GAMESYSTEM_UpdateAutoComm(struct IcaAnime *p);
struct T;
extern int GAME_EVENT_Control(void *p);
struct Comm;
extern void GAME_COMM_Update(struct Comm *p);
extern unsigned int PROCSYS_Main(void *p);
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
extern void FIELD_SOUND_SYSTEM_Update(struct T *p);
extern void ISS_SYS_Update(unsigned char *p);
extern void PALANM_UpdateTimer(unsigned char *p);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);

int GAMESYSTEM_Main(char *p)
{
    GAMESYSTEM_UpdateEventActiveFlag(p);
    if (GAME_DATA_IsWalkCountEnabled((const struct BigObj *)((struct Obj01458 *)p)->f1C) != 0)
        func_02035614(0x1e);
    if (GAME_DATA_IncWalkCount((struct BigObj *)((struct Obj01458 *)p)->f1C) == 0) {
        GAME_EVENT_StartByCreator(p, (unsigned int (*)(void *, void *))((struct Obj01458 *)p)->f10, (void *)((struct Obj01458 *)p)->f14);
        GAMESYSTEM_UpdateAutoComm((struct IcaAnime *)p);
        GAME_EVENT_Control(p);
        GAME_COMM_Update((struct Comm *)((struct Obj01458 *)p)->f24);
    }
    ((struct Obj01458 *)p)->fC = PROCSYS_Main((void *)((struct Obj01458 *)p)->f8);
    FIELD_SOUND_SYSTEM_Update((struct T *)GAME_DATA_GetBgmInfo((const struct BigObj *)((struct Obj01458 *)p)->f1C));
    ISS_SYS_Update((unsigned char *)((struct Obj01458 *)p)->f2C);
    PALANM_UpdateTimer((unsigned char *)((struct Obj01458 *)p)->f1C);
    if (GAME_DATA_IsWalkCountEnabled((const struct BigObj *)((struct Obj01458 *)p)->f1C) != 0)
        func_02035614(0x3c);
    if (((struct Obj01458 *)p)->fC == 2 || ((struct Obj01458 *)p)->fC == 0)
        GFL_NET_ERR_ShowScreen(0);
    if (((struct Obj01458 *)p)->fC == 0 && ((struct Obj01458 *)p)->f18 == 0)
        return 1;
    return 0;
}
