/*
 * file:     net_state_p09.c
 * unit:     yes
 * function: func_0203C304, func_0203C35C, func_0203C3B4, func_0203C3EC, func_0203C464
 * address:  0x0203C304
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
 *   func_0203D788  0x0203D788  arm
 *   func_02037D78  0x02037D78  arm
 *   func_020398B4  0x020398B4  arm
 *   func_02039834  0x02039834  arm
 *   func_0203AD80  0x0203AD80  arm
 *   g_021469DC     0x021469DC  data
 *   str_0203C238   0x0203C238  data
 *   func_0203C0F4  0x0203C0F4  arm
 *   func_0203C0B4  0x0203C0B4  arm
 *   func_0203C068  0x0203C068  arm
 *   func_0203C060  0x0203C060  arm
 *   func_0203C064  0x0203C064  arm
 */
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed char   s8;

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
extern void func_02037D78(void);
extern void func_020398B4(u8 *h);
extern void func_02039834(u8 *h);
extern void func_0203AD80(struct NetState *s, void *p, u32 v, int line);
extern void func_0203C0F4(void *p);
extern void func_0203C0B4(void);
extern void func_0203C068(void);
extern void func_0203C060(void);
extern void func_0203C064(void);
u32 func_0203C304(void);
u32 func_0203C35C(void);
void func_0203C3B4(void);
int func_0203C3EC(void);
void func_0203C464(void);
extern struct NetState *g_021469DC;
extern const char str_0203C238[];




/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5D9, returning success.  The twin at 0x0203C35C is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C304.c  *       --func func_0203C304 --addr 0x0203C304 --cc 1.1p1 --arm
 */
u32 func_0203C304(void)
{
    u8 *h = func_0203D788();

    g_021469DC->flag = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80(g_021469DC, (void *)0x203C0F4, 0, (int)0x5D9);
    return 1;
}




/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5FD, returning success.  The twin at 0x0203C304 is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C35C.c  *       --func func_0203C35C --addr 0x0203C35C --cc 1.1p1 --arm
 */
u32 func_0203C35C(void)
{
    u8 *h = func_0203D788();

    g_021469DC->flag = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80(g_021469DC, (void *)0x203C0F4, 0, (int)0x5FD);
    return 1;
}




void func_0203C3B4(void)
{
    g_021469DC->flag = -1;
    func_0203AD80(g_021469DC, (void *)str_0203C238, 0, 0x60d);
}



/*
 * Unlabelled ARM leaf (saves no register, so disasm.py gives it no func_
 * label): a channel-id classifier that reads the pointer at g_021469DC, then
 * the u32 at +8 of the record, and maps five distinct table addresses to
 * 0/1/3/4/5 (anything else returns 2).
 *
 * The five constants sit in their own pool words at 0x0203C450..0x0203C460
 * and are each loaded with `ldr` from pc, so they are link-time absolute
 * (R_ARM_ABS32) values that the compiler cannot fold against one another.
 * They are spelled as the addresses of the matched arm9 functions that live
 * at those addresses, taken as integers, so each becomes its own relocation
 * and no `sub`/constant-fold is possible.
 */
int func_0203C3EC(void)
{
    void *v = g_021469DC->f08;

    if (v == func_0203C0F4) {
        return 0;
    }
    if (v == func_0203C0B4) {
        return 1;
    }
    if (v == func_0203C068) {
        return 3;
    }
    if (v == func_0203C060) {
        return 4;
    }
    if (v == func_0203C064) {
        return 5;
    }
    return 2;
}


void func_0203C464(void)
{
    func_0203D788();
    func_0203AD80(g_021469DC, (void *)0x203C0F4, 0, 0x637);
}
