/*
 * function: func_0203DBB0
 * address:  0x0203DBB0
 * packet:   pkt_0203DBB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * PARKED AT MATCH.  Every concrete byte is right (68 of 68).  The one open
 * site is the ABS32 to the expression string at 0x020A7D48; the file string
 * 0x020A7D34 next to it resolves as `literal x20`, this one appears in a
 * single pool image-wide - this function's own - and its start is not fixed
 * by a preceding terminator, so `string` cannot attest it either.
 *   blocker: data address 0x020A7D48 has no witness (same shape as
 *            docs/idioms/a-string-after-a-data-table-has-no-witness.md)
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02082D44  0x02082D44  arm
 *   file_020A7D34  0x020A7D34  data
 *   file_020A7D48  0x020A7D48  data
 *
 * Copies six bytes into the record at object +0x94 + (index << 3), or reports
 * at line 0x109 (265) when there is no object.  The body is the fall-through
 * arm and the report is the branch arm, so the source is the `!= 0` if with
 * the report as its else - not the early-return spelling, which would put the
 * report inline before the body.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203DBB0.c \
 *       --func func_0203DBB0 --addr 0x0203DBB0 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02034714(const char *file, u32 line, const char *msg);
extern void func_02082D44(int a0, int a1, int a2);
extern const char file_020A7D34[];
extern const char file_020A7D48[];

void func_0203DBB0(u32 a0, u32 a1)
{
    u8 *p = *(u8 **)(0x21469F0);

    if (p != 0)
        func_02082D44((int)(p + 0x94 + (a1 << 3)), (int)a0, 6);
    else
        func_02034714(file_020A7D34, 0x109, file_020A7D48);
}
