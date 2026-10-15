/*
 * function: BOX2_SEQ_DrawTileEntry
 * address: 0x021EAFBC
 * packet: pkt_ov170_021EAFBC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BOX2_SEQ_SetDirtyBit 0x021EAAE4 thumb ov170
 *   BOX2_SEQ_PrintTextWinEx 0x021EAC28 thumb ov170
 *   func_0201D304 0x0201D304 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   BOX2_SEQ_MakeScreen 0x021EABA0 thumb ov170
 */
#include "../include/Obj06549.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { unsigned char pad[18]; unsigned char low:7,high:1; } Entry;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct StrObj;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BOX2_SEQ_SetDirtyBit(unsigned char *p, unsigned i);
extern void BOX2_SEQ_PrintTextWinEx(char *,int,void *,u32,int,int,u32,u16);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void BOX2_SEQ_MakeScreen(void **);
#define W(p) (*(char **)((p)+44))
void BOX2_SEQ_DrawTileEntry(char *p,const Entry *e,u32 i)
{
    u16 n;
    u32 text;
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(W(p)+i*8+148)),0);
    if (e->high == 0) {
        if (*(u32 *)(W(p)+380) == 1)
            n = ((struct Obj06549 *)e)->f4;
        else
            n = *(u16 *)(*(char **)(W(p)+384)+((struct Obj06549 *)e)->f4*2);
        if (n != 999) {
            BOX2_SEQ_PrintTextWinEx(W(p),i,*(void **)(W(p)+128),108,0,0,*(u32 *)(W(p)+120),1088);
            text=func_0201D304(*(void **)(W(p)+136),*(u32 *)(W(p)+120),0);
            WORDSET_SetSlotNumber(*(void **)(W(p)+132),0,n,3,2,1);
            BOX2_SEQ_PrintTextWinEx(W(p),i,*(void **)(W(p)+128),104,text,0,*(u32 *)(W(p)+120),1088);
        } else { BOX2_SEQ_SetDirtyBit((unsigned char *)W(p),i); return; }
    } else { BOX2_SEQ_SetDirtyBit((unsigned char *)W(p),i); return; }
    BOX2_SEQ_MakeScreen((void **)(W(p)+148+i*8));
}
