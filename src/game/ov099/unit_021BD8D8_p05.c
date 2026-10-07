/*
 * file:     unit_021BD8D8_p05.c
 * unit:     yes
 * function: func_021BE4BC, func_021BE4EC, func_021BE4F0, func_021BE538
 * address:  0x021BE4BC
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BE448 0x021BE448 thumb ov099
 *   func_021BE3CC 0x021BE3CC thumb ov099
 *   func_0202208C  0x0202208C  thumb
 *   func_021C27E8  0x021C27E8  thumb  ov099
 *   func_021C2864  0x021C2864  thumb  ov099
 *   func_021C0C7C  0x021C0C7C  thumb  ov099
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_021BE448(unsigned int,int);
extern void func_021BE3CC(char *,int,int,int,int,int);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021C27E8(void *, u8);
extern void func_021C2864(void *, u8);
extern void func_021C0C7C(void);
void func_021BE4BC(char *p,int a,int b,int c,int d,unsigned int e,int f);
int func_021BE4EC(int a);
int func_021BE4F0(char *p, int v);
void func_021BE538(char *p);

/*
 * Extent ends with two-byte alignment padding at 0x021BE4EA.
 */
void func_021BE4BC(char *p,int a,int b,int c,int d,unsigned int e,int f) {
 int value;
 value=func_021BE448(e,d);
 func_021BE3CC(p,a,b,c,value+f,0);
}

/*
 * Returns the constant 8.
 */
int func_021BE4EC(int a)
{
    return 8;
}


int func_021BE4F0(char *p, int v)
{
    if (v != 0)
        func_0202208C(0, 1, 1, 0, 6, 1, 0x21);
    func_021C27E8(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C2864(*(void **)(p + 8), *(u8 *)(*(char **)(p + 0x248) + 0x46));
    func_021C0C7C();
    return 9;
}

void func_021BE538(char *p)
{
}
