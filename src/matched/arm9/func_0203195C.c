/*
 * unit:     no
 * function: func_0203195C
 * address:  0x0203195C
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A four-store teardown of one record: release the object at +0x2c, the one
 * at +0x138 unconditionally, the one at +0x34 only when the byte at +0x1d is
 * exactly 1, then the record itself.  The release callee is the overruled
 * SDK address 0x020307B0 (layout/symbols_sdk.txt calls it ENV_SetResourceSet,
 * the game code proves otherwise); it is already matched, which is what
 * attests the three PC24 sites.  0x020339B4, the +0x2c argument's own
 * destructor, was matched in the same wave and attests the fourth.
 *
 * The leaf follower at 0x02031994 (a two-field getter, no prologue) carries
 * no label, so the inferred extent from this address runs long: EXACT*.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203195C.c \
 *       --func func_0203195C --addr 0x0203195C --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020307B0(void *p);
extern void func_020339B4(int *p);

void func_0203195C(u8 *p)
{
    func_020339B4((int *)(*(u32 *)(p + 0x2c)));
    func_020307B0(*(void **)(p + 0x138));
    if (p[0x1d] == 1) {
        func_020307B0(*(void **)(p + 0x34));
    }
    func_020307B0(p);
}
