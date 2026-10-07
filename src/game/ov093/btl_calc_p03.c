/*
 * file:     btl_calc_p03.c
 * unit:     yes
 * function: func_021D7090, func_021D7098, func_021D70A8, func_021D70AC, func_021D70B4, func_021D70BC, func_021D70C8
 * address:  0x021D7090
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../../matched/include/Obj21247.h"
#include "../../matched/include/Obj21249.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

/* 021D70A8  ldrh r0,[r0,#0x38] */
struct QQ { u8 pad[0x38]; u16 v; };

/* 021D70BC  movs r1,#1; ldr r2,[r0,#0x18]; lsls r1,#0x1a; orrs r1,r2;
 *           str r1,[r0,#0x18] */
struct QR { u8 pad[0x18]; u32 v; };

typedef struct { u32 pad[6]; u32 low:24, active:1, rest:7; } Node;

void func_021D7090(u8 *p);
int func_021D7098(u8 *p);
u16 func_021D70A8(struct QQ *p);
unsigned char func_021D70AC(unsigned char *p);
/* 021D70B4 lsls r1,#2; adds r0,r0,r1; ldr r0,[r0,#0x1c] */ u32 func_021D70B4(u8 *p, int i);
void func_021D70BC(struct QR *p);
void func_021D70C8(Node *p);


/*
 * store constant 0x6 at #0x10
 */
void func_021D7090(u8 *p)
{
    *(u32 *)&p[0x10] = 0x6;
}

int func_021D7098(u8 *p)
{
    if (((struct Obj21247 *)p)->f10 == 6) return 1;
    return 0;
}

/*
 * Reads the u16 field at #0x38 of the argument and returns it.
 */
u16 func_021D70A8(struct QQ *p) { return p->v; }

unsigned char func_021D70AC(unsigned char *p)
{
    return p[0x3b];
}


/* 021D70B4  lsls r1,#2; adds r0,r0,r1; ldr r0,[r0,#0x1c] */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: lsls r1, r1, #2; adds r0, r0, r1; ldr r0, [r0, #0x1c]; bx lr.
 */
u32 func_021D70B4(u8 *p, int i) { return *(u32 *)(p + i * 4 + 0x1c); }

void func_021D70BC(struct QR *p) { p->v |= 1 << 26; }

void func_021D70C8(Node *p)
{
    if (p->active) ((struct Obj21249 *)p)->f18 |= 0x10000000;
}
