/*
 * function: func_021E7388
 * address:  0x021E7388
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH (parked)
 *
 * BLOCKER: 108 bytes: the scan loop.  The image does n = func_021D775C(5); i = <pooled zero>; beq end; do{...}while(++i<n) -- the counter's zero is loaded from a literal pool word (0x021E740C) and the n==0 test is the beq on the adds; the natural for(i=0;i<n;i++) gives movs r5,#0 plus a separate cmp r7,#0; bls pre-test and a movs r5,#0, so the whole loop is shifted.
 *
 * symbols:
 *   func_021E7388   0x021E7388  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Gate on func_021D775C(3); func_021D775C(5) then bounds a scan: for each
 * key func_021D775C(i+6) whose func_021D59B4(func_021C7CF4(b,k),0x10) is not
 * 0x36, record #0x1f is published as a two-string record with the constant
 * 0x56 at +4.  The counter is unsigned, the third argument lives on the stack.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int a, int b);
int func_021D59B4(void *p, int k);
void *func_021C88A4(int a, int k, int b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(void *p, int a);
void func_021C88C8(int a, void *p);

void func_021E7388(void *a, int b, int c)
{
    u32 i;
    int n;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    n = func_021D775C(5);
    if (n == 0)
        return;
    for (i = 0; i < n; i++) {
        if (func_021D59B4(func_021C7CF4(b, (u8)func_021D775C(i + 6)), 0x10) == 0x36)
            continue;
        p = func_021C88A4(b, 0x1f, c);
        *(u8 *)(p + 6) = func_021D775C(i + 6);
        *(u16 *)(p + 4) = 0x56;
        func_021C8838(p + 0xc, 2, 0x195);
        func_021C8860(p + 0xc, *(u8 *)(p + 6));
        func_021C8860(p + 0xc, *(u16 *)(p + 4));
        func_021C88C8(b, p);
    }
}
