/*
 * file:     intro_mcss.c
 * unit:     yes
 * function: func_021BF594, func_021BF5E0, func_021BF610, func_021BF624
 * address:  0x021BF594
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from intro_cmd.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   site 0x021C0AE4 data a1
 *   site_021C0AF0 0x021C0AF0 data ov204
 *   MCSS_SetPaletteTransAdrs 0x02016024 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   defaultPos 0x021C08F0 data ov204
 *   func_021BF7F0 0x021BF7F0 thumb ov204
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_Init  0x02014B08  thumb  arm9
 *   MCSS_Add  0x020159C8  thumb  arm9
 *   MCSS_SetAnimCallback  0x02015F2C  thumb  arm9
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb  arm9
 */
#include "../../matched/include/Obj14626.h"
#include "../../matched/include/Obj14627.h"
#include "../../matched/include/Obj25390.h"
#include "intro_cmd_shared_types.h"
#include "intro_msg_shared_types.h"

struct McssSys;

struct Sub150;

struct Vec { int v[3]; };

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 func_020307B0(void *p);

extern void *MCSS_Init(u32 id, void *heap);

extern void MCSS_SetTextureTransAdrs(void *, unsigned int);

extern void MCSS_SetPaletteTransAdrs(char *p, unsigned int v);

extern void MCSS_SetOrthoMode(void *);

extern void MCSS_Del(void *,void *);

extern void MCSS_Exit(u8 *);

extern void MCSS_Main(char *);

extern void MCSS_Draw(struct McssSys *);

extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);

extern void MCSS_SetScale(void *p, u32 *src);

extern void func_021BF7F0(u8 *p);

extern void MCSS_SetAnimCallback(void *, void *, void (*)(void *, void *), int);

void *func_021BF594(unsigned int heap, int kind);

void func_021BF5E0(u8 *p);

void func_021BF610(u8 *p);

void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);

extern const char site_021C0AF0[];

extern const struct Vec defaultPos;

void *func_021BF594(unsigned int heap, int kind)
{
    char *p = func_02030734(heap, 108, 1, site_021C0AF0, 98);
    *(void **)(p + 4) = MCSS_Init(8, (void *)heap);
    *(unsigned short *)p = heap;
    if (kind != 7)
        MCSS_SetTextureTransAdrs(*(void **)(p + 4), 7 << 16);
    MCSS_SetPaletteTransAdrs(*(void **)(p + 4), 1 << 14);
    MCSS_SetOrthoMode(*(void **)(p + 4));
    return p;
}

void func_021BF5E0(u8 *p)
{
    int i;
    for(i=0;i<8;i++)if(*(void **)((u32)p+(u32)i*12+8)!=0)MCSS_Del(((struct Obj14626 *)p)->f4,*(void **)((u32)p+(u32)i*12+8));
    MCSS_Exit(*(u8 * *)&((struct Obj14626 *)p)->f4);
    func_020307B0(p);
}

void func_021BF610(u8 *p)
{
    MCSS_Main(*(char * *)&((struct Obj14627 *)p)->f4);
    MCSS_Draw(*(struct McssSys * *)&((struct Obj14627 *)p)->f4);
}

/*
 * Enum zero preserves the clear before the indexed base add.
 */
void func_021BF624(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i)
{
    struct Vec pos = defaultPos;
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    *(void **)(base + off) = MCSS_Add(((struct Obj25390 *)p)->f4, a, b, c, d);
    MCSS_SetScale(*(void **)(base + off), (u32 *)(&pos));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = 1;
    MCSS_SetAnimCallback(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}
