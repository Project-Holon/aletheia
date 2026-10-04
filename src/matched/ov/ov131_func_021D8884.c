/*
 * function: func_021D8884
 * address: 0x021D8884
 * packet: pkt_ov131_021D8884
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049E74 0x02049E74 arm
 *   func_021DBA90 0x021DBA90 thumb ov131
 */

extern void *func_02049EF4(void *, unsigned int, unsigned int, void **, unsigned short);
typedef unsigned short u16;
typedef unsigned int   u32;
struct S;
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern struct S *func_021DBA90(u32 a, u32 b);
void func_021D8884(unsigned char *a, unsigned char *p, void *arc)
{
    *(void **)(p+0x2c) = func_02049EF4(arc, 66, 0, (void **)(p+0x28), *(unsigned short *)a);
    *(void **)(p+0x34) = func_02049EF4(arc, 67, 0, (void **)(p+0x30), *(unsigned short *)a);
    *(void **)(p+0x3c) = func_02049EF4(arc, 68, 0, (void **)(p+0x38), *(unsigned short *)a);
    *(void **)(p+0x44) = func_02049EF4(arc, 69, 0, (void **)(p+0x40), *(unsigned short *)a);
    *(void **)(p+0x4c) = func_02049E74(arc, 12, 0, (u32)(p+0x48), *(unsigned short *)a);
    *(void **)(p+0x6c) = func_021DBA90(*(unsigned short *)a, (u32)(*(void **)(a+0x174)));
}
