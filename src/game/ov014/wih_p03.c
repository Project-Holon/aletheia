/*
 * file:     wih_p03.c
 * unit:     yes
 * function: func_02177DB0, func_02177E20, func_02177E9C, func_02177EB0, func_02177EDC, func_02177EFC
 * address:  0x02177DB0
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
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   d_02179680     0x02179680  data  ov014  a2
 *   func_0203D798  0x0203D798  arm
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02178524  0x02178524  thumb  ov014
 *   func_021795C0  0x021795C0  thumb  ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_0217771C  0x0217771C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_021788FC  0x021788FC  thumb  ov014
 *   func_02082D44  0x02082D44  arm
 *   func_02179158 0x02179158 thumb ov014
 *   func_02177704 0x02177704 thumb ov014
 *   func_02179570 0x02179570 thumb ov014
 *   func_02179328 0x02179328 thumb ov014
 *   func_02179498  0x02179498  thumb
 *   func_02177FF0  0x02177FF0  thumb
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

void *func_0203D798(void);
int func_02178E4C(void);
int func_02178524(u32 a, const u16 *b, u32 c);
void func_021795C0(unsigned v);
void func_0217933C(void *fn);
void func_0217727C(u32 *p, u32 v);
int func_0217771C(u8 *obj);
int func_021775AC(int a, int b, int c);
int func_021788FC(void);
void func_02082D44(void *d, void *s, u32 n);
extern void func_02179158(void);
extern void func_02177704(void);
extern int func_02179570(void (*cb)(int));
extern void func_02179328(void *v);
int func_02179498(void);
void func_02177FF0(u8 *a);
void func_02177DB0(void);
int func_02177E20(u32 a, u8 *b, u32 c, u32 d);
void func_02177E9C(void);
int func_02177EB0(int a);
int func_02177ED4(void);
int func_02177ED8(void);
void func_02177EDC(int a);
void func_02177EFC(u8 *a);
extern u8 *g_021797A4;
extern u16 d_02179680[2];


void func_02177DB0(void)
{
    u8 *st = func_0203D798();
    u16 tab[2];
    tab[0] = d_02179680[0];
    tab[1] = d_02179680[1];
    if (func_02178E4C() == 1 || func_02178E4C() == 2) {
        func_02178524(tab[st[0x64]], (const u16 *)(g_021797A4 + 0xCDE), 0);
        func_021795C0((unsigned int)func_0217771C);
        func_0217933C(func_021775AC);
        g_021797A4[0xCE8] = 1;
        func_0217727C((u32 *)g_021797A4, 0);
    }
}


int func_02177E20(u32 a, u8 *b, u32 c, u32 d)
{
    func_0203D798();
    if (*(u32 *)g_021797A4 != 0)
        return 0;
    if (func_02178E4C() == 2) {
        g_021797A4[0xCE9] = 0;
        func_021788FC();
    }
    func_0217727C((u32 *)g_021797A4, (u32)func_02177DB0);
    if (b != 0)
        func_02082D44(b, g_021797A4 + 0xCDE, 6);
    else
        func_02082D44(g_021797A4 + 0xC + c * 0xC0, g_021797A4 + 0xCDE, 6);
    *(u32 *)(g_021797A4 + 0xC60) = d;
    return 1;
}

void func_02177E9C(void) { if (func_02178E4C() == 0) { func_02179158(); func_02177704(); } }

int func_02177EB0(int a) { if (func_02179570((void (*)(int))a) != 0) { func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177E9C); return 1; } return 0; }

int func_02177ED4(void) { return 1; }

int func_02177ED8(void) { return 0; }

/*
 * evidence: 79328 stores its r0 payload unchanged; caller passes a function pointer.
 */
void func_02177EDC(int a) { if (a != 0) func_02179328(func_02177ED4); else func_02179328(func_02177ED8); }


void func_02177EFC(u8 *a)
{
    if (g_021797A4[0xCF3] == 0) {
        if (a[0xCF2] != 0)
            a[0xCF2]--;
        if (a[0xCF2] == 0) {
            if (func_02179498() != 0)
                func_0217727C((u32 *)g_021797A4, (u32)func_02177FF0);
        }
    }
}
