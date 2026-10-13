/*
 * function: func_021BBC54
 * address: 0x021BBC54
 * packet: pkt_ov225_021BBC54
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_021BBD28 0x021BBD28 thumb ov225
 *   d_021BBFA8 0x021BBFA8 data a1
 */
#include "../include/Obj03382.h"
#include "../include/Obj08471.h"
#include "../include/Obj08472.h"
#include "../include/Obj26322.h"
#include "../include/Obj26323.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct U16Vec;
typedef struct { u8 v[9]; } Record;
extern const Record d_021BBFA8[];
extern u32 BMP_WIN_Create(u32 layer,u32 a,u32 b,u32 tiles,u8 c,u8 d,u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *p,u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *p,u32 index);
extern void PRINTSYS_PrintQueColor(void *p,u32 a,u32 b,u32 c,u32 d,u32 e,u16 f);
extern void STRBUF_Delete(struct U16Vec *p);
extern void func_021BBD28(u8 *p);
void func_021BBC54(u8 *p)
{
    u8 index;
    u8 *slot;
    const Record *record;
    u8 *owner;
    struct U16Vec *string;
    for(index=0;index<3;index++) {
        record=&d_021BBFA8[index];
        slot=p+index*4;
        *(u32 *)&((struct Obj08471 *)slot)->f10=BMP_WIN_Create(record->v[0],record->v[1],record->v[2],record->v[3],record->v[4],record->v[5],record->v[6]);
        BMP_Clear((struct CharBuf *)func_02045770(*(struct Descriptor * *)&((struct Obj08471 *)slot)->f10),0);
        BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj08471 *)slot)->f10);
        ((struct Obj08471 *)slot)->f28=0;
    }
    owner=*(u8 * *)&((struct Obj03382 *)p)->f4;
    ((struct Obj03382 *)p)->f1C=((struct Obj08472 *)owner)->f10;
    *(u32 *)&((struct Obj03382 *)p)->f20=((struct Obj08472 *)owner)->f10;
    ((struct Obj03382 *)p)->f24=((struct Obj08472 *)owner)->f14;
    string=(struct U16Vec *)func_02045EC0(*(struct MsgBank * *)&((struct Obj08472 *)owner)->f20,((struct Obj26322 *)(*(u8 * *)&((struct Obj03382 *)p)->f0))->f2);
    PRINTSYS_PrintQueColor(((struct Obj03382 *)p)->f20,(u32)func_02045770(*(struct Descriptor * *)&((struct Obj03382 *)p)->f14),0,1,(u32)string,((struct Obj26323 *)(*(u8 * *)&((struct Obj03382 *)p)->f4))->fC,0x3C40);
    STRBUF_Delete(string);
    ((struct Obj03382 *)p)->f2C=1;
    func_021BBD28(p);
}
