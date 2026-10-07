/*
 * file:     battle_championship_flow_p02.c
 * unit:     yes
 * function: func_0217B014, func_0217B064, func_0217B0C8, func_0217B1BC, func_0217B2E4, func_0217B344
 * address:  0x0217B014
 * region:   ov176
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_0217AFD0 0x0217AFD0 thumb ov176
 *   func_02034714 0x02034714 arm
 *   d_0217E5E0 0x0217E5E0 data a1
 *   func_02005E30 0x02005E30 thumb
 *   func_0217B00C 0x0217B00C thumb ov176
 *   func_02082BCC 0x02082BCC arm
 *   func_0217B35C 0x0217B35C thumb ov176
 *   func_0217B368 0x0217B368 thumb ov176
 *   func_0217B984 0x0217B984 thumb ov176
 *   func_0217BAF4 0x0217BAF4 thumb ov176
 *   func_0217BB3C 0x0217BB3C thumb ov176
 *   func_0217BA9C 0x0217BA9C thumb ov176
 *   func_02030734 0x02030734 arm
 *   func_02045B38 0x02045B38 arm
 *   d_0217E5E4 0x0217E5E4 data a1
 *   func_0217B380 0x0217B380 thumb ov176
 *   func_021E8A3C 0x021E8A3C thumb ov177
 *   func_021E8A78 0x021E8A78 thumb ov177
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../../matched/include/Obj24401.h"
#include "../../matched/include/Obj24402.h"
#include "../../matched/include/Obj10698.h"
#include "../../matched/include/Obj14356.h"

struct MsgBank;
struct Rec;
typedef signed int     s32;

typedef unsigned int   u32_0217B014;

typedef unsigned int   u32_0217B064;

typedef struct Data { unsigned words[8]; } Data;

typedef unsigned char u8;

typedef unsigned u32_0217B1BC;

typedef struct {u32_0217B1BC w[10];} Init;

typedef unsigned short u16;

typedef unsigned int   u32_0217B2E4;

typedef unsigned int u32_0217B344;

extern void func_0204E720(u32_0217B014 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_021E8AA0(int *p, int v);
extern void func_0217AFD0(void *,int,char *);
extern void func_02034714(const char *expr, u32_0217B014 line, const char *file);
extern void func_02005E30(u32_0217B064 a);
extern void func_0217B00C(void *);
extern void func_02082BCC(void *,int,unsigned);
extern void func_0217B35C(int *);
extern int func_0217B368(int *);
extern u8 *func_0217B984(Init *,u32_0217B1BC);
extern void func_0217BAF4(int *);
extern int func_0217BB3C(int *);
extern void func_0217BA9C(int *);
extern void *func_02030734(u32_0217B2E4 heapId, u32_0217B2E4 size, int clear, const char *site, u16 tag);
extern struct MsgBank *func_02045B38(u32_0217B2E4 resident, u32_0217B2E4 arcId, u32_0217B2E4 fileId, u32_0217B2E4 heapId);
extern void func_0217B380(int,int,int *);
extern int *func_021E8A3C(int a, int b, int c);
extern void func_021E8A78(void *);
extern u32_0217B344 func_02045C04(struct Rec *rec);
extern u32_0217B344 func_020307B0(void *p);
void func_0217B014(void *a,int *state,char *p);
void func_0217B064(void *a,int *state,char *p);
void func_0217B0C8(int *a,int *state,int *p);
void func_0217B1BC(int *a,int *state,int *p);
void *func_0217B2E4(const Data *src,unsigned heap);
void func_0217B344(int *p);
extern const char d_0217E5E0[];
extern const char d_0217E5E4[];

void func_0217B014(void *a,int *state,char *p)
{
    switch(*state){
    case 0: func_0204E720(3,16,0,0); *state=1; break;
    case 1: if(!func_0204E804()) *state=2; break;
    case 2: func_021E8AA0(a,(int)func_0217AFD0); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}

void func_0217B064(void *a,int *state,char *p)
{
    int mode;
    switch(*state){
    case 0:
        if(((struct Obj24402 *)(*(char * *)&((struct Obj24401 *)p)->f28))->f8==0){func_02005E30(6);mode=12;}else mode=3;
        func_0204E720(mode,0,16,0);
        *state=1;
        break;
    case 1: if(!func_0204E804()) *state=2; break;
    case 2: func_021E8AA0(a,(int)func_0217B00C); break;
    default: func_02034714(d_0217E5E0,0,d_0217E5E0); break;
    }
}

void func_0217B0C8(int *a,int *state,int *p)
{
    Data config;
    switch(*state) {
    case 0:
        func_02082BCC(&config,0,32);
        config.words[1]=p[2];
        config.words[2]=p[3];
        config.words[3]=p[4];
        config.words[4]=p[5];
        config.words[5]=p[8];
        config.words[6]=p[9];
        config.words[7]=*(unsigned *)p[10];
        if(p[12]!=0) {p[12]=0;config.words[0]=2;}
        else {
            switch(((int *)p[10])[1]) {
            case 0: config.words[0]=0;break;
            case 1: config.words[0]=1;break;
            }
        }
        p[11]=(int)func_0217B2E4(&config,78);
        (*state)++;
        break;
    case 1:
        func_0217B35C((int *)p[11]);
        switch(func_0217B368((int *)p[11])) {
        case 1: ((int *)p[10])[2]=0;*state=2;break;
        case 2: ((int *)p[10])[2]=1;*state=2;break;
        case 3: ((int *)p[10])[1]=3;*state=3;break;
        }
        break;
    case 2:
        func_0217B344((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B064);
        break;
    case 3:
        func_0217B344((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B1BC);
        break;
    }
}

void func_0217B1BC(int *a,int *state,int *p)
{
    Init config;
    switch(*state) {
    case 0:
        func_02082BCC(&config,0,40);
        config.w[1]=p[2];
        config.w[2]=p[3];
        config.w[3]=p[5];
        config.w[4]=p[8];
        config.w[5]=p[9];
        config.w[6]=((u32_0217B1BC *)p[10])[0];
        config.w[7]=((u32_0217B1BC *)p[10])[3];
        config.w[8]=((u32_0217B1BC *)p[10])[4];
        config.w[9]=((u32_0217B1BC *)p[10])[5];
        switch(((u32_0217B1BC *)p[10])[1]) {
        case 3: config.w[0]=0;break;
        case 4: config.w[0]=2;break;
        case 5: config.w[0]=3;break;
        case 6: config.w[0]=1;break;
        default: config.w[0]=0;break;
        }
        p[11]=(int)func_0217B984(&config,78);
        (*state)++;
        break;
    case 1:
        func_0217BAF4((int *)p[11]);
        switch(func_0217BB3C((int *)p[11])) {
        case 1: *state=3;break;
        case 2: ((int *)p[10])[2]=2;*state=2;break;
        case 3: ((int *)p[10])[2]=3;*state=2;break;
        case 4: ((int *)p[10])[2]=4;*state=2;break;
        }
        break;
    case 2:
        func_0217BA9C((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B064);
        break;
    case 3:
        p[12]=1;
        func_0217BA9C((int *)p[11]);
        func_021E8AA0(a,(int)func_0217B0C8);
        break;
    }
}

void *func_0217B2E4(const Data *src,unsigned heap)
{
    char *p;
    p=func_02030734(heap,0x3c,0,d_0217E5E4,0xaf);
    func_02082BCC(p,0,0x3c);
    *(Data *)(p+0x14)=*src;
    ((struct Obj10698 *)p)->f34=heap;
    ((struct Obj10698 *)p)->fC=func_02045B38(0,3,0x9e,heap);
    ((struct Obj10698 *)p)->f0=func_021E8A3C((int)p,(int)func_0217B380,heap);
    return p;
}

void func_0217B344(int *p) {func_021E8A78(((struct Obj14356 *)p)->f0);func_02045C04(((struct Obj14356 *)p)->fC);func_020307B0(p);}
