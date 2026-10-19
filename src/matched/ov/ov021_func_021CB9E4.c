/*
 * function: BSUBWAY_SCR_CreateMarkerObjects
 * address:  0x021CB9E4
 * packet:   pkt_ov021_021CB9E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Spawns the marker objects for mode byte +9: in mode 4 up to five from the
 * 0x3B record list (newest first), otherwise every 0x021DAEBC entry whose
 * threshold equals the step count. The u16 accessor result held in a u32
 * local is what puts it in the top spill slot (a u16 or int local takes the
 * lowest). Unlabelled follower: 0x021CBBA0 (already filed).
 *
 * symbols:
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_020071CC  0x020071CC  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   BSUBWAY_SAVEDATA_CountHistoryEntries  0x0200DF94  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryEntryScore  0x0200DFB4  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   FLDMMDL_AddMmdlParam  0x0216CE6C  thumb  ov010
 *   FLDMMDL_SetParam  0x0216D620  thumb  ov010
 *   FLDMMDL_SetEventId  0x0216D5B4  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   BSUBWAY_SCOREDATA_GetRepeatClearCount  0x0200DB80  thumb
 *   d_021DADD0     0x021DADD0  data  a2
 *   d_021DAD48     0x021DAD48  data  a2
 *   d_021DAD5C     0x021DAD5C  data  a2
 *   d_021DAEBC     0x021DAEBC  data  a2
 *   d_021DADF8     0x021DADF8  data  a4
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12974.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct {
    s16 x;
    s16 pad0;
    s16 y;
    s16 pad1;
} Pt;

typedef struct {
    u16 id;
    u16 idx;
    s16 x;
    u16 pad6;
    s16 y;
    u16 k;
    u32 padc;
} Ent;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Flags;

struct Big;
struct Blk1AC;
struct Sub020071CCCtrl;
extern u16 FIELDMAP_GetZoneId(u8 *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
struct Buf3FC;
struct RecSlot;
struct SubEnt;
extern struct Buf3FC *BSUBWAY_SAVEDATA_AllocHistoryCopy(struct RecSlot *p, u32 heap);
extern u32 BSUBWAY_SAVEDATA_CountHistoryEntries(struct Buf3FC *b);
extern u32 BSUBWAY_SAVEDATA_GetHistoryEntryScore(struct SubEnt *e);
extern void *FLDMMDL_AddMmdlParam(void *o, int x, int y, u16 d, u32 a, u32 b, u32 c, u32 e);
extern int FLDMMDL_SetParam(int a0, int a1, int a2);
extern void FLDMMDL_SetEventId(void *h, u16 v);
extern u32 func_020307B0(void *p);
extern u16 BSUBWAY_SCOREDATA_GetRepeatClearCount(struct Blk1AC *p, u32 i);

extern const Pt d_021DADD0[];
extern const u16 d_021DAD48[];
extern const u16 d_021DAD5C[];
extern const Ent d_021DAEBC[];
extern const u32 d_021DADF8[];

void BSUBWAY_SCR_CreateMarkerObjects(u8 *p, void *a1, void *a2, void *a3)
{
    int i;
    u16 slot;
    u32 zone;
    u8 kind;
    const Pt *pt;
    u8 *list;
    u32 n;
    u8 *e;
    u16 v;
    void *h;
    u16 cnt;
    const Ent *ent;

    i = 0;
    zone = FIELDMAP_GetZoneId(a3);
    slot = 0x80;
    kind = p[9];
    if (kind == 4) {
        pt = d_021DADD0;
        list = (u8 *)BSUBWAY_SAVEDATA_AllocHistoryCopy(func_020071CC(GAME_DATA_GetSaveControl(a1), 0x3B), (int)4);
        n = BSUBWAY_SAVEDATA_CountHistoryEntries((struct Buf3FC *)list);
        if (n != 0) {
            e = list + (n - 1) * 0x22;
            while (n != 0 && i < 5) {
                u32 r = BSUBWAY_SAVEDATA_GetHistoryEntryScore((struct SubEnt *)e) % 10;
                if (((Flags *)(e + 0x20))->b1 == 0)
                    v = d_021DAD48[r];
                else
                    v = d_021DAD5C[r];
                h = FLDMMDL_AddMmdlParam(a2, pt->x, pt->y, i % 4, slot, v, 2, zone);
                FLDMMDL_SetParam((int)h, (u16)(n - 1), 0);
                FLDMMDL_SetEventId(h, 5);
                e -= 0x22;
                i++;
                slot++;
                pt++;
                n--;
            }
        }
        func_020307B0(list);
        return;
    }
    ent = d_021DAEBC;
    cnt = BSUBWAY_SCOREDATA_GetRepeatClearCount(((struct Obj12974 *)p)->f74, kind);
    switch (kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    case 5:
    case 6:
    case 7:
    case 8:
        cnt += 3;
        break;
    }
    while (ent->id != 0xFFFF) {
        if (cnt == d_021DADF8[ent->idx - 1]) {
            h = FLDMMDL_AddMmdlParam(a2, ent->x, ent->y, i % 4, slot, ent->id, 2, zone);
            FLDMMDL_SetParam((int)h, (u16)i, 0);
            FLDMMDL_SetParam((int)h, (u16)ent->k, 1);
            FLDMMDL_SetEventId(h, 5);
            if (slot < 0xFF)
                slot++;
        }
        ent++;
        i++;
    }
}
