/*
 * function: func_021D9A50
 * address: 0x021D9A50
 * packet: pkt_ov175_021D9A50
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200BAF4 0x0200BAF4 thumb
 *   func_0201A948 0x0201A948 thumb
 *   func_0201A918 0x0201A918 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00013.h"
#include "../include/Obj24310.h"
#include "../include/Obj24311.h"
extern void func_02082BCC(void *, int, int);
struct Big;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200BAC8(void *);
extern void *func_0200BAF4(int a0, int a1);
extern void *func_0201A948(void *);
extern int func_0201A918(void *);
extern void func_02082D44(const void *, void *, int);
extern void func_020307B0(void *);
void func_021D9A50(char *dest, char *ctx)
{
    void *records;
    func_02082BCC(dest, 0, 212);
    records = func_0200BAF4((int)func_0200BAC8(func_02012EBC(**(void ** *)&((struct Obj24311 *)(*(char * *)&((struct Obj00013 *)ctx)->f104))->f8)), 87);
    func_02082D44(records, dest + 212, func_0201A918(func_0201A948(dest + 212)));
    func_020307B0(records);
    ((struct Obj24310 *)dest)->f44 = 100;
}
