/*
 * function: func_021D8C04
 * address: 0x021D8C04
 * packet: pkt_ov123_021D8C04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6934 0x021D6934 thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D5A60 0x021D5A60 thumb ov123
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8B7C 0x021D8B7C thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 */
#include "../include/Obj00063.h"
#include "../include/Obj22982.h"
typedef unsigned char u8;
struct Obj;
struct Sub02009448Obj;
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void func_021D6934(struct Obj *p);
extern int func_021D6EA4(char *);
typedef unsigned int   u32;
extern int func_021D6E70(u8 *p);
extern int func_021D5950(u8 *,int);
extern void func_021D59E4(char *);
extern void func_021D5A60(char *);
extern void func_021D66D0(u8 *,int);
extern int func_021D6E08(char *,int);
extern int NHTTP_RAP_GetResultCode(u8 *p);
extern int NHTTP_RAP_PollConnection(u8 *p);
extern char *NHTTP_RAP_GetRecvBuffer(void *);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8B7C(char *);
extern void func_021D6FF0(char *);
void func_021D8C04(char *p)
{
    char *q;
    int state;
    func_02009448(((struct Obj00063 *)p)->f28);
    func_021D6934(((struct Obj00063 *)p)->f14);
    if (func_021D6EA4(p)) {
        if (((struct Obj00063 *)p)->f74==0) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,42);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==360) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        }
        ++((struct Obj00063 *)p)->f74;
    }
    if (func_021D6E70((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<50) ++((struct Obj00063 *)p)->f70;
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (func_021D6E08(p,NHTTP_RAP_GetResultCode(((struct Obj00063 *)p)->f10))) return;
        if (NHTTP_RAP_PollConnection(((struct Obj00063 *)p)->f10)) return;
        q=NHTTP_RAP_GetRecvBuffer(((struct Obj00063 *)p)->f10);
        if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
        state=((struct Obj22982 *)q)->f0;
        if (state==0) {
            func_021D6EE0((u8 *)p,(int)func_021D8B7C,0x955);
            return;
        }
        ((struct Obj00063 *)p)->f80=state;
        func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x959);
        return;
    } else {
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f68);
        if (++((struct Obj00063 *)p)->f68==100) {
            if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
            func_021D6EE0((u8 *)p,(int)func_021D8B7C,0x967);
        }
    }
}
