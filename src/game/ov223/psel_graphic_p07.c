/*
 * file:     psel_graphic_p07.c
 * unit:     yes
 * function: func_021BC64C, func_021BC654, func_021BC660, func_021BC6CC, func_021BC6DC, func_021BC6F0
 * address:  0x021BC64C
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BC34C 0x021BC34C thumb ov223
 *   func_02046440 0x02046440 arm
 *   func_02048A24 0x02048A24 arm
 *   d_021BC928 0x021BC928 data a4
 *   d_021BC91C 0x021BC91C data a4
 *   d_021BC910 0x021BC910 data a4
 *   d_020A1EB8 0x020A1EB8 data a4
 *   func_02048AC4  0x02048AC4  arm
 *   func_02046788  0x02046788  arm
 *   veneer_02047964  0x02047964  arm
 *   func_02048AD0    0x02048AD0  arm
 *   func_020479D8    0x020479D8  arm
 *   func_02047970 0x02047970 arm
 */
struct Light;
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_021BC34C(void);
extern void func_02046440(int,int,int,int,int,unsigned short,void (*)(void));
extern int func_02048A24(int,int,int,int,int,int,int,int,const int *,const int *,const int *,unsigned short);
extern u32 func_02048AC4(void *ptr);
extern int func_02046788(int);
extern void veneer_02047964(void *p);
extern void func_02048AD0(struct Light *l);
extern void func_020479D8(void);
extern void func_02047970(void);
void func_021BC64C(void *a0);
void func_021BC654(void *a0);
u32 func_021BC65C(const u32 *p);
void func_021BC660(int *p,unsigned short heap);
void func_021BC6CC(int *p);
void func_021BC6DC(int *p);
void func_021BC6F0(unsigned char *unused);
extern const short d_020A1EB8[];
extern int d_021BC91C[],d_021BC910[],d_021BC928[];

void func_021BC64C(void *a0) { func_0204A600(); }

void func_021BC654(void *a0) { func_0204A648(); }

/*
 * extent: tail-call stub followed by unlabelled 021BC65C load-return.
 */
u32 func_021BC65C(const u32 *p) { return *p; }

void func_021BC660(int *p,unsigned short heap)
{
    func_02046440(0,1,0,1,4096,heap,func_021BC34C);
    *p=func_02048A24(0,d_020A1EB8[6],d_020A1EB8[7],0x1555,0,4096,0x400000,0,d_021BC91C,d_021BC910,d_021BC928,heap);
}


void func_021BC6CC(int *p)
{
    func_02046788(func_02048AC4((void *)(*p)));
}


void func_021BC6DC(int *p)
{
    veneer_02047964(p);
    func_02048AD0((struct Light *)(*p));
    func_020479D8();
}

void func_021BC6F0(unsigned char *unused){func_02047970();}
