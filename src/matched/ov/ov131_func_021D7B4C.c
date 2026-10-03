/*
 * function: func_021D7B4C
 * address: 0x021D7B4C
 * packet: pkt_ov131_021D7B4C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   func_02045B38 0x02045B38 arm
 */

extern void *func_02049EF4(void *, unsigned int, unsigned int, void **, unsigned short);
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void func_021D7B4C(unsigned char *a, unsigned char *p, void *arc)
{
    *(void **)(p+0x50) = func_02049EF4(arc, 63, 0, (void **)(p+0x4c), *(unsigned short *)a);
    *(void **)(p+0x58) = func_02049EF4(arc, 72, 0, (void **)(p+0x54), *(unsigned short *)a);
    *(void **)(p+0x60) = func_02049EF4(arc, 64, 0, (void **)(p+0x5c), *(unsigned short *)a);
    *(void **)(p+0x68) = func_02049EF4(arc, 65, 0, (void **)(p+0x64), *(unsigned short *)a);
    *(void **)(p+0x38) = func_02045B38(0, 2, 188, *(unsigned short *)a);
    *(void **)(p+0x3c) = func_02045B38(0, 2, 89, *(unsigned short *)a);
    *(void **)(p+0x40) = func_02045B38(0, 2, 92, *(unsigned short *)a);
    *(void **)(p+0x44) = func_02045B38(0, 2, 90, *(unsigned short *)a);
    *(void **)(p+0x48) = func_02045B38(0, 2, 91, *(unsigned short *)a);
}
