/*
 * file:     net_whpipe_p02.c
 * unit:     yes
 * function: func_02177C1C, func_02177C4C, func_02177CE4, func_02177D0C, func_02177D58, func_02177DB0, func_02177E20, func_02177E9C, func_02177EB0, func_02177EDC, func_02177EFC, func_02177F48, func_02177FC4, func_02177FF0, func_02178034, func_0217807C, func_02178098, func_021780C4, func_021780E4, func_021780FC, func_02178118
 * address:  0x02177C1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from wih.c at 0x02178138 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   d_0217967C     0x0217967C  data   a2
 *   func_0203D798  0x0203D798  arm
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02178E28  0x02178E28  thumb  ov014
 *   d_02179680     0x02179680  data  ov014  a2
 *   func_0217771C  0x0217771C  thumb  ov014
 *   func_02082D44  0x02082D44  arm
 *   func_02177704 0x02177704 thumb ov014
 *   d_02179678     0x02179678  data  a1
 *   func_02177AA8  0x02177AA8  thumb  ov014
 *   func_020056EC  0x020056EC  thumb
 *   func_021773E0  0x021773E0  thumb  ov014
 *   func_0217758C  0x0217758C  thumb  ov014
 *   func_02177560  0x02177560  thumb  ov014
 *   func_02178524 0x02178524 thumb ov014
 *   func_021785B4 0x021785B4 thumb ov014
 *   func_02178714 0x02178714 thumb ov014
 *   func_021788FC 0x021788FC thumb ov014
 *   func_02178E38 0x02178E38 thumb ov014
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_02179024 0x02179024 thumb ov014
 *   func_02179158 0x02179158 thumb ov014
 *   func_02179288 0x02179288 thumb ov014
 *   func_02179328 0x02179328 thumb ov014
 *   func_0217933C 0x0217933C thumb ov014
 *   func_02179368 0x02179368 thumb ov014
 *   func_02179498 0x02179498 thumb ov014
 *   func_02179570 0x02179570 thumb ov014
 *   func_021795A4 0x021795A4 thumb ov014
 *   func_021795C0 0x021795C0 thumb ov014
 *   func_021795D4 0x021795D4 thumb ov014
 */
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef int BOOL;

/* Beacon payload (user game info) that the parent advertises; a received copy sits at 0x50 of each entry. */
typedef struct WhPipeBeacon {
    u16 checksum;
    u16 ggid;
    u8 kind;
    u8 reserved;
    u8 unused6;
    u8 status;
    u8 data[0x68];
} WhPipeBeacon;

/* One scanned parent (a WMBssDesc followed by its game info). */
typedef struct WhPipeEntry {
    u8 header[4];
    u8 bssid[6];
    u8 ssidBlock[0x2C];
    u16 channel;
    u8 gameInfoHeader[0x18];
    WhPipeBeacon beacon;
} WhPipeEntry;

typedef struct WhPipeWork WhPipeWork;
typedef void (*WhPipeTask)(WhPipeWork *work);

/* Work block of the wireless pipe; allocated with size 0xCF8 by func_02177280. */
struct WhPipeWork {
    WhPipeTask task;
    int (*eventCallback)(int a, int b, int c);
    WhPipeEntry entry[16];
    u8 entryTail[0x30];
    void *notifyFn;
    u32 notifyArg;
    u16 entryAge[16];
    void (*onConnected)(void);
    u32 userData;
    u16 tgid;
    u16 startTime;
    u16 joinLockFrames;
    WhPipeBeacon beacon;
    u8 targetBssid[6];
    u8 startedFlag;
    u8 gapCE5;
    u8 channel;
    u8 shutdownRequest;
    u8 running;
    u8 scanning;
    u8 beaconStatus;
    u8 disconnectDetected;
    u8 watchDisconnect;
    u8 gapCED[2];
    u8 resumeFlag;
    u8 gapCF0;
    u8 searchChannelIndex;
    u8 searchTimer;
    u8 timerPaused;
    u8 joinLockHold;
    u8 gapCF5[3];
};

/* Partial view of the network init block returned by func_0203D798. */
typedef struct WhPipeNetInit {
    u8 gap00[0x50];
    u32 ggid;
    u8 gap54[0xC];
    u8 maxConnectNum;
    u8 gap61[3];
    u8 bMPMode;
    u8 gap65;
    u8 bRenewTgid;
    u8 gameKind;
} WhPipeNetInit;

extern void *func_0203D798(void);
extern u16 func_0208F1B4(void);
extern void func_0217778C(void);
extern void func_0217727C(WhPipeWork *work, WhPipeTask task);
int func_021775AC(int a, int b, int c);
u16 func_0203F1FC(const u8 *src, u32 len);
void func_020862F0(void *p, u32 n);
void func_02178E28(void *p, u32 n);
int func_0217771C(u8 *obj);
void func_02082D44(void *d, void *s, u32 n);
extern void func_02177704(void);
int func_02177AA8(void);
u32 func_020056EC(u32 n);
int func_021773E0(u8 *p);
void func_0217758C(u8 *p);
void func_02177560(void);
/* Evidence: func_02177C30 truncates its second argument to u16 at the tail call; the extern reflects that caller width. */
int func_02177C1C(void);
int func_02177C30(int a, unsigned int b, int c);
unsigned int func_02177C3C(void);
int func_02177C44(void);
void func_02177C4C(WhPipeWork *work);
void func_02177CE4(WhPipeWork *work);
int func_02177D0C(int a);
void func_02177D58(u8 *buf, u32 len);
void func_02177DB0(WhPipeWork *work);
int func_02177E20(u32 a, u8 *b, u32 c, void (*d)(void));
void func_02177E9C(WhPipeWork *work);
int func_02177EB0(int a);
int func_02177ED4(void);
int func_02177ED8(void);
/* Evidence: func_02179328 stores its argument unchanged; the caller passes a function pointer. */
void func_02177EDC(int a);
void func_02177EFC(WhPipeWork *work);
void func_02177F48(WhPipeWork *work);
void func_02177FC4(WhPipeWork *work);
void func_02177FF0(WhPipeWork *work);
int func_02178034(void);
void func_0217807C(void);
/* Leaf called from func_0201058C at +005C; byte-identical to func_02177B80: read g_021797A4, test the per-slot flag, return the slot's state byte, or 0. */
u8 func_02178098(u8 i);
/* Leaf called from ov010 func_02157760. */
void func_021780C4(u32 i);
void func_021780E4(int a);
void func_021780FC(u8 value);
/* Leaf called from ov122 func_021D4B74; two stores into the pipe work block. */
void func_02178118(u32 callback, u32 value);
/* The bssid argument is const: that lets the ldrh of b[1] schedule above the strh of b[2] (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md). */
int func_02178524(u32 a, const u16 *b, u32 c);
int func_021785B4(u32 a, u16 *b, u32 c);
void func_02178714(u16 value, void *src);
int func_021788FC(void);
u16 func_02178E38(void);
int func_02178E4C(void);
int func_02178E84(void);
u16 func_02179024(void);
void func_02179158(void);
BOOL func_02179288(int mode, u16 tgid, int channel, u16 maxEntry);
void func_02179328(void *v);
void func_0217933C(void *cb);
/* Guard wrapper: forwards to func_02178D20 when func_021795A4 is nonzero or one of bits 1-7 of func_02178E38 is set, else returns 0. */
BOOL func_02179368(int a, u16 b, int c);
/* The DWC copy of the NitroSDK demo wh.c WH_Finalize (DWCi_MOV_WH_*), returning BOOL. */
BOOL func_02179498(void);
int func_02179570(void (*cb)(int));
unsigned short func_021795A4(void);
void func_021795C0(unsigned v);
/* When the state word of the WH work block is 4 or 5, forwards to the arm9 function at 0x02090CD4 (WM_SetGameInfo shape) with (0, a, b, c, d, 1), the halfword arguments truncated. */
void func_021795D4(int a, int b, int c, int d);
extern WhPipeWork *g_021797A4;
extern u16 d_0217967C[2];
extern u16 d_02179680[2];
extern u8 d_02179678[3];

/*
 * Task states of the wireless pipe: func_0217727C stores the next task
 * function into work->task, the main loop calls it once per frame.  The
 * WH system states used below are the NitroSDK wh.c ones: 0 stop, 1 idle,
 * 2 scanning, 3 busy, 4 connected, 5 data sharing, 7 measure channel,
 * 9 error.
 */

/*
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 */
int func_02177C1C(void) { if (func_02178E4C() == 2) return 1; return 0; }

int func_02177C30(int data, unsigned int size, int callbackArg) { return func_02179368(data, size, callbackArg); }

unsigned int func_02177C3C(void) { return func_02178E38(); }

int func_02177C44(void) { return func_021795A4(); }

void func_02177C4C(WhPipeWork *work)
{
    u16 connectModeTable[2];
    WhPipeNetInit *net;
    int channel;

    int state = func_02178E4C();

    connectModeTable[0] = d_0217967C[0];
    connectModeTable[1] = d_0217967C[1];
    if (state == 7) {
        net = func_0203D798();
        work->beaconStatus = 0;
        work->resumeFlag = 0;
        work->scanning = 0;
        work->running = 0;
        channel = func_02179024();
        if (work->channel == 0xFF)
            work->channel = channel;
        else
            channel = work->channel;
        if (net->bRenewTgid != 0)
            work->tgid = func_0208F1B4();
        func_0217778C();
        func_02179288(connectModeTable[net->bMPMode], work->tgid, channel, net->maxConnectNum - 1);
        func_0217727C(g_021797A4, 0);
    }
}

void func_02177CE4(WhPipeWork *work) { if (func_02178E4C() == 1 && func_02178E84() != 0) func_0217727C(g_021797A4, func_02177C4C); }

int func_02177D0C(int autoChannel)
{
    WhPipeWork *work = g_021797A4;
    if (work->task != 0)
        return 0;
    if (autoChannel != 0)
        work->channel = 0xff;
    func_0217933C(func_021775AC);
    g_021797A4->running = 1;
    func_0217727C(g_021797A4, func_02177CE4);
    return 1;
}

void func_02177D58(u8 *buf, u32 len)
{
    WhPipeWork *work = g_021797A4;
    WhPipeNetInit *net = func_0203D798();
    if (work != 0 && net != 0) {
        ((WhPipeBeacon *)buf)->checksum = func_0203F1FC(buf + 2, len - 2);
        func_020862F0(buf, len);
        if (func_02178E4C() == 1) {
            func_02178E28(buf, (u16)len);
            return;
        }
        func_021795D4((int)buf, len, net->ggid, work->tgid);
    }
}

void func_02177DB0(WhPipeWork *work)
{
    WhPipeNetInit *net = func_0203D798();
    u16 connectModeTable[2];
    connectModeTable[0] = d_02179680[0];
    connectModeTable[1] = d_02179680[1];
    if (func_02178E4C() == 1 || func_02178E4C() == 2) {
        func_02178524(connectModeTable[net->bMPMode], (const u16 *)g_021797A4->targetBssid, 0);
        func_021795C0((unsigned int)func_0217771C);
        func_0217933C(func_021775AC);
        g_021797A4->running = 1;
        func_0217727C(g_021797A4, 0);
    }
}

int func_02177E20(u32 unused, u8 *bssid, u32 entryIndex, void (*onConnected)(void))
{
    func_0203D798();
    if (g_021797A4->task != 0)
        return 0;
    if (func_02178E4C() == 2) {
        g_021797A4->scanning = 0;
        func_021788FC();
    }
    func_0217727C(g_021797A4, func_02177DB0);
    if (bssid != 0)
        func_02082D44(bssid, g_021797A4->targetBssid, 6);
    else
        func_02082D44(g_021797A4->entry[entryIndex].bssid, g_021797A4->targetBssid, 6);
    g_021797A4->onConnected = onConnected;
    return 1;
}

void func_02177E9C(WhPipeWork *work) { if (func_02178E4C() == 0) { func_02179158(); func_02177704(); } }

int func_02177EB0(int endCallback) { if (func_02179570((void (*)(int))endCallback) != 0) { func_0217727C(g_021797A4, func_02177E9C); return 1; } return 0; }

int func_02177ED4(void) { return 1; }

int func_02177ED8(void) { return 0; }

/*
 * evidence: func_02179328 stores its argument unchanged; the caller passes a function pointer.
 */
void func_02177EDC(int acceptChild) { if (acceptChild != 0) func_02179328(func_02177ED4); else func_02179328(func_02177ED8); }

void func_02177EFC(WhPipeWork *work)
{
    if (g_021797A4->timerPaused == 0) {
        if (work->searchTimer != 0)
            work->searchTimer--;
        if (work->searchTimer == 0) {
            if (func_02179498() != 0)
                func_0217727C(g_021797A4, func_02177FF0);
        }
    }
}

void func_02177F48(WhPipeWork *work)
{
    u8 channelTable[3];
    if (func_02177AA8() != 0) {
        channelTable[0] = d_02179678[0];
        channelTable[1] = d_02179678[1];
        channelTable[2] = d_02179678[2];
        work->searchChannelIndex = func_020056EC(3);
        if (work->searchChannelIndex >= 3)
            work->searchChannelIndex = 0;
        func_0217778C();
        if (func_02179288(0, work->tgid, channelTable[work->searchChannelIndex], 1) != 0) {
            work->searchTimer = func_020056EC(0x98) + 0x3C;
            func_0217727C(g_021797A4, func_02177EFC);
        }
    }
}

void func_02177FC4(WhPipeWork *work) { work->searchTimer--; if (work->searchTimer == 0) { func_021788FC(); func_0217727C(g_021797A4, func_02177F48); } }

void func_02177FF0(WhPipeWork *work)
{
    if (func_02178E4C() == 1) {
        if (func_021785B4((u32)func_021773E0, 0, 0) != 0) {
            work->searchTimer = func_020056EC(0x28) + 0x3C;
            func_0217727C(g_021797A4, func_02177FC4);
        }
    }
}

int func_02178034(void)
{
    WhPipeWork *work = g_021797A4;
    if (work == 0)
        return 0;
    func_021780E4(0);
    func_0217758C((u8 *)work);
    func_02177560();
    func_0217933C(func_021775AC);
    work->running = 1;
    func_0217727C(g_021797A4, func_02177FF0);
    return 1;
}

void func_0217807C(void)
{
    if (g_021797A4->watchDisconnect)
        g_021797A4->disconnectDetected = 1;
}

u8 func_02178098(u8 i)
{
    WhPipeWork *work = g_021797A4;

    if (work != 0 && work->entryAge[i] != 0)
        return work->entry[i].beacon.kind;
    return 0;
}

void func_021780C4(u32 i)
{
    WhPipeWork *work = g_021797A4;
    func_02178714(work->entry[i].channel, work->entry[i].bssid);
}

void func_021780E4(int a)
{
    if (g_021797A4)
        g_021797A4->joinLockFrames = 20;
}

void func_021780FC(u8 value)
{
    if (g_021797A4) {
        g_021797A4->beaconStatus = value;
        func_0217778C();
    }
}

void func_02178118(u32 callback, u32 value)
{
    if (g_021797A4) {
        g_021797A4->notifyFn = (void *)callback;
        g_021797A4->notifyArg = value;
    }
}
