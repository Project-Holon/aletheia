/*
 * file:     unit_021573C4_p01.c
 * unit:     yes
 * function: func_021573C4, func_021575DC
 * address:  0x021573C4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OSi_ReferSymbol                  0x02004eb0 arm
 *   OS_GetTick                       0x020870d0 arm
 *   WCM_GetMacAddress                0x021665e4 arm
 *   OS_CreateThread                  0x020853c0 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_CreateAlarm                   0x02087254 arm
 *   id_string                        0x020050ac data
 *   wfailed                          0x021a826c data
 *   empty_func                       0x021573b8 arm ov009
 *   default_link_is_on               0x021573bc arm ov009
 *   CPSMyMac                         0x021a82d4 data
 *   tcpip_thread                     0x021a86a4 data
 *   helper_threads_priority          0x021a1c98 data
 *   tcpip                            0x0215a900 arm ov009
 *   tcpip_stack                      0x021a9c40 data
 *   scavenger_thread                 0x021a85e4 data
 *   scavenger                        0x0215b67c arm ov009
 *   scavenger_stack                  0x021a9440 data
 *   dacktimer_alarm                  0x021a82fc data
 *   dacktimer                        0x0215bbb0 arm ov009
 *   dacktimer_thread                 0x021a8524 data
 *   dacktimer_stack                  0x021a8c40 data
 *   func_02087988  0x02087988  arm
 *   func_0208574C  0x0208574C  arm
 *   func_02085868  0x02085868  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A85E4  0x021A85E4  data
 *   g_021A826C  0x021A826C  data
 */
#include "../../matched/include/G_021A85E4.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef struct {
    u32 mode;
    void *(*alloc)(u32);
    void (*free)(void *);
    void (*dhcp_callback)(void);
    int (*link_is_on)(void);
    u64 random_seed;
    u8 *lan_buf;
    u32 lan_buflen;
    u32 mymss;
    u32 requested_ip;
    u32 yield_wait;
} CPSConfig;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext32;

struct _OSThread { u8 opaque[0xc0]; };

struct OSiAlarm { u8 opaque[0x2c]; };

struct net_vars {
    char pad0[0x58];
    unsigned long calm;
};

extern void OSi_ReferSymbol(void *sym);
extern u64 OS_GetTick(void);
extern void WCM_GetMacAddress(u8 *macAddress);
extern void OS_CreateThread(struct _OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 prio);
extern void OS_WakeupThreadDirect(struct _OSThread *thread);
extern void OS_CreateAlarm(struct OSiAlarm *alarm);
extern unsigned long func_02087988(void);
extern int func_0208574C(void *thread);
extern void func_02085868(void *thread);
extern unsigned long func_0208799C(unsigned long state);
void func_021573C4(CPSConfig *config);
int func_021575DC(void);
extern char id_string[21];
extern struct _OSThread dacktimer_thread;
extern struct _OSThread scavenger_thread;
extern struct _OSThread tcpip_thread;
extern u8 dacktimer_stack[0x800];
extern u8 scavenger_stack[0x800];
extern u8 tcpip_stack[0x800];
extern struct G_021A85E4 g_021A85E4;
extern struct net_vars g_021A826C;


static inline void MATH_InitRand32(MATHRandContext32 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3;
}


static inline u32 MATH_Rand32(MATHRandContext32 *context, u32 max)
{
    context->x = context->mul * context->x + context->add;
    if (max == 0)
        return (u32)(context->x >> 32);
    else
        return (u32)(((context->x >> 32) * max) >> 32);
}


static void empty_func(void);

static int default_link_is_on(void);

static void tcpip(void *arg);

static void scavenger(void *arg);

static void dacktimer(void *arg);


static u8 ip_conflict = 0;

static u8 wfailed = 0;

static u16 eport = 0;

static u16 mymss = 0;

static u16 pingseq = 0;

static u16 ipid = 0;

static u32 wlan_buflen = 0;

static u32 scavenger_force_exit = 0;

static void *receiver_thread = 0;

u32 CPSMyIp = 0;

u32 CPSDhcpServerIp = 0;

static void *checkNConfig_callback = 0;

void (*CPSiFree)(void *) = 0;

static u32 sleep_save = 0;

u32 CPSGatewayIp = 0;

static void *scavenger_callback = 0;

static u32 offered_myip = 0;

u32 CPSNoIpReason = 0;

static u32 wlan_putpnt = 0;

static void (*dhcp_callback)(void) = 0;

static u32 yield_wait = 0;

static u8 *wlan_buf = 0;

u32 CPSNetMask = 0;

static int (*link_is_on)(void) = 0;

static u32 xid = 0;

static u32 lease_time = 0;

static u32 wlan_getpnt = 0;

u32 CPSDhcpMode = 0;

void *(*CPSiAlloc)(u32) = 0;

u8 CPSMyMac[6] = {0};

u32 CPSDnsIp[2] = {0};

MATHRandContext32 CPSiRand32ctx = {0};

static struct OSiAlarm dacktimer_alarm = {0};


static u32 helper_threads_priority = 10;


/*
 * notes:    EXACT 2026-10-01 after the two network.o static leaves its pool
 *           words name (empty_func 0x021573B8, default_link_is_on 0x021573BC) were
 *           seeded in layout/function_starts.txt, added to symbols_sdk.json and
 *           matched (user-approved; SDK denominator +2 functions / +12 B).
 *
 * 2026-10-01 (w3 lane14): 160 B -> 0 concrete.  What closed it:
 *   - .debug_line of network.o (CPS_Startup at line 400): the OS_GetTick call
 *     and the merged context stores sit on line 406, the second arm of a
 *     403-406 if/else, so the seed test is `if (config->random_seed != 0)`
 *     with the OS_GetTick arm in the else.  Same shape for mymss (419-422),
 *     dhcp_callback (425-428), link_is_on (429-432): if/else, not ternaries
 *     (ternary callbacks cost 161 B).  `wlan_getpnt = 0;` (435) and
 *     `wlan_putpnt = 0;` (436) are separate statements; this is what keeps
 *     the late zero web born at +0xD0 instead of hoisted with the early one.
 *   - CPSVars was separate network.o .bss statics anchored at `wfailed`
 *     (vendor symtab); declarations below reproduce the vendor offsets under
 *     1.1p1's per-size-group reshuffle (checked with readelf on a --keep tu.o).
 *   - Stacks/threads are extern: the vendor keeps them in their own .bss
 *     sections.  aligned(32) on the stacks (lever 15) is inert here.
 *
 * sdk:      CPS_Startup (libcps.TWL.HYB.a network.o)
 */
void func_021573C4(CPSConfig *config)
{
    OSi_ReferSymbol(id_string);
    if (config->random_seed != 0)
        MATH_InitRand32(&CPSiRand32ctx, config->random_seed);
    else
        MATH_InitRand32(&CPSiRand32ctx, OS_GetTick());
    if (config->alloc != 0 && config->free != 0) {
        CPSiAlloc = config->alloc;
        CPSiFree = config->free;
    } else {
        CPSiAlloc = (void *(*)(u32))empty_func;
        CPSiFree = (void (*)(void *))empty_func;
    }
    CPSDhcpMode = config->mode;
    if (config->mymss != 0)
        mymss = (u16)config->mymss;
    else
        mymss = 1460;
    offered_myip = config->requested_ip;
    yield_wait = config->yield_wait;
    if (config->dhcp_callback != 0)
        dhcp_callback = config->dhcp_callback;
    else
        dhcp_callback = empty_func;
    if (config->link_is_on != 0)
        link_is_on = config->link_is_on;
    else
        link_is_on = default_link_is_on;
    wlan_buf = config->lan_buf;
    wlan_buflen = config->lan_buflen;
    wlan_getpnt = 0;
    wlan_putpnt = 0;
    eport = (u16)(MATH_Rand32(&CPSiRand32ctx, 0xf88) + 0x400);
    WCM_GetMacAddress(CPSMyMac);
    ip_conflict = 0;
    OS_CreateThread(&tcpip_thread, tcpip, 0, tcpip_stack + sizeof(tcpip_stack), sizeof(tcpip_stack), helper_threads_priority);
    OS_CreateThread(&scavenger_thread, scavenger, 0, scavenger_stack + sizeof(scavenger_stack), sizeof(scavenger_stack), helper_threads_priority);
    OS_WakeupThreadDirect(&tcpip_thread);
    OS_WakeupThreadDirect(&scavenger_thread);
    OS_CreateAlarm(&dacktimer_alarm);
    OS_CreateThread(&dacktimer_thread, dacktimer, 0, dacktimer_stack + sizeof(dacktimer_stack), sizeof(dacktimer_stack), helper_threads_priority - 1);
}


/*
 * sdk:      CPS_CalmDown (libcps.TWL.HYB.a(network.o))
 */
int func_021575DC(void)
{
    unsigned long enable = func_02087988();
    int result = func_0208574C(((char *)&g_021A85E4));

    if (result == 0 && g_021A826C.calm == 0) {
        g_021A826C.calm = 1;
        func_02085868(((char *)&g_021A85E4));
    }
    func_0208799C(enable);
    return result;
}
