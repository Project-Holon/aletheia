/*
 * function: sub_0200545C
 * address:  0x0200545C
 * packet:   pkt_02005454
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020AA194      0x020AA194  data
 *   s_gfl_use_c     0x020A7004  data
 *   d_0209D8A0      0x0209D8A0  data
 *   d_0209D8B0      0x0209D8B0  data
 *   d_020A6C58      0x020A6C58  data
 *   sub_02005768    0x02005768  thumb
 *   func_0202F768   0x0202F768  thumb
 *   func_0202F774   0x0202F774  thumb
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   OS_GetArenaHi       0x0208656C  arm
 *   OS_GetArenaLo       0x02086580  arm
 *   OS_InitAlloc        0x02086A50  arm
 *   OS_SetArenaLo       0x02086774  arm
 *   OS_CreateExtraHeap  0x02086B98  arm
 *   OS_AllocFromHeap    0x020868E0  arm
 *   OS_GetConsoleType   0x02085CBC  arm
 *   sub_020056D0    0x020056D0  thumb
 *   sub_0200566C    0x0200566C  thumb
 *   func_020057AC   0x020057AC  thumb
 *
 * gfl_use.c, the file's __FILE__ anchor function: system boot set-up.  On a
 * non-TWL console, carve the main arena into the OS heap (Hi read before Lo,
 * hence the named local), create the extra heap and take a 0x3F00 block
 * from it; then the heap system on the console's arena table, the graphics,
 * card and sound bring-up, the three heap-tracked allocations at lines
 * 0x117 / 0x119 / 0x11C of gfl_use.c (s_gfl_use_c is the __FILE__ pointer),
 * and the task/callback installs.
 *
 * Closed in wave 14.  The pool was misread by one word in the older note
 * (docs/notes/sub_0200545C.c.txt): 0x020A6C58 is func_02048CEC's argument
 * and 0x02005769 (sub_02005768, src/matched/unit_0200575C.c) is
 * func_020346EC's third, and the two words 0x0202F769 / 0x0202F775 are
 * Thumb pointers to two unlabelled callback leaves of time_icon.c, filed
 * EXACT this wave as src/matched/func_0202F768.c and func_0202F774.c, which
 * is what attests them (`matched`).  d_0209D8A0 / d_0209D8B0 now resolve on
 * sole-ref.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200545C.c \
 *       --func sub_0200545C --addr 0x0200545C --cc 1.1p1 --thumb
 */

typedef unsigned char      u8;
typedef unsigned int       u32;
typedef unsigned long long u64;

struct GflHeaps {
    u64   seed;
    u64   mul;
    u64   add;
    void *unk18;
    void *unk1C;
    void *unk20;
    void *unk24;
};

struct GflSys {
    void *unk00;
    u32   unk04;
    void (*unk08)(void *);
    u32   unk0C;
    struct GflHeaps *heaps;
    void *unk14;
};

extern struct GflSys g_020AA194;
extern u8 s_gfl_use_c[];
extern u8 d_0209D8A0[];
extern u8 d_0209D8B0[];
extern u8 d_020A6C58[];

extern u32   OS_IsRunOnTwl(void);
extern void *OS_GetArenaHi(u32 id);
extern void *OS_GetArenaLo(u32 id);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, u32 n);
extern void  OS_SetArenaLo(u32 id, void *lo);
extern u32   OS_CreateExtraHeap(u32 id);
extern void *OS_AllocFromHeap(u32 id, u32 heap, u32 size);
extern u32   OS_GetConsoleType(void);

extern void  func_02030608(void *a, u32 b, u32 c, u32 d);
extern void  func_02030BA4(u32 a);
extern void  func_0203064C(u32 a, u32 b, u32 c);
extern void  func_02030678(void *a, u32 b, u32 c);
extern void  func_0203EF5C(u32 a);
extern void  func_02048CEC(void *a, u32 b);
typedef signed int     s32;
struct Ctx;
extern void func_02034E24(u32 heap, u8 mode);
extern void  func_02034978(void);
extern void  func_020346EC(u32 a, u32 b, void (*c)(void));
extern void func_0203499C(u32 heap, int n0, int n1, int n2);
extern void  func_0203129C(u32 a);
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, unsigned short tag);
extern u32   func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void  sub_020056D0(void);
extern void  func_0204E5E8(u32 a);
extern void  func_020316C8(u32 a, void (*b)(void), void (*c)(void));
extern void  func_0204E130(u32 a);
extern void  func_0203F3B4(void);
extern void  sub_0200566C(void);
extern void  func_020057AC(void);
extern void func_0204E6F4(s32 a);
extern void  sub_02005768(void);
extern void  func_0202F768(void);
extern void  func_0202F774(void);

void sub_0200545C(void)
{
    if (OS_IsRunOnTwl() == 0) {
        void *hi = OS_GetArenaHi(0);
        OS_SetArenaLo(0, OS_InitAlloc(0, OS_GetArenaLo(0), hi, 1));
        g_020AA194.unk04 = OS_CreateExtraHeap(0);
        g_020AA194.unk14 = OS_AllocFromHeap(0, g_020AA194.unk04, 0x3F00);
    }

    if (OS_IsRunOnTwl() != 0) {
        func_02030608(d_0209D8A0, 2, 0xAD, 0);
    } else {
        func_02030608(d_0209D8B0, 2, 0xAD, 0);
    }

    func_02030BA4(0x2000);
    func_0203064C(1, 7, 0x25000);

    if (OS_IsRunOnTwl() == 0) {
        func_02030678(g_020AA194.unk14, 0x3F00, 9);
    } else {
        func_0203064C(1, 9, 0x3F00);
    }

    func_0203EF5C(0);
    func_02048CEC(d_020A6C58, 0xEB);
    func_02034E24(0, 0);

    if (OS_GetConsoleType() & 0x81000000) {
        func_02034978();
    } else {
        func_020346EC(0, 0, sub_02005768);
    }

    func_0203499C(0, 0x10, 4, 4);
    func_0203129C(0);

    g_020AA194.heaps = func_02030734(0, 0x28, 0, (const char *)s_gfl_use_c, 0x117);
    g_020AA194.heaps->unk1C = func_02030734(0, func_02030CB0(4), 0, (const char *)s_gfl_use_c, 0x119);
    g_020AA194.heaps->unk18 = func_02030CBC(4, g_020AA194.heaps->unk1C);
    g_020AA194.heaps->unk24 = func_02030734(0, func_02030CB0(0x10), 0, (const char *)s_gfl_use_c, 0x11C);
    g_020AA194.heaps->unk20 = func_02030CBC(0x10, g_020AA194.heaps->unk24);

    sub_020056D0();
    func_0204E5E8(0);
    func_020316C8(7, func_0202F768, func_0202F774);
    func_0204E130(0);
    func_0203F3B4();
    g_020AA194.unk0C = 0;
    sub_0200566C();
    func_020057AC();
    func_0204E6F4(2);
}
