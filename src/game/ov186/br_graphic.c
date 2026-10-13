/*
 * file:     _try_pair_o039.c
 * unit:     yes
 * function: func_021FC3BC, func_021FC474, func_021FC4C8, func_021FC4DC, func_021FC4E8, func_021FC4FC, func_021FC55C, func_021FC594, func_021FC598, func_021FC5A0, func_021FC5E0, func_021FC5FC, func_021FC604, func_021FC610, func_021FC640
 * address:  0x021FC3BC
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_020056A0 0x020056A0 thumb
 *   d_02200D4C 0x02200D4C data a1
 *   d_0220093C 0x0220093C data a4
 *   d_0220096C 0x0220096C data a4
 *   func_02030EAC 0x02030EAC arm
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_02200900 0x02200900 data a4
 *   d_0220099C 0x0220099C data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020419E4 0x020419E4 arm
 *   d_02200920      0x02200920  data
 *   func_0204A48C   0x0204A48C  arm
 *   func_0204B100   0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer   0x0204B270  arm
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_0207D4B0 0x0207D4B0 arm
 */
#include "../../matched/include/Obj24835.h"
#include "../../matched/include/Obj24836.h"

struct DispVram;
struct Node;
struct Bank;
struct Cfg;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct BgTemplate_021FC3BC { unsigned words[8]; } BgTemplate_021FC3BC;

typedef struct Record_021FC4FC {unsigned id;BgTemplate_021FC3BC template;unsigned type,enable;} Record_021FC4FC;

typedef struct DispConfig {unsigned words[4];} DispConfig;

typedef struct {u32 id;u8 rest[40];} Record_021FC55C;

typedef struct {u32 id;u8 rest[40];} Record;

typedef struct BgTemplate_021FC640 {unsigned words[8];} BgTemplate_021FC640;

extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned short);
extern void func_02082BCC(void *,int,int);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void func_020433E0(const struct DispVram *);
extern void func_0204363C(unsigned);
extern void func_0204361C(void),BG_SYS_ClearMainPlanes(void),BG_SYS_ClearSubPlanes(void),func_0201DD60(void);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(DispConfig *);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate_021FC3BC *tmpl, u32 type);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char,unsigned char);
extern void func_020419E4(void);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_020403F4(u32);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
void *func_021FC3BC(unsigned mode,int setting,unsigned heap);
void func_021FC474(char *p);
void func_021FC4C8(char *p);
u32 func_021FC4DC(u8*p);
void func_021FC4E8(int a0, char *p);
void func_021FC4FC(void *p,unsigned heap);
void func_021FC55C(void*p);
void func_021FC594(void *a0);
void func_021FC598(void *a0);
void func_021FC5A0(int *p, int b, int c);
void func_021FC5E0(void *p);
void func_021FC5FC(void *a0);
void func_021FC604(void *a0);
u32 func_021FC60C(u32*p);
void func_021FC610(u32 a, u16 b);
void func_021FC640(void);
extern const char d_02200D4C[];
extern const struct DispVram d_0220093C,d_0220096C;
extern const Record_021FC4FC d_0220099C[];
extern DispConfig d_02200900;
extern unsigned char d_02200920[];







/*
 * note: the mode switch has no default arm: the original 021FC3E8 branches
 *       to 021FC3F0 with r6 (config) never set for modes other than 0/1,
 *       which is what a default-less switch over an unset local compiles to
 *       (docs/idioms/switch-arms-tail-merge.md). A `default: config = 0`
 *       arm adds a `movs r4, #0` and shifts every register.
 * volatile: hardware DISPCNT read-modify-write at 021FC3FC..021FC40A; BLDCNT stores at 021FC3F4/021FC3FA.
 */
void *func_021FC3BC(unsigned mode,int setting,unsigned heap)
{
    const struct DispVram *config;
    char *p;
    p=func_02030734(heap,16,0,d_02200D4C,0x1d5);
    func_02082BCC(p,0,16);
    switch(mode){case 0:config=&d_0220093C;break;case 1:config=&d_0220096C;break;}
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    BG_SYS_ClearGraphicsMemory(0);func_020433E0(config);func_0204363C(setting);
    func_0204361C();BG_SYS_ClearMainPlanes();BG_SYS_ClearSubPlanes();func_0201DD60();
    func_021FC4FC(p,heap);
    func_021FC5A0((int *)(p+4),(int)config,heap);
    *(void **)(p+12)=func_020056A0((unsigned)func_021FC4E8,(unsigned)p,0);
    return p;
}







/*
 * volatile: hardware BLDCNT 04000050/04001050 and DISPCNT 04000000/04001000, read-modify-write at 021FC49A..021FC4A8.
 */
void func_021FC474(char *p)
{
    func_02030EAC(((struct Obj24835 *)p)->fC);
    func_021FC5E0(p+4);
    func_021FC55C(p);
    func_0201DD68();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    *(volatile unsigned *)0x04001000&=~0xe000;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}








void func_021FC4C8(char *p)
{
    func_021FC5FC(p + 4);
    func_021FC594(p);
}







u32 func_021FC4DC(u8*p){return func_021FC60C((u32 *)(p+4));}








void func_021FC4E8(int a0, char *p)
{
    func_021FC598(p);
    func_021FC604(p + 4);
}







void func_021FC4FC(void *p,unsigned heap)
{
    unsigned i;
    const Record_021FC4FC *r;
    unsigned id;
    func_02082BCC(p,0,4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(&d_02200900);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        func_0203FCA0((unsigned char)id,&r->template,(unsigned char)r->type);
        func_020414AC(id);
        func_02040588(id,r->enable);
    }
}







void func_021FC55C(void*p){u32 i;for(i=0;i<7;i++)func_020403F4((u8)d_0220099C[i].id);func_020450C8();func_0203F9B4();func_02082BCC(p,0,4);}








void func_021FC594(void *a0){}







void func_021FC598(void *a0){func_020419E4();}






void func_021FC5A0(int *p, int b, int c)
{
    func_02082BCC((void *)((int)p), 0, 4);
    func_0204A48C((const struct Cfg *)d_02200920, b, c);
    p[0] = (int)func_0204B100(0x80, 0, c);
    CLACT_SetUnitDefaultRenderer((void *)p[0]);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}





void func_021FC5E0(void *p)
{
    func_0204B1CC((struct Bank *)(((struct Obj24836 *)p)->f0));
    func_0204A5AC();
    func_02082BCC(p, 0, 4);
}




void func_021FC5FC(void *a0){func_0204A600();}




void func_021FC604(void *a0){func_0204A648();}




u32 func_021FC60C(u32*p){return *p;}


void func_021FC610(u32 a, u16 b){u32 i,id;for(i=0;i<7;i++){id=d_0220099C[i].id;if(id<4)func_020403F4((u8)id);}func_0207D4B0(1,0,1);}

/*
 * volatile: hardware BLDCNT 04000050 and DISPCNT 04000000, read-modify-write at 021FC64A..021FC650.
 */
void func_021FC640(void)
{
    unsigned i,id;
    const Record_021FC4FC *r;
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned *)0x04000000&=~0xe000;
    func_0207D4B0(1,0,0);
    for(i=0;i<7;i++){
        r=&d_0220099C[i];id=r->id;
        if(id<4){func_0203FCA0((unsigned char)id,&r->template,(unsigned char)r->type);func_020414AC(id);}
        func_02040588((unsigned char)id,(unsigned char)r->enable);
    }
}
