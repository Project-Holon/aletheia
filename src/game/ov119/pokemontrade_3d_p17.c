/*
 * file:     pokemontrade_3d_p17.c
 * unit:     yes
 * function: func_021E4F28, func_021E5098, func_021E5158, func_021E5164, func_021E51A4, func_021E5284, func_021E53CC, func_021E53F8
 * address:  0x021E4F28
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF6B4 0x021DF6B4 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B404 0x0204B404 arm
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02049DF4 0x02049DF4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   d_021E8530 0x021E8530 data a4
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B454 0x0204B454 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov119
 *   func_021D8B0C 0x021D8B0C thumb ov119
 *   func_021E57E8 0x021E57E8 thumb ov119
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02041300 0x02041300 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040618 0x02040618 arm
 *   d_021E7E24 0x021E7E24 data a4
 *   d_021E7F44 0x021E7F44 data a4
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204A48C 0x0204A48C arm
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   d_021E7D40 0x021E7D40 data a4
 *   d_021E7CC8 0x021E7CC8 data a4
 */
#include "../../matched/include/Obj05334.h"
#include "../../matched/include/Obj08071.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22808.h"
#include "../../matched/include/Obj02829.h"
#include "../../matched/include/Obj13923.h"
#include "../../matched/include/Obj22814.h"

struct Obj;
struct Vec2;
struct Actor;
struct PtS;
struct DispVram;
struct Cfg;
typedef short s16_021E4F28;

typedef unsigned char u8;

typedef struct Pt_021E4F28 { s16_021E4F28 x, y; } Pt_021E4F28;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef int s32;

typedef signed short s16_021E51A4;

typedef struct Pt_021E51A4 {s16_021E51A4 x,y;} Pt_021E51A4;

typedef struct Object {u8 pad[0xac0];void *actors[12][5];} Object;

typedef struct BgTemplate { u32 a,b,bufSize,d; u8 e,f,g,h; u32 i; u8 j,k,l,m; u32 n; } BgTemplate;

extern int func_021DF6B4(char *, int, int);
extern u8 func_020355C4(void);
extern void func_0204B800(int, u8);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void *func_02030734(unsigned heapId, unsigned size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *func_021D8DD0(void *a, int b, int c, char *p);
extern unsigned int func_0201BA68(void *mon);
extern u32 func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082D44(void *, const void *, int);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern s32 _s32_div_f(s32 num, s32 den);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern int func_021D8AF4(int,char *),func_021D8B0C(int,int);
extern void func_021E57E8(int),func_0203FCA0(u32,const BgTemplate *,u32);
extern void func_02040C14(u32,u32,u32,u32),func_02041300(u32,int,int,int,u8,u8,u8),func_020409B4(u32);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern void func_021E57E8(int);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
void func_021E4F28(char *p);
void func_021E5098(char *p, int b);
s32 func_021E5158(s32 x);
void func_021E5164(int p);
int func_021E51A4(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow);
void func_021E5284(char *p,int mode);
void func_021E53CC(int p);
void func_021E53F8(char *p);
extern char d_021E8530[];
extern const BgTemplate d_021E7E24,d_021E7F44;
extern const char d_021E7D40[];
extern const char d_021E7CC8[];

/*
 * lever:    the hoisted column sum is written inside the else arm as two statements.
 */
void func_021E4F28(char *p)
{
    char *q;
    int i, off, y, row, j, x, ty, col;
    Pt_021E4F28 b, a;
    off = 0;
    y = ((struct Obj05334 *)p)->f1080;
    for (i = 0; i < 12; i++) {
        row = func_021E5158(((struct Obj05334 *)p)->f1080 + i);
        if (y >= ((struct Obj05334 *)p)->f634) {
            y -= ((struct Obj05334 *)p)->f634;
            off = ((struct Obj05334 *)p)->f63C;
        }
        for (j = 0; j < 5; j++) {
            ty = j * 24 + 0x20;
            if (y == 0) x = 0x1c;
            else if (y == 1) x = 0x3c;
            else {
                col = (y - 2) / 6 * 160;
                col += (y - 2) % 6 * 24 + 0x14;
                x = col + 0x60;
            }
            b.x = off + (x - ((struct Obj05334 *)p)->f107C);
            b.y = ty;
            a = b;
            if (func_021DF6B4(p, y, j) && func_020355C4() == 1) {
                b.y -= 8;
                q = p + row * 20 + j * 4;
                func_0204B800(((struct Obj08071 *)q)->fAC0, 11);
            } else {
                q = p + row * 20 + j * 4;
                func_0204B800(((struct Obj08071 *)q)->fAC0, 0x1c - i);
            }
            func_0204B404((struct Obj *)(((struct Obj08071 *)q)->fAC0), (const struct Vec2 *)(&b), 1);
            if (*(u8 *)(p + row * 5 + j + 0xebc)) {
                *(Pt_021E4F28 *)(q + 0xdcc) = a;
            }
            b.y = ty + 3;
            func_0204B404((struct Obj *)(((struct Obj08071 *)q)->fBB0), (const struct Vec2 *)(&b), 1);
        }
        y++;
    }
}

/*
 * lever: initial guard is a forward goto, with the exit after the body.
 */
void func_021E5098(char *p, int b)
{
    int i, n, x, t, out;
    void *a;
    if (b == 0) *(int *)&((struct Obj00001 *)p)->f1184 = (int)func_02030734(((struct Obj00001 *)p)->f5F4, 0x5ac00, 0, d_021E8530, 0x50b);
    a = func_020490F4(7, ((struct Obj00001 *)p)->f5F4);
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = (int)func_021D8DD0((void *)(*(int *)&((struct Obj00001 *)p)->f828), b, i, p);
            if (x) x = func_0201BA68((void *)x);
            else x = func_0201BABC(0, 0, 0, 0);
            t = (int)func_02049DF4(a, x, 0, (u32)(&out), ((struct Obj00001 *)p)->f5F4);
            func_02082D44(((struct Obj22808 *)out)->f14, (void *)(*(int *)&((struct Obj00001 *)p)->f1184 + n * 512), 512);
            n++;
            func_020307B0((void *)t);
        }
    }
    goto done;
check:
    if (b < 25) goto body;
done:
    func_02049238(a);
}


/*
 * Signed remainder by 12.  The MSL divide helper returns the quotient in r0
 * and the remainder in r1, so `x % 12` moves r1 down to r0.
 */
s32 func_021E5158(s32 x)
{
    return x % 12;
}

/*
 * extent: two zero padding bytes at 0x021E51A2.
 */
void func_021E5164(int p)
{
    int i, j;
    for (i = 0; i < 12; i++)
        for (j = 0; j < 5; j++)
            func_0204B3DC((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xac0), 0);
}

/*
 * lever: pos precedes the integer locals; a typed return-base temporary
 * keeps the row/column byte offsets spilled instead of reusing r7.
 * initialization: the only ov119 calls are D9EEC and D9F5C. D9F24
 * passes p+f80 as outA; D9EBC forwards outA from its only caller DA3BC,
 * where r1=p+f98. Thus all reachable hit paths enter the outA block
 * before reading slot through outSlot. No default value is invented.
 * 0204B454 writes both coordinate halfwords through 0204B53C and then
 * subtracts the origin, itself written through 0204CF74/0204B0C8.
 */
int func_021E51A4(char *p,int x,int y,int *outA,int *outB,int *outSlot,int *outColumn,int *outRow)
{
 Pt_021E51A4 pos;
 int column,slot,row;
 Object *tmp;
 for(row=0;row<12;row++) {
  for(column=0;column<5;column++) {
   func_0204B454((struct Actor *)((Object *)p)->actors[row][column],(struct PtS *)&pos,1);
   if(pos.x<=x && x<pos.x+24 && pos.y<=y && y<pos.y+24) {
    if(outA) {
     slot=*(u8 *)(p+0xd90+row*5+column);
     if(slot==255)return 0;
     if(func_021D8B0C(slot,column)!=-1) {
      *outA=func_021D8AF4(slot,p);
      *outB=func_021D8B0C(slot,column);
     } else return 0;
    }
    if(outSlot) {*outSlot=slot;*outColumn=column;*outRow=row;}
    tmp=(Object *)p;
    return (int)tmp->actors[row][column];
   }
  }
 }
 return 0;
}

/*
 * interface: 02040618's legacy fourth argument is forwarded only to
 * 02042360, whose complete matched body reads r0-r2 and never r3.
 * The original calls here set only r0-r2; retain its three-input API.
 */
void func_021E5284(char *p,int mode)
{
 BgTemplate a,b;
 void *v;
 func_021E57E8(1);p[0x11ec]=1;
 a=d_021E7E24;func_0203FCA0(6,&a,0);func_02040C14(6,0,1,0);func_02041300(6,0,0,0,32,24,17);func_020409B4(6);
 b=d_021E7F44;func_0203FCA0(7,&b,2);
 if(mode==0) {
  v=func_020490F4(0x67,((struct Obj02829 *)p)->f5F4);
  func_02049B68(v,5,6,0x6000,0,((struct Obj02829 *)p)->f5F4);
  func_02049658((void *)((u32)v),4,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_020498F4((void *)((u32)v),6,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_02040618(7,0,0);func_02049238(v);
 } else {
  v=func_020490F4(0x68,((struct Obj02829 *)p)->f5F4);
  func_02049B68(v,1,6,0x6000,0,((struct Obj02829 *)p)->f5F4);
  func_02049658((void *)((u32)v),0,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_020498F4((void *)((u32)v),2,7,0,0,0,((struct Obj02829 *)p)->f5F4);
  func_02040618(7,0,0);func_02049238(v);
 }
}

void func_021E53CC(int p)
{
    if (((struct Obj13923 *)p)->f11EC != 0) {
        func_02040DA8(6, 1, 0);
        func_020403F4(6);
        func_020403F4(7);
        ((struct Obj13923 *)p)->f11EC = 0;
    }
}

void func_021E53F8(char *p)
{
    func_020433E0((const struct DispVram *)d_021E7D40);
    func_0204A48C((const struct Cfg *)d_021E7CC8, (unsigned int)d_021E7D40, ((struct Obj22814 *)p)->f5F4);
    func_021E57E8(0);
    func_02043534(0);
    func_020435F4(0);
}
