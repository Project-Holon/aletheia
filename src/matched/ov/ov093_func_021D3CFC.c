/*
 * function: func_021D3CFC
 * address: 0x021D3CFC
 * packet: pkt_ov093_021D3CFC
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
 *   func_021D6408 0x021D6408 thumb ov093
 *   func_021D6E88 0x021D6E88 thumb ov093
 */
#include "../include/Obj21202.h"
typedef unsigned char u8;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D6408(u8 *);
extern void func_021D6E88(u8 *);
int func_021D3CFC(char *p, int unused, unsigned int *a)
{
    u8 *obj = func_021B9934(*(char * *)&((struct Obj21202 *)p)->f4, (u8)a[0]);
    func_021D6408(obj);
    func_021D6E88(obj);
    return 1;
}
