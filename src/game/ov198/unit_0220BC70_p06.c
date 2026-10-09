/*
 * function: func_0220EC2C
 * address: 0x0220EC2C
 * packet: pkt_ov198_0220EC2C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   func_0220E974 0x0220E974 thumb ov198
 *   func_0220E9A0 0x0220E9A0 thumb ov198
 *   func_0220EA30 0x0220EA30 thumb ov198
 *   d_02211D34 0x02211D34 data a2
 *   d_02211D68 0x02211D68 data a2
 *   d_02211D98 0x02211D98 data a2
 */
#include "../../matched/include/Obj10847.h"
#include "../../matched/include/Obj14560.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {short x,y;} Pair;
typedef struct {Pair first,second;short pad[4];Pair third;} Table1;
typedef struct {Pair first;short pad[4];Pair last;} Table2;
typedef struct {u8 low:3;u8 kind:4;u8 high:1;} Bits;
extern const Table1 d_02211D34;
extern const Table2 d_02211D68;
extern const Pair d_02211D98;
extern int func_022110D4(u8 *,int);
extern void func_0220E7CC(u8 *,unsigned);
typedef unsigned int   u32;
struct Vec2;
extern void func_0220E974(int mode, u8 *p, const struct Vec2 *q);
extern void func_0220E9A0(char *,u8 *,Pair *);
extern void func_0220EA30(u32 mode, u8 *p, const struct Vec2 *q);
void func_0220EC2C(u8 *p)
{
    int i;
    u8 *rec;
    Pair pair;
    i=func_022110D4(p,(*(u8 **)p)[0x20]);
    rec=p+4+i*0x4c;
    pair=d_02211D34.third;
    func_0220E7CC(*(u8 **)(p+i*4+0x1ed8),(unsigned)&pair);
    func_0220E974(((Bits *)(rec+0x17))->kind,*(u8 **)((char *)p+i*4+0x1ef0),(const struct Vec2 *)(&d_02211D68.first));
    func_0220E9A0((char *)p,rec,(Pair *)&d_02211D98);
    pair.x+=8;
    pair.y+=8;
    func_0220EA30(((struct Obj14560 *)rec)->f1A,*(u8 **)((const u8 *)p+i*4+0x1ebc),(const struct Vec2 *)(&pair));
    func_0220EA30(((struct Obj14560 *)rec)->f1A,*(u8 * *)&((struct Obj10847 *)p)->f1ED4,(const struct Vec2 *)((Pair *)&d_02211D34.second));
    func_0220E7CC(*(u8 * *)&((struct Obj10847 *)p)->f1F08,(unsigned)&d_02211D68.last);
}
