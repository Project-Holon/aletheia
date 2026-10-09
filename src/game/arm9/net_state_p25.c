/*
 * file:     net_state_p25.c
 * unit:     yes
 * function: func_0203C304, func_0203C35C, func_0203C3B4, func_0203C3EC
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
struct NetState;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed char   s8;

struct Sys {
    u8 pad[0x48];
    s8 flag;
};

typedef struct Hdr021469DC {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int v8;
} Hdr021469DC;

extern void *func_0203D788(void);
extern void func_02037D78(void);
extern void func_020398B4(u8 *h);
extern void func_02039834(u8 *h);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern void func_0203C0F4(void *p);
extern void func_0203C0B4(void);
extern void func_0203C068(void);
extern void func_0203C060(void);
extern void func_0203C064(void);
u32 func_0203C304(void);
u32 func_0203C35C(void);
void func_0203C3B4(void);
int func_0203C3EC(void);
extern struct Sys *g_021469DC;
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

    *(signed char *)(*(u32 *)((char *)(0x21469DC)) + 0x48) = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203C0F4, 0, (int)0x5D9);
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

    *(signed char *)(*(u32 *)((char *)(0x21469DC)) + 0x48) = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)0x203C0F4, 0, (int)0x5FD);
    return 1;
}



void func_0203C3B4(void)
{
    g_021469DC->flag = -1;
    func_0203AD80((struct NetState *)g_021469DC, (void *)str_0203C238, 0, 0x60d);
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
    Hdr021469DC **pp = (Hdr021469DC **)(&g_021469DC);
    unsigned int v = (*pp)->v8;

    if (v == (unsigned int)(void *)func_0203C0F4) {
        return 0;
    }
    if (v == (unsigned int)(void *)func_0203C0B4) {
        return 1;
    }
    if (v == (unsigned int)(void *)func_0203C068) {
        return 3;
    }
    if (v == (unsigned int)(void *)func_0203C060) {
        return 4;
    }
    if (v == (unsigned int)(void *)func_0203C064) {
        return 5;
    }
    return 2;
}
