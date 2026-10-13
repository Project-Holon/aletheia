/*
 * function: func_021D80B8
 * address: 0x021D80B8
 * packet: pkt_ov123_021D80B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7F9C 0x021D7F9C thumb ov123
 */
#include "../include/Obj05368.h"
extern int func_021D6E70(unsigned char *p);
extern int func_021D6EBC(unsigned char *p);
extern int func_021D6EA4(char *);
typedef unsigned char  u8;
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
typedef unsigned int   u32;
extern int func_021D5950(u8 *p, int x);
extern void func_021D59E4(char *);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D7F9C(char *p);
void func_021D80B8(char *p)
{
    if (func_021D6E70((unsigned char *)p) && !func_021D6EBC((unsigned char *)p)) {
        if (NHTTP_RAP_CreateRequest(2, ((struct Obj05368 *)p)->f10) && !NHTTP_RAP_StartConnection(((struct Obj05368 *)p)->f10)) {
            func_021D6EE0((u8 *)p, (int)func_021D7F9C, 0x59d);
            return;
        }
    } else {
        if (func_021D6EA4(p)) {
            ((struct Obj05368 *)p)->f74 = 0;
            func_021D5950((u8 *)(*(char * *)&((struct Obj05368 *)p)->f18), 42);
            func_021D59E4(*(char * *)&((struct Obj05368 *)p)->f18);
        } else {
            ((struct Obj05368 *)p)->f74 = 0x42e;
        }
        func_021D6EE0((u8 *)p, (int)func_021D7F9C, 0x5aa);
    }
}
