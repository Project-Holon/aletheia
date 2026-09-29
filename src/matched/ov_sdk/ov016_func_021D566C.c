/*
 * function: func_021D566C
 * address:  0x021D566C
 * packet:   pkt_ov016_021D566C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskFade (libdwcutil.TWL.HYB.a(effect.o))
 *
 * symbols:
 *   func_0207C958 0x0207C958 arm
 *   func_0207D6C0 0x0207D6C0 arm
 *   func_021D7724 0x021D7724 arm ov016
 *   g_021DAA68 0x021DAA68 data
 *   g_021DAA64 0x021DAA64 data
 *   g_021DE67C 0x021DE67C data
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;

typedef struct {
    char pad0[4];
    s16 count;
    u16 max;
    u8 index;
    u8 active;
} Prm;

typedef struct { u8 b[4]; } U4;
typedef struct { s8 b[4]; } S4;

extern U4 g_021DAA68;
extern S4 g_021DAA64;
extern Prm *g_021DE67C;

extern long func_0207C958(long a, long b);
extern void func_0207D6C0(u32 addr, int brightness);
extern void func_021D7724(int kind, void *task);

void func_021D566C(void *task, void *work)
{
    U4 TABLE = g_021DAA68;
    S4 BRIGHT = g_021DAA64;
    Prm *prm = (Prm *)work;
    int value;

    prm->count++;
    value = func_0207C958(prm->count * 16, prm->max);
    if (TABLE.b[prm->index] & 1)
        value = 16 - value;
    if (TABLE.b[prm->index] & 0x10)
        value = -value;
    if (prm == g_021DE67C)
        func_0207D6C0(0x04001050, value);
    else
        func_0207D6C0(0x04000050, value);
    if (prm->count < prm->max)
        return;
    if (prm == g_021DE67C)
        func_0207D6C0(0x04001050, BRIGHT.b[prm->index]);
    else
        func_0207D6C0(0x04000050, BRIGHT.b[prm->index]);
    prm->active = 0;
    func_021D7724(1, task);
}
