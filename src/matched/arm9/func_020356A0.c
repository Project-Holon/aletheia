/*
 * unit:     no
 * function: UI_ApplyInputBounds
 * address:  0x020356A0
 * packet:   pkt_020356A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUiState     0x021469BC  data
 *   KEY_SetTrg  0x020363B8  arm
 *   KEY_SetCont  0x020363D4  arm
 *   KEY_SetRepeat  0x020363F0  arm
 *   TOUCHPANEL_SetPoint  0x02035E84  arm
 *   TOUCHPANEL_SetTrg  0x02035EB0  arm
 *   TOUCHPANEL_SetCont  0x02035ECC  arm
 *
 * A descriptor fan-out: the global at 0x021469BC carries a callback at +4
 * which fills two twelve-byte records on the stack, and the seven
 * accessors below push each pair into the object in a0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f00;
    u16 f02;
    u16 f04;
    u16 f06;
    u16 f08;
    u8  f0A;
    u8  f0B;
} S12;

typedef struct {
    u32 f00;
    int (*f04)(S12 *dst, S12 *src);
} Desc;

extern Desc gUiState;
extern int KEY_SetTrg(int a0, int a1, int a2);
extern int KEY_SetCont(int a0, int a1, int a2);
extern int KEY_SetRepeat(int a0, int a1, int a2);
extern void TOUCHPANEL_SetPoint(void *p, u16 a, u16 b, u16 c, u16 d);
extern int TOUCHPANEL_SetTrg(int a0, int a1, int a2);
extern int TOUCHPANEL_SetCont(int a0, int a1, int a2);

void UI_ApplyInputBounds(int a0)
{
    S12 b;
    S12 a;

    if (gUiState.f04 == 0) {
        return;
    }
    if (gUiState.f04(&b, &a) == 0) {
        return;
    }
    KEY_SetTrg(a0, b.f00, a.f00);
    KEY_SetCont(a0, b.f02, a.f02);
    KEY_SetRepeat(a0, b.f04, a.f04);
    TOUCHPANEL_SetPoint((void *)a0, b.f06, b.f08, a.f06, a.f08);
    TOUCHPANEL_SetTrg(a0, b.f0A, a.f0A);
    TOUCHPANEL_SetCont(a0, b.f0B, a.f0B);
}
