/*
 * function: func_021EFFB0
 * address:  0x021EFFB0
 * packet:   pkt_ov107_021EFFB0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021F1060  0x021F1060  thumb  ov107
 *   func_02012FFC  0x02012FFC  thumb
 *   func_021F1704  0x021F1704  thumb  ov107
 *   func_021F1B24  0x021F1B24  thumb  ov107
 *   func_021F1028  0x021F1028  thumb  ov107
 *   func_021F1110  0x021F1110  thumb  ov107
 *   func_021F1118  0x021F1118  thumb  ov107
 *   func_021F1120  0x021F1120  thumb  ov107
 *   func_021F1134  0x021F1134  thumb  ov107
 *   func_021F1148  0x021F1148  thumb  ov107
 *   func_021F115C  0x021F115C  thumb  ov107
 *   func_021F1164  0x021F1164  thumb  ov107
 *   func_021F116C  0x021F116C  thumb  ov107
 *   func_021F11BC  0x021F11BC  thumb  ov107
 *   func_021F1898  0x021F1898  thumb  ov107
 *   func_021F1628  0x021F1628  thumb  ov107
 *   func_021F18D8  0x021F18D8  thumb  ov107
 *   func_021F1900  0x021F1900  thumb  ov107
 *   func_021F18EC  0x021F18EC  thumb  ov107
 *   func_021F1B14  0x021F1B14  thumb  ov107
 *   func_021F19E4  0x021F19E4  thumb  ov107
 *   func_021F1A2C  0x021F1A2C  thumb  ov107
 *   func_0201293C  0x0201293C  thumb
 *   func_02007774  0x02007774  thumb
 *   func_021F1A24  0x021F1A24  thumb  ov107
 *   func_021F11F0  0x021F11F0  thumb  ov107
 *   func_021F17E0  0x021F17E0  thumb  ov107
 *   func_021F1B38  0x021F1B38  thumb  ov107
 *   func_021EFD98  0x021EFD98  thumb  ov107
 *   func_021F1184  0x021F1184  thumb  ov107
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0216BF9C  0x0216BF9C  thumb  ov010
 *   func_0216BF74  0x0216BF74  thumb  ov010
 *   func_02007E50  0x02007E50  thumb
 */

typedef struct {
    int f00;
    void *f04;
} Ov107Save;

typedef struct {
    unsigned short f00;
    unsigned char pad02[6];
    Ov107Save *f08;
    void *f0C;
    unsigned char pad10[0x10];
    int f20;
    unsigned char pad24;
    unsigned char state;
    unsigned char pad26[0xE];
    int f34;
    unsigned char pad38[8];
    int f40;
    int f44;
    int f48;
    unsigned char pad4C[0x1C];
    void *f68;
} Ov107Main;

int func_021F1060(void *);
int func_02012FFC(void);
void func_021F1704(void *, int, int);
void func_021F1B24(void *, int);
void func_021F1028(void *);
int func_021F1110(void *);
int func_021F1118(void *);
int func_021F1120(void *);
int func_021F1134(void *);
int func_021F1148(void *);
int func_021F115C(void *);
int func_021F1164(void *);
int func_021F116C(void *);
int func_021F11BC(void *);
void func_021F1898(void *);
void func_021F1628(void *, int);
void func_021F18D8(void *);
void func_021F1900(void *, int, int, int);
void func_021F18EC(void *);
int func_021F1B14(void *);
void func_021F19E4(void *, int);
int func_021F1A2C(void *);
void *func_0201293C(void *);
int func_02007774(void *);
void func_021F1A24(void *);
int func_021F11F0(void *, int, int);
void func_021F17E0(void *, int);
void func_021F1B38(void *, int);
void func_021EFD98(Ov107Main *);
void func_021F1184(void *);
void *func_0201292C(void *);
void *func_02012944(void *);
void *func_02012F08(void *);
int func_0216BF9C(void *, int, void *);
void func_0216BF74(void *, int, void *);
void func_02007E50(void *, int, int, int);

void func_021EFFB0(Ov107Main *p)
{
    int a;
    int b;
    void *c;
    void *d;
    void *e;

    switch (p->state) {
    case 0:
        if (func_021F1060(p->f0C) == 10 || func_021F1060(p->f0C) == 12) {
            func_021F1704(p->f68, 0x29, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F1028(p->f0C);
            p->f20 = 0x1B;
        }
        if (func_021F1060(p->f0C) == 11) {
            func_021F1704(p->f68, 0x2C, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F1028(p->f0C);
            p->f20 = 0x1B;
        }
        if (func_021F1110(p->f0C) == 1) {
            a = func_021F1118(p->f0C);
            b = func_021F1120(p->f0C);
            if (a != 0) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 5);
                func_021F18D8(p->f68);
                func_021F1900(p->f68, 0, a + b, 3);
                func_021F1704(p->f68, 0x16, func_02012FFC());
                func_021F1B24(p->f68, 1);
                func_021F18EC(p->f68);
                p->state = 1;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 1:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 2;
        }
        break;
    case 2:
        p->f34 = func_021F1A2C(p->f68);
        if (p->f34 == 1) {
            b = func_021F1118(p->f0C);
            a = (unsigned short)func_02007774(func_0201293C(p->f08->f04));
            func_021F1A24(p->f68);
            if ((unsigned int)a < (unsigned int)b) {
                p->f40 = 1;
                p->state = 0xD;
            } else {
                p->f40 = 0;
                p->state = 3;
            }
        } else if (p->f34 == 2) {
            p->state = 0xD;
        }
        break;
    case 3:
        if (func_021F1120(p->f0C) != 0) {
            a = func_021F1118(p->f0C);
            func_021F1898(p->f68);
            func_021F1628(p->f68, 1);
            func_021F18D8(p->f68);
            func_021F1900(p->f68, 0, a, 3);
            func_021F1704(p->f68, 0x24, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F18EC(p->f68);
            p->state = 4;
        } else {
            p->state = 5;
        }
        break;
    case 4:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 5;
        }
        break;
    case 5:
        if (func_021F1134(p->f0C) == 1) {
            func_021F1898(p->f68);
            func_021F1628(p->f68, 5);
            func_021F1704(p->f68, 0x1A, func_02012FFC());
            p->state = 6;
        } else {
            p->state = 0xD;
        }
        break;
    case 6:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 7;
        }
        break;
    case 7:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            if (func_021F1148(p->f0C) == 1) {
                func_021F1704(p->f68, 0x1B, func_02012FFC());
                p->state = 8;
            } else {
                p->state = 0xD;
            }
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 8:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 9;
        }
        break;
    case 9:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 0xA;
        }
        break;
    case 10:
        func_021F1704(p->f68, 0x1C, func_02012FFC());
        p->state = 0xB;
        break;
    case 11:
        if (func_021F1B14(p->f68) == 1) {
            func_021F19E4(p->f68, 1);
            p->state = 0xC;
        }
        break;
    case 12:
        a = func_021F1A2C(p->f68);
        if (a == 1) {
            p->f34 = 2;
            p->state = 0xD;
        } else if (a == 2) {
            p->state = 5;
        }
        break;
    case 13:
        if (p->f34 == 1) {
            if (p->f40 == 1) {
                a = 2;
            } else {
                a = 0;
            }
        } else {
            a = 1;
        }
        if (func_021F11F0(p->f0C, 0xF, a) == 1) {
            if (a == 0) {
                p->state = 0xE;
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F17E0(p->f68, 0x19);
                func_021F1B38(p->f68, 1);
            } else if (a == 2) {
                p->state = 0x11;
            } else {
                p->state = 0x13;
            }
        }
        break;
    case 14:
        if (func_021F11BC(p->f0C) == 1) {
            func_021EFD98(p);
            p->state = 0xF;
        }
        if (func_021F115C(p->f0C) == 1) {
            a = func_021F1118(p->f0C);
            func_021F1898(p->f68);
            func_021F1628(p->f68, 1);
            func_021F18D8(p->f68);
            func_021F1900(p->f68, 0, a, 3);
            func_021F1704(p->f68, 0x1E, func_02012FFC());
            func_021F1B24(p->f68, 1);
            func_021F18EC(p->f68);
            p->state = 0x10;
            p->f44 = 1;
        }
        break;
    case 15:
        if (func_021F11F0(p->f0C, 0, 0) == 1) {
            func_021F1184(p->f0C);
            p->state = 0xE;
        }
        break;
    case 16:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 17:
        func_021F1898(p->f68);
        func_021F1628(p->f68, 5);
        func_021F1704(p->f68, 0x18, func_02012FFC());
        p->state = 0x12;
        break;
    case 18:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x13;
        }
        break;
    case 19:
        if (func_021F1164(p->f0C) == 1) {
            if (func_021F116C(p->f0C) == 1) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 5);
                func_021F1704(p->f68, 0x1F, func_02012FFC());
                p->state = 0x14;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 20:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x15;
            func_021F19E4(p->f68, 1);
        }
        break;
    case 21:
        a = func_021F1A2C(p->f68);
        if (a == 1 || a == 2) {
            c = func_0201292C(p->f08->f04);
            d = func_02012944(p->f08->f04);
            e = func_02012F08(p->f08->f04);
            if (a == 1 && func_0216BF9C(e, 0, d) == 1) {
                p->f34 = 2;
                p->state = 0x16;
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x25, func_02012FFC());
                func_021F1B24(p->f68, 1);
            } else {
                p->f34 = a;
                p->state = 0x17;
            }
        }
        break;
    case 22:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x17;
        }
        break;
    case 23:
        a = 1;
        if (p->f34 != 1) {
            a = 0;
        }
        if (func_021F11F0(p->f0C, 0x10, a) == 1) {
            if (a == 1) {
                c = func_0201292C(p->f08->f04);
                d = func_02012944(p->f08->f04);
                e = func_02012F08(p->f08->f04);
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x21, func_02012FFC());
                func_021F1B24(p->f68, 1);
                func_0216BF74(e, 0, d);
                func_02007E50(c, 0x215, 1, p->f00);
                p->f48 = 1;
                p->state = 0x18;
            } else {
                p->state = 0x19;
            }
        }
        break;
    case 24:
        if (func_021F1B14(p->f68) == 1) {
            p->state = 0x19;
        }
        break;
    case 25:
        if (p->f44 == 1 || p->f48 == 1) {
            if (func_021F11F0(p->f0C, 0x11, 0) == 1) {
                p->f20 = 0x13;
            }
        } else {
            if (func_021F1118(p->f0C) == 0 && func_021F116C(p->f0C) == 0) {
                func_021F1898(p->f68);
                func_021F1628(p->f68, 1);
                func_021F1704(p->f68, 0x28, func_02012FFC());
                func_021F1B24(p->f68, 1);
            }
            p->f20 = 0x1B;
        }
        break;
    }
}
