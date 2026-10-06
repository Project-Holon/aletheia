/*
 * function: func_021C3438
 * address: 0x021C3438
 * packet: pkt_ov093_021C3438
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: declare the unsigned iterator after the event flags, keep its
 * postincrement in the call operand, and spell the filter as nested arms.
 * ABI: C3660 is the labelled Thumb veneer to ov095 0689CC70(S*,u32),
 * returning an unchanged full-word id or zero. i uses unsigned full-word
 * increment (346C), with no assumed bound. The id is used as an address.
 * C3670 forwards to 0689D5C8; C3680/C3690 forward all four inputs to
 * 0689CBB8, including the full-word id and the halfword amount.
 * CC8D8 returns the entire pre-mutation 32-bit Lock; 34FA saves all r0,
 * 363A forwards it in r1 to CC95C, whose own body stores the whole word.
 * Both original line arguments, 0x216b and 0x219c, are preserved.
 * C6948 receives the live fourth halfword loaded at3494 despite its own
 * three-input body; BFA00's pointer slot receives that same 32-bit payload.
 * C6948/C572C keep their matched caller's u32 parameter; the ldrh at each
 * site supplies a zero-extended halfword without any asserted value range.
 * C36E8 reads sixth input by ldrh at36EE and forwards full fifth input
 * to C16F8 at3712. C1828 r1 is the unchanged C3670 result (351E/35D8):
 * its own u8 parameter is widened under the observed-full-width rule.
 * half is initialized unconditionally by352A before C1678, which may
 * return0 without writing. Both event flags are initialized3536/3538.
 * symbols:
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C3660 0x021C3660 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021C6948 0x021C6948 thumb ov093
 *   func_021BFA00 0x021BFA00 thumb ov093
 *   func_021C572C 0x021C572C thumb ov093
 *   func_021CC8B8 0x021CC8B8 thumb ov093
 *   func_021C5774 0x021C5774 thumb ov093
 *   func_021CC8D8 0x021CC8D8 thumb ov093
 *   func_021C6A9C 0x021C6A9C thumb ov093
 *   func_021C3670 0x021C3670 thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D6D7C 0x021D6D7C thumb ov093
 *   func_021C3720 0x021C3720 thumb ov093
 *   func_021C3680 0x021C3680 thumb ov093
 *   func_021C1678 0x021C1678 thumb ov093
 *   func_021C36A0 0x021C36A0 thumb ov093
 *   func_021C36E8 0x021C36E8 thumb ov093
 *   func_021C3690 0x021C3690 thumb ov093
 *   func_021C1828 0x021C1828 thumb ov093
 *   func_021C4218 0x021C4218 thumb ov093
 *   func_021C1C88 0x021C1C88 thumb ov093
 *   func_021C4F64 0x021C4F64 thumb ov093
 *   func_021C88E4 0x021C88E4 thumb ov093
 *   func_021CC95C 0x021CC95C thumb ov093
 */
#include "../include/Obj21086.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Flags { u8 pad[5]; u8 a:1; u8 rest:7; };
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021C3660(void *, u32);
extern int func_021D5B68(void *);
extern u8 func_021D5440(u8 *p);
extern int func_021BF324(u8 *, u8 *, u8 *);
extern int func_021C6948(u8 *, u8 *, u8 *, u32);
extern int func_021BFA00(u8 *, u8 *, u8 *, void *);
extern void func_021C572C(u8 *, u8 *, u32);
extern u32 func_021CC8B8(u32 *, u32);
extern void func_021C5774(u8 *, u8 *);
extern u32 func_021CC8D8(void *, int);
extern int func_021C6A9C(u8 *, u8 *, u8 *, u16);
extern u8 func_021C3670(u8 *, u8);
extern int func_021D7AD4(int);
extern u32 func_021D6D7C(u8 *);
extern u16 func_021C3720(u8 *, u8 *, u16 *, int);
extern void func_021C3680(void *, u32, u16, int);
extern int func_021C1678(u8 *, u8 *, u8 *, u32, u16 *);
extern void func_021C36A0(u8 *, u8 *, u16 *, int);
extern void func_021C36E8(u8 *, u8 *, u16 *, int, int, u16);
extern void func_021C3690(void *, u32, u16, int);
extern void func_021C1828(u8 *p, u8 b, u8 *x, u8 *c, u8 *q, u16 w);
extern void func_021C4218(u8 *, u8 *, u8 *, u8 *, u32, u32, u32, u32);
extern void func_021C1C88(u8 *, u8 *, u32, u8 *, u32);
extern int func_021C4F64(u8 *, u8 *);
extern int func_021C88E4(u8 *);
extern void func_021CC95C(u32 *p, u32 v, int line);

void func_021C3438(u8 *p, u16 *q, u8 *a, u8 *out)
{
    u8 speed;
    u8 *b;
    u8 id;
    u32 item;
    u32 lock;
    u8 tag;
    int category;
    int event1, event2;
    u32 i;
    u16 half;
    struct Flags *flags;
    i = 0;
    speed = (u8)func_021D59B4(a, 15);
    for (;;) {
        int kind;
        b = (u8 *)func_021C3660(out, i++);
        if (b == 0) break;
        if (func_021D5B68(b)) continue;
        id = func_021D5440(b);
        if (!func_021BF324(p, a, b)) {
            if (func_021C6948(p, a, b, *q)) {
                func_021C572C(p, b, *q);
                continue;
            }
        }
        if (func_021BFA00(p, a, b, (void *)(u32)*q)) {
            func_021C572C(p, b, *q);
            continue;
        }
        if (speed < (u8)func_021D59B4(b, 15)) {
            func_021C5774(p, b);
            continue;
        }
        item = func_021CC8B8((u32 *)(p + 0x1f88), id);
        if (item == 0) {
            func_021C5774(p, b);
            continue;
        }
        lock = func_021CC8D8(p + 0x1d74, 0x216b);
        if (func_021C6A9C(p, a, b, *q)) {
            tag = func_021C3670(p + 0x1ab8, func_021D5440(a));
            half = func_021D59B4(b, 13);
            category = func_021D7AD4(item);
            event1 = 0;
            event2 = 0;
            flags = *(struct Flags * *)&((struct Obj21086 *)p)->f4A8;
            if (!flags->a) flags->a = 1;
            if (func_021D6D7C(b)) {
                half = func_021C3720(p, b, q, category);
                func_021C3680(out, (u32)b, half, 1);
                event1 = 1;
            } else {
                kind = func_021C1678(p, a, b, 1, &half);
                if (kind == 0) {
                    func_021C36A0(p, b, q, category);
                } else {
                    func_021C36E8(p, b, q, category, kind, half);
                    func_021C3690(out, (u32)b, half, 0);
                    event2 = 1;
                }
            }
            if (!event1) func_021C1828(p, tag, a, b, (u8 *)q, half);
            func_021C4218(p, a, b, (u8 *)q, item, half, 0, event1);
            if (event2 || event1) func_021C1C88(p, a, (u32)out, (u8 *)q, 0);
            func_021C4F64(p, b);
        } else if (!func_021C88E4(p)) {
            func_021C572C(p, b, *q);
        }
        func_021CC95C((u32 *)(p + 0x1d74), lock, 0x219c);
    }
}
