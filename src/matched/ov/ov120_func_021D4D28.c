/*
 * function: func_021D4D28
 * address: 0x021D4D28
 * packet: pkt_ov120_021D4D28
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6988 0x021D6988 thumb ov120
 *   func_021D7AF4 0x021D7AF4 thumb ov120
 *   func_021B6498 0x021B6498 thumb ov067
 *   func_021D7C10 0x021D7C10 thumb ov120
 *   func_020362DC 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_021D69F4 0x021D69F4 thumb ov120
 *   func_020355D8 0x020355D8 arm
 *   func_021D4474 0x021D4474 thumb ov120
 *   func_021D6A9C 0x021D6A9C thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4CC4 0x021D4CC4 thumb ov120
 *   func_02035C08 0x02035C08 arm
 *   d_021D88D0 0x021D88D0 data a4
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   func_021D7EC4 0x021D7EC4 thumb ov120
 *   func_021D68C4 0x021D68C4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   func_021D588C 0x021D588C thumb ov120
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021D6988(u8 *p);
extern int func_021D7AF4(char *p);
extern int func_021B6498(u8 *);
extern int func_021D7C10(char *p);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_021D69F4(u8 *p, void *q, u32 n);
extern void func_020355D8(u8 v);
extern void func_021D4474(int, u8 *);
extern void func_020061E4(u32 a);
extern int func_021D6A9C(u8 *p, u32 n);
extern void func_0202822C(char *p, int v);
extern void func_021D4244(int, int, int);
extern void func_021D4CC4(u8 *);
extern u32 func_02035C08(const void *);
extern const u32 d_021D88D0[];
extern void func_021B63D0(u8 *);
extern int func_021B6448(u8 *);
extern void func_02040588(u32, u32);
extern void func_021D7EC4(u8 *p);
extern void func_021D68C4(u8 *);
extern void func_02028148(u8 *p);
extern void func_02041B6C(u32);
extern void func_021D588C(u8 *);
void func_021D4D28(u8 *p)
{
    int changed = 0;
    int done = 0;
    u8 *q = (u8 *)func_021D6988(*(void **)(p + 0x3c));
    if (func_021D7AF4(*(void **)(p + 0x40))) {
        if (func_021B6498(q) == 0) {
            func_021D7C10((char *)(*(int *)(p + 0x40)));
            if (func_020362DC() != 0 && func_020355C4() == 1) {
                func_021D69F4(*(void **)(p + 0x3c), *(void **)(p + 0x34), *(int *)(p + 0x160));
                func_020355D8(changed);
                return;
            }
            if (func_020362DC() == 0x20) func_021D4474(0, p);
            if (func_020362DC() == 0x10) func_021D4474(1, p);
            if (func_020362DC() == 0x40) {
                func_020061E4(0x548);
                changed = 1;
                if (*(int *)(p + 0x160) != 2) --*(int *)(p + 0x160);
            }
            if (func_020362DC() == 0x80) {
                func_020061E4(0x548);
                changed = 1;
                if (*(int *)(p + 0x160) != 5) ++*(int *)(p + 0x160);
            }
            if (func_020362DC() == 1 && *(int *)(p + 0x160) == 5) {
                func_020061E4(0x54c);
                func_021D6A9C(*(void **)(p + 0x3c), *(int *)(p + 0x160));
                func_0202822C(*(void **)(p + 0x34), 1);
                func_021D4244((int)p, (int)func_021D4CC4, 0x4ca);
                return;
            }
            if (changed)
                func_021D69F4(*(void **)(p + 0x3c), *(void **)(p + 0x34), *(int *)(p + 0x160));
            if (func_02035C08(d_021D88D0) == 0) {
                func_020355D8(1);
                func_020061E4(0x54c);
                func_0202822C(*(void **)(p + 0x34), 1);
                func_021D4244((int)p, (int)func_021D4CC4, 0x4f2);
                return;
            }
        }
        func_021B63D0((u8 *)func_021D6988(*(void **)(p + 0x3c)));
        if (func_021B6448((u8 *)func_021D6988(*(void **)(p + 0x3c))) == 1) done = 1;
        if (done) {
            int zero = 0;
            func_02040588(4, 0);
            func_021D69F4(*(void **)(p + 0x3c), *(void **)(p + 0x34), 9);
            func_021D7EC4(*(void **)(p + 0x40));
            func_021D68C4(*(u8 **)(p + 0x3c));
            func_02028148(*(void **)(p + 0x34));
            *(int *)(p + 0x34) = zero;
            func_02041B6C(5);
            func_021D4244((int)p, (int)func_021D588C, 0x50b);
        }
    }
}
