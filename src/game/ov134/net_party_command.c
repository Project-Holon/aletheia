/*
 * file:     net_party_command.c
 * unit:     yes
 * function: func_021DC860, func_021DC86C, func_021DC888, func_021DC914, func_021DC93C, func_021DCB48, func_021DCC48
 * address:  0x021DC860
 * region:   ov134
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Create 0x02031324 arm
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   tbl_021DCC9C 0x021DCC9C data a4
 *   g_02FFFC3C 0x02FFFC3C data a4
 *   ov90_id 0x0000005A data a1
 *   PLIST_COMM_End 0x021B6108 thumb ov090
 *   func_02034A5C 0x02034A5C arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   PLIST_COMM_Update 0x021B6114 thumb ov090
 *   func_02034AC4 0x02034AC4 arm
 *   PROCSYS_Push 0x02031348 arm
 *   PROCSYS_Main 0x02031330 arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   gPartyListProcData 0x021BED00 data a4 ov091
 *   gPokeStatusProcData 0x021DC800 data a4 ov131
 *   ov91_id 0x0000005B data a1
 *   ov131_id 0x00000083 data a1
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   POKE_REGULATION_AdjustPartyLevels 0x0201A2A8 thumb
 *   func_0200873C 0x0200873C thumb
 *   PLIST_COMM_Start 0x021B6100 thumb ov090
 *   GAME_DATA_GetMyStatus  0x02012944  thumb  arm9
 *   POKEPARTY_GetCount  0x0201AA18  thumb  arm9
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb  arm9
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb  arm9
 */
#include "../../matched/include/Obj05411.h"
#include "../../matched/include/Obj23343.h"
#include "../../matched/include/Obj00310.h"
#include "../../matched/include/Obj06506.h"
#include "../../matched/include/Obj01742.h"
#include "../../matched/include/Obj02198.h"

struct Entry;
struct Link;
struct Obj0203159C;
struct S020314B8;
struct S020315D4;
struct Party;
struct PartyMon;
struct Big;
struct Sub02008700Obj;
struct Blk37;
typedef struct {
    char pad0[0xF0];
    int tbl[1];
} Tbl;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 w[11]; } Args_021DC860;

typedef struct { u8 *a; void *party; u32 f8; u8 fC, padD[3]; u32 f10; void *save; u8 tail[20]; } Args_021DC914;

typedef struct {
    void *party;
    u32 f4, f8, fC, f10;
    u8 *a;
    u8 pad18[24];
    u16 f30, pad32;
    u32 f34, f38, f3C, f40;
    u16 f44, f46;
    u8 f48, marks[6], pad4F;
    u32 f50;
    u16 f54, pad56;
    u32 f58, pad5C;
    u16 f60, pad62;
    u32 f64;
    u8 pad68[12];
    u32 f74, f78;
    u8 f7C, pad7D[15];
    u32 f8C, f90;
    u8 f94;
} Output;

extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, u32);
extern void *PROCSYS_Create(int a0);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void PLIST_COMM_End(void *);
extern void func_02034A5C(int);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void PLIST_COMM_Update(u8 *);
extern int func_02034AC4(int);
extern void PROCSYS_Push(void *, int, const void *, void *);
extern u32 PROCSYS_Main(void *);
extern void *POKEPARTY_GetMember(void *, u32);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(u32, u32, u32, u32, u32, u32, u32, u32);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *, unsigned int, unsigned int);
extern u32 func_0200FB24(void);
extern int GFL_NET_GetRunState(void);
extern int DWC_RAPCOMMON_HandleNetError(int, int);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void POKE_REGULATION_AdjustPartyLevels(void *, void *);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void PLIST_COMM_Start(u8 *);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
int func_021DC860(int i, Tbl *p);
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected);
int func_021DC888(void *ctx, int unused, const Args_021DC860 *args);
int func_021DC914(void *p,u32 a,u32 b,char *ctx);
int func_021DC93C(void *unused0, void *unused1, u8 *q, u8 *p);
void func_021DCB48(Args_021DC914 *p, void *unused, Output *out);
void func_021DCC48(u8 *p, void *unused, u8 *out);
extern const u32 tbl_021DCC9C[];
extern u32 g_02FFFC3C;
extern const char ov90_id[];
extern const u32 gPartyListProcData[], gPokeStatusProcData[];
extern const char ov91_id[], ov131_id[];




int func_021DC860(int i, Tbl *p)
{
    return p->tbl[i];
}



/*
 * extent: trailing 2-byte alignment padding; early return keeps the final unused compare.
 */
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected) { if(expected==GFL_NET_HANDLE_GetCurrentHandle()) { if(value!=GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())) return; } }



int func_021DC888(void *ctx, int unused, const Args_021DC860 *args)
{
    u8 *p;
    p = PROCSYS_AllocProcWork(ctx, 0x100, 4);
    MI_CpuFill8(p, 0, 0x100);
    *(Args_021DC860 *)(p + 0xd0) = *args;
    ((struct Obj05411 *)p)->fFC = 4;
    ((struct Obj05411 *)p)->fCC = PROCSYS_Create(((struct Obj05411 *)p)->fFC);
    GFL_NET_COMMAND_AddCommandTable(0x2f00, (u32)tbl_021DCC9C, 1, (u32)p);
    func_021DCB48((Args_021DC914 *)args, p, (Output *)(p + 4));
    func_021DCC48((u8 *)args, p, p + 0x9c);
    p[0xc4] = 0;
    ((struct Obj05411 *)p)->fC8 = g_02FFFC3C;
    ((struct Obj05411 *)p)->f0 = 0;
    return 1;
}



int func_021DC914(void *p,u32 a,u32 b,char *ctx) { PLIST_COMM_End(ctx+4); func_02034A5C((int)ov90_id); func_0203133C(((struct Obj23343 *)ctx)->fCC); func_020315D4(p); return 1; }



int func_021DC93C(void *unused0, void *unused1, u8 *q, u8 *p)
{
    u32 frame;
    u8 elapsed;
    u8 i;
    void *ctx;
    int code;
    if (((struct Obj00310 *)p)->f94 == 1 && ((struct Obj00310 *)p)->f64 != 0) {
        frame = g_02FFFC3C;
        elapsed = frame - ((struct Obj00310 *)p)->fC8;
        p[196] += elapsed;
        ((struct Obj00310 *)p)->fC8 = frame;
        if (p[196] > 60) {
            ((struct Obj00310 *)p)->f64 -= 1;
            p[196] -= 60;
        }
    }
    PLIST_COMM_Update(p + 4);
    switch (((struct Obj00310 *)p)->f0) {
    case 0:
        func_02034AC4((int)ov91_id);
        PROCSYS_Push(((struct Obj00310 *)p)->fCC, -1, gPartyListProcData, p + 4);
        ((struct Obj00310 *)p)->f0 = 1;
        break;
    case 1:
        if (PROCSYS_Main(((struct Obj00310 *)p)->fCC) == 0) ((struct Obj00310 *)p)->f0 = 2;
        break;
    case 2:
        func_02034A5C((int)ov91_id);
        if (((struct Obj00310 *)p)->f44 == 1) {
            p[171] = ((struct Obj00310 *)p)->f40;
            ((struct Obj00310 *)p)->f0 = 3;
        } else {
            ((struct Obj06506 *)q)->f28 = 0;
            ((struct Obj00310 *)p)->f0 = 6;
        }
        break;
    case 6:
        for (i = 0; i < 6; i++) {
            if (p[77 + i] != 0) {
                void *mon;
                mon = POKEPARTY_GetMember(((struct Obj06506 *)q)->f4, p[77 + i] - 1);
                POKEPARTY_Add(((struct Obj06506 *)q)->f1C, mon);
            }
        }
        ((struct Obj00310 *)p)->f0 = 7;
        break;
    case 7:
        ctx = GFL_NET_HANDLE_GetCurrentHandle();
        code = POKE_REGULATION_GetDataSize();
        if (GFL_NET_SendData((u32)ctx, 255, 0x2f00, code, *(u32 *)&((struct Obj06506 *)q)->f1C, 0, 0, 1) != 0) {
            GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 20, 47);
            ((struct Obj00310 *)p)->f0 = 8;
        }
        break;
    case 8:
        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 20, 47) != 0) return 1;
        break;
    case 3:
        func_02034AC4((int)ov131_id);
        PROCSYS_Push(((struct Obj00310 *)p)->fCC, -1, gPokeStatusProcData, p + 156);
        ((struct Obj00310 *)p)->f0 = 4;
        break;
    case 4:
        if (((struct Obj00310 *)p)->f94 == 1 && ((struct Obj00310 *)p)->f64 == 0) ((struct Obj00310 *)p)->fC0 = 1;
        if (func_0200FB24() != 0) ((struct Obj00310 *)p)->fC0 = 1;
        if (PROCSYS_Main(((struct Obj00310 *)p)->fCC) == 0) ((struct Obj00310 *)p)->f0 = 5;
        break;
    case 5:
        func_02034A5C((int)ov131_id);
        ((struct Obj00310 *)p)->f40 = p[171];
        ((struct Obj00310 *)p)->f0 = 0;
        break;
    }
    if (GFL_NET_GetRunState() != 0 && ((struct Obj00310 *)p)->f0 != 1 && ((struct Obj00310 *)p)->f0 != 2 && ((struct Obj00310 *)p)->f0 != 4 && ((struct Obj00310 *)p)->f0 != 5) {
        if (DWC_RAPCOMMON_HandleNetError(1, 1) != 0) {
            ((struct Obj06506 *)q)->f28 = 1;
            return 1;
        }
    }
    return 0;
}



void func_021DCB48(Args_021DC914 *p, void *unused, Output *out)
{
    u8 *a;
    void *b;
    u8 i;
    a = p->a;
    b = GAME_DATA_GetSaveControl(p->save);
    out->party = p->party;
    POKE_REGULATION_AdjustPartyLevels(a, out->party);
    out->f4 = 0;
    out->f8 = 0;
    out->fC = (u32)func_0200873C(b);
    out->f10 = 0;
    out->f30 = 0;
    out->f34 = 26;
    out->a = a;
    switch (a[0xba]) {
    case 0:
        out->f38 = 0;
        out->f64 = 1;
        break;
    case 1:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 2:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 3:
        out->f38 = 1;
        out->f64 = 1;
        break;
    case 4:
        out->f38 = 2;
        out->f64 = 2;
        break;
    }
    out->f44 = 0;
    out->f46 = 0;
    out->f48 = 0;
    out->f3C = 0;
    out->f40 = 0;
    for (i = 0; i < 6; i++) out->marks[i] = 0;
    out->f50 = 0;
    out->f58 = 0;
    out->f54 = 0;
    out->f74 = p->f10;
    out->f78 = p->f8;
    out->f7C = p->fC;
    out->f8C = a[184];
    if (a[185] != 0) {
        out->f90 = 1;
        out->f60 = a[185];
    } else {
        out->f90 = 0;
        out->f60 = 0;
    }
    out->f94 = 0;
    func_02034AC4((int)ov90_id);
    PLIST_COMM_Start((u8 *)out);
}

void func_021DCC48(u8 *p, void *unused, u8 *out)
{
    void *a;
    void *b;
    a = GAME_DATA_GetSaveControl(((struct Obj02198 *)p)->f14);
    GAME_DATA_GetMyStatus(((struct Obj02198 *)p)->f14);
    b = ZUKAN_SAVE_GetFromGameData(((struct Obj02198 *)p)->f14);
    ((struct Obj01742 *)out)->f0 = *(u32 *)&((struct Obj02198 *)p)->f4;
    ((struct Obj01742 *)out)->f8 = *(u32 *)&((struct Obj02198 *)p)->f14;
    ((struct Obj01742 *)out)->f4 = (u32)func_0200873C(a);
    out[12] = 1;
    out[13] = 1;
    out[14] = POKEPARTY_GetCount(((struct Obj02198 *)p)->f4);
    out[15] = 0;
    out[16] = 0;
    out[17] = 0;
    out[18] = 0;
    ((struct Obj01742 *)out)->f14 = 0;
    ((struct Obj01742 *)out)->f18 = ZUKAN_SAVE_IsNationalDexEnabled(b);
    ((struct Obj01742 *)out)->f20 = 0;
    ((struct Obj01742 *)out)->f24 = 0;
}
