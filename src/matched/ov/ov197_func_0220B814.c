/*
 * function: func_0220B814
 * address: 0x0220B814
 * packet: pkt_ov197_0220B814
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: named row index in Row[36][2] restores base-add-before-column-shift; raw byte row differs in seven bytes.
 * symbols:
 *   STRBUF_Create 0x020457B0 arm
 *   func_02020FB4 0x02020FB4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj04597.h"
#include "../include/Obj25005.h"
#include "../include/Obj25007.h"
#include "../include/Obj25008.h"
typedef unsigned int   u32;
struct U16Vec;
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_02020FB4(void *,unsigned,unsigned);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned short);
extern void STRBUF_Delete(struct U16Vec *vec);
typedef struct { unsigned short entry[36][2]; } Row;
void func_0220B814(char *p,int n)
{
    void *owner;
    int index;
    Row *row;
    void *buf=STRBUF_Create(130,((struct Obj25005 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    index=((struct Obj04597 *)p)->f533;
    row=(Row *)(p+0x150);
    func_02020FB4(buf,row[index].entry[n][0],((struct Obj25007 *)(*(char * *)&((struct Obj04597 *)p)->f0))->fC);
    owner=((struct Obj04597 *)p)->f18;
    PRINTSYS_PrintQueColor(owner,(unsigned)BMP_WIN_GetBmp(((struct Obj04597 *)p)->f130),4,0,(unsigned)buf,((struct Obj25008 *)(*(char * *)&((struct Obj04597 *)p)->f0))->f4,0x3c40);
    ((struct Obj04597 *)p)->f134=1;
    STRBUF_Delete(buf);
}
