/*
 * function: func_021FAC74
 * address: 0x021FAC74
 * packet: pkt_ov132_021FAC74
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_0201121C 0x0201121C thumb
 *   func_0201126C 0x0201126C thumb
 *   func_0201127C 0x0201127C thumb
 *   d_021FDC2C 0x021FDC2C data ov132 a4
 *   d_021FDCEC 0x021FDCEC data ov132 a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_021FDCEC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_0201121C(u32, void *);
extern void func_0201126C(void *, void *);
extern void func_0201127C(void *, void *);
extern char d_021FDC2C[];
void *func_021FAC74(char *p, void *arg, int flag)
{
    u8 i;
    for (i = 0; i < 10; i++) if (*(void **)(p + 0xc + i * 4) == 0) break;
    ((char **)(p + 0xc))[i] = func_02030734(*(u16 *)p, 0x1c, 0, d_021FDCEC, 0xc4);
    *(void **)(((char **)(p + 0xc))[i] + 8) = arg;
    *(void **)(((char **)(p + 0xc))[i] + 0xc) = 0;
    *(u16 *)(((char **)(p + 0xc))[i] + 0x14) = 0;
    *(int *)(((char **)(p + 0xc))[i] + 0x10) = 0;
    *(u16 *)(((char **)(p + 0xc))[i] + 0x16) = 0;
    *(u8 *)(((char **)(p + 0xc))[i] + 0x18) = 0;
    *(u8 *)(((char **)(p + 0xc))[i] + 0x19) = i;
    if (flag == 1) *(u16 *)(((char **)(p + 0xc))[i] + 0x16) |= 2;
    *(char **)((char **)(p + 0xc))[i] = p;
    *(void **)(((char **)(p + 0xc))[i] + 4) = func_0201121C(*(u16 *)p, d_021FDC2C);
    func_0201126C(*(void **)(((char **)(p + 0xc))[i] + 4), ((char **)(p + 0xc))[i]);
    func_0201127C(*(void **)(((char **)(p + 0xc))[i] + 4), *(void **)(((char **)(p + 0xc))[i] + 8));
    return ((char **)(p + 0xc))[i];
}
