/*
 * function: func_02185254
 * address: 0x02185254
 * packet: pkt_ov219_02185254
 * region: ov219
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: original truncates heap before 020457B0, and stack bytes before 02184D30; extern narrow widths preserve those visible operations.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02184968 0x02184968 thumb ov219
 *   func_02184D30 0x02184D30 thumb ov219
 *   func_02185C84 0x02185C84 thumb ov219
 *   d_02185DCB 0x02185DCB data a1
 */
#include "../include/Obj02934.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern const u8 d_02185DCB[];
struct U16Vec;
extern struct U16Vec *STRBUF_Create(unsigned int capacity, unsigned int heapId);
struct Cfg;
struct Descriptor;
struct Record;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(unsigned);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
typedef unsigned int   u32;
extern u32 func_02184968(const u8 *p, int flag);
extern void func_02184D30(char *p, struct Record *out, struct Descriptor *d, void *text, u8 x, u8 y);
extern int func_02185C84(unsigned,unsigned,void *,void *,unsigned);
void func_02185254(char *p,unsigned key,unsigned member)
{
    void *first,*second,*object;
    first=STRBUF_Create(64,(u16)(((struct Obj02934 *)p)->f0));
    second=STRBUF_Create(64,(u16)(((struct Obj02934 *)p)->f0));
    ((struct Obj02934 *)p)->fC040=(void *)func_02184968(d_02185DCB,1);
    func_02185C84(key,member,first,second,((struct Obj02934 *)p)->f0);
    if(member!=0) func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,second,0,16);
    func_02184D30(p,(struct Record *)(p+0xC044),((struct Obj02934 *)p)->fC040,first,0,0);
    STRBUF_Delete(second);
    STRBUF_Delete(first);
    BMP_MENUWORK_DrawWindow(((struct Obj02934 *)p)->fC040,0,34,7);
    object=((struct Obj02934 *)p)->fC040;
    BMP_WIN_TransferChars(object);
    BMP_WIN_MakeScreen(object);
    func_02041B6C(BMP_WIN_GetBgLayer(object));
}
