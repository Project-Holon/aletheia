/*
 * function: DWCi_SceneOptMovUser
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
 *   DWCi_MOVlGetChild  0x021C11F8  arm  ov016
 *   DWCi_FNTlFormBgEx  0x021D5A58  arm  ov016
 *   func_021C41E0  0x021C41E0  arm  ov016
 *   MIi_CpuClear16  0x02082A48  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   DWCi_FNTlDrawRect  0x021D5E5C  arm  ov016
 *   DWCi_FNTlRenewBg  0x021D5FC4  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovUserWork     0x021DE5C4  data
 *   func_021C44D8  0x021C44D8  arm  ov016
 *   func_021C4260  0x021C4260  arm  ov016
 */

typedef struct MBUserInfo {
    unsigned char color;
    unsigned char nameLength;
    unsigned short name[10];
} MBUserInfo;

extern char *DWCi_MOVlGetChild(void);
extern void *DWCi_FNTlFormBgEx(int lcd, int font);
extern void func_021C41E0();
extern void MIi_CpuClear16();
extern void MIi_CpuCopy16();
typedef unsigned short u16;
typedef unsigned int   u32;
extern void DWCi_FNTlDrawRect(void *canvas, int x, int y, int w, int h, int color, u32 flag, u16 *txt);
extern void DWCi_FNTlRenewBg(int x);
extern void DWCi_MOVlChangeCallback(unsigned int v);
extern void DWCi_WINlInitEx(int msg, int type, unsigned char dark, int n, int num);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C44D8();
extern void func_021C4260();
extern unsigned char gSceneOptMovUserWork[];

void DWCi_SceneOptMovUser(void)
{
    unsigned short buf[11];
    MBUserInfo *info;
    void *bg;

    info = (MBUserInfo *)DWCi_MOVlGetChild();
    bg = DWCi_FNTlFormBgEx(0, 0);
    gSceneOptMovUserWork[1] = 0;
    gSceneOptMovUserWork[0] = 0;
    func_021C41E0();
    MIi_CpuClear16(0, buf, sizeof(buf));
    MIi_CpuCopy16(info->name, buf, info->nameLength * 2);
    DWCi_FNTlDrawRect(bg, 8, 0x35, 0xF0, 0x1C, 2, 0x480, buf);
    DWCi_FNTlRenewBg((int)bg);
    DWCi_MOVlChangeCallback((unsigned int)func_021C44D8);
    DWCi_WINlInitEx(0x1D, 4, 0, -1, 0);
    DWCi_ChangeScene((unsigned int)func_021C4260);
}
