/*
 * file:     wifibattlematch_graphic.c
 * unit:     yes
 * function: WIFIBATTLEMATCH_GRAPHIC_Create, WIFIBATTLEMATCH_GRAPHIC_Delete, WIFIBATTLEMATCH_GRAPHIC_Draw, WIFIBATTLEMATCH_GRAPHIC_GetCamera, WIFIBATTLEMATCH_GRAPHIC_VBlank, WIFIBATTLEMATCH_GRAPHIC_InitBg, WIFIBATTLEMATCH_GRAPHIC_DeleteBg, WIFIBATTLEMATCH_GRAPHIC_Noop, WIFIBATTLEMATCH_GRAPHIC_TickDisplay, WIFIBATTLEMATCH_GRAPHIC_InitClact, WIFIBATTLEMATCH_GRAPHIC_DeleteClact, WIFIBATTLEMATCH_GRAPHIC_DrawClact, WIFIBATTLEMATCH_GRAPHIC_VBlankClact, WIFIBATTLEMATCH_GRAPHIC_GetClactBank
 * address:  0x021E5440
 * region:   ov177
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifibattlematch_view.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_021E8DA0 0x021E8DA0 data a1
 *   d_021E8B2C 0x021E8B2C data a4
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021E8B00 0x021E8B00 data a4
 *   d_021E8B5C 0x021E8B5C data a4
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BMP_WIN_Exit  0x020450C8  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   d_021E8B10      0x021E8B10  data
 *   CLACT_InitSystem   0x0204A48C  arm
 *   CLACT_CreateUnit   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   BG_SYS_SetMainPlaneVisible   0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible   0x02043598  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   CLACT_DrawSystem  0x0204A600  arm
 *   CLACT_VBlankSystem  0x0204A648  arm
 */
#include "wifibattlematch_graphic_shared_types.h"

struct DispVram;

struct Node;

struct BgTemplate;

struct DispConfig;

struct Bank;

typedef struct { unsigned id; unsigned template[8]; unsigned type; unsigned enable; } WifibattlematchBgEntry;

struct WifibattlematchGraphic {
    u8 bgData[4];
    struct Bank *clactUnit;
    u8 pad8[4];
    u32 vblankHandle;
};

/* offset-0 view of the clact slot: the clact helpers receive work + 4 */
struct WifibattlematchClact {
    struct Bank *bank;
};

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void MI_CpuFill8(void *, u8, u32);

extern void BG_SYS_ClearGraphicsMemory(unsigned);

extern void BG_SYS_SetVramBanks(const struct DispVram *c);

extern void BMP_SetDisplaySwap(unsigned);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void GF_FONT_InitTextColor(void);

extern int func_020056A0(void (*)(int, int *), int *, int);

extern void func_02030EAC(struct Node *n);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 func_020307B0(void *p);

extern void BG_SYS_Create(unsigned short);

extern void BMP_WIN_Init(unsigned short);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void BG_SYS_FreeSlot(unsigned char);

extern void func_02040588(unsigned char, unsigned char);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_Update(void);

extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned swap, u16 heap);

void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p);

void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p);

int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p);

void WIFIBATTLEMATCH_GRAPHIC_VBlank(int a, int *p);

void WIFIBATTLEMATCH_GRAPHIC_InitBg(void *p, unsigned short heap);

void WIFIBATTLEMATCH_GRAPHIC_DeleteBg(void *p);

void WIFIBATTLEMATCH_GRAPHIC_Noop(void *p);

void WIFIBATTLEMATCH_GRAPHIC_TickDisplay(int *a0);

void WIFIBATTLEMATCH_GRAPHIC_InitClact(int *p, int b, int c);

void WIFIBATTLEMATCH_GRAPHIC_DeleteClact(int *p);

void WIFIBATTLEMATCH_GRAPHIC_DrawClact(void *p);

void WIFIBATTLEMATCH_GRAPHIC_VBlankClact(int *a0);

int WIFIBATTLEMATCH_GRAPHIC_GetClactBank(int *p);

extern const char d_021E8DA0[];

extern const unsigned d_021E8B2C[];

extern const unsigned d_021E8B00[];

extern const WifibattlematchBgEntry d_021E8B5C[];

extern unsigned char d_021E8B10[];

int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned swap, u16 heap)
{
    int *p = func_02030734(heap, 16, 0, d_021E8DA0, 0x1BB);
    MI_CpuFill8(p, 0, 16);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021E8B2C);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    WIFIBATTLEMATCH_GRAPHIC_InitBg(p, heap);
    WIFIBATTLEMATCH_GRAPHIC_InitClact(p + 1, (int)d_021E8B2C, heap);
    ((struct WifibattlematchGraphic *)p)->vblankHandle = func_020056A0(WIFIBATTLEMATCH_GRAPHIC_VBlank, p, 0);
    return p;
}

/*
 * volatile: display registers 04000050/04001050 cleared; DISPCNT 04000000/04001000 read-modify-write at 021E5506-021E5514.
 */
void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p)
{
    func_02030EAC((struct Node *)((struct WifibattlematchGraphic *)p)->vblankHandle);
    WIFIBATTLEMATCH_GRAPHIC_DeleteClact((int *)(p + 4));
    WIFIBATTLEMATCH_GRAPHIC_DeleteBg(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}

void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p)
{
    WIFIBATTLEMATCH_GRAPHIC_DrawClact(p + 4);
    WIFIBATTLEMATCH_GRAPHIC_Noop(p);
}

/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls WIFIBATTLEMATCH_GRAPHIC_GetClactBank with
 * its pointer argument advanced by one word.  Matched to supply the `matched`
 * witness for the pending ov176 caller BATTLE_CHAMPIONSHIP_FLOW_CreateView.
 */
int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p)
{
    return WIFIBATTLEMATCH_GRAPHIC_GetClactBank(p + 1);
}

void WIFIBATTLEMATCH_GRAPHIC_VBlank(int a, int *p)
{
    WIFIBATTLEMATCH_GRAPHIC_TickDisplay(p);
    WIFIBATTLEMATCH_GRAPHIC_VBlankClact((int *)((char *)p + 4));
}

void WIFIBATTLEMATCH_GRAPHIC_InitBg(void *p, unsigned short heap)
{
    unsigned i;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021E8B00);
    for (i = 0; i < 8; i++) {
        const WifibattlematchBgEntry *e = &d_021E8B5C[i];
        unsigned id = e->id;
        BG_SYS_InitBgLayer((unsigned char)id, (const struct BgTemplate *)(&e->template), (unsigned char)e->type);
        BG_SYS_FreeSlot(id);
        func_02040588(id, e->enable);
    }
}

void WIFIBATTLEMATCH_GRAPHIC_DeleteBg(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        BG_SYS_FreeLayerBuf((u8)d_021E8B5C[i].id);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}

void WIFIBATTLEMATCH_GRAPHIC_Noop(void *p)
{
}

void WIFIBATTLEMATCH_GRAPHIC_TickDisplay(int *a0)
{
    BG_SYS_Update();
}

/*
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */
void WIFIBATTLEMATCH_GRAPHIC_InitClact(int *p, int b, int c)
{
    MI_CpuFill8((void *)((int)p), 0, 4);
    CLACT_InitSystem((const struct Cfg *)d_021E8B10, b, c);
    p[0] = (int)CLACT_CreateUnit(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void WIFIBATTLEMATCH_GRAPHIC_DeleteClact(int *p)
{
    CLACT_DeleteUnit(((struct WifibattlematchClact *)p)->bank);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void WIFIBATTLEMATCH_GRAPHIC_DrawClact(void *p)
{
    CLACT_DrawSystem();
}

void WIFIBATTLEMATCH_GRAPHIC_VBlankClact(int *a0)
{
    CLACT_VBlankSystem();
}

/*
 * Unlabelled ov177 leaf: loads the word its argument points at.  Matched as
 * the bottom-up dependency of the ov177 thunk WIFIBATTLEMATCH_GRAPHIC_GetCamera.
 */
int WIFIBATTLEMATCH_GRAPHIC_GetClactBank(int *p)
{
    return *p;
}
