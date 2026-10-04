/*
 * function: func_021D920C
 * address: 0x021D920C
 * packet: pkt_ov123_021D920C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: unlabelled ov009 02156DE0 leaf filed and verified before caller rerun.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_021D5644 0x021D5644 thumb ov123
 *   func_021D5E8C 0x021D5E8C thumb ov123
 *   func_021D5B70 0x021D5B70 thumb ov123
 *   func_0203CD98 0x0203CD98 arm
 *   func_02156DE0 0x02156DE0 thumb ov009
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_02156DC4 0x02156DC4 thumb ov009
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 */
#include "../include/Obj00990.h"
extern int func_020221A4(void *);
typedef unsigned char  u8;
struct S020315D4;
struct TaskMenu;
extern void func_02027858(struct TaskMenu *m);
extern void func_020307B0(void *);
extern void func_021D5644(char *p);
extern void func_021D5E8C(u8 *p);
extern void func_021D5B70(char *p);
extern int func_0203CD98(void);
extern void func_02156DE0(int,int);
extern void func_021B9838(u8 *p);
extern void func_02156DC4(int,int);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_02034A5C(int handle);
extern char ov114_id[];
int func_021D920C(void *a, int b, int c, char *p)
{
    if (!func_020221A4(a)) return 0;
    if (((struct Obj00990 *)p)->f1C) func_02027858(((struct Obj00990 *)p)->f1C);
    if (((struct Obj00990 *)p)->f38) {
        func_020307B0(((struct Obj00990 *)p)->f38);
        ((struct Obj00990 *)p)->f38=0;
    }
    func_021D5644(((struct Obj00990 *)p)->f18);
    func_021D5E8C(((struct Obj00990 *)p)->f14);
    func_021D5B70(((struct Obj00990 *)p)->f8);
    if (((struct Obj00990 *)p)->f30) func_020307B0(((struct Obj00990 *)p)->f30);
    if (((struct Obj00990 *)p)->f3C) func_020307B0(((struct Obj00990 *)p)->f3C);
    if (((struct Obj00990 *)p)->f40) func_020307B0(((struct Obj00990 *)p)->f40);
    if (((struct Obj00990 *)p)->fC) func_020307B0(((struct Obj00990 *)p)->fC);
    if (((struct Obj00990 *)p)->f44) func_020307B0(((struct Obj00990 *)p)->f44);
    if (func_0203CD98()) func_02156DE0(0,0);
    if (((struct Obj00990 *)p)->f10) {
        func_021B9838(((struct Obj00990 *)p)->f10);
        func_02156DC4(0,0);
    }
    func_020315D4(a);
    func_020306F0(98);
    func_02034A5C((int)ov114_id);
    return 1;
}
