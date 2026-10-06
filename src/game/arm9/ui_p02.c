/*
 * file:     ui_p02.c
 * unit:     yes
 * function: func_02034FB8, func_02034FD4, func_02034FE8, func_02035004, func_02035010, func_02035034, func_02035040
 * address:  0x02034FB8
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
 *   d_021469BC   0x021469BC  data  a4
 *   func_02034FA0 0x02034FA0  arm
 *   g_021469BC    0x021469BC  data
 */
typedef unsigned int u32;

extern void func_02034FA0(void *p, u32 v);
void func_02034FB8(u32 v);
asm void func_02034FD4(void);
asm void func_02034FE8(void);
void func_02035004(char *o, u32 a, u32 b);
void func_02035010(u32 a, u32 b);
void func_02035034(char *o, u32 a, u32 b);
void func_02035040(u32 a, u32 b);
extern u32 d_021469BC[];
extern char *g_021469BC;




void func_02034FB8(u32 v)
{
    func_02034FA0((void *)d_021469BC[0], v);
}



asm void func_02034FD4(void)
{
    ldrb r0, [r0, #0x38]
    tst r0, r1
    movne r0, #1
    moveq r0, #0
    bx lr
}




asm void func_02034FE8(void)
{
    ldr r2, =0x021469BC
    mov r1, r0
    ldr r0, [r2]
    ldr ip, =func_02034FD4
    bx ip
}




/*
 * Setter: stores two values into an object at +0x14 and +0x28.
 */
void func_02035004(char *o, u32 a, u32 b)
{
    *(u32 *)(o + 0x14) = a;
    *(u32 *)(o + 0x28) = b;
}




/*
 * Wrapper: calls func_02035004 with the object g_021469BC points at as the first argument.
 */
void func_02035010(u32 a, u32 b)
{
    func_02035004(g_021469BC, a, b);
}




/*
 * Setter: stores two values into an object at +0x10 and +0x28.
 */
void func_02035034(char *o, u32 a, u32 b)
{
    *(u32 *)(o + 0x10) = a;
    *(u32 *)(o + 0x28) = b;
}


/*
 * Wrapper: calls func_02035034 with the object g_021469BC points at as the first argument.
 */
void func_02035040(u32 a, u32 b)
{
    func_02035034(g_021469BC, a, b);
}
