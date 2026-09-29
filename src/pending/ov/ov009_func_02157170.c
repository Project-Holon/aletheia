/*
 * function: func_02157170
 * address:  0x02157170
 * packet:   pkt_ov009_02157170
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker: every concrete byte matches (MATCH*, 270 of 272, the tail is
 * padding); the three THM_CALL sites to func_0200FB4C stay wildcarded
 * because 0x0200FB4C is an unlabelled arm9 Thumb leaf (it prints as .word
 * data after func_0200FB38), so no class attests it. The leaf verifies
 * EXACT (literal x2) as pkt_0200FB4C / src/matched/arm9/func_0200FB4C.c
 * with this body, outside this lane's write set:
 *
 *   typedef struct State { u8 pad00[0x2C]; int f2C; u8 pad30[0x29];
 *                          u8 f59; u8 f5A; u8 pad5B[5]; int f60; } State;
 *   extern State g_0214617C;           symbols: 0x0214617C data a4
 *   void func_0200FB4C(int x)
 *   {
 *       if (g_0214617C.f2C != 2) {
 *           g_0214617C.f60 = x;
 *           g_0214617C.f5A = 1;
 *           g_0214617C.f59 = 1;
 *           g_0214617C.f2C = 2;
 *       }
 *   }
 *
 * Filing that leaf makes this file (and ov135 func_022010BC) EXACT.
 *
 * symbols:
 *   func_0203CD98  0x0203CD98  arm
 *   func_0203CA98  0x0203CA98  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02157160  0x02157160  thumb  ov009
 *   func_0200F83C  0x0200F83C  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_02059F18  0x02059F18  arm
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200FB4C  0x0200FB4C  thumb
 *   func_0200F7C0  0x0200F7C0  thumb
 *   func_0200FAAC  0x0200FAAC  thumb
 *   func_0203C554  0x0203C554  arm
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 */

typedef struct Status {
    int f0;
    int f4;
    int f8;
    int fC;
} Status;

extern int func_0203CD98(void);
extern Status *func_0203CA98(void);
extern int func_0200FB24(void);
extern void func_02157160(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_02059F18(void);
extern void func_0200FB38(void);
extern void func_0200FB4C(int);
extern void func_0200F7C0(int);
extern void func_0200FAAC(void);
extern void func_0203C554(int);
extern void func_0203CA04(void);
extern void func_0203C968(void);

int func_02157170(int a0, int a1)
{
    Status *st;
    int v;

    if (func_0203CD98() != 0) {
        st = func_0203CA98();
        if (func_0200FB24() != 0) {
            switch (st->f4) {
            case 0:
                break;
            case 1:
            case 2:
                if (a0 == 0) {
                    func_02157160();
                    func_0200F83C();
                    func_0200FBA0();
                    return 1;
                }
                func_02059F18();
            case 3:
            case 4:
            case 5:
                func_0200FB38();
                func_0200FB4C(13);
                return 2;
            case 6:
                func_0200FB38();
                return 2;
            case 7:
                func_0200F7C0(15);
                return 3;
            }
        }
        v = st->fC;
        if (v == 0x3F0 || v == 0x3F1) {
            if (a1 != 0) {
                func_0200FAAC();
                func_02157160();
                func_0203C554(1);
                func_0200F83C();
                func_0200FBA0();
                return 4;
            }
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            func_0203C554(1);
            return 0;
        }
        if (v == 0x3F2 || v == 0x3F3 || v == 0x3F4 || v == 0x3F6) {
            if (a0 == 0) {
                func_02157160();
                func_0200F83C();
                func_0200FBA0();
                return 1;
            }
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
        if (v == 0x3EE || v == 0x3F7) {
            func_0200FB38();
            func_0200FB4C(13);
            return 2;
        }
    }
    return 0;
}
