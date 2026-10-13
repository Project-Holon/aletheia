/*
 * file:     unit_021E9954.c
 * unit:     yes
 * function: func_021E9954, func_021E9964, func_021E9974, func_021E9984
 * address:  0x021E9954
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689B66C  0x0689B66C  thumb
 *   func_06899D3C 0x06899D3C thumb ov095
 *   func_06899D64   0x06899D64  thumb  ov095
 *   func_06899DB0   0x06899DB0  thumb  ov095
 *   func_021D3D70 0x021D3D70 thumb ov093
 *   BTL_MAIN_SyncSideParty 0x021B8F5C thumb ov093
 *   BTL_MAIN_IsCommMulti 0x021B8F38 thumb ov093
 *   BTL_MAIN_SyncPartnerSideParty 0x021B8F7C thumb ov093
 *   BTL_MAIN_IsSecondTeamClient 0x021B8FC0 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   BTL_MAIN_GetGameData 0x021B8748 thumb ov093
 *   BTL_MAIN_GetCompetitor 0x021B86B8 thumb ov093
 */
#include "../../matched/include/Obj00056.h"
#include "../../matched/include/Obj00714.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u32 f0; u8 pad[60]; } E64;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void func_06899D3C(u32);
extern u8 func_021D3D70(u8 *p);
extern int BTL_MAIN_SyncSideParty(char *p, int k);
extern int BTL_MAIN_IsCommMulti(unsigned char *p);
extern int BTL_MAIN_SyncPartnerSideParty(u8 *, u32);
extern unsigned char BTL_MAIN_IsSecondTeamClient(unsigned char *p, unsigned int k);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
extern int func_0689B66C(void *);
extern void *func_021F86D4(void);
extern int func_021F86E0(void);
extern u32 BTL_MAIN_GetGameData(void **p);
extern void *BTL_MAIN_GetCompetitor(void ***);
void func_021E9954(E64 *p);
void func_021E9964(E64 *p);
void func_021E9974(E64 *p);
void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y);

/*
 * Indexed-dispatch thunk, sibling of func_021E9964 (same shape, other tail target).
 * Tail call T(p[6].f0) with the index materialised as a scaled immediate.
 * Unlabelled leaf filed as the witness for the call in BTL_CLIENT_StepSelectAction.
 */
void func_021E9954(E64 *p) { func_06899D3C(p[0x6].f0); }


/*
 * Indexed-dispatch thunk (o18's 23-member shape): the member's whole stream is movs/lsls/ldr/ldr/bx with r0 as the load base; only the scratch register, the index constant and the tail target differ. Tail call T(p[i]) with the index materialised as a scaled immediate.
 */
void func_021E9964(E64 *p) { func_06899D64(p[0x6].f0); }


void func_021E9974(E64 *p) { func_06899DB0(p[0x6].f0); }


void func_021E9984(u8 *p, u8 *q, int mode, u8 x, int y)
{
    u32 k;
    int zero;
    int active;
    k = func_021D3D70(((struct Obj00056 *)p)->f4);
    ((struct Obj00714 *)q)->f4 = BTL_MAIN_SyncSideParty((char *)(*(u8 * *)&((struct Obj00056 *)p)->f0), k);
    if (mode != 3) active = BTL_MAIN_IsCommMulti(((struct Obj00056 *)p)->f0);
    else active = 0;
    ((struct Obj00714 *)q)->f18 = active;
    if (active) {
        ((struct Obj00714 *)q)->f8 = BTL_MAIN_SyncPartnerSideParty(*(u8 * *)&((struct Obj00056 *)p)->f0, k);
        q[0x1c] = BTL_MAIN_IsSecondTeamClient(((struct Obj00056 *)p)->f0, k);
    } else {
        ((struct Obj00714 *)q)->f8 = 0;
        q[0x1c] = 0;
    }
    q[0x1f] = mode;
    if (BTL_MAIN_GetRule(((struct Obj00056 *)p)->f0) != 3) q[0x22] = BTL_MAIN_GetPositionsPerClientThunk(((struct Obj00056 *)p)->f0, k);
    else q[0x22] = 3;
    switch (mode) {
    case 4:
    case 5: active = x; break;
    default: active = 0; break;
    }
    q[0x20] = active;
    q[0x21] = x;
    ((struct Obj00714 *)q)->f26 = y;
    q[0x4b] = 0;
    ((struct Obj00714 *)q)->f10 = ((struct Obj00056 *)p)->f184;
    ((struct Obj00714 *)q)->fC = ((struct Obj00056 *)p)->fB0;
    ((struct Obj00714 *)q)->f14 = BTL_MAIN_GetRule(((struct Obj00056 *)p)->f0);
    ((struct Obj00714 *)q)->f44 = func_0689B66C(((struct Obj00056 *)p)->f180);
    ((struct Obj00714 *)q)->f28 = func_021F86D4();
    ((struct Obj00714 *)q)->f2C = (void *)func_021F86E0();
    ((struct Obj00714 *)q)->f0 = (void *)BTL_MAIN_GetGameData(((struct Obj00056 *)p)->f0);
    ((struct Obj00714 *)q)->f30 = 0;
    zero = 0;
    if ((int)BTL_MAIN_GetCompetitor(*(void *** *)&((struct Obj00056 *)p)->f0) != 3) zero = 1;
    ((struct Obj00714 *)q)->f40 = zero;
    ((struct Obj00714 *)q)->f34 = 0;
    q[0x4c] = 0;
}
