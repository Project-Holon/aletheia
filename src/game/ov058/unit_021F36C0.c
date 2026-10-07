/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3714, func_021F373C, func_021F38F4
 * address:  0x021F36C0
 * region:   ov058
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   d_021F3B60  0x021F3B60  data  ov058  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021BE480 0x021BE480 thumb ov021
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3038 0x021A3038 thumb ov021
 *   func_02012A30 0x02012A30 thumb
 *   func_020056EC 0x020056EC thumb
 *   func_02006148 0x02006148 thumb
 *   func_02006224 0x02006224 thumb
 *   func_02028A7C 0x02028A7C thumb
 *   func_021F391C  0x021F391C  thumb  ov058
 */
#define W(p,k) (*(int *)((u8 *)(p)+(k)))
#define H(p,k) (*(u16 *)((u8 *)(p)+(k)))
struct Big;
struct Ctx;
struct BigObj;
struct SoundSys2;
struct Obj00020;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int u32;

struct VecFx32 { int x,y,z; };

extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern int *func_021897BC(char *p, int idx);
extern void func_021BE760(int a, void *b, int c);
extern void func_021BE418(u8 *p, u16 i);
extern void func_021897A0(unsigned char *p, int id);
extern int func_021BE480(char *p, unsigned i, int j);
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3038(u8 *,struct VecFx32 *);
extern u32 func_02012A30(const struct BigObj *);
extern u32 func_020056EC(u32);
extern int func_02006148(u32);
extern int func_02006224(u32);
extern void func_02028A7C(struct SoundSys2 *,u32);
extern void func_021F391C(void *unused, void *a, int i, int j);
void func_021F36C0(int a);
void func_021F3714(void *a0);
void func_021F373C(struct Obj00020 *p);
void func_021F38F4(void *unused, void *a);
extern char d_021F3B60[];


void func_021F36C0(int a)
{
    int r4;
    void *r6;

    func_02188C84((u8 *)a);
    r4 = func_02188D2C((int *)a);
    func_02012EC4(func_020120F4(func_02188C80((void *)a)));
    func_02189764((unsigned char *)a, 1, func_02188C84((u8 *)a), 0x20);
    r6 = func_021897BC((char *)a, 1);
    func_021BE760(r4, d_021F3B60, 0);
    func_021F38F4(r6, (void *)a);
}


void func_021F3714(void *a0)
{
    func_02012EC4((struct Big *)func_020120F4(func_02188C80(a0)));
    func_021BE418((u8 *)func_02188D2C((int *)a0), 0);
    func_021897A0((unsigned char *)a0, 1);
}

void func_021F373C(struct Obj00020 *p)
{
    struct VecFx32 pos;
    int first;
    int second;
    void *big;
    void *scene;
    void *state;
    u8 *part;
    int i;
    int *entry;
    struct SoundSys2 *sound;
    int delta;
    big=func_020120F4(func_02188C80(p));
    func_02012EC4(big);
    scene=(void *)func_02188D2C((int *)p);
    state=func_021897BC((char *)p,1);
    part=(u8 *)state+8;
    if(H(part,4)!=0) H(part,4)--;
    else {
        i=H(part,6)*4;
        W(part,0)++;
        entry=(int *)func_021BE480(scene,0,(u16)i);
        *entry=(W(part,0)<<16)+0x1770000;
        if(*entry>=0x1c60000) {
            W(part,0)=0;
            W(state,16)=0;
            H(part,4)=func_020056EC(30)+30;
            H(part,6)=func_020056EC(3);
        }
        first=*entry;
        entry=(int *)func_021BE480(scene,0,(u16)(i+1));
        *entry=(W(part,0)<<16)+0x1710000;
        if(*entry>=0x1c60000) W(part,0)=0;
    }
    part=(u8 *)state+20;
    if(H(part,4)!=0) H(part,4)--;
    else {
        i=H(part,6)*4+2;
        W(part,0)++;
        entry=(int *)func_021BE480(scene,0,(u16)i);
        *entry=0x1c60000-(W(part,0)<<16);
        if(*entry<=0x1770000) {
            W(part,0)=0;
            W(state,28)=0;
            H(part,4)=func_020056EC(30);
            H(part,6)=func_020056EC(3);
        }
        second=*entry;
        entry=(int *)func_021BE480(scene,0,(u16)(i+1));
        *entry=0x1cc0000-(W(part,0)<<16);
        if(*entry<=0x1770000) W(part,0)=0;
    }
    func_021A3038(func_02188CB4(p),&pos);
    if(pos.z>=0x2020000 && pos.z<=0x2140000) {
        sound=(struct SoundSys2 *)func_02012A30(big);
        delta=pos.x-first;
        if(delta>=0 && delta<=0x40000 && W(state,16)==0) {
            if(func_02006224(func_02006148(0x77e))==0) {
                W(state,16)=1;
                func_02028A7C(sound,0x77e);
            }
        }
        delta=second-pos.x;
        if(delta>=0 && delta<=0x40000 && W(state,28)==0) {
            if(func_02006224(func_02006148(0x77f))==0) {
                W(state,28)=1;
                func_02028A7C(sound,0x77f);
            }
        }
    }
}


void func_021F38F4(void *unused, void *a)
{
    func_021F391C(unused, a, 0, 1);
    func_021F391C(unused, a, 4, 5);
    func_021F391C(unused, a, 8, 9);
}
