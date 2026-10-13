/*
 * file:     unit_0220B120.c
 * unit:     yes
 * function: func_0220B120, func_0220B150, func_0220B188, func_0220B1A0, func_0220B1B0, func_0220B1D4, func_0220B248
 * address:  0x0220B120
 * region:   ov197
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   d_0220DA68 0x0220DA68 data a4
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0220B774 0x0220B774 thumb
 *   func_0220B880 0x0220B880 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   d_0220DA0D 0x0220DA0D data a1
 */
#include "../../matched/include/Obj14542.h"
#include "../../matched/include/Obj24989.h"
#include "../../matched/include/Obj08353.h"
#include "../../matched/include/Obj24990.h"
#include "../../matched/include/Obj24991.h"
#include "../../matched/include/Obj03905.h"
#include "../../matched/include/Obj24992.h"

struct Descriptor;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct CharBuf;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_0220B120;

typedef unsigned int u32_0220B120;

typedef short s16_0220B150;

typedef unsigned int u32_0220B150;

typedef unsigned int   u32_0220B188;

typedef unsigned int   u32_0220B1A0;

typedef short s16_0220B1D4;

typedef unsigned int   u32_0220B1D4;

typedef signed short s16_0220B248;

typedef unsigned long u32_0220B248;

extern u32_0220B120 BMP_WIN_Create(u32_0220B120,u32_0220B120,u32_0220B120,u32_0220B120,u8,u8,u8);
extern u32_0220B188 BMP_WIN_Delete(struct Descriptor *d);
extern void func_0220B774(char *);
extern void func_0220B880(char *);
extern void *func_02045EC0(struct MsgBank *bank, u32_0220B1D4 index);
extern u32_0220B1D4 func_0201D304(struct StrObj *s, u32_0220B1D4 a, u32_0220B1D4 b);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32_0220B1D4 a, u32_0220B1D4 b, u32_0220B1D4 c, u32_0220B1D4 d, u32_0220B1D4 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201EFA4(struct WordSet *p, u32_0220B248 i, u32_0220B248 a, u32_0220B248 b, u32_0220B248 c, u32_0220B248 d);
extern void func_0201EF40(struct WordSet *p, u32_0220B248 i, u32_0220B248 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void func_0220B120(char *p);
void func_0220B150(char *p,u8 unused);
void func_0220B188(char *a);
void func_0220B1A0(char *a);
void func_0220B1B0(char *a, int which);
void func_0220B1D4(char *p,int i,int id,int y,u16 colour);
void func_0220B248(char *p);
extern const u8 d_0220DA68[];
extern const char d_0220DA0D[];

void func_0220B120(char *p) { ((struct Obj14542 *)p)->f24=BMP_WIN_Create(4,1,19,30,4,12,1); func_0220B150(p,((struct Obj14542 *)p)->f532); }

/*
 * Declaring the table pointer before the counter restores r4/r5 allocation.
 */
void func_0220B150(char *p,u8 unused) { const u8 *q; u32_0220B150 i; q=d_0220DA68; for(i=0;i<35;i++,q+=6) *(u32_0220B150 *)(p+i*8+0x28)=BMP_WIN_Create(q[0],q[1],q[2],q[3],q[4],q[5],1); }


void func_0220B188(char *a)
{
    unsigned int i;

    for (i = 0; i < 0x23; i++)
        BMP_WIN_Delete((struct Descriptor *)(*(int *)(a + i * 8 + 0x28)));
}


void func_0220B1A0(char *a)
{
    func_0220B188(a);
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj24989 *)a)->f24));
}


void func_0220B1B0(char *a, int which)
{
    switch (which)
    {
    case 0:
        func_0220B248(a);
        break;
    case 1:
        func_0220B774(a);
        break;
    case 2:
        func_0220B880(a);
        break;
    }
}

void func_0220B1D4(char *p,int i,int id,int y,u16 colour)
{
    int handle=*(int *)(p+0x28+i*8);
    int text=(int)func_02045EC0((struct MsgBank *)(((struct Obj08353 *)p)->fC),id);
    int width=func_0201D304((struct StrObj *)text,((struct Obj24990 *)(*(char * *)&((struct Obj08353 *)p)->f0))->f4,0);
    int x=(BMP_WIN_GetWidth((struct Descriptor *)handle)*8-width)>>1;
    int font=((struct Obj08353 *)p)->f18;
    int surface=(int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)(p+0x28+i*8));
    PRINTSYS_PrintQueColor((void *)font,(int)surface,(s16_0220B1D4)x,(s16_0220B1D4)y,(int)text,(int)(((struct Obj24991 *)(*(char * *)&((struct Obj08353 *)p)->f0))->f4),colour);
    (p+i*8)[0x2c]=1;
    STRBUF_Delete((struct U16Vec *)text);
}

/*
 * matching: unsigned loop bound i<=4 preserves the original cmp4/bls; i<5 differs in two bytes.
 */
void func_0220B248(char *p)
{
    unsigned i;
    void *text;
    void *font;
    void *surface;
    for(i=0;i<=4;i++)BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+i*8+0x28)),0);
    func_0220B1D4(p,0,0,0,0x3C40);
    func_0220B1D4(p,0,1,16,0x3C40);
    func_0220B1D4(p,1,2,0,0x3C40);
    func_0220B1D4(p,1,3,16,0x3C40);
    func_0220B1D4(p,2,7,0,0x3C40);
    func_0220B1D4(p,3,6,0,0x3C40);
    if(((struct Obj03905 *)p)->f540!=0){
        text=func_02045EC0(((struct Obj03905 *)p)->fC,8);
        font=((struct Obj03905 *)p)->f18;
        surface=BMP_WIN_GetBmp(((struct Obj03905 *)p)->f48);
        PRINTSYS_PrintQueColor(font,(u32_0220B248)surface,0,0,(u32_0220B248)text,((struct Obj24992 *)(*(char * *)&((struct Obj03905 *)p)->f0))->f4,0x3C40);
        p[0x4C]=1;
        STRBUF_Delete(text);
    }else{
        BMP_WIN_TransferChars(((struct Obj03905 *)p)->f48);
    }
    *(const char * *)&((struct Obj03905 *)p)->f59C=d_0220DA0D;
}
