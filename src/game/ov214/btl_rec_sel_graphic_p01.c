/*
 * file:     btl_rec_sel_graphic_p01.c
 * unit:     yes
 * function: func_021BB178, func_021BB220, func_021BB27C, func_021BB290
 * address:  0x021BB178
 * region:   ov214
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
 *   func_0204335C 0x0204335C arm
 *   func_020433E0 0x020433E0 arm
 *   func_0204363C 0x0204363C arm
 *   func_0204361C 0x0204361C arm
 *   func_020434CC 0x020434CC arm
 *   func_02043588 0x02043588 arm
 *   func_0201DD60 0x0201DD60 thumb
 *   func_021BB2C8 0x021BB2C8 thumb ov214
 *   func_021BB36C 0x021BB36C thumb ov214
 *   func_021BB3DC 0x021BB3DC thumb ov214
 *   func_021BB2B4 0x021BB2B4 thumb ov214
 *   func_020056A0 0x020056A0 thumb
 *   site 0x021BB668 data ov214
 *   config 0x021BB588 data ov214
 *   func_02030EAC 0x02030EAC arm
 *   func_021BB448 0x021BB448 thumb ov214
 *   func_021BB3AC 0x021BB3AC thumb ov214
 *   func_021BB328 0x021BB328 thumb ov214
 *   func_0201DD68 0x0201DD68 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021BB3C8 0x021BB3C8 thumb ov214
 *   func_021BB360 0x021BB360 thumb ov214
 *   func_021BB458 0x021BB458 thumb ov214
 */
#include "../../matched/include/Obj25730.h"
#include "../../matched/include/Obj25731.h"

struct DispVram;
struct Node;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,u32,u32);
extern void func_0204335C(u32);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204363C(u32);
extern void func_0204361C(void);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0201DD60(void);
extern void func_021BB2C8(void *,u32);
extern void func_021BB36C(unsigned char *,int,int);
extern void func_021BB3DC(u32 **,u32);
extern void func_021BB2B4(void *unused, u8 *p);
extern u32 func_020056A0(void (*)(void *),void *,u32);
extern void func_02030EAC(struct Node *n);
extern void func_021BB448(int *);
extern void func_021BB3AC(void *);
extern void func_021BB328(void *);
extern void func_0201DD68(void);
extern u32 func_020307B0(void *p);
extern void func_021BB3C8(void *),func_021BB360(void *);
extern void func_021BB458(u32 *);
char *func_021BB178(u32 a,u32 heap);
void func_021BB220(char *p);
void func_021BB27C(u8 *p);
void func_021BB290(u8 *p);
extern const char site[];
extern const u32 config[];

/*
 * volatile: MMIO accesses 021BB19E..021BB1B2
 */
char *func_021BB178(u32 a,u32 heap)
{
    char *p=func_02030734(heap,16,0,site,458);
    func_02082BCC(p,0,16);
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0204335C(0);
    func_020433E0((const struct DispVram *)config);
    func_0204363C(a);
    func_0204361C();
    func_020434CC();
    func_02043588();
    func_0201DD60();
    func_021BB2C8(p,heap);
    func_021BB36C((unsigned char *)p+4,(int)config,heap);
    func_021BB3DC((u32 **)(p+8),heap);
    ((struct Obj25730 *)p)->fC=func_020056A0((void (*)(void *))func_021BB2B4,p,0);
    return p;
}

void func_021BB220(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj25731 *)p)->fC));
    func_021BB448((int *)(p+8));
    func_021BB3AC(p+4);
    func_021BB328(p);
    func_0201DD68();
    *(volatile u16 *)0x04000050=0;
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_02082BCC(p,0,16);
    func_020307B0(p);
}

void func_021BB27C(u8 *p) { func_021BB3C8(p+4);func_021BB360(p); }

void func_021BB290(u8 *p) { func_021BB458((u32 *)(p+8)); }
