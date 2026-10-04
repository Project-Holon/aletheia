/*
 * function: func_021D9BF8
 * address:  0x021D9BF8
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D9BF8   0x021D9BF8  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5D50   0x021D5D50  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *
 * Three gates on func_021D775C (4, 0x46 zero, 0x45 non-zero); the signed
 * func_021D5D50(func_021C7CF4(b,c),1) must be positive and its byte goes to the
 * record's +0xc.  Record #0xe also sets the 1<<23 header flag and the two-
 * string tail (c) at +0x18.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D5D50(s8 *p, int i);
void *func_021C88A4(int a, int k, int b);
void func_021C8838(void *p, int a, int b);
struct S;
void func_021C8860(struct S *p, unsigned int a);
void func_021C88C8(void *a, void *b);

void func_021D9BF8(void *a, int b, int c)
{
    void *r;
    u8 *p;

    if (c != func_021D775C(4))
        return;
    if (func_021D775C(0x46) != 0)
        return;
    if (func_021D775C(0x45) == 0)
        return;
    r = func_021C7CF4((int *)b, c);
    if (func_021D5D50(r, 1) <= 0)
        return;
    p = func_021C88A4(b, 0xe, c);
    *(u32 *)(p + 4) = 1;
    *(u8 *)(p + 0xc) = func_021D5D50(r, 1);
    *(u8 *)(p + 0xe) = 1;
    *(u8 *)(p + 0xf) = 1;
    *(u8 *)(p + 0x10) = c;
    *(u8 *)(p + 0xd) = 1;
    *(u32 *)p |= 1 << 23;
    func_021C8838(p + 0x18, 2, 0x1e1);
    func_021C8860((struct S *)(p + 0x18), c);
    func_021C88C8((void *)b, p);
}
