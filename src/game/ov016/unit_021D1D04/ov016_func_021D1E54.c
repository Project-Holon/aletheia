/*
 * function: func_021D1E54
 * address:  0x021D1E54
 * packet:   pkt_ov016_021D1E54
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_Start (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   func_021D276C  0x021d276c  arm  ov016
 *   func_021F5E7C  0x021f5e7c  arm  ov107
 *   func_021D1E9C  0x021d1e9c  arm  ov016
 *   func_02088234  0x02088234  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 user[0x16];
    u8 macAddress[6];
    u16 playerNo;
} DWCi_MOV_MBPChildInfo;

typedef struct {
    u16 state;
    u16 connectedBmp;
    u16 entryBmp;
    u16 requestBmp;
    u16 downloadBmp;
    u16 bootBmp;
    u16 endBmp;
} DWCi_MOV_MBPState;

typedef struct {
    DWCi_MOV_MBPState mbpState;
    DWCi_MOV_MBPChildInfo childInfo[1];
} DWCi_MOV_WPB_WORK;

extern DWCi_MOV_WPB_WORK *g_021DE65C;

typedef struct {
    char *romFilePathp;
    u16 *gameNamep;
    u16 *gameIntroductionp;
    char *iconCharPathp;
    char *iconPalettePathp;
    u32 ggid;
    u8 maxPlayerNum;
    u8 pad[3];
    u8 userParam[32];
} MBGameRegistry;

extern void func_021D276C(u16 state);
extern int func_021F5E7C(int channel);
extern int func_021D1E9C(MBGameRegistry *gameInfo);
extern void func_02088234(void);

void func_021D1E54(MBGameRegistry *gameInfo, u16 channel)
{
    func_021D276C(2);
    if (func_021F5E7C(channel)) {
        func_021D276C(7);
        return;
    }
    if (func_021D1E9C(gameInfo))
        return;
    func_02088234();
}
