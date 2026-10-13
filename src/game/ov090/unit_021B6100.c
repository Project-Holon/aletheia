/*
 * file:     unit_021B6100.c
 * unit:     yes
 * function: func_021B6100, func_021B6108, func_021B6114, func_021B6184, func_021B61C4, func_021B61E8
 * address:  0x021B6100
 * region:   ov090
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203A574  0x0203A574  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   d_021B6228     0x021B6228  data  a4
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
struct NetHandle;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

/*
 * The fields of the party list parameter block (PartyListParam, defined by
 * the caller in ov012) that this overlay reads and writes. Offsets 0x62,
 * 0x63 and 0x94 lie in the unnamed gap of that struct.
 */
typedef struct PartyListCommWork {
    u8 unusedHead[0x62];
    u8 syncStep;          /* 0: request sync 1, 1: wait for it and register the command table, 2: running */
    u8 commFinished;      /* set on a network error, read by func_021B61FC as "stop waiting" */
    u8 unusedMid[0x30];
    u8 receivedCount;     /* incremented by every status message with status 0 */
} PartyListCommWork;

/* Payload of the status command (4 bytes on the wire). */
typedef struct PartyListStatusMsg {
    u16 selection;
    u8 status;
} PartyListStatusMsg;

extern void func_0203A5E4(u32 commandBase);
extern struct NetHandle *func_020399A8(void);
extern void func_02039C68(struct NetHandle *handle, u32 syncNo, u32 syncGroup);
extern u32 func_02039CB4(struct NetHandle *handle, u32 syncNo, u32 syncGroup);
extern void func_0203A574(u32 commandBase, const void *commandTable, u32 commandCount, void *work);
extern u32 func_0200FB24(void);
extern u32 func_0203D3F8(struct NetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 c, u32 d, u32 e);
extern u32 func_0203D1A4(struct NetHandle *handle);
void func_021B6100(PartyListCommWork *work);
void func_021B6108(void *unused);
void func_021B6114(PartyListCommWork *work);
u32 func_021B6184(PartyListCommWork *work, u8 status, u16 selection);
void func_021B61C4(int netId, int size, u8 *data, PartyListCommWork *work);
void func_021B61E8(void *work, int syncNo);
extern u8 d_021B6228[];

void func_021B6100(PartyListCommWork *work)
{
    work->syncStep = 0;
}

/*
 * Leaf of ov178 021E54CC; caller unloads overlay 90 immediately after call.
 */
void func_021B6108(void *unused)
{
    func_0203A5E4(0x2D00);
}


void func_021B6114(PartyListCommWork *work)
{
    switch (work->syncStep) {
    case 0:
        func_02039C68(func_020399A8(), 1, 0x2d);
        work->syncStep = 1;
        break;
    case 1:
        if (func_02039CB4(func_020399A8(), 1, 0x2d) == 1) {
            func_0203A574(0x2d00, d_021B6228, 1, work);
            work->syncStep = 2;
        }
        break;
    case 2:
        break;
    }
    if (func_0200FB24() != 0 && work->commFinished == 0)
        work->commFinished = 1;
}


u32 func_021B6184(PartyListCommWork *work, u8 status, u16 selection)
{
    PartyListStatusMsg msg;
    struct NetHandle *handle;

    handle = func_020399A8();
    msg.status = status;
    msg.selection = selection;
    if (work->syncStep != 2)
        return 0;
    return func_0203D3F8(handle, 0xff, 0x2d00, 4, &msg, 1, 0, 0);
}

/* Command callback for 0x2d00: counts the status messages whose status is 0. */
void func_021B61C4(int netId, int size, u8 *data, PartyListCommWork *work)
{
    func_0203D1A4(func_020399A8());
    if (data[2] == 0)
        work->receivedCount++;
}


void func_021B61E8(void *work, int syncNo)
{
    func_02039C68(func_020399A8(), syncNo, 45);
}
