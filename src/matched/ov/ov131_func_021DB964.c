/*
 * function: func_021DB964
 * address: 0x021DB964
 * packet: pkt_ov131_021DB964
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DB9E6.
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0201C1C8 0x0201C1C8 thumb
 *   func_0204AB84 0x0204AB84 arm
 *   func_0204B784 0x0204B784 arm
 *   func_020275EC 0x020275EC thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DBCF4 0x021DBCF4 thumb ov131
 */
#include "../include/Obj00112.h"
#include "../include/Obj02847.h"
#include "../include/Obj23173.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021D6064(u8 *);
extern unsigned func_02017E88(void *,unsigned,unsigned);
extern int func_0201C1C8(u16);
extern void func_0204AB84(void *,void *);
extern void func_0204B784(void *,void *);
extern int func_020275EC(int);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_021DBCF4(u8 *p);
void func_021DB964(u8 *a,void *b,u8 *p) {
    unsigned v;
    int i;
    unsigned words[9];
    void *q;
    q=func_021D6064(a);
    if(p[0]<4) v=func_02017E88(q,p[0]+54,0);
    else v=((struct Obj23173 *)(*(u8 * *)&((struct Obj00112 *)a)->f8))->f14;
    if(((struct Obj02847 *)p)->f4==1) {
        if(v!=0) {
            i=func_0201C1C8(v);
            func_0204AB84(*(void **)(a+304+i*4),words);
            func_0204B784(((struct Obj02847 *)p)->fC,words);
            func_0204B6F4(((struct Obj02847 *)p)->fC,func_020275EC(i),1);
            func_0204B3DC(((struct Obj02847 *)p)->fC,1);
        } else func_0204B3DC(((struct Obj02847 *)p)->fC,0);
        func_021DBCF4(((struct Obj02847 *)p)->f14);
        func_0204B3DC(((struct Obj02847 *)p)->f8,1);
        ((struct Obj02847 *)p)->f4=0;
    }
}
