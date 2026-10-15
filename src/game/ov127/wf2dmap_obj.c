/*
 * file:     wf2dmap_obj.c
 * unit:     yes
 * function: WF2DMAP_OBJ_CreateList, WF2DMAP_OBJ_DeleteList, WF2DMAP_OBJ_DispatchById, WF2DMAP_OBJ_UpdateList, WF2DMAP_OBJ_GetCount, WF2DMAP_OBJ_Create, WF2DMAP_OBJ_Clear, WF2DMAP_OBJ_FindById, WF2DMAP_OBJ_GetByIndex, WF2DMAP_OBJ_FindById2, WF2DMAP_OBJ_GetByIndex2, WF2DMAP_OBJ_GetSlot, WF2DMAP_OBJ_SetSlot, WF2DMAP_OBJ_OffsetPos, WF2DMAP_OBJ_GetTableByte, WF2DMAP_OBJ_AllocSlot, WF2DMAP_OBJ_GetPos, WF2DMAP_OBJ_GetDestPos, WF2DMAP_OBJ_GetCurrentPos, WF2DMAP_OBJ_SetPos, WF2DMAP_OBJ_SetDestPos, WF2DMAP_OBJ_FindAtPos, WF2DMAP_OBJ_ApplyCommand
 * address:  0x021C4880
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wf2dmap_map.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   sWf2dmapObjFileName 0x021C6120 data a1
 *   WF2DMAP_OBJCMD_Update 0x021C4CB4 thumb ov127
 *   MI_CpuFill8 0x02082BCC arm
 *   sWf2dmapStepDelta 0x021C6014 data a4
 *   sWf2dmapDirectionTable  0x021C6010  data  a1
 *   sWf2dmapCommandTable 0x021C601C data a4
 */
#include "wf2dmap_obj_types.h"
#include "wf2dmap_map_shared_types.h"

typedef signed char s8;

typedef signed short s16;

/* Object list of the 2D map (wf2dmap_obj.c). */
typedef struct Wf2dmapObjList {
    void *entries;
    u32 count;
} Wf2dmapObjList;

/* Per-direction step delta table row. */
typedef struct Wf2dmapDelta {
    s8 dx, dy;
} Wf2dmapDelta;

/* 8-byte command descriptor applied by ApplyCommand. */
typedef struct Wf2dmapCmdDesc {
    Wf2dmapPairU16 pos;     /* 0x00 */
    u16 index;              /* 0x04 */
    u8 value;               /* 0x06 */
} Wf2dmapCmdDesc;

extern void *func_02030734(u16,u32,int,const char *,u16);

extern u32 func_020307B0(void *p);

extern void WF2DMAP_OBJCMD_Update(u8 *p);

extern void MI_CpuFill8(void *,int,int);

Wf2dmapObjList *WF2DMAP_OBJ_CreateList(u32 count, u32 heap);

void WF2DMAP_OBJ_DeleteList(u8 *p);

void WF2DMAP_OBJ_DispatchById(void *a, u8 *q);

void WF2DMAP_OBJ_UpdateList(u8 *p);

u32 WF2DMAP_OBJ_GetCount(u8 *p);

void WF2DMAP_OBJ_Create(void *a,u16 *s);

void WF2DMAP_OBJ_Clear(void *p);

char *WF2DMAP_OBJ_FindById(unsigned *p, unsigned id);

char *WF2DMAP_OBJ_GetByIndex(char **p, int i);

char *WF2DMAP_OBJ_FindById2(unsigned *p,unsigned id);

char *WF2DMAP_OBJ_GetByIndex2(char **p,int i);

int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i);

void WF2DMAP_OBJ_SetSlot(void *p, int i, int v);

Wf2dmapPos WF2DMAP_OBJ_OffsetPos(Wf2dmapPos p,int i);

unsigned char WF2DMAP_OBJ_GetTableByte(int i);

char *WF2DMAP_OBJ_AllocSlot(unsigned *p);

Wf2dmapPos WF2DMAP_OBJ_GetPos(char *p);

Wf2dmapPos WF2DMAP_OBJ_GetDestPos(char *p);

Wf2dmapPos WF2DMAP_OBJ_GetCurrentPos(char *p);

void WF2DMAP_OBJ_SetPos(char *p, Wf2dmapPairU16 v);

void WF2DMAP_OBJ_SetDestPos(char *p, Wf2dmapPairU16 v);

u8 *WF2DMAP_OBJ_FindAtPos(u8 *p, void *list, int n);

void WF2DMAP_OBJ_ApplyCommand(char *p,char *q);

extern const char sWf2dmapObjFileName[];

extern Wf2dmapDelta sWf2dmapStepDelta;

extern unsigned char sWf2dmapDirectionTable[];

Wf2dmapObjList *WF2DMAP_OBJ_CreateList(u32 count, u32 heap)
{
    Wf2dmapObjList *p;
    p = func_02030734(heap, 8, 1, sWf2dmapObjFileName, 128);
    p->count = count;
    p->entries = func_02030734(heap, 24 * p->count, 1, sWf2dmapObjFileName, 133);
    return p;
}

/*
 * Addresses are Black-image addresses.
 */
void WF2DMAP_OBJ_DeleteList(u8 *p)
{
    func_020307B0(((Wf2dmapObjList *)p)->entries);
    func_020307B0(p);
}

void WF2DMAP_OBJ_DispatchById(void *a, u8 *q)
{
    WF2DMAP_OBJ_ApplyCommand(WF2DMAP_OBJ_FindById(a, q[7]), (char *)q);
}

void WF2DMAP_OBJ_UpdateList(u8 *p) { u32 i,n; char *q; n=WF2DMAP_OBJ_GetCount(p);for(i=0;i<n;i++){q=WF2DMAP_OBJ_GetByIndex((char **)p,(u16)i);if(q)WF2DMAP_OBJCMD_Update((u8 *)q);} }

u32 WF2DMAP_OBJ_GetCount(u8 *p) { return ((Wf2dmapObjList *)p)->count; }

void WF2DMAP_OBJ_Create(void *a,u16 *s) { u8 *p; s16 x,y;p=(u8 *)WF2DMAP_OBJ_AllocSlot((unsigned *)a);x=(s16)s[0];y=(s16)s[1];((Wf2dmapObj *)p)->posX=x;((Wf2dmapObj *)p)->posY=y;((Wf2dmapObj *)p)->destX=x;((Wf2dmapObj *)p)->destY=y;((Wf2dmapObj *)p)->id=s[2];p[21]=s[3];p[20]=s[4];((Wf2dmapObj *)p)->kind=s[5];((Wf2dmapObj *)p)->active=1; }

void WF2DMAP_OBJ_Clear(void *p) { MI_CpuFill8(p,0,24); }

char *WF2DMAP_OBJ_FindById(unsigned *p, unsigned id)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0]; char *e;
 do { e=base+i*24; if (((Wf2dmapObj *)e)->active==1 && id==((Wf2dmapObj *)e)->id) return e; i++; } while(i<p[1]); }
 return 0;
}

char *WF2DMAP_OBJ_GetByIndex(char **p, int i)
{
    char *base = *p;
    char *e = base + i * 0x18;

    if (((Wf2dmapObj *)e)->active != 1)
        return 0;
    return e;
}

char *WF2DMAP_OBJ_FindById2(unsigned *p,unsigned id) { return WF2DMAP_OBJ_FindById(p,id); }

char *WF2DMAP_OBJ_GetByIndex2(char **p,int i) { return WF2DMAP_OBJ_GetByIndex(p,i); }

/*
 * extent: two zero alignment bytes at 0x021C49FE follow the return.
 */
int WF2DMAP_OBJ_GetSlot(u8 *p, unsigned int i)
{
    switch (i) {
    case 0: return *(s16 *)&((Wf2dmapObj *)p)->posX;
    case 1: return *(s16 *)&((Wf2dmapObj *)p)->posY;
    case 2: return *(s16 *)&((Wf2dmapObj *)p)->destX;
    case 3: return *(s16 *)&((Wf2dmapObj *)p)->destY;
    case 4: return ((Wf2dmapObj *)p)->id;
    case 5: return p[21];
    case 6: return p[20];
    case 7: return ((Wf2dmapObj *)p)->kind;
    case 8: return ((Wf2dmapObj *)p)->step;
    case 9: return ((Wf2dmapObj *)p)->stepCount;
    case 10: return ((Wf2dmapObj *)p)->updateCounter;
    default: return (int)p;
    }
}

void WF2DMAP_OBJ_SetSlot(void *p, int i, int v)
{
    switch (i)
    {
    case 0:
        ((Wf2dmapObj *)p)->posX = (u16)v;
        break;
    case 1:
        ((Wf2dmapObj *)p)->posY = (u16)v;
        break;
    case 2:
        ((Wf2dmapObj *)p)->destX = (u16)v;
        break;
    case 3:
        ((Wf2dmapObj *)p)->destY = (u16)v;
        break;
    case 4:
        ((Wf2dmapObj *)p)->id = (u16)v;
        break;
    case 5:
        ((Wf2dmapObj *)p)->command = (u8)v;
        break;
    case 6:
        ((Wf2dmapObj *)p)->variant = (u8)v;
        break;
    case 7:
        ((Wf2dmapObj *)p)->kind = (u16)v;
        break;
    case 8:
        ((Wf2dmapObj *)p)->step = (u16)v;
        break;
    case 9:
        ((Wf2dmapObj *)p)->stepCount = (u16)v;
        break;
    case 10:
        ((Wf2dmapObj *)p)->updateCounter = (u16)v;
        break;
    default:
        break;
    }
}

Wf2dmapPos WF2DMAP_OBJ_OffsetPos(Wf2dmapPos p,int i)
{
 Wf2dmapPos *v=&p;
 v->x += *(signed char *)((unsigned)&sWf2dmapStepDelta.dx+i*2);
 v->y += *(signed char *)((unsigned)&sWf2dmapStepDelta.dy+i*2);
 return p;
}

/*
 * Unlabelled Thumb leaf in a .word run:
 *   ldr r1,[pc,#4]; ldrb r0,[r1,r0]; bx lr; nop; .word 0x021C6010
 * Byte i of the table sWf2dmapDirectionTable.
 */
unsigned char WF2DMAP_OBJ_GetTableByte(int i)
{
    return sWf2dmapDirectionTable[i];
}

char *WF2DMAP_OBJ_AllocSlot(unsigned *p)
{
 unsigned i=0;
 if (i<p[1]) { char *base=(char *)p[0];
 do { if (*(unsigned *)(base+i*24)==0) return base+i*24; i++; } while(i<p[1]); }
 return 0;
}

Wf2dmapPos WF2DMAP_OBJ_GetPos(char *p) { return *(Wf2dmapPos *)(p+4); }

Wf2dmapPos WF2DMAP_OBJ_GetDestPos(char *p) { return *(Wf2dmapPos *)(p+8); }

Wf2dmapPos WF2DMAP_OBJ_GetCurrentPos(char *p)
{
    int n = WF2DMAP_OBJ_GetSlot((u8 *)p, 8);
    int d = WF2DMAP_OBJ_GetSlot((u8 *)p, 9);
    Wf2dmapPos a = WF2DMAP_OBJ_GetPos(p);
    Wf2dmapPos b = WF2DMAP_OBJ_GetDestPos(p);
    a.x -= b.x;
    a.y -= b.y;
    if (n > 0) {
        a.x = n * a.x / d;
        a.y = n * a.y / d;
    } else {
        a.x = 0;
        a.y = 0;
    }
    a.x += b.x;
    a.y += b.y;
    return a;
}

void WF2DMAP_OBJ_SetPos(char *p, Wf2dmapPairU16 v)
{
    ((Wf2dmapObj *)p)->posX = v.x;
    ((Wf2dmapObj *)p)->posY = v.y;
}

void WF2DMAP_OBJ_SetDestPos(char *p, Wf2dmapPairU16 v)
{
    ((Wf2dmapObj *)p)->destX = v.x;
    ((Wf2dmapObj *)p)->destY = v.y;
}

/*
 * extent: two zero alignment bytes at 0x021C4C86 follow the function.
 * lever: Pos declaration order src,a,dst,b fixes stack slots; named qid fixes cmp order.
 */
u8 *WF2DMAP_OBJ_FindAtPos(u8 *p, void *list, int n)
{
    Wf2dmapPos src, a, dst, b;
    u32 count;
    int id;
    u32 i;
    u8 *q;
    int qid;
    src = WF2DMAP_OBJ_GetPos((char *)p);
    dst = WF2DMAP_OBJ_OffsetPos(src, n);
    id = WF2DMAP_OBJ_GetSlot(p, 4);
    count = WF2DMAP_OBJ_GetCount(list);
    for (i = 0; i < count; i++) {
        q = (u8 *)WF2DMAP_OBJ_GetByIndex2((char **)list, (u16)i);
        if (q != 0) {
            qid = WF2DMAP_OBJ_GetSlot(q, 4);
            if (qid == id) continue;
            a = WF2DMAP_OBJ_GetPos((char *)q);
            if (a.x == dst.x && a.y == dst.y) return q;
            b = WF2DMAP_OBJ_GetDestPos((char *)q);
            if (b.x == dst.x && b.y == dst.y) return q;
        }
    }
    return 0;
}

extern void (*sWf2dmapCommandTable)(char *,Wf2dmapPairU16,unsigned);

void WF2DMAP_OBJ_ApplyCommand(char *p,char *q)
{
 (*(void (**)(char *,Wf2dmapPairU16,unsigned))((unsigned)&sWf2dmapCommandTable+*(u16 *)(q+4)*4))(p,*(Wf2dmapPairU16 *)q,((Wf2dmapCmdDesc *)q)->value);
 ((Wf2dmapObj *)p)->updateCounter=0;
}
