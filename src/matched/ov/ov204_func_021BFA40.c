/*
 * function: func_021BFA40
 * address: 0x021BFA40
 * packet: pkt_ov204_021BFA40
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02048A18 0x02048A18 arm
 *   func_020478B8 0x020478B8 arm
 *   func_020477D4 0x020477D4 arm
 *   func_020477A4 0x020477A4 arm
 *   func_021BFBC8 0x021BFBC8 thumb ov204
 */

extern void func_0207D63C(void *, int, int, int, int);
typedef unsigned int   u32;
struct G3dSys;
struct Owner;
extern void func_020061E4(u32 a);
extern void *func_02048A18(void *, unsigned short);
extern int func_020478B8(void *, int, int);
extern int func_020477D4(struct Owner *owner, u32 index);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_021BFBC8(char *, unsigned int);

int func_021BFA40(char *p)
{
    switch (*(unsigned int *)(p + 36))
    {
    case 0:
        func_0207D63C((void *)0x04000050, 1, 9, 0, 0);
        func_020061E4(0x555);
        ++*(unsigned int *)(p + 36);
    case 1:
    {
        void *obj = func_02048A18(*(void **)(p + 8), *(unsigned short *)(p + 16));
        int a = func_020478B8(obj, 3, 4096);
        int b = func_020478B8(obj, 4, 4096);
        if (a == 0 && b == 0)
        {
            func_020477D4(obj, 3);
            func_020477D4(obj, 4);
            func_020477A4(obj, 0);
            func_020477A4(obj, 1);
            func_020477A4(obj, 2);
            func_021BFBC8(p, 60);
            ++*(unsigned int *)(p + 36);
        }
        break;
    }
    case 2:
        return 1;
    }
    return 0;
}
