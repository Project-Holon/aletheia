/*
 * function: func_021C0A2C
 * address:  0x021C0A2C
 * packet:   pkt_ov016_021C0A2C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      checkParam (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   gDwcutilMainWork     0x021DE56C  data
 */

typedef struct Param {
    unsigned int mode : 4;
    unsigned int flags : 28;
} Param;

typedef union PU {
    Param b;
    unsigned int v;
} PU;

typedef struct UtilState {
    unsigned char lang;
    unsigned char end;
    unsigned char pad2[2];
    void *work;
    Param param;
    void (*scene)(void);
} UtilState;

extern UtilState gDwcutilMainWork;

int func_021C0A2C(int lang, unsigned int param)
{
    gDwcutilMainWork.lang = lang;
    *(unsigned int *)&gDwcutilMainWork.param = param;
    if (lang < 0 || lang > 6)
        return 0;
    if (gDwcutilMainWork.param.mode > 1)
        return 0;
    if (gDwcutilMainWork.param.flags & 2)
        return 0;
    if (lang != 0 && (gDwcutilMainWork.param.flags & 1))
        return 0;
    if (lang == 0 && !(gDwcutilMainWork.param.flags & 1))
        return 0;
    return 1;

}
