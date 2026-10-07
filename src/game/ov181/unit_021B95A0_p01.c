/*
 * file:     unit_021B95A0_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95D4, func_021B95E8, func_021B95F8, func_021B9630, func_021B96B0, func_021B96C8, func_021B974C, func_021B97BC, func_021B98F4, func_021B9908, func_021B99CC, func_021B99F8, func_021B9A80, func_021B9AD4, func_021B9AF8, func_021B9B10, func_021B9B1C, func_021B9B6C, func_021B9B98, func_021B9C30, func_021B9C58, func_021B9C80, func_021B9CC8, func_021B9D04, func_021B9D20, func_021B9D34, func_021B9DB0
 * address:  0x021B95A0
 * region:   ov181
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_021BA318 0x021BA318 thumb ov181
 *   func_021B9F40 0x021B9F40 thumb ov181
 *   d_021BAB70 0x021BAB70 data a4
 *   func_02034AC4  0x02034AC4  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0207D534  0x0207D534  arm
 *   func_02005DAC  0x02005DAC  thumb
 *   func_021B9E14  0x021B9E14  thumb  ov181
 *   ov067_id       0x00000043  data
 *   func_020221A4  0x020221A4  thumb
 *   sub_02005E50 0x02005E50 thumb
 *   sub_02005F38 0x02005F38 thumb
 *   sub_02005D28 0x02005D28 thumb
 *   func_021B9F1C 0x021B9F1C thumb ov181
 *   sub_02043534 0x02043534 arm
 *   sub_020435F4 0x020435F4 arm
 *   sub_02034A5C 0x02034A5C arm
 *   overlay_id 0x00000043 data a1
 *   func_021BA83C 0x021BA83C thumb ov181
 *   func_021BA5E8 0x021BA5E8 thumb ov181
 *   func_021BA6F0 0x021BA6F0 thumb ov181
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_021BA2AC 0x021BA2AC thumb ov181
 *   func_021BA390 0x021BA390 thumb ov181
 *   d_021BABD0 0x021BABD0 data a4
 *   func_0204335C  0x0204335C  arm
 *   func_020433E0  0x020433E0  arm
 *   d_021BABFC     0x021BABFC  data  a4
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02051E74 0x02051E74 arm
 *   sub_02040860 0x02040860 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021BAC74 0x021BAC74 data a4
 *   d_021BACC4 0x021BACC4 data a4
 *   d_021BAC84 0x021BAC84 data a4
 *   d_021BACA4 0x021BACA4 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02040EBC  0x02040EBC  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   func_021B9DDC 0x021B9DDC thumb ov181
 *   func_020419E4 0x020419E4 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02043678 0x02043678 arm
 *   func_020437AC 0x020437AC arm
 *   func_021BA4AC 0x021BA4AC thumb ov181
 *   func_02045770 0x02045770 arm
 *   func_020439A0 0x020439A0 arm
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 */
#include "../../matched/include/Obj24498.h"
#include "../../matched/include/Obj14406.h"
#include "../../matched/include/Obj24499.h"
#include "../../matched/include/Obj00682.h"
#include "../../matched/include/Obj01003.h"
#include "../../matched/include/Obj24500.h"
#include "../../matched/include/Obj03327.h"
#include "../../matched/include/Obj24501.h"
#include "../../matched/include/Obj08302.h"
#include "../../matched/include/Obj24502.h"
#include "../../matched/include/Obj14407.h"
#include "../../matched/include/Obj14408.h"
#include "../../matched/include/Obj24503.h"
#include "../../matched/include/Obj24504.h"
#include "../../matched/include/Obj14409.h"

#define STATE(p) (*(int *)((p) + 0x2EC))
#define ENTRIES(p) (*(Entry **)((p) + 0x2D4))
#define IDX(p) (*(unsigned char *)((p) + 0x2BA))
struct Obj0203159C;
struct S020315D4;
struct DispVram;
struct BgTemplate;
struct DispConfig;
struct Mtx22;
struct Node;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct Rec;
struct Bmp;
struct Obj020437AC;
struct Descriptor;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16_021B95A0;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed short s16_021B97BC;

typedef int (*Command)(char *,char *);

typedef struct { unsigned words[4]; } Small;

typedef struct { unsigned words[8]; } Big;

typedef struct { unsigned text; unsigned short tag; unsigned char kind, pad7; unsigned pad8, padC; } Entry;

extern void func_0203064C(u32,u32,u32);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *,int,u32);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_021BA318(unsigned char *),func_021B9C80(char *),func_021B9F40(char *);
extern int func_02034AC4(s32 handle);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02005DAC(void *arg);
extern void func_021B9E14(char *p);
extern u32 func_020221A4(void);
extern int sub_02005E50(void),sub_02005F38(void);
extern void sub_02005D28(void);
extern void sub_02043534(u32),sub_020435F4(u32),sub_02034A5C(int);
extern int func_021BA83C(char *);
extern int func_021BA5E8(char *),func_021BA6F0(char *);
extern int func_02005F38(void);
extern void func_02005E30(u32);
extern int func_021BA2AC(u8 *p, int a);
extern void func_021BA390(char *);
extern void func_0204335C(u32 keep);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(unsigned short);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void sub_02040860(unsigned, unsigned, unsigned, unsigned);
extern void func_020434DC(unsigned, unsigned);
extern void func_02043598(unsigned, unsigned);
extern void func_020434DC(unsigned,unsigned),func_02043598(unsigned,unsigned),func_020403F4(unsigned),func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(u8 *p);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_021B9DDC(char *),func_020419E4(void);
extern void *func_020056A0(void *,void *,int);
extern void func_02030EAC(struct Node *n);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201D83C(void *ptr);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *);
extern void func_021BA4AC(char *,unsigned char *,void *,int);
extern void *func_02045770(struct Descriptor *p);
extern void func_020439A0(struct Bmp *,struct Bmp *,unsigned,unsigned,int,int,unsigned,unsigned,unsigned);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, unsigned char, unsigned char, unsigned char);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(unsigned);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
int func_021B95A0(struct Obj0203159C *p,int unused,u32 v);
int func_021B95D4(int a0, int a1, int a2, int a3);
int func_021B95E8(void *p);
int func_021B95F8(char *p);
int func_021B9630(u8 *p);
int func_021B96B0(char *p);
int func_021B96C8(char *p);
int func_021B974C(char *p);
int func_021B97BC(char *p);
void func_021B98F4(void);
void func_021B9908(void);
void func_021B99CC(void);
void func_021B99F8(void);
void func_021B9A80(void *unused, int mode);
void func_021B9AD4(void *task,char *p);
void func_021B9AF8(char *p);
void func_021B9B10(char *p);
void func_021B9B1C(char *p);
void func_021B9B6C(char *p);
void func_021B9B98(char *p);
void func_021B9C30(char *p);
void func_021B9C58(char *p,void *s,unsigned i);
void func_021B9C80(char *p);
void func_021B9CC8(char *p);
void func_021B9D04(char *p);
void func_021B9D20(char *p);
void func_021B9D34(char *p);
void func_021B9DB0(char *p);
extern u8 ov067_id[];
extern char overlay_id[];
extern const Command d_021BABD0[];
extern int  d_021BABFC[];
extern const Small d_021BAC74;
extern const Big d_021BACC4, d_021BAC84, d_021BACA4;
extern unsigned SDK_AUTOLOAD_MAIN_TWL_START[];

int func_021B95A0(struct Obj0203159C *p,int unused,u32 v) { u8 *q; func_0203064C(1,142,0x125000); q=func_0203159C(p,756,142); func_02082BCC(q,0,756); ((struct Obj24498 *)q)->f0=v; return 1; }


int func_021B95D4(int a0, int a1, int a2, int a3)
{
    return func_021B95F8((char *)a3) == 0;
}


int func_021B95E8(void *p)
{
    func_020315D4(p);
    func_020306F0(0x8e);
    return 1;
}

extern int (*const d_021BAB70[])(char *);

int func_021B95F8(char *p){func_021BA318((unsigned char *)p);((struct Obj14406 *)p)->f2E8=d_021BAB70[*(unsigned *)(p+0x2e8)](p);if(((struct Obj14406 *)p)->f2E8==5)return 0;func_021B9C80(p);func_021B9F40(p);return 1;}


int func_021B9630(u8 *p)
{
    func_02034AC4((int)ov067_id);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    func_0204363C(1);
    func_0207D534((void *)0x0400006c, -0x10);
    func_0207D534((void *)0x0400106c, -0x10);
    func_021B98F4();
    func_021B9908();
    func_021B99F8();
    func_021B9B1C((char *)p);
    func_021B9D34((char *)p);
    func_021B9E14((char *)p);
    func_021B9D04((char *)p);
    func_021B9AF8((char *)p);
    func_02005DAC((void *)0x3f8);
    return 3;
}


int func_021B96B0(char *p)
{
    if (func_020221A4() == 1)
        return ((struct Obj24499 *)p)->f2F0;
    return 1;
}

int func_021B96C8(char *p) {
if(sub_02005E50()==1)return 2;
if(sub_02005F38()==1)sub_02005D28();
func_021B9B10(p);func_021B9D20(p);func_021B9F1C(p);func_021B9DB0(p);func_021B9B6C(p);func_021B99CC();
func_0207D534((volatile u16 *)0x0400006c,-16);func_0207D534((volatile u16 *)0x0400106c,-16);
*(volatile u16 *)0x04000050=0;*(volatile u16 *)0x04001050=0;
sub_02043534(0);sub_020435F4(0);sub_02034A5C((int)overlay_id);return 5;
}

#define COUNT(p) (*(unsigned *)((p) + 0x2E4))

int func_021B974C(char *p)
{
    switch (STATE(p)) {
    case 0:
        if (COUNT(p) >= 41) {
            COUNT(p) = 0;
            STATE(p)++;
        } else if (((struct Obj00682 *)p)->f2D2 == 1) {
            COUNT(p) += 4;
        } else {
            COUNT(p)++;
        }
        break;
    case 1:
        if (func_021BA83C(p) == 0)
            STATE(p)++;
        break;
    case 2:
        COUNT(p) = 0;
        STATE(p) = 0;
        return 4;
    }
    return 3;
}

int func_021B97BC(char *p) {
    char *row;
    if(((struct Obj01003 *)p)->f2EC==0) {
        for(;;) {
            row=*(char * *)&((struct Obj01003 *)p)->f2D4+((struct Obj01003 *)p)->f2D8*16;
            if(((struct Obj01003 *)p)->f2D8==*(u32 *)((u32)p+((struct Obj01003 *)p)->f2BB*8+0xbc)) {
                func_021B9CC8(p);
                (((struct Obj01003 *)p)->f2BB)++;
                *(u16 *)&((struct Obj01003 *)p)->f2DA=((struct Obj24500 *)row)->f4;
                ((struct Obj01003 *)p)->f2EC=1;
                ((struct Obj01003 *)p)->f2D8+=2;
                break;
            }
            if(d_021BABD0[*(u8 *)(row+6)](p,row)==1) {
                (((struct Obj01003 *)p)->f2D8)++;
                break;
            }
            (((struct Obj01003 *)p)->f2D8)++;
        }
    }
    switch(((struct Obj01003 *)p)->f2EC) {
    case 1:
        if(((struct Obj01003 *)p)->f2DA<=0) {
            ((struct Obj01003 *)p)->f2DA=0; ((struct Obj01003 *)p)->f2EC=0;
        } else if(((struct Obj01003 *)p)->f2D2==1) ((struct Obj01003 *)p)->f2DA-=4;
        else (((struct Obj01003 *)p)->f2DA)--;
        break;
    case 2: if(func_021BA5E8(p)==0) ((struct Obj01003 *)p)->f2EC=0; break;
    case 3: if(func_021BA6F0(p)==0) ((struct Obj01003 *)p)->f2EC=0; break;
    case 5:
        if(func_02005F38()==1) func_02005E30(64);
        return func_021BA2AC((u8 *)p,2);
    }
    func_021BA390(p);
    return 4;
}


void func_021B98F4(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BABFC);
}

void func_021B9908(void)
{
    Small a;
    Big b, c;
    Small d;
    Big e;
    func_0203F8F4(0x8E);
    a = d_021BAC74;
    func_0203FC28((struct DispConfig *)(&a));
    b = d_021BACC4;
    func_0203FCA0(1, (const struct BgTemplate *)(&b), 0);
    c = d_021BAC84;
    func_0203FCA0(3, (const struct BgTemplate *)(&c), 2);
    func_02051E74((struct Mtx22 *)(&d), 0, (const void *)0x9000, (const void *)0x9000, 0);
    sub_02040860(3, (unsigned)&d, 0x80, 0x60);
    e = d_021BACA4;
    func_0203FCA0(5, (const struct BgTemplate *)(&e), 0);
    func_020434DC(2, 1);
    func_02043598(2, 1);
}

/*
 * Tail: two zero alignment bytes at 0x021B99F6.
 */
void func_021B99CC(void){func_020434DC(2,0);func_02043598(2,0);func_020403F4(5);func_020403F4(3);func_020403F4(1);func_0203F9B4();}


void func_021B99F8(void)
{
    u8 *p = func_020490F4(0x1a, 0x808e);
    func_02049658(p, 0, 3, 0, 0, 1, 0x8e);
    func_020498F4(p, 1, 3, 0, 0, 1, 0x8e);
    func_02049238(p);
    p = func_020490F4(0xdc, 0x808e);
    func_02049B68(p, 0xc, 0, 0x1e0, 0x20, 0x8e);
    func_02049B68(p, 0xc, 4, 0x1e0, 0x20, 0x8e);
    func_02049238(p);
    func_02040EBC(1, 0);
    func_02040EBC(5, 0);
}

void func_021B9A80(void *unused, int mode)
{
    unsigned char *h;
    if (mode == 1) {
        h = func_020490F4(0x1A, 0x808E);
        func_02049B68(h, 2, 0, 0, 0, 0x8E);
    } else {
        h = func_020490F4(0xDC, 0x808E);
        func_02049B68(h, 0xC, 0, 0x1E0, 0x20, 0x8E);
    }
    func_02049238(h);
    func_02040EBC(1, 0);
}

/*
 * volatile: SDK OS_SetIrqCheckFlag read-modify-write at 0x02FE3FF8.
 */
void func_021B9AD4(void *task,char *p){func_021B9DDC(p);func_020419E4();*(volatile unsigned *)((unsigned)SDK_AUTOLOAD_MAIN_TWL_START+0x3ff8) |=1;}

void func_021B9AF8(char *p){((struct Obj03327 *)p)->f4=func_020056A0(func_021B9AD4,p,0);}

void func_021B9B10(char *p){func_02030EAC(((struct Obj24501 *)p)->f4);}

/*
 * Padding: two zero bytes at 0x021B9B6A, then the next function.
 */
void func_021B9B1C(char *p)
{
    ((struct Obj03327 *)p)->fB0 = func_02045B38(0, 2, 0xB1, 0x8E);
    ((struct Obj03327 *)p)->fB4 = func_020457B0(0x80, 0x8E);
    ((struct Obj03327 *)p)->fA8 = func_0201D7EC(0x17, 0, 1, 0, 0x8E);
    ((struct Obj03327 *)p)->fAC = func_0201D7EC(0x17, 2, 1, 0, 0x8E);
}

void func_021B9B6C(char *p){func_0201D83C(((struct Obj08302 *)p)->fAC);func_0201D83C(((struct Obj08302 *)p)->fA8);func_02045808(((struct Obj08302 *)p)->fB4);func_02045C04(((struct Obj08302 *)p)->fB0);}

#undef COUNT
#define COUNT(p) (*(unsigned short *)((p) + 0x2B8))

void func_021B9B98(char *p)
{
    unsigned short i;
    int found = 0;
    for (i = 0; ; i++) {
        Entry *e = &ENTRIES(p)[i];
        if (found == 0) {
            if (e->kind == 7)
                found = 1;
        } else {
            if (e->kind == 5)
                break;
            if (e->kind == 0 && e->text != 0xFFFF && ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->tag == 0 &&
                ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->kind == 0 && ((Entry *)((unsigned)ENTRIES(p) + (i + 1) * 16))->text != 0xFFFF) {
                *(void **)(p + COUNT(p) * 8 + 0xB8) = func_02043678(0x20, 2, 0x20, 0x8E);
                *(int *)(p + COUNT(p) * 8 + 0xBC) = i;
                COUNT(p)++;
                if (COUNT(p) == 0x40)
                    break;
                i++;
            }
        }
    }
}

void func_021B9C30(char *p){unsigned i;for(i=0;i<((struct Obj24502 *)p)->f2B8;i++)func_020437AC(*(struct Obj020437AC **)((unsigned)p+i*8+0xb8));}

void func_021B9C58(char *p,void *s,unsigned i){unsigned char *q=*(unsigned char * *)&((struct Obj14407 *)p)->f2D4+i*16;if(q[9]==0)func_021BA4AC(p,q,s,0);else func_021BA4AC(p,q,s,2);}

void func_021B9C80(char *p)
{
    if (IDX(p) < ((struct Obj14407 *)p)->f2B8) {
        func_021B9C58(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC));
        func_021B9C58(p, *(void **)(p + IDX(p) * 8 + 0xB8), *(int *)(p + IDX(p) * 8 + 0xBC) + 1);
        IDX(p)++;
    }
}

void func_021B9CC8(char *p){struct Bmp *s=func_02045770(((struct Obj14408 *)p)->f2C4);func_020439A0(*(struct Bmp **)((unsigned)p+((struct Obj14408 *)p)->f2BB*8+0xb8),s,0,0,0,192,256,16,0);}


void func_021B9D04(char *p)
{
    ((struct Obj24503 *)p)->f2D4 = (int)func_02048F60(0xdc, 1, 0x8e);
    func_021B9B98(p);
}


void func_021B9D20(char *p)
{
    func_021B9C30(p);
    func_020307B0((void *)(((struct Obj24504 *)p)->f2D4));
}

/*
 * Padding: two zero bytes at 0x021B9DAE, then the next function.
 */
void func_021B9D34(char *p)
{
    unsigned h;
    func_02045088(0x8E);
    ((struct Obj03327 *)p)->f2BC = func_020450F0(1, 0, 0, 0x20, 0x19, 0xF, 1);
    ((struct Obj03327 *)p)->f2C4 = func_020450F0(5, 0, 0, 0x20, 0x1C, 0xF, 1);
    h = ((struct Obj03327 *)p)->f2BC;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
    h = ((struct Obj03327 *)p)->f2C4;
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
}

void func_021B9DB0(char *p){func_020452E8(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2BC);func_020452E8(*(struct Descriptor * *)&((struct Obj14409 *)p)->f2C4);func_020450C8();}
