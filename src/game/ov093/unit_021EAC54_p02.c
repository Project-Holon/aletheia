/*
 * file:     unit_021EAC54_p02.c
 * unit:     yes
 * function: func_021EADB4, func_021EADC4, func_021EADD4, func_021EADE4
 * address:  0x021EADB4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EE2A0 0x021EE2A0 thumb ov093
 *   func_021EE2F8 0x021EE2F8 thumb ov093
 *   func_021EE318 0x021EE318 thumb ov093
 *   func_021EE370 0x021EE370 thumb ov093
 */
#include "../../matched/include/Obj21572.h"
#include "../../matched/include/Obj21573.h"
#include "../../matched/include/Obj21574.h"
#include "../../matched/include/Obj21575.h"

struct O;
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021EE2A0(struct O *);
extern void func_021EE2F8(struct O *);
extern int func_021EE318(struct O *);
extern void func_021EE370(struct O *);
int func_021EADB4(u8 *p);
void func_021EADC4(u8 *p);
int func_021EADD4(u8 *p);
void func_021EADE4(u8 *p);

int func_021EADB4(u8 *p)
{
    return func_021EE2A0(*(struct O * *)&((struct Obj21572 *)p)->f17C);
}

void func_021EADC4(u8 *p)
{
    func_021EE2F8(*(struct O * *)&((struct Obj21573 *)p)->f17C);
}

int func_021EADD4(u8 *p)
{
    return func_021EE318(*(struct O * *)&((struct Obj21574 *)p)->f17C);
}

void func_021EADE4(u8 *p)
{
    func_021EE370(*(struct O * *)&((struct Obj21575 *)p)->f17C);
}
