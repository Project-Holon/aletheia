/*
 * function: func_021C0970
 * address:  0x021C0970
 * packet:   pkt_ov016_021C0970
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_StartUtility (libdwcutil.TWL.HYB.a main.o)
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021C0A2C  0x021C0A2C  arm  ov016
 *   func_02177ED8  0x02177ED8  arm  ov009
 *   func_02177EC8  0x02177EC8  arm  ov009
 *   func_021C0AA8  0x021C0AA8  arm  ov016
 *   func_021C0B7C  0x021C0B7C  arm  ov016
 *   func_021CFEBC  0x021CFEBC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D656C  0x021D656C  arm  ov016
 *   func_021D75D0  0x021D75D0  arm  ov016
 *   func_021D6BC8  0x021D6BC8  arm  ov016
 *   func_021D7448  0x021D7448  arm  ov016
 *   func_02087AE4  0x02087AE4  arm
 *   func_021C0DE8  0x021C0DE8  arm  ov016
 *   func_021C16F4  0x021C16F4  arm  ov016
 *   g_021DE56C     0x021DE56C  data
 *   g_021DB04C     0x021DB04C  data
 */

typedef struct UtilState {
    unsigned char lang;
    unsigned char end;
    unsigned char pad2[2];
    void *work;
    unsigned int param;
    void (*scene)(void);
} UtilState;

extern int OS_IsRunOnTwl(void);
extern int func_021C0A2C(int lang, unsigned int param);
extern char *func_02177ED8(void);
extern void func_02177EC8(char *nasaddr);
extern void func_021C0AA8(void);
extern void func_021C0B7C(void);
extern void func_021CFEBC(void);
extern void func_021C0E40(void (*scene)());
extern void func_021D656C();
extern void func_021D75D0(int kind);
extern void func_021D6BC8(void);
extern void func_021D7448(void);
extern void func_02087AE4(void);
extern void func_021C0DE8(void);
extern void func_021C16F4(void);
extern UtilState g_021DE56C;
extern char g_021DB04C[];

int func_021C0970(void *work, int language, int param)
{
    char *tempNasUrl;
    int result;
    if (OS_IsRunOnTwl())
        return -2;
    g_021DE56C.work = work;
    if (!func_021C0A2C(language, param))
        return -1;
    tempNasUrl = func_02177ED8();
    func_02177EC8(g_021DB04C);
    g_021DE56C.end = 0;
    func_021C0AA8();
    func_021C0B7C();
    func_021CFEBC();
    func_021C0E40(func_021C16F4);
    result = 0;
    do {
        func_021D656C();
        g_021DE56C.scene();
        func_021D75D0(result);
        func_021D6BC8();
        func_021D7448();
        func_02087AE4();
    } while (!g_021DE56C.end);
    func_021C0DE8();
    func_02177EC8(tempNasUrl);
    return result;
}
