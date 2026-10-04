/*
 * function: func_02039ACC
 * address:  0x02039ACC
 * packet:   pkt_02039A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02039160  0x02039160  arm
 *   func_02039338  0x02039338  arm
 *   func_020395EC  0x020395EC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D788  0x0203D788  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02087C6C  0x02087C6C  arm
 *
 * Seeds the current record's +0x4a state byte: state 2 re-arms the eight-slot
 * table through func_0203D3A8 with a 3-byte payload built in a 12-byte stack
 * buffer, any state below 2 is stepped up by one, anything else is left alone.
 * The early `beq` on func_02039160() is the R4 shared-tail lever: the first
 * exit branches to the function's last `return 0` instead of predicating
 * `moveq r0, #0` / `popeq` (which cost 12 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039ACC.c \
 *       --func func_02039ACC --addr 0x02039ACC --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02039160(u32 mode);
extern u16 func_02039338(void);
extern int func_020395EC(u8 *p);
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern void *func_0203D788(void);
extern void *func_0203D798(void);
extern void func_02087C6C(void *p);

int func_02039ACC(void)
{
    u8 buf[12];
    u8 *p;
    u8 v;
    u8 *q;
    u32 f;

    p = (u8 *)func_020399A8();
    v = (u8)func_020395EC(p);
    func_0203D788();
    q = func_0203D798();
    if (func_02039160(func_02039338()) != 0) {
        f = *(u8 *)(p + 0x4a);
        if (f == 2) {
            func_02087C6C(buf);
            buf[6] = v;
            buf[7] = *(u8 *)(q + 0x67);
            buf[8] = *(u16 *)(q + 0x6e);
            return func_0203D3A8((struct Entry *)p, 3, 9, (u32)buf);
        }
        if (f < 2)
            *(u8 *)(p + 0x4a) = f + 1;
    }
    return 0;
}
