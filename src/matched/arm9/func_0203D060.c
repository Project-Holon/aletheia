/*
 * function: func_0203D060
 * address:  0x0203D060
 * packet:   pkt_0203CF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x0203DA7C, whose only caller in the image is this function, and
 * 0x0203DA7C lies past this packet (another lane's), so it cannot be matched
 * from here.
 *
 * The trailing `*` is the usual unlabelled-follower case and not a byte
 * difference: the inferred extent runs on to 0x0203D0D0 because the three
 * eight-byte ARM long-branch veneers at 0x0203D0AC, 0x0203D0B8 and 0x0203D0C4
 * save no `lr` and so carry no label.  They want seeding into
 * layout/function_starts.txt, which is the integrator's file.
 *   blocker: `bl` to 0x0203DA7C has no witness outside this range (single
 *            caller, address outside this packet)
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D060.c \
 *       --func func_0203D060 --addr 0x0203D060 --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern int func_0203DA4C(void);
extern void *func_0203DA7C(void *a0, void *a1, void *a2);
extern void func_0203BA98(u16 a0, u32 a1, u8 a2);

void func_0203D060(u32 a, u32 b, u32 c)
{
    u8 *s = func_0203D788();
    u32 v = a;

    if (func_0203DA4C() == 1)
        v = (u32)func_0203DA7C((void *)a, (void *)b, (void *)c);

    func_0203BA98(*(u16 *)(s + 0x56), v, 1);
}
