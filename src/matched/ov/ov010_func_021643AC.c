/*
 * function: func_021643AC
 * address: 0x021643AC
 * packet: pkt_ov010_021643AC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: func_02188C9C reads the u16 field at +0xD8;
 * func_0215E428 forwards its second argument to func_0200D45C,
 * whose matched ARM9 body takes u16 and stores only that halfword.
 * The legacy ov010_func_021643E8 declaration uses a pointer for this ID.
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200D418 0x0200D418 thumb
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0215E428 0x0215E428 thumb ov010
 *   func_0215E3A0 0x0215E3A0 thumb ov010
 *   func_0201296C 0x0201296C thumb
 *   func_0201433C 0x0201433C thumb
 *   func_0215E33C 0x0215E33C thumb ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200D418(void *);
extern u16 func_02188C9C(u8 *p);
typedef unsigned int   u32;
struct BigObj;
extern void func_0215E428(int a0, int a1);
extern void func_0215E3A0(void *);
extern u32 func_0201296C(const struct BigObj *p);
extern void func_0201433C(char *, int);
extern int func_0215E33C(int a0);
void func_021643AC(void *a, void *b) { void *p=func_0200D418(func_02012EBC(a)); func_0215E428((int)p,func_02188C9C(b)); func_0215E3A0(a); func_0201433C((char *)func_0201296C(a),0x964); func_0215E33C((int)b); }
