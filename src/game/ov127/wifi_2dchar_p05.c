/*
 * file:     wifi_2dchar_p05.c
 * unit:     yes
 * function: func_021C4424, func_021C4440, func_021C4464
 * address:  0x021C4424
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int     s32;

extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
void func_021C4424(char *p, int i);
void func_021C4440(char *p,int i);
void func_021C4464(u8 *p, int i);


/*
 * Addresses are Black-image addresses.
 */
void func_021C4424(char *p, int i)
{
    if (*(int *)(p + i * 0x14 + 0x10) == 0)
        func_021C4440(p, i);
    else
        func_021C4464((u8 *)p, i);
}

void func_021C4440(char *p,int i) { func_0204A8D4(*(u32 *)(p+20+(u32)i*20)); func_0204ADA4(*(u32 *)(p+24+(u32)i*20)); *(u32 *)(p+20+(u32)i*20)=-1; *(u32 *)(p+24+(u32)i*20)=-1; }


void func_021C4464(u8 *p, int i)
{
    u32 *tbl = (u32 *)(p + 0x14 + i * 20);
    func_0204A8D4((u32)((void *)*tbl));
    *tbl = (u32)-1;
}
