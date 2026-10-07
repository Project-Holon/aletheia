/*
 * file:     pokelist_p05.c
 * unit:     yes
 * function: func_021B71B0, func_021B71E4, func_021B7268, func_021B7298, func_021B7624, func_021B7698, func_021B7B98, func_021B7CC4, func_021B8180, func_021B83D8, func_021B8418, func_021B8508, func_021B86D8, func_021B8758, func_021B892C, func_021B8A8C, func_021B8AC4
 * address:  0x021B71B0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02049B40  0x02049B40  arm
 *   func_0201C450  0x0201C450  thumb
 *   func_0201DD68  0x0201DD68  thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0201BC40  0x0201BC40  thumb
 *   func_0201BCB4  0x0201BCB4  thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_02027630  0x02027630  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02027758  0x02027758  thumb
 *   func_0202775C  0x0202775C  thumb
 *   func_02027760  0x02027760  thumb
 *   func_02027764  0x02027764  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_02027694  0x02027694  thumb
 *   func_02027698  0x02027698  thumb
 *   func_0202769C  0x0202769C  thumb
 *   func_020276A0  0x020276A0  thumb
 *   func_020276B4  0x020276B4  thumb
 *   func_020276B8  0x020276B8  thumb
 *   func_020276BC  0x020276BC  thumb
 *   func_020276C0  0x020276C0  thumb
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_021BBDEC 0x021BBDEC thumb ov091
 *   func_021BC1B4 0x021BC1B4 thumb ov091
 *   func_021BC1D0 0x021BC1D0 thumb ov091
 *   func_021BC2C8 0x021BC2C8 thumb ov091
 *   func_021BA65C 0x021BA65C thumb ov091
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 *   func_021BAFA0 0x021BAFA0 thumb ov091
 *   func_021BDC5C 0x021BDC5C thumb ov091
 *   func_021BDCA0 0x021BDCA0 thumb ov091
 *   func_021B9F34 0x021B9F34 thumb ov091
 *   func_021BA004 0x021BA004 thumb ov091
 *   func_021B9E20 0x021B9E20 thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_02009050 0x02009050 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_0200902C 0x0200902C thumb
 *   func_020409B4 0x020409B4 arm
 *   func_021B907C 0x021B907C thumb ov091
 *   func_021BC17C 0x021BC17C thumb ov091
 *   func_021BDD78 0x021BDD78 thumb ov091
 *   func_021BC350 0x021BC350 thumb ov091
 *   func_021BE2B4 0x021BE2B4 thumb ov091
 *   func_021BB200 0x021BB200 thumb ov091
 *   func_021BB2C0 0x021BB2C0 thumb ov091
 *   func_021BA670 0x021BA670 thumb ov091
 *   func_021BDCC0 0x021BDCC0 thumb ov091
 *   func_021BDD58 0x021BDD58 thumb ov091
 *   func_021BC30C 0x021BC30C thumb ov091
 *   func_021B9BF4 0x021B9BF4 thumb ov091
 *   func_021B9788 0x021B9788 thumb ov091
 *   func_021BA624 0x021BA624 thumb ov091
 *   func_021BB97C 0x021BB97C thumb ov091
 *   func_021BB99C 0x021BB99C thumb ov091
 *   func_021BB9AC 0x021BB9AC thumb ov091
 *   func_021BB9BC 0x021BB9BC thumb ov091
 *   func_021BB9CC 0x021BB9CC thumb ov091
 *   func_021BB98C 0x021BB98C thumb ov091
 *   func_021BC24C 0x021BC24C thumb ov091
 *   func_021BC288 0x021BC288 thumb ov091
 *   func_021BDBF8 0x021BDBF8 thumb ov091
 *   func_021BDC3C 0x021BDC3C thumb ov091
 *   func_021B9AC8 0x021B9AC8 thumb ov091
 *   func_021BA5B4 0x021BA5B4 thumb ov091
 *   func_021BA60C 0x021BA60C thumb ov091
 *   func_021B9E3C 0x021B9E3C thumb ov091
 *   func_021BA4E4 0x021BA4E4 thumb ov091
 *   func_021BA098 0x021BA098 thumb ov091
 *   func_021B9EB0 0x021B9EB0 thumb ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021BB714  0x021BB714  thumb  ov091
 *   func_021BB7E8  0x021BB7E8  thumb  ov091
 *   func_021BD4EC  0x021BD4EC  thumb  ov091
 *   func_021BB468  0x021BB468  thumb  ov091
 *   func_021BC228  0x021BC228  thumb  ov091
 *   func_021BBAF8  0x021BBAF8  thumb  ov091
 *   func_021F6744  0x021F6744  thumb  ov112
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021B9AB4  0x021B9AB4  thumb  ov091
 *   func_021BBE5C  0x021BBE5C  thumb  ov091
 *   func_021B8F68  0x021B8F68  thumb  ov091
 *   func_02041300  0x02041300  arm
 *   func_021BB43C  0x021BB43C  thumb  ov091
 *   func_020061E4  0x020061E4  thumb
 *   func_021BBE68  0x021BBE68  thumb  ov091
 *   func_0204B878  0x0204B878  arm
 *   func_021B9968  0x021B9968  thumb  ov091
 *   func_021BB464  0x021BB464  thumb  ov091
 *   func_021BA288  0x021BA288  thumb  ov091
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02019E54  0x02019E54  thumb
 *   func_021BB9EC  0x021BB9EC  thumb  ov091
 *   func_021B8DB4 0x021B8DB4 thumb ov091
 *   func_020362DC  0x020362DC  arm
 *   func_0203633C  0x0203633C  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_021B9AA0  0x021B9AA0  thumb  ov091
 *   func_0201AA18  0x0201AA18  thumb
 *   func_021BB3C4  0x021BB3C4  thumb  ov091
 *   d_021BEAB0     0x021BEAB0  data  a1
 *   d_021BEAAA     0x021BEAAA  data  a1
 */
#include "../../matched/include/Obj01888.h"
#include "../../matched/include/Obj02767.h"
#include "../../matched/include/Obj06209.h"
#include "../../matched/include/Obj00047.h"
#include "../../matched/include/Obj20856.h"
#include "../../matched/include/Obj00009.h"
#include "../../matched/include/Obj20857.h"
#include "../../matched/include/Obj20858.h"
#include "../../matched/include/Obj20859.h"
#include "../../matched/include/Obj06210.h"

#define S (*(u8 **)(p+0x280))
#define H(k) (*(u16 *)(S+(k)))
#define T(k) (*(u32 *)(S+(k)))
struct Bank;
struct Obj;
struct GfFont;
struct MsgBank;
struct PrintSys;
struct Rec;
struct Sub02008F80Obj;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed int     s32;

extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02049B40(u32 h, u32 a, u32 c, u32 d, u32 e, u16 heap);
extern void *func_0201C450(u16 n, u32 heap);
extern void func_0201DD68(void);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void *func_02049EF4(void *h, u32 a1, u32 a2, void **out, u16 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_02027630(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern int func_02027758(void);
extern int func_0202775C(int a);
extern int func_02027760(int a);
extern int func_02027764(int a);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32 a);
extern u32 func_020276A0(u32 a);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32 a);
extern u32 func_020276C0(u32 a);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern unsigned int func_020307B0(void *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020409B4(u32 index);
extern void func_020061E4(u32);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern void func_02017E40(void *,u32,u32);
extern void func_0200902C(struct Sub02008F80Obj *arr, u32 unused, int i);
extern void func_021B907C(u8 *);
extern int func_021BC17C(unsigned short *p, int id);
extern int func_021BDD78(void *a, u32 id, int slot, u32 heap);
extern int func_021BC350(u8 *,int);
extern int func_021BE2B4(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
extern void func_021BB200(u8 *a, u8 *s, int p, int q);
extern void func_021BB2C0(u8 *a, u8 *s);
extern u32 func_021BA670(u8 *p, u16 id);
extern int func_021BDCC0(char *p, u32 a1);
extern void func_021BDD58(u32 p, void *m);
extern void func_021BC30C(int p);
extern u32 func_021B9BF4(u8 *p, void *mon, u32 param);
extern void func_021B9788(u8 *,int,int,int);
extern void func_021BA624(u8 *,void *,u16);
extern void func_021BB97C(u16 *p, u32 s);
extern void func_021BB99C(int a, int b, int c, int d);
extern void func_021BB9AC(int a, int b, int c, int d);
extern void func_021BB9BC(int a, u32 b, u32 c, int d);
extern void func_021BB9CC(int a, int b, int c, int d);
extern void func_021BB98C(void *p, u32 s);
extern void func_021BC24C(void *unused, void *a, int b);
extern void func_021BC288(int unused, int a, int b);
extern int func_021BDBF8(u8 *,u32);
extern void func_021BDC3C(u32 p, void *m);
extern int func_021B9AC8(u8 *p, void *mon, u8 bit);
extern u32 func_021BA5B4(u8 *p, void *q);
extern void func_021BA60C(u8 *p, void *q);
extern void func_021B9E3C(char *p);
extern void func_021BA4E4(u8 *p);
extern void func_021BA098(u8 *p);
extern void func_021B9EB0(u8 *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5);
extern int func_021BC1B4(unsigned short *p, void *id);
extern int func_021BC1D0(u8 *);
extern void func_021BC2C8(int p);
extern u32 func_021BA65C(u8 *p, u16 id);
extern void func_021BB7A4(void *p, u32 *s);
extern void func_021BAFA0(u8 *a, u8 *s, int k);
extern int func_021BDC5C(u8 *,u32);
extern void func_021BDCA0(u32 p, void *m);
extern void func_021B9F34(u8 *p);
extern void func_021BA004(u8 *p);
extern void func_021B9E20(u8 *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021BB714(void *a, u32 *s, u32 k);
extern void func_021BB7E8(u8 *a, u32 *s, u32 x);
extern void func_021BD4EC(char *p);
extern int func_021BB468(int unused, int *p);
extern int func_021BC228(int unused, int id);
extern void func_021BBAF8(u8 *a, u8 *b, int *items);
extern int func_021F6744(void *p);
extern int func_021B9A84(u32 p);
extern int func_021B9AB4(u8 *p);
extern void func_021BBE5C(int h, int f);
extern void func_021B8F68(u8 *p, int v);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u8 a6);
extern int func_021BB43C(int *p);
extern void func_021BBE68(int h, int f);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021B9968(u8 *p);
extern unsigned short func_021BB464(int unused, unsigned short *p);
extern void func_021BA288(u8 *p);
extern int  func_02019E54(u32 a0, u32 a1, u32 a2);
extern void func_021BB9EC(int a, int b, int c, int d, unsigned char e);
extern void func_021B8DB4(unsigned char *);
extern u32  func_020362DC(void);
extern unsigned int func_0203633C(void);
extern u32 func_0204B3F4(struct Obj *p);
extern int func_021B9AA0(u32 p);
extern u32 func_0201AA18(void *p);
extern int func_021BB3C4(void *unused, u32 p);
void func_021B71B0(unsigned p);
void func_021B71E4(char *p);
void func_021B7268(unsigned p);
void func_021B7298(u8 *p);
void func_021B7624(char *p);
void func_021B7698(u8 *p);
void func_021B7B98(u8 *p);
void func_021B7CC4(u8 *p);
void func_021B8180(u8 *p);
void func_021B83D8(u8 *p);
void func_021B8418(u8 *p);
void func_021B8508(u8 *p);
void func_021B86D8(u8 *p);
void func_021B8758(u8 *p);
void func_021B892C(u8 *p);
void func_021B8A8C(unsigned char *p);
void func_021B8AC4(u8 *p);
extern const u8 d_021BEAB0[];
extern const u8 d_021BEAAA[];

void func_021B71B0(unsigned p) { func_0204B3B4(((struct Obj01888 *)p)->f1E0); func_0204B3B4(((struct Obj01888 *)p)->f1E4); func_0204B3B4(((struct Obj01888 *)p)->f1D8); func_0204B3B4(((struct Obj01888 *)p)->f1DC); func_0204B1CC(((struct Obj01888 *)p)->f1D4); }


void func_021B71E4(char *p)
{
    ((struct Obj02767 *)p)->f138 = func_0201D7EC(0x17, 0, 0, 0, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f13C = func_0201D7EC(0x17, 3, 0, 0, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f134 = func_02045B38(0, 2, 0x9d, ((struct Obj02767 *)p)->f0);
    func_02049B40(0x17, 5, 0, 0x1c0, 0x20, ((struct Obj02767 *)p)->f0);
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, ((struct Obj02767 *)p)->f0);
    ((struct Obj02767 *)p)->f140 = func_0201C450(0x1800, ((struct Obj02767 *)p)->f0);
    func_0201DD68();
}

void func_021B7268(unsigned p) { func_0201C6EC((struct PrintSys *)(((struct Obj06209 *)p)->f140)); func_0201C4C0((struct PrintSys *)(((struct Obj06209 *)p)->f140)); func_02045C04((struct Rec *)(((struct Obj06209 *)p)->f134)); func_0201D83C(((struct Obj06209 *)p)->f13C); func_0201D83C(((struct Obj06209 *)p)->f138); }


/*
 * Graphics setup: loads BG/char/screen/palette data from archive 0x4c, the
 * 0x07 archive and the func_020275E4 archive into p's handle table
 * (p+0x178..0x1d0), then copies palette RAM 0x050000C0 back to p+0x40.
 * The second-archive loads still pass the first (closed) handle to
 * func_02049B68/02049658/020498F4, as the original does.  The 0x158 store
 * goes through a local: stored directly, the allocator rematerialises the
 * shared 0xc0 offset base instead of reloading its [sp+0xc] spill slot.
 */
void func_021B7298(u8 *p)
{
    void *h;
    void *h2;
    void *t;

    h = func_020490F4(0x4c, ((struct Obj00047 *)p)->f0);
    func_02049B68(h, 6, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049B68(h, 0, 0, 0x1a0, 0x20, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xf, 3, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, 0x14, 3, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xc, 2, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    t = func_02049EF4(h, 0x12, 0, (void **)(p + 0x15c), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f158 = t;
    func_02049B68(h, 5, 4, 0, 0, ((struct Obj00047 *)p)->f0);
    func_02049658(h, 0xe, 7, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, 0x13, 7, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f178 = func_0204AC18(h, 4, 0, 0, 0, 3, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f198 = func_0204A6C8(h, 0xb, 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f19C = func_0204A6C8(h, 8, 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1B4 = func_0204AF28(h, 0x17, 0x1a, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1B8 = func_0204AF28(h, 0x16, 0x19, ((struct Obj00047 *)p)->f0);
    func_02049238(h);

    h2 = func_020490F4(7, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f190 = func_0204ACEC(h2, func_0201BC3C(), 0, 0xc0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1D0 = func_0204AF28(h2, func_0201BC40(), func_0201BCB4(), ((struct Obj00047 *)p)->f0);
    func_02049238(h2);

    h2 = func_020490F4(func_020275E4(), ((struct Obj00047 *)p)->f0);
    func_02049B68(h, func_02027624(), 0, 0x160, 0x20, ((struct Obj00047 *)p)->f0);
    func_02049658(h, func_02027628(), 1, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020498F4(h, func_02027630(), 1, 0, 0, 0, ((struct Obj00047 *)p)->f0);
    func_020413B0(1, 0, 0, 0x40, 0x20, 0xb);
    ((struct Obj00047 *)p)->f18C = func_0204AC18(h2, func_02027758(), 0, 0xa0, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1B0 = func_0204A6C8(h2, func_0202775C(2), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1CC = func_0204AF28(h2, func_02027760(2), func_02027764(2), ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f17C = func_0204AC18(h2, func_02027614(), 0, 0x120, 0, 3, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1A0 = func_0204A6C8(h2, func_02027618(), 0, 0, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1BC = func_0204AF28(h2, func_0202761C(2), func_02027620(2), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f180 = func_0204AC18(h2, func_02027694(), 0, 0x60, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1A4 = func_0204A6C8(h2, func_02027698(), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1C0 = func_0204AF28(h2, func_0202769C(2), func_020276A0(2), ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f188 = func_0204AC18(h2, func_020276B4(), 0, 0x80, 0, 1, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1AC = func_0204A6C8(h2, func_020276B8(), 0, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1C8 = func_0204AF28(h2, func_020276BC(2), func_020276C0(2), ((struct Obj00047 *)p)->f0);
    func_02049238(h2);
    func_02082A60((void *)0x050000C0, p + 0x40, 0x60);
}


void func_021B7624(char *p)
{
    u8 i;

    func_020307B0(((struct Obj20856 *)p)->f158);
    for (i = 0; i < 8; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204ADA4(*(int *)(p + i * 4 + 0x178));
    }
    for (i = 8; i < 15; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204A8D4(*(int *)(p + i * 4 + 0x178));
    }
    for (i = 15; i < 23; i++) {
        if (*(int *)(p + i * 4 + 0x178) != -1)
            func_0204AFD8(*(int *)(p + i * 4 + 0x178));
    }
}

#define W(k) (*(u32 *)(p+(k)))

/*
 * lever: one named offset shared across the case 7/8 branch join.
 */
void func_021B7698(u8 *p)
{
    u32 old;
    int r,id,off;
    switch (T(0x34)) {
    case 1:
        W(0x108)=func_021BBDEC((int)p,W(0x154),0,0x16,0x15,0);
        func_021B7B98(p); p[0xd]=2; return;
    case 22: case 23:
        W(0x108)=func_021BBDEC((int)p,W(0x154),0,0xc,0x15,0);
        W(0x10c)=func_021BBDEC((int)p,W(0x154),1,0x16,0x15,1);
        func_021B7B98(p); p[0xd]=2; return;
    case 0: case 6: case 9: case 14: case 16: case 18: case 21: case 25:
        func_021B7B98(p); p[0xd]=2; return;
    case 3:
        W(0x14)=0; func_021B7B98(p); p[0xd]=2; return;
    case 5:
        if (func_021BC1B4((short unsigned int *)p,(void *)H(0x44))==1) {
            r=func_021BC1D0(p);
            if (r != -1) {
                W(0x2c)=r; W(0x38)=(u32)func_0201AB28((void *)T(0),r);
                func_021BC350(p,0);
                func_021BE2B4((void *)W(0x38),H(0x44),(int)0,H(0x30),(u16)(((struct Obj00009 *)p)->f0));
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                W(0x24)=1; p[0xd]=p[0xc]; p[0xc]=0;
                func_021BA670(p,H(0x44)); return;
            }
            func_021BC2C8((int)p); p[0xd]=p[0xc]; p[0xc]=0; return;
        }
        if (func_021BA65C(p,H(0x44)) != 0) {
            func_021B7B98(p); p[0xd]=2; return;
        }
        T(0x40)=10;
        func_021BB7A4(p,(u32 *)W(0x150)); func_021BB97C((u16 *)p,W(0x150));
        func_021BB9AC((int)p,(u32)W(0x150),(u32)0,(u16)H(0x44));
        func_021B9788(p,0xb3,1,(int)func_021B9E3C);
        func_021BB98C(p,W(0x150)); p[0xd]=p[0xc]; p[0xc]=0; return;
    case 7: case 8:
        W(0x2c)=T(0x3c); W(0x38)=(u32)func_0201AB28((void *)T(0),T(0x3c));
        if (S[0x48] < 4) {
            old=func_02017E1C((void *)W(0x38),S[0x48]+0x36,0);
            off=0x150;
            func_021BB97C((u16 *)p,W(off)); func_021BB99C((int)p,W(off),0,W(0x38));
            func_021BB9CC((int)p,(u32)W(off),(u32)1,(u16)old);
            func_021B9788(p,0x28,1,(int)func_021BA004);
        } else {
            off=0x150;
            func_021BB97C((u16 *)p,W(off)); func_021BB9CC((int)p,(u32)W(off),(u32)1,(u16)H(0x46));
            func_021B9788(p,0x23,0,(int)func_021B9F34);
        }
        func_021BB98C(p,W(off));
        p[0xd]=7; p[0xc]=0; W(0x14)=0;
        func_021BAFA0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),1); return;
    case 10:
        W(0x2c)=T(0x3c); W(0x38)=(u32)func_0201AB28((void *)T(0),T(0x3c));
        if (H(0x44) == 0) {
            T(0x34)=0; func_021B7B98(p); p[0xd]=2;
        } else {
            old=func_02017E1C((void *)W(0x38),6,0);
            if (old == 0) {
                func_021BA624(p,(void *)W(0x38),H(0x44));
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
                func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)H(0x44));
                func_021BC24C(p,(void *)W(0x38),(u16)H(0x44));
                func_021BC288((int)p,(int)((void *)W(0x38)),H(0x44));
                if (func_021BDBF8(p,W(0x38))==1) {
                    func_021BDC3C((u32)p,(void *)W(0x38)); func_021B9788(p,0x56,1,(int)func_021BA4E4); W(0x264)=1;
                } else func_021B9788(p,0x56,1,(int)func_021B9E20);
                func_021BB98C(p,W(0x150)); T(0x34)=0;
            } else {
                func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
                func_021BB9BC((int)p,W(0x150),1,(u16)old);
                func_021B9788(p,0x3a,0,(int)func_021BA098); func_021BB98C(p,W(0x150));
            }
        }
        p[0xd]=7; p[0xc]=0; W(0x14)=1;
        func_021BAFA0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),1); return;
    case 11: case 12:
        W(0x2c)=T(0x3c); W(0x38)=(u32)func_0201AB28((void *)T(0),T(0x3c));
        old=func_02017E1C((void *)W(0x38),6,0);
        func_021BB97C((u16 *)p,W(0x150));
        if (old == 0) {
            id=0x56;
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)H(0x44));
        } else {
            id=0x40;
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,(u32)W(0x150),(u32)1,(u16)old);
            func_021BB9AC((int)p,(u32)W(0x150),(u32)2,(u16)H(0x44));
        }
        func_021BA624(p,(void *)W(0x38),H(0x44));
        func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
        func_021BC24C(p,(void *)W(0x38),(u16)H(0x44));
        func_021BC288((int)p,(int)((void *)W(0x38)),H(0x44));
        if (func_021BDC5C(p,W(0x38))==1) {
            func_021BDCA0((u32)p,(void *)W(0x38)); func_021B9788(p,id,1,(int)func_021BA4E4); W(0x264)=2;
        } else if (T(0x34)==11) func_021B9788(p,id,1,(int)func_021B9E3C);
        else func_021B9788(p,id,1,(int)func_021B9E20);
        func_021BB98C(p,W(0x150));
        if (T(0x34)==11) T(0x40)=10; else T(0x34)=0;
        p[0xd]=7; p[0xc]=0; W(0x14)=1;
        break;
    }
}


/*
 * EXACT*: the listing extent's last two bytes (0x021B7CC2) are alignment
 * padding before the next function, not a follower.
 */
void func_021B7B98(u8 *p)
{
    func_020409B4(0);
    switch (((struct Obj20857 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34) {
    case 0:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 9);
        ((struct Obj00009 *)p)->f14 = 1;
        break;
    case 1:
        func_021BD4EC((char *)p);
        func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1E0, 0);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 22:
    case 23:
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 5:
    case 16:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xd);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 9:
    case 14:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xc);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 6:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xe);
        ((struct Obj00009 *)p)->f14 = 0;
        ((struct Obj00009 *)p)->f28 = 0;
        break;
    case 18:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0x10);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 3:
    case 25:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 9);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    case 21:
        func_021BB714(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0);
        func_021BB7E8(p, *(u32 * *)&((struct Obj00009 *)p)->f150, 0xa3);
        func_0204B3DC((struct Obj *)((struct Obj00009 *)p)->f1E0, 0);
        ((struct Obj00009 *)p)->f14 = 0;
        break;
    }
    func_021B8418(p);
}

#undef W
#define W(k) (*(u32 *)(p+(k)))

void func_021B7CC4(u8 *p)
{
    u32 old,buf;
    int r;
    if (S[0x63] == 1) { p[0xc]=0x13; return; }
    switch (T(0x34)) {
    case 0: case 1: case 18: case 21: case 22: case 23: case 25:
        func_021B907C(p); func_020409B4(0); func_021B8180(p); return;
    case 5:
        if (func_021BC17C((short unsigned int *)p,H(0x44)) == 1) {
            func_021B907C(p); func_021B8180(p); return;
        }
        if (func_021BDD78((void *)W(0x38),(u16)H(0x44),0,(u16)(((struct Obj00009 *)p)->f0)) == 1) {
            r=func_021BC350(p,0);
            func_021BE2B4((void *)W(0x38),H(0x44),(int)0,H(0x30),(u16)(((struct Obj00009 *)p)->f0));
            if (r == 2) func_021BB200(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
            else if (r == 19 || r == 13) {
                func_021BB200(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)),(u32)W(0x38),0);
                func_020061E4(0x56f);
            } else {
                func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
                func_020061E4(0x56f);
            }
            func_021BA670(p,H(0x44)); return;
        }
        if (H(0x44)==0x1d2 && func_021BDCC0((char *)p,W(0x38))==1) {
            func_021BDD58((u32)p,(void *)W(0x38)); T(0x40)=10; p[0xc]=14; W(0x264)=3; return;
        }
        func_021BC30C((int)p); return;
    case 16:
        if (func_021B9BF4(p,(void *)W(0x38),H(0x44)) != 0) {
            func_021BA670(p,H(0x44)); p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=8;
        } else func_021B9788(p,0x51,1,(int)func_021B9E3C);
        return;
    case 9:
        old=func_02017E1C((void *)W(0x38),6,0);
        if (old == 0) {
            if (func_0202136C(H(0x44)) == 1) {
                p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=6; return;
            }
            T(0x40)=10;
            func_021BA624(p,(void *)W(0x38),H(0x44));
            func_021BB2C0(p,(u8 *)(*(u32 *)((p+W(0x2c)*4)+0x160)));
            func_021BB97C((u16 *)p,W(0x150));
            func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9AC((int)p,W(0x150),1,H(0x44));
            func_021BC24C(p,(void *)W(0x38),(u16)H(0x44));
            func_021BC288((int)p,(int)((void *)W(0x38)),H(0x44));
            if (func_021BDBF8(p,W(0x38)) == 1) {
                func_021BDC3C((u32)p,(void *)W(0x38));
                func_021B9788(p,0x56,1,(int)func_021BA4E4); W(0x264)=1;
            } else func_021B9788(p,0x56,1,(int)func_021B9E3C);
            func_021BB98C(p,W(0x150)); return;
        }
        if (func_0202136C(old)==1) {
            T(0x40)=10; func_021B9788(p,0x39,1,(int)func_021B9E3C); return;
        }
        func_021BB97C((u16 *)p,W(0x150));
        func_021BB99C((int)p,W(0x150),0,W(0x38));
        func_021BB9BC((int)p,W(0x150),1,(u16)old);
        func_021B9788(p,0x3a,0,(int)func_021BA098);
        func_021BB98C(p,W(0x150)); return;
    case 14:
        if (func_02017E1C((void *)W(0x38),6,0) == 0) {
            buf=(u32)func_02009050((void *)T(8),0,H(0x5c),((struct Obj00009 *)p)->f0);
            func_02017E40((void *)W(0x38),0xa7,buf); func_020307B0((void *)buf);
            func_02017E40((void *)W(0x38),6,H(0x44));
            func_0200902C((void *)T(8),0,H(0x5c));
            func_021B9788(p,0x62,1,(int)func_021B9E3C);
        } else func_021B9788(p,0x63,1,(int)func_021B9E3C);
        return;
    case 6:
        switch ((u32)func_021B9AC8(p,(void *)W(0x38),T(0x3c))) {
        case 0:
            T(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x29,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150));
            func_021BA5B4(p,(void *)W(0x38)); func_021BA60C(p,(void *)W(0x38)); return;
        case 1:
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x20,0,(int)func_021B9EB0); func_021BB98C(p,W(0x150)); return;
        case 2:
            T(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x2a,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150)); return;
        case 3:
            T(0x40)=10;
            func_021BB97C((u16 *)p,W(0x150)); func_021BB99C((int)p,W(0x150),0,W(0x38));
            func_021BB9CC((int)p,W(0x150),1,H(0x46));
            func_021B9788(p,0x2b,1,(int)func_021B9E3C); func_021BB98C(p,W(0x150)); return;
        }
        return;
    case 3:
        p[0xc]=19; T(0x3c)=W(0x2c); T(0x40)=0; return;
    default:
        func_021B907C(p); func_021B8180(p); return;
    }
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


/*
 * EXACT*: the extent's last two bytes (0x021B83D6) are alignment padding.
 * func_021BBAF8 is declared with a third argument: this caller loads
 * `add r2, sp, #0` (the 32-byte buf) before the bl.  The switch value is
 * signed (bgt/blt compare tree).
 */
void func_021B8180(u8 *p)
{
    int buf[8];

    func_020409B4(0);
    switch (((struct Obj20858 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34) {
    case 0:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[1] = 3;
            buf[2] = 6;
            buf[0] = 0;
            buf[3] = 0x10;
        } else {
            buf[1] = 1;
            buf[2] = 3;
            buf[3] = 4;
            buf[0] = 0;
            buf[4] = 6;
            buf[5] = 0x10;
            if (func_0202136C(func_02017E1C((void *)W(0x38), 6, 0)) == 1) {
                buf[3] = 5;
            }
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 1:
    case 22:
    case 23:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        } else {
            buf[0] = 8;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 5:
        buf[0] = 2;
        buf[1] = 6;
        buf[2] = 0x10;
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), func_021BC228((int)p, ((struct Obj20859 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f44));
        func_021BB98C(p, W(0x150));
        break;
    case 18:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[1] = 6;
            buf[0] = 0;
            buf[2] = 0x10;
        } else {
            buf[0] = 7;
            buf[2] = 6;
            buf[1] = 0;
            buf[3] = 0x10;
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    case 21:
        if (func_021BB468((int)p, (int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160))) == 1) {
            buf[0] = 0xb;
            buf[2] = 6;
            buf[3] = 0x10;
            buf[1] = 0;
            func_021BB714(p, (u32 *)W(0x150), 2);
            func_021BB7E8(p, (u32 *)W(0x150), 0xa2);
        } else {
            buf[1] = 6;
            buf[2] = 0x10;
            buf[0] = 0;
            func_021BB97C((u16 *)p, W(0x150));
            func_021BB99C((int)p, W(0x150), 0, W(0x38));
            func_021BB714(p, (u32 *)W(0x150), 2);
            func_021BB7E8(p, (u32 *)W(0x150), 0x12);
            func_021BB98C(p, W(0x150));
        }
        break;
    case 25:
        if (func_021F6744((void *)W(0x38)) == 1) {
            buf[0] = 0xb;
            buf[1] = 0;
            buf[2] = 6;
            buf[3] = 0x10;
        } else {
            buf[0] = 0;
            buf[1] = 6;
            buf[2] = 0x10;
        }
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB99C((int)p, W(0x150), 0, W(0x38));
        func_021BB714(p, (u32 *)W(0x150), 2);
        func_021BB7E8(p, (u32 *)W(0x150), 0x12);
        func_021BB98C(p, W(0x150));
        break;
    default:
        buf[0] = 0;
        buf[1] = 6;
        buf[2] = 0x10;
        break;
    }
    func_021BBAF8(p, (u8 *)W(0x154), buf);
}


void func_021B83D8(u8 *p)
{
    switch (p[0xe]) {
    case 0:
        p[0xe] = 1;
        p[0xf] = 4;
        break;
    case 1:
        func_021B8A8C(p);
        break;
    case 2:
        if (p[0xc] == 3) {
            func_021B86D8(p);
        } else if (p[0xc] == 4) {
            func_021B8758(p);
        } else {
            func_021B8508(p);
        }
        break;
    }
}

#undef W

#define W(o) (*(int *)(p + (o)))


/*
 * The extent's last two bytes are alignment padding (00 00), not a follower.
 */
void func_021B8418(u8 *p)
{
    W(0x2c) = *(int *)(W(0x280) + 0x3c);
    p[0xe] = 0;
    W(0x3c) = 0x17;
    if (func_021B9A84((u32)p) == 1) {
        func_021BBE5C(W(0x108), 0);
        func_021BBE5C(W(0x10c), 0);
    }
    if (W(8) == 0) {
        if (W(0x2c) <= 5) {
            func_021B8F68(p, W(0x2c));
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
        } else {
            func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
        }
    } else {
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        if (W(0x2c) <= 5) {
            if (p[0xc] == 3) {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            }
        } else {
            func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 0);
        }
    }
    func_0204B3DC((struct Obj *)W(0x1e4), W(0x14));
    if (func_021B9A84((u32)p) == 1 || func_021B9AB4(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
}

#undef W

#define W(o) (*(int *)(p + (o)))


/*
 * Case bodies are laid out 3, 0, 1, 2: case 3 is written first.
 */
void func_021B8508(u8 *p)
{
    u8 i;
    u8 k;
    int n;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (func_021B9A84((u32)p) == 1) {
        func_02041300(0, 0, 0, 0x15, 0x20, 3, 0x10);
        for (i = 0; i < 6; i++) {
            ((u8 *)W(0x280))[i + 0x49] = 0;
        }
        for (k = 0; k < 6; k++) {
            n = func_021BB43C((int *)(*(int *)(p + k * 4 + 0x160)));
            if (n <= 5) {
                ((u8 *)W(0x280))[n + 0x49] = k + 1;
            }
        }
    }
    switch (p[0xf]) {
    case 3:
        func_0204B3DC((struct Obj *)W(0x1d8), 0);
        W(0x38) = (int)func_0201AB28(*(void **)W(0x280), W(0x2c));
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        func_020061E4(0x54c);
        func_021B7CC4(p);
        return;
    case 0:
        if (func_021B9A84((u32)p) == 1) {
            func_021B892C(p);
            return;
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 6;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x54c);
        return;
    case 1:
        if (W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        if (func_021B9A84((u32)p) == 1) {
            func_021BBE5C(W(0x108), 0);
            func_021BBE68(W(0x10c), 1);
            p[0xc] = 0xc;
            W(0x2c) = 7;
        } else {
            p[0xc] = 0x13;
            W(0x1e8) = W(0x1e0);
            func_0204B878((struct Obj *)W(0x1e8), 9);
        }
        *(int *)(W(0x280) + 0x3c) = 7;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x551);
        return;
    case 2:
        if (W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        p[0xc] = 0x13;
        *(int *)(W(0x280) + 0x3c) = 8;
        *(int *)(W(0x280) + 0x40) = 0;
        func_020061E4(0x556);
        W(0x1e8) = W(0x1e4);
        func_0204B878((struct Obj *)W(0x1e8), 8);
        return;
    }
}

#undef W

#define W(o) (*(int *)(p + (o)))


void func_021B86D8(u8 *p)
{
    func_021BB7A4(p, (u32 *)W(0x150));
    if (p[0xf] == 3 && W(0x2c) == W(0x30)) {
        p[0xf] = 1;
    }
    if (p[0xf] != 1) {
        if (p[0xf] == 3) {
            func_021B9968(p);
        }
    } else {
        W(0x38) = 0;
        p[0xc] = 2;
        func_021B8F68(p, W(0x2c));
        func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x30) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        W(0x30) = 9;
        *(int *)(W(0x280) + 0x3c) = W(0x2c);
        func_021B7B98(p);
        func_020061E4(0x551);
    }
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


void func_021B8758(u8 *p)
{
    u32 a, b;
    void *o;
    u32 c, d, e;

    func_021BB7A4(p, (u32 *)W(0x150));
    if (p[0xf] == 3) {
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        a = func_02017E1C((void *)W(0x38), 0xa0, 0);
        b = func_02017E1C((void *)W(0x38), 0xa1, 0);
        if (W(0x2c) == W(0x34) || a == 0 || b == a) {
            func_021B9788(p, 0x64, 1, (int)func_021B9E20);
            func_021B8F68(p, W(0x2c));
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1dc), 0);
            ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
            return;
        }
        func_021BB2C0(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x38) = (u32)func_0201AB28((void *)*(u32 *)W(0x280), W(0x2c));
        p[0xc] = 10;
        ((struct Obj00009 *)p)->f11C = func_021BB464((int)p, (short unsigned int *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        W(0x120) = (u32)func_021BA288;
        func_021B8F68(p, W(0x2c));
        func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
        func_0204B3DC((struct Obj *)W(0x1dc), 0);
        o = func_0201AB28((void *)*(u32 *)W(0x280), W(0x34));
        c = func_02017E1C(o, 0xa1, 0);
        d = func_02017E1C(o, 0xa0, 0);
        e = c / 5;
        if (a + e > b) {
            func_02017E40(o, 0xa0, d - (b - a));
        } else {
            func_02017E40(o, 0xa0, d - e);
        }
        ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
        W(0x2c) = W(0x34);
        func_021BB2C0(p, (u8 *)(*(u32 *)(p + W(0x2c) * 4 + 0x160)));
        func_020061E4(0x56f);
        return;
    }
    W(0x38) = 0;
    p[0xc] = 2;
    func_021B8F68(p, W(0x2c));
    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x34) * 4 + 0x160)), 0);
    func_0204B3DC((struct Obj *)W(0x1dc), 0);
    W(0x34) = 9;
    ((u32 *)W(0x280))[0x3c / 4] = W(0x2c);
    func_021B7B98(p);
    func_020061E4(0x551);
}

#undef W

#define W(o) (*(u32 *)(p + (o)))


/*
 * The six-byte buffer is a block-scope initialised array
 * (an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six assignments sink `add r7, sp, #4` below the stores.
 */
void func_021B892C(u8 *p)
{
    u8 *q;
    u8 i;
    int n;
    int r;

    q = (u8 *)((u32 *)W(0x280))[0x14 / 4];
    if (W(0x2c) != 6) {
        if ((int)W(0x2c) <= 5) {
            func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 0);
            func_0204B3DC((struct Obj *)W(0x1d8), 0);
        }
        W(0x2c) = 6;
    }
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};
        for (i = 0; i < 6; i++) {
            n = func_021BB43C((int *)(*(int *)(p + i * 4 + 0x160)));
            if (n <= 5) {
                buf[n] = i + 1;
            }
        }
        r = func_02019E54((u32)q, *(u32 *)W(0x280), (u32)buf);
    }
    if (q[2] > p[0x105]) {
        func_021B9788(p, q[2] + 0x56, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (q[3] < p[0x105]) {
        func_021B9788(p, q[3] + 0x5c, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    if (r == 1) {
        func_021BB97C((u16 *)p, W(0x150));
        func_021BB9EC((int)p, W(0x150), 0, ((struct Obj06210 *)q)->f6, 3);
        func_021B9788(p, 0x92, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        func_021BB98C(p, W(0x150));
        return;
    }
    if (r == 7) {
        func_021B9788(p, 0x94, 1, (int)func_021B9E20);
        func_020061E4(0x557);
        return;
    }
    func_021BBE5C(W(0x10c), 0);
    func_021BBE68(W(0x108), 1);
    p[0xc] = 0xc;
    ((u32 *)W(0x280))[0x3c / 4] = 6;
    ((u32 *)W(0x280))[0x40 / 4] = 0;
    W(0x118) = 1;
    func_020061E4(0x54c);
}

void func_021B8A8C(unsigned char *p) { func_021B8AC4(p); if(p[15]==4) func_021B8DB4(p); if(p[15]!=4) p[14]=2; if(*(unsigned char *)(*(unsigned *)&((struct Obj00009 *)p)->f280+99)==1) { p[14]=2; p[15]=1; } }

#undef W

#define W(o) (*(int *)(p + (o)))


/*
 * The two byte tables resolve as sole-ref only without an overlay token
 * (with `ov091` the hint is reported contested).  The spilled locals sit
 * up @0, done @4, old @8, trg @0xc: declared trg, old, done, up.
 */
void func_021B8AC4(u8 *p)
{
    u32 trg;
    int old;
    int done;
    u32 up;
    u32 rep;
    int dir;
    int max;
    u8 cnt;
    int n;

    trg = func_020362DC();
    rep = func_0203633C();
    if (W(8) == 1 && func_0204B3F4((struct Obj *)W(0x1d8)) == 0) {
        if (trg != 0 && (trg & 0x402) == 0) {
            if (W(0x2c) <= 5) {
                func_021B8F68(p, W(0x2c));
                func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
            } else {
                func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                func_0204B3DC((struct Obj *)W(0x1d8), 0);
            }
            func_020061E4(0x548);
            W(8) = 0;
        }
    } else {
        dir = 0;
        if (trg != 0) {
            W(8) = 0;
        }
        up = rep & 0x40;
        if (up) {
            dir = -2;
        } else if (rep & 0x80) {
            dir = 2;
        } else if (rep & 0x20) {
            dir = -1;
        } else if (rep & 0x10) {
            dir = 1;
        } else if (trg & 1) {
            if (W(0x2c) == 6) {
                p[0xf] = 0;
            } else if (W(0x2c) == 7) {
                p[0xf] = 1;
            } else if (W(0x28) == 0 && func_021BB468((int)p, (int *)(*(int *)(p + W(0x2c) * 4 + 0x160))) == 1) {
                func_020061E4(0x557);
            } else {
                p[0xf] = 3;
            }
        }
        if (dir != 0) {
            old = W(0x2c);
            done = 0;
            if (func_021B9A84((u32)p) == 1) {
                if (func_021B9AA0((u32)p) == 1) {
                    max = 7;
                } else {
                    max = 6;
                }
            } else {
                max = 5;
            }
            if ((u32)(W(0x2c) - 6) <= 1 && (rep & 0xc0)) {
                cnt = func_0201AA18((void *)*(int *)W(0x280));
                if (up) {
                    if (W(0x2c) == 7 || func_021B9AA0((u32)p) == 0) {
                        W(0x2c) = d_021BEAB0[cnt - 1];
                    } else {
                        W(0x2c) = d_021BEAAA[cnt - 1];
                    }
                } else {
                    if (W(0x2c) == 7 || func_021B9AA0((u32)p) == 0) {
                        if (cnt > 1) {
                            W(0x2c) = 1;
                        } else {
                            W(0x2c) = 0;
                        }
                    } else {
                        W(0x2c) = 0;
                    }
                }
            } else {
                do {
                    n = W(0x2c) + dir;
                    if (n > max) {
                        if (max == 6 && dir > 1 && old != 6) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = n - (max + 1);
                        }
                    } else if (n < 0) {
                        if (max == 6 && dir < 1) {
                            W(0x2c) = max;
                        } else {
                            W(0x2c) = dir + (W(0x2c) + (max + 1));
                        }
                    } else {
                        W(0x2c) += dir;
                    }
                    if (W(0x2c) > 5 || func_021BB3C4(p, *(int *)(p + W(0x2c) * 4 + 0x160)) == 1) {
                        done = 1;
                    }
                } while (done == 0);
            }
            if (old != W(0x2c)) {
                if (W(0x2c) <= 5) {
                    func_021B8F68(p, W(0x2c));
                    func_021BAFA0(p, (u8 *)(*(int *)(p + W(0x2c) * 4 + 0x160)), 1);
                } else {
                    func_021BBE5C(*(int *)(p + (u8)(W(0x2c) - 6) * 4 + 0x108), 1);
                    func_0204B3DC((struct Obj *)W(0x1d8), 0);
                }
                if (old <= 5) {
                    func_021BAFA0(p, (u8 *)(*(int *)(p + old * 4 + 0x160)), 0);
                } else {
                    func_021BBE5C(*(int *)(p + (u8)(old - 6) * 4 + 0x108), 0);
                }
                p[0x100] = 0xc;
            }
            func_020061E4(0x548);
        }
    }
    if (trg & 2) {
        if (func_021B9A84((u32)p) == 0 || func_021B9AA0((u32)p) == 1) {
            if (func_021B9AB4(p) == 1) {
                p[0xf] = 1;
                W(0x1e8) = W(0x1e0);
                func_0204B878((struct Obj *)W(0x1e8), 9);
                W(8) = 0;
            }
        }
    } else if ((trg & 0x400) && W(0x14) == 1) {
        p[0xf] = 2;
        W(0x1e8) = W(0x1e4);
        func_0204B878((struct Obj *)W(0x1e8), 8);
        W(8) = 0;
    }
}
