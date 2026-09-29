/*
 * function: func_0216CA04
 * address:  0x0216CA04
 * packet:   pkt_ov009_0216CA04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWC_AddMatchKeyString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * notes:    near miss, one register-allocation residue: the image never hoists a zero
 *           constant (returns are mov r0,#0, the strh zero is mov r2,#0, index in r4,
 *           keyID r7, keyString r6, valueSrc r5); this source hoists r4=0 after the
 *           first test and shifts every register by one. About 20 attempts.
 *
 * symbols:
 *   func_020948E0                0x020948E0 arm
 *   func_02173AD8                0x02173AD8 arm   ov009
 *   func_0205A1B0                0x0205A1B0 arm
 *   func_0209477C                0x0209477C arm
 *   func_0205A16C                0x0205A16C arm
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   func_02094798                0x02094798 arm
 *   func_0219D158                0x0219D158 arm   ov009
 *   g_021AAA40                   0x021AAA40 data
 *   g_021AAA44                   0x021AAA44 data
 *   g_021AAA41                   0x021AAA41 data
 *   g_021AAA42                   0x021AAA42 data
 *   g_021AAA48                   0x021AAA48 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct DWCstGameMatchKeyData {
    u8 keyID;
    u8 f1;
    u16 f2;
    char *keyString;
    char *value;
};

extern struct DWCstGameMatchKeyData g_021AAA40[154];

#define KEYID(i)  (g_021AAA40[i].keyID)
#define KEYF1(i)  (g_021AAA40[i].f1)
#define KEYF2(i)  (g_021AAA40[i].f2)
#define KEYSTR(i) (g_021AAA40[i].keyString)
#define KEYVAL(i) (g_021AAA40[i].value)

extern int func_020948E0(const char *s1, const char *s2);
extern u8 func_02173AD8(void);
extern void func_0205A1B0(int name, void *ptr);
extern u32 func_0209477C(const char *s);
extern void *func_0205A16C(int name, u32 size);
extern void func_0216EB68(int error, int errorCode);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219D158(int keyid, char *key);

u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && KEYID(keyID - 0x64) != 0) {
        if (KEYSTR(keyID - 0x64) != 0 && func_020948E0(KEYSTR(keyID - 0x64), keyString) != 0)
            return 0;
    } else {
        keyID = func_02173AD8();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    KEYID(index) = keyID;
    KEYF1(index) = 1;
    KEYF2(index) = 0;
    if (KEYSTR(index) != 0)
        func_0205A1B0(4, KEYSTR(index));
    KEYSTR(index) = func_0205A16C(4, func_0209477C(keyString) + 1);
    if (KEYSTR(index) == 0) {
        func_0216EB68(9, -80001);
        return 0;
    }
    func_02094798(KEYSTR(index), keyString);
    KEYVAL(index) = valueSrc;
    func_0219D158(keyID, KEYSTR(index));
    return keyID;
}
