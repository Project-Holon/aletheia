/*
 * function: MUSICAL_MCSS_AddImage
 * address: 0x021F4B88
 * packet: pkt_ov112_021F4B88
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_FindFreeActorIndex 0x021F4B54 thumb ov112
 *   MUSICAL_MCSS_GetArcFileCount 0x021F4AA8 thumb ov112
 *   MUSICAL_MCSS_GetElemPtr 0x021F4F54 thumb ov112
 *   MUSICAL_MCSS_GetElemSizeFlags 0x021F4F70 thumb ov112
 *   MUSICAL_MCSS_SetupObject 0x021F4AC8 thumb ov112
 *   MUSICAL_MCSS_AddElem 0x021F4C94 thumb ov112
 *   BILLBOARD_AddImage 0x0204EF58 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef struct { u16 flags,zero; u32 id,index,type; int x,y,z; s16 a,b; u8 *data; } Entry;
typedef struct { u32 pad; void *board; Entry *entries; u8 *table; } Object;
typedef struct { u8 x,y; } Pair;
extern u16 MUSICAL_MCSS_FindFreeActorIndex(u32 p);
extern u16 MUSICAL_MCSS_GetArcFileCount(int);
extern u8 *MUSICAL_MCSS_GetElemPtr(u8 *,int);
extern int MUSICAL_MCSS_GetElemSizeFlags(int *);
extern void MUSICAL_MCSS_SetupObject(u8 *p, u8 *a, u8 *b);
extern Entry *MUSICAL_MCSS_AddElem(Object *,u16,int *,s16,s16);
struct Desc;
extern u32 BILLBOARD_AddImage(struct Desc *desc, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
Entry *MUSICAL_MCSS_AddImage(Object *p,int type,u32 id,int *v)
{
    int index;
    int data;
    Pair pair;
    index=MUSICAL_MCSS_FindFreeActorIndex((u32)p);
    p->entries[index].type=MUSICAL_MCSS_GetArcFileCount(type);
    p->entries[index].data=MUSICAL_MCSS_GetElemPtr(p->table,type);
    data=MUSICAL_MCSS_GetElemSizeFlags((int *)p->entries[index].data);
    MUSICAL_MCSS_SetupObject((u8 *)(&p->entries[index]),&pair.y,&pair.x);
    p->entries[index].id=BILLBOARD_AddImage(p->board,id,0,data,pair.y<<5,pair.x<<5);
    p->entries[index].flags |= 16;
    MUSICAL_MCSS_AddElem(p,index,v,pair.y,pair.x);
    return &p->entries[index];
}
