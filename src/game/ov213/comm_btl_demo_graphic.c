/*
 * file:     comm_btl_demo_graphic.c
 * unit:     yes
 * function: func_021BAB64, func_021BAC0C, func_021BAC68, func_021BAC7C, func_021BAC88, func_021BAC94, func_021BACA0, func_021BACB4, func_021BAD14, func_021BAD4C, func_021BAD50, func_021BAD58, func_021BAD98, func_021BADB4, func_021BADBC, func_021BADC8, func_021BAE40, func_021BAE50
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
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021BB33C 0x021BB33C data a4
 *   d_021BB1C8 0x021BB1C8 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BAE64 0x021BAE64 thumb ov213
 *   func_0203F8F4 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BB17C 0x021BB17C data a4
 *   d_021BB1F8 0x021BB1F8 data a4
 *   func_020403F4 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
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
 *   func_021BAABC 0x021BAABC thumb ov213
 *   d_021BB158 0x021BB158 data a4
 *   d_021BB164 0x021BB164 data a4
 *   d_021BB170 0x021BB170 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964  0x02047964  arm
 *   func_02048AD0    0x02048AD0  arm
 *   G3D_SYSTEM_ApplyLookAt    0x020479D8  arm
 */
#include "../../matched/include/Obj25714.h"
#include "../../matched/include/Obj25715.h"
#include "../../matched/include/Obj25716.h"

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p,unsigned value,unsigned size);
extern void BG_SYS_ClearGraphicsMemory(unsigned mode);
extern void BG_SYS_SetVramBanks(const struct DispVram *p);
extern void func_0204363C(unsigned swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0201DD60(void);
extern void *func_020056A0(void *callback,void *ctx,int priority);
extern void func_02030EAC(struct Node *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BAE64(void *);
extern void func_0203F8F4(unsigned);
extern void BMP_WIN_Init(unsigned);
extern void func_0203FC28(struct DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
extern void func_020403F4(u32 i);
extern void BMP_WIN_Exit(void);
extern void func_0203F9B4(void);
extern void func_020419E4(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void func_021BAABC(void);
extern void G3D_SYSTEM_Init(u32 a,u32 b,u32 c,u32 d,u16 fifo,unsigned heap,void (*setup)(void));
extern u32 *G3D_CAMERA_Create(u32 a,u32 b,u32 c,u32 d,u32 e,u32 f,u32 g,u32 h,Vec3 *i,Vec3 *j,Vec3 *k,unsigned heap);
extern u32 G3D_CAMERA_Delete(void *ptr);
extern void G3D_SYSTEM_Exit(int);
extern void func_02047964(void);
extern void func_02048AD0(struct Light *l);
extern void G3D_SYSTEM_ApplyLookAt(void);
void *func_021BAB64(unsigned mode,unsigned heap);
void func_021BAC0C(unsigned char *p);
void func_021BAC68(char *p);
void func_021BAC7C(char *p);
void func_021BAC88(char *p);
u32 func_021BAC94(char *p);
void func_021BACA0(void *unused,char *p);
void func_021BACB4(void *p, unsigned heap);
void func_021BAD14(void *p);
void func_021BAD4C(void *a0);
void func_021BAD50(void *a0);
void func_021BAD58(void **out, int a, int b);
void func_021BAD98(void *p);
void func_021BADB4(void *a0);
void func_021BADBC(void *a0);
void *func_021BADC4(void **p);
void func_021BADC8(u32 **p,unsigned heap);
void func_021BAE40(int *p);
void func_021BAE50(int *p);
extern char d_021BB33C[];
extern const struct DispVram d_021BB1C8;
extern const unsigned d_021BB1F8[][11];
extern struct DispConfig d_021BB17C;
extern int d_021BB18C;
extern const Vec3 d_021BB158;
extern Vec3 d_021BB164,d_021BB170;
extern const unsigned char d_020A1EB8[];

void *func_021BAB64(unsigned mode,unsigned heap)
{
    unsigned char *p;
    p=func_02030734(heap,16,0,d_021BB33C,0x1B4);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021BB1C8);
    func_0204363C(mode);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    func_0201DD60();
    func_021BACB4(p,heap);
    func_021BAD58((void **)(p+4),(int)&d_021BB1C8,heap);
    func_021BADC8((unsigned **)(p+8),heap);
    ((struct Obj25714 *)p)->fC=func_020056A0((void *)func_021BACA0,p,0);
    return p;
}

void func_021BAC0C(unsigned char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj25715 *)p)->fC);
    func_021BAE40((int *)(p + 8));
    func_021BAD98(p + 4);
    func_021BAD14(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}

/*
 * EXACT* tail: two zero alignment bytes after the function.
 * Preserve the pointer explicitly loaded before the no-op/global helper call.
 */
void func_021BAC68(char *p) { func_021BADB4(p+4); func_021BAD4C(p); }

void func_021BAC7C(char *p) { func_021BAE50((int *)(p+8)); }

void func_021BAC88(char *p) { func_021BAE64(p+8); }

u32 func_021BAC94(char *p) { return (u32)func_021BADC4((void **)((u32 *)(p+4))); }

void func_021BACA0(void *unused,char *p) { func_021BAD50(p); func_021BADBC(p+4); }

void func_021BACB4(void *p, unsigned heap)
{
    const unsigned *row;
    unsigned i, layer;
    MI_CpuFill8(p, 0, 4);
    func_0203F8F4(heap);
    BMP_WIN_Init(heap);
    func_0203FC28(&d_021BB17C);
    for (i = 0; i < 6; i++) {
        row = d_021BB1F8[i];
        layer = row[0];
        func_0203FCA0((unsigned char)layer, (const struct BgTemplate *)(row + 1), (unsigned char)row[9]);
        func_020414AC(layer);
        func_02040588(layer, row[10]);
    }
}

void func_021BAD14(void *p){unsigned i;for(i=0;i<6;i++)func_020403F4((unsigned char)d_021BB1F8[i][0]);BMP_WIN_Exit();func_0203F9B4();MI_CpuFill8(p,0,4);}

/*
 * Tail: two zero alignment bytes at 021BAD4E.
 */
void func_021BAD4C(void *a0){}

void func_021BAD50(void *a0){func_020419E4();}


void func_021BAD58(void **out, int a, int b)
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
void func_021BAD98(void *p){CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj25716 *)p)->f0);CLACT_ExitSystem();MI_CpuFill8(p,0,4);}

void func_021BADB4(void *a0){CLACT_DrawSystem();}

void func_021BADBC(void *a0){CLACT_VBlankSystem();}

void *func_021BADC4(void **p){return *p;}

/*
 * lever: const ROM table orders signed halfword loads and pool entries.
 * width: both heap externs widened: 021BADD6/021BAE1C store full r1.
 */
void func_021BADC8(u32 **p,unsigned heap)
{
    Vec3 copy;
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021BAABC);
    copy=d_021BB158;
    *p=G3D_CAMERA_Create(0,*(const short *)(d_020A1EB8+12),*(const short *)(d_020A1EB8+14),0x1555,0,0x1000,0x400000,0,&d_021BB170,&copy,&d_021BB164,heap);
}


void func_021BAE40(int *p)
{
    G3D_SYSTEM_Exit(G3D_CAMERA_Delete((void *)(*p)));
}


void func_021BAE50(int *p)
{
    func_02047964();
    func_02048AD0((struct Light *)(*p));
    G3D_SYSTEM_ApplyLookAt();
}
