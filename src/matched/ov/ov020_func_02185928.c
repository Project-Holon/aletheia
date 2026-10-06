/*
 * function: func_02185928
 * address:  0x02185928
 * packet:   pkt_ov020_02185928
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * blocker:  byte-correct (MATCH*, 198 of 200 bytes, the rest is padding);
 *           the THM_CALL to func_02013DD0 (arm9) has no witness: 0x02013DD0
 *           is an unlabelled arm9 leaf (Ilias's, inside func_02013D9C's
 *           listing extent; see unit_02013D9C.c's near-miss note). Verified
 *           C for it, per ov018_func_0217EC7C.c:
 *             int func_02013DD0(int a0)
 *             { return func_02013B10(a0, d_0209DFC0, 4); }
 *
 * symbols:
 *   func_02013DD0  0x02013DD0  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_0201444C  0x0201444C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_020127E0  0x020127E0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02186538  0x02186538  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02186854  0x02186854  thumb  ov020
 *   func_021868B8  0x021868B8  thumb  ov020
 *   func_0216CEAC  0x0216CEAC  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Sub02014444Obj;
int func_02013DD0(int a0);
void *func_02012B38(const struct BigObj *p);
u32 func_0201444C(struct Sub02014444Obj *o);
u32 func_02012964(const struct BigObj *p);
u32 func_0201296C(const struct BigObj *p);
unsigned short *func_020127C4(int a);
u8 *func_020127D0(u8 *o, u32 idx);
int func_020127E0(int a);
u32 func_020307B0(void *p);
int func_02186538(unsigned short *a, int b, int c);
int func_02186278(char *p, int which);
int func_02186854(u16 *p);
int func_021868B8(int a, int b, int c, int d);
void func_0216CEAC(u32 a, u8 *p, u32 b, u32 n, u32 c);

void func_02185928(int a, const short *p)
{
    int r6;
    int r5;
    int r4;
    int ip;
    int sc;
    int s8;
    unsigned short *r7;

    if (func_02013DD0((unsigned short)p[2]) == 0)
        return;

    r6 = (int)func_0201444C(func_02012B38((const struct BigObj *)a));
    sc = (int)func_02012964((const struct BigObj *)a);
    s8 = (int)func_0201296C((const struct BigObj *)a);
    if (r6 == 0)
        r7 = func_020127C4(a);
    else
        r7 = (short unsigned int *)func_020127D0((u8 *)a, (int)0);

    r5 = func_02186538(r7, r6, 1);
    ip = func_02186278((char *)r7, r6);
    if (r5 != 0 && ip != 0)
        func_0216CEAC((int)sc, (u8 *)r5, (int)p[2], (int)ip, (int)s8);
    if (r5 != 0)
        func_020307B0((void *)r5);

    r5 = func_020127E0(a);
    r4 = func_02186854((u16 *)r5);
    r5 = func_021868B8(r5, r6, r7[1], 1);
    if (r5 != 0 && r4 != 0)
        func_0216CEAC((int)sc, (u8 *)r5, (int)p[2], (int)r4, (int)s8);
    if (r5 != 0)
        func_020307B0((void *)r5);
}
