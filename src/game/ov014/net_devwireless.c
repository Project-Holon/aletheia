/*
 * file:     net_devwireless.c
 * unit:     yes
 * function: GFL_NET_DEVWIRELESS_GetDeviceTable, GFL_NET_DEVWIRELESS_Setup, GFL_NET_DEVWIRELESS_Begin, GFL_NET_DEVWIRELESS_Update, GFL_NET_DEVWIRELESS_OnShutdownDone, GFL_NET_DEVWIRELESS_Cleanup, GFL_NET_DEVWIRELESS_ClearScanList
 * address:  0x02177020
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021796A0  0x021796A0  data  a4
 *   sDevWirelessWork 0x021797A0  data   a4
 *   sFileNetDevWireless 0x0217976C  data   a1
 *   func_02030734  0x02030734  arm
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   NET_WHPIPE_Create  0x02177280  thumb  ov014
 *   NET_WHPIPE_IsIdle 0x02177AA8 thumb ov014
 *   NET_WHPIPE_Update 0x0217796C thumb ov014
 *   NET_WHPIPE_RequestFinalize 0x021776C4 thumb ov014
 *   func_020307B0 0x020307B0 arm
 *   NET_WHPIPE_RequestEnd 0x02177EB0 thumb ov014
 *   NET_WHPIPE_ClearEntries 0x02177560 thumb ov014
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

/* State of the wireless device layer; one block, allocated by the setup slot. */
typedef struct DevWirelessWork {
    u32 setupParam;                         /* second argument of the setup slot, kept for the owner */
    void (*onEndedCallback)(void *result);  /* called once the pipe has shut down */
} DevWirelessWork;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 *GFL_NET_GetInitParam(void);
extern int NET_WHPIPE_Create(int a, int b, u32 c, int d);
extern int NET_WHPIPE_IsIdle(void);
extern void NET_WHPIPE_Update(u32);
extern int NET_WHPIPE_RequestFinalize(void);
extern u32 func_020307B0(void *p);
extern int NET_WHPIPE_RequestEnd(int a);
extern void NET_WHPIPE_ClearEntries(void);
void *GFL_NET_DEVWIRELESS_GetDeviceTable(void);
int GFL_NET_DEVWIRELESS_Setup(int heapId, u32 setupParam, int wmParam, int userData);
int GFL_NET_DEVWIRELESS_Begin(void (*doneCallback)(void));
int GFL_NET_DEVWIRELESS_Update(u32 tick);
int GFL_NET_DEVWIRELESS_RequestDisconnect(void);
int GFL_NET_DEVWIRELESS_OnShutdownDone(void *result);
int GFL_NET_DEVWIRELESS_Cleanup(void (*endCallback)(void *));
int GFL_NET_DEVWIRELESS_ClearScanList(void);
int GFL_NET_DEVWIRELESS_UnusedSlot7(void);
int GFL_NET_DEVWIRELESS_UnusedSlot8(void);
int GFL_NET_DEVWIRELESS_UnusedSlot9(void);
extern DevWirelessWork *sDevWirelessWork;
extern char sFileNetDevWireless[];


/* Returns the device table (slot array at 0x021796A0) that the net core calls into. */
void *GFL_NET_DEVWIRELESS_GetDeviceTable(void)
{
    return (void *)0x021796A0;
}



/* Slot 1: allocates the layer and starts the pipe; wmParam goes to the WH init, userData to the pipe callbacks. */
int GFL_NET_DEVWIRELESS_Setup(int heapId, u32 setupParam, int wmParam, int userData)
{
    int forListening;
    DevWirelessWork *work;

    if (sDevWirelessWork != 0)
        return 0;
    work = func_02030734(heapId, 8, 1, sFileNetDevWireless, 0xb4);
    forListening = 1;
    sDevWirelessWork = work;
    work->setupParam = setupParam;
    if (GFL_NET_GetInitParam()[0x65] != 5)
        forListening = 0;
    return NET_WHPIPE_Create(heapId, wmParam, userData, forListening);
}


/*
 * Slot 2: nothing to start asynchronously; calls the done callback at once.
 * extent: trailing two-byte zero alignment padding.
 */
int GFL_NET_DEVWIRELESS_Begin(void (*doneCallback)(void))
{
    if (doneCallback != 0) {
        NET_WHPIPE_IsIdle();
        doneCallback();
    }
    return NET_WHPIPE_IsIdle();
}


/*
 * Slot 3: per-frame update with the tick counter.
 * extent: lead and unlabelled tail-call follower at 0x021770A0.
 */
int GFL_NET_DEVWIRELESS_Update(u32 tick)
{
    NET_WHPIPE_Update(tick);
    return 1;
}


/* Slot 4: asks the pipe to shut down (same target as slot 21). */
int GFL_NET_DEVWIRELESS_RequestDisconnect(void)
{
    return NET_WHPIPE_RequestFinalize();
}


/* Pipe end callback: reports to the owner, frees the layer. */
int GFL_NET_DEVWIRELESS_OnShutdownDone(void *result)
{
    if (sDevWirelessWork->onEndedCallback != 0)
        sDevWirelessWork->onEndedCallback(result);
    func_020307B0(sDevWirelessWork);
    sDevWirelessWork = 0;
    return 1;
}


/* Slot 5: ends the pipe; endCallback runs when the end has finished. */
int GFL_NET_DEVWIRELESS_Cleanup(void (*endCallback)(void *))
{
    if(sDevWirelessWork != 0) {
        sDevWirelessWork->onEndedCallback = endCallback;
        return NET_WHPIPE_RequestEnd((int)GFL_NET_DEVWIRELESS_OnShutdownDone);
    }
    return 1;
}


/* Slot 6: forgets all scanned parents. */
int GFL_NET_DEVWIRELESS_ClearScanList(void) { NET_WHPIPE_ClearEntries(); return 1; }


int GFL_NET_DEVWIRELESS_UnusedSlot7(void) { return 1; }


int GFL_NET_DEVWIRELESS_UnusedSlot8(void) { return 1; }


int GFL_NET_DEVWIRELESS_UnusedSlot9(void) { return 1; }
