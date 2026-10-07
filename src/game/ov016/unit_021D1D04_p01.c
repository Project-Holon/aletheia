/*
 * file:     unit_021D1D04_p01.c
 * unit:     yes
 * function: func_021D1D04, func_021D1D40
 * address:  0x021D1D04
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082D44 0x02082D44 arm
 *   func_021F5904 0x021F5904 arm
 *   func_02088234 0x02088234 arm
 *   func_021F5B4C 0x021F5B4C arm
 *   func_021F1B3C 0x021F1B3C arm
 *   func_021D276C 0x021D276C arm ov016
 *   func_021D2450 0x021D2450 arm ov016
 *   g_021DE65C 0x021DE65C data
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

extern void func_021D298C(int);
extern void func_02082D44(void *srcp, void *dstp, u32 size);
extern int func_021F5904(void *work, MBUserInfo *user, u32 ggid, u32 tgid, u32 dma);
extern void func_02088234(void);
extern int func_021F5B4C(u16 sendSize, u16 maxChildren);
extern void func_021F1B3C(void (*cb)(u16, u32, void *));
extern void func_021D276C(u16 state);
extern void func_021D2450(u16, u32, void *);
void func_021D1D04(int x);
void func_021D1D40(u32 ggid, u16 tgid);
extern Wb *g_021DE65C;


/*
 * Publish the object, initialise the tail region, and clear its two control words.
 * Addresses are Black-image addresses.
 */
void func_021D1D04(int x)
{
    int *g = (int *)0x021DE65C;

    g[0] = x;
    func_021D298C(x + 0x160 + 0x1b000);
    *(int *)(g[0] + 0x1b000 + 0x140) = 0;
    *(int *)(g[0] + 0x1b000 + 0x144) = 0;
}


/*
 * sdk:      DWCi_MOV_MBP_Init (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 */
void func_021D1D40(u32 ggid, u16 tgid)
{
    MBUserInfo myUser;
    u8 *own = (u8 *)0x02fffc80;
    myUser.favoriteColor = 1;
    myUser.nameLength = own[0x1a];
    func_02082D44(own + 6, myUser.name, 0x14);
    myUser.playerNo = 0;
    {
        Hdr h = {0};
        g_021DE65C->hdr = h;
    }
    *(void **)((char *)g_021DE65C + 0x1b140) = (char *)g_021DE65C + 0x10040;
    if (func_021F5904(*(void **)((char *)g_021DE65C + 0x1b140), &myUser, ggid, tgid, 2))
        func_02088234();
    func_021F5B4C(0x100, 1);
    func_021F1B3C(func_021D2450);
    func_021D276C(1);
}
