/*
 * file:     wifibattlematch_graphic.c
 * unit:     yes
 * function: func_021E5440, func_021E54E0, func_021E5534, func_021E5548, func_021E5554, func_021E5568, func_021E55C8, func_021E5600, func_021E5604, func_021E560C, func_021E564C, func_021E5668, func_021E5670, func_021E5678
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
 *   func_020403F4  0x020403F4  arm
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
#include "../../matched/include/Obj24443.h"
#include "../../matched/include/Obj24444.h"
#include "wifibattlematch_graphic_shared_types.h"

struct DispVram;

struct Node;

struct BgTemplate;

struct DispConfig;

struct Bank;

typedef struct { unsigned id; unsigned template[8]; unsigned type; unsigned enable; } Entry_021E5568;

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

extern void func_020403F4(u32 i);

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

int *func_021E5440(unsigned swap, u16 heap);

void func_021E54E0(char *p);

void func_021E5534(u8 *p);

int func_021E5548(int *p);

void func_021E5554(int a, int *p);

void func_021E5568(void *p, unsigned short heap);

void func_021E55C8(void *p);

void func_021E5600(void *p);

void func_021E5604(int *a0);

void func_021E560C(int *p, int b, int c);

void func_021E564C(int *p);

void func_021E5668(void *p);

void func_021E5670(int *a0);

int func_021E5678(int *p);

extern const char d_021E8DA0[];

extern const unsigned d_021E8B2C[];

extern const unsigned d_021E8B00[];

extern const Entry_021E5568 d_021E8B5C[];

extern unsigned char d_021E8B10[];

int *func_021E5440(unsigned swap, u16 heap)
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
    func_021E5568(p, heap);
    func_021E560C(p + 1, (int)d_021E8B2C, heap);
    p[3] = func_020056A0(func_021E5554, p, 0);
    return p;
}

/*
 * volatile: display registers 04000050/04001050 cleared; DISPCNT 04000000/04001000 read-modify-write at 021E5506-021E5514.
 */
void func_021E54E0(char *p)
{
    func_02030EAC(((struct Obj24443 *)p)->fC);
    func_021E564C((int *)(p + 4));
    func_021E55C8(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p, 0, 0x10);
    func_020307B0(p);
}

void func_021E5534(u8 *p)
{
    func_021E5668(p + 4);
    func_021E5600(p);
}

/*
 * Unlabelled ov177 thunk hidden in a word run: tail-calls func_021E5678 with
 * its pointer argument advanced by one word.  Matched to supply the `matched`
 * witness for the pending ov176 caller func_0217AF2C.
 */
int func_021E5548(int *p)
{
    return func_021E5678(p + 1);
}

void func_021E5554(int a, int *p)
{
    func_021E5604(p);
    func_021E5670((int *)((char *)p + 4));
}

void func_021E5568(void *p, unsigned short heap)
{
    unsigned i;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021E8B00);
    for (i = 0; i < 8; i++) {
        const Entry_021E5568 *e = &d_021E8B5C[i];
        unsigned id = e->id;
        BG_SYS_InitBgLayer((unsigned char)id, (const struct BgTemplate *)(&e->template), (unsigned char)e->type);
        BG_SYS_FreeSlot(id);
        func_02040588(id, e->enable);
    }
}

void func_021E55C8(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_020403F4((u8)d_021E8B5C[i].id);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}

void func_021E5600(void *p)
{
}

void func_021E5604(int *a0)
{
    BG_SYS_Update();
}

/*
 * Bring up the graphics object: clear four words, submit the table and
 *   latch the 0x80-byte handle.
 */
void func_021E560C(int *p, int b, int c)
{
    MI_CpuFill8((void *)((int)p), 0, 4);
    CLACT_InitSystem((const struct Cfg *)d_021E8B10, b, c);
    p[0] = (int)CLACT_CreateUnit(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void func_021E564C(int *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj24444 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void func_021E5668(void *p)
{
    CLACT_DrawSystem();
}

void func_021E5670(int *a0)
{
    CLACT_VBlankSystem();
}

/*
 * Unlabelled ov177 leaf: loads the word its argument points at.  Matched as
 * the bottom-up dependency of the ov177 thunk func_021E5548.
 */
int func_021E5678(int *p)
{
    return *p;
}
