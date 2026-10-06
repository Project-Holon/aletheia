/*
 * function: func_021F6B18
 * address: 0x021F6B18
 * packet: pkt_ov112_021F6B18
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204F428 0x0204F428 arm
 *   func_0204F720 0x0204F720 arm
 *   d_021F8328 0x021F8328 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int     s32;
struct Board;
struct Vec3;
extern s32 func_0204F428(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *,u32,u32 *);
extern u32 d_021F8328;
typedef struct { u32 active,dirty; int x,y,z,id,index; } Entry;
typedef struct { u16 heap,n; void *board; Entry entries[5]; } Object;
Entry *func_021F6B18(Object *o)
{
    u8 i;
    Entry *p;
    for(i=0;i<5;i++) if(o->entries[i].active==0) break;
    p=&o->entries[i];
    p->active=1; p->dirty=1; p->x=0; p->y=0; p->z=0;
    p->index=func_0204F428(o->board,p->id,4096,4096,(struct Vec3 *)(&p->x),31,0,0);
    func_0204F720(o->board,p->index,&d_021F8328);
    return p;
}
