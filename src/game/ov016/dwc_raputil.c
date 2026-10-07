/*
 * file:     dwc_raputil.c
 * unit:     yes
 * function: func_021B6100, func_021B6154, func_021B6178, func_021B6184, func_021B6190
 * address:  0x021B6100
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_021C0970  0x021C0970  arm
 *   d_021DAAA0  0x021DAAA0  data  a1
 *   func_0203064C 0x0203064C arm
 *   func_0200F17C 0x0200F17C thumb
 *   func_02034AC4 0x02034AC4 arm
 *   ov107_id 0x0000006B data a1
 *   func_0200F234 0x0200F234 thumb
 *   func_02034A5C 0x02034A5C arm
 *   func_020306F0 0x020306F0 arm
 *   func_020107CC 0x020107CC thumb
 */
typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_02087988(void);
extern void func_0208799C(int x);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int func_02085D3C(void);
extern int func_021C0970(void *work, int language, int param);
extern void func_0203064C(u32, u32, u32);
extern int func_0200F17C(u32);
extern int func_02034AC4(int);
extern void func_02087BCC(unsigned int);
extern void func_0200F234(u32);
extern void func_02034A5C(int);
extern void func_020306F0(unsigned int);
extern void func_020107CC(void);
void func_021B6100(int heap);
int func_021B6154(void);
int func_021B6178(void);
int func_021B6184(void);
int func_021B6190(void);
extern char d_021DAAA0[];
extern char ov107_id[];


void func_021B6100(int heap)
{
    int e;
    void *p;

    e = func_02087988();
    p = func_02030734(heap, 0x40000, 1, d_021DAAA0, 0x3d);
    if (func_02085D3C() == 0)
        func_021C0970(p, 1, 0);
    func_020307B0(p);
    func_0208799C(e);
    *(volatile unsigned short *)0x04000208;
    *(volatile unsigned short *)0x04000208 = 1;
}

int func_021B6154(void) { func_0203064C(1, 15, 0x40100); func_0200F17C(1); func_02034AC4((int)ov107_id); return 1; }


int func_021B6178(void)
{
    func_021B6100(0xf);
    return 1;
}


int func_021B6184(void)
{
    func_02087BCC(0);
    return 1;
}

int func_021B6190(void) { func_0200F234(1); func_02034A5C((int)ov107_id); func_020306F0(15); func_020107CC(); return 1; }
