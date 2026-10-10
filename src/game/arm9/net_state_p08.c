/*
 * file:     net_state_p08.c
 * unit:     yes
 * function: func_0203C238, func_0203C2B0
 * address:  0x0203C238
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 */
typedef signed char   s8;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int  u32;

typedef unsigned long long u64;
typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetState {
    u32  f00;
    u32  f04;
    void (*f08)(struct NetState *s);
    MATHRandContext64 rng;
    u32  f24;
    void (*f28)(void);
    void (*f2C)(u32 a);
    u32  err[4];
    u8   mac[6];
    u16  f46;
    s8   flag;
    u8   pad49;
    u8   f4A;
    u8   f4B;
    u8   f4C;
    u8   f4D;
    u8   f4E;
    u8   f4F;
    u8   f50;
    u8   f51;
    u8   pad52;
    u8   f53;
    u8   pad54[2];
    u8   f56;
    u8   addr[6];
    u8   pad5D[7];
};

extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern void func_0203AD80(struct NetState *s, void *p, u32 v, int line);
extern void func_02037D78(void);
extern void func_020398B4(u32 a);
extern void func_02039834(u32 a);
extern u32 func_0203778C(u32 p);
void func_0203C238(struct NetState *p);
int func_0203C2B0(int a);
extern struct NetState *g_021469DC;


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C238.c \
 *       --func func_0203C238 --addr 0x0203C238 --cc 1.1p1 --arm
 */
void func_0203C238(struct NetState *p)
{
    u8 *s = func_0203D788();
    u8 *q = func_0203D798();

    if ((*(u32 (**)(int, u32, u32))(*(u32 *)(s + 0x340) + 0x50))(p->flag, q[0x60], 0) != 0)
        return;

    func_02037D78();
    func_020398B4((u32)s);
    func_02039834((u32)s);
    func_0203AD80(g_021469DC, (void *)0x0203C0F4, 0, 0x5AC);
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C2B0.c \
 *       --func func_0203C2B0 --addr 0x0203C2B0 --cc 1.1p1 --arm
 */
int func_0203C2B0(int a)
{
    if (a != -1) {
        if (func_0203778C((u32)a) == 0)
            return 0;
    }

    g_021469DC->flag = a;
    func_0203AD80(g_021469DC, (void *)0x0203C238, 0, 0x5C4);
    return 1;
}
