/*
 * file:     bsubway_comm.c
 * unit:     yes
 * function: func_02167AB0, func_02167AC4, func_02167B00, func_02167B18, func_02167B24, func_02167B34, func_02167B44, func_02167B9C, func_02167BB4, func_02167BCC, func_02167BD8, func_02167BE4, func_02167BF0, func_02167BFC, func_02167CB4, func_02167CF4, func_02167D00, func_02167D44, func_02167DB8, func_02167DEC, func_02167E28, func_02167E54, func_02167E88, func_02167EAC, func_02167ED0
 * address:  0x02167AB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from comm_player.c at 0x02167AB0: bsubway script comm block, called only from ov021 bsubway_scr.c (name guess, no anchor).
 *
 * symbols:
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02172014  0x02172014  data  ov010
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02087C6C 0x02087C6C arm
 *   func_0203A574 0x0203A574 arm
 *   d_02171FD4  0x02171FD4  data  ov010  a4
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_020399A8  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   func_021CA210  0x021CA210  thumb  ov021
 *   func_02008550  0x02008550  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021CA234  0x021CA234  thumb  ov021
 *   func_021CA2CC  0x021CA2CC  thumb  ov021
 *   func_02082D44  0x02082D44  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039338  0x02039338  arm
 */
struct Req;
struct NetHandle;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

#include "../ov021/bsubway_scr_types.h"

extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *, void *);
extern void func_02087C6C(void *);
extern void func_0203A574(u32, u32, u32, u32);
void func_0203A5E4(u32 key);
extern struct NetHandle *func_020399A8(void);
extern int GFL_NET_StartTimingSync();
extern int GFL_NET_CheckTimingSync();
extern void *func_021CA210(u8 *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u16 func_021CA234(u8 *p);
extern u16 func_021CA2CC(u16 v);
extern void func_02082D44(void *dst, void *src, int n);
extern u32 func_0200FB24(void);
extern int func_0203D3A8(struct NetHandle *a, u32 b, u32 c, u32 d);
extern u16 func_02039338(void);
void func_02167AB0(void *arg);
void *func_02167AC4(BsubwayScrWork *work);
int func_02167AF0(void);
int func_02167AF4(int a, int b);
void func_02167B00(u32 work);
void func_02167B18(void *work);
int func_02167B24(int timingNo);
int func_02167B34(int timingNo);
void func_02167B44(BsubwayScrWork *work, void *gameData);
void func_02167B9C(BsubwayScrWork *work);
void func_02167BB4(BsubwayScrWork *work, u16 retire);
void func_02167BCC(BsubwayScrWork *work);
void func_02167BD8(BsubwayScrWork *work, u32 value);
void func_02167BE4(BsubwayScrWork *work, u32 value);
void func_02167BF0(BsubwayScrWork *work, u32 value);
void func_02167BFC(BsubwayScrWork *work, u32 cmd, u16 arg);
int func_02167CB4(BsubwayScrWork *work);
void func_02167CF4(BsubwayScrWork *work, u8 mode);
int func_02167D00(BsubwayScrWork *work, u16 *result);
void func_02167D44(int netId, int size, const u16 *data, BsubwayScrWork *work);
void func_02167DB8(u16 netId, int size, void *data, BsubwayScrWork *work);
void func_02167DEC(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void func_02167E28(u16 netId, int size, void *data, BsubwayScrWork *work);
void func_02167E54(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void func_02167E88(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void func_02167EAC(u16 netId, int size, u16 *data, BsubwayScrWork *work);
void func_02167ED0(u16 netId, int size, u16 *data, BsubwayScrWork *work);
extern u8 d_02172014[];
extern const u32 d_02171FD4[];


/*
 * Tail call to ARM func_0203CBAC with (&d_02172014, 0, arg). No lr-saving
 * prologue; bl from ov021 func_021CA5C4 at 0x021CB4F4.
 */
void func_02167AB0(void *arg)
{
    func_0203CBAC((struct Req *)d_02172014, 0, (u32)arg);
}


/*
 * Fills the own comm record (MyStatus copy, MAC address, magic 0x3A0B) and
 * returns it.  The trailing unlabelled constant getter and equality
 * predicate are included.
 */
void *func_02167AC4(BsubwayScrWork *work)
{
    BsubwayCommInfo *info;
    info = &work->commInfo;
    func_02008494(func_02012944(work->gameData), info);
    func_02087C6C(info->macAddress);
    info->magic = 0x3a0b;
    return info;
}


int func_02167AF0(void)
{
    return 0x28;
}


int func_02167AF4(int a, int b)
{
    if (a == b) return 1;
    return 0;
}


/*
 * Adds the net command table 0x2C00..0x2C08 with the work as callback
 * argument.  Trailing extent is already matched func_02167B18.
 */
void func_02167B00(u32 work)
{
    func_0203A574(0x2c00, (u32)d_02171FD4, 0x2c08, work);
}


/*
 * Unlabelled leaf, blocker of ov021 func_021CB8AC: tail call of func_0203A5E4(0x2C00); the argument is ignored.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * Addresses are Black-image addresses.
 */
void func_02167B18(void *work)
{
    func_0203A5E4(0x2c00);
}


/* Starts the timing sync timingNo on the current net handle. */
int func_02167B24(int timingNo)
{
    return GFL_NET_StartTimingSync(func_020399A8(), timingNo);
}


/* Checks the timing sync timingNo on the current net handle. */
int func_02167B34(int timingNo)
{
    return GFL_NET_CheckTimingSync(func_020399A8(), timingNo);
}


/* Player data: own sex, the species of the two chosen members and the stage. */
void func_02167B44(BsubwayScrWork *work, void *gameData)
{
    void *myStatus;
    void *party;
    int i;

    myStatus = func_02012944(gameData);
    party = func_021CA210((u8 *)work);
    work->sendBuf.player.sex = func_02008550(myStatus);
    for (i = 0; i < 2; i++)
        work->sendBuf.player.monsNo[i] = func_02017E1C(func_0201AB28(party, work->memberIndex[i]), 5, 0);
    work->sendBuf.player.stage = func_021CA2CC(func_021CA234((u8 *)work));
}


/*
 * Unlabelled Thumb leaf hidden in a word run (no lr saved); callee of ov010 func_02167BFC.
 */
void func_02167B9C(BsubwayScrWork *work)
{
    func_02082D44(work->trainerNo, work->sendBuf.raw, 0x1C);
}


void func_02167BB4(BsubwayScrWork *work, u16 retire)
{
    work->stateBits.retireSelect = retire;
    work->sendBuf.select.retire = retire;
}


void func_02167BCC(BsubwayScrWork *work)
{
    *(u32 *)work->sendBuf.raw = work->playMode;
}


void func_02167BD8(BsubwayScrWork *work, u32 value)
{
    *(u32 *)work->sendBuf.raw = value;
}


void func_02167BE4(BsubwayScrWork *work, u32 value)
{
    *(u32 *)work->sendBuf.raw = value;
}


void func_02167BF0(BsubwayScrWork *work, u32 value)
{
    *(u32 *)work->sendBuf.raw = value;
}


/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void func_02167BFC(BsubwayScrWork *work, u32 cmd, u16 arg)
{
    void *gameData;
    gameData = work->gameData;
    switch (cmd) {
    case 0:
        work->sendCommand = 0x2C00;
        func_02167B44(work, gameData);
        return;
    case 1:
        work->sendCommand = 0x2C01;
        func_02167B9C(work);
        return;
    case 2:
        work->sendCommand = 0x2C02;
        func_02167BB4(work, arg);
        return;
    case 3:
        work->sendCommand = 0x2C03;
        func_02008494(func_02012944(gameData), work->sendBuf.raw);
        return;
    case 4:
        work->sendCommand = 0x2C04;
        func_02167BCC(work);
        return;
    case 5:
        work->sendCommand = 0x2C05;
        func_02167BD8(work, arg);
        return;
    case 6:
        work->sendCommand = 0x2C06;
        func_02167BE4(work, arg);
        return;
    case 7:
        work->sendCommand = 0x2C07;
        func_02167BF0(work, arg);
        return;
    default:
        work->sendCommand = 0x2C08;
        return;
    }
}


int func_02167CB4(BsubwayScrWork *work)
{
    u16 command;
    if (func_0200FB24() != 0)
        return 1;
    command = work->sendCommand;
    if (command >= 0x2C08)
        return 1;
    if (func_0203D3A8(func_020399A8(), command, 0x46, (u32)work->sendBuf.raw) == 1)
        return 1;
    return 0;
}


/*
 * Byte setter at +0x725. bl from ov021 func_021CA5C4 at 0x021CB596.
 */
void func_02167CF4(BsubwayScrWork *work, u8 mode)
{
    work->recvMode = mode;
}


int func_02167D00(BsubwayScrWork *work, u16 *result)
{
    int expected;
    if (func_0200FB24() != 0)
        return 1;
    expected = 1;
    if (work->recvMode != 1)
        expected = 2;
    if (work->recvCount == expected) {
        work->recvCount = 0;
        if (result != 0)
            *result = work->recvResult;
        return 1;
    }
    return 0;
}


/*
 * lever: Const source halfwords restores c[0]/c[1] load scheduling.
 */
void func_02167D44(int netId, int size, const u16 *data, BsubwayScrWork *work)
{
    u16 sameCount = 0;
    u16 sex;
    u16 monsNo;
    work->recvCount++;
    if (netId != func_02039338()) {
        sex = data[0];
        monsNo = data[1];
        work->partnerSex = sex;
        work->partnerMonsNo[0] = monsNo;
        work->partnerMonsNo[1] = data[2];
        work->partnerStage = data[3];
        work->stateBits.partnerNo = work->partnerSex + 5;
        if (work->memberMonsNo[0] == monsNo || work->memberMonsNo[0] == work->partnerMonsNo[1])
            sameCount += 1;
        if (work->memberMonsNo[1] == monsNo || work->memberMonsNo[1] == work->partnerMonsNo[1])
            sameCount += 2;
        work->recvResult = sameCount;
    }
}


void func_02167DB8(u16 netId, int size, void *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338() && func_02039338() != 0)
        func_02082D44(data, work->trainerNo, 0x1c);
}


void func_02167DEC(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338()) {
        work->recvResult = 0;
        if ((work)->stateBits.retireSelect != 0 || *data != 0)
            work->recvResult = 1;
    }
}


void func_02167E28(u16 netId, int size, void *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338())
        func_02082D44(data, &work->partnerMyStatus, 0x20);
}


void func_02167E54(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338()) {
        if (work->playMode != *data)
            work->recvResult = 0;
        else
            work->recvResult = 1;
    }
}


void func_02167E88(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338())
        work->recvResult = *data;
}


void func_02167EAC(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338())
        work->recvResult = *data;
}


void func_02167ED0(u16 netId, int size, u16 *data, BsubwayScrWork *work)
{
    work->recvCount++;
    if (netId != func_02039338())
        work->recvResult = *data;
}
