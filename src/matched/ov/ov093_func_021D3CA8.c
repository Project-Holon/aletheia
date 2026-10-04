/*
 * function: func_021D3CA8
 * address: 0x021D3CA8
 * packet: pkt_ov093_021D3CA8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding.
 * ABI: narrow extern arguments follow explicit caller truncation.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6264 0x021D6264 thumb ov093
 */
#include "../include/Obj21200.h"
typedef unsigned char u8;
struct UtilSlots;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D6264(struct UtilSlots *, u8);
int func_021D3CA8(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21200 *)p)->f4, (u8)a[0]);
    func_021D6264((struct UtilSlots *)obj, a[1]);
    return 1;
}
