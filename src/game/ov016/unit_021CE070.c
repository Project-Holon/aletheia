/*
 * file:     unit_021CE070.c
 * function: func_021CE070
 * address:  0x021CE070
 * packet:   pkt_ov016_021CE070
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneSetUsbReady1 (libdwcutil.TWL.HYB.a scenesetusbready)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE070.c \n *       --func func_021CE070 --addr 0x021CE070 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   g_021DE62C     0x021DE62C  data
 *   func_021CE108  0x021CE108  arm  ov016
 *   func_021BD674  0x021BD674  arm  ov016
 *   func_021BD214  0x021BD214  arm  ov016
 *   func_02087C88  0x02087C88  arm
 *   func_02082A48  0x02082A48  arm
 *   func_02082A60  0x02082A60  arm
 *   func_021BD310  0x021BD310  arm  ov016
 *   func_021BC820  0x021BC820  arm  ov016
 *   func_021D0B44  0x021D0B44  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021CE45C  0x021CE45C  arm  ov016
 *   func_021CE1B0  0x021CE1B0  arm  ov016
 */

typedef struct {
    unsigned char favoriteColor;
    unsigned char pad;
    unsigned char birthMonth;
    unsigned char birthDay;
    unsigned short nickName[11];
    unsigned short nickNameLength;
    unsigned short comment[27];
    unsigned short commentLength;
} OwnerInfo;

extern unsigned char g_021DE62C;
extern void func_021CE108(void);
extern void func_021BD674(int idx);
extern void func_021BD214(int step);
struct OSOwnerInfo;
extern void func_02087C88(struct OSOwnerInfo *info);
extern void func_02082A48(unsigned short value, void *destp, unsigned long size);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern void func_021BD310(unsigned short *name, int msgId);
extern void func_021BC820(int color);
extern int func_021D0B44(void (*callback)(int));
extern void func_021CFFAC(unsigned int v);
extern void func_021C0E40(unsigned int v);
extern void func_021CE45C(int state);
extern void func_021CE1B0(void);

void func_021CE070(void)
{
    OwnerInfo info;
    unsigned short buf[11];
    g_021DE62C = 0;
    func_021CE108();
    func_021BD674(8);
    func_021BD214(2);
    func_02087C88((struct OSOwnerInfo *)(&info));
    func_02082A48(0, buf, 0x16);
    func_02082A60(info.nickName, buf, info.nickNameLength * 2);
    func_021BD310(buf, 40);
    func_021BC820(0);
    func_021D0B44(func_021CE45C);
    func_021CFFAC(11);
    func_021C0E40((unsigned int)func_021CE1B0);
}
