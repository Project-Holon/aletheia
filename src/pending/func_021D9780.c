/*
 * function: func_021D9780
 * address:  0x021D9780
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (parked)
 *
 * DIFF: codegen, 128/144 bytes.  Same per-arm stack-slot quirk: the image
 * copies the selected 4-byte table entry into one half of an 8-byte frame
 * (sp or sp+4 by the a1 test) and points r1 at that half, then registers
 * the pointer; the same C gets a single 4-byte slot and an extra callee-saved
 * register instead.  Blocker: codegen, not evidence.
 *
 * symbols:
 *   func_0204B404  0x0204B404  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021D8FA4  0x021D8FA4  thumb  ov119
 *   func_021E5B6C  0x021E5B6C  thumb  ov119
 *   func_021E219C  0x021E219C  thumb  ov119
 */

typedef unsigned short u16;

struct Pt {
    u16 x;
    u16 y;
};

extern int func_0204B404(int a, void *b, int c);
extern int func_020355C4(int a);
extern void func_0204B3DC(int a, int b);
extern int func_021D8FA4(void *p, int a);
extern void func_021E5B6C(void *p, int a, int b);
extern void func_021E219C(void *p, int a, int b, int c);

void func_021D9780(void *p, int a1, int a2)
{
    struct Pt buf;
    int v;

    if (a1 == 0)
        buf = *(struct Pt *)0x021E7580;
    else
        buf = *(struct Pt *)0x021E757C;
    v = func_020355C4(func_0204B404(*(int *)((char *)p + 0xf0c), &buf, 1));
    if (v != 0) {
        func_021E5B6C(p, a1, 0);
        func_0204B3DC(*(int *)((char *)p + 0xf0c), 0);
    } else {
        func_021E5B6C(p, a1, 1);
        func_0204B3DC(*(int *)((char *)p + 0xf0c), 1);
    }
    if (a2 != 0) {
        func_021E219C(p, func_021D8FA4(p, *(int *)((char *)p + 0x10a0)),
                      *(int *)((char *)p + 0x10a0), 1);
    }
}
