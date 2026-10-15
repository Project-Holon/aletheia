/*
 * function: func_0218519C
 * address: 0x0218519C
 * packet: pkt_ov219_0218519C
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 457B0 heap input is explicitly narrowed to u16 in original;
 * retain all observed narrow inputs to matching4D30 stack-byte interface.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_02184968 0x02184968 thumb ov219
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   WORDSET_DeleteMsgdataF094 0x0201F094 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   func_02184D30 0x02184D30 thumb ov219
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_02185DCB 0x02185DCB data ov219 a1
 */
#include "../include/Obj01984.h"
typedef unsigned char u8;typedef unsigned short u16;
struct U16Vec;struct Descriptor;struct WordSet;struct MsgBank;
struct Record {struct Descriptor *descriptor;u8 active;};
extern struct U16Vec *STRBUF_Create(unsigned int capacity, unsigned int heapId);
typedef unsigned int   u32;
extern u32 func_02184968(const u8 *p, int flag);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *,unsigned,unsigned),WORDSET_DeleteMsgdataF094(struct WordSet *,unsigned,unsigned,unsigned);
extern void MSGDATA_ReadString(struct MsgBank *,unsigned,void *),WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern void func_02184D30(char *,struct Record *,struct Descriptor *,void *,u8,u8);
extern void STRBUF_Delete(struct U16Vec *),BMP_MENUWORK_DrawWindow(void *,int,int,int),BMP_WIN_TransferChars(struct Descriptor *);
extern const unsigned char d_02185DCB[];
void func_0218519C(char *p)
{
    struct U16Vec *dst,*src;
    dst=STRBUF_Create(1024,(u16)(((struct Obj01984 *)p)->f0));src=STRBUF_Create(1024,(u16)(((struct Obj01984 *)p)->f0));
    *(struct Descriptor * *)&((struct Obj01984 *)p)->fC040=(struct Descriptor *)func_02184968(d_02185DCB,1);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,0,((struct Obj01984 *)p)->fC33C);
    WORDSET_DeleteMsgdataF094(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,1,((struct Obj01984 *)p)->fC33C,((struct Obj01984 *)p)->fC340);
    MSGDATA_ReadString(*(struct MsgBank * *)&((struct Obj01984 *)p)->fC070,14,src);
    WORDSET_CopyTaggedText(*(struct WordSet * *)&((struct Obj01984 *)p)->fC0A8,dst,src);
    func_02184D30(p,(struct Record *)(p+0xc044),*(struct Descriptor * *)&((struct Obj01984 *)p)->fC040,dst,0,0);
    STRBUF_Delete(src);STRBUF_Delete(dst);
    BMP_MENUWORK_DrawWindow(((struct Obj01984 *)p)->fC040,0,34,7);
    BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj01984 *)p)->fC040);
}
