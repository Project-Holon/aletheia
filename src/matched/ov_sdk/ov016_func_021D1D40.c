/*
 * function: DWCi_MOV_MBP_Init
 * address:  0x021D1D40
 * packet:   pkt_ov016_021D1D40
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_Init (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_021F5904 0x021F5904 arm
 *   OS_Terminate 0x02088234 arm
 *   func_021F5B4C 0x021F5B4C arm
 *   func_021F1B3C 0x021F1B3C arm
 *   DWCi_MOV_MBP_ChangeState 0x021D276C arm ov016
 *   func_021D2450 0x021D2450 arm ov016
 *   gDwcMovMbpWork 0x021DE65C data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    u8 favoriteColor : 4;
    u8 playerNo : 4;
    u8 nameLength;
    u16 name[10];
} MBUserInfo;

typedef struct {
    u16 v[7];
} Hdr;

typedef struct {
    Hdr hdr;
} Wb;

extern Wb *gDwcMovMbpWork;

extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern int func_021F5904(void *work, MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
extern void OS_Terminate(void);
extern int func_021F5B4C(u16 sendSize, u16 maxChildren);
extern void func_021F1B3C(void (*cb)(u16, u32, void *));
extern void DWCi_MOV_MBP_ChangeState(u16 state);
extern void func_021D2450(u16, u32, void *);

void DWCi_MOV_MBP_Init(u32 ggid, u16 tgid)
{
    MBUserInfo myUser;
    u8 *own = (u8 *)0x02fffc80;
    myUser.favoriteColor = 1;
    myUser.nameLength = own[0x1a];
    MI_CpuCopy8(own + 6, myUser.name, 0x14);
    myUser.playerNo = 0;
    {
        Hdr h = {0};
        gDwcMovMbpWork->hdr = h;
    }
    *(void **)((char *)gDwcMovMbpWork + 0x1b140) = (char *)gDwcMovMbpWork + 0x10040;
    if (func_021F5904(*(void **)((char *)gDwcMovMbpWork + 0x1b140), &myUser, ggid, tgid, 2))
        OS_Terminate();
    func_021F5B4C(0x100, 1);
    func_021F1B3C(func_021D2450);
    DWCi_MOV_MBP_ChangeState(1);
}
