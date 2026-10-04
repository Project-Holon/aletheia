/*
 * function: func_021D8B0C
 * address: 0x021D8B0C
 * packet: pkt_ov129_021D8B0C
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021D9890 0x021D9890 thumb ov129
 *   func_021DA164 0x021DA164 thumb ov129
 *   func_021D9AB0 0x021D9AB0 thumb ov129
 *   func_021DA1A8 0x021DA1A8 thumb ov129
 *   func_021D9BEC 0x021D9BEC thumb ov129
 *   func_021D9D44 0x021D9D44 thumb ov129
 *   func_021DA320 0x021DA320 thumb ov129
 *   func_021DA3B8 0x021DA3B8 thumb ov129
 *   func_021DA42C 0x021DA42C thumb ov129
 *   func_021DA524 0x021DA524 thumb ov129
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 */
#include "../include/Obj10498.h"

extern void func_021D9890(char *);
extern void func_021DA164(void *);
extern void func_021D9AB0(char *);
extern void func_021DA1A8(char *,int);
extern void func_021D9BEC(char *);
extern void func_021D9D44(char *);
extern void func_021DA320(char *);
extern void func_021DA3B8(char *);
extern void func_021DA42C(char *);
extern void func_021DA524(char *,int,int,int,int,int,int,int,int);
extern void func_021D8AF4(char *,int);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
int func_021D8B0C(char *p)  {
    func_021D9890(p);
    func_021DA164(p);
    func_021D9AB0(p);
    func_021DA1A8(p,0);
    func_021D9BEC(p);
    func_021D9D44(p);
    func_021DA320(p);
    func_021DA3B8(p);
    func_021DA42C(p);
    func_021DA524(p+0x310,((struct Obj10498 *)p)->f328,4,2,19,27,4,((struct Obj10498 *)p)->f314,((struct Obj10498 *)p)->f344);
    func_021D8AF4(p,1);
    func_0202208C(0,1,1,0,6,1,50);
    return 0;
}
