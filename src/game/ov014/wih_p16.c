/*
 * file:     wih_p16.c
 * unit:     yes
 * function: func_021793B8, func_021793F8, func_0217945C, func_02179498, func_02179570, func_021795A4, func_021795C0, func_021795D4, func_02179614, func_02179628, func_0217963C, func_02179650
 * address:  0x021793B8
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A8     0x021797A8  data   ov014  a4
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_020902D8  0x020902D8  arm
 *   func_02178138 0x02178138 thumb ov014
 *   func_0217863C 0x0217863C thumb ov014
 *   func_0209028C 0x0209028C arm
 *   func_02178CDC 0x02178CDC thumb ov014
 *   func_021788FC       0x021788FC  thumb  ov014
 *   func_02178C50       0x02178C50  thumb  ov014
 *   func_021784AC       0x021784AC  thumb  ov014
 *   WM_EndDataSharing   0x0209028C  arm
 *   func_0208F43C 0x0208F43C arm
 *   func_02178DE0 0x02178DE0 thumb ov014
 *   func_02090CD4  0x02090CD4  arm
 */
struct WMDataSet;
struct WMDataSharingInfo;
typedef unsigned char u8;

typedef int BOOL;

typedef unsigned short u16;

typedef short s16;

typedef unsigned int u32;

extern void func_0217814C(int err);
extern int func_020902D8(struct WMDataSharingInfo *dsInfo, const u16 *sendData, struct WMDataSet *receiveData);
extern void func_02178138(int);
extern int func_0217863C(void);
extern int func_0209028C(void *);
extern int func_02178CDC(void);
extern BOOL func_021788FC(void);
extern BOOL func_02178C50(void);
extern BOOL func_021784AC(void);
extern int WM_EndDataSharing(void *info);
extern int func_0208F43C(void (*)(u8 *));
extern void func_02178DE0(u8 *);
extern void func_02090CD4(int a, int b, u16 c, int d, u16 e, int f);
BOOL func_021793B8(int arg);
void func_021793F8(void);
void func_0217945C(void);
BOOL func_02179498(void);
int func_02179570(void (*cb)(int));
unsigned short func_021795A4(void);
void func_021795C0(unsigned v);
void func_021795D4(int a, int b, int c, int d);
unsigned short func_02179614(void);
void func_02179628(unsigned v);
void func_0217963C(u32 v);
void func_02179650(u16 v);
extern u8 *g_021797A8;


/*
 * Calls the arm9 function at 0x020902D8 with the data-sharing info
 * (+0x1444) and buffer (+0x1C64) of the work block behind g_021797A8; result
 * 7 or 5 counts as failure without the error setter, other nonzero results
 * call func_0217814C and fail, zero succeeds.
 */
BOOL func_021793B8(int arg)
{
    int r;

    r = func_020902D8((struct WMDataSharingInfo *)(g_021797A8 + 0x1444), (const u16 *)arg, (struct WMDataSet *)(g_021797A8 + 0x1C64));
    if (r == 7)
        return 0;
    if (r == 5)
        return 0;
    if (r != 0) {
        func_0217814C(r);
        return 0;
    }
    return 1;
}

/*
 * lever: final counter store uses unsigned address arithmetic rather than
 *   pointer arithmetic, so its offset is reloaded independently of the flag.
 */
void func_021793F8(void)
{
    if (g_021797A8 != 0 && *(s16 *)(g_021797A8 + 0x1EBE) > 0) {
        *(s16 *)(g_021797A8 + 0x1EBE) =
            (*(int *)(g_021797A8 + 0x1E70) != 2) ? 0 : *(s16 *)(g_021797A8 + 0x1EBE) - 1;
        if (*(s16 *)(g_021797A8 + 0x1EBE) == 0) {
            if (*(int *)(g_021797A8 + 0x1E70) == 2 && g_021797A8[0x1EDE] == 0) {
                if (func_0217863C() == 0) func_02178138(9);
            } else {
                *(s16 *)((unsigned int)g_021797A8 + 0x1EBE) = 1;
            }
        }
    }
}

/*
 * return-chain: 0209028C result is passed to 0217814C.
 */
void func_0217945C(void)
{
    int error;
    if (*(int *)(g_021797A8 + 0x1E70) == 5) {
        error = func_0209028C(g_021797A8 + 0x1444);
        if (error != 0) func_0217814C(error);
    }
    if (func_02178CDC() == 0) func_02178138(10);
}


/*
 * The DWC copy of the NitroSDK demo wh.c's WH_Finalize (DWCi_MOV_WH_*),
 * returning BOOL and reading its state from the work block behind
 * g_021797A8: +0x1E70 system state, +0x1E74 connect mode, +0x1444 the
 * data-sharing info, +0x1E98 an error latch, +0x1EDF a byte flag.
 */
BOOL func_02179498(void)
{
    int state;

    if (g_021797A8 == 0 || (state = *(int *)(g_021797A8 + 0x1E70)) == 1)
        return 1;

    if (*(int *)(g_021797A8 + 0x1E98) != 0) {
        func_0217945C();
        return 1;
    }

    if (state == 3)
        return 0;

    if (state == 2) {
        if (!func_021788FC())
            func_0217945C();
        return 1;
    }

    if (g_021797A8[0x1EDF] != 0)
        return 1;

    if (state != 5 && state != 4) {
        func_02178138(3);
        func_0217945C();
        return 1;
    }

    func_02178138(3);

    switch (*(int *)(g_021797A8 + 0x1E74)) {
    case 5:
        if (WM_EndDataSharing(g_021797A8 + 0x1444) != 0) {
            func_0217945C();
            break;
        }
    case 1:
        if (!func_02178C50())
            func_0217945C();
        break;
    case 2:
    case 3:
        break;
    case 4:
        if (WM_EndDataSharing(g_021797A8 + 0x1444) != 0) {
            func_0217945C();
            break;
        }
    case 0:
        if (!func_021784AC())
            func_0217945C();
        break;
    }
    return 1;
}

int func_02179570(void (*cb)(int))
{
    *(void (**)(int))(g_021797A8 + 0x1E64) = cb;
    func_02178138(3);
    if (func_0208F43C(func_02178DE0) != 2) {
        func_02178138(9);
        return 0;
    }
    return 1;
}

unsigned short func_021795A4(void)
{
    if (g_021797A8 != 0) return *(unsigned short *)(g_021797A8 + 0x1EA8);
    return 0;
}

void func_021795C0(unsigned v) { *(unsigned *)(g_021797A8 + 0x1E94) = v; }


/*
 * When the state word (+0x1E70) of the work block behind
 * g_021797A8 is 4 or 5, forwards the arguments to the arm9 function at
 * 0x02090CD4 with (0, a, b, c, d, 1) and the halfword arguments truncated.
 */
void func_021795D4(int a, int b, int c, int d)
{
    if (g_021797A8 != 0 && (unsigned)(*(int *)(g_021797A8 + 0x1E70) - 4) <= 1)
        func_02090CD4(0, a, (u16)b, c, (u16)d, 1);
}

unsigned short func_02179614(void) { return *(unsigned short *)(g_021797A8 + 0x1EBA); }

void func_02179628(unsigned v) { *(unsigned *)(g_021797A8 + 0x1E84) = v; }


/*
 * Recursive MATCH unblocker: the unlabelled ov014 setter that func_020103E4
 * (+001A) and sub_02010360 (+0056) call: store v into word +0x1E88 of the
 * object behind the pointer at g_021797A8.
 */
void func_0217963C(u32 v)
{
    *(u32 *)(g_021797A8 + 0x1E88) = v;
}

void func_02179650(u16 v)
{
    *(u16 *)(g_021797A8 + 0x1ec2) = v;
}
