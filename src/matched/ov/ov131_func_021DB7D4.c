/*
 * function: func_021DB7D4
 * address: 0x021DB7D4
 * packet: pkt_ov131_021DB7D4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * semantic: selector loads are fresh bytes after each getter, additions
 *   <=321 fit int. Every branch initializes id/count/value. Late table
 *   index is the full byte, with no assumed menu bound; address arithmetic
 *   is u32 wrap. Table x+5<=260, times8<=2080; y*8<=2040, fit s16.
 *   All24 descriptor bytes (including its value and screen) are assigned.
 *   Pool B95C/B960 name the same byte-pair object at C2B8 and its +1 byte.
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_02017E88 0x02017E88 thumb
 *   func_0201BD28 0x0201BD28 thumb
 *   func_02043678 0x02043678 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_021D614C 0x021D614C thumb ov131
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021D6244 0x021D6244 thumb ov131
 *   func_0201ED04 0x0201ED04 thumb
 *   func_021D61B8 0x021D61B8 thumb ov131
 *   func_021DBAD0 0x021DBAD0 thumb ov131
 *   d_021DC2B8 0x021DC2B8 data a1 ov131
 */
#include "../include/Obj01409.h"
#include "../include/Obj02846.h"
#include "../include/Obj04511.h"
#include "../include/Obj23172.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {void *pixels;u16 width,height,depth,kind;} Bmp;
typedef struct {Bmp *bmp;s16 x,y;u32 resource,value;u8 a,b;u16 c;u32 d;} Descriptor;
typedef struct {u8 x,y;} Pair;
struct MsgBank;
struct U16Vec;
struct Rec;
struct WordSet;
extern const Pair d_021DC2B8[];
extern void *func_021D6064(u8 *);
extern u32 func_02017E88(void *,u32,u32);
extern u32 func_0201BD28(u16,u32);
struct Bmp;
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_02045EC0(struct MsgBank *,u32);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(struct U16Vec *);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021D614C(u8 *,int,int,int,s16,u16);
extern struct WordSet *func_0201EC64(u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_021D6244(u8 *,int,void *,int,u16,s16,u16);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_021D61B8(u8 *,int,void *,int,s16,s16,u16);
extern u8 *func_021DBAD0(u8 *a, const u8 *b);
void func_021DB7D4(u8 *p,u8 *q,u8 *entry)
{
    Descriptor desc;
    void *mon;
    u32 id,count,value;
    struct MsgBank *bank;
    void *text;
    struct WordSet *first,*second;
    mon=func_021D6064(p);
    if(entry[0]<4) {
        id=func_02017E88(mon,entry[0]+54,0);
        count=func_02017E88(mon,entry[0]+58,0);
        value=func_02017E88(mon,entry[0]+66,0);
    } else {
        id=((struct Obj23172 *)(*(u8 * *)&((struct Obj02846 *)p)->f8))->f14;
        count=func_0201BD28(id,5);
        value=count;
    }
    *(Bmp * *)&((struct Obj01409 *)entry)->f10=(Bmp *)func_02043678(11,4,32,((struct Obj02846 *)p)->f0);
    bank=func_02045B38(0,2,203,((struct Obj02846 *)p)->f0);
    text=func_02045EC0(bank,id);
    func_0201C724(((struct Obj02846 *)p)->f84,*(u32 *)&((struct Obj01409 *)entry)->f10,3,2,(u32)text,((struct Obj02846 *)p)->f80,1088);
    func_02045808(text);
    func_02045C04((struct Rec *)bank);
    if(id!=0) {
        func_021D614C(p,*(int *)&((struct Obj01409 *)entry)->f10,135,13,17,1088);
        first=func_0201EC64(((struct Obj02846 *)p)->f0);
        func_0201EFA4(first,0,count,3,1,1);
        func_021D6244(p,*(int *)&((struct Obj01409 *)entry)->f10,first,136,57,17,1088);
        func_0201ED04(first);
        func_021D614C(p,*(int *)&((struct Obj01409 *)entry)->f10,117,57,17,1088);
        second=func_0201EC64(((struct Obj02846 *)p)->f0);
        func_0201EFA4(second,0,value,3,1,1);
        func_021D61B8(p,*(int *)&((struct Obj01409 *)entry)->f10,second,141,61,17,1088);
        func_0201ED04(second);
    } else {
        func_021D614C(p,*(int *)&((struct Obj01409 *)entry)->f10,153,49,17,1088);
    }
    desc.x=(*(const u8 *)((u32)&d_021DC2B8[0].x+(u32)entry[0]*2U)+5)*8;
    desc.y=*(const u8 *)((u32)&d_021DC2B8[0].y+(u32)entry[0]*2U)*8;
    desc.resource=*(u32 *)&((struct Obj02846 *)p)->fB8;
    desc.value=0;
    desc.a=6;
    desc.b=0;
    desc.c=0;
    desc.d=0;
    desc.bmp=*(Bmp * *)&((struct Obj01409 *)entry)->f10;
    *(u8 * *)&((struct Obj01409 *)entry)->f14=func_021DBAD0(*(u8 * *)&((struct Obj04511 *)q)->fA4,(const u8 *)(&desc));
    ((struct Obj01409 *)entry)->f4=1;
}
