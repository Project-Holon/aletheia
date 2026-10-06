/*
 * file:     net_lower_data_p01.c
 * unit:     yes
 * function: func_0203E5F8, func_0203E6C0, func_0203E758, func_0203E808, func_0203E8C8, func_0203E96C, func_0203E9DC
 * address:  0x0203E5F8
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021469F4      0x021469F4  data
 *   s_020A7D74      0x020A7D74  data
 *   s_020A7D88      0x020A7D88  data
 *   s_020A7DA0      0x020A7DA0  data
 *   s_020A7DD8      0x020A7DD8  data
 *   s_020A7DB8      0x020A7DB8  data
 *   s_020A7E00      0x020A7E00  data
 *   g_021469F0      0x021469F0  data
 *   s_020A7D34      0x020A7D34  data
 *   s_020A7D4C      0x020A7D4C  data
 *   s_020A7D68      0x020A7D68  data
 */
#include "../../matched/include/Obj11383.h"
#include "../../matched/include/Obj11384.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
void func_0203E5F8(int a0, int a1);
void func_0203E6C0(void);
void func_0203E758(int a0, int a1, int a2, int a3);
void func_0203E808(u32 a0, int a1, u32 a2, u32 a3);
void func_0203E8C8(int idx);
int func_0203E96C(unsigned int idx);
int func_0203E9DC(unsigned int idx);
extern int *g_021469F4;
extern char s_020A7D74[];
extern char s_020A7D88[];
extern char s_020A7DA0[];
extern char s_020A7DD8[];
extern char s_020A7DB8[];
extern char s_020A7E00[];
extern int *g_021469F0;
extern char s_020A7D34[];
extern char s_020A7D4C[];
extern char s_020A7D68[];


void func_0203E5F8(int a0, int a1)
{
    u8 i;
    if (g_021469F4 != 0)
        func_02034714(s_020A7D74, 0x65, s_020A7D88);
    g_021469F4 = (int *)func_02030734(a0, 0x48, 1, s_020A7D74, 0x67);
    *(int *)((char *)g_021469F4 + 0x20) = 0;
    *(int *)((char *)g_021469F4 + 0x24) = 0;
    *(int *)((char *)g_021469F4 + 0x44) = 0;
    *(int *)((char *)g_021469F4 + 0x30) = 0;
    *(int *)((char *)g_021469F4 + 0x34) = 0;
    *(int *)((char *)g_021469F4 + 0x38) = a1;
    *(int *)((char *)g_021469F4 + 0x3c) = 1;
    *(int *)((char *)g_021469F4 + 0x40) = 0;
    for (i = 0; i < 8; i++)
        g_021469F4[i] = 0;
}


void func_0203E6C0(void)
{
    u8 i;
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x81, s_020A7DA0);
    for (i = 0; i < 8; i++) {
        int *p = (int *)g_021469F4[i];
        if (p == 0)
            continue;
        if (((((unsigned int)(((struct Obj11383 *)p)->f10) << 0x1e) >> 0x1f) == 1))
            func_020307B0((void *)((struct Obj11383 *)p)->f0);
        func_020307B0((void *)g_021469F4[i]);
    }
    func_020307B0((void *)g_021469F4);
    g_021469F4 = 0;
}


void func_0203E758(int a0, int a1, int a2, int a3)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x9f, s_020A7DA0);
    if (*(int *)((char *)g_021469F4 + 0x20) != 0)
        func_02034714(s_020A7D74, 0xa0, s_020A7DB8);
    *(int *)((char *)g_021469F4 + 0x20) = a0;
    *(int *)((char *)g_021469F4 + 0x24) = a1;
    *(u8 *)((char *)g_021469F4 + 0x28) = (u8)a2;
    *(int *)((char *)g_021469F4 + 0x2c) = a3;
    *(int *)((char *)g_021469F4 + 0x44) = 0;
    *(int *)((char *)g_021469F4 + 0x34) = 1;
    *(int *)((char *)g_021469F4 + 0x30) = 0;
}


void func_0203E808(u32 a0, int a1, u32 a2, u32 a3)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xcf, s_020A7DA0);
    if (g_021469F4[a1] != 0)
        func_02034714(s_020A7D74, 0xd0, s_020A7DD8);
    g_021469F4[a1] = (int)func_02030734(a2, 0x48, 1, s_020A7D74, 0xd2);
    *(int *)g_021469F4[a1] = a3;
    *(int *)(g_021469F4[a1] + 4) = a0;
    *(u8 *)(g_021469F4[a1] + 0x10) = (u8)(*(u8 *)(g_021469F4[a1] + 0x10) & ~2);
}


void func_0203E8C8(int idx)
{
    int *p;
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xe2, s_020A7DA0);
    if (g_021469F4[idx] == 0)
        func_02034714(s_020A7D74, 0xe3, s_020A7E00);
    p = (int *)g_021469F4[idx];
    if (((((unsigned int)(((struct Obj11384 *)p)->f10) << 0x1e) >> 0x1f) == 1))
        func_020307B0((void *)((struct Obj11384 *)p)->f0);
    func_020307B0((void *)g_021469F4[idx]);
    g_021469F4[idx] = 0;
}


int func_0203E96C(unsigned int idx)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0xf6, s_020A7DA0);
    if (g_021469F4[idx] == 0)
        func_02034714(s_020A7D74, 0xf7, s_020A7E00);
    return *(int *)g_021469F4[idx];
}

int func_0203E9DC(unsigned int idx)
{
    if (g_021469F4 == 0)
        func_02034714(s_020A7D74, 0x105, s_020A7DA0);
    if (g_021469F4[idx] == 0)
        func_02034714(s_020A7D74, 0x106, s_020A7E00);
    return *(int *)(g_021469F4[idx] + 0xc);
}
