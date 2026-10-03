/*
 * function: func_02154B08
 * address:  0x02154B08
 * packet:   pkt_ov006_02154B08
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4   0x020120F4  thumb
 *   func_02012138   0x02012138  thumb
 *   func_020124E8   0x020124E8  thumb
 *   func_02026454   0x02026454  thumb
 *   func_02026400   0x02026400  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_02030734   0x02030734  arm
 *   func_02012EBC   0x02012EBC  thumb
 *   func_0201283C   0x0201283C  thumb
 *   func_02005C44   0x02005C44  thumb
 *   func_0200ADF0   0x0200ADF0  thumb
 *   d_02154C80      0x02154C80  data  ov006  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_020120F4(void *p);
struct Ctx;
struct Obj;
u32 func_02012138(const struct Ctx *p);
void *func_020124E8(struct Obj *p);
int func_02026454(int x);
void func_02026400(int x);
u32 func_0201A920(u32 a);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_02012EBC(int a);
int func_0201283C(int a);
u16 func_02005C44(void);
int func_0200ADF0(u32 a);

extern char d_02154C80[];

typedef struct Sub {
    int f00;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    u8  f20;
    u8  pad21[0x25];
    u8  f46;
    u8  pad47[2];
    u8  f49;
} Sub;

void func_02154B08(void *obj_in, void *p, int a, int b)
{
    char *obj;
    Sub *s;

    if (func_02026454(func_02012138(p)))
        func_02026400(func_02012138(p));
    obj = func_020124E8(obj_in);
    *(void **)(obj + 0x4) = p;
    *(int *)(obj + 0x8) = a;
    *(void **)(obj + 0x0) = obj_in;
    *(int *)(obj + 0x14) = b;
    *(Sub **)(obj + 0x5c) = func_02030734(0x8004, 0x4c, 1, d_02154C80, 0x2b0);
    (*(Sub **)(obj + 0x5c))->f00 = (int)func_02030734(0x8004, 0x20, 1, d_02154C80, 0x2b1);
    (*(Sub **)(obj + 0x5c))->f04 = func_020120F4(*(void **)(obj + 0x4));
    (*(Sub **)(obj + 0x5c))->f08 = func_02012EBC((*(Sub **)(obj + 0x5c))->f04);
    (*(Sub **)(obj + 0x5c))->f46 = 1;
    (*(Sub **)(obj + 0x5c))->f49 = 0;
    *(int *)(obj + 0x90) = (*(Sub **)(obj + 0x5c))->f04;
    *(int *)(obj + 0x94) = func_0201283C(*(int *)(obj + 0x90));
    (*(Sub **)(obj + 0x5c))->f0c = 0;
    *(int *)(obj + 0x7c) = *(int *)(obj + 0x168) = func_0201A920(0x8004);
    *(char **)(obj + 0xc) = obj;
    *(u16 *)(obj + 0x170) = func_02005C44();
    (*(Sub **)(obj + 0x5c))->f14 = func_0201A920(0x8001);
    (*(Sub **)(obj + 0x5c))->f18 = func_0201A920(0x8001);
    (*(Sub **)(obj + 0x5c))->f1c = func_0200ADF0(0x8001);
    (*(Sub **)(obj + 0x5c))->f20 = 1;
}
