/*
 * file:     compatible_irc_sys_p02.c
 * unit:     yes
 * function: func_021B652C, func_021B6540, func_021B6554, func_021B6568, func_021B657C, func_021B658C, func_021B6634, func_021B6670, func_021B667C
 * address:  0x021B652C
 * region:   ov101
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B67B0 0x021B67B0 thumb ov101
 *   func_021B67C4 0x021B67C4 thumb ov101
 *   func_021B67E4 0x021B67E4 thumb ov101
 *   func_021B67F8 0x021B67F8 thumb ov101
 *   func_021B685C 0x021B685C thumb ov101
 *   func_02087C88 0x02087C88 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008494 0x02008494 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0203F4E4 0x0203F4E4 arm
 *   func_02080D24 0x02080D24 arm
 *   func_0203D378 0x0203D378 arm
 *   func_02082D44 0x02082D44 arm
 */
#include "../../matched/include/Obj22096.h"
#include "../../matched/include/Obj22097.h"

struct OSOwnerInfo;
struct RtcDate;
struct BigObj;
struct Ctx;
typedef unsigned int u32;

typedef struct R { int words[11]; } R;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Data { u32 f00; u8 f04,f05; u16 f06; u8 f08,f09,f0a; unsigned char low:4; unsigned char high:4; u8 tail[32]; } Data;

typedef struct Config { u8 bytes[0x54]; } Config;

typedef struct Four { int a,b,c,d; } Four;

extern int func_021B67B0(int *p);
extern int func_021B67C4(int *p);
extern int func_021B67E4(int *);
extern int func_021B67F8(int *,int);
extern void func_021B685C(int *,R *);
extern void func_02087C88(struct OSOwnerInfo *info);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *,void *);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_0203F4E4(struct RtcDate *date);
extern u32 func_02080D24(u32);
extern u32 func_0203D378(void);
extern void func_02082D44(void *,const void *,unsigned);
int func_021B652C(u32 p);
int func_021B6540(u32 p);
int func_021B6554(int *p);
int func_021B6568(int *p,int resource);
void func_021B657C(int *p,R *out);
void func_021B658C(void *p,Data *out);
void func_021B6634(u32 *p, int i);
int func_021B6650(void);
int func_021B6658(void);
int func_021B665C(int a, int b);
void func_021B6668(int *p);
void func_021B6670(void);
void func_021B6674(int *p);
void func_021B667C(unsigned a,int b,void *c,unsigned char *d);

int func_021B652C(u32 p) {
    if(((struct Obj22096 *)p)->f78!=0) return 1;
    return func_021B67B0((int *)(p+4));
}

int func_021B6540(u32 p) {
    if(((struct Obj22097 *)p)->f78!=0) return 1;
    return func_021B67C4((int *)(p+4));
}

int func_021B6554(int *p) { if(p[30]) return 1; return func_021B67E4(p+1); }

int func_021B6568(int *p,int resource) { if(p[30]) return 1; return func_021B67F8(p+1,resource); }

void func_021B657C(int *p,R *out) { if(!p[30]) func_021B685C(p+1,out); }

/*
 * lever: pack the words with unsigned left/right shift pairs; u8 casts
 *   keep separate truncation shifts and add eight bytes.
 */
void func_021B658C(void *p,Data *out)
{
    Config config;
    Four four;
    void *sub;
    void *record;
    int flag;
    func_02087C88((struct OSOwnerInfo *)(&config));
    sub=func_020120F4(p);
    p=func_02012944(sub);
    out->f04=config.bytes[2];
    out->f05=config.bytes[3];
    func_02008494(p,out->tail);
    record=func_0201AB28(func_02012934(sub),0);
    flag=0;
    out->f06=func_02017E1C(record,5,0);
    out->f08=func_02017E1C(record,111,0);
    out->f09=func_02017E1C(record,110,0);
    out->f0a=func_02017E1C(record,76,0);
    func_0203F4E4((struct RtcDate *)(&four));
    if(four.c == 14) flag=1;
    out->low=(u8)flag;
    out->f00=((u32)four.a << 24) | (((u32)four.b << 24) >> 8) | (((u32)four.c << 24) >> 16) | four.d;
}

void func_021B6634(u32 *p, int i)
{
    p[19] |= 1 << i;
    if (func_02080D24(p[19]) >= 2)
        p[20] = 1;
}

int func_021B6650(void) { return 0x021B7520; }

int func_021B6658(void) { return 4; }

int func_021B665C(int a, int b) { return a == b ? 1 : 0; }

void func_021B6668(int *p) { p[20] = 0; }

void func_021B6670(void) { }

void func_021B6674(int *p) { p[21] = 1; }

void func_021B667C(unsigned a,int b,void *c,unsigned char *d) { unsigned v; if(func_0203D378()) { func_02082D44(c,&v,4); *(unsigned *)(d+0x68+a*4)=v; } }
