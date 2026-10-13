/*
 * file:     unit_021FD4F8.c
 * unit:     yes
 * function: func_021FD4F8, func_021FD52C, func_021FD550, func_021FD5E4, func_021FD634, func_021FD68C, func_021FD6A4, func_021FD6C8, func_021FD6DC, func_021FD6F0, func_021FD704, func_021FD76C, func_021FD7D4, func_021FD83C, func_021FD844, func_021FD84C, func_021FD8C4, func_021FD8D4, func_021FD8EC, func_021FD904, func_021FD908, func_021FD910, func_021FD918, func_021FD938
 * address:  0x021FD4F8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FCEA8 0x021FCEA8 thumb ov132
 *   _u32_div_f 0x0209C2B0 arm
 *   GFL_NET_HANDLE_GetNetHandle 0x0203996C arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   func_021FDA74 0x021FDA74 thumb ov132
 *   func_0203F0A8 0x0203F0A8 arm
 *   func_021FCE74  0x021FCE74  thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   func_021FCDEC 0x021FCDEC thumb ov132
 */
#include "ov132_types.h"

struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int u32;

struct Rec {
    u8 pad00[4];
    int state;
    u8 pad08[0x0A];
    u8 id;
    u8 pad13[9];
    u32 f1c;
    u8 pad20[0x10];
};

struct Ctx {
    u8 pad00[0x60];
    struct Rec rec[4];
};

typedef struct S {
    u8 pad00[0x14C];
    u8 f14c;
    int f150;
    int f154;
    u8 pad158[0x24];
    int f17c;
} S;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned long long u64;

extern u32 func_021FCEA8(int unused, int kind, u32 value, u32 id);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern void func_021FDA74(int a0, int a1, int a2);
extern u32 func_0203F0A8(void);
extern void func_021FCE74(int unused, int kind, u32 value, u32 id);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(struct Link *);
extern void func_021FCDEC(int,int);
u32 func_021FD4F8(struct Ctx *p, u8 key);
void func_021FD52C(S *s);
void func_021FD550(char *p);
int func_021FD5E4(char *p,u32 i);
void func_021FD634(int a,int b,int c,char *p);
void *func_021FD68C(int a,char *p);
int func_021FD6A4(char *p);
int func_021FD6C8(u8 *p);
int func_021FD6DC(char *p);
int func_021FD6F0(char *p);
int func_021FD704(u8 *p);
void func_021FD744(void *a, void *b, void *c, u8 *p);
u32 func_021FD760(void *a, u8 *p);
int func_021FD76C(u8 *p);
void func_021FD7AC(void *a, void *b, void *c, u8 *p);
u32 func_021FD7C8(void *a, u8 *p);
int func_021FD7D4(u8 *p);
void func_021FD814(void *a, void *b, void *c, u8 *p);
u32 func_021FD830(void *a, u8 *p);
u32 func_021FD83C(char *p);
int func_021FD844(int *p);
int func_021FD84C(u8 *p);
void func_021FD8C4(char *p, int a);
u32 func_021FD8D4(char *p);
u8 func_021FD8EC(char *p, int index);
u32 func_021FD8F8(char *p,u32 index);
int func_021FD904(int *p);
u32 func_021FD908(u8 *p);
int func_021FD910(int *p);
void func_021FD918(char *p, u32 a, int b);
void func_021FD938(char *p);
void func_021FD948(char *p,u32 value);
u32 func_021FD954(char *p);
u32 func_021FD95C(char *p);


/*
 * 2026-10-05 (wave D9): witness leaf for ov010 MUSICAL_EVENT_RollProgramRewards. Searches the
 * four 48-byte records at +0x60 for one whose id byte (+0x12) equals the key
 * and whose state word (+4) is 1; returns its word at +0x1C, else 0.
 */
u32 func_021FD4F8(struct Ctx *p, u8 key)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (key == p->rec[i].id && p->rec[i].state == 1)
            return p->rec[i].f1c;
    }
    return 0;
}


/*
 * Unlabelled leaf hidden in a .word run; helper whose address is the
 * witness for the call in ov010 MUSICAL_DRESSUP_SYS_Main.
 */
void func_021FD52C(S *s)
{
    if (s->f150 == 0) {
        s->f150 = 1;
        s->f14c = 0;
        s->f17c = 1;
        s->f154 = 0;
    }
}

void func_021FD550(char *p)
{
    if(((struct ActingHost *)p)->f150==1) {
        switch(*(u32 *)&((struct ActingHost *)p)->f17C) {
        case 0: break;
        case 1:
            if(func_021FCEA8((int)p,7,((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->f140))->f2C,0xff)==1) ((struct ActingHost *)p)->f17C=2;
            break;
        case 2: break;
        case 3:
            if(func_021FD5E4(p,((struct ActingHost *)p)->f14C)==1) {
                ((struct ActingHost *)p)->f154=1;
                ((struct ActingHost *)p)->f17C=4;
            }
            break;
        case 4:
            if(((struct ActingHost *)p)->f154==0) {
                if((u32)(((struct ActingHost *)p)->f14C*0x3800)>=((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->f140))->f2C) ((struct ActingHost *)p)->f150=0;
                else ((struct ActingHost *)p)->f17C=3;
            }
            break;
        }
    }
}

/*
 * followers: own leaf files 021FD634 and 021FD68C.
 */
int func_021FD5E4(char *p,u32 i)
{
    char *q;
    char *s;
    u16 n;
    q=*(char * *)&((struct ActingHost *)p)->f140;
    n=0x3800;
    s=*(char * *)&((struct HostEntry *)q)->f10+i*0x3800;
    if((i+1)*0x3800>((struct HostEntry *)q)->f2C) n=((struct HostEntry *)q)->f2C%0x3800U;
    return GFL_NET_SendData((u32)GFL_NET_HANDLE_GetNetHandle(0xff),0xff,0x1105,n,(u32)s,0,1,1);
}

void func_021FD634(int a,int b,int c,char *p)
{
    char *q;
    char *s;
    u32 v;
    (((struct ActingHost *)p)->f14C)++;
    ((struct ActingHost *)p)->f154=0;
    q=*(char * *)&((struct ActingHost *)p)->f140;
    if((u32)(((struct ActingHost *)p)->f14C*0x3800)>=((struct HostEntry *)q)->f2C) {
        s=*(char * *)&((struct HostEntry *)q)->f10;
        ((struct HostEntry *)q)->f14=s+0xc;
        q=*(char * *)&((struct ActingHost *)p)->f140;
        ((struct HostEntry *)q)->f18=*(char * *)&((struct HostEntry *)q)->f10+0xc+((struct Obj10567 *)s)->f0;
        q=*(char * *)&((struct ActingHost *)p)->f140;
        v=((struct Obj10567 *)s)->f4;
        ((struct HostEntry *)q)->f1C=v+(*(u32 *)&((struct HostEntry *)q)->f10+0xc+((struct Obj10567 *)s)->f0);
    }
}

void *func_021FD68C(int a,char *p)
{
    char *q;
    q=*(char * *)&((struct ActingHost *)p)->f140;
    return *(char * *)&((struct HostEntry *)q)->f10+((struct ActingHost *)p)->f14C*0x3800;
}

int func_021FD6A4(char *p) {if(((struct HostEntry *)(*(char * *)&((struct ActingHost *)p)->f140))->f2C/0x3800u<((struct ActingHost *)p)->f14C)return 1;return 0;}


/*
 * Addresses are Black-image addresses.
 */
int func_021FD6C8(u8 *p)
{
    void *q = ((struct ActingHost *)p)->f140.p;
    return func_021FCEA8((int)p, 4, (u32)(((struct HostEntry *)q)->f20), 0xff);
}


int func_021FD6DC(char *p)
{
    return func_021FCEA8((int)p, 5, *(int *)(((struct ActingHost *)p)->f140.s + 0x24), 0xff);
}


int func_021FD6F0(char *p)
{
    return func_021FCEA8((int)p, 6, *(int *)(((struct ActingHost *)p)->f140.s + 0x28), 0xff);
}

int func_021FD704(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->f140;
    u32 id;
    func_021FDA74(q[1], q[8], 2);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1106, (*(u32 **)(p + 0x140))[8], (*(u32 **)(p + 0x140))[1], 1, 0, 1);
}

void func_021FD744(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->f170 = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->f140;
    func_021FDA74(q[1], q[8], 12);
}

u32 func_021FD760(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[1];
}

int func_021FD76C(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->f140;
    u32 id;
    func_021FDA74(q[2], q[9], 1);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1107, (*(u32 **)(p + 0x140))[9], (*(u32 **)(p + 0x140))[2], 1, 0, 1);
}

void func_021FD7AC(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->f174 = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->f140;
    func_021FDA74(q[2], q[9], 11);
}

u32 func_021FD7C8(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[2];
}

int func_021FD7D4(u8 *p)
{
    u32 *q = *(u32 * *)&((struct ActingHost *)p)->f140;
    u32 id;
    func_021FDA74(q[3], q[10], 0);
    id = (u32)GFL_NET_HANDLE_GetNetHandle(255);
    return GFL_NET_SendData(id, 255, 0x1108, (*(u32 **)(p + 0x140))[10], (*(u32 **)(p + 0x140))[3], 1, 0, 1);
}

void func_021FD814(void *a, void *b, void *c, u8 *p)
{
    u32 *q;
    ((struct ActingHost *)p)->f178 = 1;
    q = *(u32 * *)&((struct ActingHost *)p)->f140;
    func_021FDA74(q[3], q[10], 10);
}

u32 func_021FD830(void *a, u8 *p)
{
    return (*(u32 **)(p + 0x140))[3];
}

u32 func_021FD83C(char *p) {return ((struct ActingHost *)p)->f170;}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x5e of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionReady.
 */
int func_021FD844(int *p)
{
    return p[0x5e];
}

static inline u8 random4(void)
{
    u32 draw;
    draw = func_0203F0A8();
    return ((u64)draw * 4) >> 32;
}

/*
 * padding: two zero bytes at 021FD8C2 before next labelled function.
 * lever: bind the inline random draw to u32 before the multiply-high.
 */
int func_021FD84C(u8 *p)
{
    u8 slots[4];
    u8 i, j, n;
    int result = 0;
    for (i = 0; i < 4; i++) slots[i] = i;
    for (n = 0; n < 10; n++) {
        for (i = 0; i < 4; i++) {
            int t;
            j = random4();
            t = slots[i];
            slots[i] = slots[j];
            slots[j] = t;
        }
    }
    for (i = 0; i < 4; i++) result += slots[i] << (i * 4);
    return func_021FCEA8((int)p, 1, result, 255);
}


void func_021FD8C4(char *p, int a)
{
    func_021FCE74((int)p, 0xa, a, 0xff);
}

u32 func_021FD8D4(char *p) {return *(u8 *)((u32)p+GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle())*0x30+0x72);}

u8 func_021FD8EC(char *p, int index) {return *(u8 *)((u32)p+index*0x30+0x72);}

u32 func_021FD8F8(char *p,u32 index){return *(u32 *)((u32)p+index*0x30+0x80);}


/*
 * Unlabelled ov132 leaf hidden in a .word run: returns the word at +0x48.
 * Matched to supply the `matched` witness for the pending ov010 caller
 * MUSICAL_EVENT_CreateLocalPerformer.
 */
int func_021FD904(int *p)
{
    return ((struct ActingHost *)p)->f48;
}

/*
 * Getter: returns the word at offset 0x158.
 */
u32 func_021FD908(u8 *p)
{
 return *(u32 *)(p+0x158);
}

/*
 * Unlabelled ov132 leaf hidden in a .word run: returns element 0x57 of the
 * argument viewed as an int array.  Matched to supply the `matched` witness
 * for the pending ov010 caller SCRCMD_MUSICAL_WaitSessionFinish.
 */
int func_021FD910(int *p)
{
    return p[0x57];
}

void func_021FD918(char *p, u32 a, int b) {func_021FCDEC((int)p,0x40);((struct ActingHost *)p)->f4C=6;((struct ActingHost *)p)->f144.s=a;((struct ActingHost *)p)->f148.s=b;}

void func_021FD938(char *p) {func_021FCDEC((int)p,0x42);((struct ActingHost *)p)->f4C=12;}

/*
 * The larger indexed follower at 021FD964 is parked separately at DIFF.
 */
void func_021FD948(char *p,u32 value){((struct ActingHost *)p)->f4C=18;((struct ActingHost *)p)->f120=value;}

u32 func_021FD954(char *p){return ((struct ActingHost *)p)->f144.u;}

u32 func_021FD95C(char *p){return ((struct ActingHost *)p)->f148.u;}
