/*
 * function: func_02174AA0
 * address:  0x02174AA0
 * packet:   pkt_ov009_02174AA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      DWCi_QR2ServerKeyCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * symbols:
 *   func_0217603C  0x0217603C arm   ov009
 *   func_0219B628  0x0219B628 arm   ov009
 *   func_02175F3C  0x02175F3C arm   ov009
 *   func_02175FB8  0x02175FB8 arm   ov009
 *   func_0219B660  0x0219B660 arm   ov009
 *   g_021AAA40     0x021AAA40 data
 *   g_021AAA41     0x021AAA41 data
 *   g_021AAA48     0x021AAA48 data
 */

struct DWCstMatchControl {
    char pad0[0x15];
    unsigned char f15;
    unsigned char f16;
    unsigned char f17;
    char pad18[0x10];
    int f28;
    char pad2c[0x678 - 0x2c];
    int f678;
    char pad67c[0x790 - 0x67c];
    int f790;
};

struct gamekey_s {
    unsigned char keyID;
    unsigned char isStr;
    unsigned short pad;
    char *keyStr;
    void *value;
};

extern int func_0217603C(void);
extern int func_0219B628(void *outbuf, int value);
extern struct DWCstMatchControl *func_02175F3C(void);
extern int func_02175FB8(void);
extern int func_0219B660(void *outbuf, char *value);
extern struct gamekey_s g_021AAA40[154];

void func_02174AA0(int keyid, void *outbuf)
{
    int suspendMatch;
    int numPlayers;
    int index;

    switch (keyid) {
    case 8:
        numPlayers = func_0217603C() - 1;
        if (numPlayers < 0)
            numPlayers = 0;
        func_0219B628(outbuf, numPlayers);
        return;
    case 10:
        func_0219B628(outbuf, func_02175F3C()->f17);
        return;
    case 50:
        func_0219B628(outbuf, func_02175F3C()->f678);
        return;
    case 51:
        func_0219B628(outbuf, func_02175F3C()->f15);
        return;
    case 52:
        func_0219B628(outbuf, 90);
        return;
    case 53:
        func_0219B628(outbuf, 1);
        return;
    case 54:
        if (func_02175FB8() == 2)
            suspendMatch = func_02175F3C()->f790;
        else
            suspendMatch = 0;
        func_0219B628(outbuf, suspendMatch);
        return;
    case 55:
        func_0219B628(outbuf, func_02175F3C()->f16);
        return;
    case 56:
        func_0219B628(outbuf, func_02175F3C()->f28);
        return;
    }
    index = keyid - 100;
    if (index < 0 || index >= 154)
        return;
    if (g_021AAA40[index].keyID == 0)
        return;
    if (g_021AAA40[index].isStr != 0)
        func_0219B660(outbuf, (char *)g_021AAA40[index].value);
    else
        func_0219B628(outbuf, *(int *)g_021AAA40[index].value);
}
