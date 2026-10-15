/*
 * function: STA_ACT_OBJ_AddEntry
 * address: 0x021F6B18
 * packet: pkt_ov112_021F6B18
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   d_021F8328 0x021F8328 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int     s32;
struct Board;
struct Vec3;
extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, struct Vec3 *src, u8 k, u32 w, u32 mode);
extern void BILLBOARD_SetElemVisible(void *,u32,u32 *);
extern u32 d_021F8328;
typedef struct { u32 active,dirty; int x,y,z,id,index; } Entry;
typedef struct { u16 heap,n; void *board; Entry entries[5]; } Object;
Entry *STA_ACT_OBJ_AddEntry(Object *o)
{
    u8 i;
    Entry *p;
    for(i=0;i<5;i++) if(o->entries[i].active==0) break;
    p=&o->entries[i];
    p->active=1; p->dirty=1; p->x=0; p->y=0; p->z=0;
    p->index=BILLBOARD_AddElem(o->board,p->id,4096,4096,(struct Vec3 *)(&p->x),31,0,0);
    BILLBOARD_SetElemVisible(o->board,p->index,&d_021F8328);
    return p;
}
