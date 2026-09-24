/*
 * function: func_021E781C
 * address:  0x021E781C
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E781C   0x021E781C  thumb ov093
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021D57FC   0x021D57FC  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *
 * Gate on func_021D775C(3); the (u8) of func_021D775C(6) keys func_021C7CF4,
 * whose result is halfword-stored through func_021D57FC in record #0x14.  A
 * second record #4 gets the 4<<22 flag in its header word and the two-string
 * tail (c and the key).
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int a, int b);
void *func_021C88A4(int a, int k, int b);
int func_021D57FC(void *p);
void func_021C88C8(int a, void *p);
void func_021C8838(void *p, int a, int b);
void func_021C8860(void *p, int a);

void func_021E781C(void *a, int b, int c)
{
    u8 k;
    void *r;
    u8 *p;

    if (c != func_021D775C(3))
        return;
    k = (u8)func_021D775C(6);
    r = func_021C7CF4(b, k);
    p = func_021C88A4(b, 0x14, c);
    *(u8 *)(p + 6) = c;
    *(u16 *)(p + 4) = func_021D57FC(r);
    *(u8 *)(p + 7) = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    *(u32 *)p |= 4 << 22;
    func_021C8838(p + 4, 2, 0x441);
    func_021C8860(p + 4, c);
    func_021C8860(p + 4, k);
    func_021C88C8(b, p);
}
