/*
 * function: func_021573C4
 * address:  0x021573C4
 * packet:   (none, pending)
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss: register allocation, see notes)
 * notes:    config r5 vs r4; the u64 add-hi zero is hoisted into r6 before the OS_GetTick branch in the target, CSEd late into r4 here
 * blocker:  188 concrete bytes, size 536/536: one early register choice
 *           cascades.  The image keeps config in r4 and the context in r5 and
 *           materialises the u64 add high zero into r6 (a callee-saved reg,
 *           since the value is live across the conditional OS_GetTick) before
 *           the seed test; 1.1p1 lets the context take r6 and sinks the zero
 *           into r4/r0 after the call, shifting almost every later operand by
 *           one.  w7: re-measured, not re-spelled; the fix would need the
 *           front end to hoist the 64-bit add-half zero across the branch.
 *
 * lane 6 (wave 10): still 188 B. Image has TWO separate zero webs (r6 hoisted above the seed branch
 *           for the u64 add-high word, then r4 born after the last config read for the getpnt/putpnt/
 *           flag01/thread-arg zeros); ours merges them into one early web. Measured no better: all six
 *           store orders in MATH_InitRand32, seed as a named u64 local (two shapes), a `u32 zero = 0`
 *           declaration initialiser feeding the stores (188), chained or swapped getpnt/putpnt (187).
 *
 * sdk:      CPS_Startup (libcps.TWL.HYB.a network.o)
 * symbols:
 *   func_02004EB0                    0x02004eb0 arm
 *   OS_GetTick                       0x020870d0 arm
 *   WCM_GetMacAddress                0x021665e4 arm
 *   OS_CreateThread                  0x020853c0 arm
 *   OS_WakeupThreadDirect            0x02085868 arm
 *   OS_CreateAlarm                   0x02087254 arm
 *   g_020050AC                       0x020050ac data
 *   g_021A826C                       0x021a826c data
 *   func_021573B8                    0x021573b8 arm ov009
 *   func_021573BC                    0x021573bc arm ov009
 *   g_021A82D4                       0x021a82d4 data
 *   g_021A86A4                       0x021a86a4 data
 *   g_021A1C98                       0x021a1c98 data
 *   func_0215A900                    0x0215a900 arm ov009
 *   g_021AA440                       0x021aa440 data
 *   g_021A85E4                       0x021a85e4 data
 *   func_0215B67C                    0x0215b67c arm ov009
 *   g_021A9C40                       0x021a9c40 data
 *   g_021A82FC                       0x021a82fc data
 *   func_0215BBB0                    0x0215bbb0 arm ov009
 *   g_021A8524                       0x021a8524 data
 *   g_021A9440                       0x021a9440 data
 */

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

struct CPSVars {
    u8 pad00;
    u8 flag01;
    u8 pad02[2];
    u16 mymss;
    u16 eport;
    u8 pad08[4];
    u32 dhcp_mode;
    u8 pad10[4];
    void *(*alloc)(u32);
    int (*link_is_on)(void);
    u8 pad1c[4];
    u8 *wlan_buf;
    u32 yield_wait;
    void (*dhcp_callback)(void);
    u8 pad2c[0x38 - 0x2c];
    u32 requested_ip;
    u8 pad3c[0x44 - 0x3c];
    void (*free)(void *);
    u8 pad48[0x5c - 0x48];
    u32 wlan_buflen;
    u32 wlan_putpnt;
    u32 wlan_getpnt;
    u8 pad68[0x78 - 0x68];
    MATHRandContext32 rand;
};

struct _OSThread;

extern struct CPSVars g_021A826C;
extern u8 g_020050AC[];
extern u8 g_021A82D4[];
extern u8 g_021A86A4[];
extern u32 g_021A1C98;
extern u8 g_021AA440[];
extern u8 g_021A85E4[];
extern u8 g_021A9C40[];
extern u8 g_021A82FC[];
extern u8 g_021A8524[];
extern u8 g_021A9440[];
extern void func_02004EB0(void *sym);
extern u64 OS_GetTick(void);
extern void WCM_GetMacAddress(u8 *mac);
extern void OS_CreateThread(void *thread, void (*func)(void *), void *arg, void *stack, u32 size, u32 prio);
extern void OS_WakeupThreadDirect(void *thread);
extern void OS_CreateAlarm(void *alarm);
extern void func_021573B8(void);
extern int func_021573BC(void);
extern void func_0215A900(void *arg);
extern void func_0215B67C(void *arg);
extern void func_0215BBB0(void *arg);

void func_021573C4(CPSConfig *config)
{
    func_02004EB0(g_020050AC);
    MATH_InitRand32(&g_021A826C.rand, config->random_seed ? config->random_seed : OS_GetTick());
    if (config->alloc != 0 && config->free != 0) {
        g_021A826C.alloc = config->alloc;
        g_021A826C.free = config->free;
    } else {
        g_021A826C.alloc = (void *(*)(u32))func_021573B8;
        g_021A826C.free = (void (*)(void *))func_021573B8;
    }
    g_021A826C.dhcp_mode = config->mode;
    g_021A826C.mymss = config->mymss ? config->mymss : 0x5b4;
    g_021A826C.requested_ip = config->requested_ip;
    g_021A826C.yield_wait = config->yield_wait;
    g_021A826C.dhcp_callback = config->dhcp_callback ? config->dhcp_callback : func_021573B8;
    g_021A826C.link_is_on = config->link_is_on ? config->link_is_on : func_021573BC;
    g_021A826C.wlan_buf = config->lan_buf;
    g_021A826C.wlan_buflen = config->lan_buflen;
    g_021A826C.wlan_getpnt = 0;
    g_021A826C.wlan_putpnt = 0;
    g_021A826C.eport = (u16)(MATH_Rand32(&g_021A826C.rand, 0xf88) + 0x400);
    WCM_GetMacAddress(g_021A82D4);
    g_021A826C.flag01 = 0;
    OS_CreateThread(g_021A86A4, func_0215A900, 0, g_021AA440, 0x800, g_021A1C98);
    OS_CreateThread(g_021A85E4, func_0215B67C, 0, g_021A9C40, 0x800, g_021A1C98);
    OS_WakeupThreadDirect(g_021A86A4);
    OS_WakeupThreadDirect(g_021A85E4);
    OS_CreateAlarm(g_021A82FC);
    OS_CreateThread(g_021A8524, func_0215BBB0, 0, g_021A9440, 0x800, g_021A1C98 - 1);
}
