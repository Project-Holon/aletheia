/*
 * function: FLDMMDL_BLACT_AddActorPos
 * address:  0x0219C6B8
 * packet:   pkt_ov021_0219C6B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Former blocker (now filed in src/matched/arm9): BILLBOARD_ACT_SetEntryList (0x0205082C) and BILLBOARD_ACT_SetEntryEnabled (0x020507F0) are
 * unlabelled arm9 leaves (the integrator's), no witness outside this range. Verified C,
 * both EXACT under --arm --region arm9 (BILLBOARD_ACT_ResetPlayback is the arm9 label at 0x020500A0):
 *     void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u32 *)(e + 24) = v; }
 *     void BILLBOARD_ACT_SetEntryList(void *p, int idx, u16 h)
 *     { char *e = (char *)(*(u32 *)((char *)p + 24) + idx * 40); *(u16 *)(e + 14) = h; BILLBOARD_ACT_ResetPlayback(e); }
 * FLDMMDL_BLACT_EntryHook (function pointer word) is filed as pkt_ov021_0219C9D0.
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   BILLBOARD_ACT_CreateEntries  0x02050340  arm
 *   FLDMMDL_BLACT_GetAnimeTable  0x0219D3E4  thumb  ov021
 *   BILLBOARD_ACT_SetEntryCommands  0x02050804  arm
 *   BILLBOARD_ACT_SetEntryList  0x0205082C  arm
 *   BILLBOARD_ACT_SetEntryEnabled  0x020507F0  arm
 *   FLDMMDL_BLACT_EntryHook  0x0219C9D0  thumb  ov021
 *   sBlactDrawSize     0x021D75D0  data  a4
 */
#include "../include/Obj07474.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

extern u16 sBlactDrawSize[][2];
extern u32 FLDMMDL_SysGetBlActCont(void *p);
struct BbActDesc;
struct BbActSys;
extern u16 BILLBOARD_ACT_CreateEntries(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern char *FLDMMDL_BLACT_GetAnimeTable(int i);
extern void BILLBOARD_ACT_SetEntryCommands(void *p, int idx, u32 v, u16 h);
extern void BILLBOARD_ACT_SetEntryList(void *p, int idx, u32 h);
extern void BILLBOARD_ACT_SetEntryEnabled(void *p, int idx, u32 v);
extern void FLDMMDL_BLACT_EntryHook(u32 a, u32 b, u8 *p);

u32 FLDMMDL_BLACT_AddActorPos(u32 a, V3 *b, int c, u32 d, u16 e)
{
    u8 *m = (u8 *)FLDMMDL_SysGetBlActCont((void *)a);
    Desc s;
    u32 r;
    u32 *q;
    u16 *t = sBlactDrawSize[c];
    u32 h;
    s.slot = e;
    s.v12 = sBlactDrawSize[c][0];
    s.v14 = t[1];
    s.pos = *b;
    s.k = 0x1f;
    s.flag = 1;
    s.w = 1;
    s.f1c = (void (*)(void))FLDMMDL_BLACT_EntryHook;
    s.f20 = (u32)m;
    r = BILLBOARD_ACT_CreateEntries((struct BbActSys *)(((struct Obj07474 *)m)->f4), ((struct Obj07474 *)m)->f8, (const struct BbActDesc *)(&s), 1, 0);
    q = (u32 *)FLDMMDL_BLACT_GetAnimeTable(d);
    if (q[0] != 0) {
        BILLBOARD_ACT_SetEntryCommands((void *)(((struct Obj07474 *)m)->f4), r, q[0], (u16)q[1]);
        h = ((struct Obj07474 *)m)->f4;
        BILLBOARD_ACT_SetEntryList((void *)h, r, 0);
        BILLBOARD_ACT_SetEntryEnabled((void *)h, r, 1);
    }
    return r;
}
