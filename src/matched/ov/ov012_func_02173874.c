/*
 * function: UNION_MAIN_FieldCreateCallback
 * address:  0x02173874
 * packet:   pkt_ov012_02173874
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * FIELDMAP_CTRL_GRID_SetBusy(q, v) takes a second argument (it stores r1 at +0xc); its 1
 * is CSE'd with the stored 1, which is what puts that constant in r1 and
 * fixes the prologue schedule. Bitfield at +0xc8 needs lsls/lsrs #0x1f.
 *
 * symbols:
 *   FIELDMAP_CTRL_GRID_SetBusy  0x021A2E44  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   func_02013CC8  0x02013CC8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   UNION_CHARA_RefreshParentMarks  0x0217B440  thumb  ov019
 *   COMM_PLAYER_Resume  0x021676E4  thumb  ov010
 */
#include "../include/Obj07338.h"
#include "../include/Obj19237.h"
#include "../include/Obj19238.h"

typedef unsigned char u8;

typedef struct { u8 pad[0xc8]; u8 f : 1; } S;

extern void FIELDMAP_CTRL_GRID_SetBusy(int a, unsigned int v);
typedef unsigned short u16;
typedef unsigned int   u32;
struct Work;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern u32 func_02013CC8(u32 id);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void UNION_CHARA_RefreshParentMarks(char *base, int x, void *y);
extern void COMM_PLAYER_Resume(struct Work *w);

void UNION_MAIN_FieldCreateCallback(int a, u8 *p, void *q)
{
    S *r4;

    r4 = *(S * *)&((struct Obj07338 *)p)->f355C;
    p[0x282A] = 1;
    if (p[0x3563] == 1) {
        FIELDMAP_CTRL_GRID_SetBusy((int)q, 1);
    }
    if (func_02013CC8(FIELDMAP_GetZoneId(q)) == 1) {
        UNION_CHARA_RefreshParentMarks((char *)p, (int)GAMESYSTEM_GetGameData((const struct Ctx *)(((struct Obj19238 *)(*(u8 * *)&((struct Obj07338 *)p)->f0))->fC)), q);
    }
    if (r4 != 0 && r4->f == 1) {
        COMM_PLAYER_Resume(((struct Obj19237 *)r4)->f0);
    }
}
