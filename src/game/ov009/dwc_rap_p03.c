/*
 * file:     dwc_rap_p03.c
 * unit:     yes
 * function: func_0215642C, func_02156460, func_02156690, func_02156730, func_0215677C, func_021567B8
 * address:  0x0215642C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8264 0x021A8264 data ov009 a4
 *   func_0216B838 0x0216B838 arm ov009
 *   func_021AF2AC 0x021AF2AC thumb ov013
 *   func_021AF30C 0x021AF30C thumb ov013
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02034714  0x02034714  arm
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 *   func_021AF13C  0x021AF13C  thumb  ov013
 *   func_02059E38  0x02059E38  arm
 *   func_02059F18  0x02059F18  arm
 *   func_0216AD50 0x0216AD50 arm ov009
 *   func_0205CC20 0x0205CC20 arm
 *   func_02156400 0x02156400 thumb ov009
 *   func_021554A0 0x021554A0 thumb ov009
 *   func_0205912C  0x0205912C  arm
 *   func_02168848  0x02168848  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 */
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

extern unsigned char func_0216B838(void);
extern int func_021AF2AC(int);
extern void func_021AF30C(int);
extern int _s32_div_f(int, int);
void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02155374(int v);
extern void func_021AF13C(void);
extern int func_02059E38(int *errorCode, int *errorType);
extern void func_02059F18(void);
extern void func_0216AD50(void);
extern void func_0205CC20(void);
extern void func_02156400(void);
extern void func_021554A0(void);
extern int func_0205912C(u8 *);
extern unsigned char func_02168848(void *p, int a, int b);
extern void func_02082BCC(u8 *, u32, u32);
void func_0215642C(int flag);
int func_02156460(int err, int kind);
int func_02156690(int a);
int func_02156730(void);
void func_0215677C(void);
void func_021567B8(void);
extern u8 *d_021A8264;
extern char d_021A1C5C[];
extern u8 *g_021A8264;

/*
 * Retains the live result of func_0216B838 as func_021AF2AC's argument.
 */
void func_0215642C(int flag)
{
    if (flag) {
        func_021AF2AC(func_0216B838());
        d_021A8264[0x79F] = 1;
    } else {
        d_021A8264[0x79F] = 0;
    }
    func_021AF30C(d_021A8264[0x79F]);
}


/*
 * Classify a network error code (and its error kind) into a message class.
 */
int func_02156460(int err, int kind)
{
    int d100 = err / 100;
    int d1000 = err / 1000;

    if (err == 20101)
        return 1;
    if (d1000 == 23)
        return 1;
    if (err == 20108)
        return 2;
    if (err == 20110)
        return 3;
    if (d100 == 512)
        return 4;
    if (d100 == 500)
        return 5;
    if (err == 51103)
        return 6;
    if (d100 == 510)
        return 6;
    if (d100 == 511)
        return 6;
    if (d100 == 513)
        return 6;
    if (err >= 52000 && err <= 52003)
        return 8;
    if (err >= 52010 && err <= 52012)
        return 8;
    if (err >= 52100 && err <= 52103)
        return 8;
    if (err >= 52110 && err <= 52112)
        return 8;
    if (err >= 52200 && err <= 52203)
        return 8;
    if (err >= 52210 && err <= 52212)
        return 8;
    if (err >= 52400 && err <= 52403)
        return 8;
    if (err >= 52410 && err <= 52412)
        return 8;
    if (err >= 52500 && err <= 52503)
        return 8;
    if (err >= 52510 && err <= 52512)
        return 8;
    if (err >= 52700 && err <= 52703)
        return 8;
    if (err >= 52710 && err <= 52712)
        return 8;
    if (err == 80430)
        return 9;
    if (d1000 == 20)
        return 0;
    if (d100 == 520)
        return 0;
    if (d100 == 521)
        return 0;
    if (d100 == 522)
        return 0;
    if (d100 == 523)
        return 0;
    if (d100 == 530)
        return 0;
    if (d100 == 531)
        return 0;
    if (d100 == 532)
        return 0;
    if (err < 10000)
        return 14;
    if (d1000 == 31)
        return 12;
    switch (kind) {
    case 0:
    case 1:
        return 14;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return 11;
    default:
        func_02034714(d_021A1C5C, 0, d_021A1C5C);
        break;
    case 7:
        return 15;
    }
    return -1;
}


int func_02156690(int a)
{
    u32 x, y;
    if (func_02059E38((int *)(&x), (int *)(&y)) != 0) {
        func_02059F18();
    }
    if (a == 0) {
        switch (*(u32 *)(g_021A8264 + 0x754)) {
        case 7:
        case 9:
        case 10:
            if (*(u32 *)(g_021A8264 + 0x76c) != 0) {
                func_021AF13C();
            }
            func_02155374(0x12);
            break;
        case 6:
        case 16:
        case 19:
        case 20:
            return 1;
        default:
            break;
        }
    } else {
        switch (*(u32 *)(g_021A8264 + 0x754)) {
        case 6:
        case 0x13:
        case 0x14:
            return 1;
        default:
            break;
        }
    }
    return 0;
}


int func_02156730(void)
{
    u32 s = *(u32 *)(g_021A8264 + 0x754);
    if (s == 0x13 || s == 0x14 || s == 0x10 || s == 6) {
        u32 v = 6;
        func_02155374(v);
        *(u32 *)(g_021A8264 + 0x758) = 0x3ef;
        *(u32 *)(g_021A8264 + 0x774) = v - 7;
        return 1;
    }
    return 0;
}

void func_0215677C(void)
{
    if (g_021A8264 != 0) {
        func_02059F18();
        if (g_021A8264[0x7a9] != 0)
            func_0216AD50();
        g_021A8264[0x7a9] = 0;
        func_0205CC20();
        func_02156400();
        func_021554A0();
    }
}


void func_021567B8(void)
{
    if (*(u8 **)(g_021A8264 + 0x100) != 0) {
        u32 i = *(u32 *)(g_021A8264 + 0x74c) & 0x1f;
        u32 o = i * 12;
        int n;
        if (func_0205912C(*(u8 **)(g_021A8264 + 0x100) + o) != 0) {
            u32 r = func_02168848(*(u8 **)(g_021A8264 + 0x100) + o,
                                  (int)(g_021A8264 + 0x34c + i * 32), (int)(&n));
            if (n < 1) {
                (g_021A8264 + i)[0x32c] = 0;
                func_02082BCC(g_021A8264 + 0x34c + i * 32, 0, 0x20);
            } else {
                (g_021A8264 + i)[0x32c] = r;
            }
        }
        *(u32 *)(g_021A8264 + 0x74c) += 1;
    }
}
