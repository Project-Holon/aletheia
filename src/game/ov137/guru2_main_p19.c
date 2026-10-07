/*
 * file:     guru2_main_p19.c
 * unit:     yes
 * function: func_021E0E1C, func_021E0E2C, func_021E0E50, func_021E0EAC, func_021E0EFC, func_021E0F20, func_021E0F54, func_021E0F64, func_021E0FAC, func_021E1028, func_021E104C, func_021E1080, func_021E1090, func_021E10D8
 * address:  0x021E0E1C
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_021E15DC 0x021E15DC thumb ov137
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_0203F5FC 0x0203F5FC arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../../matched/include/Obj23787.h"
#include "../../matched/include/Obj23788.h"
#include "../../matched/include/Obj23790.h"
#include "../../matched/include/Obj14244.h"
#include "../../matched/include/Obj23791.h"
#include "../../matched/include/Obj14245.h"
#include "../../matched/include/Obj23793.h"
#include "../../matched/include/Obj04541.h"

struct Node;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct { int active; char rest[0xb0]; } Record;

typedef struct { char pad[0x140]; Record records[1]; } Block;

typedef struct { int active, state, x, y, key; } Entry_021E0F64;

typedef struct { int active, state, x, y, z, key; } Entry_021E1090;

typedef struct {unsigned state;int active,other,timer,speed;} State;

extern void func_02030EAC(struct Node *n);
extern void func_021E15DC(int *, int);
extern void func_02082BCC(void *, int, unsigned);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
extern int func_0203F5FC(u32 x);
extern void func_020061E4(u32 a);
void func_021E0E1C(u8 *p);
void func_021E0E2C(char *p,int value);
void func_021E0E50(char *p);
int func_021E0E8C(char *p);
void func_021E0EAC(int *p);
void func_021E0EFC(void *unused,char *p);
void func_021E0F20(char *p);
void func_021E0F54(u8 *p);
void func_021E0F64(char *p, int key);
void func_021E0FAC(int *p);
void func_021E1028(void *unused,char *p);
void func_021E104C(char *p);
void func_021E1080(u8 *p);
void func_021E1090(char *p, int key);
void func_021E10D8(u8 *p,State *s);
void func_021E11A0(void *unused,u8 *p);


/*
 * Addresses are Black-image addresses.
 */
void func_021E0E1C(u8 *p)
{
    func_02030EAC(((struct Obj23787 *)p)->fD7C);
}

void func_021E0E2C(char *p,int value) { int i; int *q; q=(int *)(p+0xaf8); for(i=0;i<5;i++,q+=8) { if(*q==0) { *q=1; q[7]=value; return; } } }

void func_021E0E50(char *p)
{
    Block *base=(Block *)(p+0x1a0);
    int count=((struct Obj23788 *)p)->f30;
    int i;
    i=0;
    do {
        if (base->records[i].active) func_021E0E2C(p,(int)((char *)&base->records[i]));
        i++;
    } while (i<count);
}

/*
 * extent: unlabelled bool scan follower at 0x021E0E8C, through pool at 0x021E0EA8.
 */
int func_021E0E8C(char *p)
{
    int i;
    char *q=p+0xaf8;
    for (i=0;i<5;i++,q+=0x20) if (((struct Obj23790 *)q)->f0) return 1;
    return 0;
}

void func_021E0EAC(int *p)
{
    int *q = (int *)p[4];
    switch (p[1]) {
    case 0:
        p[3] = 0x18000;
        q[12] = 0;
        p[1]++;
    case 1:
        func_021E15DC(q + 12, p[3]);
        if (q[12] < 0x4000) {
            p[3] = (unsigned)p[3] >> 1;
            if (p[3] < 0x4000) {
                q[12] = 0;
                func_02082BCC(p, 0, 20);
            }
        }
        break;
    }
}

void func_021E0EFC(void *unused,char *p) { int i; int *q; q=(int *)(p+0xb98); for(i=0;i<5;i++,q+=5) if(*q!=0) func_021E0EAC(q); }

void func_021E0F20(char *p) { func_02082BCC(p+2968,0,100); *(struct Node * *)&((struct Obj14244 *)p)->fD80=func_02030DA8(*(struct Ctx * *)&((struct Obj14244 *)p)->fD98,(u32)func_021E0EFC,(u32)p,257); }


void func_021E0F54(u8 *p)
{
    func_02030EAC(((struct Obj23791 *)p)->fD80);
}

void func_021E0F64(char *p, int key)
{
    int i;
    Entry_021E0F64 *entry;
    Entry_021E0F64 *base = (Entry_021E0F64 *)(p + 0xb98);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}

/*
 *   typedef unsigned short u16;
 *   extern const short d_020A1B38[];
 *   int func_0203F5FC(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 *   }
 */
void func_021E0FAC(int *p)
{
    int *q = (int *)p[5];
    int old;
    int amount;
    switch (p[1]) {
    case 0:
        q[13] = 0;
        p[4] = 0;
        p[2] = 0x1e000;
        p[3] = 0x14000;
        p[1]++;
    case 1:
        amount = func_0203F5FC((u16)(p[4] / 4096)) * (p[2] / 4096);
        q[13] = 0;
        func_021E15DC(q + 13, amount);
        old = p[4];
        func_021E15DC(p + 4, p[3]);
        if (p[4] < old) {
            p[2] = (unsigned)p[2] >> 1;
            if (p[2] == 0) {
                q[13] = 0;
                func_02082BCC(p, 0, 24);
            }
        }
        break;
    }
}

void func_021E1028(void *unused,char *p) { int i; int *q; q=(int *)(p+0xbfc); for(i=0;i<5;i++,q+=6) if(*q!=0) func_021E0FAC(q); }

void func_021E104C(char *p) { func_02082BCC(p+3068,0,120); *(struct Node * *)&((struct Obj14245 *)p)->fD84=func_02030DA8(*(struct Ctx * *)&((struct Obj14245 *)p)->fD98,(u32)func_021E1028,(u32)p,258); }


void func_021E1080(u8 *p)
{
    func_02030EAC(((struct Obj23793 *)p)->fD84);
}

void func_021E1090(char *p, int key)
{
    int i;
    Entry_021E1090 *entry;
    Entry_021E1090 *base = (Entry_021E1090 *)(p + 0xbfc);
    entry = base;
    for (i = 0; i < 5; i++, entry++) {
        if (entry->active == 1 && entry->key == key) {
            entry->state = 0;
            return;
        }
    }
    for (i = 0; i < 5; i++, base++) {
        if (base->active == 0) {
            base->active = 1;
            base->key = key;
            return;
        }
    }
}

void func_021E10D8(u8 *p,State *s)
{
    u8 *b=p+0xe0;
    switch(s->state) {
    case 1:
        s->speed=0x4000;s->timer=0;s->state++;
    case 2:
        ((struct Obj04541 *)b)->f34-=4096;
        if(((struct Obj04541 *)b)->f34<=-32768)s->state++;
        break;
    case 3:
        ((struct Obj04541 *)b)->f34+=8192;
        if(((struct Obj04541 *)b)->f34>=0) {
            ((struct Obj04541 *)b)->f34=0;
            func_021E0E50((char *)p);
            s->active=1;s->state++;
            func_020061E4(0x55e);
        }
        break;
    case 4:
        ((struct Obj04541 *)b)->f28=s->speed;
        s->speed=-s->speed;
        s->timer++;
        if(!(s->timer&3)) {
            if(s->speed<=4096) {((struct Obj04541 *)b)->f28=0;s->state++;}
            else s->speed>>=1;
        }
        break;
    case 5:
        if(!func_021E0E8C((char *)p)) {
            s->other=0;s->active=0;s->state=0;
            func_020061E4(0x76d);
        }
        break;
    case 0:break;
    }
}

void func_021E11A0(void *unused,u8 *p)
{
    func_021E10D8(p,(State *)(p+0xc74));
}
