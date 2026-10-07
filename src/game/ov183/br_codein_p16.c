/*
 * file:     br_codein_p16.c
 * unit:     yes
 * function: func_021DE7C0, func_021DE8FC, func_021DE940, func_021DE9A0, func_021DEA30, func_021DEADC, func_021DEB4C, func_021DECB0, func_021DED14, func_021DED64, func_021DEDB4
 * address:  0x021DE7C0
 * region:   ov183
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_020457B0 0x020457B0 arm
 *   func_02012944 0x02012944 thumb
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FC7C4 0x021FC7C4 thumb ov186
 *   func_02045808 0x02045808 arm
 *   d_021E351C 0x021E351C data a4
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_021FB494 0x021FB494 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   d_021E3534 0x021E3534 data a4
 *   func_021FD860 0x021FD860 thumb ov186
 *   func_020061E4 0x020061E4 thumb
 *   func_021F9B9C 0x021F9B9C thumb ov186
 *   func_0203159C 0x0203159C arm
 *   func_02025538 0x02025538 thumb
 *   func_0201C440 0x0201C440 thumb
 *   func_021FD760 0x021FD760 thumb ov186
 *   func_021FD6D8 0x021FD6D8 thumb ov186
 *   func_021FD73C 0x021FD73C thumb ov186
 *   func_021DF0DC 0x021DF0DC thumb ov183
 *   func_021DF388 0x021DF388 thumb ov183
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FD15C 0x021FD15C thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_021FF88C 0x021FF88C thumb ov186
 *   func_021F9C6C 0x021F9C6C thumb ov186
 *   func_021FD71C 0x021FD71C thumb ov186
 *   func_021FD72C 0x021FD72C thumb ov186
 *   func_021FD854 0x021FD854 thumb ov186
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021FC830 0x021FC830 thumb ov186
 *   func_021FD1BC 0x021FD1BC thumb ov186
 *   func_02034714 0x02034714 arm
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021DF1DC 0x021DF1DC thumb ov183
 *   d_021E3964 0x021E3964 data a1
 *   func_020409B4 0x020409B4 arm
 *   func_021FD744 0x021FD744 thumb ov186
 *   func_021FE784 0x021FE784 thumb ov186
 *   func_021FE7B0 0x021FE7B0 thumb ov186
 *   func_021DF3DC 0x021DF3DC thumb ov183
 *   func_02035D20 0x02035D20 arm
 *   func_021FB4B4 0x021FB4B4 thumb ov186
 *   func_021F9BA0 0x021F9BA0 thumb ov186
 *   func_021DF8F0 0x021DF8F0 thumb ov183
 *   func_021DF41C 0x021DF41C thumb ov183
 *   func_021F9BF4 0x021F9BF4 thumb ov186
 */
#include "../../matched/include/Obj08312.h"
#include "../../matched/include/Obj10744.h"
#include "../../matched/include/Obj10745.h"
#include "../../matched/include/Obj00785.h"
#include "../../matched/include/Obj02229.h"
#include "../../matched/include/Obj06605.h"
#include "../../matched/include/Obj24581.h"
#include "../../matched/include/Obj00923.h"
#include "../../matched/include/Obj24582.h"
#include "../../matched/include/Obj24583.h"
#include "../../matched/include/Obj24584.h"
#include "../../matched/include/Obj02521.h"
#include "../../matched/include/Obj24585.h"
#include "../../matched/include/Obj24586.h"
#include "../../matched/include/Obj00364.h"
#include "../../matched/include/Obj24587.h"
#include "../../matched/include/Obj24588.h"
#include "../../matched/include/Obj24589.h"
#include "../../matched/include/Obj24590.h"
#include "../../matched/include/Obj24591.h"
#include "../../matched/include/Obj24592.h"
#include "../../matched/include/Obj24593.h"
#include "../../matched/include/Obj24595.h"
#include "../../matched/include/Obj24596.h"
#include "../../matched/include/Obj24597.h"
#include "../../matched/include/Obj24598.h"
#include "../../matched/include/Obj02894.h"
#include "../../matched/include/Obj24599.h"
#include "../../matched/include/Obj24600.h"
#include "../../matched/include/Obj14430.h"
#include "../../matched/include/Obj24601.h"
#include "../../matched/include/Obj24602.h"
#include "../../matched/include/Obj14431.h"
#include "../../matched/include/Obj24603.h"
#include "../../matched/include/Obj24604.h"
#include "../../matched/include/Obj03880.h"
#include "../../matched/include/Obj24605.h"
#include "../../matched/include/Obj24606.h"
#include "../../matched/include/Obj24607.h"
#include "../../matched/include/Obj24608.h"
#include "../../matched/include/Obj24609.h"
#include "../../matched/include/Obj24610.h"

struct U16Vec;
struct WordSet;
struct MsgBank;
struct Obj24810;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Record {u8 a,b,c,d; u32 value;} Record;

typedef struct Config {u16 left,right,top;u8 flag,pad;} Config;

typedef struct Triple {u32 a,b,c;} Triple;

typedef struct Rect { u32 x0, y0, x1, y1; } Rect;

extern void func_021FBE54(char *,u32,u32);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern int func_021FC21C(char *);
extern void func_02082BCC(void *,int,int);
extern int func_021FC124(void *,int,Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern struct U16Vec *func_020457B0(u32,u32);
extern u8 *func_02012944(void *p);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
extern void func_02045CAC(struct MsgBank *,u32,void *);
extern void func_0201F02C(struct WordSet *,u32,void *);
extern void func_0201F250(struct WordSet *,void *,void *);
extern void func_021FC7C4(char *,void *,void *,u16);
extern void func_02045808(struct U16Vec *);
extern void func_021FC734(u8 *p);
extern void func_021FB494(char *p);
extern void func_021FC0C8(char *p, unsigned i);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FD860(int, int, int *);
extern void func_020061E4(u32 a);
extern unsigned func_021F9B9C(struct Obj24810 *p);
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *func_02025538(unsigned int a0, void *a1);
extern u32 func_0201C440(void *p);
extern char *func_021FD760(unsigned owner, char *resources, int index, int heap);
extern int *func_021FD6D8(int payload, int callback, u32 heap);
extern int *func_021FD73C(int *p, int v);
extern void func_021DF0DC(int *p, int *state, char *q);
extern void func_021DF388(char *p);
extern void func_021FD714(void *);
extern void func_021FD15C(void *, int);
extern void func_021FD820(char *r5);
extern void func_02025588(void *);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_020315D4(struct S020315D4 *p);
extern int func_021FF88C(char *p);
extern void func_021F9C6C(void *);
extern void func_021FD71C(u8 *p);
extern int func_021FD72C(int *p);
extern void func_021FD854(char *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern int func_021FC830(u8 *p);
extern void func_021FD1BC(void *);
extern void func_02034714(const char *,u32,const char *);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021DF1DC(char *,char *,char *,int,void *,void *,u16 *,u32);
extern void func_020409B4(u32 index);
extern int func_021FD744(int *a);
extern void func_021FE784(int a, int b, int c, int d);
extern int func_021FE7B0(int *);
extern void func_021DF3DC(char *, int);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int func_021FB4B4(unsigned int *obj, int x, int y);
extern void func_021F9BA0(unsigned *ctx);
extern int func_021DF8F0(int x, int y);
extern int func_021DF41C(char *p);
extern void func_021F9BF4(unsigned *, unsigned);
void func_021DE7C0(char *p,char *q);
void func_021DE8FC(char *p, char *q);
int func_021DE940(char *p, int x, int y);
int func_021DE9A0(void *a, int b, char *q);
int func_021DEA30(void *a, int b, char *q, char *p);
int func_021DEADC(int a, int b, int c, char *p);
void func_021DEB4C(int *task,int *state,char *p);
void func_021DECB0(void *a, int b, char *p);
void func_021DED14(int *a, int *state, char *p);
void func_021DED64(int *p, int *state, char *q);
void func_021DEDB4(int *task, int *state, char *p);
extern const Record d_021E351C[];
extern const Rect d_021E3534[];
extern const char d_021E3964[];

/*
 * lever: bank/words declaration order selects their original stack slots.
 * omits func_02045CAC from its function header. Existing C verified EXACT
 * (344 bytes, 12/12 relocations; ARM9-45CAC-one.log, terminal exit 0).
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char g_020A7E8C[];
 * extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void func_020307B0(void *p);
 * extern void func_020495F4(void *stream, u32 size, void *dest);
 * extern void func_0204960C(void *stream, u32 pos);
 * extern void func_0204581C(void *dest);
 * extern void func_02045A00(void *dest, const void *src, u16 len);
 * extern void func_02045E04(void *dest, u32 index);
 * extern u8 func_020461B8(const void *file);
 * extern void func_02046110(struct MsgBank *bank);
 * extern void func_02046180(struct MsgBank *bank);
 *
 * void func_02045CAC(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         func_0204581C(dest);
 *         return;
 *     }
 *
 *     func_02046180(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         func_0204960C(bank->stream, pos + (index * 8 + 4));
 *         func_020495F4(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, g_020A7E8C, 0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             func_020495F4(bank->stream, size, buf);
 *             func_02045A00(dest, buf, e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         func_02045A00(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     func_02045E04(dest, index);
 * }
 */
void func_021DE7C0(char *p,char *q)
{
    int font,words,bank,i;
    Config config;
    Triple triple;
    struct U16Vec *base,*text;
    void *value;
    const Record *rec;
    char *slot;
    func_021FBE54(*(char **)(q+8),6,*(u16 *)(p+0x6c));
    func_021FB964((void *)(*(int *)(q+8)),15,*(u16 *)(p+0x6c));
    font=func_021FC20C(*(char **)(q+8));
    bank=func_021FC214(*(char **)(q+8));
    words=func_021FC21C(*(char **)(q+8));
    func_02082BCC(&config,0,8);
    config.left=80; config.right=168; config.top=0; config.flag=1;
    func_021FC124(*(void **)(q+8),6,&triple);
    *(void **)(p+0xc)=func_021FB378(&config,4,96,1,*(int *)q,*(int *)p,font,bank,&triple,*(u16 *)(p+0x6c));
    base=func_020457B0(128,*(u16 *)(p+0x6c));
    text=func_020457B0(128,*(u16 *)(p+0x6c));
    value=func_02012944(*(void **)(q+0x10));
    for(i=0;i<3;i++) {
        rec=&d_021E351C[i];
        slot=p+i*4;
        *(void **)(slot+0x10)=func_021FC6A4(4,rec->a,rec->b,rec->c,rec->d,14,*(void **)(p+4),*(u16 *)(p+0x6c));
        if(i==0) {
            func_02045CAC((struct MsgBank *)bank,rec->value,base);
            func_0201F02C((struct WordSet *)words,0,value);
            func_0201F250((struct WordSet *)words,text,base);
        } else func_02045CAC((struct MsgBank *)bank,rec->value,text);
        func_021FC7C4(*(char **)(slot+0x10),text,(void *)font,0x3da0);
    }
    func_02045808(base);
    func_02045808(text);
}

void func_021DE8FC(char *p, char *q)
{
    int i;
    for (i = 0; i < 3; i++) {
        char *slot = p + i * 4;
        if (((struct Obj10745 *)slot)->f10) {
            func_021FC734(((struct Obj10745 *)slot)->f10);
            ((struct Obj10745 *)slot)->f10 = 0;
        }
    }
    if (((struct Obj10744 *)p)->fC) {
        func_021FB494(((struct Obj10744 *)p)->fC);
        ((struct Obj10744 *)p)->fC = 0;
    }
    func_021FC0C8((char *)(((struct Obj08312 *)q)->f8), 6);
    func_021FBDA4(((struct Obj08312 *)q)->f8, 15);
}

int func_021DE940(char *p, int x, int y)
{
    int skip = ((struct Obj00785 *)p)->f68;
    int i;
    for (i = 0; i < 4; i++) {
        if (i != skip && (u32)(x - d_021E3534[i].x0) <= d_021E3534[i].x1 - d_021E3534[i].x0 &&
            (u32)(y - d_021E3534[i].y0) <= d_021E3534[i].y1 - d_021E3534[i].y0) {
            int args[2];
            args[0] = x;
            args[1] = y;
            func_021FD860(*(int *)&((struct Obj00785 *)p)->f64, 1, args);
            func_020061E4(0x703);
            return i;
        }
    }
    return 0;
}

int func_021DE9A0(void *a, int b, char *q)
{
    char *p = func_0203159C(a, 0x10C, func_021F9B9C(((struct Obj06605 *)q)->f14));
    int i;
    func_02082BCC(p, 0, 0x10C);
    *(char * *)&((struct Obj02229 *)p)->f108 = q;
    ((struct Obj02229 *)p)->f18 = func_021F9B9C(((struct Obj06605 *)q)->f14);
    ((struct Obj02229 *)p)->f0 = func_02025538(((struct Obj02229 *)p)->f18, ((struct Obj06605 *)q)->fC);
    ((struct Obj02229 *)p)->f14 = (void *)func_0201C440((void *)(((struct Obj02229 *)p)->f18));
    for (i = 0; i < 2; i++)
        *(void **)(p + i * 4 + 0x1C) = func_021FD760((unsigned int)(((struct Obj06605 *)q)->fC), (char *)(((struct Obj06605 *)q)->f10), i, ((struct Obj02229 *)p)->f18);
    ((struct Obj02229 *)p)->f10 = func_021FD6D8((int)p, (int)func_021DF0DC, ((struct Obj02229 *)p)->f18);
    if (((struct Obj24581 *)(*(char * *)&((struct Obj02229 *)p)->f108))->f4 != 0)
        func_021FD73C(((struct Obj02229 *)p)->f10, (int)func_021DEB4C);
    else
        func_021FD73C(((struct Obj02229 *)p)->f10, (int)func_021DF0DC);
    return 1;
}

int func_021DEA30(void *a, int b, char *q, char *p)
{
    int i;
    if (((struct Obj00923 *)p)->f100 != 0) {
        func_021DF388(p + 0x28);
        ((struct Obj00923 *)p)->f100 = 0;
    }
    if (((struct Obj00923 *)p)->fC != 0) {
        func_021FC734(((struct Obj00923 *)p)->fC);
        ((struct Obj00923 *)p)->fC = 0;
    }
    if (((struct Obj00923 *)p)->f8 != 0) {
        func_021FC734(((struct Obj00923 *)p)->f8);
        ((struct Obj00923 *)p)->f8 = 0;
    }
    if (((struct Obj00923 *)p)->f4 != 0) {
        func_021FB494(((struct Obj00923 *)p)->f4);
        ((struct Obj00923 *)p)->f4 = 0;
    }
    if (((struct Obj00923 *)p)->f104 != 0) {
        func_021FC0C8(((struct Obj24583 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10, 6);
        func_021FBDA4((int)(((struct Obj24584 *)(*(char * *)&((struct Obj00923 *)p)->f108))->f10), 24);
        ((struct Obj00923 *)p)->f104 = 0;
    }
    func_021FD714(((struct Obj00923 *)p)->f10);
    if (((struct Obj00923 *)p)->f24 != 0) {
        func_021FD15C(((struct Obj00923 *)p)->f24, ((struct Obj24582 *)q)->f10);
        ((struct Obj00923 *)p)->f24 = 0;
    }
    for (i = 0; i < 2; i++) func_021FD820(*(void **)(p + 0x1C + i * 4));
    func_02025588(((struct Obj00923 *)p)->f0);
    func_0201C4C0(((struct Obj00923 *)p)->f14);
    func_020315D4(a);
    return 1;
}

/*
 * extent: two trailing zero bytes are alignment padding before the next labelled function.
 */
int func_021DEADC(int a, int b, int c, char *p)
{
    int i;
    if (func_021FF88C(((struct Obj24585 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f18) == 2) {
        func_021F9C6C(((struct Obj24586 *)(*(char * *)&((struct Obj02521 *)p)->f108))->f14);
        return 1;
    }
    func_021FD71C(((struct Obj02521 *)p)->f10);
    if (func_021FD72C(((struct Obj02521 *)p)->f10) != 0) return 1;
    for (i = 0; i < 2; i++) func_021FD854(*(void **)(p + 0x1C + i * 4));
    func_0201C4E4(((struct Obj02521 *)p)->f14);
    if (((struct Obj02521 *)p)->f8 != 0) func_021FC830(((struct Obj02521 *)p)->f8);
    if (((struct Obj02521 *)p)->fC != 0) func_021FC830(((struct Obj02521 *)p)->fC);
    if (((struct Obj02521 *)p)->f24 != 0) func_021FD1BC(((struct Obj02521 *)p)->f24);
    return 0;
}

void func_021DEB4C(int *task,int *state,char *p)
{
    int font,bank;
    Config config;
    Triple triple;
    font=func_021FC20C(*(char * *)&((struct Obj24587 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    bank=func_021FC214(*(char * *)&((struct Obj24588 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
    if(((struct Obj00364 *)p)->f24) {
        func_021FD15C(((struct Obj00364 *)p)->f24,((struct Obj24589 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10);
        ((struct Obj00364 *)p)->f24=0;
    }
    func_021FB964((void *)(((struct Obj24590 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10),24,((struct Obj00364 *)p)->f18);
    func_021FBE54(*(char * *)&((struct Obj24591 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f104=1;
    func_02082BCC(&config,0,8);
    config.left=80;config.right=168;config.top=0;config.flag=1;
    if(!func_021FC124(((struct Obj24592 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,6,&triple))
        func_02034714(d_021E3964,0,d_021E3964);
    ((struct Obj00364 *)p)->f4=func_021FB378(&config,4,96,1,((struct Obj24593 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f0,font,bank,&triple,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f8=func_021FC6A4(4,11,6,10,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    func_021FC754(*(char * *)&((struct Obj00364 *)p)->f8,(void *)bank,(void *)0x55,(void *)font,0x3da0);
    ((struct Obj00364 *)p)->fC=func_021FC6A4(1,3,3,26,4,14,((struct Obj00364 *)p)->f14,((struct Obj00364 *)p)->f18);
    func_021FC868(((struct Obj00364 *)p)->fC,0,1,0);
    func_021FC754(*(char * *)&((struct Obj00364 *)p)->fC,(void *)bank,(void *)(**(int * *)&((struct Obj00364 *)p)->f108+0x57),(void *)font,0x3da0);
    func_021DF1DC(p+0x28,*(char * *)&((struct Obj24595 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f1C,*(char * *)&((struct Obj24596 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f10,((struct Obj24597 *)(*(char * *)&((struct Obj00364 *)p)->f108))->fC,((struct Obj00364 *)p)->f1C,((struct Obj00364 *)p)->f20,*(u16 * *)&((struct Obj24598 *)(*(char * *)&((struct Obj00364 *)p)->f108))->f28,((struct Obj00364 *)p)->f18);
    ((struct Obj00364 *)p)->f100=1;
    func_021FD73C(task,(int)func_021DED14);
}

void func_021DECB0(void *a, int b, char *p)
{
    func_021DF388(p + 0x28);
    ((struct Obj02894 *)p)->f100 = 0;
    func_021FC734(((struct Obj02894 *)p)->fC);
    ((struct Obj02894 *)p)->fC = 0;
    func_021FC734(((struct Obj02894 *)p)->f8);
    ((struct Obj02894 *)p)->f8 = 0;
    func_020409B4(4);
    func_020409B4(1);
    func_021FB494(((struct Obj02894 *)p)->f4);
    ((struct Obj02894 *)p)->f4 = 0;
    func_021FC0C8(((struct Obj24599 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10, 6);
    func_021FBDA4((int)(((struct Obj24600 *)(*(char * *)&((struct Obj02894 *)p)->f108))->f10), 24);
    ((struct Obj02894 *)p)->f104 = 0;
    func_021FD744((int *)a);
}

void func_021DED14(int *a, int *state, char *p)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(((struct Obj24601 *)(*(char * *)&((struct Obj14430 *)p)->f108))->f8), 2, 3, 0);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int * *)&((struct Obj24602 *)(*(char * *)&((struct Obj14430 *)p)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(a, (int)func_021DEDB4);
        break;
    }
}

void func_021DED64(int *p, int *state, char *q)
{
    switch (*state) {
    case 0:
        func_021FE784((int)(*(int * *)&((struct Obj24603 *)(*(char * *)&((struct Obj14431 *)q)->f108))->f8), 2, 3, 1);
        *state = 1;
        break;
    case 1:
        if (func_021FE7B0(*(int * *)&((struct Obj24604 *)(*(char * *)&((struct Obj14431 *)q)->f108))->f8) != 0) *state = 2;
        break;
    case 2:
        func_021FD73C(p, (int)func_021DECB0);
        break;
    }
}

void func_021DEDB4(int *task, int *state, char *p)
{
    u32 x,y;
    func_021DF3DC(p+0x28,((struct Obj03880 *)p)->f18);
    if (func_02035D20(&x,&y)) {
        if (func_021FB4B4((unsigned int *)(((struct Obj03880 *)p)->f4),x,y)) {
            int args[2];
            args[0]=x; args[1]=y;
            func_021FD860(((struct Obj03880 *)p)->f20,1,args);
            func_021F9BA0(((struct Obj24605 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14);
            func_021FD73C(task,(int)func_021DED64);
        }
        if (func_021DF8F0(x,y)) {
            u32 selection;
            int args[2];
            selection=func_021DF41C(p+0x28);
            if (selection>=((struct Obj24607 *)(*(char * *)&((struct Obj24606 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f1718)
                func_02034714(d_021E3964,0,d_021E3964);
            ((struct Obj24609 *)(*(char * *)&((struct Obj24608 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f1C))->f171C=selection;
            func_021F9BF4(*(unsigned * *)&((struct Obj24610 *)(*(char * *)&((struct Obj03880 *)p)->f108))->f14,2);
            func_021FD73C(task,(int)func_021DED64);
            args[0]=x; args[1]=y;
            func_021FD860(((struct Obj03880 *)p)->f20,1,args);
        }
    }
}
