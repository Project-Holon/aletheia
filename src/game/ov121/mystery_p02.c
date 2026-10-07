/*
 * file:     mystery_p02.c
 * unit:     yes
 * function: func_021D6D50, func_021D6D6C, func_021D6D7C, func_021D6D80, func_021D6DB4, func_021D6DF4, func_021D6E3C
 * address:  0x021D6D50
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0205121C  0x0205121C  arm
 *   func_02051230  0x02051230  arm
 *   func_020515CC  0x020515CC  arm
 *   func_021D9F08 0x021D9F08 thumb ov121
 *   func_021D81B0 0x021D81B0 thumb ov121
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   func_0204E720 0x0204E720 arm
 *   func_0204E804 0x0204E804 arm
 *   func_021D80C0 0x021D80C0 thumb ov121
 *   func_0202EB44 0x0202EB44 thumb
 *   func_021DA84C 0x021DA84C thumb ov121
 *   func_021DE4D8 0x021DE4D8 thumb ov121
 *   func_021D80F0 0x021D80F0 thumb ov121
 *   func_021D7B4C 0x021D7B4C thumb ov121
 *   func_021D72F0 0x021D72F0 thumb ov121
 *   func_021D7EAC 0x021D7EAC thumb ov121
 *   func_021D73DC 0x021D73DC thumb ov121
 *   func_021D7CF4 0x021D7CF4 thumb ov121
 *   func_021DE308 0x021DE308 thumb ov121
 *   func_021DE3E0 0x021DE3E0 thumb ov121
 *   func_021DE4DC 0x021DE4DC thumb ov121
 *   func_021DEF6C 0x021DEF6C thumb ov121
 *   func_021D9554 0x021D9554 thumb ov121
 *   func_021DE500 0x021DE500 thumb ov121
 *   func_021DE550 0x021DE550 thumb ov121
 *   func_021DA8C0 0x021DA8C0 thumb ov121
 *   func_021DA8C4 0x021DA8C4 thumb ov121
 *   func_021D83DC 0x021D83DC thumb ov121
 *   func_021D83B0 0x021D83B0 thumb ov121
 *   func_021D8138 0x021D8138 thumb ov121
 *   func_021DA178 0x021DA178 thumb ov121
 *   func_021D8198 0x021D8198 thumb ov121
 *   func_021D8380 0x021D8380 thumb ov121
 *   func_021D849C 0x021D849C thumb ov121
 *   func_021D9FF8 0x021D9FF8 thumb ov121
 *   func_021D7814 0x021D7814 thumb ov121
 *   func_020362DC 0x020362DC arm
 *   func_0203F4E4 0x0203F4E4 arm
 */
#include "../../matched/include/Obj22857.h"
#include "../../matched/include/Obj00326.h"

#define P(k) (*(void **)(p+(k)))
#define W(k) (*(u32 *)(p+(k)))
struct RtcDate;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct {int y,m,d,week;} Date;

extern int func_0205121C(u32 a, u32 b, u32 c);
extern void func_02051230(int, int, int, int);
extern int func_020515CC(int *p, int a, int b, int c);
extern void func_021D9F08(u8 *,int,int,int);
extern void func_021D81B0(u8 *,u32,int);
extern void func_021DA8B0(u32 *p, u32 a);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern int func_0204E804(void);
extern void func_02005E30(u32 a);
extern void func_021D80C0(void *p, int n, char *q);
extern void func_021DE308(char *,unsigned);
extern int func_021DE3E0(void *);
extern int func_021DE4DC(u8 *p, void *a, u32 b);
extern int func_021DEF6C(char *,void *,u16);
extern int func_021D9554(char *p, int n);
extern int func_021DE500(void *);
extern void func_021DE550(char *p);
extern void func_021DA8C0(u32 *p, u32 a);
extern void func_021DA8C4(u32 *p);
extern void func_021D83DC(u8 *,int);
extern int func_021D83B0(char *p);
extern void func_021D8138(u8 *,int,int);
extern int func_021DA178(char *);
extern void func_021D8198(char *);
extern void func_021D8380(char *p);
extern void func_021D849C(char *p);
extern unsigned func_021D9FF8(u8 *p);
extern void func_021D7814(void *task, u32 *state, u8 *p);
extern u32 func_020362DC(void);
extern void func_0203F4E4(struct RtcDate *date);
extern int func_0200A1A8(char *p, unsigned int bit);
extern int func_0200A034(void *p, void *arg);
extern void func_0200A1E4(void *p, unsigned int idx);
extern u32 func_0200A0C8(u8 *p);
extern u32 func_0200A348(struct Obj *);
extern int func_0200A104(char *p, unsigned int idx);
extern int func_0200A350(struct Obj *a0);
extern int func_0202EB44(void);
extern void *func_021DE4D8(char *p);
extern void func_021DA84C(u8 *p, u32 i, u32 value);
extern void func_021D80F0(void *a, int *state, u8 *p);
extern void func_021D7B4C(void *task, u32 *state, u8 *p);
extern void func_021D72F0(void *a, int *state, char *p);
extern void func_021D7EAC(void *task, u32 *state, u8 *p);
extern void func_021D73DC(void *task, u32 *state, u8 *p);
extern void func_021D7CF4(void *task, u32 *state, u8 *p);
void func_021D6D50(int *p, int a, int b, int c);
int func_021D6D6C(void **p, int x);
void *func_021D6D7C(u8 *p);
void func_021D6D80(void *a,int b,u8 *p);
void func_021D6DB4(void *a, int *state);
void func_021D6DF4(void *a, int *state);
void func_021D6E3C(void *task,u32 *state,u8 *p);


/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x0205121C now has an
 * EXACT arm9 shard entry (pkt_0205121C), so the call at +000A resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void func_021D6D50(int *p, int a, int b, int c)
{
    int x = func_0205121C(a, b, c);
    func_02051230(*p, x, 1, 0);
}


/*
 * Addresses are Black-image addresses.
 */
int func_021D6D6C(void **p, int x)
{
    return func_020515CC(*p, x, 0, (int)p);
}

void *func_021D6D7C(u8 *p) { return ((struct Obj22857 *)p)->fC; }

void func_021D6D80(void *a,int b,u8 *p)
{
    func_021D9F08(*(u8 * *)&((struct Obj00326 *)p)->f284,((struct Obj00326 *)p)->f3A4,79,0);
    func_021D81B0(p,0,29);
    func_021DA8B0(a,(u32)func_021D6DB4);
}

void func_021D6DB4(void *a, int *state)
{
    switch (*state) {
    case 0: func_0204E720(3, 16, 0, 0); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2: func_021DA8B0(a, (u32)func_021D6E3C); break;
    }
}

void func_021D6DF4(void *a, int *state)
{
    switch (*state) {
    case 0: func_0204E720(12, 0, 16, 0); func_02005E30(8); *state = 1; break;
    case 1: if (!func_0204E804()) *state = 2; break;
    case 2: func_021DA8B0(a, (u32)func_021D80C0); break;
    }
}

void func_021D6E3C(void *task,u32 *state,u8 *p)
{
    int v,flag,all,id;
    u32 i;
    switch(*state) {
    case 0:
        if(W(968)) {W(968)=0;*state=2;break;}
        func_021D9F08(P(644),W(932),79,0);
        if(P(624)==0) func_021D81B0(p,0,29);
        *state=1;break;
    case 1:
        v=func_021D83B0((char *)p);
        if(v!=-1) {
        if(v==0) {
            all=1;
            func_021D8380((char *)p);
            flag=(func_0200A0C8(P(956))==0);
            if(flag) {
                for(i=0;i<func_0200A348(P(956));i++) {
                    if(func_0200A104(P(956),i)) all=0;
                }
            }
            if(flag) {
                if(all) {
                    if(func_0200A350(P(956))==0) id=146;
                    else id=137;
                    func_021D9F08(P(644),W(932),id,1);
                    func_021DA8C0(task,0);*state=19;
                } else *state=16;
            } else {
                if(func_0202EB44()==0) func_021DA8B0(task,(u32)func_021D80F0);
                else *state=2;
            }
        } else if(v==1) {
            func_021D8380((char *)p);func_021DA8B0(task,(u32)func_021D7B4C);
        } else if(v==2) {
            func_021D8380((char *)p);func_021DA8B0(task,(u32)func_021D72F0);
        } else if(v==3) func_021DA8B0(task,(u32)func_021D6DF4);
        else break;
        }
        break;
    case 2:
        func_021D9F08(P(644),W(932),83,1);
        func_021DA8C0(task,3);*state=19;break;
    case 3:func_021D8138(p,0,29);*state=4;break;
    case 4:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) *state=5;else if(v==1) *state=0;
        }
        break;
    case 5:func_021DE308(P(944),1);*state=6;break;
    case 6:if(func_021DE3E0(P(944))==2) *state=7;break;
    case 7:
        func_021D8380((char *)p);func_021D81B0(p,1,29);
        func_021D9F08(P(644),W(932),86,0);*state=8;break;
    case 8:
        if(((u32)func_021DE4D8(P(944)))&32) func_021DA84C(P(624),0,1);
        else func_021DA84C(P(624),0,0);
        v=func_021D83B0((char *)p);
        if(v!=-1) {
        func_021D8380((char *)p);
        switch(v) {
        case 0:W(940)=0;*state=9;break;
        case 1:W(940)=1;*state=12;break;
        case 2:W(940)=2;*state=9;break;
        case 3:*state=14;break;
        }
        }
        break;
    case 9:
        switch(W(940)) {
        case 0:func_021D9F08(P(644),W(932),96,1);func_021DA8C0(task,10);*state=19;break;
        case 1:break;
        case 2:func_021D9F08(P(644),W(932),102,1);func_021DA8C0(task,10);*state=19;break;
        }
        break;
    case 10:func_021D8138(p,0,29);*state=11;break;
    case 11:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) *state=12;else if(v==1) *state=7;
        }
        break;
    case 12:
        if(func_021DE3E0(P(944))==2) {func_021DE308(P(944),3);*state=13;}
        break;
    case 13:
        if(func_021DE3E0(P(944))==0) {
            if(W(940)==1) func_021DA8B0(task,(u32)func_021D7EAC);
            else func_021DA8B0(task,(u32)func_021D73DC);
        }
        break;
    case 14:
        if(func_021DE3E0(P(944))==2) {func_021DE308(P(944),3);*state=15;}
        else *state=0;
        break;
    case 15:if(func_021DE3E0(P(944))==0) *state=0;break;
    case 16:
        func_021D9F08(P(644),W(932),141,1);
        func_021DA8C0(task,17);*state=19;break;
    case 17:func_021D8138(p,0,29);*state=18;break;
    case 18:
        v=func_021DA178(P(608));
        if(v!=-1) {
            func_021D8198((char *)p);
            if(v==0) func_021DA8B0(task,(u32)func_021D7CF4);
            else if(v==1) *state=0;
        }
        break;
    case 19:if(func_021D9FF8(P(644))) func_021DA8C4(task);break;
    }
}
