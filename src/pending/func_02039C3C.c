/*
 * function: func_02039C3C
 * address:  0x02039C3C
 * packet:   pkt_02039A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * blocker:  four instructions: the boolean is built in r1 with a preset `mov r1, #1` where the original builds it in r0 with the conditional moves alone
 *
 * symbols:
 *   func_020395EC  0x020395EC  arm
 *
 * Seeds a transfer: the first argument is the payload selector, the record's
 * +0x48 byte is set to 0xFF and the +0x49 byte to whether the query against
 * the source object answers anything other than 0xFF.  The two stores happen
 * before the call, and 0xFF reaches its byte straight from a `mov r2, #255`
 * because it is `mov`-encodable in that role.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039C3C.c \
 *       --func func_02039C3C --addr 0x02039C3C --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020395EC(u8 *p);

void func_02039C3C(u8 *p, u16 v)
{
    *(u16 *)(p + 0x46) = v;
    p[0x48] = 0xFF;
    p[0x49] = func_020395EC(p) != 0xFF;
}
