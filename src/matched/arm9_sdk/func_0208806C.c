/*
 * function: func_0208806C
 * address:  0x0208806C
 * packet:   pkt_02087FBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * 172 bytes, 0x0208806C..0x02088118, every concrete byte reproduced (0
 * differing bytes of 172); the diff is empty apart from the one wildcarded
 * call field at +0x04.
 *
 * Blocked on the `label` class, and it is a one-address wall: func_02088150
 * is reached by exactly one branch anywhere in the image, the `bl` at
 * +0x04 of this function, which is inside the compared range, so `label`
 * refuses it and `matched` has no EXACT entry at 0x02088150 yet.  The
 * compared range cannot be shrunk to exclude it (the call is the function's
 * first statement).  It graduates the day 0x02088150 is matched -- nothing
 * in this C changes.  Note 0x02088150 carries a `.global func_02088150`
 * label in asm/arm9/src/027_0208475C.s, so only the outside-branch witness
 * is missing.
 *
 * The other four calls resolve through `label` with plenty of outside
 * witnesses.  func_02004632 had to be declared at 0x02004632 (thumb), not
 * 0x02004630: the target is a BLX, and match.py rewrites BL against BLX from
 * the declared ISA, so a wrong address leaves the H bit wrong and reports a
 * concrete one-byte DIFF (0xFB vs 0xEB in byte 3 of the branch) rather than
 * an unresolved wildcard.
 *
 * symbols:
 *   func_02088150  0x02088150  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02004632  0x02004632  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02088118  0x02088118  arm
 */

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

extern int  func_02088150(void);
extern void func_02082D44(u32 bus, u32 p, u32 n);
extern u32  func_02004632(u32 a, u32 p, u32 n);
extern void MI_CpuFill8(u32 p, u32 c, u32 n);
extern void func_02088118(void);

int func_0208806C(void)
{
    u32 *base;
    u32  old;

    if (func_02088150() == 0)
        return -1;

    base = (u32 *)0x02151384;
    if (base[2] == 0)
        return -1;

    func_02082D44(0x02000000, base[2], 0x300);

    old = *(u16 *)(base[2] + 0x10);
    *(u16 *)(base[2] + 0x10) = 0;
    *(u16 *)(base[2] + 0x10) = func_02004632(0xffff, base[2], 0x300);

    if (old != *(u16 *)(base[2] + 0x10)) {
        MI_CpuFill8(base[2], 0, 0x300);
        func_02088118();
        return 0;
    }

    *(u8 *)(base[2] + 9) &= 0xfe;
    base[1] = 1;
    return 0;
}
