/*
 * function: func_021BB9E0
 * address: 0x021BB9E0
 * packet: pkt_ov206_021BB9E0
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: zero halfword at 0x021BBA7A before 0x021BBA7C.
 * lever: flag zero assigned after clearing loop; assigning it before loop costs two bytes.
 * symbols:
 *   func_021BC0B4 0x021BC0B4 thumb ov206
 *   func_021BC0B8 0x021BC0B8 thumb ov206
 *   func_021BC0CC 0x021BC0CC thumb ov206
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef enum Flag { FLAG_ZERO=0,FLAG_ONE=1 } Flag;
struct State { u16 heap; char pad2[26]; int flag; char pad20[0x168]; unsigned array[2],index; char pad194[0x44]; unsigned owner; };
extern int func_021BC0B4(int);
extern int func_021BC0B8(int);
extern int func_021BC0CC(int);
extern int func_0204AC18(unsigned,unsigned,unsigned,unsigned,u16,u16,u16);
extern int func_0204AF28(unsigned,unsigned,unsigned,unsigned);
void func_021BB9E0(struct State *p)
{
    u8 i;
    int flag;
    unsigned owner;
    i=0;
    for(;i<2;i++) p->array[i]=0;
    p->index=0;
    flag=0;
    if(p->flag) flag=1;
    owner=p->owner;
    *(int *)((char *)p+0x17c)=func_0204AC18(owner,func_021BC0B4(p->flag),flag,160,0,1,p->heap);
    *(int *)((char *)p+0x180)=func_0204AF28(owner,func_021BC0B8(0),func_021BC0CC(0),p->heap);
    *(int *)((char *)p+0x184)=func_0204AF28(owner,func_021BC0B8(494),func_021BC0CC(494),p->heap);
}
