/*
 * function: func_021BA108
 * address: 0x021BA108
 * packet: pkt_ov214_021BA108
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 0201CCE4's r0 remains live and is stored at +5c after the call;
 * its caller declaration returns that word despite the own source's void.
 * extent-tail: 021BA16A alignment padding (two zero bytes).
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 */
#include "../include/Obj01782.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern signed char MSG_SPEED_GetWait(void);
extern void*PRINTSYS_PrintStream(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
void func_021BA108(int unused,char*p,unsigned entry,int v)
{
    int x;
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct Obj01782 *)p)->f6C),15);
    if(*(void* *)&((struct Obj01782 *)p)->f5C)PRINTSYS_PrintStreamDelete(*(void* *)&((struct Obj01782 *)p)->f5C);
    if(*(void* *)&((struct Obj01782 *)p)->f78)STRBUF_Delete(*(void* *)&((struct Obj01782 *)p)->f78);
    *(void* *)&((struct Obj01782 *)p)->f78=func_02045EC0(*(void* *)&((struct Obj01782 *)p)->f58,entry);
    x=MSG_SPEED_GetWait();
    *(void* *)&((struct Obj01782 *)p)->f5C=PRINTSYS_PrintStream(*(unsigned *)&((struct Obj01782 *)p)->f6C,0,0,*(unsigned *)&((struct Obj01782 *)p)->f78,((struct Obj01782 *)p)->f8,x,((struct Obj01782 *)p)->f68,2,((struct Obj01782 *)p)->f0,15);
    ((struct Obj01782 *)p)->f60=v;
}
