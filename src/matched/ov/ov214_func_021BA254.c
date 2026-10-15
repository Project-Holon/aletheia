/*
 * function: BTL_REC_SEL_PrintQueEntry
 * address: 0x021BA254
 * packet: pkt_ov214_021BA254
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent-tail: 021BA2B6 alignment padding (two zero bytes).
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   BTL_REC_SEL_IsEntryShown 0x021BA2B8 thumb ov214
 */
#include "../include/Obj01082.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct Rec3;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u32 BTL_REC_SEL_IsEntryShown(int unused, u8 *p);
void BTL_REC_SEL_PrintQueEntry(void*obj,char*p,unsigned entry)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj01082 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01082 *)p)->f5C)PRINTSYS_PrintStreamDelete(*(void* *)&((struct Obj01082 *)p)->f5C);
    *(int *)&((struct Obj01082 *)p)->f5C=0;
    if(*(void* *)&((struct Obj01082 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj01082 *)p)->f78);
    *(void* *)&((struct Obj01082 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01082 *)p)->f58,entry);
    *(int *)&((struct Obj01082 *)p)->f7C=0;
    PRINTSYS_PrintQue(*(void* *)&((struct Obj01082 *)p)->fC,(unsigned)BMP_WIN_GetBmp(*(void* *)&((struct Obj01082 *)p)->f6C),0,0,*(void* *)&((struct Obj01082 *)p)->f78,((struct Obj01082 *)p)->f8);
    BTL_REC_SEL_IsEntryShown((int)obj,(u8 *)p);
}
