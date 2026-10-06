/*
 * file:     time_icon_p06.c
 * unit:     yes
 * function: sub_0202F170, func_0202F190, func_0202F1B4, func_0202F27C, func_0202F2AC, func_0202F2F4, func_0202F30C, func_0202F358
 * address:  0x0202F170
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_020A03C8      0x020A03C8  data
 *   func_020185F0   0x020185F0  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02018488  0x02018488  thumb
 *   func_0202F3AC  0x0202F3AC  thumb
 *   func_0202F41C  0x0202F41C  thumb
 *   func_0202F464  0x0202F464  thumb
 *   func_0202F47C  0x0202F47C  thumb
 *   func_0203F4E4   0x0203F4E4  arm
 *   func_02017E64   0x02017E64  thumb
 *   func_02017E88   0x02017E88  thumb
 *   func_02014034   0x02014034  thumb
 */
struct Sav;
struct RtcDate;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Entry {
    u16 a;
    u16 b;
};

typedef unsigned char  u8;

extern u32  func_020185F0(void *a0);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32 func_02018488(void *p, void *mail);
extern void func_0202F3AC(void *a0, u32 a1);
extern int func_0202F41C(int a0, int a1, int a2);
extern int func_0202F464(int a0);
extern void func_0202F47C(void *p);
extern void func_0203F4E4(struct RtcDate *date);
extern void func_02017E64(void *p, u32 id, u32 v);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern u32 func_02014034(u32 id);
u32 sub_0202F170(u16 key);
void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_0202F27C(void *a0);
void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_0202F2F4(void *a0, u32 a1);
void func_0202F30C(void *a0, u32 a1, u32 a2);
void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern struct Entry g_020A03C8[];



/*
 * Index of the entry whose first field matches, 0 when there is none.
 * Unsigned loop here, signed in sub_0202F144.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202F170.c \
 *       --func sub_0202F170 --addr 0x0202F170 --cc 1.1p1 --thumb
 */
u32 sub_0202F170(u16 key)
{
    u32 i;

    for (i = 0; i < 0x2E; i++) {
        if (g_020A03C8[i].a == key)
            return i;
    }
    return 0;
}




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F190.c \
 *       --func func_0202F190 --addr 0x0202F190 --cc 1.1p1 --thumb
 */
void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    func_0202F1B4((u32)((void *)func_020185F0(a0)), a1, a2, a3, a4);
}



/*
 * note:     time_icon.c seven-way mode switch around a func_02017DBC /
 *           func_02017DE4 bracket.  Closed in wave 16: the 129-byte residue
 *           of docs/notes/func_0202F1B4.c.txt was NOT an allocator tie but
 *           the source's gotos.  Every case is written out in full (no
 *           shared labels) and case 2's guard carries the call run in BOTH
 *           arms; 1.1p1's own cross-jumping then produces the image's
 *           `b` into case 0's func_0202F464/func_0202F47C tail, the kept
 *           `bne; b` pair in case 2, and the head that spills the selector
 *           and holds the fifth parameter in r7.  The call at +0x58 is
 *           attested by src/matched/func_0202F47C.c (same shard).
 *           0x7532 is a plain constant.
 */
void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    u32 h = func_02017DBC((struct Sav *)a);

    switch (b) {
    case 0:
        func_0202F2F4((void *)a, 0);
        func_0202F30C((void *)a, d, 1);
        func_0202F41C(a, c, e);
        func_0202F464(a);
        func_0202F47C((void *)a);
        break;
    case 1:
        func_0202F30C((void *)a, 0x7532, 1);
        func_0202F464(a);
        func_0202F47C((void *)a);
        break;
    case 2:
        if (func_02018488((void *)a, (void *)c) == 1) {
            func_0202F30C((void *)a, d, 1);
            func_0202F41C(a, c, e);
        } else {
            func_0202F3AC((void *)a, 1);
            func_0202F30C((void *)a, d, 1);
            func_0202F41C(a, c, e);
        }
        func_0202F47C((void *)a);
        break;
    case 3:
    case 4:
        break;
    case 5:
        func_0202F30C((void *)a, d, 0);
        func_0202F41C(a, c, e);
        func_0202F47C((void *)a);
        break;
    case 6:
        func_0202F30C((void *)a, d, 1);
        break;
    }
    func_02017DE4((struct Sav *)a, h);
}




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F27C.c \
 *       --func func_0202F27C --addr 0x0202F27C --cc 1.1p1 --thumb
 */
void func_0202F27C(void *a0)
{
    u32 buf[4];

    func_0203F4E4((struct RtcDate *)buf);

    func_02017E64(a0, 0x92, buf[0]);
    func_02017E64(a0, 0x93, buf[1]);
    func_02017E64(a0, 0x94, buf[2]);
}




/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F2AC.c \
 *       --func func_0202F2AC --addr 0x0202F2AC --cc 1.1p1 --thumb
 */
void func_0202F2AC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    if (func_02017E88(a0, 0xAA, 0) == 1)
        func_0202F358(a0, a1, a2, a3, a4, 0);
    else
        func_0202F358(a0, a1, a2, a3, a4, 1);
    func_0202F464((int)a0);
    func_02017E64(a0, 0x6D, 1);
}




void func_0202F2F4(void *a0, u32 a1)
{
    func_0202F358(a0, 0, 0, 0, 0, a1);
}



/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F30C.c \
 *       --func func_0202F30C --addr 0x0202F30C --cc 1.1p1 --thumb
 */
void func_0202F30C(void *a0, u32 a1, u32 a2)
{
    u32 buf[4];

    func_0203F4E4((struct RtcDate *)buf);

    if (func_02014034((u16)a1) == 1)
        func_0202F358(a0, 0x753E, buf[0], buf[1], buf[2], a2);
    else
        func_0202F358(a0, a1, buf[0], buf[1], buf[2], a2);
}



/*
 * Installs the four resource slots of one variant.  The base index is the
 * caller's u8 flag plus 0x95 for the first slot, then that same base times
 * three plus 0x8f/0x90/0x91 for the rest.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F358.c \
 *       --func func_0202F358 --addr 0x0202F358 --cc 1.1p1 --thumb
 */
void func_0202F358(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    u8 base = (a5 == 1);

    func_02017E64(a0, base + 0x95, a1);
    base = (u8)(base * 3);
    func_02017E64(a0, base + 0x8F, a2);
    func_02017E64(a0, base + 0x90, a3);
    func_02017E64(a0, base + 0x91, a4);
}
