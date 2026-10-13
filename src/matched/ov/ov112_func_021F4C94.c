/*
 * function: func_021F4C94
 * address: 0x021F4C94
 * packet: pkt_ov112_021F4C94
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   func_0204F720 0x0204F720 arm
 *   d_021F8300 0x021F8300 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int     s32;
struct Board;
struct Vec3;
extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void func_0204F720(void *,u32,u32 *);
extern u32 d_021F8300;
typedef struct { u16 flags, zero; u32 id, index, type; int x,y,z; s16 a,b; void *data; } Entry;
typedef struct { u32 pad; void *board; Entry *entries; } Object;
Entry *func_021F4C94(Object *p, u16 index, int *v, s16 a, s16 b)
{
    p->entries[index].index = BILLBOARD_AddElem(p->board,p->entries[index].id,4096,4096,(struct Vec3 *)v,31,0,0);
    func_0204F720(p->board,p->entries[index].index,&d_021F8300);
    p->entries[index].flags = (p->entries[index].flags & ~1) | 1;
    p->entries[index].flags |= 2;
    p->entries[index].flags |= 4;
    p->entries[index].flags = p->entries[index].flags & ~8;
    p->entries[index].x = v[0];
    p->entries[index].y = v[1];
    p->entries[index].z = v[2];
    p->entries[index].a = a;
    p->entries[index].b = b;
    p->entries[index].zero = 0;
    return &p->entries[index];
}
