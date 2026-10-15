/*
 * function: WIFI_2DCHAR_SpawnActor
 * address:  0x021C40BC
 * packet:   pkt_ov127_021C40BC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note (2026-10-05, wD5 lane07): EXACT. Keys: a real record array (stride 0x14 at +0x10) keeps idx*0x14 spilled
 *   and recomputes owner+row per use; the 6/1 argument as a call in each if/else arm keeps the 6 from merging with
 *   the pos[3] offset constant; const pos lets the pos[3] load schedule above the e[1] store; off = 0x2E0 local.
 *
 * symbols:
 *   WIFI_2DCHAR_FindFreeActor  0x021C4604  thumb ov127
 *   WIFI_2DCHAR_GetCellIndex  0x021C4354  thumb ov127
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   WIFI_2DCHAR_IsHandleValid  0x021C4550  thumb ov127
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { s16 x, y, z; u8 a, b; } Pos;
typedef struct { u32 f0, f4, f8, fC, f10; } Rec;
typedef struct {
    u32 h0;
    u8 pad4[0xC];
    Rec rec[18];        /* +0x010 */
    u8 pad178[0x10];
    Rec res[1];         /* +0x188, indexed by idx */
} Own;
struct Obj;
extern void *WIFI_2DCHAR_FindFreeActor(u8 *p);
extern int WIFI_2DCHAR_GetCellIndex(int);
extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void CLACT_SetActorBgPriority(u32, u32);
extern void CLACT_SetActorAnimIndex(int a0, int a1);
extern int WIFI_2DCHAR_IsHandleValid(int *p);
u32 *WIFI_2DCHAR_SpawnActor(Own *owner, const s16 *pos, int idx, u32 heap)
{
    u32 *e = WIFI_2DCHAR_FindFreeActor((u8 *)owner);
    Pos l;
    int off;
    int ta;
    idx = WIFI_2DCHAR_GetCellIndex(idx);
    l.x = pos[0];
    l.y = pos[1];
    ta = pos[2];
    l.z = 0;
    l.a = ta;
    l.b = pos[3];
    e[1] = (u32)CLACT_CreateActor((void *)owner->h0, owner->rec[idx].f4, owner->rec[idx].f8,
                         owner->res[idx].f0, &l, 0, (u16)heap);
    CLACT_SetActorBgPriority(e[1], (u8)pos[3]);
    if (owner->rec[idx].f10 == 1)
        CLACT_SetActorAnimIndex(e[1], 6);
    else
        CLACT_SetActorAnimIndex(e[1], 1);
    e[3] = 9;
    *(u16 *)(e + 5) = 0;
    e[4] = 1;
    e[0] = (u32)&owner->rec[idx];
    off = 0x2E0;
    if (WIFI_2DCHAR_IsHandleValid((int *)((u8 *)owner + off))) {
        l.x = pos[0];
        l.y = pos[1];
        l.z = 0;
        l.a = *(u32 *)((u8 *)owner + off + 0x10);
        l.b = 0;
        e[2] = (u32)CLACT_CreateActor((void *)owner->h0, *(u32 *)((u8 *)owner + off), *(u32 *)((u8 *)owner + off + 4),
                             *(u32 *)((u8 *)owner + off + 8), &l, 0, (u16)heap);
        CLACT_SetActorBgPriority(e[2], (u8)pos[3]);
    } else {
        e[2] = 0;
    }
    return e;
}
