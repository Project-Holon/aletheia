/*
 * function: func_021D36CC
 * address: 0x021D36CC
 * packet: pkt_ov093_021D36CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 30 bytes followed by two zero alignment bytes.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5F90 0x021D5F90 thumb ov093
 */
#include "../include/Obj21166.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D5F90(u8 *, u16);
int func_021D36CC(char *p, int *state, unsigned int *q)
{
    func_021D5F90(func_021B9934(*(char * *)&((struct Obj21166 *)p)->f4, (u8)q[0]), q[1]);
    return 1;
}
