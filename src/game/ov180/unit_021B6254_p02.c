/*
 * file:     unit_021B6254_p02.c
 * unit:     yes
 * function: func_021B6418, func_021B6474, func_021B64AC, func_021B64D0
 * address:  0x021B6418
 * region:   ov180
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   d_021B8018 0x021B8018 data a4
 *   func_02005A98 0x02005A98 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005B04 0x02005B04 thumb
 */
#include "../../matched/include/Obj02515.h"
#include "../../matched/include/Obj05469.h"

struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct U16Vec;
struct Sub02005A98Hdr;
typedef unsigned int   u32;

typedef unsigned short u16;

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_020457B0(unsigned,unsigned);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern struct Sub02005A98Hdr *func_02005A98(const u32 *,u32);
extern void func_02005D90(u32,u32);
extern void func_02005B04(const u32 *arg);
void func_021B6418(char *p);
void func_021B6474(char *p);
void func_021B64AC(char *p);
void func_021B64D0(char *p);
extern const u32 d_021B8018[];

void func_021B6418(char *p) {
 ((struct Obj02515 *)p)->f9038=func_02045B38(0,2,32,141);
 ((struct Obj02515 *)p)->f9030=func_0201D7EC(23,0,0,0,141);
 ((struct Obj02515 *)p)->f9034=func_0201D7EC(23,3,0,0,141);
 ((struct Obj02515 *)p)->f903C=func_0201EC64(141);
 ((struct Obj02515 *)p)->f9040=func_020457B0(1024,141);
}

void func_021B6474(char *p) {func_02045808(((struct Obj05469 *)p)->f9040);func_0201ED04(*(struct WordSet * *)&((struct Obj05469 *)p)->f903C);func_0201D83C(((struct Obj05469 *)p)->f9034);func_0201D83C(((struct Obj05469 *)p)->f9030);func_02045C04(*(struct Rec * *)&((struct Obj05469 *)p)->f9038);}

void func_021B64AC(char *p) {*(struct Sub02005A98Hdr * *)&((struct Obj02515 *)p)->fC=func_02005A98(d_021B8018,1);func_02005D90(1015,65535);}

void func_021B64D0(char *p) {func_02005B04(((struct Obj05469 *)p)->fC);}
