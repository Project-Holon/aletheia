/*
 * file:     unit_02731590.c
 * unit:     yes
 * function: func_02731590, func_027315A8, func_027315C0, func_027315D0, func_027315E0
 * address:  0x02731590
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PMi_PostExitCallbackList  0x02732FAC  data
 *   PMi_DeleteList  0x0208C788  arm
 *   PMi_ExecuteList           0x0208C7E0  arm
 *   d_020A8724  0x020A8724  data  twl
 *   func_0207D42C 0x0207D42C arm
 *   func_02087A04 0x02087A04 arm
 *   func_0208BC8C 0x0208BC8C arm
 *   func_02087988 0x02087988 arm
 *   func_02082658 0x02082658 arm
 *   func_0272FD18 0x0272FD18 arm
 *   func_02731500 0x02731500 arm
 *   func_020882C0 0x020882C0 arm
 */
typedef struct PMiGenCallbackInfo PMiGenCallbackInfo;

extern void PMi_DeleteList(PMiGenCallbackInfo **listp, PMiGenCallbackInfo *info);
extern void PMi_ExecuteList(PMiGenCallbackInfo *listp);
void func_02731590(PMiGenCallbackInfo *info);
void func_027315A8(void);
extern PMiGenCallbackInfo *PMi_PostExitCallbackList;


void func_02731590(PMiGenCallbackInfo *info)
{
    PMi_DeleteList(&PMi_PostExitCallbackList, info);
}


/*
 * sdk:      PMi_ExecutePostExitCallbackList (pm.o, .ltdmain; no catalogue row)
 */
void func_027315A8(void)
{
    PMi_ExecuteList(PMi_PostExitCallbackList);
}


typedef unsigned int u32;
extern u32 d_020A8724[];

void func_027315C0(u32 v)
{
    d_020A8724[1] = v;
}


u32 func_027315D0(void)
{
    return d_020A8724[1];
}


/* power-off sequence (callbacks, wait three ticks, request until the status word reads zero, shutdown calls) */
typedef unsigned short u16;
void func_0207D42C(void);
void func_02087A04(u32 n);
int func_0208BC8C(u32 cmd, u32 a, u16 *buf);
void func_02087988(void);
void func_02082658(void);
void func_0272FD18(void);
void func_02731500(void);
void func_020882C0(void);

void func_027315E0(int flag)
{
    u32 cmd;
    int i;
    int sel;
    u16 buf;

    PMi_ExecuteList(PMi_PostExitCallbackList);
    func_0207D42C();
    *(volatile u32 *)0x04001000 &= ~0x10000;
    *(volatile u16 *)0x04000204 |= 0x8000;
    for (i = 0; i < 3; i++) {
        u32 t = *(volatile u32 *)0x02FFFC3C;
        while (t == *(volatile u32 *)0x02FFFC3C)
            func_02087A04(0x32);
    }
    sel = (flag != 0);
    for (;;) {
        cmd = sel ? 0x14 : 0x13;
        if (*(volatile u32 *)0x02FFF684 == 1) {
            cmd = 0x14;
            *(volatile u32 *)0x02000300 = 0;
        }
        if (func_0208BC8C(cmd, 0, &buf) != 0) {
            do {
                func_02087A04(0x51D23);
            } while (func_0208BC8C(cmd, 0, &buf) != 0);
        }
        if (buf == 0)
            break;
        func_02087A04(0x51D23);
    }
    func_02087988();
    func_02082658();
    func_0272FD18();
    func_02731500();
    func_020882C0();
}
