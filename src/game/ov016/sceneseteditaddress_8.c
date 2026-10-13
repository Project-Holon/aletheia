/*
 * file:     sceneseteditaddress_8.c
 * unit:     yes
 * function: func_021C7768, func_021C77F4, func_021C78A0, func_021C7960, func_021C79B4, func_021C7A0C, func_021C7ABC, func_021C7B34, func_021C7C74
 * address:  0x021C7768
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BF730  0x021BF730  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   g_021DE5E4     0x021DE5E4  data
 *   func_021BD138  0x021BD138  arm  ov016
 *   func_021D6F38  0x021D6F38  arm  ov016
 *   func_021D5CA8  0x021D5CA8  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021D6090  0x021D6090  arm  ov016
 *   func_021C0EA0  0x021C0EA0  arm  ov016
 *   func_021C0E50  0x021C0E50  arm  ov016
 *   func_021C0E8C  0x021C0E8C  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   g_021DB550     0x021DB550  data
 *   func_0207E51C  0x0207E51C  arm
 *   func_021C82FC  0x021C82FC  arm  ov016
 *   func_021D5F14  0x021D5F14  arm  ov016
 *   func_021D5E5C  0x021D5E5C  arm  ov016
 *   func_021D5FC4  0x021D5FC4  arm  ov016
 *   g_021DA5E8     0x021DA5E8  data
 *   g_021DA5D4     0x021DA5D4  data
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021D157C  0x021D157C  arm  ov016
 *   g_021DB4DC     0x021DB4DC  data
 *   func_021C7314  0x021C7314  arm  ov016
 *   d_021DE5E4     0x021DE5E4  data
 *   func_021CFE18 0x021CFE18 arm ov016
 *   func_020588D0 0x020588D0 arm
 *   g_021DA5CC 0x021DA5CC data
 *   func_021C7CA0  0x021C7CA0  arm  ov016
 */
typedef struct MemSsea {
    void *bg;                         /* 0x00 */
    void *caret;                      /* 0x04 */
    char text[4][3];                  /* 0x08 */
    unsigned char pos;                /* 0x14 */
    unsigned char result;             /* 0x15 */
} MemSsea;

typedef struct COORD {
    unsigned short x, y;
} COORD;

typedef struct AREA {
    unsigned short x, y, w, h;
} AREA;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct GXOamAttr_021C7960 {
    union {
        struct {
            unsigned short attr0;
            unsigned short attr1;
        } h;
        unsigned int attr01;
    } u;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr_021C7960;

typedef struct GXOamAttr_021C7768 {
    unsigned int attr01;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr_021C7768;

typedef struct FuncTable {
    void (*f[5])(char *);
} FuncTable;

typedef unsigned char  u8;

typedef struct { char c[4]; } Val;

extern int func_021BF730();
extern void func_021C0E40(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021BD138();
extern void func_021D6F38(unsigned int *obj);
extern void func_021D5CA8(int a);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern void func_021D6090(int lcd, int plane);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern void func_021C0E50(unsigned int a, unsigned int b);
extern void func_021C0E8C(unsigned int a, unsigned int b);
extern void func_021D6438(void **mem);
extern void func_0207E51C();
extern void func_021C82FC();
extern void func_021D5F14();
extern void func_021D5E5C(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
extern void func_021D5FC4(int x);
extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524();
extern int func_021D157C();
extern void func_021C7314();
extern void func_021CFE18(char *adr, u8 *buf);
extern int func_020588D0(u8 *address);
extern void func_021C7CA0();
void func_021C7768(void);
void func_021C77F4(void);
void func_021C78A0(void);
void func_021C7960(void);
void func_021C79B4(void);
void func_021C7A0C(void);
void func_021C7ABC(void);
int func_021C7B34(void);
void func_021C7C74(void);
extern MemSsea *g_021DE5E4;
extern unsigned char g_021DB550[];
extern COORD g_021DA5E8;
extern unsigned char g_021DA5D4[];
extern FuncTable g_021DB4DC;
extern Val g_021DA5CC;





/*
 * sdk:      endScene2 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C7768(void)
{
    int r;

    if (func_021BF730())
        return;
    r = g_021DE5E4->result;
    if (r == 0) {
        func_021C0E40((unsigned int)func_021C77F4);
    } else if (r == 2) {
        func_021D1208(6, 3, 1, -1, 0);
        func_021C0E40((unsigned int)func_021C7C74);
    } else {
        func_021D1208(0x47, 2, 1, -1, 0);
        func_021C0E40((unsigned int)func_021C79B4);
    }
}





/*
 * sdk:      endScene3 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C77F4(void)
{
    int prm;

    func_021BD138();
    func_021D6F38(g_021DE5E4->caret);
    func_021D5CA8(0);
    func_021BD1D4((char *)g_021DB550, func_0207E51C);
    func_021D6090(1, 1);
    func_021D6090(0, 0x15);
    func_021C0EA0((unsigned int *)(&prm), 0);
    if (prm >= 3)
        prm++;
    func_021C0E50(2, 1);
    func_021C0E8C(0, prm + 3);
    func_021C0E40((unsigned int)func_021C82FC);
    func_021D6438((void *)0x021DE5E4);
}




/*
 * sdk:      drawAddress (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * Draws the 12-character edit-address field: one 12x16 area whose y/w/h come
 * from an AREA built before the first call, then a per-character blit.
 *
 * The AREA must be aggregate-initialised: `AREA a = { g_021DA5E8.x,
 * g_021DA5E8.y, 11, 16 };`.  That is what keeps `a` memory-resident (fields
 * reloaded from the stack frame per iteration, exactly like the object); the
 * same four field assignments written as statements get the struct promoted
 * to registers and the function compiles 28 bytes short.  The two redundant
 * stores that follow the initialiser are dead (1.1p1 removes them) but they
 * change the schedule of the initialiser stores into the object's x,y,w,h
 * order and are required for EXACT; drop either one and the row goes back to
 * 142+ concrete bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C78A0.c \
 *       --func func_021C78A0 --addr 0x021C78A0 --region ov016 --cc 1.1p1 --arm --lang c99
 */
void func_021C78A0(void)
{
    AREA a = { g_021DA5E8.x, g_021DA5E8.y, 11, 16 };
    int i;
    unsigned short buf[2];

    a.w = 11;
    a.h = 16;
    func_021D5F14(g_021DE5E4->bg, 0);
    buf[1] = 0;
    for (i = 0; i < 12; i++) {
        buf[0] = ((unsigned char *)g_021DE5E4->text)[i];
        a.x = g_021DA5D4[i];
        func_021D5E5C(g_021DE5E4->bg, a.x, a.y, a.w, a.h, 2, 0x480, buf);
    }
    func_021D5FC4((int)g_021DE5E4->bg);

}




static inline void SetObjPosition(GXOamAttr_021C7960 *oam, int x, int y)
{
    oam->u.attr01 = (oam->u.attr01 & ~(0x01FF0000 | 0x000000FF)) | (y & 0xFF) | ((x & 0x1FF) << 16);
}




/*
 * sdk:      dispCaret (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * notes:    the OAM update is an inlined position setter (y term before x);
 *           the open-coded expression swaps r1 and r2.
 */
void func_021C7960(void)
{
    int x = g_021DE5E4->pos;

    if (x > 3)
        x = 3;
    SetObjPosition(g_021DE5E4->caret, g_021DA5D4[x * 3 + 2], 0x28);
}





/*
 * sdk:      procWin (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C79B4(void)
{
    g_021DE5E4->result = func_021D1568();
    switch (g_021DE5E4->result) {
    case 0:
        func_021CFFAC(7);
        break;
    case 1:
        func_021CFFAC(0xE);
        break;
    default:
        return;
    }
    func_021D1524();
    func_021C0E40((unsigned int)func_021C7A0C);
}





/*
 * sdk:      procWin1 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 */
void func_021C7A0C(void)
{
    FuncTable FUNC = g_021DB4DC;
    int prm;

    if (func_021D157C())
        return;
    if (g_021DE5E4->result == 0) {
        ((GXOamAttr_021C7768 *)g_021DE5E4->caret)->attr01 &= 0xC1FFFCFF;
        func_021C0E40((unsigned int)func_021C7314);
        return;
    }
    func_021C0EA0((unsigned int *)(&prm), 0);
    FUNC.f[prm]((char *)g_021DE5E4 + 8);
    func_021C0E40((unsigned int)func_021C77F4);
}



/*
 * Sanitises four three-byte rows of a global buffer: every leading byte that
 * is NUL, space or '0' becomes a space, except the third column which becomes
 * '0'; the run stops at the first other byte.
 */
void func_021C7ABC(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        char *row = ((char *)g_021DE5E4) + 8 + i * 3;
        int j;
        for (j = 0; j < 3; j++) {
            u8 c = row[j];
            if (c != 0x30 && c != 0x20 && c != 0)
                break;
            row[j] = (j == 2) ? 0x30 : 0x20;
        }
    }
    func_021C78A0();
}



/*
 * sdk:      isCorrect (libdwcutil.TWL.HYB.a(sceneseteditaddr))
 */
int func_021C7B34(void)
{
    Val VAL = g_021DA5CC;
    u8 *c;
    int prm;
    int i;
    int j;
    u8 buf[4];
    int b;

    for (i = 0; i < 4; i++) {
        c = (u8 *)g_021DE5E4->text[i];
        if (c[0] == ' ')
            continue;
        for (j = 0; j < 3; j++) {
            if (c[j] > (u8)VAL.c[j])
                return 0;
            if (c[j] < (u8)VAL.c[j])
                break;
        }
    }
    func_021CFE18(g_021DE5E4->text[0], buf);
    b = 0;
    func_021C0EA0((unsigned int *)((void **)&prm), 0);
    if (prm == 1) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 8; j++) {
                if (b != 0) {
                    if (buf[i] & (1 << (7 - j)))
                        return 0;
                } else {
                    if ((buf[i] & (1 << (7 - j))) == 0)
                        b = 1;
                }
            }
        }
        return 1;
    }
    if (func_020588D0(buf))
        b = 1;
    return b;
}



void func_021C7C74(void)
{
    if (func_021D1568())
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021C0E40((unsigned int)func_021C7CA0);
}
