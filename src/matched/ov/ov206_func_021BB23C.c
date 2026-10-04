/*
 * function: func_021BB23C
 * address: 0x021BB23C
 * packet: pkt_ov206_021BB23C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0204B604 0x0204B604 arm
 */
typedef struct { short x,y,z,w; } Pos;
extern void func_02082BCC(void *,int,int);
struct Obj;
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
typedef unsigned int   u32;
struct Actor;
struct Node;
struct Personal;
extern void func_0204B800(struct Node *node, u32 val);
extern void func_0204B688(struct Actor *actor, u32 value);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0204B604(struct Actor *actor, u32 which, u32 set);
void func_021BB23C(char *p,int x,int y,int index)
{
    int flag=0;
    Pos pos;
    if (*(int *)(p+0x1c)) flag=1;
    func_02082BCC(&pos,0,8);
    pos.x=x;
    pos.y=y;
    *(int *)(p+0xac+index*4)=(int)func_0204B294((void *)*(int *)(p+0x24),*(int *)(p+0x94+index*4),*(int *)(p+0x9c+index*4),*(int *)(p+0xa4+index*4),&pos,flag,*(unsigned short *)p);
    func_0204B800((struct Node *)(*(int *)(p+0xac+index*4)),0);
    if(*(int *)(p+0x18)==2) func_0204B688((struct Actor *)(*(int *)(p+0xac+index*4)),1);
    if(func_0201AE1C((const struct Personal *)(*(int *)(p+0x26c)),34)==0) func_0204B604((struct Actor *)(*(int *)(p+0xac+index*4)),1,1);
}
