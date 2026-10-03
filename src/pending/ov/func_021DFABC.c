/*
 * function: func_021DFABC
 * address:  0x021DFABC
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH (parked)
 *
 * BLOCKER: 48 bytes: the (u8) truncation of func_021DCFF8(a,2) lands in r1 directly in the image (lsls r0,#0x18; lsrs r1,r0,#0x18) but mwcc copies r0 to r1 first (adds r1,r0,#0; lsls r1,r1,#0x18; lsrs r1,r1,#0x18), 2 bytes longer.  Probes: callee 2nd param declared u8, a u8 local for the cast -- both worse.
 *
 * symbols:
 *   func_021DFABC   0x021DFABC  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_0201BEB8   0x0201BEB8  thumb
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021DCFF8   0x021DCFF8  thumb ov093
 *   func_021D7B74   0x021D7B74  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Gate on func_021D775C(4) and on func_021D775C(0x46) being zero, then the
 * (u16) of func_021D775C(0x12) must satisfy the ARM helper at 0x0201BEB8.
 * Record #7 takes func_021D775C(3) in its +6 byte, the halfword of
 * func_021D7B74(func_021C7CF4(b, that byte), (u8)func_021DCFF8(a,2)) at +4,
 * and the two-string tail seeded with the byte.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
int func_0201BEB8(int a, int b);
void *func_021C88A4(int a, int k, int b);
void *func_021C7CF4(int a, int b);
int func_021DCFF8(void *a, int k);
extern int func_021D7B74(u8 *p, u32 k);
void func_021C8838(void *p, int a, int b);
void func_021C8860(void *p, int a);
void func_021C88C8(int a, void *p);

void func_021DFABC(void *a, int b, int c)
{
    void *r;
    u8 *p;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_0201BEB8((u16)func_021D775C(0x12), 0) == 0)
        return;
    p = func_021C88A4(b, 7, c);
    *(u8 *)(p + 6) = func_021D775C(3);
    r = func_021C7CF4(b, *(u8 *)(p + 6));
    *(u16 *)(p + 4) = func_021D7B74(r, func_021DCFF8(a, 2));
    func_021C8838(p + 0xc, 2, 0x6a << 2);
    func_021C8860(p + 0xc, *(u8 *)(p + 6));
    func_021C88C8(b, p);
}
