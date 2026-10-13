/*
 * function: func_0217D028
 * address: 0x0217D028
 * packet: pkt_ov176_0217D028
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0217D15E before existing 0217D160.
 * ABI: 0200AE14 is an empty void callee leaving its supplied pointer in r0; caller reads it.
 * symbols:
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200BAC8 0x0200BAC8 thumb
 *   func_0200AE14 0x0200AE14 thumb
 *   func_0200B358 0x0200B358 thumb
 *   func_0200B204 0x0200B204 thumb
 *   func_02012944 0x02012944 thumb
 *   func_021E5548 0x021E5548 thumb ov177
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0200E918 0x0200E918 thumb
 *   func_0200AE54 0x0200AE54 thumb
 *   func_02008554 0x02008554 thumb
 *   func_0200B074 0x0200B074 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_0200B078 0x0200B078 thumb
 *   func_021E6118 0x021E6118 thumb ov177
 */
#include "../include/Obj00053.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 image[0x94]; u32 f94, f98; int f9c; u16 fa0, fa2, fa4, fa6, fa8, faa; } Record;
typedef signed int     s32;
struct Big;
struct Reg2;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *func_0200BAC8(void *);
extern int func_0200AE14(void *);
extern void *func_0200B358(void *);
struct Rec1E;
struct RecBig;
struct Reg;
struct Sub0200852CObj;
extern struct Rec1E *func_0200B204(struct RecBig *p, u32 index);
extern u8 *func_02012944(void *p);
extern int func_021E5548(int *);
extern void MI_CpuFill8(void *, int, u32);
extern u8 func_0200E918(const u8 *, u32);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u8 *func_0200B074(struct Reg2 *p);
extern void MI_CpuCopy8(int, void *, u32);
extern s32 func_0200B078(struct Reg2 *p, u32 id);
extern char *func_021E6118(char *info, void *a, void *owner, void *table, int b, void *c, void *d, void *e, void *record, int mode, u16 heap);
void func_0217D028(u8 *p)
{
    Record rec;
    void *base;
    int box, aux, x, table, a, b, c, d;
    if (*(int *)&((struct Obj00053 *)p)->f10) return;
    base = GAME_DATA_GetSaveControl(((struct Obj00053 *)p)->f1B8);
    func_0200BAC8(base);
    box = func_0200AE14(((struct Obj00053 *)p)->f38);
    aux = (int)func_0200B204(func_0200B358(base), 1);
    x = (int)func_02012944(((struct Obj00053 *)p)->f1B8);
    table = func_021E5548(*(int * *)&((struct Obj00053 *)p)->f1B4);
    MI_CpuFill8(&rec, 0, 0xAC);
    rec.fa0 = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 1);
    rec.fa2 = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 2);
    rec.fa4 = func_0200E918(*(u8 * *)&((struct Obj00053 *)p)->f34, 0);
    rec.fa6 = func_0200AE54((struct Reg *)box, 0x16);
    rec.f9c = func_02008554((const struct Sub0200852CObj *)x);
    MI_CpuCopy8((int)func_0200B074(((struct Obj00053 *)p)->f38), &rec, 0x92);
    a = func_0200B078(((struct Obj00053 *)p)->f38, 6);
    b = func_0200B078(((struct Obj00053 *)p)->f38, 5);
    c = func_0200B078(((struct Obj00053 *)p)->f38, 4);
    rec.f94 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    a = func_0200B078(((struct Obj00053 *)p)->f38, 9);
    b = func_0200B078(((struct Obj00053 *)p)->f38, 8);
    c = func_0200B078(((struct Obj00053 *)p)->f38, 7);
    rec.f98 = ((u32)c << 24) | (((u32)b << 24) >> 8) | (((u32)a << 24) >> 16);
    rec.fa8 = func_0200B078(((struct Obj00053 *)p)->f38, 11);
    *(int *)&((struct Obj00053 *)p)->f10 = (int)func_021E6118((char *)(&rec), (void *)x, (void *)table, (void *)(((struct Obj00053 *)p)->f1B0), ((struct Obj00053 *)p)->f1A8, (void *)(*(int *)&((struct Obj00053 *)p)->f1AC), (void *)(*(int *)&((struct Obj00053 *)p)->f24), (void *)(((struct Obj00053 *)p)->f2C), (void *)aux, 0, ((struct Obj00053 *)p)->f1C8);
}
