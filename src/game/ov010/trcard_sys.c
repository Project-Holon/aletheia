/*
 * file:     trcard_sys.c
 * unit:     yes
 * function: func_0216F088, func_0216F0AC, func_0216F144, func_0216F174, func_0216F1E0, func_0216F228, func_0216F244, func_0216F288, func_0216F2B4, func_0216F2E0, func_0216F31C, func_0216F378, func_0216F3B0, func_0216F3D4, func_0216F40C, func_0216F7BC, func_0216F7F4, func_0216F830, func_0216F8B8, func_0216F8C8, func_0216F8DC, func_0216F900
 * address:  0x0216F088
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   PROCSYS_Main  0x02031330  arm
 *   func_0203133C  0x0203133C  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   d_02172B64     0x02172B64  data  ov010
 *   func_02012944  0x02012944  thumb
 *   func_02008554  0x02008554  thumb
 *   GAME_BEACON_SetTrainerView  0x02027174  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021725FC 0x021725FC data a4
 *   func_02012EBC 0x02012EBC thumb
 *   gPmsInputProcData 0x021C39D4 data ov110 a4
 *   ov110_id 0x0000006E data a1
 *   func_0216F088  0x0216F088  thumb  ov010
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E714  0x0200E714  thumb
 *   GAME_BEACON_SetPms  0x0202715C  thumb
 *   d_021C892C 0x021C892C data a4 ov111
 *   func_02008DFC  0x02008DFC  thumb
 *   d_02172620     0x02172620  data  a2
 *   func_020089C0  0x020089C0  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008A0C  0x02008A0C  thumb
 *   func_02008A28  0x02008A28  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_0200BF54  0x0200BF54  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02010F8C  0x02010F8C  thumb
 *   func_0200C184  0x0200C184  thumb
 *   func_02008EA0  0x02008EA0  thumb
 *   func_02008E78  0x02008E78  thumb
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_020089D0  0x020089D0  thumb
 *   func_020089CC  0x020089CC  thumb
 *   func_0216FEAC  0x0216FEAC  thumb  ov010
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   func_02045A98  0x02045A98  arm
 *   GAME_DATA_GetSaveBlock3A  0x02012EF0  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   func_0200D298  0x0200D298  thumb
 *   func_0200DBA0  0x0200DBA0  thumb
 *   func_0200A73C  0x0200A73C  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_021F385C  0x021F385C  thumb  ov059
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F38BC  0x021F38BC  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02012EC4 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 */

struct ZukanSave;
struct BtlSetup;
struct GameSystem;
struct BtlSetup;
struct RecordBlock;
struct BtlSetup;
struct ProcSys;
struct TrainerCardProfile;
struct MyStatus;
struct ProcSys;
struct PlayerSave;
struct BeaconRecord;
struct BadgeSave;
struct PlayTime;
struct BeaconRecord;
struct BattleRecSave;
struct TrainerCardSignature;
struct SaveClockOwner;
struct GameClearSave;
struct GameClearSave;
struct FlagSave;
struct RecordFlags;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef int s32;

typedef struct BtlSetup {
    u32 mode;           /* 0x00 */
    u8 pad04[0x14];
    u16 bgmId;          /* 0x18 */
    u8 pad1A[0x32];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BtlSetup;

/* Parameter block of the trainer card proc (24 bytes, copied into the work). */
typedef struct TrainerCardParam {
    struct TrainerCardProfile *profile;/* 0x00: caller's game data on entry, profile buffer in the work copy */
    void *saveData;                 /* 0x04 */
    u32 linkFlag;                   /* 0x08 */
    u32 nextScreen;                 /* 0x0C: set by the card proc, selects the next state */
    u32 result;                     /* 0x10 */
    u32 startScreen;                /* 0x14 */
} TrainerCardParam;

typedef struct TrainerCardWork {
    u32 heapId;                     /* 0x00 */
    u8 pad04[4];
    void *childProc;                /* 0x08 */
    void *playerSave;               /* 0x0C: parameter slot of the edit and badge procs */
    u8 pad10[4];
    u16 *editedBeacon;              /* 0x14 */
    TrainerCardParam *param;        /* 0x18 */
    int outfit;                     /* 0x1C */
} TrainerCardWork;

typedef struct MinimalWork {
    int heapId;                     /* 0x00 */
    u8 pad04[0x14];
    int param;                      /* 0x18 */
    u8 pad1C[4];
} MinimalWork;

typedef long long s64;

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

#include "field_event_types.h"

typedef struct SaveClock {
    u8 pad[0x24];
    s64 firstPlaySec;    /* 0x24 */
    s64 clearSec;        /* 0x2C */
} SaveClock;

typedef struct ViewWork {
    void *bmpWin;                   /* 0x00 */
    void *cardData;                 /* 0x04 */
    void *profile;                  /* 0x08 */
    u32 phase;                      /* 0x0C */
    u32 reserved10;                 /* 0x10 */
    u32 reserved14;                 /* 0x14 */
} ViewWork;

typedef struct EditWork {
    u8 *profile;                    /* 0x00 */
    void *cardData;                 /* 0x04 */
    void *reserved08;               /* 0x08 */
    u32 phase;                      /* 0x0C */
    u32 reserved10;                 /* 0x10 */
    u32 reserved14;                 /* 0x14 */
} EditWork;

extern void *func_0200CA1C(void *a);
extern void *func_020120F4(const struct GameSystem *p);
extern void *func_0201210C(const struct GameSystem *p);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern unsigned int PROCSYS_Main(void *p);
extern int func_0203133C();
extern void func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern void *func_0203159C(struct ProcSys *obj, u32 size, u32 heapId);
extern void func_02082BCC(void *p, int v, int n);
extern u8 *func_02012944(void *p);
extern u8 func_02008554(const struct MyStatus *obj);
extern int GAME_BEACON_SetTrainerView();
extern void func_020315D4(struct ProcSys *p);
extern void func_020306F0(unsigned int heapId);
extern void *PROCSYS_Create(int a0);
extern void PROCSYS_Push(void *,u32,const void *,void *);
int func_0216F088(void **childSlot);
int func_0216F0AC(void *proc, int state, TrainerCardParam *param);
int func_0216F144(void *proc, int state, int param);
int func_0216F174(int proc, int *state, int param, int work);
int func_0216F1E0(int proc, int state, TrainerCardParam *param, TrainerCardWork *work);
int func_0216F228(void *proc, int state, int param, MinimalWork *work);
int func_0216F244(TrainerCardWork *work, TrainerCardParam *param);
int func_0216F288(TrainerCardWork *work);
int func_0216F2B4(TrainerCardWork *work);
extern void *func_02012EBC(struct PlayerSave *p);
extern int func_0200E6F0(void);
extern void func_0200E714(struct BeaconRecord *dst, int idx, struct BeaconRecord *src);
extern void GAME_BEACON_SetPms(u32 a0);
extern u32 func_02008DFC(struct RecordBlock *obj, int i);
extern struct TrainerCardSignature *func_020089C0(void *gameSystem);
extern void *func_02012F08(int *p);
extern struct SaveClockOwner *func_02008B14(void *gameSystem);
extern struct RecordBlock *func_02008C58(void *gameSystem);
extern void *func_0200E6E8(u32 a);
extern int func_020084BC(const u16 *values);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct MyStatus *obj);
extern u32 func_02008530(const struct MyStatus *obj);
extern u32 func_0200C274(struct BadgeSave *p);
extern u32 func_0200C234(struct BadgeSave *p, u32 bit);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u16 func_02008A0C(const struct TrainerCardSignature *obj);
extern u8 func_02008A28(const struct TrainerCardSignature *obj);
extern void func_0200E6FC(struct BeaconRecord *src, int idx, struct BeaconRecord *dst);
extern u32 func_0200C1DC(struct BadgeSave *p);
extern u16 *func_0200BE48(void *gameSystem);
extern void *func_02010F7C(u32 heapId);
extern void func_0200BF54(struct BattleRecSave *p, u8 *dest, u32 n);
extern void *func_020127B8(void *save);
extern void func_02010F8C(void *p);
extern u32 func_0200C184(struct BadgeSave *p);
extern u32 func_02008EA0(struct RecordBlock *obj);
extern u8 func_02008E78(struct RecordBlock *obj);
extern struct GameClearSave *func_0200921C(void *p);
extern u8 func_020090E0(const struct GameClearSave *obj);
extern unsigned long long func_0200BF94(struct BattleRecSave *p);
extern u32 func_0201296C(const struct BtlSetup *p);
extern u32 func_020142E8(void *bitmap, int id);
extern u32 func_0200D0AC(struct ZukanSave *p, u32 heapId);
extern int func_020089D0(const struct TrainerCardSignature *obj);
extern void *func_020089CC(void *p);
extern int func_0216FEAC(void *tbl, void *pos, u8 *flags);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern u16 func_02045A98(void);
extern void *GAME_DATA_GetSaveBlock3A(void **p);
extern void *GAME_DATA_GetSaveBlock2A(void *save);
extern int func_0200D298(void *p);
extern u32 func_0200DBA0(struct FlagSave *p, s32 i, u32 op);
extern u32 func_0200A73C(struct PlayerSave *p);
extern u16 func_0200BDF8(struct BattleRecSave *p);
extern u16 func_0200BDFC(struct BattleRecSave *p);
extern void *func_0215A5DC(void *a0);
extern void func_021F385C(void *);
extern void *func_0215A5F4(void *p);
extern void *func_021F38BC();
extern int func_0215897C();
extern u8 *func_02012EC4(struct PlayerSave *p);
extern s32 *func_0200B3A4(struct RecordFlags *p, u32 b);
int func_0216F2E0(TrainerCardWork *work);
int func_0216F31C(TrainerCardWork *work);
int func_0216F378(TrainerCardWork *work);
int func_0216F3B0(TrainerCardWork *work);
u32 func_0216F3D4(void *records, int group, u32 cap);
void func_0216F40C(TrainerCardProfile *out, void *save, int mode, int flag, volatile u16 heapId);
ViewWork *func_0216F7BC(void *cardData, u32 heapId, void *profile);
EditWork *func_0216F7F4(void *cardData, u8 *profile, u32 heapId);
int func_0216F830(void *save);
int func_0216F8B8(void *unused, void *scriptCtx);
int func_0216F8C8(void *unused, void *scriptCtx);
int func_0216F8DC(void *unused, void *scriptCtx);
void func_0216F900(void *gameSystem);
extern char d_02172B64[];
extern char d_021725FC[];
extern const u32 gPmsInputProcData[];
extern char ov110_id[];
extern const u32 d_021C892C[];
extern u16 d_02172620[][7];


int func_0216F088(void **childSlot)
{
    if (*childSlot != 0 && PROCSYS_Main(*childSlot) == 0) {
        func_0203133C(*childSlot);
        *childSlot = 0;
        return 1;
    }
    return 0;
}




int func_0216F0AC(void *proc, int state, TrainerCardParam *param)
{
    TrainerCardWork *work;

    func_0203064C(1, 0x26, 0x18000);
    work = func_0203159C(proc, 0x20, 0x26);
    func_02082BCC(work, 0, 0x20);
    work->heapId = 0x26;
    work->param = func_02030734((u16)work->heapId, 0x18, 1, d_02172B64, 0x9f);
    *work->param = *param;
    work->param->profile = func_02030734((u16)work->heapId, 0x678, 1, d_02172B64, 0xa1);
    func_0216F40C(work->param->profile, param->saveData, 0, work->param->linkFlag, (u16)work->heapId);
    work->outfit = work->param->profile->outfit;
    return 1;
}



int func_0216F144(void *proc, int state, int param)
{
    MinimalWork *work;

    func_0203064C(1, 38, 0x18000);
    work = func_0203159C(proc, 32, 38);
    func_02082BCC(work, 0, 32);
    work->heapId = 38;
    work->param = param;
    return 1;
}




int func_0216F174(int proc, int *state, int param, int work)
{
    switch (*state) {
    case 0:
        *state = func_0216F244((TrainerCardWork *)work, (TrainerCardParam *)param);
        break;
    case 1:
        *state = func_0216F288((TrainerCardWork *)work);
        break;
    case 2:
        *state = func_0216F2B4((TrainerCardWork *)work);
        break;
    case 3:
        *state = func_0216F2E0((TrainerCardWork *)work);
        break;
    case 4:
        *state = func_0216F31C((TrainerCardWork *)work);
        break;
    case 5:
        *state = func_0216F378((TrainerCardWork *)work);
        break;
    case 6:
        *state = func_0216F3B0((TrainerCardWork *)work);
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}




/*
 * blocked:  listing 72 compiled 70
 */
int func_0216F1E0(int proc, int state, TrainerCardParam *param, TrainerCardWork *work)
{
    u8 *myStatus;
    int outfit;

    if (param->linkFlag != 0) {
        myStatus = func_02012944(param->saveData);
        outfit = func_02008554((const struct MyStatus *)myStatus);
        if (work->outfit != outfit)
            outfit = GAME_BEACON_SetTrainerView(outfit);
    }
    param->result = work->param->result;
    func_020307B0(work->param->profile);
    func_020307B0(work->param);
    func_020315D4((struct ProcSys *)proc);
    func_020306F0(0x26);
    return 1;
}




int func_0216F228(void *proc, int state, int param, MinimalWork *work)
{
    func_020307B0((void *)work->param);
    func_020315D4(proc);
    func_020306F0(0x26);
    return 1;
}




int func_0216F244(TrainerCardWork *work, TrainerCardParam *param)
{
    struct TrainerCardProfile *profile;

    switch (param->startScreen) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 5;
    case 0:
    default:
        profile = work->param->profile;
        if (profile->clearMonth == 0 && profile->playTimeSource != 0)
            return 5;
        return 1;
    }
}



/*
 * PROCSYS_Create forwards r0 to 02031354, which reads the heap input
 * and returns the allocation in r0. PROCSYS_Push forwards all four
 * inputs to 020314F4, which reads/stores r0-r3. Legacy void(void)
 * prototypes omit these live inputs and the observed return value.
 */
int func_0216F288(TrainerCardWork *work)
{
    if (work->childProc == 0)
        work->childProc = PROCSYS_Create((u16)work->heapId);
    PROCSYS_Push(work->childProc, -1, d_021725FC, work->param);
    return 2;
}



/*
 * Extent: two-byte zero alignment padding at 0216F2DE.
 */
int func_0216F2B4(TrainerCardWork *work)
{
    int screen;

    if (!func_0216F088(&work->childProc))
        return 2;
    screen = work->param->nextScreen;
    if (screen == 1)
        return 3;
    if (screen == 2)
        return 5;
    return 7;
}





/*
 * Interface: 02031324 veneer forwards heap in r0 and returns allocation from
 * 02031354; 02031348 forwards all four arguments to 020314F4.
 */
int func_0216F2E0(TrainerCardWork *work)
{
    if (work->childProc == 0)
        work->childProc = PROCSYS_Create((u16)work->heapId);
    work->playerSave = func_02012EBC(work->param->saveData);
    PROCSYS_Push(work->childProc, (u32)ov110_id, gPmsInputProcData, &work->playerSave);
    return 4;
}






/*
 * Byte-correct. Blocker: func_0200E714 (site +004C) is an unlabelled ARM9 Thumb
 * leaf (copies four halfwords to dst[idx*4]) whose only caller is this
 * function; no witness. Its C is parked: docs/notes/pkt_ov010_0200E714.c.txt
 * (register naming r3/r4 swapped).
 */
int func_0216F31C(TrainerCardWork *work)
{
    TrainerCardProfile *profile;
    u16 *beacon;
    int beaconSave;

    if (func_0216F088(&work->childProc) == 0)
        return 4;
    if (work->editedBeacon != 0) {
        func_02012EBC(work->param->saveData);
        beaconSave = func_0200E6F0();
        profile = work->param->profile;
        beacon = work->editedBeacon;
        profile->beaconRecord[0] = beacon[0];
        profile->beaconRecord[1] = beacon[1];
        profile->beaconRecord[2] = beacon[2];
        profile->beaconRecord[3] = beacon[3];
        func_0200E714((struct BeaconRecord *)beaconSave, 0, (struct BeaconRecord *)work->editedBeacon);
        GAME_BEACON_SetPms((u32)work->editedBeacon);
    }
    return 1;
}





/*
 * hint. Pooled request ID is 110, so no proven ov111 loading path yet.
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * Interface: veneers preserve arguments and result as shown by their full
 * forwarding targets 02031354 and 020314F4.
 */
int func_0216F378(TrainerCardWork *work)
{
    if (work->childProc == 0)
        work->childProc = PROCSYS_Create((u16)work->heapId);
    work->playerSave = func_02012EBC(work->param->saveData);
    PROCSYS_Push(work->childProc, (u32)ov110_id, d_021C892C, work->param);
    return 6;
}





/*
 * Extent: two-byte zero alignment padding at 0216F3D2.
 */
int func_0216F3B0(TrainerCardWork *work)
{
    if (!func_0216F088(&work->childProc))
        return 6;
    if (work->param->nextScreen == 3)
        return 1;
    return 7;
}






/*
 * Sums func_02008DFC over one seven-entry row of a u16 table (rows of 14
 * bytes at 0x02172620), stopping at the first zero entry and clamping the
 * running sum to cap.
 */
u32 func_0216F3D4(void *records, int group, u32 cap)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 7; i++) {
        if (d_02172620[group][i] == 0)
            break;
        sum += func_02008DFC(records, d_02172620[group][i]);
        if (sum > cap)
            sum = cap;
    }
    return sum;
}






/*
 * Fills a 0x674-byte profile record from the save (name, flags, two RTC
 * dates, seven capped counters, a 0x600-byte blob). Byte-correct: 944/944,
 * every concrete byte right.
 *
 * Levers: the fifth (stack) parameter is `volatile u16`, which is what makes
 * the image re-read it from its stack home at both uses (0x0216F66C and
 * 0x0216F760); held in a register it takes r6 and the constant 1 that the
 * image keeps in r7 from 0x0216F608 to the fl0 insert at 0x0216F6E2 is
 * rematerialised instead. `out->f08 = 0` is written before `out->kind`.
 *
 * Blocker (MATCH, two sites): 0x02010F7C and 0x02010F8C are unlabelled ARM9
 * Thumb thunks whose only caller is this function, so neither call has a
 * witness. 0x02010F7C is `ldr r3, =0x02048F61; adds r2, r0, #0; movs r0,
 * #0x26; movs r1, #0; bx r3` (a heap-id forwarder, `return
 * func_02048F60(0x26, 0, heap);`), 0x02010F8C is `ldr r3, =0x020307B1;
 * bx r3` (`func_020307B0(p);`). Matching either thunk (ARM9 territory)
 * closes that site.
 */
void func_0216F40C(TrainerCardProfile *out, void *save, int mode, int flag, volatile u16 heap)
{
    RTCDate date;
    RTCTime time;
    u8 work[4];
    void *playerSave;
    void *signature;
    void *myStatus;
    void *badges;
    SaveClock *saveClock;
    void *records;
    void *beaconData;
    void *zukan;
    void *scratch;
    void *battleRec;
    u8 badgeIndex;
    u8 badgeBit;

    playerSave = func_02012EBC(save);
    signature = func_020089C0(playerSave);
    myStatus = func_02012944(save);
    badges = func_02012F08(save);
    saveClock = (SaveClock *)func_02008B14(playerSave);
    records = func_02008C58(playerSave);
    beaconData = func_0200E6E8((u32)playerSave);
    zukan = func_0200CA1C(save);

    if (func_020084BC(myStatus) == 0) {
        MIi_CpuCopy16(func_020084F4(myStatus), out->name, 16);
    } else {
        out->name[0] = 'N';
        out->name[1] = 'o';
        out->name[2] = 'N';
        out->name[3] = 'a';
        out->name[4] = 'm';
        out->name[5] = 'e';
        out->name[6] = func_02045A98();
    }
    out->starCount = (u32)func_0216F830(save);
    out->outfitVariant = (u32)func_02008550(myStatus);
    out->trainerId = func_02008530(myStatus);
    out->badgeCount = func_0200C274(badges);
    out->badgeMask = 0;
    out->formatVersion = 0x15;
    for (badgeIndex = 0, badgeBit = 1; badgeIndex < 8; badgeIndex++) {
        if (func_0200C234(badges, badgeIndex) == 1)
            out->badgeMask |= badgeBit;
        badgeBit <<= 1;
    }

    if (mode == 1) {
        scratch = (void *)func_02012FCC((int)save);
        out->outfit = (u32)func_02008554(myStatus);
        out->isLinkMode = 0;
        out->playTimeSource = 0;
        out->playHours = (u32)func_0200864C(scratch);
        out->playMinutes = (u32)func_02008650(scratch);
    } else {
        out->outfit = (u32)func_02008554(myStatus);
        out->isLinkMode = 1;
        out->playTimeSource = (u32)func_02012FCC((int)save);
    }
    out->signatureColor = (u32)func_02008A0C(signature);
    out->signatureStyle = (u32)func_02008A28(signature);
    func_0200E6FC(beaconData, (u32)0, (struct BeaconRecord *)out->beaconRecord);

    RTC_ConvertSecondToDateTime(&date, &time, saveClock->firstPlaySec);
    out->startYear = date.year;
    out->startMonth = date.month;
    out->startDay = date.day;
    if (saveClock->clearSec == 0) {
        out->clearYear = 0;
        out->clearMonth = 0;
        out->clearDay = 0;
        out->clearHour = 0;
        out->clearMinute = 0;
    } else {
        RTC_ConvertSecondToDateTime(&date, &time, saveClock->clearSec);
        out->clearYear = date.year;
        out->clearMonth = date.month;
        out->clearDay = date.day;
        out->clearHour = time.hour;
        out->clearMinute = time.minute;
    }

    out->recordSum0 = func_0216F3D4(records, 0, 999999999);
    out->recordSum1 = func_0216F3D4(records, 1, 999999999);
    out->recordSum2 = func_0216F3D4(records, 2, 999999999);
    out->recordSum3 = func_0216F3D4(records, 3, 999999999);
    out->recordSum4 = func_0216F3D4(records, 4, 999999999);
    out->recordSum5 = func_0216F3D4(records, 5, 999999999);
    out->recordSum6 = func_0216F3D4(records, 6, 999999999);
    out->badgeTotal = func_0200C1DC(badges);
    out->recordSum7 = func_0216F3D4(records, 7, 9999);

    battleRec = func_0200BE48(playerSave);
    scratch = func_02010F7C(heap);
    func_0200BF54(battleRec, work, 2);
    out->visitedSpotCount = func_0216FEAC(scratch, func_020127B8(save), work);
    func_02010F8C(scratch);

    out->recordSum8 = func_0216F3D4(records, 8, 9999);
    out->badgeExtraCount = func_0200C184(badges);
    out->recordTopValue = func_02008EA0(records);
    out->recordTopFlag = (u32)func_02008E78(records);
    out->isGameCleared = (u32)func_020090E0((const struct GameClearSave *)func_0200921C(save));
    if (func_0200BF94((struct BattleRecSave *)func_0200BE48(playerSave)) != 0)
        out->hasBattleRecord = 1;
    if (out->recordSum8 != 0)
        out->hasRecordSum8 = 1;
    if (func_02008DFC(records, (u16)0x78))
        out->hasRecordFlag78 = 1;
    if (func_02008DFC(records, (u16)0x79))
        out->hasRecordFlag79 = 1;
    if (func_020142E8((void *)func_0201296C(save), 2402) == 1)
        out->hasEventFlag2402 = 1;
    else
        out->hasEventFlag2402 = 0;
    out->pokedexCount = func_0200D0AC(zukan, heap);
    out->hasSignature = (u32)func_020089D0(signature);
    MI_CpuCopy8(func_020089CC(signature), out->signatureBitmap, 0x600);
    out->flagFromParam = flag;
}





ViewWork *func_0216F7BC(void *cardData, u32 heapId, void *profile)
{
    ViewWork *view;

    view = func_02030734(heapId, 24, 1, d_02172B64, 0x321);
    func_02082BCC(view, 0, 24);
    view->bmpWin = 0;
    view->cardData = cardData;
    view->phase = 0;
    view->profile = profile;
    return view;
}




EditWork *func_0216F7F4(void *cardData, u8 *profile, u32 heapId)
{
    EditWork *edit;

    edit = func_02030734(heapId, 24, 1, d_02172B64, 0x33a);
    edit->profile = profile;
    edit->cardData = cardData;
    edit->phase = 0;
    profile[4] = profile[4] & ~0x40;
    edit->profile[4] |= 0x80;
    return edit;
}





/*
 * Counts how many of five save-data conditions hold.
 *
 * Byte-correct (MATCH*, the 136-byte extent includes two bytes of pad).
 * unlabelled ARM9 Thumb thunk (`ldr r0, [r0]; ldr r3, =0x020071CD;
 * movs r1, #0x3a; bx r3`, i.e. `return func_020071CC(*p, 0x3A);`, with the
 * sibling at 0x02012F00 passing 0x3B) whose only caller is this function.
 * Matching that thunk (ARM9 territory) or seeding its start closes this file.
 */
int func_0216F830(void *save)
{
    int n;
    void *a;
    void *b;
    void *c;

    n = 0;
    a = GAME_DATA_GetSaveBlock3A(save);
    b = GAME_DATA_GetSaveBlock2A(save);
    c = func_020127B8(save);
    if (func_020142E8((void *)func_0201296C(save), 0x960))
        n++;
    if (func_0200D298(func_0200CA1C(save)))
        n++;
    if (func_0200DBA0(a, 7, 0) && func_0200DBA0(a, 8, 0))
        n++;
    if (func_0200A73C(b))
        n++;
    if (func_0200BDF8(c) >= 30 && func_0200BDFC(c) >= 30)
        n++;
    return n;
}





int func_0216F8B8(void *unused, void *scriptCtx)
{
    void *gameSystem;

    gameSystem = func_0215A5DC(scriptCtx);
    func_0216F900(gameSystem);
    return 0;
}





/*
 * blocked:
 */
int func_0216F8C8(void *unused, void *scriptCtx)
{
    func_021F385C(func_0201210C(func_0215A5DC(scriptCtx)));
    return 0;
}





int func_0216F8DC(void *unused, void *scriptCtx)
{
    void *scriptWork;
    void *gameSystem;
    void *task;

    scriptWork = func_0215A5F4(scriptCtx);
    gameSystem = func_0215A5DC(scriptCtx);
    task = func_021F38BC(gameSystem);
    func_0215897C(scriptWork, task);
    return 1;
}




/*
 * Extent: two-byte zero alignment padding at 0216F916.
 * Interface: the call explicitly supplies r1=0x36 even though the leaf reads only r0.
 */
void func_0216F900(void *gameSystem)
{
    *func_0200B3A4((struct RecordFlags *)func_02012EC4(func_020120F4(gameSystem)), 0x36) = 1;
}
