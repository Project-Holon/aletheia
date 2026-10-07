/*
 * file:     unit_021BA290_p03.c
 * unit:     yes
 * function: func_021BA720, func_021BA75C, func_021BA780, func_021BA7A4
 * address:  0x021BA720
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BAED8 0x021BAED8 data a2
 */
struct Actor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef struct PtS{s16 x,y;} PtS;

typedef enum { FogMode0 = 0 } FogMode;

typedef enum { FogSlope0 = 0 } FogSlope;

extern u32 func_0204B3F4(struct Obj *);
extern void func_0204B3DC(struct Obj *,u32);
extern void func_0204B454(struct Actor *,PtS *,u32);
extern void func_0204B404(struct Obj *,const PtS *,u32);
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(int, FogMode, FogSlope, int);
extern void func_0207DD24(unsigned short, int, int, int, int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned, unsigned);
int func_021BA720(u32 base,u32 i,u32 space,int y);
int func_021BA75C(char *p, int v);
unsigned int func_021BA780(int v);
void func_021BA7A4(void);
extern int tbl_021BAC80[];
extern const unsigned short d_021BAED8[];

int func_021BA720(u32 base,u32 i,u32 space,int y){PtS pos;int r;void *o;o=*(void **)(base+i*4);r=0;if(func_0204B3F4(o)==0){func_0204B3DC(o,1);r=1;func_0204B454(o,&pos,space);pos.y=y;func_0204B404(o,&pos,space);}return r;}

int func_021BA75C(char *p, int v)
{
    int i;
    for (i = 0; i < 0x14; i++)
    {
        if (v == *(int *)(p + 0x2dc + i * 4))
        {
            return 1;
        }
    }
    return 0;
}


unsigned int func_021BA780(int v)
{
    int i;
    for (i = 0; i < 0x82; i++)
    {
        if (v == tbl_021BAC80[i])
        {
            break;
        }
    }
    if (i >= 0x82)
    {
        return 0xffff;
    }
    return i;
}

void func_021BA7A4(void)
{
    unsigned i;
    func_020434DC(1, 1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~(2 | 0x3000)) | 2;
    *(volatile unsigned short *)0x04000060 &= ~(0x10 | 0x3000);
    *(volatile unsigned short *)0x04000060 &= ~(4 | 0x3000);
    *(volatile unsigned short *)0x04000060 = (*(volatile unsigned short *)0x04000060 & ~0x3000) | 8;
    *(volatile unsigned short *)0x04000060 &= ~(0x20 | 0x3000);
    func_0207DC44(0, 0, 0, 0);
    func_0207DD24(0, 0, 0x7fff, 63, 0);
    *(volatile unsigned *)0x04000580 = 0xbfff0000;
    for (i = 0; i < 4; i++)
        func_02046A94((unsigned char)i, &d_021BAED8[i * 4]);
    func_02046BE0(0, 0);
}
