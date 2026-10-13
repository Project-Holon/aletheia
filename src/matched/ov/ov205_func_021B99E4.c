/*
 * function: func_021B99E4
 * address: 0x021B99E4
 * packet: pkt_ov205_021B99E4
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Fourth parameter u16 restores the entry spill and delayed reload;
 *   unsigned moved the spill to +0010 and reloaded it before stack args.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201F73C 0x0201F73C thumb
 */
#include "../include/Obj01777.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *,unsigned,unsigned,void *,void *,unsigned,void *,unsigned,u16,u16);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_0201F73C(void *,int,int,int);
void func_021B99E4(char *p,unsigned entry,unsigned index,u16 kind)
{
    void *buffer;
    buffer=STRBUF_Create(1024,((struct Obj01777 *)p)->f0);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj01777 *)p)->f1C),15);
    MSGDATA_ReadString(((struct Obj01777 *)p)->f14,entry,buffer);
    func_0201F02C(((struct Obj01777 *)p)->f18,0,((struct Obj01777 *)p)->f8);
    func_0201F250(((struct Obj01777 *)p)->f18,((struct Obj01777 *)p)->fC,buffer);
    ((struct Obj01777 *)p)->f20=PRINTSYS_PrintStream(((struct Obj01777 *)p)->f1C,index,kind,((struct Obj01777 *)p)->fC,((struct Obj01777 *)p)->f10,func_02012FFC(),((struct Obj01777 *)p)->f24,0,((struct Obj01777 *)p)->f0,3855);
    STRBUF_Delete(buffer);
    func_0201F73C(((struct Obj01777 *)p)->f1C,2,1,12);
}
