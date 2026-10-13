/*
 * file:     unit_021797C0.c
 * unit:     yes
 * function: func_021797C0, func_021797E0, func_021797EC, func_021797FC
 * address:  0x021797C0
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   func_0217993C  0x0217993C  thumb  ov015
 *   func_021799CC  0x021799CC  thumb  ov015
 *   func_02179FC4  0x02179FC4  arm
 *   func_02179AAC 0x02179AAC thumb ov015
 *   func_02179998 0x02179998 thumb ov015
 *   func_021799F0 0x021799F0 thumb ov015
 */
typedef unsigned int   u32;

typedef unsigned char  u8;

struct s67 { char pad[0x67]; unsigned char f67; };

struct s68 { char pad[0x68]; int f68; };

extern void *GFL_NET_GetInitParam(void);
extern void func_0217993C(u32 a, u8 b);
extern void  func_021799CC(void);
void func_02179FC4(void);
extern void func_02179AAC(void);
extern void func_02179998(void);
extern unsigned char func_021799F0(void);
int func_021797C0(void);
int func_021797E0(void);
int func_021797EC(void);
int func_021797F8(void);
int func_021797FC(void);
unsigned char func_02179808(void);


int func_021797C0(void)
{
    struct s67 *a = (struct s67 *)GFL_NET_GetInitParam();
    struct s68 *b = (struct s68 *)GFL_NET_GetInitParam();

    func_0217993C(b->f68, a->f67);
    func_021799CC();
    return 1;
}


int func_021797E0(void)
{
    func_02179FC4();
    return 1;
}

/*
 * extent: includes constant-return follower 021797F8; root claimed.
 */
int func_021797EC(void) { func_02179AAC(); return 0; }

int func_021797F8(void) { return 1; }

/*
 * extent: includes tail getter follower 02179808; root claimed.
 */
int func_021797FC(void) { func_02179998(); return 1; }

unsigned char func_02179808(void) { return func_021799F0(); }
