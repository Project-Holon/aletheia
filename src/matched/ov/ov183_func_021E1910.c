/*
 * function: BR_CODEIN_ProfileCreateButtons
 * address: 0x021E1910
 * packet: pkt_ov183_021E1910
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Bound: original copies 48 halfwords (12 eight-byte coordinate records); loops initialize 12 then 12 records.
 * symbols:
 *   d_021E3880 0x021E3880 data a2
 *   BR_CODEIN_ProfileHandleInput 0x021E19EC thumb ov183
 *   BUTTON_MAN_Create 0x02051B84 arm
 */
#include "../include/Obj03331.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef struct {short a,b,c,d;} Row;
typedef struct {Row row[12];} Table;
extern const Table d_021E3880;
extern void BR_CODEIN_ProfileHandleInput(u32 idx, int arg, char *p);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
void BR_CODEIN_ProfileCreateButtons(char *p) {
    int i;
    Table table;
    for(i=0;i<12;i++)*(char **)(p+i*28+16)=(p+0x298)+i*4;
    table=d_021E3880;
    for(;i<24;i++){
        *(u8 *)(p+i*4+0x298)=table.row[i-12].b-table.row[i-12].d;
        *(u8 *)(p+i*4+0x29A)=table.row[i-12].a-table.row[i-12].c;
        *(u8 *)(p+i*4+0x299)=table.row[i-12].b+table.row[i-12].d;
        *(u8 *)(p+i*4+0x29B)=table.row[i-12].a+table.row[i-12].c;
    }
    ((struct Obj03331 *)p)->f2F8=255;
    ((struct Obj03331 *)p)->f294=BUTTON_MAN_Create((u8 *)(p+0x298),(int)BR_CODEIN_ProfileHandleInput,(int)p,((struct Obj03331 *)p)->f34C);
}
