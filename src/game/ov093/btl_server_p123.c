/*
 * file:     btl_server_p123.c
 * unit:     yes
 * function: func_021CC8A0, func_021CC8B0, func_021CC8B8, func_021CC8C0
 * address:  0x021CC8A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

void func_021CC8A0(u32 *p);
void func_021CC8B0(u32 *p, u32 i, u32 b);
u32 func_021CC8B8(u32 *p, u32 i);
u32 func_021CC8C0(u32 *p, u32 i);

void func_021CC8A0(u32 *p) { u32 i; for (i=0;i<24;i++) p[i]=6; }


void func_021CC8B0(u32 *p, u32 i, u32 b)
{
    *(u32 *)&p[i] = b;
}


/*
 * indexed load
 */
u32 func_021CC8B8(u32 *p, u32 i)
{
    return p[i];
}


u32 func_021CC8C0(u32 *p, u32 i)
{
    return p[i];
}
