/*
 * file:     net_state_p31.c
 * unit:     yes
 * function: func_0203C600, func_0203C628, func_0203C65C
 * address:  0x0203C600
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
 *   func_0203C0F4  0x0203C0F4  arm
 *   func_0203C464  0x0203C464  arm
 *   func_0203D788   0x0203D788  arm
 *   func_0203D798   0x0203D798  arm
 *   func_0203AEEC   0x0203AEEC  arm
 */
struct Card0203C600 {
    unsigned char pad[8];
    void *cb;
};

struct Card0203C628 {
    unsigned char pad[8];
    void *cb;
};

typedef unsigned char u8;

typedef unsigned int  u32;

extern void func_0203C0F4(void *p);
extern int func_0203C464(int a0, int a1, int a2, int a3);
extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern void func_0203AEEC(u8 *p);
int func_0203C600(void);
int func_0203C628(void);
void func_0203C65C(u8 *p);
extern struct Card0203C600 *g_021469DC;


/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4.
 */
int func_0203C600(void)
{
    return g_021469DC->cb == (void *)func_0203C0F4;
}


/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4 or func_0203C464.
 */
int func_0203C628(void)
{
    void *cb = g_021469DC->cb;
    return cb == (void *)func_0203C0F4 || cb == (void *)func_0203C464;
}


/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C65C.c \
 *       --func func_0203C65C --addr 0x0203C65C --cc 1.1p1 --arm
 */
void func_0203C65C(u8 *p)
{
    u8 *s;

    func_0203D798();
    s = func_0203D788();

    (*(void (**)(u32))(*(u32 *)(s + 0x340) + 0x0C))(1);

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x78))() != 0) {
        (*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0);
        func_0203AEEC(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x6C))() == 0) {
        (*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0);
        func_0203AEEC(p);
        return;
    }

    if ((*(u32 (**)(void))(*(u32 *)(s + 0x340) + 0x74))() == 0)
        return;

    (*(u32 (**)(u32))(*(u32 *)(s + 0x340) + 0x14))(0);
    func_0203AEEC(p);
}
