/*
 * file:     b_app_tool.c
 * unit:     yes
 * function: B_APP_TOOL_Create, B_APP_TOOL_Delete, B_APP_TOOL_CreateActors, B_APP_TOOL_DeleteActors, B_APP_TOOL_SetActorsVisible, B_APP_TOOL_LayoutActors, B_APP_TOOL_ShowWindow, B_APP_TOOL_ShowWindows, B_APP_TOOL_Update
 * address:  0x0220AF40
 * region:   ov196
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * extent: intended code is 66 bytes; the handed tail is zero alignment and b_sap_ptool.c string data, not follower code.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_0220B100 0x0220B100 data a4
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
struct Obj;
struct Vec2;
struct Descriptor;
struct Cfg;
struct PrintSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

/* Actor creation record read by CLACT_CreateActor (8 bytes). */
typedef struct BAppToolActorPos {
    u16 x;      /* 0x00 */
    u16 y;      /* 0x02 */
    u16 z;      /* 0x04, the actor index here */
    u8 mode;    /* 0x06, actor blend/anim mode */
    u8 space;   /* 0x07, always 1 here */
} BAppToolActorPos;

/* 2D point read by CLACT_AddActorSurfacePos (4 bytes). */
typedef struct BAppToolLayoutPos {
    u16 x;      /* 0x00 */
    u16 y;      /* 0x02 */
} BAppToolLayoutPos;

/* One window entry walked by B_APP_TOOL_Update (8 bytes). */
typedef struct BAppToolEntry {
    int handle;             /* 0x00, descriptor handle */
    unsigned char active;   /* 0x04 */
    unsigned char pad[3];   /* 0x05, alignment only */
} BAppToolEntry;

/* The tool object allocated by B_APP_TOOL_Create (0x18 bytes). */
typedef struct BAppTool {
    int actors[4];      /* 0x00: CLACT actor handles */
    u16 heapId;         /* 0x10: heap used for the tool and its actors */
    u16 pad12;          /* 0x12 */
    void *visible;      /* 0x14: last visibility value passed to SetActorsVisible */
} BAppTool;

typedef char BAppTool_size_check[(sizeof(BAppTool) == 0x18) ? 1 : -1];
typedef char BAppToolEntry_size_check[(sizeof(BAppToolEntry) == 0x8) ? 1 : -1];

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern int CLACT_CreateActor(int, int, int, int, void *, int, u16);
struct Actor;
extern void CLACT_SetActorPaletteOffset(struct Actor *actor, unsigned int offset, unsigned int pltt_op);
extern void CLACT_SetActorAutoAnim(struct Actor *actor, unsigned int enable);
extern void CLACT_DeleteActor(struct Actor *actor);
extern void CLACT_SetActorDrawEnable(struct Actor *actor, unsigned int value);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct BmpWin;
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *win);
extern void BG_SYS_MarkTileDirty(u32);
struct PrintQueue;
extern u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
u8 *B_APP_TOOL_Create(u16 heapId);
void B_APP_TOOL_Delete(void *p);
void B_APP_TOOL_CreateActors(char *p, int owner, int charRes, int palRes, int cellRes);
void B_APP_TOOL_DeleteActors(u8 *p);
void B_APP_TOOL_SetActorsVisible(char *p, void *visible);
void B_APP_TOOL_LayoutActors(int *p, u8 *q);
void B_APP_TOOL_ShowWindow(void **p);
void B_APP_TOOL_ShowWindows(char *p, unsigned char *q);
void B_APP_TOOL_Update(BAppToolEntry *p, struct PrintSys *printSys, unsigned n);
extern const char d_0220B100[];


u8 *B_APP_TOOL_Create(u16 heapId) { BAppTool *tool; tool=(BAppTool *)GFL_HEAP_Alloc(heapId,24,0,d_0220B100,43); tool->heapId=heapId; tool->visible=(void *)1; return (u8 *)tool; }


/*
 * leaf: parent-cleared sole blocker of ov197 B_BAG_MAIN_StateExit; eight-byte tail stub.
 */
void B_APP_TOOL_Delete(void *p)
{
    GFL_HEAP_Free(p);
}


void B_APP_TOOL_CreateActors(char *p, int owner, int charRes, int palRes, int cellRes)
{
    BAppTool *tool = (BAppTool *)p;
    BAppToolActorPos pos;
    unsigned i;
    pos.x=0;pos.y=0;pos.mode=0;pos.space=1;
    for(i=0;i<4;i++) {
        pos.z=i;
        tool->actors[i]=CLACT_CreateActor(owner,charRes,palRes,cellRes,&pos,1,tool->heapId);
        CLACT_SetActorPaletteOffset((struct Actor *)tool->actors[i],0,1);
        CLACT_SetActorAutoAnim((struct Actor *)tool->actors[i],1);
    }
}



/*
 * Addresses are Black-image addresses.
 */
void B_APP_TOOL_DeleteActors(u8 *p)
{
    BAppTool *tool = (BAppTool *)p;
    u32 i;

    for (i = 0; i < 4; i++) {
        CLACT_DeleteActor((struct Actor *)tool->actors[i]);
    }
}



void B_APP_TOOL_SetActorsVisible(char *p, void *visible)
{
    BAppTool *tool = (BAppTool *)p;
    if (tool->visible != visible)
    {
        unsigned int i;
        for (i = 0; i < 4; i++)
        {
            CLACT_SetActorDrawEnable((void *)tool->actors[i], (unsigned int)visible);
        }
        tool->visible = visible;
    }
}


void B_APP_TOOL_LayoutActors(int *actors, u8 *rect)
{
    BAppToolLayoutPos pos;
    u8 halfH=rect[3]/2;
    u8 halfW=rect[2]/2;
    pos.x=rect[0]-halfW;pos.y=rect[1]-halfH;CLACT_AddActorSurfacePos((struct Obj *)actors[0],(const struct Vec2 *)(&pos),1);
    pos.x=rect[0]-halfW;pos.y=rect[1]+halfH;CLACT_AddActorSurfacePos((struct Obj *)actors[1],(const struct Vec2 *)(&pos),1);
    pos.x=rect[0]+halfW;pos.y=rect[1]-halfH;CLACT_AddActorSurfacePos((struct Obj *)actors[2],(const struct Vec2 *)(&pos),1);
    pos.x=rect[0]+halfW;pos.y=rect[1]+halfH;CLACT_AddActorSurfacePos((struct Obj *)actors[3],(const struct Vec2 *)(&pos),1);
}


/*
 * EXACT* tail: two zero alignment bytes after the function.
 */
void B_APP_TOOL_ShowWindow(void **p) { BMP_WIN_MakeScreen((struct BmpWin *)*p); BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)*p)); }



void B_APP_TOOL_ShowWindows(char *windows, unsigned char *order)
{
    int i = 0;
    for (;;) {
        unsigned char slot = order[i];
        if (slot == 0xff)
            break;
        B_APP_TOOL_ShowWindow((void **)(windows + (slot << 3)));
        i++;
    }
}

void B_APP_TOOL_Update(BAppToolEntry *p, struct PrintSys *printSys, unsigned n)
{
    unsigned i;
    PRINTSYS_QUE_Main((struct PrintQueue *)printSys);
    for(i=0;i<n;i++) {
        if(p[i].active && PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)printSys,(void *)((int)BMP_WIN_GetBmp((struct BmpWin *)p[i].handle)))==0) {
            BMP_WIN_TransferChars((struct BmpWin *)p[i].handle);
            p[i].active=0;
        }
    }
}
