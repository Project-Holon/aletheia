/*
 * function: func_021F4B88
 * address: 0x021F4B88
 * packet: pkt_ov112_021F4B88
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4B54 0x021F4B54 thumb ov112
 *   func_021F4AA8 0x021F4AA8 thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_021F4AC8 0x021F4AC8 thumb ov112
 *   func_021F4C94 0x021F4C94 thumb ov112
 *   func_0204EF58 0x0204EF58 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry;
typedef struct { u32 pad; void *board; Entry *entries; u8 *table; } Object;
typedef struct { u8 x,y; } Pair;
extern u16 func_021F4B54(Object *);
extern u16 func_021F4AA8(int);
extern u8 *func_021F4F54(u8 *,int);
extern int func_021F4F70(int *);
extern void func_021F4AC8(Entry *,u8 *,u8 *);
extern Entry *func_021F4C94(Object *,u16,int *,s16,s16);
struct Desc;
extern u32 func_0204EF58(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
Entry *func_021F4B88(Object *p,int type,u32 id,int *v)
{
    int index;
    int data;
    Pair pair;
    index=func_021F4B54(p);
    p->entries[index].type=func_021F4AA8(type);
    p->entries[index].data=func_021F4F54(p->table,type);
    data=func_021F4F70((int *)p->entries[index].data);
    func_021F4AC8(&p->entries[index],&pair.y,&pair.x);
    p->entries[index].id=func_0204EF58(p->board,id,0,data,pair.y<<5,pair.x<<5);
    p->entries[index].flags |= 16;
    func_021F4C94(p,index,v,pair.y,pair.x);
    return &p->entries[index];
}
