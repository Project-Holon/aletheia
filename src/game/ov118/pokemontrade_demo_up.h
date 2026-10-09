/*
 * pokemontrade_demo_up.h: the object that every function of pokemontrade_demo_up
 * receives as p (ov118 0x021D4664..0x021D67F8). Field names with an offset are
 * placeholders; offsets come from the code.
 */
#ifndef POKEMONTRADE_DEMO_UP_H
#define POKEMONTRADE_DEMO_UP_H

typedef struct {
    int x, y, z;
} Vec;

typedef struct TradeUp {
    unsigned char  pad_0[0xC];
    void          *work;           /* 0x00C */
    unsigned char  pad_10[0x5F4 - 0x10];
    unsigned short heap;           /* 0x5F4 */
    unsigned char  pad_5F6[0x720 - 0x5F6];
    unsigned int   f720;
    void          *f724;
    unsigned char  pad_728[0x738 - 0x728];
    unsigned int   f738;
    unsigned int   f73C;
    unsigned char  pad_740[0x818 - 0x740];
    signed char   *fade;           /* 0x818 */
    unsigned char  pad_81C[0x830 - 0x81C];
    unsigned int   f830;
    unsigned int   f834;
    unsigned char  pad_838[0x844 - 0x838];
    void          *obj[4];         /* 0x844 */
    unsigned int   f854;
    unsigned char  pad_858[4];
    void          *slot0;          /* 0x85C */
    void          *slot1;          /* 0x860 */
    void          *f864;
    void          *f868;
    unsigned char  pad_86C[0x88C - 0x86C];
    unsigned int   f88C;
    unsigned char  pad_890[0x8A8 - 0x890];
    unsigned int   f8A8;
    unsigned char  pad_8AC[0x8BC - 0x8AC];
    unsigned int   f8BC;
    unsigned char  pad_8C0[0x9C4 - 0x8C0];
    int            f9C4;
    unsigned char  pad_9C8[0xF2C - 0x9C8];
    int            frame;          /* 0xF2C */
    unsigned char  pad_F30[0x1094 - 0xF30];
    unsigned int   f1094;
    unsigned char  pad_1098[0x118C - 0x1098];
    unsigned int   f118C;
    unsigned char  pad_1190[0x11ED - 0x1190];
    unsigned char  f11ED;
    unsigned char  f11EE;
    unsigned char  f11EF;
    unsigned char  f11F0;
} TradeUp;

#endif
