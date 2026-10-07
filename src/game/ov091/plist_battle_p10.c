/*
 * file:     plist_battle_p10.c
 * unit:     yes
 * function: func_021BBBA0, func_021BBBD8, func_021BBBE4, func_021BBC04, func_021BBD98, func_021BBDEC, func_021BBE44, func_021BBE50, func_021BBE5C, func_021BBE68, func_021BBE74, func_021BC17C
 * address:  0x021BBBA0
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
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 *   func_020355C4 0x020355C4 arm
 *   func_02027974  0x02027974  thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021B99E4 0x021B99E4 thumb ov091
 *   func_021BB43C 0x021BB43C thumb ov091
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   d_021BEC8C     0x021BEC8C  data  ov091  a4
 *   func_02027FEC  0x02027FEC  thumb
 *   func_02028148  0x02028148  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02028218  0x02028218  thumb
 *   func_0202822C  0x0202822C  thumb
 *   func_02020F34 0x02020F34 thumb
 *   func_02021014 0x02021014 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_02020FE4 0x02020FE4 thumb
 */
#include "../../matched/include/Obj13256.h"
#include "../../matched/include/Obj20901.h"
#include "../../matched/include/Obj13257.h"
#include "../../matched/include/Obj05174.h"
#include "../../matched/include/Obj07735.h"
#include "../../matched/include/Obj00009.h"

#define APPEND(v) do { *(u16 *)(s + s[0] * 2 + 2) = (v); s[0]++; } while (0)
#define GET(k) func_02021014(p,(k))
#define DONE(k) {func_020307B0(p);return(k);}
struct TaskMenu;
struct U16Vec;
struct MsgBank;
struct Rec;
struct Obj;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct {
    int a;
    short b;
    int flag;
} S;

extern void func_02027858(struct TaskMenu *m);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_020355C4(void);
void func_02027974(int);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern int func_021B99E4(void *, int);
extern int func_021BB43C(int *);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_02027FEC(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void func_02028148(u8 *p);
extern void func_02028178(u8 *p);
extern void func_02028218(struct Obj *obj, u32 a);
void func_0202822C(char *p, int v);
extern void *func_02020F34(u32 item, u32 which, u32 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern unsigned int func_02020FE4(void *,unsigned int,unsigned int);
void func_021BBBA0(unsigned char *a,unsigned char *b);
void func_021BBBD8(int unused, int *p);
unsigned int func_021BBBE4(int a,unsigned char *b);
void func_021BBC04(u8 *p, u8 *s, int *items);
int func_021BBD98(int a, int unused, int idx);
int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5);
void func_021BBE44(int x);
void func_021BBE50(int x);
void func_021BBE5C(int x, int f);
void func_021BBE68(int p, int v);
int func_021BBE74(int id);
int func_021BC17C(unsigned short *p,int id);
extern int d_021BEC8C[];

void func_021BBBA0(unsigned char *a,unsigned char *b) {unsigned char i;func_02027858((struct TaskMenu *)(((struct Obj13256 *)b)->f74));for(i=0;i<b[0];i++)func_02045808((struct U16Vec *)(*(unsigned int *)((unsigned int)b+(unsigned int)i*12+20)));((struct Obj20901 *)a)->f8=func_020355C4();}


void func_021BBBD8(int unused, int *p)
{
    (void)unused;
    func_02027974(p[29]);
}

unsigned int func_021BBBE4(int a,unsigned char *b) {if(func_020279E8(((struct Obj13257 *)b)->f74)==0)return 23;return *(unsigned short *)((unsigned int)b+func_02027A04((const u8 *)(*(int *)&((struct Obj13257 *)b)->f74))*2+2);}

void func_021BBC04(u8 *p, u8 *s, int *items)
{
    int n, i;
    u8 j;
    int v;
    n = 0;
    while (items[n] != 16) {
        n++;
        if (n >= 8)
            break;
    }
    s[0] = 0;
    for (i = 0; i < n; i++) {
        switch (items[i]) {
        case 0: APPEND(0); break;
        case 1:
            for (j = 0; j < 4; j++) {
                if (func_021B99E4(((struct Obj05174 *)p)->f38, j))
                    APPEND(j + 16);
            }
            break;
        case 2:
            for (j = 0; j < 4; j++) {
                if (func_02017E1C(((struct Obj05174 *)p)->f38, j + 0x36, 0))
                    APPEND(j + 16);
            }
            break;
        case 3: APPEND(3); break;
        case 4: APPEND(4); break;
        case 5: APPEND(5); break;
        case 6: APPEND(6); break;
        case 7: APPEND(7); break;
        case 8:
            v = func_021BB43C(*(int **)(p + ((struct Obj05174 *)p)->f2C * 4 + 0x160));
            if (v == 6)
                APPEND(20);
            else if (v <= 5)
                APPEND(21);
            break;
        case 9: APPEND(9); break;
        case 10: APPEND(10); break;
        case 11: APPEND(11); break;
        case 12: APPEND(12); break;
        case 13: APPEND(13); break;
        case 14: APPEND(14); break;
        case 15: APPEND(15); break;
        }
    }
    for (n = 0; n < s[0]; n++) {
        u8 *entry;
        *(int *)(s + n * 12 + 0x14) = func_021BBD98((int)p, (int)s, *(u16 *)(s + n * 2 + 2));
        entry = s + n * 12;
        if (*(u16 *)(s + n * 2 + 2) >= 16 && *(u16 *)(s + n * 2 + 2) <= 19 && (*(int **)(p + 0x280))[0x34 / 4] != 5)
            ((struct Obj07735 *)entry)->f18 = 0x35e0;
        else
            ((struct Obj07735 *)entry)->f18 = 0x39e0;
        if (*(u16 *)(s + n * 2 + 2) == 6)
            ((struct Obj07735 *)entry)->f1C = 1;
        else
            ((struct Obj07735 *)entry)->f1C = 0;
    }
}


int func_021BBD98(int a, int unused, int idx)
{
    int r;
    int h;
    if (idx >= 0x10 && idx <= 0x13) {
        r = func_02017E1C((void *)*(int *)&((struct Obj05174 *)a)->f38, idx + 0x26, 0);
        h = (int)func_02045B38(0, 2, 0xcb, ((struct Obj05174 *)a)->f0);
        r = (int)func_02045EC0((struct MsgBank *)h, r);
        func_02045C04((struct Rec *)h);
    } else {
        r = (int)func_02045EC0((struct MsgBank *)(((struct Obj05174 *)a)->f134), d_021BEC8C[idx]);
    }
    return r;
}


int func_021BBDEC(int p, int unused, int id, int r3, u8 a4, int a5)
{
    S s;
    int r;
    s.a = (int)func_02045EC0((struct MsgBank *)(((struct Obj00009 *)p)->f134), id);
    s.b = 0x39e3;
    if (a5 == 0) {
        s.flag = 0;
    } else {
        s.flag = 1;
    }
    r = func_02027FEC(((struct Obj00009 *)p)->f254, (u32)(&s), r3, a4, 10, ((struct Obj00009 *)p)->f0);
    func_02045808((struct U16Vec *)s.a);
    return r;
}


/*
 * Three null-guarded wrappers, each into an ARM9 routine.
 */
void func_021BBE44(int x)
{
    if (x != 0)
        func_02028148((u8 *)x);
}


void func_021BBE50(int x)
{
    if (x != 0)
        func_02028178((u8 *)x);
}


void func_021BBE5C(int x, int f)
{
    if (x != 0)
        func_02028218((struct Obj *)x, f);
}


/*
 * (no witness at all), and no branch outside this 12-byte range reaches it,
 * so the `bl` site cannot be resolved.  All bytes are correct.
 *
 * DUPLICATE: src/matched/func_021BBE68.c (packet pkt_021BBE68) is the
 * promoted EXACT entry for this address; this copy shares the same packet
 * and is left parked so the address is not sharded twice.
 */
void func_021BBE68(int p, int v)
{
    if (p) {
        func_0202822C((char *)p, v);
    }
}

/*
 * extent: 774 bytes of code; final two zero bytes align the next function.
 */
int func_021BBE74(int id)
{
    void *p=func_02020F34(id,0,23);
    int mask;
    int val;
    if(GET(14)!=1) DONE(29);
    if(GET(30)!=0 || GET(31)!=0 || GET(32)!=0 || GET(33)!=0 || GET(34)!=0 || GET(35)!=0 || GET(36)!=0) DONE(0);
    if(GET(27)!=0) DONE(1);
    if(GET(28)!=0) DONE(2);
    mask=GET(18);
    mask+=GET(19)*2;
    mask+=GET(20)*4;
    mask+=GET(21)*8;
    mask+=GET(22)*16;
    mask+=GET(23)*32;
    switch(mask) {
    case 1:DONE(3);
    case 2:DONE(4);
    case 4:DONE(5);
    case 8:DONE(6);
    case 16:DONE(7);
    case 32:DONE(8);
    case 63:
        if(GET(41)!=0) DONE(11);
        DONE(9);
    }
    if(GET(24)!=0) DONE(10);
    if(GET(41)!=0) DONE(11);
    if(GET(26)!=0) DONE(12);
    val=GET(52);
    if(val>0) DONE(13);
    if(val<0) DONE(19);
    val=GET(53);
    if(val>0) DONE(14);
    if(val<0) DONE(20);
    val=GET(54);
    if(val>0) DONE(15);
    if(val<0) DONE(21);
    val=GET(55);
    if(val>0) DONE(16);
    if(val<0) DONE(22);
    val=GET(56);
    if(val>0) DONE(17);
    if(val<0) DONE(23);
    val=GET(57);
    if(val>0) DONE(18);
    if(val<0) DONE(24);
    if(GET(29)!=0) DONE(25);
    if(GET(37)!=0) DONE(26);
    if(GET(38)!=0) DONE(27);
    if(GET(39)!=0 || GET(40)!=0) DONE(28);
    DONE(29);
}

int func_021BC17C(unsigned short *p,int id) { switch(func_021BBE74(id)) { case 26:return 1; case 27:return 1; case 28: if(func_02020FE4((void *)id,39,*p)) return 1; break; } return 0; }
