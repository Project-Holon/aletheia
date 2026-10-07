/*
 * file:     demo3d_graphic_p03.c
 * unit:     yes
 * function: func_021BE0C4, func_021BE0E0, func_021BE0E8, func_021BE0F0, func_021BE0F4, func_021BE12C
 * address:  0x021BE0C4
 * region:   ov203
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02046440 0x02046440 arm
 *   func_02048BC4 0x02048BC4 arm
 *   func_02048C58 0x02048C58 arm
 *   func_021BDD40 0x021BDD40 thumb ov203
 *   d_021BFB48 0x021BFB48 data a4
 *   func_02048C4C 0x02048C4C arm
 *   func_02046788 0x02046788 arm
 */
#include "../../matched/include/Obj25312.h"
#include "../../matched/include/Obj25313.h"

struct Bank;
struct Owner;
struct TcblNode;
struct LightSet;
struct LightSlot;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Config {unsigned words[11];} Config;

typedef signed short s16;

extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(int);
extern void func_02082BCC(void *, int, int);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_02046440(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize,
                          u16 fifoSize, s16 heap, void (*setup)(void));
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_021BDD40(void);
extern int func_02048C4C(int);
extern void func_02046788(int);
void func_021BE0C4(char *a);
void func_021BE0E0(void *a0);
void func_021BE0E8(u8 *a0);
int func_021BE0F0(void *p);
void func_021BE0F4(char *p, u8 heap);
void func_021BE12C(int *p);
extern const struct LightSet d_021BFB48;


void func_021BE0C4(char *a)
{
    func_0204A5AC(func_0204B1CC((struct Bank *)(((struct Obj25312 *)a)->f0)));
    func_02082BCC(a, 0, 4);
}

void func_021BE0E0(void *a0){func_0204A600();}

void func_021BE0E8(u8 *a0) { func_0204A648(); }


int func_021BE0F0(void *p){return ((struct Obj25313 *)p)->f0;}

/*
 * lever: twin of ov204_func_021BE03C.c (3D setup, texSize 2, plttSize 4,
 * light set 0x021BFB48); u8 heap parameter.
 */
void func_021BE0F4(char *p, u8 heap)
{
    func_02046440(0, 2, 0, 4, 0, heap, func_021BDD40);
    *(struct LightSlot **)(p + 4) = func_02048BC4(&d_021BFB48, heap);
    func_02048C58(*(struct LightSlot **)(p + 4));
}


void func_021BE12C(int *p)
{
    func_02046788(func_02048C4C(p[1]));
}
