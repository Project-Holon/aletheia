/*
 * function: func_021EEF2C
 * address: 0x021EEF2C
 * packet: pkt_ov188_021EEF2C
 * region: ov188
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02030734 0x02030734 arm
 *   func_0201A954 0x0201A954 thumb
 *   func_021EEBF0 0x021EEBF0 thumb ov188
 *   func_02017E40 0x02017E40 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_020307B0 0x020307B0 arm
 *   d_021EF360 0x021EF360 data a4
 */
#include "../include/Obj14491.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020173EC(void);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
typedef signed int     s32;
struct Party;
extern void func_0201A954(struct Party *p, s32 capacity);
struct Mon;
struct PartyMon;
extern void func_021EEBF0(char *p, struct Mon *q);
extern void func_02017E40(void *,u32,u32);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_020307B0(void *);
extern char d_021EF360[];
void func_021EEF2C(u8 *a,void *b,u32 c)
{
    int i;
    u8 *p;
    p=func_02030734((u16)((c & 0x7FFF)|0x8000),func_020173EC(),1,d_021EF360,173);
    func_0201A954(b,((struct Obj14491 *)a)->f0);
    for(i=0;i<((struct Obj14491 *)a)->f2;i++) {
        func_021EEBF0((char *)(a+4+i*112),(struct Mon *)p);
        func_02017E40(p,159,0);
        func_0201A98C(b,(const struct PartyMon *)p);
    }
    func_020307B0(p);
}
