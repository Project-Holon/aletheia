/*
 * file:     manual_category.c
 * unit:     yes
 * function: func_021BB6E0, func_021BB7F4, func_021BB850, func_021BB854, func_021BBA14, func_021BBA70, func_021BBA74, func_021BBAE8, func_021BBB0C, func_021BBBF0, func_021BBBF4, func_021BBC44, func_021BBC50, func_021BBC54, func_021BBCF4, func_021BBD28
 * address:  0x021BB6E0
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021B9C50 0x021B9C50 thumb ov225
 *   func_021B9C34 0x021B9C34 thumb ov225
 *   func_021B9C40 0x021B9C40 thumb ov225
 *   func_021B9BD4 0x021B9BD4 thumb ov225
 *   func_021B9C58 0x021B9C58 thumb ov225
 *   func_021B9C28 0x021B9C28 thumb ov225
 *   func_021BA65C 0x021BA65C thumb ov225
 *   d_021BC048 0x021BC048 data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA740 0x021BA740 thumb ov225
 *   func_020307B0 0x020307B0 arm
 *   func_021BA760 0x021BA760 thumb ov225
 *   func_021B9C20 0x021B9C20 thumb ov225
 *   func_021B9BE0 0x021B9BE0 thumb ov225
 *   func_021B9C98 0x021B9C98 thumb ov225
 *   func_021B9BC8 0x021B9BC8 thumb ov225
 *   d_021BC05C 0x021BC05C data a1
 *   file_021BC06C 0x021BC06C data a1
 *   func_021BA068 0x021BA068 thumb ov225
 *   func_021BA0F0 0x021BA0F0 thumb ov225
 *   func_021BBD74 0x021BBD74 thumb ov225
 *   func_021B9CDC 0x021B9CDC thumb ov225
 *   func_021B9E80 0x021B9E80 thumb ov225
 *   sub_02030EAC 0x02030EAC arm
 *   func_021B9FBC 0x021B9FBC thumb ov225
 *   func_021BA158 0x021BA158 thumb ov225
 *   func_021BA154 0x021BA154 thumb ov225
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   sub_02041B6C 0x02041B6C arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   d_021BBFA8 0x021BBFA8 data a1
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../../matched/include/Obj00637.h"
#include "../../matched/include/Obj14810.h"
#include "../../matched/include/Obj26278.h"
#include "../../matched/include/Obj26279.h"
#include "../../matched/include/Obj26280.h"
#include "../../matched/include/Obj26281.h"
#include "../../matched/include/Obj26282.h"
#include "../../matched/include/Obj26283.h"
#include "../../matched/include/Obj26284.h"
#include "../../matched/include/Obj26286.h"
#include "../../matched/include/Obj26288.h"
#include "../../matched/include/Obj01789.h"
#include "../../matched/include/Obj26290.h"
#include "../../matched/include/Obj26291.h"
#include "../../matched/include/Obj26292.h"
#include "../../matched/include/Obj26293.h"
#include "../../matched/include/Obj26294.h"
#include "../../matched/include/Obj26295.h"
#include "../../matched/include/Obj01790.h"
#include "../../matched/include/Obj26296.h"
#include "../../matched/include/Obj26297.h"
#include "../../matched/include/Obj26298.h"
#include "../../matched/include/Obj26299.h"
#include "../../matched/include/Obj26300.h"
#include "../../matched/include/Obj26301.h"
#include "../../matched/include/Obj26302.h"
#include "../../matched/include/Obj02563.h"
#include "../../matched/include/Obj26303.h"
#include "../../matched/include/Obj26304.h"
#include "../../matched/include/Obj26305.h"
#include "../../matched/include/Obj26306.h"
#include "../../matched/include/Obj10985.h"
#include "../../matched/include/Obj26308.h"
#include "../../matched/include/Obj00602.h"
#include "../../matched/include/Obj26309.h"
#include "../../matched/include/Obj26310.h"
#include "../../matched/include/Obj26312.h"
#include "../../matched/include/Obj26313.h"
#include "../../matched/include/Obj26314.h"
#include "../../matched/include/Obj05575.h"
#include "../../matched/include/Obj26316.h"
#include "../../matched/include/Obj26317.h"
#include "../../matched/include/Obj26318.h"
#include "../../matched/include/Obj26319.h"
#include "../../matched/include/Obj26320.h"
#include "../../matched/include/Obj26321.h"
#include "../../matched/include/Obj03382.h"
#include "../../matched/include/Obj08471.h"
#include "../../matched/include/Obj08472.h"
#include "../../matched/include/Obj26322.h"
#include "../../matched/include/Obj26323.h"
#include "../../matched/include/Obj06736.h"

struct Data;
struct Node;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct PrintSys;
struct Cfg;
typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Owner { u32 f0; u16 f4; u16 f6; u16 f8; } Owner;

typedef struct Data { void *f0; u16 f4; char pad6[0x26]; char *f2C; } Data;

typedef struct Q { Owner *f0; Data *f4; u32 f8; u16 fC; char padE[2]; char *f10; u16 f14; u16 f16; char pad18[4]; char *f1C; void *f20; } Q;

typedef enum { FLAG_FALSE, FLAG_TRUE } Flag;

typedef unsigned char u8;

typedef short s16;

typedef struct { u8 v[9]; } Record;

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern u16 func_021B9C50(const char *p);
extern u16 func_021B9C34(char *,int);
extern u16 func_021B9C40(char *,int,int);
extern u16 func_021B9BD4(char *,int);
extern int func_021B9C58(void *,int,void *);
extern u16 func_021B9C28(char *,int);
extern void *func_021BA65C(char *owner, struct Data *data);
extern void func_02030EAC(struct Node *);
extern void func_021BA740(char *);
extern u32 func_020307B0(void *p);
extern int func_021BA760(char *p);
extern u16 func_021B9C20(const char *p);
extern u16 func_021B9BE0(char *, int);
extern int func_021B9C98(void *, int, int);
extern u16 func_021B9BC8(char *, int);
extern void func_021BA068(char *, unsigned);
extern void func_021BA0F0(char *, unsigned, unsigned);
extern void func_021BBD74(char *);
extern int func_021B9CDC(void *);
extern void func_021B9E80(char *,u32);
extern void sub_02030EAC(struct Node *);
extern void func_021B9FBC(char *);
extern unsigned func_021BA158(char *p);
extern unsigned func_021BA154(char *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void sub_02041B6C(u32);
extern u32 BMP_WIN_Create(u32 layer,u32 a,u32 b,u32 tiles,u8 c,u8 d,u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *p,u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *p);
extern void *func_02045EC0(struct MsgBank *p,u32 index);
extern void PRINTSYS_PrintQueColor(void *p,u32 a,u32 b,u32 c,u32 d,u32 e,u16 f);
extern void STRBUF_Delete(struct U16Vec *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void BMP_WIN_ClearScreen(struct Descriptor *);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p,void *value);
extern void BMP_WIN_MakeScreen(struct Cfg *p);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 channel);
char *func_021BB6E0(char *p,char *data);
void func_021BB7F4(char *p);
int func_021BB844(char *p);
void func_021BB850(void);
Q *func_021BB854(Owner *p, Data *data);
void func_021BBA14(char *p);
int func_021BBA64(char *p);
void func_021BBA70(void);
char *func_021BBA74(char *p, char *data);
void func_021BBAE8(char *p);
int func_021BBB0C(char *p);
void func_021BBBF0(void *p);
void func_021BBBF4(char *p);
void func_021BBC44(char *a0);
void func_021BBC50(char *a0);
void func_021BBC54(u8 *p);
void func_021BBCF4(char *p);
void func_021BBD28(u8 *p);
extern const char d_021BC048[];
extern const char d_021BC05C[];
extern const char file_021BC06C[];
extern const Record d_021BBFA8[];

char *func_021BB6E0(char *p,char *data)
{
    char *q;
    u16 groups,items;
    u16 i,j,valid;
    q=func_02030734(((struct Obj14810 *)data)->f4,0x24,1,d_021BC048,0x5c);
    *(char * *)&((struct Obj00637 *)q)->f0=p;
    ((struct Obj26278 *)p)->f4=0;
    ((struct Obj26279 *)(*(char * *)&((struct Obj00637 *)q)->f0))->f8=0;
    *(char * *)&((struct Obj00637 *)q)->f4=data;
    ((struct Obj00637 *)q)->f8=0;
    groups=func_021B9C50(*(char * *)&((struct Obj14810 *)data)->f2C);
    ((struct Obj00637 *)q)->fC=0;
    *(char * *)&((struct Obj00637 *)q)->f10=func_02030734(((struct Obj26280 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f4,groups*8,1,d_021BC048,0x71);
    for(i=0;i<groups;i++) {
        valid=0;
        items=func_021B9C34(*(char * *)&((struct Obj26281 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,i);
        for(j=0;j<items;j++) {
            int id;
            id=func_021B9C40(*(char * *)&((struct Obj26282 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,i,j);
            id=func_021B9BD4(*(char * *)&((struct Obj26283 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,id);
            if(func_021B9C58(((struct Obj26284 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,id,*(void **)*(char * *)&((struct Obj00637 *)q)->f4)) valid++;
        }
        if(valid) {
            *(u16 *)(*(char * *)&((struct Obj00637 *)q)->f10+((struct Obj00637 *)q)->fC*8)=i;
            *(u16 *)(*(char * *)&((struct Obj00637 *)q)->f10+((struct Obj00637 *)q)->fC*8+2)=func_021B9C28(*(char * *)&((struct Obj26286 *)(*(char * *)&((struct Obj00637 *)q)->f4))->f2C,i);
            *(u32 *)(*(char * *)&((struct Obj00637 *)q)->f10+((struct Obj00637 *)q)->fC*8+4)=0;
            ((struct Obj00637 *)q)->fC+=1;
        }
    }
    ((struct Obj00637 *)q)->f14=*(u16 *)*(char * *)&((struct Obj00637 *)q)->f0;
    ((struct Obj00637 *)q)->f16=((struct Obj26288 *)(*(char * *)&((struct Obj00637 *)q)->f0))->f2;
    *(char * *)&((struct Obj00637 *)q)->f1C=func_021BA65C(q+8,(struct Data *)data);
    ((struct Obj00637 *)q)->f20=func_020056A0((unsigned)func_021BB850,(unsigned)q,1);
    return q;
}

/*
 * extent: 94-byte unit; two zero alignment bytes at 021BB852 are outside the unit.
 * followers: parent cleared 021BB844 tail stub and 021BB850 empty Thumb leaf.
 */
void func_021BB7F4(char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj01789 *)p)->f20);
    *(u16 *)*(char * *)&((struct Obj01789 *)p)->f0 = ((struct Obj01789 *)p)->f14;
    ((struct Obj26290 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f2 = ((struct Obj01789 *)p)->f16;
    if (((struct Obj01789 *)p)->f18 == 0) ((struct Obj26291 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f4 = 0;
    else if (((struct Obj01789 *)p)->f18 == 1) {
        ((struct Obj26292 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f4 = 1;
        ((struct Obj26294 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f8 = *(u16 *)(*(char * *)&((struct Obj01789 *)p)->f10 + ((struct Obj26293 *)(*(char * *)&((struct Obj01789 *)p)->f0))->f2 * 8);
    }
    func_021BA740(*(char * *)&((struct Obj01789 *)p)->f1C);
    func_020307B0(((struct Obj01789 *)p)->f10);
    func_020307B0(p);
}

int func_021BB844(char *p)
{
    return func_021BA760(*(char * *)&((struct Obj26295 *)p)->f1C);
}

void func_021BB850(void)
{
}

Q *func_021BB854(Owner *p, Data *data)
{
    Q *q;
    u32 t, t0;
    int g;
    u16 ca, cb;
    int ra, rb;
    q = func_02030734(data->f4, 0x24, 1, d_021BC05C, 0x61);
    q->f0 = p;
    *(u32 *)((char *)p + 0xC) = 0;
    *(u16 *)((char *)q->f0 + 0x10) = 0;
    q->f4 = data;
    t0 = q->f0->f0;
    if (t0 == 0) {
        q->f8 = 1;
        g = q->f0->f4;
        ca = func_021B9C34(q->f4->f2C, g);
        q->fC = 0;
        q->f10 = func_02030734(q->f4->f4, ca * 8, 1, d_021BC05C, 0x79);
        {
            u16 i;
        for (i = 0; i < ca; i++) {
            u16 id;
            int id2;
            id = func_021B9C40(q->f4->f2C, g, i);
            id2 = func_021B9BD4(q->f4->f2C, id);
            if (func_021B9C58(q->f4->f2C, id2, q->f4->f0)) {
                t = func_021B9BE0(q->f4->f2C, id);
                ra = func_021B9C98(q->f4->f2C, t, (int)q->f4->f0);
                *(u16 *)(q->f10 + q->fC * 8) = id;
                *(u16 *)(q->f10 + q->fC * 8 + 2) = func_021B9BC8(q->f4->f2C, id);
                *(u32 *)(q->f10 + q->fC * 8 + 4) = (ra != 0) ? FLAG_FALSE : FLAG_TRUE;
                q->fC += 1;
            }
        }
        }
        q->f14 = *(u16 *)((char *)q->f0 + 6);
        q->f16 = *(u16 *)((char *)q->f0 + 8);
    } else {
        q->f8 = 1;
        cb = func_021B9C20(q->f4->f2C);
        q->fC = 0;
        q->f10 = func_02030734(q->f4->f4, cb * 8, 1, d_021BC05C, 0xB2);
        {
            u16 i;
        for (i = 0; i < cb; i++) {
            int id;
            id = func_021B9BD4(q->f4->f2C, i);
            if (func_021B9C58(q->f4->f2C, id, q->f4->f0)) {
                t = func_021B9BE0(q->f4->f2C, i);
                rb = func_021B9C98(q->f4->f2C, t, (int)q->f4->f0);
                *(u16 *)(q->f10 + q->fC * 8) = i;
                *(u16 *)(q->f10 + q->fC * 8 + 2) = func_021B9BC8(q->f4->f2C, i);
                {
                    u32 fl = 0;
                    if (rb == 0)
                        fl = 1;
                    *(u32 *)(q->f10 + q->fC * 8 + 4) = fl;
                }
                q->fC += 1;
            }
        }
        }
        q->f14 = *(u16 *)((char *)q->f0 + 6);
        q->f16 = *(u16 *)((char *)q->f0 + 8);
    }
    q->f1C = func_021BA65C((char *)q + 8, (struct Data *)data);
    q->f20 = func_020056A0((unsigned)func_021BBA70, (unsigned)q, 1);
    return q;
}

/*
 * extent: 94-byte unit; two zero alignment bytes at 021BBA72 are outside the unit.
 * followers: parent cleared 021BBA64 tail stub and 021BBA70 empty Thumb leaf.
 */
void func_021BBA14(char *p)
{
    func_02030EAC(*(struct Node * *)&((struct Obj01790 *)p)->f20);
    ((struct Obj26296 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f6 = ((struct Obj01790 *)p)->f14;
    ((struct Obj26297 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f8 = ((struct Obj01790 *)p)->f16;
    if (((struct Obj01790 *)p)->f18 == 0) ((struct Obj26298 *)(*(char * *)&((struct Obj01790 *)p)->f0))->fC = 0;
    else if (((struct Obj01790 *)p)->f18 == 1) {
        ((struct Obj26299 *)(*(char * *)&((struct Obj01790 *)p)->f0))->fC = 1;
        ((struct Obj26301 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f10 = *(u16 *)(*(char * *)&((struct Obj01790 *)p)->f10 + ((struct Obj26300 *)(*(char * *)&((struct Obj01790 *)p)->f0))->f8 * 8);
    }
    func_021BA740(*(char * *)&((struct Obj01790 *)p)->f1C);
    func_020307B0(((struct Obj01790 *)p)->f10);
    func_020307B0(p);
}

int func_021BBA64(char *p)
{
    return func_021BA760(*(char * *)&((struct Obj26302 *)p)->f1C);
}

void func_021BBA70(void)
{
}

/*
 * arity: BBC44 retains original visible r0 context although its fixed tail ignores it.
 */
char *func_021BBA74(char *p, char *data)
{
    char *q;
    q = func_02030734(((struct Obj26303 *)data)->f4, 64, 1, file_021BC06C, 156);
    *(char * *)&((struct Obj02563 *)q)->f0 = p;
    ((struct Obj26304 *)p)->f28 = 0;
    *(char * *)&((struct Obj02563 *)q)->f4 = data;
    q[8] = 0;
    ((struct Obj02563 *)q)->fC = 0;
    func_021BBBF4(q);
    func_021BBC44(q);
    func_021BBC54((u8 *)q);
    ((struct Obj02563 *)q)->f34 = func_020056A0((unsigned)func_021BBBF0, (unsigned)q, 1);
    ((struct Obj02563 *)q)->f38 = 0;
    q[0x3c] = -1;
    func_021BA068(*(char * *)&((struct Obj26305 *)(*(char * *)&((struct Obj02563 *)q)->f4))->f34, 3);
    func_021BA0F0(*(char * *)&((struct Obj26306 *)(*(char * *)&((struct Obj02563 *)q)->f4))->f34, *(u8 *)*(char * *)&((struct Obj02563 *)q)->f0, ((struct Obj02563 *)q)->f8);
    func_021BBD74(q);
    return q;
}

void func_021BBAE8(char *p) { func_021B9E80(*(char * *)&((struct Obj10985 *)p)->f4,func_021B9CDC(((struct Obj26308 *)(*(char * *)&((struct Obj10985 *)p)->f4))->f2C)); sub_02030EAC(*(struct Node * *)&((struct Obj10985 *)p)->f34); func_020307B0(p); }

int func_021BBB0C(char *p)
{
    int result = 0;
    int timer = ((struct Obj00602 *)p)->f3C;
    int choice;
    if (timer == 0) result = 1;
    else if (timer > 0) {
        if (timer == 1) {
            func_021BBCF4(p);
            func_021BBC50(p);
        }
        ((struct Obj00602 *)p)->f3C -= 1;
    }
    if (((struct Obj00602 *)p)->f38 != 1) func_021BBD28((u8 *)p);
    if (((struct Obj00602 *)p)->f38 == 0 || ((struct Obj00602 *)p)->f38 == 2) {
        func_021B9FBC(*(char * *)&((struct Obj26309 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
        if (((struct Obj00602 *)p)->f38 == 0) {
            choice = func_021BA158(*(char * *)&((struct Obj26310 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
            if (choice == -1) goto done;
            ((struct Obj00602 *)p)->f38 = 2;
            if (choice == 4) {
                if (((struct Obj00602 *)p)->f8 != 0) {
                    ((struct Obj00602 *)p)->f8 -= 1;
                    ((struct Obj00602 *)p)->fC = 1;
                }
            } else if (choice == 5) {
                if (((struct Obj00602 *)p)->f8 < *(u8 *)*(char * *)&((struct Obj00602 *)p)->f0 - 1) {
                    ((struct Obj00602 *)p)->f8 += 1;
                    ((struct Obj00602 *)p)->fC = 1;
                }
            }
            if (((struct Obj00602 *)p)->fC) func_021BBD74(p);
        } else {
            choice = func_021BA154(*(char * *)&((struct Obj26312 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34);
            if (choice == -1) goto done;
            switch (choice) {
            case 1:
                ((struct Obj26313 *)(*(char * *)&((struct Obj00602 *)p)->f0))->f28 = 0;
                ((struct Obj00602 *)p)->f38 = 1;
                ((struct Obj00602 *)p)->f3C = 1;
                break;
            case 4: case 5:
                ((struct Obj00602 *)p)->f38 = 0;
                if (((struct Obj00602 *)p)->fC) {
                    func_021BA0F0(*(char * *)&((struct Obj26314 *)(*(char * *)&((struct Obj00602 *)p)->f4))->f34, *(u8 *)*(char * *)&((struct Obj00602 *)p)->f0, ((struct Obj00602 *)p)->f8);
                    ((struct Obj00602 *)p)->fC = 0;
                }
                break;
            }
        }
    }
done:
    return result;
}

/*
 * leaf: sole unresolved BA74 callback; parent clearance. Thumb bx lr, then two zero alignment bytes.
 */
void func_021BBBF0(void *p)
{
}

void func_021BBBF4(char *p)
{
    func_02049B68((void *)(((struct Obj26316 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f24), 0, 4, 0, 64, ((struct Obj26317 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f4);
    func_02049658((void *)(((struct Obj26318 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f24), 2, 4, 0, 0, 0, ((struct Obj26319 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f4);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt((void *)(((struct Obj26320 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f24), 6, 4, 0, 0, 0, 0, ((struct Obj26321 *)(*(char * *)&((struct Obj05575 *)p)->f4))->f4);
}

void func_021BBC44(char *a0) { sub_02041B6C(4); }

void func_021BBC50(char *a0) {}

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
        BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj08471 *)slot)->f10),0);
        BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj08471 *)slot)->f10);
        ((struct Obj08471 *)slot)->f28=0;
    }
    owner=*(u8 * *)&((struct Obj03382 *)p)->f4;
    ((struct Obj03382 *)p)->f1C=((struct Obj08472 *)owner)->f10;
    *(u32 *)&((struct Obj03382 *)p)->f20=((struct Obj08472 *)owner)->f10;
    ((struct Obj03382 *)p)->f24=((struct Obj08472 *)owner)->f14;
    string=(struct U16Vec *)func_02045EC0(*(struct MsgBank * *)&((struct Obj08472 *)owner)->f20,((struct Obj26322 *)(*(u8 * *)&((struct Obj03382 *)p)->f0))->f2);
    PRINTSYS_PrintQueColor(((struct Obj03382 *)p)->f20,(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj03382 *)p)->f14),0,1,(u32)string,((struct Obj26323 *)(*(u8 * *)&((struct Obj03382 *)p)->f4))->fC,0x3C40);
    STRBUF_Delete(string);
    ((struct Obj03382 *)p)->f2C=1;
    func_021BBD28(p);
}

void func_021BBCF4(char *p) { u8 i; for(i=0;i<3;i++) { *(u32 *)(p+i*4+0x28)=0; PRINTSYS_QUE_Clear(*(struct PrintSys **)(p+i*4+0x1c)); BMP_WIN_ClearScreen(*(struct Descriptor **)(p+i*4+0x10)); BMP_WIN_Delete(*(struct Descriptor **)(p+i*4+0x10)); } sub_02041B6C(5); }

void func_021BBD28(u8 *p)
{
    u8 index;
    u8 *slot;
    struct Descriptor *descriptor;
    for(index=0;index<3;index++) {
        slot=p+index*4;
        if(((struct Obj06736 *)slot)->f28!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj06736 *)slot)->f1C,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj06736 *)slot)->f10))==0) {
                descriptor=*(struct Descriptor * *)&((struct Obj06736 *)slot)->f10;
                BMP_WIN_TransferChars(descriptor);
                BMP_WIN_MakeScreen((struct Cfg *)descriptor);
                func_02041B6C(BMP_WIN_GetBgLayer(descriptor));
                ((struct Obj06736 *)slot)->f28=0;
            }
        }
    }
}
