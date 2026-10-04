/*
 * function: func_021C7430
 * address: 0x021C7430
 * packet: pkt_ov136_021C7430
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C7F04 0x021C7F04 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021C7F04[];
extern void *func_02030734(u32, u32, int, const char *, u16);
struct BigObj;
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern void *func_0200CA1C(void *a);
void func_021C7430(u8 *p, int a, u16 b, u16 c)
{
    u8 *q = func_02030734(0x65, 0x98, 1, d_021C7F04, 0x529);
    *(void **)(q + 0) = func_02012934(**(void ***)(p + 4));
    *(void **)(q + 4) = func_0201292C(**(void ***)(p + 4));
    *(void **)(q + 8) = *(void **)p;
    *(int *)(q + 0x38) = 0;
    *(int *)(q + 0x34) = a;
    *(u16 *)(q + 0x44) = b;
    *(u16 *)(q + 0x5C) = c;
    *(u32 *)(q + 0x18) = (u32)func_0200CA1C(**(void ***)(p + 4));
    *(u8 **)(p + 0x10) = q;
}
