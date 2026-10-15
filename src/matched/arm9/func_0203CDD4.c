/*
 * function: GFL_NET_EndSession
 * address:  0x0203CDD4
 * packet:   pkt_0203CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Net teardown/mode dispatch.  Fetches the state record, snapshots four
 * fields, fires two optional callbacks through function-pointer fields,
 * runs the shared shutdown calls, clears a word of the global block and
 * then dispatches on the mode byte.
 *
 * THE DISPATCH BASE IS THE WHOLE PUZZLE, and it is worth stating plainly
 * because an off-by-one here costs a whole pass.  The image has:
 *
 *   0203CE3C  cmp   r8, #6
 *   0203CE40  addls pc, pc, r8, lsl #2
 *   0203CE44  b     #0x203ce78          <- NOT table[0]
 *   0203CE48  b     #0x203ce8c          <- table[0]
 *
 * `addls pc, pc, ...` reads pc as the instruction address PLUS 8, so the
 * base is 0x0203CE40 + 8 = 0x0203CE48 and entry k sits at 0x0203CE48 + 4k.
 * The word at 0x0203CE44, which LOOKS like the first table slot in a plain
 * byte diff, is the out-of-range fallthrough branch to the default arm.
 * Reading it as table[0] shifts every case by one and yields a residue that
 * no source-level edit can fix: the blocks all land at the right addresses
 * and only the dispatch words differ.  The true mapping is
 *
 *   0 -> break      1 -> f(b)    2 -> f(b)    3 -> f(c)
 *   4 -> f(c)       5 -> break   6 -> f(b)    default -> assert, return
 *
 * The assert arm must be spelled `default:`, not `case 0:`; with an
 * explicit case 0 the fallthrough word at 0x0203CE44 is wrong.
 *
 * PERMUTER RESULT (negative, and recorded because it is the evidence that
 * the residue was structural rather than an allocation tie):
 *   hill,   budget 800,  --types: 181 single mutations, none improved.
 *   anneal, budget 3000, --types: 3000 compiles in 128s, completely flat at
 *   asm=30 bytes-out=8 size=216/216, never once below the baseline.
 * Six different source orderings of the five arms were also measured by
 * hand and every one gave byte-identical output.  A residue that flat is
 * not a spelling problem, which is what sent the work back to the dispatch
 * arithmetic.
 *
 * NET_DEVICE_TABLE_Reset is THUMB and reached by `blx`; declaring it arm makes
 * match.py refuse the site outright (it checks the .thumb_func marker).
 * The gGFLNetMain store is written gGFLNetMain[2] rather than
 * *(u32 *)(0x021469E0 + 8): the constant-plus-offset form folds the +8
 * into the pool word and compiles to `str r1, [r0]`.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/GFL_NET_EndSession.c \
 *       --func GFL_NET_EndSession --addr 0x0203CDD4 --cc 1.1p1 --arm
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_HANDLE_ExitWork  0x020398B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02034714  0x02034714  arm
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   NET_DEVICE_TABLE_Reset  0x0200F234  thumb
 *   gGFLNetMain     0x021469E0  data
 *   str_020A7CA0   0x020A7CA0  data
 *   str_020A7CE8   0x020A7CE8  data
 */
#include "../include/Obj03452.h"
#include "../include/G_Singleton.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *GFL_NET_GetSession(void);
extern void GFL_NET_HANDLE_ExitWork(u8 *p);
extern u32 func_020307B0(void *p);
extern void func_020306F0(u32 a);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void UI_ClearKeepAwakeFlagsGlobal(u32 a);
extern void NET_DEVICE_TABLE_Reset(u32 a);
extern struct Singleton gGFLNetMain;
extern char str_020A7CA0[];
extern char str_020A7CE8[];

void GFL_NET_EndSession(void)
{
    u8 *s = GFL_NET_GetSession();
    void (*f)(u32);
    u16 a;
    u16 b;
    u16 c;
    u8 m;

    f = *(void (**)(u32))(s + 0x348);
    a = ((struct Obj03452 *)s)->f56;
    b = ((struct Obj03452 *)s)->f58;
    c = ((struct Obj03452 *)s)->f5A;
    m = s[0x65];

    if (f != 0)
        f(((struct Obj03452 *)s)->f34C);

    f = *(void (**)(u32))(s + 0x2C);
    if (f != 0)
        f(((struct Obj03452 *)s)->f34C);

    GFL_NET_HANDLE_ExitWork(s);
    NET_DEVICE_TABLE_Reset(m);
    func_020307B0(s);

    ((u32 *)&gGFLNetMain)[2] = 0;

    switch (m) {
    case 1:
    case 2:
    case 6:
        func_020306F0(b);
        break;
    case 3:
    case 4:
        func_020306F0(c);
        break;
    case 0:
    case 5:
        break;
    default:
        func_02034714(str_020A7CA0, 0xEE, str_020A7CE8);
        return;
    }

    func_020306F0(a);
    UI_ClearKeepAwakeFlagsGlobal(4);
}
