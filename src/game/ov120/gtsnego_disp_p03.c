/*
 * file:     gtsnego_disp_p03.c
 * unit:     yes
 * function: func_021D4584, func_021D4608, func_021D46A4
 * address:  0x021D4584
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203CD98 0x0203CD98 arm
 *   func_021D880C 0x021D880C thumb ov120
 *   func_021D74B0 0x021D74B0 thumb ov120
 *   func_021D4244 0x021D4244 thumb ov120
 *   func_021D4544 0x021D4544 thumb ov120
 *   func_0217BC90 0x0217BC90 arm ov009
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045808 0x02045808 arm
 *   func_02039338 0x02039338 arm
 *   func_0200ED48 0x0200ED48 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02008510 0x02008510 thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_02045A90 0x02045A90 arm
 *   func_020458F8 0x020458F8 arm
 *   func_02045A98 0x02045A98 arm
 *   func_0217BC44 0x0217BC44 arm ov009
 */
#include "../../matched/include/Obj04484.h"
#include "../../matched/include/Obj06433.h"
#include "../../matched/include/Obj08076.h"
#include "../../matched/include/Obj22823.h"
#include "../../matched/include/Obj05341.h"
#include "../../matched/include/Obj22824.h"

struct Sub0200852CObj;
struct MsgBank;
struct Rec;
struct U16Vec;
struct L0200ED54;
struct Rec44;
struct Sub24;
struct Entry;
struct Link;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern int func_0203CD98(void);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern void func_021D880C(char *p, void *q, u32 n);
extern void func_021D74B0(u8 *p, int n);
extern void func_021D4244(int *p, int v, int a2);
extern void func_021D4544(int *a);
extern int func_0217BC90(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern void func_020084E4(u16 *out, struct U16Vec *vec);
extern u16 func_02039338(void);
extern struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
extern void func_02008494(void *src, void *dst);
extern void *func_0200ED48(void *p);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern struct Entry *func_020399A8(void);
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
extern void *func_02008510(void *, int);
extern void func_02082BCC(void *, u8, u32);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u16 func_020458F8(struct U16Vec *vec);
extern u16 func_02045A98(void);
extern int func_0217BC44(u16 **, int, char *, int, char *, int *, int);
void func_021D4584(u8 *p);
void func_021D4608(u8 *p);
void func_021D46A4(u8 *p);

void func_021D4584(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj06433 *)p)->f48;
    int value;
    int mode = 2;
    if (func_0203CD98() == 0) {
        value = (int)func_02012944((void *)(((struct Obj04484 *)q)->f0));
    } else {
        value = ((struct Obj04484 *)q)->f18;
        mode = ((struct Obj06433 *)p)->f17C;
        *(int *)(q + ((struct Obj04484 *)q)->f1AC * 4 + 0x1c) = func_02008530((const struct Sub0200852CObj *)value);
        ((struct Obj04484 *)q)->f1AC = ((struct Obj04484 *)q)->f1AC + 1;
        if (((struct Obj04484 *)q)->f1AC >= 100)
            ((struct Obj04484 *)q)->f1AC = 0;
    }
    func_021D880C((char *)(((struct Obj06433 *)p)->f40), (void *)value, mode);
    func_021D74B0((u8 *)(((struct Obj06433 *)p)->f3C), func_02008554((const struct Sub0200852CObj *)value));
    ((struct Obj06433 *)p)->f14 = 0xb4;
    func_021D4244((int *)p, (int)func_021D4544, 0x265);
}

void func_021D4608(u8 *p)
{
    int ready = 0;
    int value = ((struct Obj22823 *)(*(u8 * *)&((struct Obj08076 *)p)->f48))->f18;
    int active;
    void *message;
    void *text;
    int result;
    active = func_0217BC90() == 2;
    if (active)
        ready = ((struct Obj08076 *)p)->f1A8 > 0;
    if (active) {
        if (ready) {
            message = func_02045B38(0, 2, 0x51, 0x1f);
            text = func_02045EC0(message, 15);
            func_02045C04(message);
            func_020084E4((u16 *)value, text);
            func_02045808(text);
        }
        func_02008494((void *)value, func_02012950((struct Sub24 *)(((struct Obj08076 *)p)->f2C), 1 - func_02039338()));
        result = func_02008530((const struct Sub0200852CObj *)value);
        func_0200ED54(func_0200ED48((void *)(((struct Obj08076 *)p)->f30)), result);
        func_021D4244((int *)p, (int)((void (*)(int))func_021D4584), 0x283);
    }
}

/*
 * evidence: 020399A8's r0 is consumed by 02039CB4 despite its void definition.
 * evidence: 020458F8 returns ldrh r0; this caller uses full-word r0+1 without narrowing.
 */
void func_021D46A4(u8 *p)
{
    void *str;
    u16 *chars;
    u32 i;
    void *value = ((struct Obj22824 *)(*(u8 * *)&((struct Obj05341 *)p)->f48))->f18;
    if (func_02039CB4((struct Link *)func_020399A8(), 3, 0x22) != 0) {
        str = func_02008510(value, 31);
        func_02082BCC(p + 0x188, 0, 40);
        ((struct Obj05341 *)p)->f1AC = 31;
        chars = func_02045A90(str);
        for (i = 0; i < func_020458F8(str) + 1u; i++) {
            u16 c = chars[i];
            if (c == func_02045A98()) ((u16 *)(p + 0x188))[i] = 0;
            else ((u16 *)(p + 0x188))[i] = c;
        }
        ((struct Obj05341 *)p)->f1A0 = p + 0x188;
        ((struct Obj05341 *)p)->f1A8 = 0;
        func_0217BC44((u16 **)(p + 0x1a0), 1, 0, 0, (char *)(p + 0x1a4), (int *)(p + 0x1a8), 128);
        func_02045808(str);
        func_021D4244((int *)p, (int)func_021D4608, 0x29c);
    }
}
