/*
 * function: func_021E21F4
 * address:  0x021E21F4
 * packet:   pkt_ov093_021E21F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E896C  0x021E896C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *
 * Lever: func_021E896C returns a one-word struct (Word), which reserves the
 * third frame word (`sub sp, #0xc` with push {r4-r7, lr}); see
 * docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md.
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct QQ;
struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern u32 func_021D78AC(u32 range);
extern void *func_021C88A4(int a, int k, int b);
extern Word func_021E896C(int a, int b);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);

void func_021E21F4(void *u, int a, int b, int *p)
{
    u8 *r;
    u8 t;

    if (b == func_021D775C(2)) {
        if (func_021D62C4(func_021C7CF4((int *)a, b), 0x19) == 0 && p[6] == 0) {
            t = func_021D78AC(2) + 2;
            r = func_021C88A4(a, 0xc, b);
            *(int *)(r + 4) = 0x19;
            *(Word *)(r + 8) = func_021E896C(t, func_021D70A8(u));
            r[0xc] = 0;
            r[0xf] = b;
            func_021C88C8((void *)a, r);
            p[6] = 1;
            p[0] = t;
        }
    }
}
