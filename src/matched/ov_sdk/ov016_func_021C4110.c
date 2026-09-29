/*
 * function: func_021C4110
 * address:  0x021C4110
 * packet:   pkt_ov016_021C4110
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneOptMovUser (libdwcutil.TWL.HYB.a sceneoptmovuser.o)
 *
 * symbols:
 *   func_021C11F8  0x021C11F8  arm  ov016
 *   func_021D5A58  0x021D5A58  arm  ov016
 *   func_021C41E0  0x021C41E0  arm  ov016
 *   func_02082A48  0x02082A48  arm
 *   func_02082A60  0x02082A60  arm
 *   func_021D5E5C  0x021D5E5C  arm  ov016
 *   func_021D5FC4  0x021D5FC4  arm  ov016
 *   func_021C11D4  0x021C11D4  arm  ov016
 *   func_021D1208  0x021D1208  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   g_021DE5C4     0x021DE5C4  data
 *   func_021C44D8  0x021C44D8  arm  ov016
 *   func_021C4260  0x021C4260  arm  ov016
 */

typedef struct MBUserInfo {
    unsigned char color;
    unsigned char nameLength;
    unsigned short name[10];
} MBUserInfo;

extern MBUserInfo *func_021C11F8();
extern int func_021D5A58();
extern void func_021C41E0();
extern void func_02082A48();
extern void func_02082A60();
extern void func_021D5E5C();
extern void func_021D5FC4();
extern void func_021C11D4();
extern void func_021D1208();
extern void func_021C0E40();
extern void func_021C44D8();
extern void func_021C4260();
extern unsigned char g_021DE5C4[];

void func_021C4110(void)
{
    unsigned short buf[11];
    MBUserInfo *info;
    int bg;

    info = func_021C11F8();
    bg = func_021D5A58(0, 0);
    g_021DE5C4[1] = 0;
    g_021DE5C4[0] = 0;
    func_021C41E0();
    func_02082A48(0, buf, sizeof(buf));
    func_02082A60(info->name, buf, info->nameLength * 2);
    func_021D5E5C(bg, 8, 0x35, 0xF0, 0x1C, 2, 0x480, buf);
    func_021D5FC4(bg);
    func_021C11D4(func_021C44D8);
    func_021D1208(0x1D, 4, 0, -1, 0);
    func_021C0E40(func_021C4260);
}
