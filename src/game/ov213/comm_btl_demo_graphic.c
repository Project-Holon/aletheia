/*
 * file:     comm_btl_demo_graphic.c
 * unit:     yes
 * function: COMM_BTL_DEMO_GRAPHIC_Create, COMM_BTL_DEMO_GRAPHIC_Delete, COMM_BTL_DEMO_GRAPHIC_Draw, COMM_BTL_DEMO_GRAPHIC_Draw3d, COMM_BTL_DEMO_GRAPHIC_DrawEnd, COMM_BTL_DEMO_GRAPHIC_GetCamera, COMM_BTL_DEMO_GRAPHIC_VBlank, COMM_BTL_DEMO_GRAPHIC_InitBg, COMM_BTL_DEMO_GRAPHIC_DeleteBg, COMM_BTL_DEMO_GRAPHIC_Noop, COMM_BTL_DEMO_GRAPHIC_TickDisplay, COMM_BTL_DEMO_GRAPHIC_InitClact, COMM_BTL_DEMO_GRAPHIC_DeleteClact, COMM_BTL_DEMO_GRAPHIC_DrawClact, COMM_BTL_DEMO_GRAPHIC_VBlankClact, COMM_BTL_DEMO_GRAPHIC_InitG3d, COMM_BTL_DEMO_GRAPHIC_DeleteG3d, COMM_BTL_DEMO_GRAPHIC_DrawG3d, COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd
 * address:  0x021BAB64
 * region:   ov213
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * leaf: parent-cleared sole ov213 blocker of COMM_BTL_DEMO_GRAPHIC_DrawEnd; eight-byte tail stub.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   d_021BB33C 0x021BB33C data a4
 *   d_021BB1C8 0x021BB1C8 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BB17C 0x021BB17C data a4
 *   d_021BB1F8 0x021BB1F8 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem  0x0204A48C  arm
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   d_021BB18C     0x021BB18C  data  a4
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   COMM_BTL_DEMO_MAIN_Init3dSystem 0x021BAABC thumb ov213
 *   d_021BB158 0x021BB158 data a4
 *   d_021BB164 0x021BB164 data a4
 *   d_021BB170 0x021BB170 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964  0x02047964  arm
 *   G3D_CAMERA_Reset    0x02048AD0  arm
 *   G3D_SYSTEM_ApplyLookAt    0x020479D8  arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 */

struct DispVram;
struct Node;
struct DispConfig;
struct BgTemplate;
struct Cfg;
struct Bank;
struct Light;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef short s16;

typedef struct {u32 x,y,z;} Vec3;

struct CommBtlDemoGraphic {
    u8 bgData[4];
    struct Bank *clactUnit;
    u32 *g3dCamera;
    void *vblankHandle;
};

/* offset-0 view of the clact slot: the clact helpers receive work + 4 */
struct CommBtlDemoClact {
    struct Bank *bank;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p,unsigned value,unsigned size);
extern void BG_SYS_ClearGraphicsMemory(unsigned mode);
extern void BG_SYS_SetVramBanks(const struct DispVram *p);
extern void BMP_SetDisplaySwap(unsigned swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void *GFL_USE_AddMainTask(void *callback,void *ctx,int priority);
extern void TCB_DeleteTask(struct Node *);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_Create(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(unsigned char);
extern void BG_SYS_SetPlaneVisible(unsigned char, unsigned char);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void COMM_BTL_DEMO_MAIN_Init3dSystem(void);
extern void G3D_SYSTEM_Init(u32 a,u32 b,u32 c,u32 d,u16 fifo,unsigned heap,void (*setup)(void));
extern u32 *G3D_CAMERA_Create(u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h,Vec3 *i,Vec3 *j,Vec3 *k,unsigned heap);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void G3D_CAMERA_Reset(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
void *COMM_BTL_DEMO_GRAPHIC_Create(unsigned mode,unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *p);
void COMM_BTL_DEMO_GRAPHIC_Draw(char *p);
void COMM_BTL_DEMO_GRAPHIC_Draw3d(char *p);
void COMM_BTL_DEMO_GRAPHIC_DrawEnd(char *p);
u32 COMM_BTL_DEMO_GRAPHIC_GetCamera(char *p);
void COMM_BTL_DEMO_GRAPHIC_VBlank(void *unused,char *p);
void COMM_BTL_DEMO_GRAPHIC_InitBg(void *p, unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_DeleteBg(void *p);
void COMM_BTL_DEMO_GRAPHIC_Noop(void *a0);
void COMM_BTL_DEMO_GRAPHIC_TickDisplay(void *a0);
void COMM_BTL_DEMO_GRAPHIC_InitClact(void **out, int a, int b);
void COMM_BTL_DEMO_GRAPHIC_DeleteClact(void *p);
void COMM_BTL_DEMO_GRAPHIC_DrawClact(void *a0);
void COMM_BTL_DEMO_GRAPHIC_VBlankClact(void *a0);
void *COMM_BTL_DEMO_GRAPHIC_GetClactBank(void **p);
void COMM_BTL_DEMO_GRAPHIC_InitG3d(u32 **p,unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_DeleteG3d(int *p);
void COMM_BTL_DEMO_GRAPHIC_DrawG3d(int *p);
void COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(void *unused);
extern char d_021BB33C[];
extern const struct DispVram d_021BB1C8;
extern const unsigned d_021BB1F8[][11];
extern struct DispConfig d_021BB17C;
extern int d_021BB18C;
extern const Vec3 d_021BB158;
extern Vec3 d_021BB164,d_021BB170;
extern const unsigned char d_020A1EB8[];


void *COMM_BTL_DEMO_GRAPHIC_Create(unsigned mode,unsigned heap)
{
    unsigned char *p;
    p=GFL_HEAP_Alloc(heap,16,0,d_021BB33C,0x1B4);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BB1C8);
    BMP_SetDisplaySwap(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    COMM_BTL_DEMO_GRAPHIC_InitBg(p,heap);
    COMM_BTL_DEMO_GRAPHIC_InitClact((void **)(p+4),(int)&d_021BB1C8,heap);
    COMM_BTL_DEMO_GRAPHIC_InitG3d((unsigned **)(p+8),heap);
    ((struct CommBtlDemoGraphic *)p)->vblankHandle=GFL_USE_AddMainTask((void *)COMM_BTL_DEMO_GRAPHIC_VBlank,p,0);
    return p;
}


void COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *p)
{
    TCB_DeleteTask((struct Node *)((struct CommBtlDemoGraphic *)p)->vblankHandle);
    COMM_BTL_DEMO_GRAPHIC_DeleteG3d((int *)(p + 8));
    COMM_BTL_DEMO_GRAPHIC_DeleteClact(p + 4);
    COMM_BTL_DEMO_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p, 0, 0x10);
    GFL_HEAP_Free(p);
}


/*
 * EXACT* tail: two zero alignment bytes after the function.
 * Preserve the pointer explicitly loaded before the no-op/global helper call.
 */
void COMM_BTL_DEMO_GRAPHIC_Draw(char *p) { COMM_BTL_DEMO_GRAPHIC_DrawClact(p+4); COMM_BTL_DEMO_GRAPHIC_Noop(p); }


void COMM_BTL_DEMO_GRAPHIC_Draw3d(char *p) { COMM_BTL_DEMO_GRAPHIC_DrawG3d((int *)(p+8)); }


void COMM_BTL_DEMO_GRAPHIC_DrawEnd(char *p) { COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(p+8); }


u32 COMM_BTL_DEMO_GRAPHIC_GetCamera(char *p) { return (u32)COMM_BTL_DEMO_GRAPHIC_GetClactBank((void **)((u32 *)(p+4))); }


void COMM_BTL_DEMO_GRAPHIC_VBlank(void *unused,char *p) { COMM_BTL_DEMO_GRAPHIC_TickDisplay(p); COMM_BTL_DEMO_GRAPHIC_VBlankClact(p+4); }


void COMM_BTL_DEMO_GRAPHIC_InitBg(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode(&d_021BB17C);
    for (i = 0; i < 6; i++) {
        row = d_021BB1F8[i];
        layer = row[0];
        BG_SYS_InitBgLayer((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        BG_SYS_FreeSlot(layer);
        BG_SYS_SetPlaneVisible(layer, row[10]);
    }
}


void COMM_BTL_DEMO_GRAPHIC_DeleteBg(void *p){unsigned i;for(i=0;i<6;i++)BG_SYS_FreeLayerBuf((unsigned char)d_021BB1F8[i][0]);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}


/*
 * Tail: two zero alignment bytes at 021BAD4E.
 */
void COMM_BTL_DEMO_GRAPHIC_Noop(void *a0){}


void COMM_BTL_DEMO_GRAPHIC_TickDisplay(void *a0){BG_SYS_Update();}



void COMM_BTL_DEMO_GRAPHIC_InitClact(void **out, int a, int b)
{
    MI_CpuFill8(out, 0, 4);
    CLACT_InitSystem((const struct Cfg *)(&d_021BB18C), a, b);
    *out = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(*out);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}


/*
 * Tail: two zero alignment bytes at 021BADB2.
 */
void COMM_BTL_DEMO_GRAPHIC_DeleteClact(void *p){CLACT_DeleteUnit(((struct CommBtlDemoClact *)p)->bank);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}


void COMM_BTL_DEMO_GRAPHIC_DrawClact(void *a0){CLACT_DrawSystem();}


void COMM_BTL_DEMO_GRAPHIC_VBlankClact(void *a0){CLACT_VBlankSystem();}


void *COMM_BTL_DEMO_GRAPHIC_GetClactBank(void **p){return *p;}


/*
 * lever: const ROM table orders signed halfword loads and pool entries.
 * width: both heap externs widened: 021BADD6/021BAE1C store full r1.
 */
void COMM_BTL_DEMO_GRAPHIC_InitG3d(u32 **p,unsigned heap)
{
    Vec3 copy;
    G3D_SYSTEM_Init(0,1,0,1,0,heap,COMM_BTL_DEMO_MAIN_Init3dSystem);
    copy=d_021BB158;
    *p=G3D_CAMERA_Create(0,*(const short *)(d_020A1EB8+12),*(const short *)(d_020A1EB8+14),0x1555,0,0x1000,0x400000,0,&d_021BB170,&copy,&d_021BB164,heap);
}



void COMM_BTL_DEMO_GRAPHIC_DeleteG3d(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}



void COMM_BTL_DEMO_GRAPHIC_DrawG3d(int *p)
{
    func_02047964();
    G3D_CAMERA_Reset((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}

void COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(void *unused) { G3D_SYSTEM_DrawEnd(); }
