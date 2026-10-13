/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007AC8
 * packet:   pkt_020075B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: BOX_SAVEDATA_Delete, BOX_SAVEDATA_ClearBoxPage, BOX_SAVEDATA_GetBoxDataSize, BOX_SAVEDATA_GetBoxPokemon,
 *           PERAPVOICE_GetSize, PERAPVOICE_Init, PERAPVOICE_Create, PERAPVOICE_GetFromSave,
 *           PERAPVOICE_IsRecorded
 *
 * symbols:
 *   sub_02007B20_File  0x020A707C  data
 *   SAVE_CONTROL_GetBlock       0x020071CC  thumb
 *   POKE_TOOL_ClearBoxParam       0x02017550  thumb
 *   func_02030734      0x02030734  arm
 *   func_020307B0      0x020307B0  arm
 *   func_02082A7C      0x02082A7C  arm
 *
 * The two block lookups everything above goes through, the page clear, and
 * a constructor.  PERAPVOICE_Create passes 0x020A707C to the debug allocator at
 * 0x02030734 with the line number 0x57, and the bytes at 0x020A707C spell
 * "perapvoice.c", so the second half of this range is that file.  The
 * string is named by one pool word in the whole image and it is this
 * function's own, so the `literal` class discards its only witness; the
 * `string` class closes it, because "box_savedata.c" ends with its NUL at
 * 0x020A707A and one byte of padding puts the next string at 0x020A707C by
 * construction.
 *
 * Three of the nine carry no label, all because they save nothing.
 * BOX_SAVEDATA_GetBoxDataSize and PERAPVOICE_GetSize return the two object sizes, 0xFF0 and
 * 0x3EC, each as `movs` plus `lsls` rather than a pool word; 0x3EC is what
 * PERAPVOICE_Init clears and what PERAPVOICE_Create allocates, which is how the
 * three tie together.  BOX_SAVEDATA_GetBoxPokemon is a tail call through a pool word, and
 * it is the function every accessor above reaches the entry array with.
 */
#include "../include/Obj16869.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02007AC8Entry {
    u8 data[0x88];
};

extern const char sub_02007B20_File[];

typedef unsigned short u16;
struct Sub020071CCCtrl;
extern void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id);
struct Sav;
extern void POKE_TOOL_ClearBoxParam(struct Sav *entry);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082A7C(u32 value, void *dest, u32 size);

void PERAPVOICE_Init(void *p);

void BOX_SAVEDATA_Delete(void *p)
{
    func_020307B0(p);
}

void BOX_SAVEDATA_ClearBoxPage(struct Sub02007AC8Entry *base)
{
    u32 i;

    for (i = 0; i < 30; i++) {
        POKE_TOOL_ClearBoxParam((struct Sav *)&base[i]);
    }
}

u32 BOX_SAVEDATA_GetBoxDataSize(void)
{
    return 0xFF0;
}

struct Sub02007AC8Entry *BOX_SAVEDATA_GetBoxPokemon(void **save, u32 box)
{
    return SAVE_CONTROL_GetBlock(*save, box + 1);
}

u32 PERAPVOICE_GetSize(void)
{
    return 0x3EC;
}

void PERAPVOICE_Init(void *p)
{
    func_02082A7C(0, p, 0x3EC);
    ((struct Obj16869 *)p)->f0 = 0;
}

void *PERAPVOICE_Create(u32 heap)
{
    void *p = func_02030734(heap, 0x3EC, 1, sub_02007B20_File, 0x57);

    PERAPVOICE_Init(p);
    return p;
}

struct Sub02007AC8Entry *PERAPVOICE_GetFromSave(void *sys)
{
    return SAVE_CONTROL_GetBlock(sys, 0x24);
}

void *PERAPVOICE_IsRecorded(void **p)
{
    return *p;
}
