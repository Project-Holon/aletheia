/*
 * file:     guru2_main_p13.c
 * unit:     yes
 * function: func_021E0640, func_021E0678
 * address:  0x021E0640
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
 *   func_02047E88 0x02047E88 arm
 *   func_0207DD24 0x0207DD24 arm
 *   d_021E1D80 0x021E1D80 data a4
 *   func_020480E4 0x020480E4 arm
 */
#include "../../matched/include/Obj02208.h"
#include "../../matched/include/Obj14234.h"

struct Descriptor;
struct Cfg;
struct CharBuf;
struct Bank;
struct Util;
struct Setup;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern u16 func_02047E88(struct Util *,const struct Setup *);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_020480E4(struct Ctx *c, u32 i);
void func_021E0640(u8 *p);
void func_021E0678(char *p);
extern const struct Setup d_021E1D80;

void func_021E0640(u8 *p){((struct Obj02208 *)p)->fDA4=func_02047E88(*(struct Util * *)&((struct Obj02208 *)p)->fAF4,&d_021E1D80);func_0207DD24(0,0,32767,0,0);}

/*
 * note: original narrows the second call argument with lsls/lsrs #16 at 021E0682/021E0686, so this caller's extern uses u16.
 */
void func_021E0678(char *p) { func_020480E4(*(struct Ctx * *)&((struct Obj14234 *)p)->fAF4,(u16)(((struct Obj14234 *)p)->fDA4)); }
