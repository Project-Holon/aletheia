/*
 * function: BTL_SETUP_SetupWild
 * address:  0x0201347C
 * packet:   pkt_02013360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020076D0   0x020076D0  thumb
 *   GAME_DATA_GetBoxManager   0x0201293C  thumb
 *   BTL_SETUP_Clear   0x020130C4  thumb
 *   BTL_SETUP_SetStatusFlag   0x02013144  thumb
 *   BTL_SETUP_SetPlayerParty   0x0201333C  thumb
 *   BTL_SETUP_InitCommon   0x02013360  thumb
 *   POKEPARTY_Create   0x0201A920  thumb
 *   POKEPARTY_GetCapacity   0x0201AA14  thumb
 *   POKEPARTY_GetCount   0x0201AA18  thumb
 *   POKEPARTY_Copy   0x0201AC2C  thumb
 *
 * btl_setup.c.  The link-battle variant of the setup builder: the same
 * three shared writers as BTL_SETUP_SetupDemo, then the object is put in mode 0
 * and a consistency check on the +0x24 slot decides whether flag 0x40 is
 * set.
 *
 * The documented near miss in docs/notes/pkt_02013360.c.txt compiled 122
 * bytes against 120 and missed on 108 of them.  Two leftover-register
 * readings are what close it, and both are the same idiom, see
 * docs/idioms/a-loop-carried-value-in-a-callees-argument-register-names-the-arity.md.
 *
 * (1) POKEPARTY_Copy takes the POKEPARTY_Create result as a second argument.
 * The original writes `adds r1, r0, #0; str r1, [r4, #0x28]`, which reads
 * as a gratuitous register copy before the store.  It is not: r1 is the
 * second argument of the guarded POKEPARTY_Copy call below, so the value has
 * to reach r1 anyway and the store then sources it from there.  The
 * declaration has to be variadic, `void POKEPARTY_Copy(u32 a, ...)`, because
 * the other call site of this family (in BTL_SETUP_SetupDemo, EXACT) passes two
 * registers while some pass one; a fixed two-parameter declaration emits a
 * spurious `movs r1, #0`.  This is the same finding
 * docs/notes/pkt_02013528.c.txt reached for BTL_SETUP_SetupDemo.
 *
 * (2) func_020076D0 takes THREE arguments, and its first is the return
 * value of the GAME_DATA_GetBoxManager call immediately above it.  The original sets
 * only r1 and r2 (`add r1, sp, #4; add r2, sp, #0`) and leaves r0 holding
 * what GAME_DATA_GetBoxManager returned.  Declaring it with two parameters puts the
 * two pointers in r0/r1 and is a two-byte, two-instruction miss; declaring
 * GAME_DATA_GetBoxManager as returning u32 and passing that result explicitly gives
 * the original bytes with no extra `adds`, because the value is already in
 * r0 and the compiler elides the copy.
 *
 * The two out-parameters are declared x then y but passed &x as the SECOND
 * argument and &y as the third: x lives at sp+4 and y at sp+0, which is the
 * later-declaration-at-the-lower-address rule, see
 * docs/idioms/local-declaration-order-is-stack-order.md.
 *
 * EXACT*: all 118 code bytes reproduce (10 of 10 relocation sites
 * resolved); the inferred extent ran two bytes long only on the
 * `movs r0, r0` alignment pad at 0x020134F2 before BTL_SETUP_SetupTrainerBase.  Never a
 * byte difference.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BTL_SETUP_SetupWild.c \
 *       --func BTL_SETUP_SetupWild --addr 0x0201347C --cc 1.1p1 --thumb
 */
#include "../include/Obj00155.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
extern void BTL_SETUP_Clear(u8 *p);
struct Party;
struct Rec534;
extern void BTL_SETUP_InitCommon(u8 *o, void *a1, const void *a2);
extern int BTL_SETUP_SetPlayerParty(int a0, int a1, int a2);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern u32  POKEPARTY_GetCount(void *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern void BTL_SETUP_SetStatusFlag(char *p, int v);

void BTL_SETUP_SetupWild(u8 *a0, void *a1, u32 a2, u32 a3, u32 a4, u16 a5)
{
    u32 x;
    u32 y;
    u32 r;
    u32 t;
    u32 u;

    BTL_SETUP_Clear(a0);
    BTL_SETUP_InitCommon(a0, a1, (const void *)a3);
    BTL_SETUP_SetPlayerParty((int)a0, (int)a1, a5);
    r = (u32)POKEPARTY_Create(a5);
    ((struct Obj00155 *)a0)->f28 = r;
    if (a2 != 0) {
        POKEPARTY_Copy((const struct Rec534 *)a2, (struct Rec534 *)r);
    }
    ((struct Obj00155 *)a0)->f4 = a4;
    ((struct Obj00155 *)a0)->f0 = 0;
    t = POKEPARTY_GetCount((void *)((struct Obj00155 *)a0)->f24);
    if (t != POKEPARTY_GetCapacity((void *)(((struct Obj00155 *)a0)->f24))) {
        return;
    }
    u = GAME_DATA_GetBoxManager(a1);
    x = 0;
    y = 0;
    if (func_020076D0((void *)u, (int *)(&x), (int *)(&y)) == 0) {
        BTL_SETUP_SetStatusFlag((char *)a0, 0x40);
    }
}
