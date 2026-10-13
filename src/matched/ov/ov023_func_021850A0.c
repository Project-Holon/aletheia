/*
 * function: OEKAKI_HandleTouch
 * address: 0x021850A0
 * packet: pkt_ov023_021850A0
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: the activation tail is an inline returning its flag value;
 * assigning the returned u8 to k recolours the merged flag store to r1.
 * The pointer-out helper and inline assignment stayed DIFF by two bytes.
 * symbols:
 *   gOekakiButtonHitTable     0x02186AFC  data  ov023  a4
 *   gOekakiCanvasHitTable     0x02186AB4  data  ov023  a4
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   OEKAKI_SelectColorButton  0x021852B4  thumb  ov023
 *   OEKAKI_GetJoinedBits  0x02186558  thumb  ov023
 *   OEKAKI_PrintMessage  0x021861C4  thumb  ov023
 *   OEKAKI_SetNextScene  0x02186444  thumb  ov023
 *   OEKAKI_SetQuitButtonPressed  0x021852F4  thumb  ov023
 *   OEKAKI_SetCursorPosition  0x0218506C  thumb  ov023
 *   OEKAKI_MakeStroke  0x021864C4  thumb  ov023
 *   OEKAKI_MakeEmptyStroke  0x02185080  thumb  ov023
 *   OEKAKI_StoreStroke  0x02186988  thumb  ov023
 *   OEKAKI_AdvanceQueueTail  0x021868C8  thumb  ov023
 *   OEKAKI_AdvanceQueueTailIfUsed  0x02186888  thumb  ov023
 */
#include "../include/Obj00525.h"
#include "../include/Obj01221.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 n;
    u16 a;
    u16 b;
    u16 pad;
} Ent;

typedef struct {
    Ent e[8];
    u16 tail;
} Path;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Rec;

extern char gOekakiButtonHitTable[];
extern char gOekakiCanvasHitTable[];

extern int  TOUCHPANEL_HitTrg(const void *p);
extern int  TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int  TOUCHPANEL_GetCont(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void OEKAKI_SelectColorButton(u32 *p, int n);
extern int  OEKAKI_GetJoinedBits(char *p);
extern void OEKAKI_PrintMessage(u8 *w, u32 msg, int mode);
extern void OEKAKI_SetNextScene(char *p, u32 v);
extern void OEKAKI_SetQuitButtonPressed(void *p, int flag);
extern void OEKAKI_SetCursorPosition(void *actor, int x, int y);
extern void OEKAKI_MakeStroke(Rec *d, Ent *s, int a, int c);
extern void OEKAKI_MakeEmptyStroke(Rec *d, int a, int c);
extern void OEKAKI_StoreStroke(Rec *d, char *q, int z);
extern void OEKAKI_AdvanceQueueTail(char *p);
extern void OEKAKI_AdvanceQueueTailIfUsed(char *p);

static inline u8 activate(char *p, int value)
{
    OEKAKI_PrintMessage((u8 *)p, value, value);
    OEKAKI_SetNextScene(p, 5);
    OEKAKI_SetQuitButtonPressed((void *)(((struct Obj00525 *)p)->f100), 1);
    GFL_USE_PlaySeDefaultVolume(0x551);
    return value;
}

void OEKAKI_HandleTouch(char *p)
{
    Path path;
    int tx;
    int ty;
    Rec rec;
    int x;
    int y;
    u8 k;
    int r;
    int i;

    k = 0;
    r = TOUCHPANEL_HitTrg(gOekakiButtonHitTable);
    if (r != -1) {
        switch (r) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (((struct Obj01221 *)p)->f420A != r) {
                ((struct Obj01221 *)p)->f420A = r;
                OEKAKI_SelectColorButton((u32 *)(p + 0xd0), r);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
            break;
        case 8:
            if (((struct Obj01221 *)p)->f198 != 4)
                break;
            if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
                if (((struct Obj01221 *)p)->f1B0 != OEKAKI_GetJoinedBits(p)) {
                    GFL_USE_PlaySeDefaultVolume(0x54b);
                } else {
                    ((struct Obj01221 *)p)->f9E6C = 2;
                    k = activate(p, 1);
                }
            } else {
                if (((struct Obj01221 *)p)->f4217 == 2) {
                    GFL_USE_PlaySeDefaultVolume(0x54b);
                } else {
                    k = activate(p, 1);
                }
            }
            break;
        case 9:
        case 10:
        case 11:
            for (i = 0; i < 3; i++) {
                if (r - 9 == i)
                    CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + 0xf4 + i * 4)), i * 2 + 0x1e);
                else
                    CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(p + 0xf4 + i * 4)), i * 2 + 0x1d);
            }
            if (((struct Obj01221 *)p)->f420B != r - 9) {
                ((struct Obj01221 *)p)->f420B = r - 9;
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
            break;
        }
    }
    r = TOUCHPANEL_HitCont(gOekakiCanvasHitTable);
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + 0x60 + GFL_NET_SYSTEM_GetCurrentAid() * 4), 0);
    if (r != -1) {
        TOUCHPANEL_GetPointCont((u32 *)(&tx), (u32 *)(&ty));
        OEKAKI_SetCursorPosition((void *)(*(int *)(p + 0x60 + GFL_NET_SYSTEM_GetCurrentAid() * 4)), tx, ty);
        CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(p + 0x60 + GFL_NET_SYSTEM_GetCurrentAid() * 4), 1);
    }
    x = 0;
    y = 0;
    if (TOUCHPANEL_GetCont() == 1) {
        TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y));
        path.e[0].n = 2;
        path.e[0].a = ((Path *)(p + 0x4244))->e[1].a;
        path.e[0].b = ((Path *)(p + 0x4244))->e[1].b;
        path.e[1].a = x;
        path.e[1].b = y;
        OEKAKI_MakeStroke(&rec, path.e, ((struct Obj01221 *)p)->f420A, ((struct Obj01221 *)p)->f420B);
        if (k == 1)
            rec.mid = 0;
    } else {
        path.e[1].a = 0;
        path.e[1].b = 0;
        OEKAKI_MakeEmptyStroke(&rec, ((struct Obj01221 *)p)->f420A, ((struct Obj01221 *)p)->f420B);
    }
    OEKAKI_StoreStroke(&rec, p + 0x928c, 0);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0)
        OEKAKI_AdvanceQueueTail(p + 0x928c);
    else
        OEKAKI_AdvanceQueueTailIfUsed(p + 0x928c);
    *(Path *)(p + 0x4244) = path;
}
