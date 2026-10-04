/*
 * function: func_021E1E44
 * address:  0x021E1E44
 * packet:   pkt_ov093_021E1E44
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *
 * The tail after the pop (movs r1,#4; str r1,[r0]; ldr r0,[pc]; bx lr) is an
 * unlabelled follower stub.
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);

void func_021E1E44(int u, int a, int b)
{
    u8 *r;
    u8 *s;

    if (b == func_021D775C(3)) {
        if (func_021D5BDC(func_021C7CF4((int *)a, b), 9) == 0) {
            r = func_021C88A4(a, 0x17, b);
            r[8] = b;
            *(int *)(r + 4) = 9;
            func_021C88C8((void *)a, r);
            s = func_021C88A4(a, 4, b);
            func_021C8838(s + 4, 2, 0x411);
            func_021C8860((struct S *)(s + 4), b);
            func_021C88C8((void *)a, s);
        }
    }
}
