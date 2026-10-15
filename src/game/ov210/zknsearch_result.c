/*
 * file:     zknsearch_result.c
 * unit:     yes
 * function: func_021C04CC, func_021C0550, func_021C0584, func_021C05B4, func_021C05B8, func_021C05BC, func_021C05EC, func_021C05F0, func_021C0608, func_021C0660, func_021C0678, func_021C06A8, func_021C06AC, func_021C06C4, func_021C06F8, func_021C06FC
 * address:  0x021C04CC
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   d_021C0CC0 0x021C0CC0 data a4
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   STRBUF_Delete 0x02045808 arm
 *   func_021BEC60 0x021BEC60 thumb ov210
 *   func_021BF7B0 0x021BF7B0 thumb ov210
 *   func_021BFBF8 0x021BFBF8 thumb ov210
 *   func_021BF728 0x021BF728 thumb ov210
 *   func_021BCEF0 0x021BCEF0 thumb ov210
 *   func_021BECAC 0x021BECAC thumb ov210
 *   func_021BFA14 0x021BFA14 thumb ov210
 *   func_021BFB8C 0x021BFB8C thumb ov210
 *   func_021BFCE4  0x021BFCE4  thumb  ov210
 */
#include "../../matched/include/Obj06699.h"
#include "../../matched/include/Obj14683.h"
#include "../../matched/include/Obj04620.h"
#include "../../matched/include/Obj25636.h"

struct S;
struct Tmpl;
struct U16Vec;
typedef unsigned short u16;

typedef struct Template { unsigned char prefix[24]; unsigned char zero, count; unsigned short offset; unsigned words[2]; void *ctx; } Template;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern struct S *FRAME_LIST_Create(struct Tmpl *tmpl, unsigned int heap);
extern void FRAME_LIST_CopyMapToBuffer(unsigned char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int index);
extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void ARC_TOOL_DeleteHandle(void *);
extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);
extern void FRAME_LIST_Delete(struct S *s);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021BEC60(int p, int *a, u32 b);
extern void func_021BF7B0(char *p, int idx, int y, int flag);
extern void func_021BFBF8(int p, int v);
extern void func_021BF728(u8 *p, int a);
extern u32 func_021BCEF0(u32 a, u32 b);
extern void func_021BECAC(int p, unsigned *b);
extern void func_021BFA14(char *p, int y, int flag);
extern void func_021BFB8C(char *ctx, unsigned long slot, int y, int flag);
extern void func_021BFCE4(char *p, int dx);
void func_021C04CC(char *ctx);
void func_021C0550(int p);
void func_021C0584(int p, unsigned a, int b, int c, int d);
void func_021C05B4(void);
void func_021C05B8(void);
void func_021C05BC(int p, unsigned a, int b, int c, int d);
void func_021C05EC(void);
void func_021C05F0(int p, int v);
void func_021C0608(char *p,int index,void *data,int value,int flag);
void func_021C065C(void);
void func_021C0660(int p, int v);
void func_021C0678(int p, unsigned a, int b, int c, int d);
void func_021C06A8(void);
void func_021C06AC(int p, int v);
void func_021C06C4(int p, unsigned a, unsigned *b, int c, int d);
void func_021C06F8(void);
void func_021C06FC(int a, int b);
extern const Template d_021C0CC0;






void func_021C04CC(char *ctx)
{
    void *archive = func_020490F4(159, 0x807b);
    Template config;
    unsigned i;
    config = d_021C0CC0;
    config.zero = 0;
    config.offset = 0;
    config.ctx = ctx;
    ((struct Obj06699 *)ctx)->f1E0 = FRAME_LIST_Create((struct Tmpl *)(&config), 123);
    ((struct Obj06699 *)ctx)->f2AC = config.count;
    FRAME_LIST_CopyMapToBuffer(((struct Obj06699 *)ctx)->f1E0, (unsigned int)archive, 98, 0, 0);
    FRAME_LIST_LoadPalettes(((struct Obj06699 *)ctx)->f1E0, archive, 73, 2, 3);
    ARC_TOOL_DeleteHandle(archive);
    for (i = 0; i < 14; i++) FRAME_LIST_AddItem(((struct Obj06699 *)ctx)->f1E0, 0, i);
}







/*
 * Addresses are Black-image addresses.
 */
void func_021C0550(int p)
{
    unsigned i;

    FRAME_LIST_Delete((struct S *)(((struct Obj14683 *)p)->f1E0));
    ((struct Obj14683 *)p)->f1E0 = 0;
    for (i = 0; i < 0x32; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0x79] != 0) {
            STRBUF_Delete((struct U16Vec *)q[0x79]);
            q[0x79] = 0;
        }
    }
}






void func_021C0584(int p, unsigned a, int b, int c, int d)
{
    func_021BEC60(p, (int *)b, *(int *)(p + a * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((struct Obj04620 *)p)->f0 + 2))[1] == a)
        func_021BF7B0((char *)p, 0, c, d);
}






/* hidden function: empty leaf (bx lr) in an address gap */
void func_021C05B4(void)
{
}






/* hidden function: empty leaf (bx lr) in an address gap */
void func_021C05B8(void)
{
}





void func_021C05BC(int p, unsigned a, int b, int c, int d)
{
    func_021BEC60(p, (int *)b, *(int *)(p + a * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((struct Obj04620 *)p)->f0 + 2))[2] == a)
        func_021BF7B0((char *)p, 0, c, d);
}






/* hidden function: empty leaf (bx lr) in an address gap */
void func_021C05EC(void)
{
}






void func_021C05F0(int p, int v)
{
    func_021BFBF8(p, (signed char)(-v));
    func_021BF728((u8 *)p, 1);
}






/*
 * trailing: unit aligns the bx-lr follower at 021C065C after zero pad
 * 021C065A; two additional zero alignment bytes at 021C065E follow the unit.
 */
void func_021C0608(char *p,int index,void *data,int value,int flag)
{
    func_021BEC60((int)p,data,(*(unsigned *)(p+484+index*4)));
    if(index==func_021BCEF0((u32)p,(unsigned char)(*(char **)(*(char * *)&((struct Obj04620 *)p)->f0+8))[3]))func_021BF7B0(p,0,value,flag);
    if(index==func_021BCEF0((u32)p,(unsigned char)(*(char **)(*(char * *)&((struct Obj04620 *)p)->f0+8))[4]))func_021BF7B0(p,1,value,flag);
}






void func_021C065C(void){}







void func_021C0660(int p, int v)
{
    func_021BFBF8(p, (signed char)(-v));
    func_021BF728((u8 *)p, 1);
}





void func_021C0678(int p, unsigned a, int b, int c, int d)
{
    func_021BEC60(p, (int *)b, *(int *)(p + a * 4 + 0x1e4));
    if ((*(u8 **)(*(int * *)&((struct Obj04620 *)p)->f0 + 2))[5] == a)
        func_021BF7B0((char *)p, 0, c, d);
}





/* hidden function: empty leaf (bx lr) in an address gap */
/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
void func_021C06A8(void)
{
}




void func_021C06AC(int p, int v)
{
    func_021BFBF8(p, (signed char)(-v));
    func_021BF728((u8 *)p, 1);
}




void func_021C06C4(int p, unsigned a, unsigned *b, int c, int d)
{
    func_021BECAC(p, b);
    if ((*(u8 **)(*(int * *)&((struct Obj25636 *)p)->f0 + 2))[6] == a)
        func_021BFA14((char *)p, c, d);
    func_021BFB8C((char *)p, (unsigned short)a, c, d);
}


/* Empty callback. */
void func_021C06F8(void)
{
}


void func_021C06FC(int a, int b)
{
    func_021BFCE4((char *)a, (signed char)(-b));
    func_021BF728((u8 *)a, 1);
}
