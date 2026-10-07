/*
 * file:     union_oneself_p11.c
 * unit:     yes
 * function: func_0217F8EC, func_0217F914, func_0217F928, func_0217F93C
 * address:  0x0217F8EC
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217FCE4 0x0217FCE4 thumb ov019
 *   func_0217FBD0 0x0217FBD0 thumb ov019
 *   func_0217FABC 0x0217FABC thumb ov019
 *   func_0217F9BC 0x0217F9BC thumb ov019
 *   func_020307B0 0x020307B0 arm
 *   func_0217FD04 0x0217FD04 thumb ov019
 *   func_0217FACC 0x0217FACC thumb ov019
 *   func_0217FD38 0x0217FD38 thumb ov019
 *   func_0217FAF0 0x0217FAF0 thumb ov019
 *   func_0217F9DC  0x0217F9DC  thumb ov019
 */
struct E;
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_0217FCE4(struct E *p);
extern void func_0217FBD0(char *p);
extern void func_0217FABC(u32 *p);
extern void func_0217F9BC(char *p);
extern u32 func_020307B0(void *p);
extern void func_0217FD04(struct E *p);
extern void func_0217FACC(u32 *p);
extern void func_0217FD38(struct E *p);
extern void func_0217FAF0(u32 *p);
void func_0217F9DC(char *p, u32 a);
void func_0217F8EC(char *p);
void func_0217F914(char *p);
void func_0217F928(char *p);
void func_0217F93C(int x, int y);

void func_0217F8EC(char *p) { if(p) { func_0217FCE4((struct E *)(p+0x20)); func_0217FBD0(p+0x20); func_0217FABC((u32 *)p); func_0217F9BC(p); func_020307B0(p); } }

void func_0217F914(char *p) { if(p) { func_0217FD04((struct E *)(p+0x20)); func_0217FACC((u32 *)p); } }

void func_0217F928(char *p) { if(p) { func_0217FD38((struct E *)(p+0x20)); func_0217FAF0((u32 *)p); } }


void func_0217F93C(int x, int y)
{
    if (x != 0)
        func_0217F9DC((char *)x, y);
}
