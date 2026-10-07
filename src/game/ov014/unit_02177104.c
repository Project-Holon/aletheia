/*
 * file:     unit_02177104.c
 * unit:     yes
 * function: func_02177104, func_02177114, func_02177134, func_02177150, func_02177168, func_0217719C, func_021771A8
 * address:  0x02177104
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
 *   func_02177B2C 0x02177B2C thumb ov014
 *   func_02177B58 0x02177B58 thumb ov014
 *   func_02177C08 0x02177C08 thumb ov014
 *   func_02179628 0x02179628 thumb ov014
 *   func_02177D0C 0x02177D0C thumb ov014
 *   func_021775BC 0x021775BC thumb ov014
 *   func_02177E20 0x02177E20 thumb ov014
 *   func_021776C4 0x021776C4 thumb ov014
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_021793B8 0x021793B8 thumb ov014
 *   func_02179394 0x02179394 thumb ov014
 *   func_02177C30 0x02177C30 thumb ov014
 *   func_02177310  0x02177310  thumb
 *   func_021779F4 0x021779F4 thumb ov014
 */
typedef unsigned char  u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern u8 *func_02177B2C(int i);
extern u8 *func_02177B58(int i);
extern int func_02177C08(void);
extern void func_02179628(unsigned v);
extern int func_02177D0C(int);
extern int func_021775BC(int);
extern int func_02177E20(u32,u8 *,u32,u32);
extern int func_021776C4(void);
extern int func_02178E4C(void);
extern int func_021793B8(int);
extern int func_02179394(u16);
extern int func_02177C30(int,u32,int);
void func_02177310(u32 v);
extern int func_021779F4(void);
void *func_02177104(int index);
void *func_02177114(int index);
int func_02177124(void);
int func_02177128(void);
int func_0217712C(void);
int func_02177134(int a);
int func_02177140(int a);
int func_02177148(int a);
int func_02177150(u32 a,u8 *b,u32 c,u32 d,u32 e);
int func_0217715C(void);
int func_02177160(void);
int func_02177168(void);
int func_0217717C(int a);
int func_02177184(u32 a);
int func_02177190(int a,u32 b,int c,int d);
int func_0217719C(u32 v);
int func_021771A8(void);
int func_021771DC(void);

void *func_02177104(int index)
{
    if (index >= 16) return 0;
    return func_02177B2C(index);
}

void *func_02177114(int index) { if (index >= 16) return 0; return func_02177B58(index); }

int func_02177124(void) { return 1; }

int func_02177128(void) { return 1; }

int func_0217712C(void) { return func_02177C08(); }

int func_02177134(int a) { func_02179628(a); return 1; }

int func_02177140(int a) { return func_02177D0C(a); }

int func_02177148(int a) { return func_021775BC(a); }

int func_02177150(u32 a,u8 *b,u32 c,u32 d,u32 e) { return func_02177E20(a,b,c,e); }

int func_0217715C(void) { return 0; }

int func_02177160(void) { return func_021776C4(); }

/*
 * interface: 02177190 forwards r1 unchanged to 02177C30; that leaf
 * performs the u16 truncation itself. Its matched signature uses full width.
 */
int func_02177168(void) { if (func_02178E4C() == 5) return 1; return 0; }

int func_0217717C(int a) { return func_021793B8(a); }

int func_02177184(u32 a) { return func_02179394((u16)a); }

int func_02177190(int a,u32 b,int c,int d) { return func_02177C30(a,b,d); }


int func_0217719C(u32 v)
{
    func_02177310(v);
    return 1;
}

int func_021771A8(void)
{
    switch (func_02178E4C()) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: return 1;
    case 0: default: return 0;
    }
}

int func_021771DC(void) { return func_021779F4(); }
