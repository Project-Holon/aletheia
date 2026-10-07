/*
 * file:     unit_021BC240_p02.c
 * unit:     yes
 * function: func_021BC2BC, func_021BC2E4, func_021BC2FC
 * address:  0x021BC2BC
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 *   func_02005624 0x02005624 thumb
 *   func_021BC308 0x021BC308 thumb ov209
 *   func_02030EAC 0x02030EAC arm
 */
#include "../../matched/include/Obj25534.h"
#include "../../matched/include/Obj25535.h"
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj25536.h"

struct S02021D50;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void func_020419E4(void),func_0204A648(void);
extern void func_02021D50(struct S02021D50 *);
extern void *func_02005624(unsigned,unsigned,unsigned);
extern void func_021BC308(void);
extern void func_02030EAC(struct Node *n);
void func_021BC2BC(void *unused,char *p);
void func_021BC2E4(char *p);
void func_021BC2FC(char *p);

/*
 * lever: enum-typed DTCM base preserves the base-first two-pool address; constant addition folds and enum offset reverses pool/register roles.
 * volatile: hardware interrupt check flag at 02FE3FF8 read and written by 021BC2D4/021BC2D8.
 */
void func_021BC2BC(void *unused,char *p){enum Base { DTCM_BASE=0x02fe0000 } base;func_020419E4();func_0204A648();func_02021D50(*(struct S02021D50 * *)&((struct Obj25534 *)p)->fC);base=DTCM_BASE;*(volatile unsigned *)&((struct Obj25535 *)base)->f3FF8|=1;}

void func_021BC2E4(char *p){((struct Obj00123 *)p)->f8=func_02005624((unsigned)func_021BC308,(unsigned)p,0);}

void func_021BC2FC(char *p)
{
    func_02030EAC(((struct Obj25536 *)p)->f8);
}
